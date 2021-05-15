// MmAllocateContiguousMemorySpecifyCacheNode 
 
int __fastcall MmAllocateContiguousMemorySpecifyCacheNode(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r1

  if ( a9 == 1 )
  {
    v10 = 64;
  }
  else if ( a9 == 2 )
  {
    v10 = 1028;
  }
  else
  {
    v10 = 516;
  }
  return MmAllocateContiguousNodeMemory(a1, v10, a3, a4, a5, a6, a7, a8, v10, a10);
}
