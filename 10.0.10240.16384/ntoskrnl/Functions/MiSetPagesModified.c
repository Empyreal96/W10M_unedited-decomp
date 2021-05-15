// MiSetPagesModified 
 
int __fastcall MiSetPagesModified(_DWORD *a1, int a2)
{
  unsigned int v4; // r6
  int v5; // r10
  unsigned int v6; // r9
  int v7; // r1
  unsigned int v8; // r0
  unsigned int *v9; // r4
  int v10; // r1
  int v11; // r0
  int v12; // r6
  _DWORD *v13; // r2
  unsigned int v14; // lr
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v19; // r1
  unsigned int v20; // r6
  unsigned __int8 *v21; // r0
  unsigned int v22; // r2
  int v23; // r3
  int v24; // r2
  unsigned int *v25; // r2
  unsigned int v26; // r4
  int v27; // r1
  int v28; // r6
  int v29; // r8
  unsigned int v30; // r0
  unsigned __int8 *v31; // r4
  int v32; // r0
  int v33; // r5
  unsigned int v34; // r2
  unsigned int v35; // r1
  int v36; // r0
  __int16 v37; // r3
  _DWORD *v39; // [sp+10h] [bp-A0h]
  _DWORD *v40; // [sp+14h] [bp-9Ch]
  int v41; // [sp+18h] [bp-98h]
  int v42; // [sp+1Ch] [bp-94h]
  _DWORD *v43; // [sp+20h] [bp-90h]
  int v44; // [sp+24h] [bp-8Ch]
  int v45; // [sp+30h] [bp-80h]
  int v46; // [sp+38h] [bp-78h]
  unsigned int v47; // [sp+3Ch] [bp-74h]
  unsigned int v48; // [sp+44h] [bp-6Ch]
  _DWORD v49[2]; // [sp+68h] [bp-48h] BYREF
  unsigned int *v50; // [sp+70h] [bp-40h]

  v45 = *a1;
  v4 = *(_DWORD *)(*a1 + 4);
  v47 = v4;
  if ( !MiChargeCommit((int)MiSystemPartition, v4, 0) )
    return -1073741523;
  v40 = (_DWORD *)a1[21];
  v43 = &v40[v4];
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v48 = v6;
  if ( MiGetEffectivePagePriorityThread((_DWORD *)v6) <= 5 )
    v8 = MiGetEffectivePagePriorityThread((_DWORD *)v6);
  else
    v8 = 5;
  MiPrefetchControlArea(a1, v7, 0, 0, 0, v8, 0, a2);
  v5 = MiMapImageInSystemSpace(a1, 3, v49);
  if ( v5 >= 0 )
  {
    v9 = v50;
    v44 = (int)v50;
    v5 = 0;
    v10 = v49[0];
    v11 = ((v49[0] >> 10) & 0x3FFFFC) - 0x40000000;
    v12 = 0;
    v13 = v40;
    v14 = (unsigned int)v43;
    while ( 1 )
    {
      v39 = (_DWORD *)v11;
      v42 = v10;
      if ( (unsigned int)v13 >= v14 )
        break;
      if ( *v13 )
      {
        while ( 1 )
        {
          v46 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9);
          }
          else
          {
            v15 = (unsigned __int8 *)v9 + 3;
            do
              v16 = __ldrex(v15);
            while ( __strex(v16 | 0x80, v15) );
            __dmb(0xBu);
            if ( v16 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire(v9);
            while ( 1 )
            {
              v17 = *v9;
              if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v17 & 0x40000000) == 0 )
              {
                do
                  v18 = __ldrex(v9);
                while ( v18 == v17 && __strex(v17 | 0x40000000, v9) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
            v6 = v48;
          }
          if ( (*v39 & 2) != 0 )
            break;
          MiUnlockWorkingSetExclusive((int)v9, v46);
        }
        v41 = ++v12;
        v19 = MmPfnDatabase + 24 * (*v39 >> 12);
        if ( (*(_DWORD *)(v19 + 20) & 0x8000000) != 0 )
        {
          v20 = 0;
          v21 = (unsigned __int8 *)(v19 + 15);
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 | 0x80, v21) );
          while ( 1 )
          {
            __dmb(0xBu);
            if ( !(v22 >> 7) )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
              v23 = *(_DWORD *)(v19 + 12);
              __dmb(0xBu);
            }
            while ( (v23 & 0x80000000) != 0 );
            do
              v22 = __ldrex(v21);
            while ( __strex(v22 | 0x80, v21) );
          }
          if ( (*(_DWORD *)(v19 + 8) & 0x400) == 0 && (*(_BYTE *)(v19 + 18) & 8) == 0 )
          {
            v24 = *(_DWORD *)(v19 + 8);
            if ( (v24 & 0x10) != 0 )
            {
              *(_DWORD *)(v19 + 8) = v24 & 0xFFFFFFEF;
              v20 = v24 & 0xFFFFFFF7;
            }
            else
            {
              v20 = 0;
            }
          }
          *(_BYTE *)(v19 + 18) |= 0x10u;
          __dmb(0xBu);
          v25 = (unsigned int *)(v19 + 12);
          do
            v26 = __ldrex(v25);
          while ( __strex(v26 & 0x7FFFFFFF, v25) );
          if ( v20 )
            MiReleasePageFileInfo((int)MiSystemPartition, v20, 1, 0);
          v12 = v41;
          v9 = (unsigned int *)v44;
        }
        MiUnlockWorkingSetExclusive((int)v9, v46);
        v10 = v42;
        v14 = (unsigned int)v43;
        v11 = (int)v39;
        v13 = v40;
      }
      v40 = ++v13;
      v11 += 4;
      v10 += 4096;
    }
    MiUnmapImageInSystemSpace(v49);
    if ( v47 != v12 )
      MiReturnCommit((int)MiSystemPartition, v47 - v12);
    v27 = *(_DWORD *)(v45 + 12);
    if ( v27 )
      MiReturnCommit((int)MiSystemPartition, v27);
    v28 = v12 - *(_DWORD *)(v45 + 12);
    if ( v28 )
    {
      v29 = *a1;
      do
        v30 = __ldrex((unsigned int *)&dword_634DAC);
      while ( __strex(v30 + v28, (unsigned int *)&dword_634DAC) );
      --*(_WORD *)(v6 + 310);
      v31 = (unsigned __int8 *)(v29 + 28);
      v32 = KeAbPreAcquire(v29 + 28, 0, 0);
      v33 = v32;
      do
        v34 = __ldrex(v31);
      while ( __strex(v34 | 1, v31) );
      __dmb(0xBu);
      if ( (v34 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v29 + 28), v32, v29 + 28);
      if ( v33 )
        *(_BYTE *)(v33 + 14) |= 1u;
      *(_DWORD *)(v29 + 12) += v28;
      __dmb(0xBu);
      do
        v35 = __ldrex((unsigned int *)v31);
      while ( __strex(v35 - 1, (unsigned int *)v31) );
      if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v29 + 28));
      v36 = KeAbPostRelease(v29 + 28);
      v37 = *(_WORD *)(v6 + 310) + 1;
      *(_WORD *)(v6 + 310) = v37;
      if ( !v37 && *(_DWORD *)(v6 + 100) != v6 + 100 )
        KiCheckForKernelApcDelivery(v36);
    }
  }
  else
  {
    MiReturnCommit((int)MiSystemPartition, v4);
  }
  return v5;
}
