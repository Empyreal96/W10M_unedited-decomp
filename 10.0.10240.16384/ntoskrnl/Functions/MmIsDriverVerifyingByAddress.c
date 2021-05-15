// MmIsDriverVerifyingByAddress 
 
int __fastcall MmIsDriverVerifyingByAddress(unsigned int a1)
{
  unsigned int v2; // r5

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  MiLookupDataTableEntry(a1, 1);
  return sub_7F1008();
}
