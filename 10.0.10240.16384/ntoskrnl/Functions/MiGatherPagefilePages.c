// MiGatherPagefilePages 
 
int __fastcall MiGatherPagefilePages(int a1)
{
  int v1; // r8
  int v3; // lr
  int v4; // r9
  int result; // r0
  int *v6; // r7
  int v7; // r2
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r1
  int v11; // r10
  unsigned int v12; // r4
  int v13; // r0
  unsigned int v14; // r6
  unsigned int v15; // r5
  unsigned int v16; // r9
  unsigned int v17; // r9
  int v18; // r8
  _DWORD *v19; // r1
  unsigned int v20; // r2
  unsigned int v21; // r10
  int v22; // r0
  int v23; // r1
  __int16 v24; // r3
  int v25; // r4
  int *v26; // r1
  unsigned int v27; // r5
  int v28; // r2
  int v29; // t1
  int v30; // r4
  char v31; // r8
  int v32; // r9
  unsigned __int8 *v33; // r3
  unsigned int v34; // r1
  int v35; // r2
  unsigned int v36; // r1
  unsigned int *v37; // r2
  unsigned int v38; // r0
  _DWORD *v39; // r7
  unsigned int *v40; // r0
  unsigned int v41; // r2
  unsigned int *v42; // r1
  unsigned int v43; // r0
  _DWORD *v44; // r0
  __int16 *v45; // r6
  int v46; // r1
  int v47; // r4
  unsigned int v48; // r2
  int v49; // r3
  int v50; // r9
  __int16 v51; // r2
  int v52; // r3
  unsigned int v53; // r6
  int v54; // r2
  unsigned int v55; // r3
  int v56; // r6
  int v57; // r4
  __int16 *v58; // r2
  int *v59; // r1
  int v60; // r3
  int *v61; // r8
  int v62; // t1
  int v63; // r4
  unsigned __int8 *v64; // r3
  unsigned int v65; // r1
  unsigned __int8 *v66; // r1
  int v67; // r3
  unsigned int v68; // r2
  unsigned int *v69; // r2
  unsigned int v70; // r0
  unsigned __int8 *v71; // r1
  int v72; // r3
  unsigned int v73; // r2
  int v74; // r0
  int v75; // r4
  int v76; // r3
  unsigned int v77; // [sp+18h] [bp-50h]
  unsigned int v78; // [sp+1Ch] [bp-4Ch] BYREF
  unsigned int v79; // [sp+20h] [bp-48h] BYREF
  unsigned int v80; // [sp+24h] [bp-44h]
  int v81; // [sp+28h] [bp-40h] BYREF
  int v82; // [sp+2Ch] [bp-3Ch]
  int v83; // [sp+30h] [bp-38h]
  __int16 *v84; // [sp+34h] [bp-34h]
  int v85; // [sp+38h] [bp-30h]
  char v86[40]; // [sp+40h] [bp-28h] BYREF

  v1 = *(_DWORD *)(a1 + 84);
  v3 = 0;
  v4 = *(_DWORD *)(v1 + 128);
  v83 = a1;
  v84 = (__int16 *)v4;
  v77 = 0;
  v82 = v1;
  v80 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !*(_DWORD *)(v1 + 12) )
    return sub_5487A4();
  *(_DWORD *)(a1 + 128) = 0;
  *(_DWORD *)(a1 + 144) = 0;
  *(_DWORD *)(a1 + 148) = 0;
  *(_DWORD *)(a1 + 152) = 0;
  *(_WORD *)(a1 + 134) = 2;
  *(_WORD *)(a1 + 132) = 28;
  v6 = (int *)(a1 + 156);
  v7 = *(_DWORD *)(v4 + 672);
  v8 = *(_WORD *)(v1 + 96) & 0xF;
  v85 = a1 + 156;
  __dmb(0xBu);
  if ( v7 )
  {
    v3 = 16;
    v77 = 16;
  }
  v9 = *(_DWORD *)(v4 + 20 * v8 + 1920);
  v10 = 0;
  if ( (v3 & 0x10) != 0 && (*(_WORD *)(v1 + 96) & 0x10) == 0 )
  {
    v10 = *(_DWORD *)(v4 + 20 * *(_DWORD *)(v4 + 668) + 1920);
    if ( v10 )
    {
      v3 |= 8u;
      v77 = v3;
LABEL_8:
      if ( v9 )
        goto LABEL_11;
      goto LABEL_9;
    }
  }
  if ( !*(_DWORD *)(v4 + 664) )
  {
    v10 = *(_DWORD *)(v4 + 1792);
    goto LABEL_8;
  }
  v9 = 0;
