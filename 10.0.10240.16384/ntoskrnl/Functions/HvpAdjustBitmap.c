// HvpAdjustBitmap 
 
int __fastcall HvpAdjustBitmap(int a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // r5
  unsigned int v4; // r3
  unsigned int v6; // r7
  unsigned int v7; // r1
  _BYTE *v8; // r0
  _BYTE *v9; // r9
  unsigned int v10; // r8
  _BYTE *v11; // r0

  v3 = a2 >> 12;
  v4 = ((a2 >> 12) + 7) >> 3;
  if ( v4 )
    v6 = (v4 + 255) & 0xFFFFFF00;
  else
    v6 = 256;
  v7 = a3[2];
  if ( v6 <= *a3 )
  {
    a3[2] = v3;
    if ( v7 < v3 )
      RtlClearBits((_BYTE *)a3 + 8, v7, v3 - v7);
    return 0;
  }
  v8 = (_BYTE *)(*(int (__fastcall **)(unsigned int, int, int))(a1 + 12))(v6, 1, 959663427);
  v9 = v8;
  if ( v8 )
  {
    *a3 = v6;
    v10 = a3[3];
    v11 = memset(v8, 0, v6);
    a3[2] = v3;
    a3[3] = (unsigned int)v9;
    if ( v10 )
      return sub_805AC0(v11);
    return 0;
  }
  return -1073741670;
}
