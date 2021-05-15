// MiInitializeInPageSupport 
 
int __fastcall MiInitializeInPageSupport(unsigned int a1, char a2)
{
  int v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r1
  int result; // r0
  char v8; // r3

  *(_BYTE *)(a1 + 18) = 4;
  *(_BYTE *)(a1 + 16) = 0;
  *(_BYTE *)(a1 + 17) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = a1 + 24;
  *(_DWORD *)(a1 + 28) = a1 + 24;
  *(_BYTE *)(a1 + 32) = 0;
  *(_BYTE *)(a1 + 33) = 0;
  *(_BYTE *)(a1 + 34) = 4;
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 40) = a1 + 40;
  *(_DWORD *)(a1 + 44) = a1 + 40;
  *(_DWORD *)(a1 + 112) = 0;
  if ( (a2 & 1) != 0 )
    *(_BYTE *)(a1 + 113) |= 0x20u;
  *(_DWORD *)(a1 + 100) = 1;
  *(_DWORD *)(a1 + 144) = 0;
  *(_DWORD *)(a1 + 116) = 0;
  *(_DWORD *)(a1 + 120) = 0;
  *(_DWORD *)(a1 + 8) = a1 + 8;
  *(_DWORD *)(a1 + 12) = a1 + 8;
  *(_DWORD *)(a1 + 92) = 0;
  v4 = __mrc(15, 0, 13, 0, 3);
  *(_DWORD *)(a1 + 88) = v4 & 0xFFFFFFC0;
  v5 = *(_DWORD *)((v4 & 0xFFFFFFC0) + 0x3C8);
  if ( (v5 & 0x100) != 0 )
  {
    v6 = (v5 >> 9) & 7;
  }
  else
  {
    v6 = (*(_DWORD *)((v4 & 0xFFFFFFC0) + 0x3C0) >> 12) & 7;
    if ( (*(_DWORD *)(*(_DWORD *)((v4 & 0xFFFFFFC0) + 0x150) + 192) & 0x100000) != 0 && v6 >= 2 )
      v6 = 2;
  }
  if ( v6 > 5 )
    return sub_544E80();
  *(_BYTE *)(a1 + 115) |= 4u;
  if ( v6 )
    result = v6 - 1;
  else
    result = 0;
  v8 = *(_BYTE *)(a1 + 114);
  *(_DWORD *)(a1 + 124) = 0;
  *(_BYTE *)(a1 + 114) = v6 & 7 | v8 & 0x88 | (16 * (result & 7));
  if ( (a2 & 2) != 0 )
  {
    result = KeAbPreAcquire(a1, 0, 2);
    *(_DWORD *)(a1 + 124) = result;
    if ( result )
      *(_BYTE *)(result + 14) |= 1u;
  }
  return result;
}
