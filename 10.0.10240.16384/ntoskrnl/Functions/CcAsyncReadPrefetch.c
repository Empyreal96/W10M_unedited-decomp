// CcAsyncReadPrefetch 
 
int __fastcall CcAsyncReadPrefetch(int a1, int a2)
{
  int v2; // r10
  int v3; // r4
  int v4; // r6
  __int64 v5; // r8
  unsigned int v6; // r5
  _DWORD *v7; // lr
  int v8; // r1
  int v9; // r0
  unsigned int v10; // r0
  __int64 *v11; // r0
  __int64 v12; // kr00_8
  _DWORD *v13; // r4
  int v15; // [sp+18h] [bp-60h]
  int v16; // [sp+20h] [bp-58h]
  _DWORD _50[14]; // [sp+50h] [bp-28h] BYREF

  _50[13] = a2;
  _50[12] = a1;
  v2 = 0;
  v15 = 0;
  v3 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(a1 + 24);
  LODWORD(v5) = *(_DWORD *)(a1 + 16);
  _50[0] = v5;
  HIDWORD(v5) = *(_DWORD *)(a1 + 20);
  _50[1] = HIDWORD(v5);
  v6 = *(_DWORD *)(a1 + 28);
  v7 = *(_DWORD **)(a1 + 32);
  v16 = *(_DWORD *)(a1 + 40);
  v8 = *(_DWORD *)(a1 + 52);
  v9 = *(char *)(a1 + 56);
  if ( (*(_WORD *)(v16 + 6) & 0x817) == 0 )
    MmProbeAndLockProcessPages(v16, v8, v9, 1);
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4) = 0;
  *v7 = 0;
  v10 = v6;
  if ( v5 < *(_QWORD *)(v3 + 8) )
  {
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 7;
    if ( v5 + v6 > *(_QWORD *)(v3 + 8) )
      v10 = *(_DWORD *)(v3 + 8) - v5;
    v2 = MmPrefetchForCacheManager(
           v4,
           ((v5 + v10 + 4095) & 0xFFFFF000) - (v5 & 0xFFFFF000),
           v5 & 0xFFFFF000,
           HIDWORD(v5));
    v15 = v2;
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 0;
  }
  if ( v2 )
    v11 = (__int64 *)&CcNumberAsyncReadPrefetches;
  else
    v11 = (__int64 *)&CcNumberAsyncReadCacheHits;
  v12 = *v11 + 1;
  __dmb(0xBu);
  *v11 = v12;
  v13 = *(_DWORD **)(v4 + 24);
  if ( CcEnableReadAheadInAsyncRead && v15 )
  {
    if ( !v13 )
      return 1;
    if ( (*v13 & 0x20000) == 0 )
      CcScheduleReadAheadEx(v4, _50, v6, 0);
  }
  if ( v13 )
    CcUpdateReadHistory(v4, _50, v6);
  return 1;
}
