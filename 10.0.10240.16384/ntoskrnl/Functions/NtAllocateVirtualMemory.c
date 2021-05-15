// NtAllocateVirtualMemory 
 
int __fastcall NtAllocateVirtualMemory(int a1, int a2, int a3, int a4, int a5)
{
  __mrc(15, 0, 13, 0, 3);
  return MiAllocateVirtualMemory(a1, a2, a3, a4, a5);
}
