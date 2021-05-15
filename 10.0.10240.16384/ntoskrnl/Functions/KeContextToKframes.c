// KeContextToKframes 
 
int __fastcall KeContextToKframes(int a1, _DWORD *a2, _DWORD *a3, int a4, char a5)
{
  int result; // r0
  int v10; // r10
  int v11; // r2
  unsigned int v12; // r3
  int v13; // r2
  char *v14; // r8
  int v15; // r7
  unsigned int v16; // r1
  unsigned int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r3

  result = KeGetCurrentIrql(a1);
  v10 = result;
  if ( !result )
  {
    result = KfRaiseIrql(1);
    v10 = result;
  }
  *(_BYTE *)(a1 + 17) = (*a3 & 0x20000000) != 0;
  if ( (a4 & 0x200001) == 2097153 )
  {
    *(_DWORD *)(a1 + 116) = a3[14];
    *(_DWORD *)(a1 + 120) = a3[15];
    *(_DWORD *)(a1 + 128) = a3[16];
    v11 = a3[17];
    if ( a5 )
      v12 = v11 & 0xFF0FFC30 | 0x10;
    else
      v12 = v11 & 0xFF0FFCF3 | 0x33;
    *(_DWORD *)(a1 + 132) = v12;
  }
  if ( (a4 & 0x200002) == 2097154 )
  {
    *(_DWORD *)(a1 + 96) = a3[1];
    *(_DWORD *)(a1 + 100) = a3[2];
    *(_DWORD *)(a1 + 104) = a3[3];
    *(_DWORD *)(a1 + 108) = a3[4];
    *(_DWORD *)(a1 + 124) = a3[12];
    *(_DWORD *)(a1 + 112) = a3[13];
    a2[5] = a3[5];
    a2[6] = a3[6];
    a2[7] = a3[7];
    a2[8] = a3[8];
    a2[9] = a3[9];
    a2[10] = a3[10];
    a2[11] = a3[11];
  }
  if ( (a4 & 0x200004) == 2097156 )
  {
    result = KiGetVfpStatePointer(a1);
    if ( result )
    {
      *(_DWORD *)(result + 4) = a3[18];
      result = memmove(result + 16, (int)(a3 + 20), 0x100u);
    }
  }
  if ( (a4 & 0x200008) == 2097160 && KiCP14DebugEnabled )
  {
    v13 = a1;
    v14 = (char *)a3 - a1;
    v15 = 8;
    do
    {
      v16 = *(_DWORD *)&v14[v13 + 336];
      if ( a5 && v16 > MmHighestUserAddress )
        v16 = 0;
      *(_DWORD *)(v13 + 24) = v16;
      v17 = *(_DWORD *)&v14[v13 + 368];
      if ( a5 )
        v17 = v17 & 0xFFFF3FFD | 4;
      *(_DWORD *)(v13 + 56) = v17;
      v13 += 4;
      --v15;
    }
    while ( v15 );
    v18 = a3[100];
    if ( a5 && v18 > MmHighestUserAddress )
      v18 = 0;
    *(_DWORD *)(a1 + 88) = v18;
    v19 = a3[101];
    if ( a5 )
      v19 = v19 & 0xFFFF3FFD | 4;
    *(_DWORD *)(a1 + 92) = v19;
    result = KiIsArmedForDebug(a1 + 56, a1 + 92);
    *(_BYTE *)(a1 + 18) = result;
    if ( a5 )
      result = KiSetDebugActive(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, *(_BYTE *)(a1 + 18) != 0);
  }
  if ( !v10 )
    result = KfLowerIrql(0);
  return result;
}
