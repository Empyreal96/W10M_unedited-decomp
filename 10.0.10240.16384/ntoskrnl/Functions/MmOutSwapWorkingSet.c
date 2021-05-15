// MmOutSwapWorkingSet 
 
int __fastcall MmOutSwapWorkingSet(int a1, int a2)
{
  int v2; // r6
  unsigned int v4; // r9
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v9; // r4
  int *v10; // r0
  int *v11; // r10
  int v12; // r4
  unsigned int v13; // r1
  int v14; // r6
  unsigned int v15; // r9
  unsigned int v16; // r1
  int v17; // r4
  int v18; // r1
  unsigned int v19; // r0
  int v20; // r4
  int v21; // r3
  unsigned int v22; // r6
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r7
  bool v26; // zf
  int v27; // r8
  __int64 v28; // r2
  int v29; // r0
  _DWORD *v30; // r2
  int v31; // r6
  _DWORD *v32; // r4
  _DWORD *i; // r3
  int v34; // r6
  _DWORD *v35; // r3
  unsigned __int8 *v36; // r3
  unsigned int v37; // r1
  unsigned int v38; // r0
  unsigned int v39; // r1
  int v40; // r4
  int v41; // r0
  int v42; // r4
  int v43; // r7
  unsigned int v44; // r1
  int v45; // r6
  unsigned int *v46; // r2
  unsigned int v47; // r0
  unsigned int v48; // r0
  int v49; // r0
  __int16 v50; // r3
  char v51; // [sp+8h] [bp-A8h]
  int v53; // [sp+10h] [bp-A0h]
  unsigned int v54; // [sp+14h] [bp-9Ch]
  unsigned int v55; // [sp+18h] [bp-98h]
  int *v56; // [sp+1Ch] [bp-94h]
  unsigned int v57; // [sp+28h] [bp-88h] BYREF
  int v58[18]; // [sp+30h] [bp-80h] BYREF
  int var38[15]; // [sp+78h] [bp-38h] BYREF

  v2 = a1;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v53 = a1 + 492;
  v54 = 0;
  v55 = v4;
  v51 = 0;
  memset(v58, 0, sizeof(v58));
  v7 = 0;
  var38[0] = 0;
  if ( a2 )
  {
    v7 = 1;
    var38[0] = 1;
  }
  if ( SmStoreExistsForProcess(v2, v5, v6, v7) )
    return sub_51CD18();
  EtwTraceWorkingSetSwap(v2, 2, var38, -1);
  if ( MiFindBestOutswapPagefile(MiSystemPartition, &v57) == 2 )
  {
    v9 = -1073741497;
  }
  else
  {
    v10 = (int *)ExAllocatePoolWithTag(512, 40, 1129540941);
    v11 = v10;
    v56 = v10;
    if ( v10 )
    {
      memset(v10, 0, 40);
      v51 = 1;
      --*(_WORD *)(v4 + 310);
      v12 = KeAbPreAcquire(&dword_63F98C, 0, 0);
      do
        v13 = __ldrex((unsigned __int8 *)&dword_63F98C);
      while ( __strex(v13 | 1, (unsigned __int8 *)&dword_63F98C) );
      __dmb(0xBu);
      if ( (v13 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&dword_63F98C, v12, &dword_63F98C);
      if ( v12 )
        *(_BYTE *)(v12 + 14) |= 1u;
      v14 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        v15 = 328;
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_63F990);
      }
      else
      {
        do
          v16 = __ldrex((unsigned __int8 *)&dword_63F990 + 3);
        while ( __strex(v16 | 0x80, (unsigned __int8 *)&dword_63F990 + 3) );
        __dmb(0xBu);
        v15 = 0x148u;
        if ( v16 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_63F990);
        while ( 1 )
        {
          v17 = dword_63F990;
          if ( (dword_63F990 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (dword_63F990 & 0x40000000) == 0 )
          {
            v18 = dword_63F990 | 0x40000000;
            do
              v19 = __ldrex((unsigned int *)&dword_63F990);
            while ( v19 == v17 && __strex(v18, (unsigned int *)&dword_63F990) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
        v11 = v56;
      }
      v20 = a1;
      v21 = *(_DWORD *)(a1 + 612);
      if ( v21 )
      {
        if ( v21 == 1 )
        {
          v9 = -1073740682;
        }
        else if ( v21 == 2 )
        {
          v9 = -1073741558;
        }
        else
        {
          v9 = -1073741791;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiSystemPartition[v15]);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)&MiSystemPartition[v15] = 0;
        }
        KfLowerIrql(v14);
      }
      else
      {
        *(_DWORD *)(a1 + 612) = 1;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiSystemPartition[v15]);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)&MiSystemPartition[v15] = 0;
        }
        KfLowerIrql(v14);
        v22 = v57;
        while ( 1 )
        {
          v23 = *(_DWORD *)(v20 + 548);
          v54 = v23;
          if ( !v23 )
          {
            v9 = -1073741779;
            goto LABEL_99;
          }
          if ( v58[14] == -1 )
            goto LABEL_51;
          v9 = MiReserveWorkingSetSwapSpace(MiSystemPartition, &v58[4]);
          if ( v9 >= 0 )
            break;
          if ( v22 >= 2 )
            goto LABEL_99;
          v9 = MiExtendWorkingSetSwapPagefile(MiSystemPartition, v54, v22);
          if ( v9 < 0 )
            goto LABEL_99;
          v20 = a1;
        }
        v20 = a1;
        v23 = v54;
LABEL_51:
        v24 = MiAllocateWorkingSetSwapSupport(v23);
        *v11 = v24;
        if ( !v24 )
        {
          v9 = -1073741670;
LABEL_99:
          v27 = v53;
          goto LABEL_100;
        }
        v25 = 0;
        v26 = a2 == 0;
        v27 = v53;
        if ( v26 )
          goto LABEL_59;
        v28 = *(_QWORD *)(v53 + 60);
        v25 = v28 - HIDWORD(v28);
        if ( (int)v28 - HIDWORD(v28) > (unsigned int)v28 )
          v25 = *(_DWORD *)(v53 + 60);
        if ( !v25 || (v29 = MiAllocateWorkingSetSwapSupport(v25), (v11[1] = v29) != 0) )
        {
LABEL_59:
          v58[0] = *v11;
          v58[1] = v11[1];
          v58[2] = v53;
          LOCK_ADDRESS_SPACE_SHARED(v55, v20);
          if ( (*(_DWORD *)(v20 + 192) & 0x20) != 0 )
          {
            UNLOCK_ADDRESS_SPACE_SHARED(v55, v20, v30);
            v9 = -1073741558;
          }
          else
          {
            v31 = a1;
            v32 = 0;
            for ( i = *(_DWORD **)(a1 + 636); i; i = (_DWORD *)*i )
              v32 = i;
            if ( v32 )
            {
              do
              {
                if ( !MiVadMapsLargeImage(v32) && ((1 << (v32[7] & 7)) & 0x55) != 0 )
                {
                  v34 = KfRaiseIrql(2);
                  if ( (dword_682604 & 0x210000) != 0 )
                  {
                    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v53);
                  }
                  else
                  {
                    v36 = (unsigned __int8 *)(v53 + 3);
                    do
                      v37 = __ldrex(v36);
                    while ( __strex(v37 | 0x80, v36) );
                    __dmb(0xBu);
                    if ( v37 >> 7 )
                      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v53);
                    while ( 1 )
                    {
                      v38 = *(_DWORD *)v53;
                      if ( (*(_DWORD *)v53 & 0xBFFFFFFF) == 0x80000000 )
                        break;
                      if ( (v38 & 0x40000000) == 0 )
                      {
                        do
                          v39 = __ldrex((unsigned int *)v53);
                        while ( v39 == v38 && __strex(v38 | 0x40000000, (unsigned int *)v53) );
                        __dmb(0xBu);
                      }
                      __dmb(0xAu);
                      __yield();
                    }
                  }
                  LOBYTE(v58[3]) = v34;
                  if ( !MiVadDeleted(v32) )
                  {
                    MiEnumerateLeafPtes(v32[3] << 12, v32[4] << 12, MiOutSwapWorkingSetCallback, v58);
                    v34 = LOBYTE(v58[3]);
                  }
                  MiUnlockWorkingSetExclusive(v53, v34);
                }
                v35 = (_DWORD *)v32[1];
                v30 = v32;
                if ( v35 )
                {
                  do
                  {
                    v32 = v35;
                    v35 = (_DWORD *)*v35;
                  }
                  while ( v35 );
                }
                else
                {
                  while ( 1 )
                  {
                    v32 = (_DWORD *)(v32[2] & 0xFFFFFFFC);
                    if ( !v32 || (_DWORD *)*v32 == v30 )
                      break;
                    v30 = v32;
                  }
                }
              }
              while ( v32 );
              v11 = v56;
              v31 = a1;
              v15 = 328;
            }
            UNLOCK_ADDRESS_SPACE_SHARED(v55, v31, v30);
            if ( *(_DWORD *)(*v11 + 8) < v54 )
            {
              v40 = ((int (*)(void))MiReAllocateWorkingSetSwapSupport)();
              if ( v40 )
              {
                ExFreePoolWithTag(*v11, 0);
                *v11 = v40;
              }
            }
            v41 = v11[1];
            if ( v41 )
            {
              if ( *(_DWORD *)(v41 + 8) < v25 )
              {
                v42 = ((int (*)(void))MiReAllocateWorkingSetSwapSupport)();
                if ( v42 )
                {
                  ExFreePoolWithTag(v11[1], 0);
                  v11[1] = v42;
                }
              }
            }
            v54 = *(_DWORD *)(*v11 + 12);
            MiGetKernelStackSwapSupport(v11, v31);
            v51 = 5;
            v9 = 0;
          }
        }
        else
        {
          v9 = -1073741670;
        }
