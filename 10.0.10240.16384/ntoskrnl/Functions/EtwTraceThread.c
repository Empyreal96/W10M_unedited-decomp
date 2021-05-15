// EtwTraceThread 
 
int *__fastcall EtwTraceThread(int a1, int a2, int a3)
{
  int v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r2
  int v9; // r8
  int v10; // r0
  int v11; // r2
  int v12; // r4
  int v13; // r0
  _DWORD *v14; // r2
  _DWORD v16[4]; // [sp+10h] [bp-58h] BYREF
  int v17; // [sp+20h] [bp-48h]
  int v18; // [sp+24h] [bp-44h]
  int v19; // [sp+28h] [bp-40h]
  int v20; // [sp+2Ch] [bp-3Ch]
  int v21; // [sp+30h] [bp-38h]
  int v22; // [sp+34h] [bp-34h]
  char v23; // [sp+38h] [bp-30h]
  char v24; // [sp+39h] [bp-2Fh]
  char v25; // [sp+3Ah] [bp-2Eh]
  char v26; // [sp+3Bh] [bp-2Dh]
  int v27[10]; // [sp+40h] [bp-28h] BYREF

  if ( (dword_61AD40 & 2) != 0 )
    EtwpPsProvTraceThread();
  v16[0] = *(_DWORD *)(a1 + 876);
  v16[1] = *(_DWORD *)(a1 + 880);
  v16[2] = *(_DWORD *)(a1 + 40);
  v6 = *(_DWORD *)(a1 + 36);
  __dmb(0xBu);
  v16[3] = v6;
  v19 = *(_DWORD *)(a1 + 356);
  v20 = *(_DWORD *)(a1 + 924);
  v17 = 0;
  v18 = 0;
  v21 = *(_DWORD *)(a1 + 156);
  v22 = 0;
  v23 = *(_BYTE *)(a1 + 347);
  v7 = *(_DWORD *)(a1 + 960);
  v8 = (v7 >> 12) & 7;
  v9 = *(_DWORD *)(a1 + 336);
  if ( (*(_DWORD *)(v9 + 192) & 0x100000) != 0 )
  {
    v10 = MmGetMinWsPagePriority();
    if ( v8 >= v10 + 1 )
      LOBYTE(v8) = v10 + 1;
  }
  v24 = v8;
  v11 = (v7 >> 9) & 7;
  if ( (*(_DWORD *)(v9 + 192) & 0x100000) != 0 )
    v11 = 0;
  if ( v11 < 2 && a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(a1 + 1000) )
    LOBYTE(v11) = 2;
  v25 = v11;
  v26 = 0;
  if ( a3 )
  {
    v12 = 1281;
    if ( a2 )
    {
      v17 = *(_DWORD *)(a2 + 8);
      v18 = *(_DWORD *)(a2 + 12);
    }
    v13 = PsGetCurrentThreadTeb();
    if ( v13 )
      v22 = *(_DWORD *)(v13 + 3936);
  }
  else
  {
    v12 = 1282;
    v14 = *(_DWORD **)(a1 + 156);
    if ( v14 )
    {
      v22 = v14[984];
      v17 = v14[1];
      v18 = v14[2];
    }
  }
  v27[0] = (int)v16;
  v27[1] = 0;
  v27[2] = 44;
  v27[3] = 0;
  return EtwTraceKernelEvent(v27, 1, 2u, v12, 5249283);
}
