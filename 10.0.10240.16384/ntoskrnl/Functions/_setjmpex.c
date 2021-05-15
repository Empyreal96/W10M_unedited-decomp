// _setjmpex 
 
int __fastcall setjmpex(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r7
  int v9; // r8
  int v10; // r9
  int v11; // r10
  int v12; // r11
  int v13; // lr
  __int64 v14; // d8
  __int64 v15; // d9
  __int64 v16; // d10
  __int64 v17; // d11
  __int64 v18; // d12
  __int64 v19; // d13
  __int64 v20; // d14
  __int64 v21; // d15

  *(_DWORD *)a1 = a2;
  *(_DWORD *)(a1 + 4) = v5;
  *(_DWORD *)(a1 + 8) = v6;
  *(_DWORD *)(a1 + 12) = v7;
  *(_DWORD *)(a1 + 16) = v8;
  *(_DWORD *)(a1 + 20) = v9;
  *(_DWORD *)(a1 + 24) = v10;
  *(_DWORD *)(a1 + 28) = v11;
  *(_DWORD *)(a1 + 32) = v12;
  *(_DWORD *)(a1 + 36) = &a5;
  *(_DWORD *)(a1 + 40) = v13;
  __asm { VMRS            R2, FPSCR }
  *(_QWORD *)(a1 + 48) = v14;
  *(_QWORD *)(a1 + 56) = v15;
  *(_QWORD *)(a1 + 64) = v16;
  *(_QWORD *)(a1 + 72) = v17;
  *(_QWORD *)(a1 + 80) = v18;
  *(_QWORD *)(a1 + 88) = v19;
  *(_QWORD *)(a1 + 96) = v20;
  *(_QWORD *)(a1 + 104) = v21;
  *(_DWORD *)(a1 + 44) = _R2;
  return 0;
}
