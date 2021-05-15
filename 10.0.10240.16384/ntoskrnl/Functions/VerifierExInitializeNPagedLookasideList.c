// VerifierExInitializeNPagedLookasideList 
 
int __fastcall VerifierExInitializeNPagedLookasideList(unsigned int a1, int a2, int a3, int a4, unsigned int a5, int a6, unsigned __int16 a7)
{
  int v8; // r4
  BOOL v11; // r9
  int v12; // r2
  BOOL v13; // r1
  unsigned int vars4; // [sp+3Ch] [bp+4h]

  v8 = a2;
  v11 = VfTargetDriversIsEnabled(vars4, a2);
  if ( v11 )
  {
    VfCheckPoolType(a4, vars4, a6);
    if ( a5 < 4 )
    {
      if ( (MmVerifierData & 1) != 0 )
        VerifierBugCheckIfAppropriate(196, 205, a1, a5, 4);
      v8 = a2;
    }
    VfUtilSynchronizationObjectSanityChecks(a1, 128);
    v12 = 0;
  }
  else
  {
    v12 = a7;
  }
  pXdvExInitializeNPagedLookasideList(a1, v8, a3, a4, a5, a6, v12, v11, ExInitializeNPagedLookasideListInternal);
  v13 = v11 || KernelVerifier;
  return ViLookasideTrackList(a1, v13);
}
