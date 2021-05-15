// BgpGxDrawRectangle 
 
int __fastcall BgpGxDrawRectangle(char *a1, int a2)
{
  char *v2; // r4
  char *v4; // r5
  unsigned int v5; // r0
  int v6; // r5
  char *v8; // [sp+0h] [bp-58h] BYREF
  char v9; // [sp+8h] [bp-50h] BYREF

  v2 = 0;
  v8 = 0;
  v4 = a1;
  v5 = BgpGetBitsPerPixel(a1, a2);
  if ( *((_DWORD *)v4 + 2) == v5 )
    goto LABEL_2;
  if ( (dword_619018 & 0xC00) == 0 )
  {
    v6 = BgpGxConvertRectangle(v4, v5, (int)&v8, 0);
    if ( v6 < 0 )
      return v6;
    v2 = v8;
    v4 = v8;
LABEL_2:
    v6 = GxpWriteFrameBufferPixels(v4, a2);
    if ( v2 )
    {
      if ( v2 != &v9 )
        BgpGxRectangleDestroy(v2);
    }
    return v6;
  }
  return sub_54D660();
}
