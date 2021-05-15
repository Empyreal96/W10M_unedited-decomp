// GxpWriteFrameBufferPixels 
 
int __fastcall GxpWriteFrameBufferPixels(unsigned int *a1, _DWORD *a2)
{
  unsigned int v4; // r0
  int v5; // r5
  int v6; // lr
  __int64 v7; // r8
  unsigned int v8; // r3
  unsigned int v9; // r3
  int v10; // r7
  int v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // r10
  int v15; // r5
  char *v16; // r6
  int v17; // r8
  unsigned int v18; // [sp+4h] [bp-A4h]
  int v19; // [sp+8h] [bp-A0h]
  char *v20; // [sp+Ch] [bp-9Ch]
  unsigned int v21; // [sp+18h] [bp-90h]
  unsigned int v22[28]; // [sp+38h] [bp-70h] BYREF

  v4 = BgpGetBitsPerPixel(a1, a2);
  v18 = v4;
  v5 = dword_618FC4;
  v6 = dword_618FCC;
  if ( !a1 )
    return -1073741811;
  HIDWORD(v7) = a1[1];
  if ( !HIDWORD(v7) )
    return -1073741811;
  LODWORD(v7) = *a1;
  v21 = *a1;
  if ( !*a1 || a1[2] != v4 )
    return -1073741811;
  if ( (dword_619018 & 2) == 0 )
    return -1073741823;
  v8 = dword_618FC8 - *a2;
  if ( HIDWORD(v7) > v8 )
    a1[1] = v8;
  v9 = v5 - a2[1];
  if ( (unsigned int)v7 > v9 )
    *a1 = v9;
  v10 = 0;
  if ( !BgInternal )
    return sub_54D66C();
  v12 = *a2 + v6 * a2[1];
  v13 = a1[1];
  v14 = *a1;
  v15 = a1[5];
  v19 = v12;
  v20 = (char *)off_618FD8;
  v22[0] = (v4 >> 3) * v13;
  v22[1] = v14;
  v16 = (char *)off_618FD8 + v12 * (v4 >> 3);
  v22[2] = v6 * (v4 >> 3);
  if ( v14 )
  {
    v17 = v6 * (v4 >> 3);
    do
    {
      memmove((int)v16, v15, v22[0]);
      v15 += v22[0];
      v16 += v17;
      --v14;
    }
    while ( v14 );
    LODWORD(v7) = v21;
    v4 = v18;
    v12 = v19;
  }
  BgpFwFlushFrameBufferRectangle(&v20[v12 * (v4 >> 3)], v22);
  *(_QWORD *)a1 = v7;
  return v10;
}
