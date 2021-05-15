// SymCryptSha256Result 
 
int __fastcall SymCryptSha256Result(int a1, _DWORD *a2, int a3, unsigned int a4)
{
  unsigned int v6; // r2
  int result; // r0
  unsigned int v8; // r2
  int v9; // r2
  int v10; // r1
  unsigned int v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a4;
  v6 = *(_DWORD *)a1 + 1;
  *(_BYTE *)(*(_DWORD *)a1 + a1 + 24) = 0x80;
  if ( v6 > 0x38 )
    return sub_524A80();
  SymCryptWipeAsm((_BYTE *)(v6 + a1 + 24), 64 - v6);
  v8 = bswap32(8 * *(_DWORD *)(a1 + 8));
  *(_DWORD *)(a1 + 80) = bswap32(*(__int64 *)(a1 + 8) >> 29);
  *(_DWORD *)(a1 + 84) = v8;
  SymCryptSha256AppendBlocks_ul1((int *)(a1 + 88), (unsigned int *)(a1 + 24), 0x40u, v11);
  v9 = 8;
  v10 = a1 + 88 - (_DWORD)a2;
  do
  {
    --v9;
    *a2 = bswap32(*(_DWORD *)((char *)a2 + v10));
    ++a2;
  }
  while ( v9 );
  SymCryptWipeAsm((_BYTE *)a1, 120);
  *(_DWORD *)(a1 + 88) = 1779033703;
  *(_DWORD *)(a1 + 92) = -1150833019;
  *(_DWORD *)(a1 + 96) = 1013904242;
  *(_DWORD *)(a1 + 100) = -1521486534;
  result = 1359893119;
  *(_DWORD *)(a1 + 104) = 1359893119;
  *(_DWORD *)(a1 + 108) = -1694144372;
  *(_DWORD *)(a1 + 112) = 528734635;
  *(_DWORD *)(a1 + 116) = 1541459225;
  return result;
}
