// PspSetContext 
 
int __fastcall PspSetContext(int result, int a2, _DWORD *a3, char a4)
{
  int v4; // r8
  int v5; // r10
  int v8; // r7
  int v9; // r4
  _DWORD *v10; // r2
  _DWORD *v11; // r2
  _DWORD *v12; // r2
  _DWORD *v13; // r2
  _DWORD *v14; // r2
  _DWORD *v15; // r2
  _DWORD *v16; // r2
  _DWORD *v17; // r2
  _DWORD *v18; // r2
  int v19; // r10
  int v20; // r9
  unsigned int v21; // r1
  unsigned int v22; // r3
  int v23; // r3
  unsigned int v24; // r2
  unsigned int v25; // r3

  v4 = a4;
  v5 = *a3;
  v8 = result;
  if ( (*a3 & 0x200001) == 2097153 )
  {
    *(_DWORD *)(result + 116) = a3[14];
    *(_DWORD *)(result + 120) = a3[15];
    *(_DWORD *)(result + 128) = a3[16];
    if ( !a4 )
      return sub_7E6558();
    *(_DWORD *)(result + 132) = a3[17] & 0xFF0FFC30 | 0x10;
  }
  if ( (v5 & 0x200002) == 2097154 )
  {
    *(_DWORD *)(result + 96) = a3[1];
    *(_DWORD *)(result + 100) = a3[2];
    *(_DWORD *)(result + 104) = a3[3];
    *(_DWORD *)(result + 108) = a3[4];
    *(_DWORD *)(result + 112) = a3[13];
    **(_DWORD **)a2 = a3[5];
    **(_DWORD **)(a2 + 4) = a3[6];
    **(_DWORD **)(a2 + 8) = a3[7];
    **(_DWORD **)(a2 + 12) = a3[8];
    **(_DWORD **)(a2 + 16) = a3[9];
    **(_DWORD **)(a2 + 20) = a3[10];
    **(_DWORD **)(a2 + 24) = a3[11];
    **(_DWORD **)(a2 + 28) = a3[12];
  }
  if ( (v5 & 0x200004) == 2097156 )
  {
    result = KiGetVfpStatePointer(result);
    v9 = result;
    if ( result )
    {
      *(_DWORD *)(result + 4) = a3[18] & 0xFFC8FFFF;
      memmove(result + 16, (int)(a3 + 20), 0x40u);
      result = memmove(v9 + 144, (int)(a3 + 52), 0x80u);
      v10 = *(_DWORD **)(a2 + 36);
      *v10 = a3[36];
      v10[1] = a3[37];
      v11 = *(_DWORD **)(a2 + 40);
      *v11 = a3[38];
      v11[1] = a3[39];
      v12 = *(_DWORD **)(a2 + 44);
      *v12 = a3[40];
      v12[1] = a3[41];
      v13 = *(_DWORD **)(a2 + 48);
      *v13 = a3[42];
      v13[1] = a3[43];
      v14 = *(_DWORD **)(a2 + 52);
      *v14 = a3[44];
      v14[1] = a3[45];
      v15 = *(_DWORD **)(a2 + 56);
      *v15 = a3[46];
      v15[1] = a3[47];
      v16 = *(_DWORD **)(a2 + 60);
      *v16 = a3[48];
      v16[1] = a3[49];
      v17 = *(_DWORD **)(a2 + 64);
      *v17 = a3[50];
      v17[1] = a3[51];
    }
  }
  if ( (v5 & 0x200008) == 2097160 )
  {
    *(_BYTE *)(v8 + 18) = 1;
    LOBYTE(result) = 0;
    v18 = a3;
    v19 = v8 - (_DWORD)a3;
    v20 = 8;
    do
    {
      v21 = v18[84];
      if ( v4 && v21 > MmHighestUserAddress )
        v21 = 0;
      *(_DWORD *)((char *)v18 + v19 + 24) = v21;
      v22 = v18[92];
      if ( v4 )
        v22 = v22 & 0xFFFF3FFD | 4;
      *(_DWORD *)((char *)v18 + v19 + 56) = v22;
      v23 = v18[92];
      ++v18;
      result = (unsigned __int8)(v23 | result);
      --v20;
    }
    while ( v20 );
    v24 = a3[100];
    if ( v4 && v24 > MmHighestUserAddress )
      v24 = 0;
    *(_DWORD *)(v8 + 88) = v24;
    v25 = a3[101];
    if ( v4 )
      v25 = v25 & 0xFFFF3FFD | 4;
    *(_DWORD *)(v8 + 92) = v25;
    if ( v4 )
      result = (int)KiSetDebugActive(
                      (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0),
                      (unsigned __int8)(*((_BYTE *)a3 + 404) | result) != 0);
  }
  return result;
}
