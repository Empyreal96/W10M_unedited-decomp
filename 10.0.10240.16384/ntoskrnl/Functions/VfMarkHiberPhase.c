// VfMarkHiberPhase 
 
char *VfMarkHiberPhase()
{
  char *result; // r0
  int v1; // r3

  result = (char *)VfIsVerifierEnabled();
  if ( result )
  {
    if ( ViTrackIrqlQueue )
    {
      v1 = ViTrackIrqlQueueLength;
      __dmb(0xBu);
      PoSetHiberRange(0, 0x10000, (const void *)ViTrackIrqlQueue, (const void *)(32 * v1), 1919510102);
    }
    result = (char *)VfIsVerifierExtensionEnabled();
    if ( result == (char *)1 )
    {
      if ( ViFnExtensionHiberFunc )
        result = PoSetHiberRange(0, 0x10000, ViFnExtensionHiberFunc, 0, 1919510102);
    }
  }
  return result;
}
