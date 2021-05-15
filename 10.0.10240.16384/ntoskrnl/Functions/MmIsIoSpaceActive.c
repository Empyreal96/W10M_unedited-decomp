// MmIsIoSpaceActive 
 
int __fastcall MmIsIoSpaceActive(__int64 a1, unsigned int a2, int a3)
{
  return MiIsProbeActive((unsigned int *)(a1 >> 12), ((a1 + a2 - 1) >> 12) - (a1 >> 12) + 1, 0);
}
