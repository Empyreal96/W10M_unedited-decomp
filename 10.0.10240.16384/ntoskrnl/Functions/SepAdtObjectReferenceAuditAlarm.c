// SepAdtObjectReferenceAuditAlarm 
 
int __fastcall SepAdtObjectReferenceAuditAlarm(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r7
  unsigned int v5; // r5
  int v6; // r6
  unsigned int v8; // r8
  unsigned int v9; // r10
  __int16 v10; // r3
  int result; // r0
  int v12; // r6
  unsigned __int16 *v13; // r4
  int v14; // r3
  __int64 v15; // kr08_8
  int v16; // r3
  int v17; // r3
  unsigned __int16 *v18; // [sp+0h] [bp-2D0h] BYREF
  unsigned __int16 *v19; // [sp+4h] [bp-2CCh] BYREF
  unsigned int v20; // [sp+8h] [bp-2C8h]
  int v21; // [sp+Ch] [bp-2C4h]
  _DWORD *v22; // [sp+10h] [bp-2C0h]
  int v23; // [sp+14h] [bp-2BCh]
  _QWORD v24[87]; // [sp+18h] [bp-2B8h] BYREF

  v4 = *a2;
  v21 = a3;
  v22 = a2;
  v5 = 0;
  v6 = a2[2];
  v23 = a4;
  v18 = 0;
  v19 = 0;
  if ( v4 )
    v8 = **(_DWORD **)(v4 + 148);
  else
    v8 = **(_DWORD **)(v6 + 148);
  v9 = *(_DWORD *)(v6 + 24);
  v20 = *(_DWORD *)(v6 + 28);
  memset(v24, 0, 664);
  v24[0] = 0x125300000003i64;
  LOWORD(v24[2]) = 120;
  LODWORD(v24[1]) = 0;
  if ( v23 )
    v10 = 8;
  else
    v10 = 16;
  WORD1(v24[2]) = v10;
  result = SepQueryNameString(a1, &v19);
  v12 = result;
  v13 = v19;
  if ( result >= 0 )
  {
    result = SepQueryTypeString(a1, &v18);
    v12 = result;
    if ( result < 0 )
    {
      v5 = (unsigned int)v18;
    }
    else
    {
      LODWORD(v24[3]) = 4;
      v14 = *(unsigned __int8 *)(v8 + 1);
      v24[5] = v8 | 0x100000000i64;
      HIDWORD(v24[3]) = 4 * (v14 + 2);
      LODWORD(v24[6]) = 24;
      HIDWORD(v24[7]) = &SeSubsystemName;
      if ( v4 )
      {
        v15 = *(_QWORD *)(v4 + 24);
        v24[8] = 0x800000005i64;
        v24[9] = v15;
      }
      else
      {
        v24[8] = 0x800000005i64;
        v24[9] = __PAIR64__(v20, v9);
      }
      v5 = (unsigned int)v18;
      if ( v18 )
      {
        HIDWORD(v24[10]) = 1;
        v16 = *v18;
        HIDWORD(v24[12]) = v18;
        LODWORD(v24[11]) = v16 + 8;
      }
      if ( v13 )
      {
        LODWORD(v24[13]) = 1;
        v17 = *v13;
        LODWORD(v24[15]) = v13;
        HIDWORD(v24[13]) = v17 + 8;
      }
      HIDWORD(v24[15]) = 7;
      LODWORD(v24[16]) = 4;
      HIDWORD(v24[16]) = v21;
      LODWORD(v24[17]) = 3;
      LODWORD(v24[19]) = v21;
      HIDWORD(v24[20]) = 11;
      LODWORD(v24[21]) = 4;
      v24[18] = 0x40000000Ai64;
      HIDWORD(v24[21]) = v22[3];
      LODWORD(v24[1]) = 8;
      result = SepAdtLogAuditRecord((int)v24);
    }
  }
  if ( v13 )
    result = ExFreePoolWithTag((unsigned int)v13);
  if ( v5 )
    result = ExFreePoolWithTag(v5);
  if ( v12 < 0 )
    result = SepAuditFailed();
  return result;
}
