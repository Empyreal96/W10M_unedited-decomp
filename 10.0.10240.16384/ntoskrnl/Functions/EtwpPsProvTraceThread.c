// EtwpPsProvTraceThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpPsProvTraceThread(int a1, int a2, int a3, int a4)
{
  int *v7; // r5
  int v8; // r0
  int v9; // r3
  int v10; // r2
  char v11; // r3
  unsigned __int64 *v12; // r6
  __int64 v13; // r0 OVERLAPPED
  __int64 v14; // r2 OVERLAPPED
  unsigned __int64 v15; // kr00_8
  int result; // r0
  int v17; // r6
  int v18; // r4
  int v19; // r8
  int v20; // r10
  int v21; // [sp+8h] [bp-F8h] BYREF
  int *v22; // [sp+Ch] [bp-F4h]
  int v23; // [sp+10h] [bp-F0h] BYREF
  int v24; // [sp+14h] [bp-ECh] BYREF
  int v25; // [sp+18h] [bp-E8h] BYREF
  int v26; // [sp+1Ch] [bp-E4h] BYREF
  int v27; // [sp+20h] [bp-E0h] BYREF
  int v28; // [sp+24h] [bp-DCh] BYREF
  _DWORD _28[58]; // [sp+28h] [bp-D8h] BYREF
  int varg_r2; // [sp+110h] [bp+10h]
  int varg_r3; // [sp+114h] [bp+14h]

  _28[56] = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  LOBYTE(varg_r2) = a3;
  _28[57] = a2;
  v21 = a1;
  v25 = 0;
  v24 = 0;
  v23 = 0;
  if ( a3 )
  {
    v7 = ThreadStart;
    v22 = ThreadStart;
    v8 = PsGetCurrentThreadTeb();
    if ( v8 )
      v23 = *(_DWORD *)(v8 + 3936);
  }
  else
  {
    v7 = ThreadStop;
    v22 = ThreadStop;
    v9 = *(_DWORD *)(a1 + 156);
    if ( v9 )
      v23 = *(_DWORD *)(v9 + 3936);
  }
  v28 = *(_DWORD *)(a1 + 876);
  _28[2] = &v28;
  _28[3] = 0;
  _28[4] = 4;
  _28[5] = 0;
  v26 = *(_DWORD *)(a1 + 880);
  _28[6] = &v26;
  _28[7] = 0;
  _28[8] = 4;
  _28[9] = 0;
  _28[10] = a1 + 40;
  _28[11] = 0;
  _28[12] = 4;
  _28[13] = 0;
  _28[14] = a1 + 36;
  _28[15] = 0;
  _28[16] = 4;
  _28[17] = 0;
  if ( a3 )
  {
    if ( a2 )
    {
      v25 = *(_DWORD *)(a2 + 8);
      v24 = *(_DWORD *)(a2 + 12);
    }
  }
  else
  {
    v10 = *(_DWORD *)(a1 + 156);
    if ( v10 )
    {
      v25 = *(_DWORD *)(v10 + 4);
      v24 = *(_DWORD *)(v10 + 8);
    }
  }
  _28[18] = &v25;
  _28[19] = 0;
  _28[20] = 4;
  _28[21] = 0;
  _28[22] = &v24;
  _28[23] = 0;
  _28[24] = 4;
  _28[25] = 0;
  if ( (*(_DWORD *)(a1 + 76) & 0x400) == 0 )
  {
    v11 = *(_BYTE *)(a1 + 968);
    __dmb(0xBu);
    if ( (v11 & 8) == 0 )
    {
      __dmb(0xFu);
      __dmb(0xBu);
    }
  }
  _28[26] = &v27;
  _28[27] = 0;
  _28[28] = 4;
  _28[29] = 0;
  v27 = *(_DWORD *)(a1 + 924);
  _28[30] = &v27;
  _28[31] = 0;
  _28[32] = 4;
  _28[33] = 0;
  _28[34] = a1 + 156;
  _28[35] = 0;
  _28[36] = 4;
  _28[37] = 0;
  _28[38] = &v23;
  _28[39] = 0;
  _28[40] = 4;
  _28[41] = 0;
  if ( !a3 )
  {
    v12 = (unsigned __int64 *)(a1 + 48);
    while ( 1 )
    {
      *(__int64 *)((char *)&v13 + 4) = *v12;
      do
      {
        v15 = __ldrexd(v12);
        LODWORD(v13) = HIDWORD(v15);
        HIDWORD(v14) = v15;
      }
      while ( v14 == v13 && __strexd(__PAIR64__(v14, HIDWORD(v13)), v12) );
      if ( v13 == v14 )
        break;
      __dmb(0xAu);
      __yield();
    }
    _28[0] = HIDWORD(v13);
    _28[1] = v14;
    _28[42] = _28;
    _28[43] = 0;
    _28[44] = 8;
    _28[45] = 0;
  }
  EtwWrite(EtwpPsProvRegHandle, dword_61A934, (int)v7, 0);
  result = PsGetProcessServerSilo(*(_DWORD *)(a1 + 336));
  v17 = result;
  if ( result )
  {
    PsGetMonitorContextServerSilo(EtwSiloMonitor, result, &v21);
    v18 = v21;
    if ( v21 )
    {
      v19 = *(_DWORD *)(v21 + 368);
      v20 = *(_DWORD *)(v21 + 372);
      if ( EtwProviderEnabled(v19, v20, 0, 0, 32i64) )
        EtwWrite(v19, v20, (int)v7, 0);
      PsDereferenceMonitorContextServerSilo(v18);
    }
    result = PspDereferenceSiloObject(v17);
  }
  return result;
}
