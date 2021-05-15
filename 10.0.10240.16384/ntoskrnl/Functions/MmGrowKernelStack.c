// MmGrowKernelStack 
 
int __fastcall MmGrowKernelStack(int a1)
{
  return MmGrowKernelStackEx(a1, 12288);
}
