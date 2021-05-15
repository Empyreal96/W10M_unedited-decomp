// BgpGxCopyBitmapToRectangle 
 
int __fastcall BgpGxCopyBitmapToRectangle(unsigned int *a1, int a2)
{
  unsigned int v3; // r3
  unsigned int v4; // r0
  unsigned int v5; // r6
  int v6; // r8
  unsigned int v8; // r5
  int v9; // r4

  v3 = a1[2];
  v4 = *a1;
  v5 = (v3 >> 3) * a1[1];
  v6 = a1[5] + (v4 - 1) * v5;
  if ( (v5 & 3) != 0 )
    return sub_8DF39C();
  v8 = 0;
  v9 = a2 + 40;
  if ( v4 )
  {
    do
    {
      memmove(v6, v9, v5);
      ++v8;
      v6 -= v5;
      v9 += v5;
    }
    while ( v8 < *a1 );
  }
  return BgpGxMarkClean((int)a1);
}
