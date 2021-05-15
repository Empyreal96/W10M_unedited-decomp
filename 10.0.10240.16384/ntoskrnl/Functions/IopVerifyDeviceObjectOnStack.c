// IopVerifyDeviceObjectOnStack 
 
int __fastcall IopVerifyDeviceObjectOnStack(int a1, int a2, int a3)
{
  int v5; // r0

  v5 = 0;
  if ( a3 )
    v5 = KeAcquireQueuedSpinLock(10);
  while ( a1 != a2 )
  {
    a1 = *(_DWORD *)(a1 + 16);
    if ( !a1 )
      return sub_53C754(v5);
  }
  if ( a3 )
    KeReleaseQueuedSpinLock(10, v5);
  return 1;
}
