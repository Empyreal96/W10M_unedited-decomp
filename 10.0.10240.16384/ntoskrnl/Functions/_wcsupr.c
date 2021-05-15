// _wcsupr 
 
unsigned __int16 *__fastcall wcsupr(unsigned __int16 *result)
{
  unsigned __int16 *v1; // r2
  unsigned int v2; // r3
  int v3; // t1

  v1 = result;
  if ( *result )
  {
    do
    {
      v2 = *v1;
      if ( v2 >= 0x61 && v2 <= 0x7A )
        *v1 = v2 - 32;
      v3 = v1[1];
      ++v1;
    }
    while ( v3 );
  }
  return result;
}
