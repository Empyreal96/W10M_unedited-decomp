// AslHashFree 
 
int *__fastcall AslHashFree(int *result)
{
  int *v1; // r5
  int v2; // r6
  unsigned int v3; // r0
  unsigned int v4; // r4
  unsigned int v5; // r0

  v1 = result;
  if ( result )
  {
    if ( result[1] )
    {
      v2 = 0;
      if ( *result > 0 )
      {
        do
        {
          v3 = *(_DWORD *)(v1[1] + 4 * v2);
          if ( v3 )
          {
            do
            {
              v4 = *(_DWORD *)(v3 + 8);
              ExFreePoolWithTag(v3);
              v3 = v4;
            }
            while ( v4 );
          }
          ++v2;
        }
        while ( v2 < *v1 );
      }
      v5 = v1[1];
      if ( v5 )
        ExFreePoolWithTag(v5);
    }
    result = (int *)ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
