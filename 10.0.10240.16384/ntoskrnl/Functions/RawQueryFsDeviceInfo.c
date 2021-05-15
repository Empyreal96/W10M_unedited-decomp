// RawQueryFsDeviceInfo 
 
int __fastcall RawQueryFsDeviceInfo(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v9; // r3
  int v10; // r3

  if ( *a4 < 8u )
    return -2147483643;
  v9 = *(_DWORD *)(a1 + 148);
  if ( (!v9 || a2 != v9) && !ExAcquireRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1) )
    return -1073741202;
  *a3 = 0;
  a3[1] = 0;
  *a3 = 7;
  a3[1] = *(_DWORD *)(*(_DWORD *)(a1 + 136) + 32);
  *a4 -= 8;
  v10 = *(_DWORD *)(a1 + 148);
  if ( !v10 || a2 != v10 )
    ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1);
  return 0;
}
