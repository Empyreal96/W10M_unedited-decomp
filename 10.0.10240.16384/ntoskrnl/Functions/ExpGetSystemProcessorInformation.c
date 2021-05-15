// ExpGetSystemProcessorInformation 
 
int __fastcall ExpGetSystemProcessorInformation(int a1)
{
  *(_WORD *)a1 = KeProcessorArchitecture;
  *(_WORD *)(a1 + 2) = KeProcessorLevel;
  *(_WORD *)(a1 + 4) = KeProcessorRevision;
  *(_WORD *)(a1 + 6) = KeQueryMaximumProcessorCountEx(0xFFFF);
  *(_DWORD *)(a1 + 8) = KeFeatureBits;
  return 0;
}
