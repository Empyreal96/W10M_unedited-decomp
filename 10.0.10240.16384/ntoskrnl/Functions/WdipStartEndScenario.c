// WdipStartEndScenario 
 
int __fastcall WdipStartEndScenario(int a1, int a2, int a3, int a4)
{
  if ( !a1
    || !a2
    || !a3
    || !*(_DWORD *)a2
    && !*(_WORD *)(a2 + 4)
    && !*(_WORD *)(a2 + 6)
    && !*(_BYTE *)(a2 + 8)
    && !*(_BYTE *)(a2 + 9)
    && !*(_BYTE *)(a2 + 10)
    && !*(_BYTE *)(a2 + 11)
    && !*(_BYTE *)(a2 + 12)
    && !*(_BYTE *)(a2 + 13)
    && !*(_BYTE *)(a2 + 14)
    && !*(_BYTE *)(a2 + 15) )
  {
    return -1073741811;
  }
  if ( a4 == 10 )
  {
    if ( WdipSemEnabled )
      return WdipSemEnableScenario();
    return -1073741823;
  }
  if ( !WdipSemEnabled )
    return -1073741823;
  return WdipSemDisableScenario();
}
