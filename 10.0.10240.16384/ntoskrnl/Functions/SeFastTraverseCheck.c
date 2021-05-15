// SeFastTraverseCheck 
 
int __fastcall SeFastTraverseCheck(int a1, int a2, int a3)
{
  int v5; // r3
  int v6; // r2
  unsigned int v7; // r5
  unsigned int v8; // r6
  int v9; // r4
  unsigned __int16 *v10; // r8

  if ( !a1 )
    return 0;
  if ( (*(_WORD *)(a1 + 2) & 4) != 0 )
  {
    if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
    {
      v5 = *(_DWORD *)(a1 + 16);
      if ( !v5 )
        return 1;
      v6 = v5 + a1;
    }
    else
    {
      v6 = *(_DWORD *)(a1 + 16);
    }
    if ( v6 )
    {
      v7 = *(unsigned __int16 *)(v6 + 4);
      if ( *(_WORD *)(v6 + 4) )
      {
        if ( (*(_DWORD *)(a2 + 12) & 0x810) == 0 )
        {
          v8 = 0;
          v9 = v6 + 8;
          if ( *(_WORD *)(v6 + 4) )
          {
            v10 = (unsigned __int16 *)SeWorldSid;
            while ( 1 )
            {
              if ( (*(_BYTE *)(v9 + 1) & 8) == 0 )
              {
                if ( *(_BYTE *)v9 )
                {
                  if ( *(_BYTE *)v9 == 1 && (a3 & *(_DWORD *)(v9 + 4)) != 0 )
                    return 0;
                }
                else if ( (a3 & *(_DWORD *)(v9 + 4)) != 0 && RtlEqualSid(v10, (unsigned __int16 *)(v9 + 8)) )
                {
                  return 1;
                }
              }
              ++v8;
              v9 += *(unsigned __int16 *)(v9 + 2);
              if ( v8 >= v7 )
                return 0;
            }
          }
        }
      }
      return 0;
    }
  }
  return 1;
}