LABEL_9:
  if ( !v10 || (*(_WORD *)(v1 + 96) & 0x10) != 0 )
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)(v1 + 116), (unsigned int)v86);
    *(_BYTE *)(v1 + 98) |= 1u;
    result = KeReleaseInStackQueuedSpinLock((int)v86);
    v50 = v80;
    *(_DWORD *)a1 = -1719109871;
    goto LABEL_68;
  }
LABEL_11:
  if ( (v3 & 8) == 0
    && v10
    && (*(_WORD *)(v1 + 96) & 0x10) == 0
    && (!v9
     || (*(_WORD *)(v4 + 516) & 1) != 0
     || *(_DWORD *)(v1 + 28)
     && *(_DWORD *)(v1 + 76) >= *(_DWORD *)(v1 + 88) >> 2
     && (v10 >= (unsigned int)dword_681270 >> 2 || v10 >= v9)) )
  {
    v3 |= 8u;
    v77 = v3;
  }
  v11 = *(_DWORD *)(v1 + 80);
  if ( *(_DWORD *)(v4 + 588) )
  {
    KeDelayExecutionThread(0, 0, (unsigned int *)Mi30Milliseconds);
    v12 = 1;
    v3 = v77 | 2;
    v78 = 1;
  }
  else
  {
    if ( (v3 & 8) == 0 )
    {
LABEL_73:
      v12 = dword_681270;
      v78 = dword_681270;
      goto LABEL_20;
    }
    v12 = *(_DWORD *)(v1 + 76);
    v78 = v12;
    if ( v10 < v12 )
    {
      v12 = v10;
      v78 = v10;
      v3 |= 2u;
    }
    else
    {
      if ( v12 >= dword_681270 || *(_DWORD *)(v1 + 84) == v11 )
        goto LABEL_20;
      if ( v12 < (unsigned int)dword_681270 >> 3 )
      {
        v12 *= 2;
      }
      else
      {
        v12 += v12 >> 1;
        if ( v12 >= dword_681270 )
          goto LABEL_73;
      }
      v78 = v12;
    }
  }
