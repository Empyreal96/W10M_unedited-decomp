// KiCheckForEffectivePriorityChange 
 
_DWORD *__fastcall KiCheckForEffectivePriorityChange(_DWORD *result, int a2)
{
  _DWORD *v2; // r5
  int v3; // r4
  int v4; // r2
  int v5; // r2
  int v6; // r1
  char v7; // r3
  char v8; // r2

  v2 = result;
  v3 = result[2];
  if ( !v3 )
    v3 = result[1];
  v4 = *(_DWORD *)(v3 + 68);
  if ( v4 )
  {
    for ( v4 += result[588]; v4; v4 = *(_DWORD *)(v4 + 236) )
    {
      if ( v4 == a2 )
        goto LABEL_7;
    }
  }
  if ( v4 == a2 )
  {
LABEL_7:
    if ( (*(_BYTE *)(v3 + 2) & 4) != 0 )
    {
      if ( *(char *)(v3 + 123) < 16
        && *(_DWORD *)(v3 + 68)
        && (v5 = *(_DWORD *)(v3 + 68)) != 0
        && (v6 = result[588] + v5) != 0
        && (result = (_DWORD *)KiGetThreadEffectiveRankNonZero(v3, v6, 0)) != 0 )
      {
        v7 = 1;
      }
      else
      {
        v7 = *(_BYTE *)(v3 + 123);
      }
      v8 = v7;
    }
    else
    {
      v8 = *(_BYTE *)(v3 + 123);
    }
    *(_BYTE *)v2[7] = v8;
  }
  return result;
}
