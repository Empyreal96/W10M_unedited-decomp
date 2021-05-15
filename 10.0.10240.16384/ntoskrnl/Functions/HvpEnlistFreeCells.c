// HvpEnlistFreeCells 
 
int __fastcall HvpEnlistFreeCells(_DWORD *a1, int a2, int a3)
{
  unsigned int v3; // r7
  unsigned int v4; // r5
  unsigned int v5; // r6
  int v8; // r10
  unsigned int v9; // r4
  int v11; // r3

  v3 = *(_DWORD *)(a2 + 8);
  v4 = a2 + 32;
  v5 = v3 + a2;
  v8 = 1;
  if ( a2 + 32 < v3 + a2 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)v4;
      if ( *(int *)v4 >= 0 )
      {
        if ( v9 > v3 || v9 + v4 > v5 || (v9 & 7) != 0 || !v9 )
          return sub_803F80(7, &CmpSelfHeal, &CmpBootType);
        HvpEnlistFreeCell(a1, v4 - a2 + a3, v9, 0, 0);
        a1[20] += v9;
      }
      else
      {
        v9 = -v9;
        if ( v9 > v3 || v9 + v4 > v5 || (v9 & 7) != 0 || !v9 )
        {
          v8 = 0;
          if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
            return v8;
          v11 = v3 - v4 + a2;
          *(_DWORD *)v4 = v11;
          memset((_BYTE *)(v4 + 4), 0, v11 - 4);
          v9 = *(_DWORD *)v4;
          HvpEnlistFreeCell(a1, v4 - a2 + a3, *(_DWORD *)v4, 0, 0);
          *(_DWORD *)(a1[8] + 4088) |= 4u;
          a1[20] += v9;
        }
        a1[21] += v9;
      }
      v3 = *(_DWORD *)(a2 + 8);
      v4 += v9;
      v5 = v3 + a2;
      if ( v4 >= v3 + a2 )
        return v8;
    }
  }
  return 1;
}