LABEL_20:
  if ( v12 > 0x100 && (*(_DWORD *)(a1 + 20) & 0x1Cu) < 8 )
  {
    v12 = 256;
    v78 = 256;
    v3 |= 2u;
  }
  v77 = v3 | 4;
  --*(_WORD *)(v80 + 308);
  if ( ((v3 | 4) & 8) == 0 )
  {
    v79 = v12;
    v14 = MiBuildReservationCluster(v6, v1, &v79, &v78);
    v16 = v78;
    v15 = v79;
    v81 = v14;
    goto LABEL_26;
  }
  v81 = *(_DWORD *)(v1 + 68);
  MiFindPageFileWriteCluster(v1, &v81, &v78, 0);
  if ( v78 )
  {
    if ( v78 < v12 )
    {
      v12 = v78;
      v77 = v77 & 0xFFFFFFFC | 1;
    }
    v13 = MiFillNoReservationCluster((_DWORD *)v4, v6, v78);
    v14 = v81;
    v15 = v13;
    v16 = v13;
LABEL_26:
    if ( !v15 )
    {
      v50 = v80;
      --*(_WORD *)(v80 + 310);
      v57 = v83;
      result = (int)v84;
      v58 = v84 + 268;
      v59 = (int *)*((_DWORD *)v84 + 135);
      *(_DWORD *)v83 = v84 + 268;
      *(_DWORD *)(v57 + 4) = v59;
      if ( (__int16 *)*v59 != v58 )
        __fastfail(3u);
      *v59 = v57;
      *((_DWORD *)v58 + 1) = v57;
      v60 = (__int16)(*(_WORD *)(v50 + 310) + 1);
      *(_WORD *)(v50 + 310) = v60;
      if ( !v60 && *(_DWORD *)(v50 + 100) != v50 + 100 )
        result = KiCheckForKernelApcDelivery(result);
      goto LABEL_68;
    }
    v17 = v16 - 1;
    v78 = v15;
    v79 = v15;
    KeAcquireInStackQueuedSpinLock((unsigned int *)(v1 + 116), (unsigned int)v86);
    v18 = (v77 >> 3) & 1;
    if ( v18 )
    {
      MiFindPageFileWriteCluster(v82, &v81, &v78, 1);
      v14 = v81;
      v79 = v78;
    }
    RtlSetBits((_BYTE *)(*(_DWORD *)(v82 + 64) + 4), v14, v79);
    v19 = (_DWORD *)v82;
    v20 = v79;
    *(_DWORD *)(v82 + 12) -= v79;
    if ( v18 )
    {
      v19[17] = v14 + v20;
      if ( (v77 & 1) != 0 )
        v19[21] = v11;
      v21 = v79;
      if ( (v77 & 2) == 0 )
        v19[19] = v12;
    }
    else
    {
      v21 = v79;
      v19[22] = v19[22] - (v19[22] >> 2) + v79;
    }
    MiUpdatePagefilePeakUsage(v19);
    v22 = KeReleaseInStackQueuedSpinLock((int)v86);
    v23 = v80;
    v24 = *(_WORD *)(v80 + 308) + 1;
    *(_WORD *)(v80 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      KiCheckForKernelApcDelivery(v22);
    LOBYTE(v77) = v77 & 0xFB;
    if ( v21 != v15 )
    {
      v61 = &v6[v79];
      do
      {
        v62 = *v61++;
        v63 = MmPfnDatabase + 24 * v62;
        v81 = KfRaiseIrql(2);
        v64 = (unsigned __int8 *)(v63 + 15);
        do
          v65 = __ldrex(v64);
        while ( __strex(v65 | 0x80, v64) );
        __dmb(0xBu);
        if ( v65 >> 7 )
        {
          v66 = (unsigned __int8 *)(v63 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v67 = *(_DWORD *)(v63 + 12);
              __dmb(0xBu);
            }
            while ( (v67 & 0x80000000) != 0 );
            do
              v68 = __ldrex(v66);
            while ( __strex(v68 | 0x80, v66) );
            __dmb(0xBu);
          }
          while ( v68 >> 7 );
        }
        MiWriteCompletePfn(v63, 1);
        __dmb(0xBu);
        v69 = (unsigned int *)(v63 + 12);
        do
          v70 = __ldrex(v69);
        while ( __strex(v70 & 0x7FFFFFFF, v69) );
        KfLowerIrql(v81);
      }
      while ( v61 < &v6[v15] );
      v21 = v79;
      v17 = v17 - v15 + v79;
      MiReleaseWriteInProgressCharges(v84, v15 - v79, 0);
      v6 = (int *)v85;
    }
    v25 = v83;
    v26 = MiState;
    *(_DWORD *)(v83 + 148) = v21 << 12;
    *(_DWORD *)(v25 + 76) = v21 << 12;
    *(_DWORD *)(v25 + 80) = v17;
    v27 = 0;
    v85 = v14;
    do
    {
      v29 = *v6++;
      v28 = v29;
      if ( v29 != v26[1949] )
      {
        v30 = MmPfnDatabase + 24 * v28;
        v31 = 1;
        v32 = KfRaiseIrql(2);
        v33 = (unsigned __int8 *)(v30 + 15);
        do
          v34 = __ldrex(v33);
        while ( __strex(v34 | 0x80, v33) );
        __dmb(0xBu);
        if ( v34 >> 7 )
        {
          v71 = (unsigned __int8 *)(v30 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v72 = *(_DWORD *)(v30 + 12);
              __dmb(0xBu);
            }
            while ( (v72 & 0x80000000) != 0 );
            do
              v73 = __ldrex(v71);
            while ( __strex(v73 | 0x80, v71) );
            __dmb(0xBu);
          }
          while ( v73 >> 7 );
        }
        if ( (*(_DWORD *)(v30 + 8) & 8) != 0 )
          v31 = 3;
        v35 = *(_DWORD *)(v30 + 8) & 0x3E0 | (4 * (*(_WORD *)(v82 + 96) & 1 | (v14 << 11))) | 0x10;
        if ( (v31 & 2) != 0 )
          v35 = *(_DWORD *)(v30 + 8) & 0x3E0 | (4 * (*(_WORD *)(v82 + 96) & 1 | (v14 << 11))) | 0x18;
        v36 = v30 + 8;
        if ( (unsigned int)(v30 + 8) < 0xC0000000 || v36 > 0xC03FFFFF )
        {
          *(_DWORD *)v36 = v35;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v36 = v35;
          if ( (unsigned int)(v30 + 1070596104) <= 0xFFF )
          {
            v74 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v74, (_DWORD *)(v74 + 4 * (v36 & 0xFFF)), v35);
          }
        }
        __dmb(0xBu);
        v37 = (unsigned int *)(v30 + 12);
        do
          v38 = __ldrex(v37);
        while ( __strex(v38 & 0x7FFFFFFF, v37) );
        KfLowerIrql(v32);
        v26 = MiState;
      }
      ++v27;
      ++v14;
    }
    while ( v27 < v21 );
    v39 = (_DWORD *)v83;
    *(_WORD *)(v83 + 132) = 4 * (dword_681270 + 7);
    v40 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2980);
    do
      v41 = __ldrex(v40);
    while ( __strex(v41 + 1, v40) );
    v42 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2976);
    do
      v43 = __ldrex(v42);
    while ( __strex(v43 + v21, v42) );
    v39[5] &= 0xFFFFFFFD;
    v44 = KeQuerySystemTime(v39 + 28);
    v45 = v84;
    v46 = *((_DWORD *)v84 + 125);
    v47 = (v39[5] >> 2) & 7;
    v48 = *((_DWORD *)v84 + 928);
    v49 = 32;
    if ( v46 )
    {
      if ( v48 >= 0x400 )
      {
        v49 = 0;
LABEL_127:
        *((_DWORD *)v84 + 125) = v49;
LABEL_59:
        v50 = v80;
        v39[5] ^= ((unsigned __int8)v39[5] ^ (unsigned __int8)(4 * v47)) & 0x1C;
        if ( v47 < 2 )
        {
          --*(_WORD *)(v50 + 310);
          ++*((_DWORD *)v45 + 100);
          v51 = *(_WORD *)(v50 + 310);
          *(_WORD *)(v50 + 310) = v51 + 1;
          if ( v51 == -1 && *(_DWORD *)(v50 + 100) != v50 + 100 )
            KiCheckForKernelApcDelivery((int)v44);
        }
        MI_PAGEFILE_WRITE(v39, v39 + 28, v47, (v77 & 8) == 0, -1);
        v52 = *((_DWORD *)v45 + 122);
        if ( v52 == 512 )
          *((_DWORD *)v45 + 121) -= *((_DWORD *)v45 + 121) >> 9;
        else
          *((_DWORD *)v45 + 122) = v52 + 1;
        *((_DWORD *)v45 + 121) += v21;
        v53 = v85;
        v39[26] = v85 << 12;
        v54 = v39[5];
        v39[27] = v53 >> 20;
        v39[5] = v54 & 0xFFFFFFDF;
        if ( (v77 & 0x10) == 0 || (result = MiStoreWriteModifiedPages(v39), result < 0) )
        {
          v55 = v53;
          v56 = v82;
          MiMapPageFileHash(v82, v39 + 32, 0, v55, v21);
          result = IoAsynchronousPageWrite(
                     *(_DWORD *)(v56 + 32),
                     v39 + 32,
                     v39 + 26,
                     MiWriteComplete,
                     v39,
                     v47,
                     *(_DWORD *)(v56 + 92),
                     0,
                     v39 + 2,
                     v39 + 4);
          if ( (result & 0xC0000000) == -1073741824 )
          {
            v39[2] = result;
            v39[3] = 0;
            v75 = KfRaiseIrql(1);
            MiWriteComplete(v39, v39 + 2, 0);
            result = KfLowerIrql(v75);
          }
        }
        goto LABEL_68;
      }
      v49 = v46 - 1;
    }
    else if ( v48 >= 0x80 )
    {
      if ( v48 >= 0x100 )
        goto LABEL_59;
      v49 = 8;
    }
    v47 = 4;
    goto LABEL_127;
  }
  result = MiPageFileNoFreeSpace(v1, a1);
  v50 = v80;
LABEL_68:
  if ( (v77 & 4) != 0 )
  {
    v76 = (__int16)(*(_WORD *)(v50 + 308) + 1);
    *(_WORD *)(v50 + 308) = v76;
    if ( !v76 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
