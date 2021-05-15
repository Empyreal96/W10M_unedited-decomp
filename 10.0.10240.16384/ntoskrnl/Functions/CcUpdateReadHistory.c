// CcUpdateReadHistory 
 
// local variable allocation has failed, the output may be wrong!
unsigned __int64 *__fastcall CcUpdateReadHistory(int a1, unsigned __int64 *a2, unsigned int a3)
{
  __int64 v3; // kr00_8
  int v4; // r9
  unsigned int v5; // r3 OVERLAPPED
  unsigned int v6; // r4 OVERLAPPED
  unsigned __int64 *v7; // r5
  unsigned __int64 v8; // kr08_8
  unsigned int v9; // r3 OVERLAPPED
  unsigned int v10; // r4 OVERLAPPED
  unsigned __int64 *v11; // r5
  unsigned __int64 v12; // kr10_8
  unsigned __int64 v13; // kr18_8
  unsigned __int64 *result; // r0
  unsigned __int64 v15; // kr20_8
  unsigned __int64 v16; // kr28_8
  unsigned __int64 *v17; // r3
  unsigned __int64 v18; // kr30_8

  v3 = *(_QWORD *)(a1 + 20);
  v4 = *(_DWORD *)(v3 + 4);
  __dmb(0xBu);
  *(_QWORD *)&v5 = *(_QWORD *)(HIDWORD(v3) + 32);
  v7 = (unsigned __int64 *)(HIDWORD(v3) + 16);
  do
    v8 = __ldrexd(v7);
  while ( __strexd(__PAIR64__(v6, v5), v7) );
  __dmb(0xBu);
  *(_QWORD *)&v9 = *(_QWORD *)(HIDWORD(v3) + 40);
  v11 = (unsigned __int64 *)(HIDWORD(v3) + 24);
  do
    v12 = __ldrexd(v11);
  while ( __strexd(__PAIR64__(v10, v9), v11) );
  __dmb(0xBu);
  v13 = *a2;
  result = (unsigned __int64 *)(HIDWORD(v3) + 32);
  do
    v15 = __ldrexd(result);
  while ( __strexd(v13, result) );
  __dmb(0xBu);
  v16 = *a2 + a3;
  v17 = (unsigned __int64 *)(HIDWORD(v3) + 40);
  do
    v18 = __ldrexd(v17);
  while ( __strexd(v16, v17) );
  __dmb(0xBu);
  if ( (*(_DWORD *)(v4 + 96) & 0x200000) != 0
    && (unsigned int)((*(_DWORD *)(HIDWORD(v3) + 32) >> 12) - (*(_DWORD *)(HIDWORD(v3) + 24) >> 12)) > 1 )
  {
    result = (unsigned __int64 *)CcUpdateSharedCacheMapFlag(v4, 0x200000, 0);
  }
  return result;
}
