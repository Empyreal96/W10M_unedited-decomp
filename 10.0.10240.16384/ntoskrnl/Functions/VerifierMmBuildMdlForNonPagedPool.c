// VerifierMmBuildMdlForNonPagedPool 
 
int __fastcall VerifierMmBuildMdlForNonPagedPool(int a1)
{
  unsigned int v2; // r5

  if ( !KeGetCurrentIrql(a1) )
  {
    v2 = *(_DWORD *)(a1 + 16);
    if ( MmDeterminePoolType(v2) )
      VerifierBugCheckIfAppropriate(196, 127, 0, a1, v2);
  }
  return pXdvMmBuildMdlForNonPagedPool(a1);
}
