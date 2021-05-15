// PspDeleteKernelStack 
 
int __fastcall PspDeleteKernelStack(int a1, unsigned int *a2)
{
  return MmDeleteKernelStack(*a2, 4);
}
