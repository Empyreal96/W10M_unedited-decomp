// MiAdvanceVadHint 
 
unsigned int __fastcall MiAdvanceVadHint(unsigned int result, unsigned int a2)
{
  unsigned int v2; // r6
  unsigned int v3; // r5
  int v4; // r4
  unsigned int v5; // r3
  int v6; // r1
  unsigned int v7; // r5
  unsigned int v8; // r4

  v2 = (unsigned __int16)(a2 >> 4);
  v3 = (unsigned __int16)(result >> 4);
  v4 = MEMORY[0xC040212C] + 1069547520;
  if ( v2 >= 8 * (MEMORY[0xC040212C] + 1069547520) )
  {
    v5 = MEMORY[0xC0402114] + 8 * v4;
    if ( v3 < v5 )
    {
      v6 = 0;
      if ( v3 >= 8 * v4 )
      {
        if ( v2 >= v5 )
        {
          v2 = v5 - 1;
          v6 = 1;
        }
        result = v2 - v3 + 1;
        v7 = v3 - 8 * v4;
        v8 = v2 - 8 * v4;
        if ( result == 1 && !v6 || v7 == MEMORY[0xC0402104] )
        {
          if ( MEMORY[0xC0402108] < v8 + 1 )
          {
            MEMORY[0xC0402108] = v8 + 1;
            if ( MEMORY[0xC040210C] < result )
              MEMORY[0xC040210C] = result;
          }
          MEMORY[0xC0402104] = v8 + 1;
        }
        else if ( v6 != 1 )
        {
          MEMORY[0xC0402108] = v8 + 1;
          MEMORY[0xC040210C] = result;
        }
      }
      else
      {
        result = sub_802478();
      }
    }
  }
  return result;
}
