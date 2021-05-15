// BgpGxParseBitmap 
 
int __fastcall BgpGxParseBitmap(int a1, int *a2)
{
  int v5; // r5
  int v6; // r1
  int v7; // r4
  int v8; // [sp+0h] [bp-20h] BYREF
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v8 = 0;
  if ( *(_DWORD *)(a1 + 2) < 0x2Cu || *(_WORD *)a1 != 19778 || *(_DWORD *)(a1 + 30) )
    return -1073741811;
  if ( *(_WORD *)(a1 + 28) != 24 )
    return sub_8DF380();
  if ( *(_DWORD *)(a1 + 14) != 40 )
    return -1073741637;
  v9[0] = *(_DWORD *)(a1 + 18);
  v9[1] = *(_DWORD *)(a1 + 22);
  v5 = BgpGxRectangleCreate(v9, 24, &v8);
  if ( v5 < 0 )
  {
    if ( v8 )
      BgpGxRectangleDestroy(v8);
  }
  else
  {
    v6 = a1 + 14;
    v7 = v8;
    BgpGxCopyBitmapToRectangle(v8, v6);
    *a2 = v7;
  }
  return v5;
}
