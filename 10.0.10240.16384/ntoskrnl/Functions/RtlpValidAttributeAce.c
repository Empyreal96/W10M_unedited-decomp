// RtlpValidAttributeAce 
 
BOOL __fastcall RtlpValidAttributeAce(int a1)
{
  BOOL result; // r0
  unsigned int v2; // r2
  int v3; // r0
  int v4; // t1
  unsigned int v5; // r3
  int v6; // r4

  result = 0;
  if ( a1 )
  {
    v2 = *(unsigned __int16 *)(a1 + 2);
    if ( ((v2 + 3) & 0xFFFFFFFC) == v2 && v2 >= 0x10 )
    {
      v4 = *(unsigned __int8 *)(a1 + 8);
      v3 = a1 + 8;
      if ( v4 == 1 )
      {
        v5 = *(unsigned __int8 *)(v3 + 1);
        if ( v5 <= 0xF )
        {
          v6 = 4 * (v5 + 2);
          if ( v2 >= v6 + 28 )
          {
            if ( RtlpValidRelativeAttribute(v3 + v6, v2 - v6 - 8) )
              result = 1;
          }
        }
      }
    }
  }
  return result;
}
