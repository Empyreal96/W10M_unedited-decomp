// EtwpLogTxREvent 
 
int __fastcall EtwpLogTxREvent(int a1, int a2, int *a3, int a4, int a5, int *a6, int a7)
{
  int v8; // r5
  int v9; // r6
  int v10; // r7
  int v11; // r1
  int v12; // r3
  int *v13; // r2
  int v15[10]; // [sp+8h] [bp-78h] BYREF
  int v16[20]; // [sp+30h] [bp-50h] BYREF

  v15[0] = *a6;
  v15[1] = a6[1];
  v8 = a3[1];
  v9 = a3[2];
  v10 = a3[3];
  v15[2] = *a3;
  v15[3] = v8;
  v15[4] = v9;
  v15[5] = v10;
  v15[6] = a4;
  v11 = 1;
  v15[7] = a5;
  v16[0] = (int)v15;
  v16[1] = 0;
  v16[2] = 32;
  v16[3] = 0;
  if ( (*(_WORD *)a7 & 0xFFFE) != 0 )
  {
    v12 = *(_DWORD *)(a7 + 4);
    v16[6] = *(_WORD *)a7 & 0xFFFE;
    v16[4] = v12;
    v16[5] = 0;
    v16[7] = 0;
    v11 = 2;
  }
  v13 = &v16[4 * v11];
  *v13 = (int)&EtwpNull;
  v13[1] = 0;
  v13[2] = 2;
  v13[3] = 0;
  return EtwpLogKernelEvent(v16, a1, v11 + 1, a2 | 0x900, 5249282);
}
