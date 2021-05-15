// RawSetInformation 
 
int __fastcall RawSetInformation(int a1, int a2, int a3)
{
  int v4; // r2
  int v7; // r4
  _DWORD *v8; // r4
  int v9; // r8
  int v10; // r3
  int v11; // r2

  v4 = *(_DWORD *)(a1 + 148);
  if ( v4 && *(_DWORD *)(a3 + 28) == v4 || ExAcquireRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1) )
  {
    v8 = *(_DWORD **)(a2 + 12);
    v9 = *(_DWORD *)(a3 + 28);
    if ( *(_DWORD *)(a3 + 12) == 14 )
    {
      if ( (*v8 & *(_DWORD *)(IoGetRelatedDeviceObject(*(_DWORD **)(a3 + 28)) + 92)) != 0 )
      {
        v7 = -1073741811;
      }
      else
      {
        *(_DWORD *)(v9 + 56) = *v8;
        v10 = v8[1];
        v7 = 0;
        *(_DWORD *)(v9 + 60) = v10;
      }
    }
    else
    {
      v7 = -1073741808;
    }
    v11 = *(_DWORD *)(a1 + 148);
    if ( !v11 || *(_DWORD *)(a3 + 28) != v11 )
      ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1);
  }
  else
  {
    v7 = -1073741202;
  }
  *(_DWORD *)(a2 + 24) = v7;
  IofCompleteRequest(a2, 1);
  return v7;
}
