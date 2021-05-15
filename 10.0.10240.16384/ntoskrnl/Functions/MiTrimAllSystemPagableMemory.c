// MiTrimAllSystemPagableMemory 
 
int __fastcall MiTrimAllSystemPagableMemory(int a1, int a2)
{
  int v2; // r4
  unsigned int *v3; // r5
  int v4; // r8
  int *v5; // r6
  unsigned int *v6; // r4
  unsigned int i; // r7
  unsigned int v8; // r0
  unsigned int v9; // r6
  int v10; // r10
  unsigned int v11; // r1
  signed int v12; // r1
  int v13; // r4
  int v14; // r10
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v19; // r4
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r1
  int v24; // r3
  unsigned __int8 *v25; // r3
  unsigned int v26; // r1
  unsigned int v27; // r0
  unsigned int v28; // r1
  int v29; // r0
  unsigned int *v30; // r1
  int *v31; // r0
  unsigned int *v32; // r2
  unsigned int v33; // r0
  __int64 v34; // r0
  int v35; // r0
  unsigned int *v36; // r1
  int *v37; // r0
  unsigned int *v38; // r2
  unsigned int v39; // r0
  int v40; // r0
  unsigned int *v41; // r1
  int *v42; // r0
  unsigned int *v43; // r2
  unsigned int v44; // r4
  unsigned int v45; // r1
  __int16 v46; // r3
  int v50; // [sp+18h] [bp-28h] BYREF
  unsigned int *v51; // [sp+1Ch] [bp-24h]
  int vars4; // [sp+44h] [bp+4h]

  v2 = a1;
  v3 = 0;
  v4 = 0;
  if ( a1 )
  {
    i = 3;
  }
  else
  {
    v5 = MiState;
    v6 = dword_634E00;
    for ( i = 0; i < 3; ++i )
    {
      v3 = v6;
      if ( v5[1990] != v6[25] )
        break;
      v6 += 32;
      ++v5;
    }
    if ( i == 3 )
      return 0;
    v2 = 0;
  }
  v8 = KeGetCurrentIrql(a1);
  if ( v8 > 1 )
    return 0;
  v9 = 0;
  v10 = 0;
  do
  {
    v11 = __ldrex((unsigned int *)algn_634984);
    v12 = v11 + 1;
  }
  while ( __strex(v12, (unsigned int *)algn_634984) );
  __dmb(0xBu);
  if ( v12 <= 1 )
  {
    v8 = KeAreInterruptsEnabled();
    if ( v8 )
    {
      v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v9 + 0x136);
      if ( !v2 )
        goto LABEL_42;
      if ( v2 == 1 )
      {
        v13 = *(_DWORD *)(v9 + 116);
        v3 = (unsigned int *)(v13 + 492);
        v14 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v13 + 492));
        }
        else
        {
          v15 = (unsigned __int8 *)(v13 + 495);
          do
            v16 = __ldrex(v15);
          while ( __strex(v16 | 0x80, v15) );
          __dmb(0xBu);
          if ( v16 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v13 + 492));
          while ( 1 )
          {
            v17 = *v3;
            if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v17 & 0x40000000) == 0 )
            {
              do
                v18 = __ldrex(v3);
              while ( v18 == v17 && __strex(v17 | 0x40000000, v3) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        if ( (*(_DWORD *)(v13 + 192) & 0x20) != 0 )
          goto LABEL_98;
        while ( 1 )
        {
          KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_634980, &v50);
          if ( v3[3] )
          {
            v34 = *(_QWORD *)(v3 + 3);
            if ( *(unsigned int **)(v34 + 4) != v3 + 3 || *(unsigned int **)HIDWORD(v34) != v3 + 3 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v34) = v34;
            *(_DWORD *)(v34 + 4) = HIDWORD(v34);
            v3[3] = 0;
            *((_BYTE *)v3 + 113) = *((_BYTE *)v3 + 113) & 0xF9 | 2;
            if ( !a1 )
              MiState[i + 1990] = v3[25];
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseQueuedSpinLockInstrumented(&v50, vars4);
              goto LABEL_87;
            }
            v35 = v50;
            if ( v50 )
            {
LABEL_85:
              v50 = 0;
              __dmb(0xBu);
              v38 = (unsigned int *)(v35 + 4);
              do
                v39 = __ldrex(v38);
              while ( __strex(v39 ^ 1, v38) );
            }
            else
            {
              v36 = v51;
              __dmb(0xBu);
              do
                v37 = (int *)__ldrex(v36);
              while ( v37 == &v50 && __strex(0, v36) );
              if ( v37 != &v50 )
              {
                v35 = KxWaitForLockChainValid(&v50);
                goto LABEL_85;
              }
            }
LABEL_87:
            MiEmptyWorkingSet(v3, v14, 0);
            KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_634980, &v50);
            *((_BYTE *)v3 + 113) &= 0xF9u;
            MiReturnWsToExpansionList((int *)v3, 0);
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseQueuedSpinLockInstrumented(&v50, vars4);
            }
            else
            {
              v40 = v50;
              if ( !v50 )
              {
                v41 = v51;
                __dmb(0xBu);
                do
                  v42 = (int *)__ldrex(v41);
                while ( v42 == &v50 && __strex(0, v41) );
                if ( v42 == &v50 )
                  goto LABEL_97;
                v40 = KxWaitForLockChainValid(&v50);
              }
              v50 = 0;
              __dmb(0xBu);
              v43 = (unsigned int *)(v40 + 4);
              do
                v44 = __ldrex(v43);
              while ( __strex(v44 ^ 1, v43) );
            }
