// BgpGxDrawBitmapImage 
 
int __fastcall BgpGxDrawBitmapImage(int a1, int a2, int a3, char *a4)
{
  int v5; // r4
  char *v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[1] = a4;
  v7[0] = 0;
  v5 = BgpGxParseBitmap(a1, v7);
  if ( v5 >= 0 )
  {
    v5 = BgpGxDrawRectangle(v7[0], a2);
    BgpGxRectangleDestroy(v7[0]);
  }
  return v5;
}
