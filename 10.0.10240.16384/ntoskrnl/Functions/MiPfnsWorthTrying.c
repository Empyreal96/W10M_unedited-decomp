// MiPfnsWorthTrying 
 
int __fastcall MiPfnsWorthTrying(int a1, unsigned int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  _DWORD *v6; // lr
  _DWORD *v8; // r1
  unsigned int v10; // r5
  unsigned int v12; // r2
  int v14; // r2
  int v15; // r0
  int *v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  int *v19; // r2
  unsigned int v20; // r1

  v6 = a5;
  v8 = a6;
  v10 = a2 + 24 * a3;
  *a6 = 0;
  *a5 = 0;
  if ( a2 >= v10 )
    return 0;
  while ( !a1 )
  {
    v12 = *(_BYTE *)(a2 + 18) & 7;
    if ( v12 <= 1 )
    {
      if ( (*(_DWORD *)(a2 + 20) & 0xFFFFF) == 1048574 && (a4 & 0x2000000) != 0 )
        return (int)(v10 - a2) / 24;
      ++*v8;
    }
    else if ( v12 == 5 )
    {
      if ( (*(_DWORD *)(a2 + 4) | 0x80000000) == -4 )
        return (int)(v10 - a2) / 24;
      if ( !*(_DWORD *)a2 )
      {
        v16 = MiState;
        v17 = (int)(a2 - MmPfnDatabase) / 24;
        v18 = 0;
        while ( v17 != v16[1957] )
        {
          ++v18;
          ++v16;
          if ( v18 >= 2 )
          {
            v19 = MiState;
            v20 = 0;
            while ( v17 != v19[1955] )
            {
              ++v20;
              ++v19;
              if ( v20 >= 2 )
                goto LABEL_18;
            }
            return (int)(v10 - a2) / 24;
          }
        }
        return (int)(v10 - a2) / 24;
      }
    }
    else
    {
      if ( (*(_BYTE *)(a2 + 19) & 0x80) == 128 )
        return sub_513A4C();
      if ( v12 <= 4 )
      {
        if ( *(_WORD *)(a2 + 16) || (a4 & 0x4000000) == 0 && (*(_DWORD *)(a2 + 4) & 0x80000000) == 0 )
          return (int)(v10 - a2) / 24;
LABEL_18:
        v8 = a6;
        goto LABEL_19;
      }
      if ( v12 != 6 )
        return (int)(v10 - a2) / 24;
      v14 = *(_DWORD *)(a2 + 20);
      if ( (v14 & 0x7000000) != 0x2000000 )
      {
        if ( (a4 & 0x1000000) != 0 && (v14 & 0x8000000) != 0 && (*(_DWORD *)(a2 + 12) & 0x3FFFFFFFu) > 1 )
          return (int)(v10 - a2) / 24;
        v15 = MiActivePageClaimCandidate(a2, 0);
        if ( v15 )
          return (int)(24 * v15 - a2 + v10 - 24) / 24;
        if ( (a4 & 8) != 0 )
          return (int)(v10 - a2) / 24;
        v6 = a5;
        goto LABEL_18;
      }
      if ( (a4 & 8) != 0 || *(_DWORD *)a2 == -5 )
        return (int)(v10 - a2) / 24;
      v8 = a6;
      if ( (*(_DWORD *)a2 & 1) == 0 )
        *v6 = 1;
    }
LABEL_19:
    a2 += 24;
    if ( a2 >= v10 )
      return 0;
  }
  return (int)(v10 - a2) / 24;
}
