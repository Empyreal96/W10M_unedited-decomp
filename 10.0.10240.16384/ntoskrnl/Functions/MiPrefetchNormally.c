// MiPrefetchNormally 
 
BOOL __fastcall MiPrefetchNormally(int a1)
{
  int v2; // r1

  return *(int *)(a1 + 3840) >= 128
      && (unsigned int)MiCommitmentAvailable() >= 0x1000
      && MiGetAvailablePagesBelowPriority(a1, v2);
}
