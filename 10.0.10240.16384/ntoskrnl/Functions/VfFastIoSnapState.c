// VfFastIoSnapState 
 
int VfFastIoSnapState()
{
  int v1; // r0

  if ( !ViIoCallbacksInitialized || (MmVerifierData & 0x10) == 0 )
    return 0;
  v1 = KeAreInterruptsEnabled();
  if ( !v1 )
    v1 = VerifierBugCheckIfAppropriate(196, 194, 0);
  return ViIoCallbackSnapState(v1);
}
