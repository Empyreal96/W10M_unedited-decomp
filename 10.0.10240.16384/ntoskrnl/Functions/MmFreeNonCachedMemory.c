// MmFreeNonCachedMemory 
 
int __fastcall MmFreeNonCachedMemory(unsigned int a1, unsigned int a2)
{
  BOOL v3; // r6
  _DWORD *v4; // r5
  int v5; // r3
  unsigned int v6; // r4

  v3 = (a2 & 0xFFF) != 0;
  v4 = (_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  v5 = MmPfnDatabase + 24 * (*v4 >> 12);
  v6 = *(_DWORD *)(v5 + 8);
  *(_DWORD *)(v5 + 8) = 128;
  MmFreePagesFromMdl(v6, a2, 128, v5);
  ExFreePoolWithTag(v6);
  return MiReleasePtes(&dword_634D58, (unsigned int)v4, v3 + (a2 >> 12));
}
