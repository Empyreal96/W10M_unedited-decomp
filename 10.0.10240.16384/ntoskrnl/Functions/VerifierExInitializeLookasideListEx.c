// VerifierExInitializeLookasideListEx 
 
int __fastcall VerifierExInitializeLookasideListEx(unsigned int a1, int a2, int a3, int a4, int a5, unsigned int a6, int a7, unsigned __int16 a8)
{
  int v9; // r4
  BOOL v12; // r6
  int v13; // r4
  BOOL v14; // r1
  unsigned int vars4; // [sp+3Ch] [bp+4h]

  v9 = a2;
  v12 = VfTargetDriversIsEnabled(vars4, a2);
  if ( v12 )
  {
    VfCheckPoolType(a4, vars4, a7);
    if ( a6 < 4 )
    {
      if ( (MmVerifierData & 1) != 0 )
        VerifierBugCheckIfAppropriate(196, 205, a1, a6, 4);
      v9 = a2;
    }
    VfUtilSynchronizationObjectSanityChecks(a1, 72);
  }
  v13 = pXdvExInitializeLookasideListEx(a1, v9, a3, a4, a5, a6, a7, a8, v12, ExInitializeLookasideListExInternal);
  if ( v13 >= 0 )
  {
    v14 = v12 || KernelVerifier;
    ViLookasideTrackListEx(a1, v14);
  }
  return v13;
}
