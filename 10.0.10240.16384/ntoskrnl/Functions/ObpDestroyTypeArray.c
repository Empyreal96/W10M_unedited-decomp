// ObpDestroyTypeArray 
 
unsigned int *__fastcall ObpDestroyTypeArray(unsigned int *result)
{
  unsigned int *v1; // r4
  unsigned int v2; // r6
  unsigned int *v3; // r5
  unsigned int v4; // r3
  unsigned int v5; // t1

  v1 = result;
  if ( result )
  {
    v2 = 0;
    if ( *result )
    {
      v3 = result;
      do
      {
        v5 = v3[1];
        ++v3;
        v4 = v5;
        if ( v5 )
          ObfDereferenceObject(v4 + 40);
        ++v2;
      }
      while ( v2 < *v1 );
    }
    result = (unsigned int *)ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
