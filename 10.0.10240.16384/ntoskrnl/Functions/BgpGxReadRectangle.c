// BgpGxReadRectangle 
 
int __fastcall BgpGxReadRectangle(int *a1, int a2, _DWORD *a3, int a4)
{
  int v7; // r0
  int v8; // r5
  int v9; // r4
  int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[1] = a4;
  *a1 = 0;
  v11[0] = 0;
  v7 = BgpGetBitsPerPixel();
  v8 = BgpGxRectangleCreate(a3, v7, v11);
  if ( v8 >= 0 )
  {
    v9 = v11[0];
    v8 = GxpReadFrameBufferPixels(v11[0], a2);
    if ( v8 < 0 )
    {
      if ( v9 )
        BgpGxRectangleDestroy(v9);
    }
    else
    {
      *a1 = v9;
    }
  }
  return v8;
}
