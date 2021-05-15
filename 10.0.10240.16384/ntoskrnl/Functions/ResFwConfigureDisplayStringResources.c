// ResFwConfigureDisplayStringResources 
 
_DWORD *__fastcall ResFwConfigureDisplayStringResources(int a1)
{
  _DWORD *v2; // r4
  _DWORD *v4; // [sp+8h] [bp-20h] BYREF
  int v5[2]; // [sp+10h] [bp-18h] BYREF
  char v6[4]; // [sp+18h] [bp-10h] BYREF
  int v7; // [sp+1Ch] [bp-Ch]
  int v8; // [sp+20h] [bp-8h]

  if ( !a1 )
    return 0;
  if ( (*(_DWORD *)(a1 + 24) & 1) == 0 )
    return 0;
  if ( BgpFoGetFontHandle(0, v6) < 0 )
    return 0;
  v5[0] = 0;
  v5[1] = -1;
  v8 = 0;
  v7 = *(_DWORD *)(a1 + 20);
  if ( BgpTxtCreateRegion(a1, a1 + 8, v5, &v4, 0) < 0 )
    return 0;
  v2 = v4;
  dword_619044 = BgpTxtRegionSize(v4);
  return v2;
}
