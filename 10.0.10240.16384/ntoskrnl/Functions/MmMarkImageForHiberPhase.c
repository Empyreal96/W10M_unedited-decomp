// MmMarkImageForHiberPhase 
 
unsigned int __fastcall MmMarkImageForHiberPhase(unsigned int a1)
{
  int *v1; // r0

  v1 = MiLookupDataTableEntry(a1, 1);
  return MiEnumerateLeafPtes(
           v1[6],
           (v1[8] + v1[6]) & 0xFFFFF000,
           (int (__fastcall *)(int, unsigned int, unsigned int))MiMarkNonPagedHiberPhasePages,
           0);
}
