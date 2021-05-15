// IovUtilMultipleDevicesSameDriver 
 
int __fastcall IovUtilMultipleDevicesSameDriver(int a1)
{
  int v2; // r5
  int v3; // r6
  int v4; // r0
  int i; // r2

  v2 = 0;
  v3 = *(_DWORD *)(a1 + 8);
  v4 = KeAcquireQueuedSpinLock(10);
  for ( i = *(_DWORD *)(a1 + 16); i; i = *(_DWORD *)(i + 16) )
  {
    if ( *(_DWORD *)(i + 8) == v3 )
    {
      v2 = 1;
      break;
    }
  }
  KeReleaseQueuedSpinLock(10, v4);
  return v2;
}
