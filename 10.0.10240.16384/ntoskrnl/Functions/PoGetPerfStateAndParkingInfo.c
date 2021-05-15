// PoGetPerfStateAndParkingInfo 
 
unsigned int __fastcall PoGetPerfStateAndParkingInfo(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  char v7; // r7
  unsigned int result; // r0
  unsigned int v9; // r1
  int v10; // r6
  _DWORD *v11; // r4
  unsigned int v12; // r0
  int v13; // r10
  int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r3
  unsigned int v20; // r2
  unsigned int v21; // r1
  int v23; // [sp+Ch] [bp-84h] BYREF
  __int16 v24[2]; // [sp+10h] [bp-80h] BYREF
  int v25; // [sp+14h] [bp-7Ch]
  int v26; // [sp+18h] [bp-78h]
  __int64 v27[14]; // [sp+20h] [bp-70h] BYREF

  memset((_BYTE *)a2, 0, 32);
  v7 = -1;
  if ( *(_BYTE *)(a1 + 3) )
    return sub_529198(KeNumberProcessors_0);
  if ( *(_WORD *)a1 )
    return sub_529198(KeNumberProcessors_0);
  v9 = *(unsigned __int8 *)(a1 + 2);
  if ( v9 >= KeNumberProcessors_0 )
    return sub_529198(KeNumberProcessors_0);
  v10 = (int)*(&KiProcessorBlock + v9);
  v11 = *(_DWORD **)(v10 + 3200);
  result = PpmPerfGetCurrentState(v10, a2 + 4, &v23, a2 + 8, a2, a2 + 24);
  if ( v11 )
  {
    *(_DWORD *)(a2 + 12) = v11[34];
    *(_DWORD *)(a2 + 16) = v11[33];
    if ( v11[21] != v11[23] )
      *(_BYTE *)(a2 + 28) = 1;
    if ( v11[33] < 0x64u )
      *(_DWORD *)(a2 + 24) |= 1u;
    v12 = v11[20];
    if ( !v12 )
      __brkdiv0();
    result = 100 * v23 / v12;
    *(_DWORD *)(a2 + 20) = result;
  }
  else
  {
    *(_DWORD *)(a2 + 20) = 100;
  }
  *(_BYTE *)(a2 + 29) = *(_BYTE *)(v10 + 3222);
  if ( a4 )
  {
    *a4 = *(_DWORD *)(v10 + 3248);
    a4[1] = *(_DWORD *)(v10 + 3252);
  }
  if ( a3 )
  {
    memset(v27, 0, 80);
    v13 = KfRaiseIrql(2);
    v14 = PpmSnapPerformanceAccumulation(v10, 0, v10 != ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, 0, v27);
    KfLowerIrql(v13);
    if ( v14 )
    {
      if ( *(_DWORD *)(v10 + 3112) == 3 )
        result = PpmHvPerformanceCounterShift;
      else
        result = PpmPerformanceCounterShift;
      v15 = HIDWORD(v27[4]);
      a3[2] = (unsigned __int64)v27[4] >> result;
      v16 = v27[5];
      v17 = v15 >> result;
      v18 = HIDWORD(v27[5]);
      a3[3] = v17;
      a3[4] = __PAIR64__(v18, v16) >> result;
      v19 = v27[0];
      v20 = v18 >> result;
      v21 = HIDWORD(v27[0]);
      a3[5] = v20;
      *a3 = __PAIR64__(v21, v19) >> result;
      a3[1] = (unsigned __int64)v27[1] >> result;
    }
    else
    {
      v24[0] = 1;
      v24[1] = 1;
      v25 = 0;
      if ( !*(_BYTE *)(a1 + 3) && !*(_WORD *)a1 && *(unsigned __int8 *)(a1 + 2) < (unsigned int)KeNumberProcessors_0 )
        v7 = *(_BYTE *)(a1 + 2);
      v26 = 1 << v7;
      result = PopExecuteOnTargetProcessors(v24, PpmGetThroughputInfoCallback, a3, 0);
    }
  }
  return result;
}
