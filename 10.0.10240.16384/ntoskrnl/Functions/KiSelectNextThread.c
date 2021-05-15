// KiSelectNextThread 
 
int __fastcall KiSelectNextThread(int a1, _DWORD *a2)
{
  int v4; // r0
  int v5; // r4
  char v6; // r2
  int v8; // r2
  int v9; // r1
  char v10; // r3
  int v11; // [sp+0h] [bp-20h]

  v11 = a1;
  while ( 1 )
  {
    v4 = KiSelectReadyThreadEx(a1, 0, 0);
    v5 = v4;
    if ( !v4 )
      break;
    if ( *(_DWORD *)(v4 + 352) == KiCpuSetSequence || (*(_DWORD *)(v4 + 76) & 8) != 0 )
      goto LABEL_6;
    if ( !a2 )
      return sub_50A868();
    *(_BYTE *)(v4 + 132) = 7;
    *(_DWORD *)(v4 + 144) = *a2;
    *a2 = v4 + 144;
  }
  v5 = *(_DWORD *)(a1 + 12);
  KiSetProcessorIdle(a1, 1, 1);
LABEL_6:
  if ( (*(_BYTE *)(v5 + 2) & 4) != 0 )
  {
    if ( *(char *)(v5 + 123) < 16
      && *(_DWORD *)(v5 + 68)
      && (v8 = *(_DWORD *)(v5 + 68)) != 0
      && (v9 = *(_DWORD *)(a1 + 2352) + v8) != 0
      && KiGetThreadEffectiveRankNonZero(v5, v9, 0) )
    {
      v10 = 1;
    }
    else
    {
      v10 = *(_BYTE *)(v5 + 123);
    }
    v6 = v10;
  }
  else
  {
    v6 = *(_BYTE *)(v5 + 123);
  }
  **(_BYTE **)(a1 + 28) = v6;
  *(_DWORD *)(a1 + 8) = v5;
  *(_BYTE *)(v5 + 132) = 3;
  return v11;
}
