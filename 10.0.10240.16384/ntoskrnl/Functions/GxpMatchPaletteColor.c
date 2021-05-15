// GxpMatchPaletteColor 
 
unsigned int __fastcall GxpMatchPaletteColor(int a1, _BYTE *a2)
{
  unsigned int result; // r0
  int v3; // r5
  unsigned int v4; // r6
  unsigned int v5; // r4
  unsigned int i; // r7
  unsigned __int8 *v7; // r3
  _DWORD vars8[2]; // [sp+18h] [bp+8h] BYREF

  vars8[0] = a1;
  vars8[1] = a2;
  result = 0;
  v3 = (char *)&FourBitPalette - (char *)vars8;
  v4 = -1;
  do
  {
    v5 = 0;
    for ( i = 0; i < 3; ++i )
    {
      v7 = (unsigned __int8 *)vars8 + i;
      v5 += 3 * abs32(*v7 - v7[v3]);
    }
    if ( v5 < v4 )
    {
      v4 = v5;
      *a2 = result;
    }
    ++result;
    v3 += 4;
  }
  while ( result < 0x10 );
  return result;
}
