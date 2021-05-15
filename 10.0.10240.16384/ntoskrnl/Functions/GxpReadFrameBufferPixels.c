// GxpReadFrameBufferPixels 
 
int __fastcall GxpReadFrameBufferPixels(int *a1)
{
  unsigned int v2; // r4
  _DWORD *v3; // r1
  int v4; // r7
  int v5; // r6
  int v6; // r9
  int v7; // r4
  unsigned int v8; // r8
  unsigned int v9; // r10
  int v10; // r3
  int v11; // r7
  char *v12; // r9
  int v13; // r4
  unsigned int v15; // [sp+0h] [bp-48h]
  int v16[2]; // [sp+8h] [bp-40h] BYREF
  int v17; // [sp+10h] [bp-38h]
  int v18[12]; // [sp+18h] [bp-30h] BYREF

  v2 = BgpGetBitsPerPixel();
  BgpGetResolution(v16);
  if ( !a1 )
    return -1073741811;
  v4 = a1[1];
  if ( !v4 )
    return -1073741811;
  v5 = *a1;
  if ( !*a1 )
    return -1073741811;
  if ( a1[2] != v2 )
    return -1073741811;
  if ( (unsigned int)(*v3 + v4) > v16[0] )
    return -1073741811;
  v6 = v3[1];
  if ( (unsigned int)(v6 + v5) > v16[1] )
    return -1073741811;
  if ( (dword_619018 & 8) != 0 )
    return -1073741637;
  v8 = v2 >> 3;
  v9 = a1[3];
  v15 = v4 * (v2 >> 3);
  if ( v15 * v5 > v9 )
    return -1073741789;
  if ( (dword_619018 & 2) == 0 )
    return -1073741823;
  v7 = 0;
  if ( BgInternal )
  {
    v11 = a1[5];
    v12 = (char *)off_618FD8 + (*v3 + v6 * v17) * v8;
    if ( v5 )
    {
      v13 = v17;
      do
      {
        memmove(v11, (int)v12, v15);
        v12 += v13 * v8;
        v11 += a1[1] * v8;
        --v5;
      }
      while ( v5 );
      v7 = 0;
    }
  }
  else
  {
    v18[1] = a1[1];
    v18[2] = dword_618FD0;
    v10 = a1[5];
    v18[0] = v5;
    v18[3] = v9;
    v18[4] = v10;
    v7 = off_618FD8(v18);
  }
  return v7;
}
