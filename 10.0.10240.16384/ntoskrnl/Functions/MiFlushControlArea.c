// MiFlushControlArea 
 
int __fastcall MiFlushControlArea(_DWORD *a1, int a2, int *a3)
{
  int v4; // r3
  int v6; // r9
  unsigned int *v7; // r5
  int v8; // r6
  int v9; // r10
  int v10; // r8
  unsigned __int64 *v11; // r3
  unsigned __int64 v12; // kr00_8
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  int v17; // r8
  int v18; // r10
  int v19; // r7
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r1
  int v24; // r1
  unsigned int v25; // r0
  int v27; // [sp+10h] [bp-50h]
  int v28; // [sp+14h] [bp-4Ch]
  int v29; // [sp+14h] [bp-4Ch]
  int v31; // [sp+20h] [bp-40h] BYREF
  int v32[2]; // [sp+28h] [bp-38h] BYREF
  int v33; // [sp+30h] [bp-30h]
  char v34; // [sp+34h] [bp-2Ch]
  char v35; // [sp+35h] [bp-2Bh]
  char v36; // [sp+36h] [bp-2Ah]
  int v37; // [sp+38h] [bp-28h]
  int var24[10]; // [sp+3Ch] [bp-24h] BYREF
  int vars4; // [sp+64h] [bp+4h]

  a1[7] |= 0x100u;
  v33 = 0;
  v32[1] = 4;
  v34 = 7;
  v35 = 1;
  v36 = 4;
  v37 = 0;
  var24[1] = (int)var24;
  var24[0] = (int)var24;
  v4 = a1[11];
  *a3 = 0;
  v32[0] = v4;
  a1[11] = v32;
  v6 = MiPreventControlAreaDelete(a1);
  v7 = a1 + 9;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v7 = 0;
  }
  KfLowerIrql(a2);
  v8 = 0;
  v9 = 0;
  v27 = 0;
  if ( FsRtlAcquireFileForCcFlushEx(v6) >= 0 )
  {
    v9 = 1;
    v27 = 1;
  }
  v10 = KfRaiseIrql(2);
  v28 = v10;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 9);
  }
  else
  {
    v13 = (unsigned __int8 *)a1 + 39;
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a1 + 9);
    while ( 1 )
    {
      v15 = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v16 = __ldrex(v7);
        while ( v16 == v15 && __strex(v15 | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v11 = (unsigned __int64 *)(a1 + 16);
  do
    v12 = __ldrexd(v11);
  while ( __strexd(v12 - 1, v11) );
  if ( !v9 || (a1[7] & 1) != 0 )
  {
    v33 = 1;
    a1[7] &= 0xFFFFFEFF;
    if ( v12 == 1 )
    {
      MiRemoveWakeListEntry(a1, v32);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v7 = 0;
      }
      KfLowerIrql(v10);
      if ( v9 == 1 )
        FsRtlReleaseFileForCcFlush(v6);
      MiDeleteControlArea(a1);
      ObfDereferenceObjectWithTag(v6);
      return 0;
    }
    v17 = 0;
    v19 = v28;
    v18 = 0;
  }
  else
  {
    ++a1[10];
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
    KfLowerIrql(v10);
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 1;
    v17 = MiFlushSectionInternal(0, 0, a1 + 20, 0, 0, 2u, &v31);
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 0;
    FsRtlReleaseFileForCcFlush(v6);
    v27 = 0;
    if ( v17 < 0 )
      v8 = ExAllocatePoolWithTag(512, 32);
    v18 = (*(_DWORD *)(*(_DWORD *)(v6 + 4) + 32) & 0x10) != 0;
    MI_DEREFERENCE_CONTROL_AREA_FILE((int)a1, v6);
    v29 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 9);
    }
    else
    {
      v20 = (unsigned __int8 *)a1 + 39;
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 | 0x80, v20) );
      __dmb(0xBu);
      if ( v21 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(a1 + 9);
      while ( 1 )
      {
        v22 = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v22 & 0x40000000) == 0 )
        {
          do
            v23 = __ldrex(v7);
          while ( v23 == v22 && __strex(v22 | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v19 = v29;
    a1[7] &= 0xFFFFFEFF;
    *a3 = MiDecrementModifiedWriteCount((int)a1, 1);
  }
  MiRemoveWakeListEntry(a1, v32);
  if ( !(a1[3] | a1[7] & 1 | a1[5]) )
  {
    if ( v33 && a1[4] )
      goto LABEL_45;
    if ( v17 < 0 && a1[4] )
    {
      if ( v17 == -1073740749 || !MmIsWriteErrorFatal(1, v18, v17) )
      {
LABEL_45:
        MiInsertUnusedSegment(a1, v24);
        goto LABEL_46;
      }
      if ( v8 )
      {
        v25 = ObFastReferenceObjectLocked(a1 + 8);
        *(_BYTE *)(v8 + 28) = 1;
        *(_DWORD *)(v8 + 16) = v25;
        *(_DWORD *)(v8 + 20) = v17;
        *(_DWORD *)(v8 + 8) = MiLdwPopupWorker;
        *(_DWORD *)(v8 + 12) = v8;
        *(_DWORD *)v8 = 0;
        ExQueueWorkItem((_DWORD *)v8, 1);
      }
    }
    return 1;
  }
LABEL_46:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v7 = 0;
  }
  KfLowerIrql(v19);
  if ( v27 == 1 )
    FsRtlReleaseFileForCcFlush(v6);
  if ( v8 )
    ExFreePoolWithTag(v8);
  return 0;
}
