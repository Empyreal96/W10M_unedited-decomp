// WmipIsEqualInstanceSets 
 
BOOL __fastcall WmipIsEqualInstanceSets(_DWORD *a1, _DWORD *a2)
{
  int v2; // r2
  unsigned int v4; // r4
  int v5; // r5
  char **v6; // r6
  int v7; // r7
  char *v8; // r1
  char *v9; // t1

  v2 = a1[2];
  if ( ((a2[2] ^ v2) & 0xFFFF9FFF) != 0 )
    return 0;
  if ( (v2 & 1) == 0 )
  {
    if ( (v2 & 2) != 0 )
    {
      v4 = a1[9];
      if ( v4 != a2[9] )
        return 0;
      v5 = 0;
      if ( v4 )
      {
        v6 = (char **)a1[12];
        v7 = a2[12] - (_DWORD)v6;
        while ( 1 )
        {
          v8 = *(char **)((char *)v6 + v7);
          v9 = *v6++;
          if ( wcscmp(v9, v8) )
            break;
          if ( ++v5 >= v4 )
            return 1;
        }
        return 0;
      }
    }
    return 1;
  }
  return a1[9] == a2[9] && !wcscmp((char *)(a1[12] + 4), (char *)(a1[12] + 4));
}
