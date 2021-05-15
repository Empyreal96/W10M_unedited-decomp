// VerifierKeSetEvent 
 
int __fastcall VerifierKeSetEvent(unsigned int a1, int a2, int a3)
{
  int v3; // r4
  unsigned int v6; // r0

  v3 = a1;
  if ( a1 < MmHighestUserAddress || a1 + 16 < a1 )
    a1 = VerifierBugCheckIfAppropriate(196, 224, a1, 16, 0);
  if ( (MmVerifierData & 0x20000) == 0 )
  {
    v6 = KeGetCurrentIrql(a1);
    if ( v6 > 2 )
      VerifierBugCheckIfAppropriate(196, 128, v6, v3, 0);
  }
  return pXdvKeSetEvent(v3, a2, a3);
}
