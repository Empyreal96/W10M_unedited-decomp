// MiInsertWsle 
 
_DWORD *__fastcall MiInsertWsle(_DWORD *result, _DWORD *a2, int a3)
{
  unsigned int v4; // r4
  int v5; // r5
  _DWORD *v6; // r2
  int v7; // r6

  if ( result[9] == 16 )
  {
    v4 = ((int)a2 - result[63]) >> 4;
    if ( v4 >= result[1] )
    {
      v5 = 2 * ((*a2 >> 9) & 7);
      if ( *a2 < 0xC0000000 || *a2 > 0xC03FFFFF )
        ++v5;
      v6 = &result[2 * v5];
      if ( a3 == 1 )
      {
        v7 = v6[31];
        a2[1] = v7;
        a2[2] = 0xFFFFF;
        if ( v7 == 0xFFFFF )
          v6[32] = v4;
        else
          *(_DWORD *)(result[63] + 16 * v7 + 8) = v4;
        v6[31] = v4;
        ++result[v5 + 15];
      }
      else
      {
        result = (_DWORD *)sub_51A2A8(result);
      }
    }
  }
  return result;
}
