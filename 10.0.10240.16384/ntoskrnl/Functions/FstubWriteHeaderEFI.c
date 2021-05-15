// FstubWriteHeaderEFI 
 
int __fastcall FstubWriteHeaderEFI(_DWORD *a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  int v15; // r4
  int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r3
  unsigned int v19; // r5
  unsigned int v20; // r6
  _DWORD *varg_r0; // [sp+20h] [bp+8h]

  varg_r0 = a1;
  v15 = a1[10];
  *(_DWORD *)v15 = 541673029;
  *(_DWORD *)(v15 + 16) = 0;
  *(_DWORD *)(v15 + 20) = 0;
  *(_DWORD *)(v15 + 4) = 1414676816;
  *(_DWORD *)(v15 + 8) = 0x10000;
  *(_DWORD *)(v15 + 12) = 92;
  if ( a14 )
  {
    v17 = a1[13];
    v18 = a1[12];
    *(_DWORD *)(v15 + 36) = 0;
    *(_QWORD *)(v15 + 24) = __PAIR64__(v17, v18) - 1;
    v16 = 1;
  }
  else
  {
    *(_DWORD *)(v15 + 24) = 1;
    *(_DWORD *)(v15 + 28) = 0;
    v16 = a1[12] - 1;
    *(_DWORD *)(v15 + 36) = (unsigned __int64)(*((_QWORD *)a1 + 6) - 1i64) >> 32;
  }
  *(_DWORD *)(v15 + 32) = v16;
  v19 = *(_DWORD *)(v15 + 24);
  v20 = *(_DWORD *)(v15 + 28);
  *(_DWORD *)(v15 + 40) = a9;
  *(_DWORD *)(v15 + 44) = a10;
  *(_DWORD *)(v15 + 48) = a11;
  *(_DWORD *)(v15 + 52) = a12;
  *(_DWORD *)(v15 + 56) = a3;
  *(_DWORD *)(v15 + 60) = a4;
  *(_DWORD *)(v15 + 64) = a5;
  *(_DWORD *)(v15 + 68) = a6;
  *(_DWORD *)(v15 + 80) = a7;
  *(_DWORD *)(v15 + 84) = 128;
  *(_DWORD *)(v15 + 88) = a13;
  if ( a14 )
    *(_QWORD *)(v15 + 72) = __PAIR64__(v20, v19) - a2;
  else
    *(_QWORD *)(v15 + 72) = __PAIR64__(v20, v19) + 1;
  *(_DWORD *)(v15 + 16) = RtlComputeCrc32(0, v15, 0x5Cu);
  return FstubWriteSector(*a1, a1[1], v19, v20);
}
