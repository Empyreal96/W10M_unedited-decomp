// LdrpThumbProcessRelocation 
 
int __fastcall LdrpThumbProcessRelocation(unsigned __int16 *a1, int a2, int a3)
{
  unsigned int v3; // r5
  _WORD *v4; // r9
  unsigned int v6; // r6
  unsigned int v7; // r0

  v3 = *a1;
  v4 = (_WORD *)((v3 & 0xFFE) + a2);
  if ( v3 >> 12 != 7 )
    return sub_54E014();
  v6 = (unsigned __int16)v4[1];
  v7 = ((unsigned __int8)v6 | (unsigned __int16)(2 * (*v4 & 0x400 | (*v4 << 11))) | ((v4[3] & 0x7000 | (16 * ((unsigned __int8)v4[3] | (2 * (v4[2] & 0x400 | ((unsigned __int16)v4[2] << 11)))))) << 12) | (v6 >> 4) & 0x700)
     + a3;
  *v4 = *v4 & 0xFBF0 | ((v7 & 0x800 | ((unsigned __int16)v7 >> 11)) >> 1);
  v4[1] = (unsigned __int8)v7 | v6 & 0x8F00 | (16 * (v7 & 0x700));
  v4[2] = v4[2] & 0xFBF0 | ((HIWORD(v7) & 0x800 | (v7 >> 27)) >> 1);
  v4[3] = BYTE2(v7) | v4[3] & 0x8F00 | (16 * (HIWORD(v7) & 0x700));
  return 1;
}
