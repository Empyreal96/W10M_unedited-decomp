// RaspDestroyCachedBitmap 
 
int __fastcall RaspDestroyCachedBitmap(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v7 = a2;
  v8 = a3;
  v9 = a4;
  v5 = *(_DWORD *)(a1 + 8);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  RaspRectangleDestroy(v5, (int)&v7);
  return RaspFreeMemory(a1, (int)&v7);
}
