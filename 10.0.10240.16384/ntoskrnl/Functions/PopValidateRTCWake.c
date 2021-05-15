// PopValidateRTCWake 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopValidateRTCWake(_BYTE *a1)
{
  char v1; // r2
  unsigned int v3; // r3
  __int64 v4; // r6
  bool v6; // cf
  unsigned int v7; // r9 OVERLAPPED
  unsigned int v8; // r10 OVERLAPPED
  int v9; // r2
  int v10; // [sp+10h] [bp-48h] BYREF
  int v11; // [sp+14h] [bp-44h] BYREF
  char v12[64]; // [sp+18h] [bp-40h] BYREF

  v1 = PopFixedWakeSourceMask;
  *a1 = 0;
  if ( (v1 & 0x18) == 16 )
  {
LABEL_2:
    v3 = 1;
LABEL_13:
    dword_61ECB0 = v3;
    goto LABEL_14;
  }
  if ( (v1 & 0x18) == 8 )
  {
LABEL_12:
    v3 = 0;
    goto LABEL_13;
  }
  if ( (v1 & 0x18) != 0 )
  {
    PopCurrentPowerStatePrecise(v12);
    v1 = PopFixedWakeSourceMask;
    v3 = dword_61EC0C;
    dword_61ECB0 = dword_61EC0C;
  }
  else
  {
    v3 = dword_61ECB0;
  }
  if ( v3 >= 3 )
  {
    if ( (v1 & 4) == 0 )
      *a1 = 1;
    if ( *(_QWORD *)&qword_61ECD8 && (unsigned __int64)qword_61ECC0 > *(_QWORD *)&qword_61ECD8 )
      goto LABEL_2;
    goto LABEL_12;
  }
LABEL_14:
  LODWORD(v4) = *(_DWORD *)&PopAction[24 * v3 + 100];
  HIDWORD(v4) = *(_DWORD *)&PopAction[24 * v3 + 96];
  if ( !v4 )
  {
    dword_61ECB0 = 3;
    *a1 = 0;
    return 0;
  }
  if ( *(_QWORD *)&PopAction[24 * v3 + 96] >= (unsigned __int64)(unsigned int)dword_989680 )
  {
    v6 = __CFADD__(HIDWORD(v4), -10000000);
    HIDWORD(v4) -= 10000000;
    LODWORD(v4) = v6 + (_DWORD)v4 - 1;
  }
  *(_QWORD *)&v7 = unk_61ECA0;
  if ( PoResumeFromHibernate )
  {
    PopPowerTransitionTimesInMs(0, 0, 0, &v11, &v10);
    v8 = (__PAIR64__(v8, v7) - (unsigned int)(10000 * v11 + 10000 * v10)) >> 32;
    v7 -= 10000 * v11 + 10000 * v10;
  }
  if ( (unsigned int)v4 >= v8 && ((unsigned int)v4 > v8 || HIDWORD(v4) >= v7) )
  {
    if ( (PoDebug & 8) != 0 )
      DbgPrint(
        "PopValidateRTCWake: The machine woke earlier (ActualWakeTime %I64u) than programmed (ProgrammedWakeTime of %I64u)\n",
        __PAIR64__(v8, v7),
        __PAIR64__(v4, HIDWORD(v4)));
LABEL_26:
    dword_61ECB0 = 3;
    *a1 = 0;
    return 0;
  }
  if ( (PopFullWake & 3) != 0 )
    v9 = 100000000;
  else
    v9 = 1200000000;
  if ( __PAIR64__(v8, v7) - __PAIR64__(v4, HIDWORD(v4)) >= (unsigned int)v9 )
  {
    if ( (PoDebug & 8) != 0 )
      DbgPrint(
        "PopValidateRTCWake: The machine woke later (ActualWakeTime %I64u) than programmed (ProgrammedWakeTime of %I64u),"
        " which is later than the allowable tolerance (%I64u)\n",
        __PAIR64__(v8, v7),
        __PAIR64__(v4, HIDWORD(v4)),
        (unsigned __int64)(unsigned int)v9);
    goto LABEL_26;
  }
  return 1;
}
