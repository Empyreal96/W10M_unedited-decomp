// IopGetDevicePDO 
 
int __fastcall IopGetDevicePDO(int a1)
{
  int v2; // r5
  int v3; // r0
  int v4; // r4

  v2 = KeAcquireQueuedSpinLock(10);
  v3 = IopGetDeviceAttachmentBase(a1);
  v4 = v3;
  if ( (*(_DWORD *)(v3 + 28) & 0x1000) != 0 )
    ObfReferenceObjectWithTag(v3);
  else
    v4 = 0;
  KeReleaseQueuedSpinLock(10, v2);
  return v4;
}
