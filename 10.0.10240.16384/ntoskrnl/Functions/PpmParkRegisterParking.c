// PpmParkRegisterParking 
 
int PpmParkRegisterParking()
{
  unsigned int v0; // r0
  unsigned int v1; // r2
  unsigned int v2; // r5
  int v3; // r6
  int v4; // r4
  int v5; // r4
  unsigned int i; // r5
  _BYTE *v7; // r0
  unsigned int v8; // r6
  _BYTE *v9; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r0
  int v14; // r2
  unsigned int v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r5
  int v18; // r1
  unsigned __int8 *v19; // r2
  int v20; // r3
  int v21; // r9
  unsigned int v22; // r0
  unsigned int v23; // r2
  _BYTE *v24; // r0
  unsigned int v25; // r7
  unsigned int v26; // r1
  int v27; // r3
  unsigned int v28; // r4
  int v29; // r0
  int v30; // r2
  int v31; // r3
  int v32; // r3
  unsigned int v33; // r2
  int v34; // r3
  int v35; // r3
  unsigned int v36; // r2
  unsigned int v37; // lr
  int v38; // r9
  unsigned int v39; // r5
  int v40; // lr
  int v41; // r2
  int v42; // r5
  int v43; // r8
  int v44; // r4
  unsigned int v45; // r5
  unsigned int v46; // r4
  unsigned int v47; // r0
  int v48; // [sp+0h] [bp-58h] BYREF
  int v49; // [sp+4h] [bp-54h]
  unsigned int v50; // [sp+8h] [bp-50h]
  unsigned int v51; // [sp+Ch] [bp-4Ch]
  _BYTE *v52; // [sp+10h] [bp-48h]
  int v53; // [sp+18h] [bp-40h] BYREF
  __int16 v54; // [sp+1Ch] [bp-3Ch]
  __int16 v55; // [sp+28h] [bp-30h] BYREF
  __int16 v56; // [sp+2Ah] [bp-2Eh]
  int v57; // [sp+2Ch] [bp-2Ch]
  int v58; // [sp+30h] [bp-28h]

  v0 = PpmParkNodes;
  if ( PpmParkNodes )
  {
    v1 = PpmParkNumNodes;
    v2 = 0;
    if ( PpmParkNumNodes )
    {
      v3 = 0;
      do
      {
        v4 = v3 + v0;
        if ( *(_DWORD *)(v3 + v0 + 28) )
        {
          if ( (*(_BYTE *)(v4 + 82) & 8) != 0 )
          {
            v55 = 1;
            v56 = 1;
            v57 = 0;
            v58 = 0;
            v58 = *(_DWORD *)(v4 + 8);
            PopExecuteOnTargetProcessors((int)&v55, (int)PpmIdleRemoveConcurrency, 0, 0);
          }
          ExFreePoolWithTag(*(_DWORD *)(v4 + 28));
          v0 = PpmParkNodes;
          v1 = PpmParkNumNodes;
        }
        ++v2;
        v3 += 88;
      }
      while ( v2 < v1 );
    }
    ExFreePoolWithTag(v0);
    ExFreePoolWithTag(PpmParkHistograms);
    PpmParkNodes = 0;
    PpmParkHistograms = 0;
    PpmParkNumNodes = 0;
  }
  v5 = 0;
  for ( i = 0; i < (unsigned __int16)KeNumberNodes; ++i )
  {
    KeQueryNodeActiveAffinity((unsigned __int16)i, 0, &v48);
    if ( (_WORD)v48 )
      ++v5;
  }
  v7 = (_BYTE *)ExAllocatePoolWithTag(512, 88 * v5, 1884115024);
  v8 = (unsigned int)v7;
  v52 = v7;
  if ( v7 )
  {
    PpmParkNumNodes = v5;
    v9 = memset(v7, 0, 88 * v5);
    if ( !PpmParkUseCoreGranularity )
      return sub_817480(v9);
    v11 = 1;
    PpmParkCoreMask = 1;
    PpmParkUnparkCores = PpmParkUseCoreGranularity == 2;
    PpmParkGranularity = 1;
    v39 = dword_6174B8;
    v40 = 0;
    while ( v39 )
    {
      v33 = __clz(__rbit(v39));
      v39 &= ~(1 << v33);
      v51 = v33;
      if ( v33 >= KeNumberProcessors_0 )
        v34 = 0;
      else
        v34 = (int)*(&KiProcessorBlock + v33);
      v35 = *(_DWORD *)(v34 + 3468);
      if ( v40 )
      {
        if ( v40 != (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v35 >> 16))
                                    + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v35 >> 24))
                                    + *((_BYTE *)RtlpBitsClearTotal
                                      + (unsigned __int8)((unsigned __int16)~(_WORD)v35 >> 8))
                                    + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v35)) )
        {
          v11 = 0;
          PpmParkCoreMask = 0;
        }
      }
      else
      {
        v40 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v35 >> 16))
                              + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v35 >> 24))
                              + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v35 >> 8))
                              + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v35));
      }
    }
    v25 = 0;
    if ( v11 )
      PpmParkGranularity = v40;
    v21 = 0;
    LOWORD(v23) = 0;
    v49 = 0;
    v50 = 0;
    if ( KeNumberNodes )
    {
      v48 = v8;
      do
      {
        KeQueryNodeActiveAffinity((unsigned __int16)v23, &v53, 0);
        if ( v54 )
          v41 = 0;
        else
          v41 = dword_6174B8;
        v42 = v53 & v41;
        v53 &= v41;
        if ( v53 )
        {
          v43 = PpmHeteroPolicy;
          v44 = v48;
          v48 += 88;
          v15 = 0;
          *(_WORD *)(v44 + 4) = v54;
          v16 = 0;
          *(_DWORD *)(v44 + 8) = v42;
          do
          {
            v36 = v16;
            if ( v15 && !v43 )
              v36 = 0;
            v13 = v42;
            v37 = v36 + v44;
            v38 = v44 + 4 * v36;
            while ( v13 )
            {
              v12 = __clz(__rbit(v13));
              v13 &= ~(1 << v12);
              v51 = v12;
              if ( v12 >= KeNumberProcessors_0 )
                v14 = 0;
              else
                v14 = (int)*(&KiProcessorBlock + v12);
              if ( *(unsigned __int8 *)(v14 + 2986) == v16 )
              {
                ++*(_BYTE *)(v37 + 64);
                *(_DWORD *)(v38 + 12) |= *(_DWORD *)(v14 + 1048);
              }
            }
            v15 = (unsigned __int8)(v16 + 1);
            v16 = v15;
          }
          while ( v15 < 2 );
          v8 = (unsigned int)v52;
          if ( !*(_BYTE *)(v44 + 64) )
          {
            *(_BYTE *)(v44 + 64) = *(_BYTE *)(v44 + 65);
            *(_DWORD *)(v44 + 12) = *(_DWORD *)(v44 + 16);
            *(_BYTE *)(v44 + 65) = 0;
            *(_DWORD *)(v44 + 16) = 0;
          }
          if ( !*(_BYTE *)(v44 + 65) )
            *(_BYTE *)(v44 + 82) |= 4u;
          v17 = 0;
          v18 = 2;
          v19 = (unsigned __int8 *)v44;
          do
          {
            v20 = v19[64];
            v19[74] = v20;
            v19[79] = v20;
            ++v19;
            v17 += v20;
            --v18;
          }
          while ( v18 );
          v21 = v49 + 3 * (v17 + 1);
          v55 = 1;
          v56 = 1;
          v57 = 0;
          v58 = 0;
          v58 = *(_DWORD *)(v44 + 8);
          v49 = v21;
          if ( PpmIdleInitializeConcurrency(&v55, v44 + 28, v19) < 0 )
            goto LABEL_59;
          *(_BYTE *)(v44 + 6) = v17;
          *(_BYTE *)(v44 + 71) = v17;
          *(_BYTE *)(v44 + 73) = v17;
          if ( !PpmParkMultiparkGranularity )
            __brkdiv0();
          v22 = v17 / (PpmParkMultiparkGranularity != 0);
          *(_BYTE *)(v44 + 81) = v22;
          if ( (unsigned __int8)v22 < (unsigned int)(unsigned __int8)PpmParkGranularity )
            *(_BYTE *)(v44 + 81) = PpmParkGranularity;
        }
        v23 = v50 + 1;
        v50 = v23;
      }
      while ( v23 < (unsigned __int16)KeNumberNodes );
    }
    v24 = (_BYTE *)ExAllocatePoolWithTag(512, 8 * v21, 1884115024);
    v25 = (unsigned int)v24;
    if ( v24 )
    {
      memset(v24, 0, 8 * v21);
      v26 = PpmParkNumNodes;
      v27 = v25;
      if ( PpmParkNumNodes )
      {
        v28 = v8;
        v29 = PpmParkNumNodes;
        do
        {
          v30 = *(unsigned __int8 *)(v28 + 6);
          *(_DWORD *)(v28 + 32) = v27;
          v31 = v27 + 8 * v30 + 8;
          *(_DWORD *)(v28 + 36) = v31;
          v32 = v31 + 8 * v30 + 8;
          *(_DWORD *)(v28 + 40) = v32;
          v27 = v32 + 8 * v30 + 8;
          v28 += 88;
          --v29;
        }
        while ( v29 );
      }
      PpmParkNodes = v8;
      v8 = 0;
      PpmParkHistograms = v25;
      v25 = 0;
    }
    else
    {
LABEL_59:
      v26 = PpmParkNumNodes;
    }
    if ( v8 )
    {
      v45 = 0;
      if ( v26 )
      {
        v46 = v8;
        do
        {
          v47 = *(_DWORD *)(v46 + 28);
          if ( v47 )
          {
            ExFreePoolWithTag(v47);
            v26 = PpmParkNumNodes;
          }
          ++v45;
          v46 += 88;
        }
        while ( v45 < v26 );
      }
      ExFreePoolWithTag(v8);
      PpmParkNumNodes = 0;
    }
    if ( v25 )
      ExFreePoolWithTag(v25);
  }
  PpmParkApplyPolicy();
  return PpmParkParkingAvailable();
}
