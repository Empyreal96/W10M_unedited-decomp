// PsQueryProcessEnergyValues 
 
_BYTE *__fastcall PsQueryProcessEnergyValues(_DWORD *a1, int a2)
{
  unsigned int v4; // r5
  unsigned int *v5; // r7
  int v6; // r0
  unsigned int v7; // r2
  int v8; // r1
  int v9; // r4
  int v10; // r6
  __int64 v11; // kr00_8
  _QWORD *v12; // r1
  int v13; // r0
  _DWORD *v14; // r6
  _DWORD *v15; // lr
  _QWORD *v16; // r4
  int v17; // r8
  int v18; // r5
  int v19; // r10
  unsigned int v20; // r2
  _BYTE *result; // r0
  __int16 v22; // r3
  unsigned int v23; // [sp+0h] [bp-20h]

  if ( !PoEnergyEstimationEnabled() || a1 == (_DWORD *)PsIdleProcess )
    return memset((_BYTE *)a2, 0, 144);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = v4;
  --*(_WORD *)(v4 + 308);
  v5 = a1 + 180;
  v6 = KeAbPreAcquire((unsigned int)(a1 + 180), 0, 0);
  do
    v7 = __ldrex(v5);
  while ( !v7 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v7 )
    return (_BYTE *)sub_7C2774(v6, 17);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v8 = a1[199];
  v9 = 4;
  v10 = v8 - a2;
  *(_QWORD *)(a2 + 64) = *(_QWORD *)(v8 + 64);
  *(_QWORD *)(a2 + 72) = *(_QWORD *)(v8 + 72);
  *(_QWORD *)(a2 + 80) = *(_QWORD *)(v8 + 80);
  *(_QWORD *)(a2 + 88) = *(_QWORD *)(v8 + 88);
  *(_QWORD *)(a2 + 96) = *(_QWORD *)(v8 + 96);
  *(_DWORD *)(a2 + 104) = *(_DWORD *)(v8 + 104);
  *(_DWORD *)(a2 + 108) = *(_DWORD *)(v8 + 108);
  *(_QWORD *)(a2 + 112) = *(_QWORD *)(v8 + 112);
  *(_QWORD *)(a2 + 120) = *(_QWORD *)(v8 + 120);
  *(_QWORD *)(a2 + 128) = *(_QWORD *)(v8 + 128);
  v11 = *(_QWORD *)(v8 + 136);
  v12 = (_QWORD *)a2;
  *(_QWORD *)(a2 + 136) = v11;
  do
  {
    v13 = 2;
    do
    {
      *v12 = *(_QWORD *)((char *)v12 + v10);
      ++v12;
      --v13;
    }
    while ( v13 );
    --v9;
  }
  while ( v9 );
  v14 = (_DWORD *)a1[99];
  v15 = a1 + 99;
  if ( v14 != a1 + 99 )
  {
    do
    {
      v16 = (_QWORD *)a2;
      v17 = 4;
      v18 = v14[38] - a2;
      do
      {
        v19 = 2;
        do
        {
          *v16 += *(_QWORD *)((char *)v16 + v18);
          ++v16;
          --v19;
        }
        while ( v19 );
        --v17;
      }
      while ( v17 );
      v14 = (_DWORD *)*v14;
    }
    while ( v14 != v15 );
    v4 = v23;
  }
  __dmb(0xBu);
  do
    v20 = __ldrex(v5);
  while ( v20 == 17 && __strex(0, v5) );
  if ( v20 != 17 )
    ExfReleasePushLockShared(v5);
  result = (_BYTE *)KeAbPostRelease((unsigned int)v5);
  v22 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    result = (_BYTE *)KiCheckForKernelApcDelivery((int)result);
  return result;
}
