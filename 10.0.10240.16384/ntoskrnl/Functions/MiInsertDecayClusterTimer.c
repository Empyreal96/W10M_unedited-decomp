// MiInsertDecayClusterTimer 
 
int __fastcall MiInsertDecayClusterTimer(int result)
{
  int v1; // r4
  int v2; // r5
  int v3; // r1
  int v4; // r7

  v1 = (result - MmPfnDatabase) / 24 - dword_634690;
  v2 = dword_6401E4;
  *(_BYTE *)(result + 18) = *(_BYTE *)(result + 18) & 0x3F | ((_BYTE)dword_6401E4 << 6);
  v3 = dword_6401D4[v2];
  v4 = (unsigned __int16)v3 >> 1;
  *(_DWORD *)(result + 4) = 2 * (v4 | 0xFFFF0000);
  if ( v4 == 0x7FFF )
    v3 = v3 & 0x1FFFF | (v1 << 17);
  else
    *(_DWORD *)(MmPfnDatabase + 24 * (dword_634690 + v4) + 4) = *(_DWORD *)(MmPfnDatabase + 24 * (dword_634690 + v4) + 4) & 0x1FFFF | (v1 << 17);
  dword_6401D4[v2] = ((unsigned __int16)v3 ^ (unsigned __int16)(2 * v1)) & 0xFFFE ^ v3;
  return result;
}
