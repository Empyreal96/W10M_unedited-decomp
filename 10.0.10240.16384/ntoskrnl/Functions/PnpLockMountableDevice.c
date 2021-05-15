// PnpLockMountableDevice 
 
int __fastcall PnpLockMountableDevice(int result)
{
  int v1; // r4
  int v2; // r0

  v1 = result;
  while ( v1 )
  {
    if ( *(_DWORD *)(v1 + 36) )
      KeWaitForSingleObject(v1 + 156, 0, 0, 0, 0);
    v2 = KeAcquireQueuedSpinLock(10);
    v1 = *(_DWORD *)(v1 + 16);
    result = KeReleaseQueuedSpinLock(10, v2);
  }
  return result;
}
