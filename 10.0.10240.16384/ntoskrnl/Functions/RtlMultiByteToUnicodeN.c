// RtlMultiByteToUnicodeN 
 
int __fastcall RtlMultiByteToUnicodeN(int a1, unsigned int a2, _DWORD *a3, int a4, unsigned int a5, int a6, int a7, int a8, int a9)
{
  unsigned int v9; // r4
  unsigned int v10; // r2
  int v11; // r5
  _WORD *v12; // r1
  unsigned __int8 *i; // r0

  v9 = a2 >> 1;
  if ( NlsMbCodePageTag )
    return sub_7C49AC(a1, (unsigned __int8)NlsMbCodePageTag, (int)a3, a4, a5, a6, a7, a8, a9);
  if ( v9 >= a5 )
    v9 = a5;
  if ( a3 )
    *a3 = 2 * v9;
  v10 = v9 & 0x1F;
  v11 = NlsAnsiToUnicodeData;
  v12 = (_WORD *)(a1 + 2 * (v9 - v10));
  for ( i = (unsigned __int8 *)(v9 - v10 + a4); ; i -= 32 )
  {
    if ( v10 != 1 )
    {
      if ( v10 <= 0x1F )
        __asm { ADD             PC, R3 }
      v12[31] = *(_WORD *)(v11 + 2 * i[31]);
      v12[30] = *(_WORD *)(v11 + 2 * i[30]);
      v12[29] = *(_WORD *)(v11 + 2 * i[29]);
      v12[28] = *(_WORD *)(v11 + 2 * i[28]);
      v12[27] = *(_WORD *)(v11 + 2 * i[27]);
      v12[26] = *(_WORD *)(v11 + 2 * i[26]);
      v12[25] = *(_WORD *)(v11 + 2 * i[25]);
      v12[24] = *(_WORD *)(v11 + 2 * i[24]);
      v12[23] = *(_WORD *)(v11 + 2 * i[23]);
      v12[22] = *(_WORD *)(v11 + 2 * i[22]);
      v12[21] = *(_WORD *)(v11 + 2 * i[21]);
      v12[20] = *(_WORD *)(v11 + 2 * i[20]);
      v12[19] = *(_WORD *)(v11 + 2 * i[19]);
      v12[18] = *(_WORD *)(v11 + 2 * i[18]);
      v12[17] = *(_WORD *)(v11 + 2 * i[17]);
      v12[16] = *(_WORD *)(v11 + 2 * i[16]);
      v12[15] = *(_WORD *)(v11 + 2 * i[15]);
      v12[14] = *(_WORD *)(v11 + 2 * i[14]);
      v12[13] = *(_WORD *)(v11 + 2 * i[13]);
      v12[12] = *(_WORD *)(v11 + 2 * i[12]);
      v12[11] = *(_WORD *)(v11 + 2 * i[11]);
      v12[10] = *(_WORD *)(v11 + 2 * i[10]);
      v12[9] = *(_WORD *)(v11 + 2 * i[9]);
      v12[8] = *(_WORD *)(v11 + 2 * i[8]);
      v12[7] = *(_WORD *)(v11 + 2 * i[7]);
      v12[6] = *(_WORD *)(v11 + 2 * i[6]);
      v12[5] = *(_WORD *)(v11 + 2 * i[5]);
      v12[4] = *(_WORD *)(v11 + 2 * i[4]);
      v12[3] = *(_WORD *)(v11 + 2 * i[3]);
      v12[2] = *(_WORD *)(v11 + 2 * i[2]);
      v12[1] = *(_WORD *)(v11 + 2 * i[1]);
    }
    *v12 = *(_WORD *)(v11 + 2 * *i);
    if ( v9 < 0x20 )
      break;
    v10 = 32;
    v9 -= 32;
    v12 -= 32;
  }
  return 0;
}
