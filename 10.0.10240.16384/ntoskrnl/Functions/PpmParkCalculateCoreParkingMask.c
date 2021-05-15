// PpmParkCalculateCoreParkingMask 
 
int PpmParkCalculateCoreParkingMask()
{
  unsigned int v0; // r9
  int v1; // r2
  unsigned int v2; // r6
  unsigned int v3; // r1
  int v4; // lr
  int v5; // r5
  unsigned int v6; // r1
  unsigned int v7; // r3
  int v9; // r7
  unsigned int v10; // r2
  unsigned int v11; // r1
  int v12; // r1
  unsigned int i; // r7
  int v14; // r6
  int v15; // r8
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r10
  int v19; // lr
  __int64 v20; // kr00_8
  int v21; // r4
  int v22; // r4
  int v23; // r3
  unsigned __int8 *v24; // r9
  unsigned int v25; // r3
  int v26; // r3
  int v27; // r8
  unsigned __int8 v28; // r0
  int v29; // r2
  __int64 v30; // kr08_8
  unsigned int v31; // r1
  int v32; // [sp+18h] [bp-48h] BYREF
  unsigned int v33; // [sp+1Ch] [bp-44h]
  unsigned int v34; // [sp+20h] [bp-40h]
  int v35; // [sp+24h] [bp-3Ch]
  int v36; // [sp+28h] [bp-38h]
  unsigned int v37; // [sp+2Ch] [bp-34h]
  int v38; // [sp+30h] [bp-30h]
  int *v39; // [sp+34h] [bp-2Ch]
  unsigned int v40; // [sp+38h] [bp-28h]
  unsigned int v41; // [sp+3Ch] [bp-24h]

  if ( !PpmIsParkingEnabled )
    return 1;
  v0 = 0;
  v37 = 0;
  v1 = BYTE1(PpmCurrentProfile[44 * dword_61EC0C + 26]);
  v39 = &PpmCurrentProfile[44 * dword_61EC0C + 8];
  v2 = 100 * v1;
  v3 = PpmParkNumNodes;
  v41 = 100 * v1;
  if ( !PpmParkNumNodes )
    goto LABEL_17;
  v4 = 0;
  v38 = 0;
  do
  {
    v5 = PpmParkNodes + v4;
    if ( (*(_BYTE *)(PpmParkNodes + v4 + 82) & 1) != 0 )
      goto LABEL_16;
    v6 = *(unsigned __int8 *)(v5 + 71);
    *(_DWORD *)(v5 + 24) = *(_DWORD *)(v5 + 20);
    v7 = *(unsigned __int8 *)(v5 + 73);
    v33 = v6;
    if ( v6 < v7 )
      return sub_540AD4();
    v35 = 2;
    v33 = v7;
    v9 = 0;
    v10 = *(_DWORD *)(v5 + 8);
    v36 = 0;
    while ( v10 )
    {
      v11 = __clz(__rbit(v10));
      v10 &= ~(1 << v11);
      v40 = v11;
      if ( v11 >= KeNumberProcessors_0 )
        v12 = 0;
      else
        v12 = (int)*(&KiProcessorBlock + v11);
      if ( *(_DWORD *)(v12 + 3244) >= v2 )
        v9 |= *(_DWORD *)(v12 + 1048);
    }
    v36 = v9;
    for ( i = 0; i < 2; ++i )
    {
      v14 = *(_DWORD *)(v5 + 4 * i + 12);
      v15 = 0;
      v32 = 0;
      if ( !v14 )
        break;
      v16 = *(unsigned __int8 *)(i + v5 + 74);
      v40 = *(unsigned __int8 *)(i + v5 + 64);
      v17 = v40;
      if ( v40 > v16 )
        v17 = v16;
      v34 = (unsigned __int8)PpmParkGranularity;
      if ( !PpmParkGranularity )
        __brkdiv0();
      v18 = (unsigned __int8)PpmParkGranularity
          + v17
          - 1
          - ((unsigned __int8)PpmParkGranularity + v17 - 1) % (unsigned __int8)PpmParkGranularity;
      if ( PpmParkUnparkCores )
        v18 *= v34;
      if ( PpmCheckLatencyBoostActive )
      {
        v30 = 1374389535i64 * (int)(*((unsigned __int8 *)v39 + i + 67) * v40 + 50);
        if ( !v34 )
          __brkdiv0();
        v31 = (v40 - (SHIDWORD(v30) >> 5)) % v34;
        if ( v18 < v31 + (SHIDWORD(v30) >> 5) )
        {
          v15 = 64;
          v32 = 64;
          v18 = v31 + (SHIDWORD(v30) >> 5);
        }
      }
      if ( !i && *(_BYTE *)(v5 + 75) )
      {
        v15 |= 0x80u;
        v18 = *(unsigned __int8 *)(v5 + 64);
        v32 = v15;
      }
      *(_BYTE *)(i + v5 + 74) = v18;
      v19 = *(unsigned __int16 *)(v5 + 4);
      do
      {
        while ( 1 )
        {
          v20 = KiCpuSetSequence;
          __dmb(0xBu);
          if ( (v20 & 1) == 0 )
            break;
          __dmb(0xAu);
          __yield();
        }
        v21 = KiSystemAllowedCpuSets[v19];
        __dmb(0xBu);
      }
      while ( KiCpuSetSequence != v20 );
      v22 = v14 & ~v21;
      if ( v22 )
      {
        v23 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v22 >> 16))
                              + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v22 >> 24))
                              + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v22 >> 8))
                              + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v22));
      }
      else
      {
        v22 = 0;
        v23 = 0;
      }
      v24 = (unsigned __int8 *)(i + v5);
      if ( v23 )
      {
        v18 += v23;
        if ( v18 >= v24[64] )
          v18 = v24[64];
        v15 |= 0x10u;
        v32 = v15;
      }
      v25 = v24[66];
      if ( v18 < v25 )
      {
        v15 |= 4u;
LABEL_45:
        v18 = v25;
        v32 = v15;
        goto LABEL_39;
      }
      v25 = v24[68];
      if ( v18 > v25 )
      {
        v15 |= 8u;
        goto LABEL_45;
      }
LABEL_39:
      v26 = 0;
      if ( v33 < v18 )
      {
        v18 = v33;
        v32 = v15 | v35;
        v26 = 1;
      }
      v27 = v36;
      v33 -= v18;
      v28 = PpmParkChooseCoresToUnpark(
              v18,
              *(unsigned __int16 *)(v5 + 4),
              v14,
              *(_DWORD *)(v5 + 24),
              v36,
              v22,
              v5 + 20,
              v26,
              &v32);
      v29 = v32;
      v24[79] = v28;
      PpmEventTraceCoreParkingSelection(v5, i, v27, v22, (unsigned __int8)v18, v29);
    }
    v2 = v41;
    v3 = PpmParkNumNodes;
    v0 = v37;
    v4 = v38;
LABEL_16:
    ++v0;
    v4 += 88;
    v37 = v0;
    v38 = v4;
  }
  while ( v0 < v3 );
LABEL_17:
  PpmParkComputeDiff();
  if ( PpmParkLpiEngaged != (PpmParkLpiCap != 0) || PpmParkLpiCapChanged )
  {
    PpmParkLpiCapChanged = 0;
    PpmParkLpiEngaged = PpmParkLpiCap != 0;
    PpmEventLPICoreParking(PpmParkLpiCap);
  }
  else
  {
    PpmParkLpiCapChanged = 0;
    PpmParkLpiEngaged = PpmParkLpiCap != 0;
  }
  return 1;
}
