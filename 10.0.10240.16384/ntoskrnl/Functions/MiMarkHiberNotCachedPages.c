// MiMarkHiberNotCachedPages 
 
void __fastcall MiMarkHiberNotCachedPages(int a1, unsigned int *a2, unsigned int a3, int a4)
{
  unsigned int *i; // r4
  unsigned int v7; // r5
  int v8; // r3
  int v9; // r3
  const void *v10; // r2
  unsigned int v11; // r5
  int v12; // r3

  for ( i = a2; (unsigned int)i <= a3; ++i )
  {
    if ( a4 )
    {
      v7 = *i >> 12;
      if ( !MI_IS_PFN(v7) )
        continue;
      v8 = *(unsigned __int8 *)(MmPfnDatabase + 24 * v7 + 18) >> 6;
      if ( v8 )
      {
        if ( v8 != 2 )
          continue;
      }
      v9 = 1024;
      v10 = (const void *)v7;
    }
    else
    {
      v11 = *i;
      if ( (*i & 2) == 0 )
        continue;
      v12 = (v11 >> 2) & 3;
      if ( v12 != 3 && v12 != 1 )
        continue;
      if ( !MI_IS_PFN(v11 >> 12) )
        continue;
      v9 = 1;
      v10 = (const void *)(v11 >> 12);
    }
    PoSetHiberRange(0, 81920, v10, (const void *)v9, 1668181325);
  }
}
