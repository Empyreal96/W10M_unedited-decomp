// HvpViewMapIsRangePinned 
 
int __fastcall HvpViewMapIsRangePinned(int a1, int a2)
{
  unsigned int v2; // r5
  unsigned int v3; // r4
  int v4; // r8
  unsigned int v5; // r6
  char v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r2

  v2 = a2 & 0xFFFFF000;
  v3 = (a2 - (a2 & 0xFFFFF000) + 4099) & 0xFFFFF000;
  if ( !v3 )
    return 1;
  v4 = *(_DWORD *)(a1 + 12);
  while ( 1 )
  {
    v5 = 0x40000 - (v2 & 0x3FFFF);
    if ( v5 > v3 )
      v5 = v3;
    v6 = 64 - (v5 >> 12);
    v7 = (0xFFFFFFFF >> v6) | (-1 << ((v5 >> 12) - 32)) | (0xFFFFFFFF >> (32 - (v5 >> 12)));
    v8 = *(_DWORD *)(v4 + 4 * (((v2 & 0xFFFC0000) >> 24) & 0x7F)) + 24 * (((v2 & 0xFFFC0000) >> 18) & 0x3F);
    if ( __PAIR64__(
           *(_DWORD *)(v8 + 12) & (unsigned int)(__PAIR64__(0xFFFFFFFF >> v6, v7) << ((v2 >> 12) & 0x3F) >> 32),
           *(_DWORD *)(v8 + 8) & (v7 << ((v2 >> 12) & 0x3F))) != __PAIR64__(0xFFFFFFFF >> v6, v7) << ((v2 >> 12) & 0x3F) )
      break;
    v3 -= v5;
    v2 += v5;
    if ( !v3 )
      return 1;
  }
  return 0;
}
