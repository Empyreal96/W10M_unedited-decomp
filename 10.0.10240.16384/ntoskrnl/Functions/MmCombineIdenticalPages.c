// MmCombineIdenticalPages 
 
int MmCombineIdenticalPages()
{
  __int16 *v0; // r0

  __mrc(15, 0, 13, 0, 3);
  v0 = MiGetThreadPartition();
  __mrc(15, 0, 13, 0, 3);
  return MiCombineIdenticalPages(v0);
}
