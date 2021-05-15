// AnFwConfigureProgressResources 
 
_DWORD *__fastcall AnFwConfigureProgressResources(int *a1)
{
  int v2; // r0
  unsigned int v3; // r0
  _DWORD *v4; // r5
  _DWORD *v6; // [sp+8h] [bp-28h] BYREF
  int v7[2]; // [sp+10h] [bp-20h] BYREF
  char v8[4]; // [sp+18h] [bp-18h] BYREF
  int v9; // [sp+1Ch] [bp-14h]
  int v10; // [sp+20h] [bp-10h]

  KeInitializeEvent((int)&unk_649DC8, 0, 1);
  if ( !a1 )
    return 0;
  if ( (a1[6] & 1) == 0 )
    return 0;
  if ( BgpFoGetFontHandle(0, v8) < 0 )
    return 0;
  v7[0] = -16777216;
  v7[1] = -1;
  v10 = 1;
  v9 = a1[5];
  if ( BgpTxtCreateRegion(a1, a1 + 2, v7, &v6, 10) < 0 )
    return 0;
  v2 = BgpGetBitsPerPixel();
  v3 = BgpGxRectangleSize(a1[3], a1[2], v2);
  v4 = v6;
  dword_619038 = 122 * (((v3 + 15) & 0xFFFFFFF0) + 80);
  *(_DWORD *)algn_61903C = ((v3 + 15) & 0xFFFFFFF0) + 80;
  dword_619040 = BgpTxtRegionSize(v6);
  return v4;
}
