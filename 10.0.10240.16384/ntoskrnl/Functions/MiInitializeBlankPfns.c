// MiInitializeBlankPfns 
 
_BYTE *__fastcall MiInitializeBlankPfns(_DWORD *a1, int a2, int a3, int a4, char a5)
{
  _BYTE *result; // r0
  _DWORD *v9; // r6
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r3
  _DWORD v14[5]; // [sp+4h] [bp-24h] BYREF

  result = memset(v14, 0, sizeof(v14));
  BYTE2(v14[3]) = a5 & 7 | BYTE2(v14[3]) & 0x38 | 0x40;
  v14[4] = v14[4] & 0xFF00000 | (a3 << 28) | 0xFFFFE;
  v9 = &a1[6 * a2];
  while ( a1 != v9 )
  {
    result = 0;
    v10 = v14[0];
    v11 = v14[1];
    v12 = v14[2];
    *a1 = 0;
    a1[1] = v10;
    a1[2] = v11;
    a1[3] = v12;
    v13 = v14[4];
    a1[4] = v14[3];
    a1[5] = v13;
    a1 += 6;
  }
  return result;
}
