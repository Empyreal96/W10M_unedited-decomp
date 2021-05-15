// ExpSaBinaryArrayInsert 
 
int __fastcall ExpSaBinaryArrayInsert(unsigned int **a1, unsigned int a2)
{
  unsigned int v4; // r6
  unsigned int *v5; // r4
  unsigned int v6; // r7
  unsigned int *v7; // r0
  int i; // r0

  v4 = 0;
  while ( 1 )
  {
    v5 = *a1;
    v6 = 1 << (v4 + 2);
    if ( !*a1 )
    {
      v7 = (unsigned int *)ExAllocatePoolWithTag(512, 4 * (v6 + 1));
      v5 = v7;
      if ( !v7 )
        return -1;
      memset(v7, 0, 4 * (v6 + 1));
      if ( !v5 )
        return -1;
      *a1 = v5;
    }
    if ( *v5 < v6 )
      break;
    ++v4;
    ++a1;
    if ( v4 >= 0x10 )
      return -1;
  }
  for ( i = *v5; v5[i + 1]; i = (i + 1) & (v6 - 1) )
    ;
  ++*v5;
  v5[i + 1] = a2;
  return i | (1 << (v4 + 2));
}
