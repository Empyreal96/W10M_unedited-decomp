// RaspMapCharacterCodeToGlyphIndex 
 
int __fastcall RaspMapCharacterCodeToGlyphIndex(unsigned int *a1, unsigned int a2, _WORD *a3)
{
  unsigned int v3; // r5
  unsigned int i; // r4

  v3 = *a1;
  for ( i = 0; i < v3; ++i )
  {
    if ( *(unsigned __int16 *)(a1[2] + 2 * i) <= a2 && a2 <= *(unsigned __int16 *)(a1[3] + 2 * i) )
      break;
  }
  if ( i == v3 )
    return -1073741823;
  if ( *(_WORD *)(a1[5] + 2 * i) )
    return sub_54DC00();
  *a3 = *(_WORD *)(a1[4] + 2 * i) + a2;
  return 0;
}
