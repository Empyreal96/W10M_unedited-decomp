// VerifierIoVolumeDeviceToDosName 
 
int __fastcall VerifierIoVolumeDeviceToDosName(int a1, int a2)
{
  int v4; // r0

  if ( (MmVerifierData & 0x10) != 0 )
  {
    v4 = KeGetCurrentIrql(a1);
    if ( v4 )
      VerifierBugCheckIfAppropriate(196, 229, v4, 0, 0);
  }
  return pXdvIoVolumeDeviceToDosName(a1, a2);
}
