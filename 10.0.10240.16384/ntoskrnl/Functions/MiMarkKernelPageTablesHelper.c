// MiMarkKernelPageTablesHelper 
 
unsigned int __fastcall MiMarkKernelPageTablesHelper(unsigned int result, unsigned int a2, int a3)
{
  unsigned int v5; // r4

  v5 = result;
  if ( a3 != 1 )
  {
    while ( v5 <= a2 )
    {
      result = *(_DWORD *)v5;
      if ( (*(_DWORD *)v5 & 2) != 0 && (a3 != 2 || (result & 0x400) == 0) )
      {
        PoSetHiberRange(0, 81920, (const void *)(result >> 12), (const void *)1, 1886088525);
        result = MiMarkKernelPageTablesHelper(v5 << 10, (v5 << 10) + 4092, a3 - 1);
      }
      v5 += 4;
    }
  }
  return result;
}
