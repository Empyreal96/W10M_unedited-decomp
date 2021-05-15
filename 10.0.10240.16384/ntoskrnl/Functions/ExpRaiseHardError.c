// ExpRaiseHardError 
 
int __fastcall ExpRaiseHardError(int a1, unsigned int a2, int a3, int a4, int a5, int a6, unsigned int *a7)
{
  unsigned int v7; // r6
  _DWORD *v9; // r8
  int v10; // r4
  int v11; // r4
  int v12; // r1
  unsigned int v13; // r2
  int v14; // r0
  int v15; // lr
  unsigned int v16; // r3
  int v17; // r5
  int v18; // r6
  int v19; // r3
  int v20; // r2
  int v21; // r4
  int v22; // r8
  _DWORD v27[3]; // [sp+48h] [bp-160h] BYREF
  unsigned int v28; // [sp+54h] [bp-154h]
  int v29; // [sp+58h] [bp-150h]
  int v30; // [sp+5Ch] [bp-14Ch]
  _DWORD _60[88]; // [sp+60h] [bp-148h] BYREF

  _60[87] = a4;
  _60[86] = a3;
  v7 = a2;
  _60[85] = a2;
  _60[84] = a1;
  v9 = PsGetCurrentServerSiloGlobals();
  v10 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v7 > 0x4A )
    return -1073741811;
  v12 = 0;
  if ( a6 == 6 )
  {
    if ( !SeSinglePrivilegeCheck(SeShutdownPrivilege, dword_922B8C, v10, (int)&SeShutdownPrivilege) )
      return -1073741727;
    if ( !PsIsCurrentThreadInServerSilo() )
      ExReadyForErrors = 0;
    v9[4] = 2;
    v12 = 1;
  }
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v15 = *(_DWORD *)(v13 + 960) & 0x10;
  if ( !v15 && (a1 & 0xC0000000) == -1073741824 && (!v9[4] || v12) )
  {
    ExpSystemErrorHandler(a1, v7, a3, a5, v10 != 0);
    return 0;
  }
  if ( v14 == v9[5] )
  {
    if ( (a1 & 0xC0000000) == -1073741824 )
      ExpSystemErrorHandler(a1, v7, a3, a5, v10 != 0);
LABEL_17:
    v16 = 0;
    v11 = 0;
LABEL_45:
    *a7 = v16;
    return v11;
  }
  v17 = 0;
  v18 = 0;
  if ( !v15 && ((*(_DWORD *)(v14 + 412) & 1) != 0 || (a1 & 0x10000000) != 0) )
  {
    v17 = PsCaptureExceptionPort(v14);
    if ( v17 )
      v18 = 1;
    else
      v17 = v9[6];
  }
  if ( v17
    && ((*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
     || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 ? (v19 = 0) : (v19 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C)),
        v19) )
  {
    v20 = 0;
    if ( (*(_DWORD *)(v19 + 3880) & 0x10) != 0 )
      v20 = -1073741823;
    v21 = a2;
    v22 = a6;
    if ( v20 < 0 )
    {
      if ( v18 == 1 )
        ObfDereferenceObject(v17);
      v17 = 0;
    }
  }
  else
  {
    v22 = a6;
    v21 = a2;
  }
  if ( !v17 )
    goto LABEL_17;
  v27[2] = v22;
  v30 = a3;
  v29 = v21;
  if ( a4 )
    memmove((int)_60, a4, 4 * v21);
  KeQuerySystemTime(v27);
  v11 = LpcRequestWaitReplyPortEx();
  if ( v18 == 1 )
    ObfDereferenceObject(v17);
  if ( v11 >= 0 )
  {
    v16 = v28;
    if ( v28 > 0xA )
      v16 = 0;
    goto LABEL_45;
  }
  return v11;
}
