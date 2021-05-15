// PopFxPepPerfInfoFree 
 
unsigned int *__fastcall PopFxPepPerfInfoFree(unsigned int *result)
{
  unsigned int *v1; // r4
  unsigned int v2; // r6
  _DWORD *v3; // r5
  unsigned int v4; // r0
  unsigned int v5; // r0

  v1 = result;
  if ( result )
  {
    v2 = 0;
    if ( *result )
    {
      v3 = result + 2;
      do
      {
        if ( !v3[5] )
        {
          v4 = v3[7];
          if ( v4 )
            ExFreePoolWithTag(v4);
        }
        v5 = v3[1];
        if ( v5 )
          ExFreePoolWithTag(v5);
        ++v2;
        v3 += 10;
      }
      while ( v2 < *v1 );
    }
    result = (unsigned int *)ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
