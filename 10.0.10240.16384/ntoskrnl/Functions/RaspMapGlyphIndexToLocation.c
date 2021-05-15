// RaspMapGlyphIndexToLocation 
 
int __fastcall RaspMapGlyphIndexToLocation(int a1, int a2, _DWORD *a3, int a4)
{
  int result; // r0
  int v7; // r6
  _DWORD v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a4;
  if ( !a1 )
    return -1073741823;
  if ( *(_WORD *)(a1 + 56) )
    return sub_54DA9C();
  v7 = *(_DWORD *)(a1 + 52) + 2 * a2;
  result = FioFwReadUshortAtOffset(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 8), v7, v8);
  if ( result >= 0 )
  {
    *a3 = 2 * LOWORD(v8[0]);
    result = FioFwReadUshortAtOffset(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 8), v7 + 2, v8);
    if ( result >= 0 )
    {
      if ( *a3 == 2 * LOWORD(v8[0]) )
        *a3 = -1;
      result = 0;
    }
  }
  return result;
}
