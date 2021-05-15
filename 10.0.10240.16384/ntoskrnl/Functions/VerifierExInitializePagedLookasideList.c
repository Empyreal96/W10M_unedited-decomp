// VerifierExInitializePagedLookasideList 
 
int __fastcall VerifierExInitializePagedLookasideList(unsigned int a1, int a2, int a3, int a4, unsigned int a5, int a6, unsigned __int16 a7)
{
  BOOL v11; // r7
  int v12; // r2
  BOOL v13; // r1
  unsigned int vars4; // [sp+3Ch] [bp+4h]

  v11 = VfTargetDriversIsEnabled(vars4, a2);
  if ( v11 )
  {
    if ( a5 < 4 && (MmVerifierData & 1) != 0 )
      VerifierBugCheckIfAppropriate(196, 205, a1, a5, 4);
    VfUtilSynchronizationObjectSanityChecks(a1, 128);
    v12 = 0;
  }
  else
  {
    v12 = a7;
  }
  pXdvExInitializePagedLookasideList(a1, a2, a3, a4, a5, a6, v12, v11, ExInitializePagedLookasideListInternal);
  v13 = v11 || KernelVerifier;
  return ViLookasideTrackList(a1, v13);
}
