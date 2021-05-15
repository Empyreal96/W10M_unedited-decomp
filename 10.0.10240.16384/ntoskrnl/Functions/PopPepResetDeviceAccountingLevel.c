// PopPepResetDeviceAccountingLevel 
 
int PopPepResetDeviceAccountingLevel()
{
  unsigned int v0; // r1
  int v1; // r3
  int result; // r0
  int v3; // r9
  int v4; // r6
  int v5; // r2
  int v6; // r3
  int v7; // r0
  unsigned __int8 *v8; // r4
  char v9; // r5
  unsigned int v10; // r0
  unsigned int v11; // r2
  unsigned int v12; // r3
  int v13; // r4
  unsigned __int8 *v14; // r3
  unsigned int v15; // r2
  int v16; // r3
  __int16 v17; // r3
  unsigned int v18; // r2
  int *i; // r5
  int v20; // r7
  int v21; // r3
  unsigned int *v22; // r4
  int v23; // r6
  unsigned int v24; // r2
  int v25; // r3
  __int64 v26; // r0
  unsigned int j; // r6
  int v28; // r4
  int v29; // r10
  unsigned int v30; // r2
  int v31; // r3
  __int64 v32; // r0
  unsigned int v33; // r2
  int v34; // r6
  int v35; // r4
  int v36; // r3
  int v37; // r5
  int v38; // r2
  int v39; // r5
  int v40; // r3
  int v41; // r3
  unsigned __int8 *v42; // r2
  unsigned int v43; // r4
  unsigned int v44; // r1
  __int16 v45; // r3
  unsigned int v46; // [sp+8h] [bp-28h]
  unsigned int v47; // [sp+Ch] [bp-24h]
  int v48; // [sp+Ch] [bp-24h]
  int vars4; // [sp+34h] [bp+4h]

  __dmb(0xBu);
  do
    v0 = __ldrex((unsigned int *)&PopFxDeviceAccountingLevel);
  while ( !v0 && __strex(0, (unsigned int *)&PopFxDeviceAccountingLevel) );
  v46 = v0;
  __dmb(0xBu);
  v1 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v1 & 0xFFFFFFC0) + 0x134);
  result = (int)MiState;
  v3 = -1;
  if ( !KiAbEnabled || ((unsigned int)&PopPepDeviceListLock & 0x7FFFFFFC) == 0 )
  {
    v13 = 0;
    goto LABEL_34;
  }
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v5 = 0;
  }
  else
  {
    __disable_irq();
    v5 = 1;
  }
  v6 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v5 )
    __enable_irq();
  if ( (v6 & 0x10001) != 0 )
  {
    v7 = KeGetCurrentIrql(MiState);
    KeBugCheckEx(402, v4, (int)&PopPepDeviceListLock, v7, 0);
  }
  --*(_WORD *)(v4 + 310);
  if ( !*(_BYTE *)(v4 + 484) )
  {
    if ( !*(_BYTE *)(v4 + 810) )
    {
      v13 = 0;
      if ( (dword_682604 & 0x200) != 0 )
        result = (int)EtwTraceAutoBoostEntryExhaustion(v4, (int)&PopPepDeviceListLock);
      goto LABEL_19;
    }
    v8 = (unsigned __int8 *)(v4 + 810);
    v9 = *(_BYTE *)(v4 + 810);
    __dmb(0xBu);
    do
      v10 = __ldrex(v8);
    while ( __strex(v10 & ~v9, v8) );
    __dmb(0xBu);
    result = (int)MiState;
    *(_BYTE *)(v4 + 484) |= v9;
  }
  v11 = *(unsigned __int8 *)(v4 + 484);
  v47 = __clz(__rbit(v11));
  *(_BYTE *)(v4 + 484) = v11 & ~(unsigned __int8)(1 << v47);
  v12 = v4 + 48 * v47;
  v13 = v12 + 488;
  if ( v12 == -488 )
  {
LABEL_19:
    v14 = (unsigned __int8 *)(v4 + 81);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 | 0x80, v14) );
    goto LABEL_30;
  }
  if ( (unsigned int)&PopPepDeviceListLock >= dword_63389C
    && ((v16 = *((unsigned __int8 *)&MiState[2423]
               + ((int)((((unsigned int)&PopPepDeviceListLock >> 20) & 0xFFC)
                      - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v16 == 1)
     || v16 == 11) )
  {
    result = MmGetSessionIdEx(*(_DWORD *)(v4 + 116));
  }
  else
  {
    result = -1;
  }
  *(_DWORD *)(v13 + 20) = result;
  *(_DWORD *)(v13 + 16) = (unsigned int)&PopPepDeviceListLock & 0x7FFFFFFC;
LABEL_30:
  v17 = *(_WORD *)(v4 + 310) + 1;
  *(_WORD *)(v4 + 310) = v17;
  if ( !v17 && *(_DWORD *)(v4 + 100) != v4 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  do
LABEL_34:
    v18 = __ldrex((unsigned int *)&PopPepDeviceListLock);
  while ( !v18 && __strex(0x11u, (unsigned int *)&PopPepDeviceListLock) );
  __dmb(0xBu);
  if ( v18 )
    result = ExfAcquirePushLockSharedEx(&PopPepDeviceListLock, v13, (unsigned int)&PopPepDeviceListLock);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  for ( i = (int *)PopPepDeviceList; i != &PopPepDeviceList; i = (int *)*i )
  {
    v20 = i[6];
    v21 = *(_DWORD *)(v20 + 28);
    if ( v21 )
    {
      v48 = *(_DWORD *)(v21 + 16);
      PoFxActivateDevice(v48);
      v22 = (unsigned int *)(v20 + 344);
      v23 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v20 + 344);
      }
      else
      {
        do
          v24 = __ldrex(v22);
        while ( __strex(1u, v22) );
        __dmb(0xBu);
        if ( v24 )
          KxWaitForSpinLockAndAcquire((unsigned int *)(v20 + 344));
      }
      *(_DWORD *)(v20 + 368) = 0;
      *(_DWORD *)(v20 + 372) = 0;
      *(_DWORD *)(v20 + 356) = v46;
      v25 = *(_DWORD *)(v20 + 352);
      *(_DWORD *)(v20 + 376) = 0;
      *(_DWORD *)(v20 + 380) = 0;
      if ( v25 == 5 )
      {
        *(_BYTE *)(v20 + 348) = 0;
        *(_DWORD *)(v20 + 360) = 0;
        *(_DWORD *)(v20 + 364) = 0;
      }
      else
      {
        *(_BYTE *)(v20 + 348) = 1;
        LODWORD(v26) = KeQueryInterruptTime();
        *(_QWORD *)(v20 + 360) = v26;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented((_DWORD *)(v20 + 344), vars4);
      }
      else
      {
        __dmb(0xBu);
        *v22 = 0;
      }
      KfLowerIrql(v23);
      for ( j = 0; j < i[30]; ++j )
      {
        v28 = *(_DWORD *)(*(_DWORD *)(v20 + 392) + 4 * j) + 144;
        v29 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v28);
        }
        else
        {
          do
            v30 = __ldrex((unsigned int *)v28);
          while ( __strex(1u, (unsigned int *)v28) );
          __dmb(0xBu);
          if ( v30 )
            KxWaitForSpinLockAndAcquire((unsigned int *)v28);
        }
        *(_DWORD *)(v28 + 24) = 0;
        *(_DWORD *)(v28 + 28) = 0;
        *(_DWORD *)(v28 + 12) = v46;
        v31 = *(_DWORD *)(v28 + 8);
        *(_DWORD *)(v28 + 32) = 0;
        *(_DWORD *)(v28 + 36) = 0;
        if ( v31 == -1 )
        {
          *(_BYTE *)(v28 + 4) = 0;
          *(_DWORD *)(v28 + 16) = 0;
          *(_DWORD *)(v28 + 20) = 0;
        }
        else
        {
          *(_BYTE *)(v28 + 4) = 1;
          LODWORD(v32) = KeQueryInterruptTime();
          *(_QWORD *)(v28 + 16) = v32;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented((_DWORD *)v28, vars4);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v28 = 0;
        }
        KfLowerIrql(v29);
      }
      result = PoFxIdleDevice(v48);
    }
  }
  __dmb(0xBu);
  do
    v33 = __ldrex((unsigned int *)&PopPepDeviceListLock);
  while ( v33 == 17 && __strex(0, (unsigned int *)&PopPepDeviceListLock) );
  if ( v33 != 17 )
    result = (int)ExfReleasePushLockShared(&PopPepDeviceListLock);
  if ( KiAbEnabled && ((unsigned int)&PopPepDeviceListLock & 0x7FFFFFFC) != 0 )
  {
    v34 = 0;
    v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (unsigned int)&PopPepDeviceListLock >= dword_63389C )
    {
      result = 4092;
      v36 = *((unsigned __int8 *)&MiState[2423]
            + ((int)((((unsigned int)&PopPepDeviceListLock >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
      if ( v36 == 1 || v36 == 11 )
      {
        result = *(_DWORD *)(v35 + 116);
        v37 = *(_DWORD *)(result + 324);
        if ( v37 )
        {
          result = PsIsSystemProcess(result);
          if ( !result )
            v3 = *(_DWORD *)(v37 + 8);
        }
      }
    }
    if ( (unsigned int)KeGetCurrentIrql(result) <= 1 )
    {
      v34 = 1;
      --*(_WORD *)(v35 + 310);
    }
    result = KiAbThreadClearAcquiredLockEntry(v35, (int)&PopPepDeviceListLock, v3);
    v39 = result;
    if ( result )
    {
      *(_BYTE *)(result + 16) |= 2u;
      if ( *(int *)(result + 16) < 0 )
        KiAbEntryRemoveFromTree(result);
      result = KiAbEntryRemoveBoosts(v39, v35, v38);
      *(_BYTE *)(v39 + 13) &= 0xFEu;
      *(_DWORD *)(v39 + 16) = 0;
      v41 = (v39 - v35 - 488) / 48;
      if ( !v34 )
      {
        __dmb(0xBu);
        result = (char)(1 << v41);
        v42 = (unsigned __int8 *)(v35 + 810);
        do
          v43 = __ldrex(v42);
        while ( __strex(v43 | result, v42) );
        __dmb(0xBu);
        goto LABEL_97;
      }
      *(_BYTE *)(v35 + 484) |= 1 << v41;
      goto LABEL_87;
    }
    if ( (*(_DWORD *)(v35 + 80) & 0x8000) == 0 )
      KeBugCheckEx(354, v35, (int)&PopPepDeviceListLock, v3, 0);
    if ( v34 )
    {
LABEL_87:
      v40 = (__int16)(*(_WORD *)(v35 + 310) + 1);
      *(_WORD *)(v35 + 310) = v40;
      if ( !v40 && *(_DWORD *)(v35 + 100) != v35 + 100 )
        result = KiCheckForKernelApcDelivery(result);
      goto LABEL_97;
    }
  }
LABEL_97:
  v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v45 = *(_WORD *)(v44 + 0x134) + 1;
  *(_WORD *)(v44 + 308) = v45;
  if ( !v45 && *(_DWORD *)(v44 + 100) != v44 + 100 && !*(_WORD *)(v44 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
