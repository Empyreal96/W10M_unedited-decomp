// MiMarkPrivateImageCfgBits 
 
int __fastcall MiMarkPrivateImageCfgBits(int a1, int a2)
{
  int v3; // r0
  int v4; // r5
  int v5; // r3
  int v6; // r1
  int v7; // r0
  int v8; // r2

  v3 = **(_DWORD **)(a2 + 44);
  v4 = (*(_DWORD *)(a2 + 16) + 1) << 12;
  v5 = *(_DWORD *)(a2 + 48);
  v6 = *(_DWORD *)(*(_DWORD *)v3 + 40);
  if ( v5 != v6 )
    v4 += (v5 - v6) >> 2 << 12;
  v7 = MiGetControlAreaCfg(v3);
  return MiPopulateCfgBitMap(a1, v7, v8, v4, 0);
}
