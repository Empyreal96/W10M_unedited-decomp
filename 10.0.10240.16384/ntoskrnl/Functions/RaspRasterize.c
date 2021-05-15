// RaspRasterize 
 
int __fastcall RaspRasterize(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, _DWORD *a7, int *a8, int a9)
{
  int v10; // r0
  int v11; // r4
  int v12; // r6
  int v13; // r2
  int v14; // r7
  int v16; // r2
  int v17; // [sp+10h] [bp-20h] BYREF
  int v18; // [sp+14h] [bp-1Ch] BYREF
  int v19; // [sp+18h] [bp-18h] BYREF
  char v20[20]; // [sp+1Ch] [bp-14h] BYREF

  v10 = *(_DWORD *)(a1 + 8);
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v11 = RaspGetUnscaledGlyphData(v10, a2, &v18, (int)v20, a9);
  v12 = v18;
  if ( v11 >= 0 )
  {
    v11 = RaspScaleCoordinates(a1, v18);
    if ( v11 >= 0 )
    {
      v11 = RaspCreatePointList(v12, &v19);
      v14 = v19;
      if ( v11 >= 0 )
      {
        v11 = RaspScanConvert(v12, v19, v13, a5, a5, &v17, a8, a9);
        if ( v11 < 0 )
          return sub_54DB50();
        v16 = v17;
        *a6 = v17;
        *a7 = *(_DWORD *)(v16 + 4) >> 2;
      }
      if ( v14 )
        RaspFreeMemory(v14, a9);
    }
  }
  if ( v12 )
    RaspFreeMemory(v12, a9);
  return v11;
}
