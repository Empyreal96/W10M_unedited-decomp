// SepAdtIncorporatePerUserPolicy 
 
unsigned int __fastcall SepAdtIncorporatePerUserPolicy(unsigned int result, int a2, int a3, int a4, _BYTE *a5)
{
  int v5; // r3

  if ( *(_BYTE *)(a4 + 118) == 2 )
  {
    v5 = (*(unsigned __int8 *)(a4 + (result >> 1) + 88) >> (4 * (result & 1))) & 0xF;
    if ( v5 )
    {
      if ( a2 && (v5 & 1) != 0 || a3 && (v5 & 4) != 0 )
      {
        *a5 = 1;
      }
      else if ( a2 && (v5 & 2) != 0 || a3 && (v5 & 8) != 0 )
      {
        *a5 = 0;
      }
    }
  }
  return result;
}
