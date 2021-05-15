// MiEnumerateKernelLeafPtes 
 
unsigned int MiEnumerateKernelLeafPtes()
{
  unsigned int v0; // r0

  v0 = MmSystemRangeStart;
  if ( MmSystemRangeStart == -1073741824 )
    v0 = -1069547520;
  return MiEnumerateLeafPtes(
           v0,
           0xFFFFFFFF,
           (int (__fastcall *)(int, unsigned int, unsigned int))MiMarkHiberNotCachedPages,
           0);
}
