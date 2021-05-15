// KeUpdateThreadSchedulingProperties 
 
int __fastcall KeUpdateThreadSchedulingProperties(int a1, int a2, int a3)
{
  int result; // r0
  char v7; // r1
  int v8; // r2
  int v9; // r1
  char v10; // r3

  result = KiUpdateSharedReadyQueueAffinityThread(0, a1);
  if ( a2 == 2 && !*(_DWORD *)(a3 + 8) || a2 == 3 )
  {
    if ( (*(_BYTE *)(a1 + 2) & 4) != 0 )
    {
      if ( *(char *)(a1 + 123) < 16
        && *(_DWORD *)(a1 + 68)
        && (v8 = *(_DWORD *)(a1 + 68)) != 0
        && (v9 = *(_DWORD *)(a3 + 2352) + v8) != 0
        && (result = KiGetThreadEffectiveRankNonZero(a1, v9, 0)) != 0 )
      {
        v10 = 1;
      }
      else
      {
        v10 = *(_BYTE *)(a1 + 123);
      }
      v7 = v10;
    }
    else
    {
      v7 = *(_BYTE *)(a1 + 123);
    }
    **(_BYTE **)(a3 + 28) = v7;
  }
  return result;
}
