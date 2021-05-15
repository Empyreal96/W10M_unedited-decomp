// MiAllocatingNonPagedPoolVa 
 
unsigned int __fastcall MiAllocatingNonPagedPoolVa(unsigned int result, int a2, int a3, int a4)
{
  unsigned int v4; // r6
  unsigned int v5; // lr
  unsigned int v6; // r7
  unsigned int i; // r4
  int *v8; // r1
  unsigned int j; // r2
  int v10; // t1

  v4 = a3 + a4;
  v5 = result + 8 * (a2 + 18);
  v6 = result;
  for ( i = a3 & 0xFFFFFC00; i < v4; i += 1024 )
  {
    v8 = (int *)(*(_DWORD *)(v6 + 164) + 4 * (i >> 5));
    for ( j = 0; j < 0x20; ++j )
    {
      v10 = *v8++;
      if ( v10 != -1 )
        break;
    }
    if ( j == 32 )
    {
      result = i >> 13;
      *(_BYTE *)((i >> 13) + *(_DWORD *)(v5 + 4)) |= 1 << ((i >> 10) & 7);
    }
  }
  return result;
}
