// RtlBackoff 
 
unsigned int *__fastcall RtlBackoff(unsigned int *result)
{
  unsigned int v1; // r4
  unsigned int v2; // [sp+0h] [bp-8h]

  v1 = *result;
  if ( *result )
  {
    if ( v1 < 0x1FFF )
      v1 *= 2;
  }
  else
  {
    if ( KeNumberProcessors_0 == 1 )
      return result;
    v1 = 64;
  }
  *result = v1;
  result = (unsigned int *)(((v1 - 1) & ReadTimeStampCounter()) + v1);
  v2 = 0;
  if ( result )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      ++v2;
    }
    while ( v2 < (unsigned int)result );
  }
  return result;
}
