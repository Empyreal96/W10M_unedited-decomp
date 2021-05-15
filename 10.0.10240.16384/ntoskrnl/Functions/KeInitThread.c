// KeInitThread 
 
int __fastcall KeInitThread(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r6
  int v10; // r5
  _DWORD *v11; // r1
  int v12; // r0
  int v13; // r3
  int v14; // r2
  int v15; // r0
  int v16; // r3
  int v17; // r1
  _DWORD *varg_r0; // [sp+40h] [bp+8h]
  int varg_r1; // [sp+44h] [bp+Ch]
  int varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v9 = a2;
  v10 = (int)a1;
  varg_r0 = a1;
  a1[3] = a1 + 2;
  a1[2] = a1 + 2;
  a1[120] = a1 + 119;
  a1[119] = a1 + 119;
  v11 = a1;
  v12 = 4;
  do
  {
    v11[57] = v10;
    v11 += 6;
    --v12;
  }
  while ( v12 );
  *(_DWORD *)(v10 + 80) = *(_DWORD *)(v10 + 80) & 0xFFFFFFFE | *(_DWORD *)(a8 + 100) & 1 | 0x10020;
  *(_DWORD *)(v10 + 60) = 16 * KiShortExecutionCycles;
  *(_DWORD *)(v10 + 104) = v10 + 100;
  *(_DWORD *)(v10 + 100) = v10 + 100;
  *(_DWORD *)(v10 + 112) = v10 + 108;
  *(_DWORD *)(v10 + 108) = v10 + 108;
  *(_DWORD *)(v10 + 116) = a8;
  *(_DWORD *)(v10 + 336) = a8;
  v13 = *(_DWORD *)(v10 + 76) | 0x4000;
  *(_DWORD *)(v10 + 76) = v13;
  if ( !a6 )
    *(_DWORD *)(v10 + 76) = v13 | 0x400;
  KeInitializeApc(
    v10 + 400,
    v10,
    0,
    (int)PopPoCoalescinCallback,
    (int)PopPoCoalescinCallback,
    (int)KiSchedulerApc,
    0,
    v10);
  KeInitializeEvent(v10 + 452, 0, 1);
  KeInitializeTimerEx((_DWORD *)(v10 + 168), 0);
  *(_DWORD *)(v10 + 200) = __ROR4__(bswap32(KiWaitAlways) ^ (v10 + 168), KiWaitNever) ^ KiWaitNever;
  v14 = v10 + 288;
  *(_WORD *)(v10 + 298) = 258;
  *(_BYTE *)(v10 + 296) = 1;
  *(_BYTE *)(v10 + 297) = 4;
  v15 = *(_DWORD *)(v10 + 176);
  *(_DWORD *)(v10 + 288) = v15;
  *(_DWORD *)(v10 + 292) = v10 + 176;
  if ( *(_DWORD *)(v15 + 4) != v10 + 176 )
    __fastfail(3u);
  *(_DWORD *)(v15 + 4) = v14;
  *(_DWORD *)(v10 + 176) = v14;
  *(_DWORD *)(v10 + 156) = a7;
  __dmb(0xBu);
  *(_BYTE *)v10 = 6;
  if ( !v9 )
  {
    v16 = *(unsigned __int16 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x168);
    v17 = a9 ? (unsigned __int16)(a9 - 1) : *(unsigned __int16 *)(a8 + 2 * v16 + 112);
    v9 = MmCreateKernelStack(8, v17, v10);
    if ( !v9 )
      return -1073741670;
  }
  *(_DWORD *)(v10 + 32) = v9;
  *(_DWORD *)(v10 + 40) = v9;
  *(_DWORD *)(v10 + 36) = v9 - KeKernelStackSize;
  *(_BYTE *)(v10 + 86) = *(_BYTE *)(v10 + 86) & 0x80 | 8;
  if ( KiHeteroSystem )
    *(_BYTE *)(v10 + 85) = KiDefaultHeteroCpuPolicy;
  KeAbInitializeThreadState(v10);
  *(_DWORD *)(v10 + 816) = 1;
  KiInitializeContextThread(v10, a3, a4, a5, a6);
  return 0;
}
