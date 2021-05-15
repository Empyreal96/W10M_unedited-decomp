// MI_PAGEFILE_WRITE 
 
int __fastcall MI_PAGEFILE_WRITE(_DWORD *a1, _DWORD *a2, char a3, int a4, int a5)
{
  int v6; // r7
  unsigned int *v7; // r4
  unsigned int v8; // r5
  unsigned int v9; // r5
  int v10; // r4
  char v11; // r2
  _DWORD *v12; // r5
  int v13; // r1
  int v14; // r2
  int v15; // r3
  _DWORD *v16; // r4
  int result; // r0
  int v18; // r1
  int v19; // r2
  int v20; // r3

  v6 = *(_DWORD *)(a1[21] + 128);
  v7 = (unsigned int *)(v6 + 4148);
  do
  {
    v8 = __ldrex(v7);
    v9 = v8 + 1;
  }
  while ( __strex(v9, v7) );
  __dmb(0xBu);
  v10 = v6 + 80 * (v9 & 0x1F) + 4152;
  *(_DWORD *)v10 = a5;
  v11 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x7B);
  *(_BYTE *)(v10 + 7) = a3;
  *(_BYTE *)(v10 + 6) = v11;
  *(_BYTE *)(v6 + 80 * (v9 & 0x1F) + 4160) = a4 != 0;
  v12 = (_DWORD *)(v6 + 80 * (v9 & 0x1F) + 4196);
  *(_DWORD *)(v10 + 16) = *a2;
  *(_DWORD *)(v10 + 20) = a2[1];
  *(_WORD *)(v10 + 4) = *(_WORD *)v6;
  *(_DWORD *)(v10 + 24) = *(_DWORD *)(v6 + 3712);
  *(_DWORD *)(v10 + 28) = *(_DWORD *)(v6 + 3968);
  *(_DWORD *)(v10 + 32) = *(_DWORD *)(v6 + 4120);
  *(_DWORD *)(v10 + 36) = *(_DWORD *)(v6 + 4096);
  *(_DWORD *)(v10 + 40) = *(_DWORD *)(v6 + 1792);
  v13 = a1[33];
  v14 = a1[34];
  v15 = a1[35];
  v16 = a1 + 36;
  *v12 = a1[32];
  v12[1] = v13;
  v12[2] = v14;
  v12[3] = v15;
  v12 += 4;
  result = a1[36];
  v18 = v16[1];
  v19 = v16[2];
  v20 = v16[3];
  *v12 = *v16;
  v12[1] = v18;
  v12[2] = v19;
  v12[3] = v20;
  return result;
}
