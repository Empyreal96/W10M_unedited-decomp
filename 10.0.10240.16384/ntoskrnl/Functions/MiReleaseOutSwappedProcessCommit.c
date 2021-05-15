// MiReleaseOutSwappedProcessCommit 
 
unsigned int __fastcall MiReleaseOutSwappedProcessCommit(int a1)
{
  int v1; // r6
  int v2; // r10
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r4
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  int v9; // r1
  int v10; // r2
  unsigned int v11; // r9
  int v12; // r3
  int v13; // r6
  _DWORD *i; // r3
  unsigned int v15; // r0
  unsigned int v16; // r9
  unsigned int v17; // r6
  int v18; // r2
  int v19; // r3
  unsigned int v20; // r1
  int v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r4
  int v24; // r3
  int v25; // r3
  unsigned int v26; // r2
  int v27; // r1
  unsigned int v28; // r3
  int v29; // r0
  int v30; // r5
  unsigned int v31; // r2
  int v32; // r8
  int v33; // r10
  int v34; // r5
  int v35; // r3
  int v36; // r7
  int v37; // r2
  unsigned __int8 *v38; // r9
  int v39; // r6
  unsigned int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r4
  __int16 v44; // r3
  int v45; // r3
  int v46; // r3
  int v47; // r3
  int v48; // r3
  _DWORD **v49; // r3
  int v50; // r2
  unsigned int v51; // r2
  int v52; // r0
  int v53; // r3
  _DWORD *v54; // r3
  int v55; // r4
  unsigned __int8 *v56; // r3
  unsigned int v57; // r1
  unsigned int v58; // r0
  char v59; // r3
  int v60; // r3
  unsigned int result; // r0
  unsigned int v62; // r3
  unsigned __int8 *v63; // r4
  char v64; // r5
  unsigned int v65; // r0
  char v66; // r3
  unsigned int v67; // r1
  unsigned __int8 *v68; // r3
  unsigned int v69; // r2
  unsigned int *v70; // r2
  unsigned int v71; // r1
  __int16 v72; // r3
  unsigned int v73; // r3
  unsigned int v74; // r1
  int k; // [sp+8h] [bp-70h]
  int v76; // [sp+10h] [bp-68h]
  unsigned int v77; // [sp+18h] [bp-60h]
  int v79; // [sp+20h] [bp-58h]
  unsigned int v80; // [sp+24h] [bp-54h] BYREF
  unsigned int v81; // [sp+28h] [bp-50h]
  unsigned int j; // [sp+2Ch] [bp-4Ch]
  int v83; // [sp+30h] [bp-48h]
  unsigned int v84; // [sp+34h] [bp-44h]
  int v85; // [sp+38h] [bp-40h]
  unsigned int v86; // [sp+3Ch] [bp-3Ch]
  char v87[16]; // [sp+40h] [bp-38h] BYREF
  int v88; // [sp+50h] [bp-28h]

  v1 = a1;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) )
    sub_5370DC();
  KiStackAttachProcess(a1, 1, (int)v87);
  v2 = v1 + 492;
  v80 = v1 + 492;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v77 = v3;
  v4 = ExAllocatePoolWithTag(512, 16, 1917020493);
  v83 = v4;
  if ( v4 )
  {
    v5 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v1 + 492);
    }
    else
    {
      v6 = (unsigned __int8 *)(v1 + 495);
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 | 0x80, v6) );
      __dmb(0xBu);
      if ( v7 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v1 + 492));
      while ( 1 )
      {
        v8 = *(_DWORD *)v2;
        if ( (*(_DWORD *)v2 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v8 & 0x40000000) == 0 )
        {
          do
            v67 = __ldrex((unsigned int *)v2);
          while ( v67 == v8 && __strex(v8 | 0x40000000, (unsigned int *)v2) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    *(_BYTE *)(v1 + 607) |= 0xC0u;
    MiUnlockWorkingSetExclusive(v1 + 492, v5);
    v79 = 0;
    v11 = 0;
    v81 = 0;
    v12 = dword_63F9A0;
    __dmb(0xBu);
    if ( v12 && SmStoreExistsForProcess(v1, v9, v10, v12) )
      v79 = 1;
    LOCK_ADDRESS_SPACE(v3, v1);
    v13 = 0;
    k = 0;
    for ( i = *(_DWORD **)(a1 + 636); i; k = v13 )
    {
      v13 = (int)i;
      i = (_DWORD *)*i;
    }
    if ( v13 )
    {
      v15 = 524286;
      for ( j = 524286; ; v15 = j )
      {
        --*(_WORD *)(v3 + 310);
        v16 = v13 + 24;
        v85 = v13 + 24;
        if ( !KiAbEnabled || (v16 & 0x7FFFFFFC) == 0 )
        {
          v23 = 0;
          goto LABEL_31;
        }
        v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        if ( (__get_CPSR() & 0x80) != 0 )
        {
          v18 = 0;
        }
        else
        {
          __disable_irq();
          v18 = 1;
        }
        v19 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
        if ( v18 )
          __enable_irq();
        if ( (v19 & 0x10001) != 0 )
        {
          KeGetCurrentIrql(v15);
          KeBugCheckEx(402, v17, v16);
        }
        --*(_WORD *)(v17 + 310);
        if ( !*(_BYTE *)(v17 + 484) )
        {
          if ( !*(_BYTE *)(v17 + 810) )
          {
            v23 = 0;
            if ( (dword_682604 & 0x200) != 0 )
              v15 = EtwTraceAutoBoostEntryExhaustion(v17, v16);
            goto LABEL_116;
          }
          v63 = (unsigned __int8 *)(v17 + 810);
          v64 = *(_BYTE *)(v17 + 810);
          __dmb(0xBu);
          do
            v65 = __ldrex(v63);
          while ( __strex(v65 & ~v64, v63) );
          __dmb(0xBu);
          v66 = *(_BYTE *)(v17 + 484) | v64;
          v3 = v77;
          *(_BYTE *)(v17 + 484) = v66;
        }
        v20 = *(unsigned __int8 *)(v17 + 484);
        v15 = __clz(__rbit(v20));
        v21 = v20 & ~(1 << v15);
        v22 = v17 + 48 * v15;
        v23 = v22 + 488;
        v86 = v15;
        *(_BYTE *)(v17 + 484) = v21;
        if ( v22 != -488 )
        {
          if ( v16 >= dword_63389C
            && ((v24 = *((unsigned __int8 *)&MiState[2423]
                       + ((int)(((v16 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
                 v24 == 1)
             || v24 == 11) )
          {
            v15 = MmGetSessionIdEx(*(_DWORD *)(v17 + 116));
          }
          else
          {
            v15 = -1;
          }
          *(_DWORD *)(v23 + 20) = v15;
          *(_DWORD *)(v23 + 16) = v16 & 0x7FFFFFFC;
          goto LABEL_29;
        }
LABEL_116:
        v68 = (unsigned __int8 *)(v17 + 81);
        do
          v69 = __ldrex(v68);
        while ( __strex(v69 | 0x80, v68) );
LABEL_29:
        v25 = (__int16)(*(_WORD *)(v17 + 310) + 1);
        *(_WORD *)(v17 + 310) = v25;
        if ( !v25 && *(_DWORD *)(v17 + 100) != v17 + 100 )
          KiCheckForKernelApcDelivery(v15);
        v13 = k;
        v15 = j;
        do
LABEL_31:
          v26 = __ldrex((unsigned __int8 *)v16);
        while ( __strex(v26 | 1, (unsigned __int8 *)v16) );
        __dmb(0xBu);
        if ( (v26 & 1) != 0 )
        {
          ExfAcquirePushLockExclusiveEx(v16, v23, v16);
          v15 = j;
        }
        if ( v23 )
          *(_BYTE *)(v23 + 14) |= 1u;
        *(_BYTE *)(v3 + 968) |= 0x80u;
        v27 = *(_DWORD *)(v13 + 28);
        if ( ((1 << (v27 & 7)) & 0x55) == 0
          || (*(_DWORD *)(v13 + 28) & 7) == 2 && (*(_BYTE *)(v13 + 43) & 1) != 0
          || (v28 = *(_DWORD *)(v13 + 32) & 0x7FFFFFFF) == 0
          || v28 >= v15
          || (v27 & 0x4000) != 0 )
        {
          *(_BYTE *)(v3 + 968) &= 0x7Fu;
          __dmb(0xBu);
          do
            v51 = __ldrex((unsigned int *)v16);
          while ( __strex(v51 - 1, (unsigned int *)v16) );
          if ( (v51 & 2) != 0 && (v51 & 4) == 0 )
            ExfTryToWakePushLock(v16);
          v52 = KeAbPostRelease(v16);
          v53 = (__int16)(*(_WORD *)(v3 + 310) + 1);
          *(_WORD *)(v3 + 310) = v53;
          if ( !v53 && *(_DWORD *)(v3 + 100) != v3 + 100 )
            KiCheckForKernelApcDelivery(v52);
        }
        else
        {
          v29 = MiCheckCommitReleaseFromVad((int)MiSystemPartition, a1, a1 + 492, v13, v79);
          v30 = v29;
          v76 = v29;
          *(_BYTE *)(v77 + 968) &= 0x7Fu;
          __dmb(0xBu);
          do
            v31 = __ldrex((unsigned int *)v16);
          while ( __strex(v31 - 1, (unsigned int *)v16) );
          if ( (v31 & 2) != 0 && (v31 & 4) == 0 )
            v29 = ExfTryToWakePushLock(v16);
          if ( KiAbEnabled )
          {
            v32 = v16 & 0x7FFFFFFC;
            if ( (v16 & 0x7FFFFFFC) != 0 )
            {
              v33 = 0;
              v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              if ( v16 >= dword_63389C
                && ((v29 = 4092,
                     v35 = *((unsigned __int8 *)&MiState[2423]
                           + ((int)(((v16 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
                     v35 == 1)
                 || v35 == 11) )
              {
                v29 = MmGetSessionIdEx(*(_DWORD *)(v34 + 116));
                v36 = v29;
              }
              else
              {
                v36 = -1;
              }
              if ( (unsigned int)KeGetCurrentIrql(v29) <= 1 )
              {
                v33 = 1;
                --*(_WORD *)(v34 + 310);
              }
              v37 = *(char *)(v34 + 484);
              __dmb(0xBu);
              v38 = (unsigned __int8 *)(v34 + 810);
              v39 = (v37 | *(char *)(v34 + 810)) ^ 0x3F;
              v40 = __clz(v39);
              v29 = 31 - v40;
              v84 = 31 - v40;
              if ( 1 == (unsigned __int8)(v40 >> 5) )
              {
LABEL_140:
                if ( (*(_DWORD *)(v34 + 80) & 0x8000) == 0 )
                  KeBugCheckEx(354, v34, v85);
                if ( v33 )
                {
                  v72 = *(_WORD *)(v34 + 310) + 1;
                  *(_WORD *)(v34 + 310) = v72;
                  if ( !v72 && *(_DWORD *)(v34 + 100) != v34 + 100 )
                    v29 = KiCheckForKernelApcDelivery(v29);
                }
              }
              else
              {
                v41 = 2147483644;
                while ( 1 )
                {
                  v39 &= ~(1 << v29);
                  v42 = v34 + 48 * v29;
                  v43 = v42 + 488;
                  if ( (*(_BYTE *)(v42 + 502) & 1) != 0
                    && (*(_DWORD *)(v42 + 504) & 1) == 0
                    && (*(_DWORD *)(v42 + 504) & 0x7FFFFFFC) == v32
                    && *(_DWORD *)(v42 + 508) == v36 )
                  {
                    *(_BYTE *)(v42 + 502) &= 0xFEu;
                    if ( *(_DWORD *)(v42 + 504) )
                      break;
                  }
                  v62 = __clz(v39);
                  v29 = 31 - v62;
                  v84 = 31 - v62;
                  if ( 1 == (unsigned __int8)(v62 >> 5) )
                    goto LABEL_140;
                }
                *(_BYTE *)(v42 + 504) |= 2u;
                if ( (*(_DWORD *)(v42 + 504) & 0x80000000) != 0 )
                  KiAbEntryRemoveFromTree(v43);
                v44 = *(_WORD *)(v43 + 44);
                if ( v44 )
                {
                  if ( (v44 & 1) != 0 )
                  {
                    __dmb(0xBu);
                    v70 = (unsigned int *)(v34 + 804);
                    do
                      v71 = __ldrex(v70);
                    while ( __strex(v71 - 1, v70) );
                    __dmb(0xBu);
                    PsBoostThreadIoEx(v34, 1, 0);
                  }
                  if ( (*(_WORD *)(v43 + 44) & 0xFFFE) != 0 )
                    KiAbThreadUnboostCpuPriority(v34, v43, v41, *(_WORD *)(v43 + 44) & 0xFFFE);
                  if ( (dword_682604 & 0x200) != 0 )
                    EtwTraceAutoBoostClearFloor(
                      v34,
                      *(_DWORD *)(v43 + 16) & 0xFFFFFFFC | 0x80000000,
                      *(unsigned __int16 *)(v43 + 44));
                  *(_WORD *)(v43 + 44) = 0;
                }
                *(_BYTE *)(v43 + 13) &= 0xFEu;
                *(_DWORD *)(v43 + 16) = 0;
                v29 = (unsigned __int64)(715827883i64 * (v43 - v34 - 488)) >> 32;
                v45 = (v43 - v34 - 488) / 48;
                if ( v33 )
                {
                  *(_BYTE *)(v34 + 484) |= 1 << v45;
                  v46 = (__int16)(*(_WORD *)(v34 + 310) + 1);
                  *(_WORD *)(v34 + 310) = v46;
                  if ( !v46 && *(_DWORD *)(v34 + 100) != v34 + 100 )
                    v29 = KiCheckForKernelApcDelivery(v29);
                }
                else
                {
                  __dmb(0xBu);
                  do
                    v29 = __ldrex(v38);
                  while ( __strex(v29 | (1 << v45), v38) );
                  __dmb(0xBu);
                }
              }
              v13 = k;
              v30 = v76;
            }
          }
          v47 = (__int16)(*(_WORD *)(v77 + 310) + 1);
          *(_WORD *)(v77 + 310) = v47;
          if ( !v47 && *(_DWORD *)(v77 + 100) != v77 + 100 )
            KiCheckForKernelApcDelivery(v29);
          v48 = v81 + v30;
          v3 = v77;
          v81 = v48;
        }
        v49 = *(_DWORD ***)(v13 + 4);
        v50 = v13;
        if ( v49 )
        {
          v13 = *(_DWORD *)(v13 + 4);
          v54 = *v49;
          for ( k = v13; v54; k = v13 )
          {
            v13 = (int)v54;
            v54 = (_DWORD *)*v54;
          }
        }
        else
        {
          v13 = *(_DWORD *)(v13 + 8) & 0xFFFFFFFC;
          k = v13;
          if ( v13 )
          {
            do
            {
              if ( *(_DWORD *)v13 == v50 )
                break;
              v50 = v13;
              v13 = *(_DWORD *)(v13 + 8) & 0xFFFFFFFC;
            }
            while ( v13 );
            k = v13;
          }
        }
        if ( !v13 )
        {
          v2 = v80;
          v11 = v81;
          break;
        }
      }
    }
    UNLOCK_ADDRESS_SPACE(v3, a1);
    if ( v79 )
    {
      SmQueryStoreCommitUsage(a1, &v80);
      v73 = ((v80 & 0xFFF) != 0) + (v80 >> 12);
      if ( v11 <= v73 )
      {
        v11 = 0;
LABEL_88:
        v55 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
        }
        else
        {
          v56 = (unsigned __int8 *)(v2 + 3);
          do
            v57 = __ldrex(v56);
          while ( __strex(v57 | 0x80, v56) );
          __dmb(0xBu);
          if ( v57 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v2);
          while ( 1 )
          {
            v58 = *(_DWORD *)v2;
            if ( (*(_DWORD *)v2 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v58 & 0x40000000) == 0 )
            {
              do
                v74 = __ldrex((unsigned int *)v2);
              while ( v74 == v58 && __strex(v58 | 0x40000000, (unsigned int *)v2) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v59 = *(_BYTE *)(v2 + 115);
        if ( v11 )
        {
          *(_BYTE *)(v2 + 115) = v59 & 0x3F | 0x80;
          v60 = v83;
          *(_DWORD *)(v2 + 116) = v11;
          v4 = 0;
          *(_DWORD *)(v2 + 124) = v60;
        }
        else
        {
          v4 = v83;
          *(_BYTE *)(v2 + 115) = v59 & 0x3F;
        }
        MiUnlockWorkingSetExclusive(v2, v55);
        MiLogOutswappedProcessCommitRelease(a1, v11);
        goto LABEL_97;
      }
      v11 -= v73;
    }
    if ( v11 )
      MiReturnCommit(MiSystemPartition, v11);
    goto LABEL_88;
  }
LABEL_97:
  v88 = 0;
  result = KiUnstackDetachProcess((unsigned int)v87, 1);
  if ( v4 )
    result = ExFreePoolWithTag(v4, 0);
  return result;
}
