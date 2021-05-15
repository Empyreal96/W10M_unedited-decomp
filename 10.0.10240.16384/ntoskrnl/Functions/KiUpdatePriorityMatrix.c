// KiUpdatePriorityMatrix 
 
int __fastcall KiUpdatePriorityMatrix(int result, int a2)
{
  int v3; // r5
  char v4; // r2
  int v5; // r2
  int v6; // r1
  char v7; // r3

  v3 = result;
  if ( (*(_BYTE *)(a2 + 2) & 4) != 0 )
  {
    if ( *(char *)(a2 + 123) < 16
      && *(_DWORD *)(a2 + 68)
      && (v5 = *(_DWORD *)(a2 + 68)) != 0
      && (v6 = *(_DWORD *)(result + 2352) + v5) != 0
      && (result = KiGetThreadEffectiveRankNonZero(a2, v6, 0)) != 0 )
    {
      v7 = 1;
    }
    else
    {
      v7 = *(_BYTE *)(a2 + 123);
    }
    v4 = v7;
  }
  else
  {
    v4 = *(_BYTE *)(a2 + 123);
  }
  **(_BYTE **)(v3 + 28) = v4;
  return result;
}