LABEL_100:
        v43 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&MiSystemPartition[v15]);
        }
        else
        {
          do
            v44 = __ldrex((unsigned __int8 *)&dword_63F990 + 3);
          while ( __strex(v44 | 0x80, (unsigned __int8 *)&dword_63F990 + 3) );
          __dmb(0xBu);
          if ( v44 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&MiSystemPartition[v15]);
          while ( 1 )
          {
            v45 = *(_DWORD *)&MiSystemPartition[v15];
            if ( (v45 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v45 & 0x40000000) == 0 )
            {
              v46 = (unsigned int *)&MiSystemPartition[v15];
              do
                v47 = __ldrex(v46);
              while ( v47 == v45 && __strex(v45 | 0x40000000, v46) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
          v11 = v56;
        }
        if ( *(_DWORD *)(v27 + 120) == 1 )
        {
          if ( (v51 & 4) != 0 )
          {
            *(_DWORD *)(v27 + 120) = v11;
            v11 = 0;
            v9 = 0;
          }
          else
          {
            *(_DWORD *)(v27 + 120) = 0;
          }
        }
        else
        {
          v9 = -1073741558;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiSystemPartition[v15]);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)&MiSystemPartition[v15] = 0;
        }
        KfLowerIrql(v43);
        MiFreeReservationRuns(MiSystemPartition, &v58[4]);
      }
      if ( v11 )
        MiFreeWorkingSetSwapContext(MiSystemPartition, v11);
      v4 = v55;
      v2 = a1;
    }
    else
    {
      v9 = -1073741670;
    }
  }
  if ( (v51 & 1) != 0 )
  {
    __dmb(0xBu);
    do
      v48 = __ldrex((unsigned int *)&dword_63F98C);
    while ( __strex(v48 - 1, (unsigned int *)&dword_63F98C) );
    if ( (v48 & 2) != 0 && (v48 & 4) == 0 )
      ExfTryToWakePushLock(&dword_63F98C);
    v49 = KeAbPostRelease(&dword_63F98C);
    v50 = *(_WORD *)(v4 + 310) + 1;
    *(_WORD *)(v4 + 310) = v50;
    if ( !v50 && *(_DWORD *)(v4 + 100) != v4 + 100 )
      KiCheckForKernelApcDelivery(v49);
  }
  var38[0] = v54;
  var38[4] = v9;
  var38[1] = v58[15];
  var38[2] = v58[16];
  var38[3] = v58[17];
  EtwTraceWorkingSetSwap(v2, 0, var38, v58[17]);
  return v9;
}
