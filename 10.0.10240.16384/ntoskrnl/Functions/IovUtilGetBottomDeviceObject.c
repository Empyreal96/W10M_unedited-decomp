// IovUtilGetBottomDeviceObject 
 
int __fastcall IovUtilGetBottomDeviceObject(int a1)
{
  int v2; // r6
  int v3; // r5

  v2 = KeAcquireQueuedSpinLock(10);
  do
  {
    v3 = a1;
    a1 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 24);
  }
  while ( a1 );
  ObfReferenceObject(v3);
  KeReleaseQueuedSpinLock(10, v2);
  return v3;
}
