// RaspLoadGlyphData 
 
int __fastcall RaspLoadGlyphData(int a1, int a2, int a3, int *a4, int a5)
{
  int v8; // r3
  int v9; // r1
  int v10; // r3
  int result; // r0
  _DWORD v12[6]; // [sp+8h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  if ( !a1 )
    return -1073741823;
  v8 = *(_DWORD *)(a1 + 40);
  if ( !v8 )
    return -1073741823;
  if ( a2 == -1 )
    return RaspLoadEmptyGlyph(a4);
  v9 = v8 + a2;
  v10 = *(_DWORD *)(a1 + 8);
  LOWORD(v12[0]) = 0;
  FioFwReadUshortAtOffset(*(_DWORD *)(v10 + 8), v9, v12);
  if ( SLOWORD(v12[0]) >= 0 )
    result = RaspInitializeGlyphData(a1, a2, a4, a5);
  else
    result = sub_54DBF0(a1, a2);
  return result;
}
