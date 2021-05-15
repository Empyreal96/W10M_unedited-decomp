// IoGetDeviceAttachmentBaseRef 
 
int __fastcall IoGetDeviceAttachmentBaseRef(int a1)
{
  int v2; // r5
  int v3; // r4

  v2 = KeAcquireQueuedSpinLock(10);
  v3 = IopGetDeviceAttachmentBase(a1);
  ObfReferenceObjectWithTag(v3, 1953261124);
  KeReleaseQueuedSpinLock(10, v2);
  return v3;
}
