// SepAdtOpenObjectForDeleteAuditAlarm 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SepAdtOpenObjectForDeleteAuditAlarm(int a1, int a2, int a3, unsigned __int16 *a4, unsigned __int16 *a5, int a6, int a7, int a8, unsigned int a9, _DWORD *a10, int a11, int a12, _DWORD *a13)
{
  _DWORD *v13; // r7
  unsigned int v16; // r8
  unsigned int v17; // r9 OVERLAPPED
  unsigned int v18; // r10 OVERLAPPED
  int v19; // r3
  __int64 v20; // kr00_8
  int v21; // r3
  int v22; // r3
  int v23; // r3
  int v24; // r3
  _QWORD v26[83]; // [sp+0h] [bp-2C8h] BYREF
  _DWORD v27[12]; // [sp+298h] [bp-30h] BYREF

  v13 = a13;
  v27[0] = 0;
  v27[1] = 0;
  v27[2] = 0;
  v27[3] = 0;
  if ( !a13 )
    v13 = v27;
  if ( a6 )
    v16 = **(_DWORD **)(a6 + 148);
  else
    v16 = **(_DWORD **)(a7 + 148);
  *(_QWORD *)&v17 = *(_QWORD *)(a7 + 24);
  memset(v26, 0, sizeof(v26));
  v26[0] = 0x123300000003i64;
  WORD1(v26[2]) = 8;
  LODWORD(v26[3]) = 4;
  v19 = *(unsigned __int8 *)(v16 + 1);
  LOWORD(v26[2]) = a1;
  HIDWORD(v26[3]) = 4 * (v19 + 2);
  v26[5] = v16 | 0x100000000i64;
  LODWORD(v26[6]) = 24;
  HIDWORD(v26[7]) = &SeSubsystemName;
  if ( a6 )
  {
    v20 = *(_QWORD *)(a6 + 24);
    v26[8] = 0x800000005i64;
    v26[9] = v20;
  }
  else
  {
    v26[8] = 0x800000005i64;
    v26[9] = __PAIR64__(v18, v17);
  }
  HIDWORD(v26[10]) = 1;
  LODWORD(v26[11]) = 24;
  HIDWORD(v26[12]) = &SeSubsystemName;
  if ( a4 )
  {
    LODWORD(v26[13]) = 1;
    v21 = *a4;
    LODWORD(v26[15]) = a4;
    HIDWORD(v26[13]) = v21 + 8;
  }
  if ( a5 )
  {
    if ( a1 == 116 || a1 == 128 )
      v22 = 2;
    else
      v22 = 1;
    HIDWORD(v26[15]) = v22;
    v23 = *a5;
    HIDWORD(v26[17]) = a5;
    LODWORD(v26[16]) = v23 + 8;
  }
  v26[18] = 0x40000000Bi64;
  LODWORD(v26[19]) = 0;
  HIDWORD(v26[20]) = 13;
  LODWORD(v26[21]) = 16;
  HIDWORD(v26[22]) = v13;
  v26[23] = 0x400000007i64;
  HIDWORD(v26[25]) = 10;
  LODWORD(v26[26]) = 4;
  HIDWORD(v26[26]) = a9;
  v26[24] = a9 | 0x400000000i64;
  if ( a10 && *a10 )
  {
    v24 = 12 * (*a10 - 1) + 20;
    LODWORD(v26[28]) = 8;
    HIDWORD(v26[28]) = v24;
    LODWORD(v26[30]) = a10;
  }
  HIDWORD(v26[30]) = 11;
  LODWORD(v26[31]) = 4;
  HIDWORD(v26[31]) = a12;
  LODWORD(v26[1]) = 12;
  SepAdtLogAuditRecord((int)v26);
  return 1;
}
