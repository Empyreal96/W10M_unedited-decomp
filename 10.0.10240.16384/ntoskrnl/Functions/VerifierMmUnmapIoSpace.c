// VerifierMmUnmapIoSpace 
 
int __fastcall VerifierMmUnmapIoSpace(int a1, int a2)
{
  unsigned int v4; // r0
  int vars4; // [sp+14h] [bp+4h]

  v4 = KeGetCurrentIrql(a1);
  if ( v4 > 2 )
    VerifierBugCheckIfAppropriate(196, 123, v4, a1, a2);
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetAddToCounter(vars4, 112, 116, -a2);
  return pXdvMmUnmapIoSpace(a1, a2);
}
