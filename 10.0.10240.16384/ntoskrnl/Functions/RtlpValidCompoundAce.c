// RtlpValidCompoundAce 
 
BOOL __fastcall RtlpValidCompoundAce(int a1)
{
  BOOL result; // r0
  unsigned int v2; // r2
  int v3; // r0
  int v4; // t1
  unsigned int v5; // r1
  _BYTE *v6; // r0
  unsigned int v7; // r3

  result = 0;
  if ( a1 )
  {
    v2 = *(unsigned __int16 *)(a1 + 2);
    if ( ((v2 + 3) & 0xFFFFFFFC) == v2 && v2 >= 0x18 && *(_WORD *)(a1 + 8) == 1 )
    {
      v4 = *(unsigned __int8 *)(a1 + 12);
      v3 = a1 + 12;
      if ( v4 == 1 )
      {
        v5 = *(unsigned __int8 *)(v3 + 1);
        if ( v5 <= 0xF && v2 >= 4 * (v5 + 8) )
        {
          v6 = (_BYTE *)(v3 + 4 * (v5 + 2));
          if ( *v6 == 1 )
          {
            v7 = (unsigned __int8)v6[1];
            if ( v7 <= 0xF && v2 >= 4 * (v7 + v5 + 7) )
              result = 1;
          }
        }
      }
    }
  }
  return result;
}
