// MiClearVadBits 
 
unsigned int __fastcall MiClearVadBits(unsigned int result, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r6
  unsigned int v5; // r7
  int v8; // r3
  unsigned int v9; // r4
  unsigned int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r6
  unsigned int v13; // r1
  unsigned int v14; // r3
  unsigned int v15; // r2
  int v16; // [sp+0h] [bp-20h] BYREF
  int v17; // [sp+4h] [bp-1Ch]

  v16 = a3;
  v17 = a4;
  v4 = HIWORD(result);
  v5 = HIWORD(a2);
  if ( a3 )
  {
    result = (result ^ (*(_DWORD *)(a3 + 16) << 12)) & 0xFFFF0000;
    if ( !result )
      ++v4;
  }
  if ( a4 )
  {
    result = *(_DWORD *)(a4 + 12);
    if ( ((a2 ^ (result << 12)) & 0xFFFF0000) == 0 )
    {
      if ( v5 - 1 > v5 )
        return result;
      --v5;
    }
  }
  v8 = MEMORY[0xC040212C] + 1069547520;
  if ( !v4 )
    return sub_51F71C();
  if ( v4 <= v5 )
  {
    v9 = 8 * v8;
    if ( v5 >= 8 * v8 )
    {
      v10 = MEMORY[0xC0402114] + v9;
      if ( v4 < MEMORY[0xC0402114] + v9 )
      {
        if ( v4 < v9 )
          v4 = v9;
        if ( v5 >= v10 )
          v5 = v10 - 1;
        v11 = v5 - v4;
        v12 = v4 - v9;
        if ( v11 != -1 )
        {
          v16 = MEMORY[0xC0402114];
          v17 = MEMORY[0xC040212C];
          result = RtlClearBits(&v16, v12, v11 + 1);
          if ( MEMORY[0xC0402104] > v12 )
            MEMORY[0xC0402104] = v12;
          v13 = 0;
          if ( a3 )
          {
            v14 = (((*(_DWORD *)(a3 + 16) << 12) | 0xFFFu) + 0xFFFF) >> 16;
            if ( v14 <= v9 )
            {
              v13 = 0;
            }
            else
            {
              v13 = v14 - v9;
              if ( v14 != v9 )
              {
LABEL_21:
                v15 = MEMORY[0xC0402114];
                if ( a4 )
                {
                  result = (unsigned __int16)(*(_DWORD *)(a4 + 12) >> 4);
                  if ( result <= MEMORY[0xC0402114] + v9 )
                    v15 = result - v9;
                }
                if ( v13 < MEMORY[0xC0402108] && v15 - v13 >= MEMORY[0xC040210C] )
                  MEMORY[0xC0402108] = v13;
                return result;
              }
            }
          }
          if ( !v9 )
            v13 = 1;
          goto LABEL_21;
        }
      }
    }
  }
  return result;
}
