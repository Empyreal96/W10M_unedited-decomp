// MiCompressImportList 
 
unsigned int *__fastcall MiCompressImportList(unsigned int *a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r3
  int v3; // r6
  int v4; // r5
  unsigned int v5; // r2
  unsigned int v6; // r1
  unsigned int v7; // t1
  _DWORD *v9; // r0
  unsigned int v10; // r1
  _DWORD *v11; // r2
  unsigned int *v12; // r5
  unsigned int v13; // r3
  unsigned int v14; // t1

  v1 = a1;
  v2 = *a1;
  v3 = 0;
  v4 = 0;
  if ( !*a1 )
    goto LABEL_19;
  v5 = *a1;
  do
  {
    v7 = a1[1];
    ++a1;
    v6 = v7;
    if ( v7 )
    {
      v3 = v6 | 1;
      ++v4;
    }
    --v5;
  }
  while ( v5 );
  if ( v4 == 1 )
    goto LABEL_11;
  if ( !v4 )
  {
LABEL_19:
    v3 = -2;
LABEL_11:
    ExFreePoolWithTag((unsigned int)v1);
    return (unsigned int *)v3;
  }
  if ( v4 != v2 )
  {
    v9 = (_DWORD *)ExAllocatePoolWithTag(257, 4 * (v4 + 1), 1413770573);
    if ( v9 )
    {
      *v9 = v4;
      v10 = 0;
      if ( *v1 )
      {
        v11 = v9;
        v12 = v1;
        do
        {
          v14 = v12[1];
          ++v12;
          v13 = v14;
          if ( v14 )
          {
            v11[1] = v13;
            ++v11;
          }
          ++v10;
        }
        while ( v10 < *v1 );
      }
      v3 = (int)v9;
      goto LABEL_11;
    }
  }
  return v1;
}
