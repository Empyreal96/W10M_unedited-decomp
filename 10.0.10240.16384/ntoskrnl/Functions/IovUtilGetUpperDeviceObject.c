// IovUtilGetUpperDeviceObject 
 
int __fastcall IovUtilGetUpperDeviceObject(int a1)
{
  int v2; // r0
  int v3; // r4
  int v4; // r5

  v2 = KeAcquireQueuedSpinLock(10);
  v3 = *(_DWORD *)(a1 + 16);
  v4 = v2;
  if ( v3 )
    ObfReferenceObject(v3);
  KeReleaseQueuedSpinLock(10, v4);
  return v3;
}
