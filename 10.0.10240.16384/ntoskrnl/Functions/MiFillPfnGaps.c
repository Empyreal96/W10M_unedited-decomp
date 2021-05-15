// MiFillPfnGaps 
 
int MiFillPfnGaps()
{
  __int64 v0; // r0

  if ( !MiInitializeGapFrames(0, &dword_634914) )
    return 0;
  LODWORD(v0) = MmPfnDatabase;
  HIDWORD(v0) = MmPfnDatabase + 24 * dword_633850 + 23;
  MiFillGapAddresses(v0);
  return 1;
}
