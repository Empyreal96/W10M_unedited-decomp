// CcCopyReadEx 
 
int __fastcall CcCopyReadEx(int a1, _DWORD *a2, unsigned int a3, int a4, int a5, _DWORD *a6, int a7)
{
  _DWORD *v11; // r2
  int v12; // r5
  __int64 v13; // kr08_8
  __int64 v14; // kr10_8
  unsigned int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r1
  int v18; // r9
  int v19; // r2
  unsigned int *v20; // r4
  unsigned int v21; // r5
  unsigned int *v23; // r2
  unsigned int v24; // r1
  unsigned int *v25; // r2
  unsigned int v26; // r1
  int v27[8]; // [sp+18h] [bp-20h] BYREF

  v27[0] = 0;
  v11 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v12 = (v11[240] >> 9) & 7;
  if ( (*(_DWORD *)(v11[84] + 192) & 0x100000) != 0 )
    v12 = 0;
  if ( v12 < 2 && v11 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v11[250] )
    v12 = 2;
  v13 = *(_QWORD *)(a1 + 20);
  if ( v12 <= 0 )
    a4 = 1;
  v14 = *(_QWORD *)a2 + a3;
  if ( v14 > *(_QWORD *)(*(_DWORD *)(v13 + 4) + 8) )
    KeBugCheckEx(52, 780, -1073740768);
  if ( !a5 )
    sub_54A490(v14);
  if ( (*(_DWORD *)HIDWORD(v13) & 0x20000) != 0 )
    CcScheduleReadAheadEx(a1, a2, a3, a7);
  v15 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( a4 )
  {
    v16 = (unsigned int *)(v15 + 3016);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 + 1, v16) );
  }
  else
  {
    v23 = (unsigned int *)(v15 + 3012);
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 + 1, v23) );
  }
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4) = 0;
  v18 = CcMapAndCopyFromCache(a1, v27, *a2, a2[1], a3, a4, a5, v27, (*(_DWORD *)HIDWORD(v13) >> 18) & 7);
  if ( v18 )
  {
    v19 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4);
    v20 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4292);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 + v19, v20) );
    if ( v27[0] && (*(_DWORD *)HIDWORD(v13) & 0x20000) == 0 )
      CcScheduleReadAheadEx(a1, a2, a3, a7);
    CcUpdateReadHistory(a1, a2, a3);
    *a6 = 0;
    a6[1] = a3;
  }
  else
  {
    v25 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3020);
    do
      v26 = __ldrex(v25);
    while ( __strex(v26 + 1, v25) );
  }
  return v18;
}
