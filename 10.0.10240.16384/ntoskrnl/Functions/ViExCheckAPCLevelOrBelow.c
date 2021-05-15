// ViExCheckAPCLevelOrBelow 
 
unsigned int __fastcall ViExCheckAPCLevelOrBelow(int a1, int a2, int a3)
{
  unsigned int v5; // r0
  unsigned int v6; // r5

  v5 = KeGetCurrentIrql(a1);
  v6 = v5;
  if ( !a3 && v5 > 1 )
    VerifierBugCheckIfAppropriate(196, 51, v5, a2, 0);
  return v6;
}
