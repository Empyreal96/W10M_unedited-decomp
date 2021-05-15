// MmFreeIsrStack 
 
int __fastcall MmFreeIsrStack(int a1)
{
  int v1; // r4

  v1 = a1 - 12288;
  MmFreeIndependentPages(a1 - 12288, 0x3000u);
  return MiReleasePtes(&dword_634D58, (((unsigned int)(v1 - 4096) >> 10) & 0x3FFFFC) - 0x40000000, 1u);
}
