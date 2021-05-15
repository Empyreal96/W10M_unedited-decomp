// MmAllocateContiguousMemory 
 
int __fastcall MmAllocateContiguousMemory(unsigned int a1, __int64 a2)
{
  unsigned int v3; // r2

  v3 = a2 >> 12;
  if ( v3 > dword_633850 )
    v3 = dword_633850;
  return MiAllocateContiguousMemory(a1, 0, v3, 0, 6u, 0x80000000);
}
