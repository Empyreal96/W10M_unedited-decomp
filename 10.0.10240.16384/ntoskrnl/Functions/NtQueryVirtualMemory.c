// NtQueryVirtualMemory 
 
int __fastcall NtQueryVirtualMemory(int a1, int a2, int a3)
{
  return MmQueryVirtualMemory(a1, a2, a3);
}
