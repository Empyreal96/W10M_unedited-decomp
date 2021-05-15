// WmipHexStringToDword 
 
BOOL __fastcall WmipHexStringToDword(unsigned __int16 *a1, int *a2, unsigned int a3, int a4)
{
  int v4; // r5
  unsigned int i; // r6
  unsigned int v6; // r4
  unsigned int v7; // t1
  BOOL result; // r0

  v4 = 0;
  for ( i = 0; i < a3; ++i )
  {
    v7 = *a1++;
    v6 = v7;
    if ( v7 > 0x39 || v6 < 0x30 )
    {
      if ( v6 > 0x46 || v6 < 0x41 )
      {
        if ( v6 < 0x61 || v6 > 0x66 )
          return 0;
        v4 = v6 + 16 * v4 - 87;
      }
      else
      {
        v4 = v6 + 16 * v4 - 55;
      }
    }
    else
    {
      v4 = v6 + 16 * v4 - 48;
    }
  }
  *a2 = v4;
  if ( a4 )
    result = *a1 == a4;
  else
    result = 1;
  return result;
}
