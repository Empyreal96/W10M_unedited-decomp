// IsEncodedAttributeChar 
 
BOOL __fastcall IsEncodedAttributeChar(unsigned int a1)
{
  BOOL result; // r0
  const __int16 *v3; // r1
  int v4; // r2
  int v5; // t1

  result = 1;
  if ( a1 < 0x7F )
  {
    result = iswalnum(a1) == 0;
    if ( result )
    {
      v3 = L"#$'*+-./:;?@[\\]^_`{}~";
      v4 = 0;
      while ( 1 )
      {
        v5 = *(unsigned __int16 *)v3++;
        if ( v5 == a1 )
          break;
        if ( (unsigned int)++v4 >= 0x15 )
          return result;
      }
      result = 0;
    }
  }
  return result;
}
