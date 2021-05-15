// RawQueryFsVolumeInfo 
 
int __fastcall RawQueryFsVolumeInfo(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r1
  int v9; // r3

  v5 = *(_DWORD *)(a1 + 148);
  if ( (!v5 || a2 != v5) && !ExAcquireRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1) )
    return -1073741202;
  memset((_BYTE *)a3, 0, 24);
  *(_DWORD *)(a3 + 8) = *(_DWORD *)(*(_DWORD *)(a1 + 140) + 16);
  *(_BYTE *)(a3 + 16) = 0;
  *(_DWORD *)(a3 + 12) = 0;
  *a4 -= 18;
  v9 = *(_DWORD *)(a1 + 148);
  if ( !v9 || a2 != v9 )
    ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1);
  return 0;
}