LABEL_97:
            v4 = 1;
            goto LABEL_98;
          }
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(&v50, vars4);
            goto LABEL_98;
          }
          v29 = v50;
          if ( v50 )
            goto LABEL_70;
          v30 = v51;
          __dmb(0xBu);
          do
            v31 = (int *)__ldrex(v30);
          while ( v31 == &v50 && __strex(0, v30) );
          if ( v31 != &v50 )
            break;
LABEL_98:
          v8 = MiUnlockWorkingSetExclusive((int)v3, v14);
          if ( ++i >= 3 )
          {
            if ( a2 == 1 && v4 == 1 )
              v8 = MiPurgePartitionStandby(MiSystemPartition, 8);
            goto LABEL_103;
          }
          v3 = &dword_634E00[32 * i];
          v4 = 0;
LABEL_42:
          v24 = v3[28] & 7;
          if ( v24 == 3 )
          {
            if ( MiState[i + 1990] != v3[25] )
              goto LABEL_48;
            v3 = &dword_634E00[32 * ++i];
          }
          else if ( v24 != 4 )
          {
            goto LABEL_48;
          }
          if ( MiState[i + 1990] == v3[25] )
            goto LABEL_103;
LABEL_48:
          v19 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
LABEL_49:
            ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v3);
          }
          else
          {
            v25 = (unsigned __int8 *)v3 + 3;
            do
              v26 = __ldrex(v25);
            while ( __strex(v26 | 0x80, v25) );
            __dmb(0xBu);
            if ( v26 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire(v3);
            while ( 1 )
            {
              v27 = *v3;
              if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v27 & 0x40000000) == 0 )
              {
                do
                  v28 = __ldrex(v3);
                while ( v28 == v27 && __strex(v27 | 0x40000000, v3) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
LABEL_50:
          v14 = v19;
        }
        v29 = KxWaitForLockChainValid(&v50);
LABEL_70:
        v50 = 0;
        __dmb(0xBu);
        v32 = (unsigned int *)(v29 + 4);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 ^ 1, v32) );
        goto LABEL_98;
      }
      if ( (*(_DWORD *)(*(_DWORD *)(v9 + 116) + 192) & 0x10000) != 0 )
      {
        v3 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 3248);
        v19 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) == 0 )
        {
          v20 = (unsigned __int8 *)v3 + 3;
          do
            v21 = __ldrex(v20);
          while ( __strex(v21 | 0x80, v20) );
          __dmb(0xBu);
          if ( v21 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v3);
          while ( 1 )
          {
            v22 = *v3;
            if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v22 & 0x40000000) == 0 )
            {
              do
                v23 = __ldrex(v3);
              while ( v23 == v22 && __strex(v22 | 0x40000000, v3) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
          goto LABEL_50;
        }
        goto LABEL_49;
      }
LABEL_103:
      v10 = 1;
    }
  }
  __dmb(0xBu);
  do
    v45 = __ldrex((unsigned int *)algn_634984);
  while ( __strex(v45 - 1, (unsigned int *)algn_634984) );
  if ( v10 == 1 )
  {
    v46 = *(_WORD *)(v9 + 310) + 1;
    *(_WORD *)(v9 + 310) = v46;
    if ( !v46 && *(_DWORD *)(v9 + 100) != v9 + 100 )
      KiCheckForKernelApcDelivery(v8);
  }
  return v4;
}
