// RaspGetUnscaledGlyphData 
 
int __fastcall RaspGetUnscaledGlyphData(int a1, int a2, int *a3, int a4, int a5)
{
  int v6; // r0
  int v9; // r6
  int v11; // r5
  int v12; // r4
  unsigned __int16 v13; // [sp+8h] [bp-28h] BYREF
  int v14; // [sp+Ch] [bp-24h] BYREF
  int v15[8]; // [sp+10h] [bp-20h] BYREF

  v6 = *(_DWORD *)(a1 + 12);
  v14 = 0;
  if ( RaspMapCharacterCodeToGlyphIndex(v6, a2, &v13) < 0 )
    v9 = 0;
  else
    v9 = v13;
  if ( RaspMapGlyphIndexToLocation(a1, v9, v15) < 0 )
    return sub_54D9A4();
  v13 = v9;
  v11 = RaspLoadGlyphData(a1, v15[0], &v13, &v14, a5);
  v12 = v14;
  if ( v11 >= 0 )
  {
    v11 = RaspConvertDeltas(v14);
    if ( v11 >= 0 )
      v11 = RaspLoadBearings(a1, v13, v12, a4);
  }
  if ( a3 )
  {
    *a3 = v12;
    v12 = 0;
  }
  if ( v12 )
    RaspFreeMemory(v12, a5);
  return v11;
}
