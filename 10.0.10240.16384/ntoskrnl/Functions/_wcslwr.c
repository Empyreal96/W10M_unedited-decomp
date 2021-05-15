// _wcslwr 
 
unsigned __int16 *__fastcall wcslwr(unsigned __int16 *result)
{
  int v1; // r3
  unsigned __int16 *v2; // r2
  unsigned int v3; // r3
  int v4; // t1

  if ( result )
  {
    v1 = *result;
    v2 = result;
    while ( v1 )
    {
      v3 = *v2;
      if ( v3 >= 0x41 && v3 <= 0x5A )
        *v2 = v3 + 32;
      v4 = v2[1];
      ++v2;
      v1 = v4;
    }
  }
  else
  {
    PopPoCoalescinCallback();
    result = 0;
  }
  return result;
}
