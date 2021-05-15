// IovUtilGetLowerDeviceObject 
 
int __fastcall IovUtilGetLowerDeviceObject(int a1)
{
  int v2; // r0
  int v3; // r3
  int v4; // r5
  int v5; // r4

  v2 = KeAcquireQueuedSpinLock(10);
  v3 = *(_DWORD *)(a1 + 176);
  v4 = v2;
  v5 = *(_DWORD *)(v3 + 24);
  if ( v5 )
    ObfReferenceObject(*(_DWORD *)(v3 + 24));
  KeReleaseQueuedSpinLock(10, v4);
  return v5;
}
