// MiInitializeDummyPages 
 
int __fastcall MiInitializeDummyPages(int a1)
{
  int v1; // r0
  int v2; // r0

  v1 = MiAllocateDummyPage(a1);
  *(_DWORD *)(v1 + 8) = 32;
  dword_634900 = (v1 - MmPfnDatabase) / 24;
  v2 = MxFillPhysicalPage((v1 - MmPfnDatabase) / 24, 0);
  dword_6348F0 = MiAllocateDummyPage(v2);
  *(_DWORD *)(dword_6348F0 + 8) = 32;
  dword_6348F4 = (dword_6348F0 - MmPfnDatabase) / 24;
  return MxFillPhysicalPage(dword_6348F4, -1);
}
