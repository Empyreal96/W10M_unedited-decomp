// IovCallDriver 
 
int __fastcall IovCallDriver(int a1, int a2, int a3, int a4)
{
  int v6; // r3
  int v8; // r0
  int v9; // r4
  int v10; // r3
  unsigned __int8 *v11; // r3
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r5
  unsigned int v15; // r2
  int v16; // r5
  char v17; // r4
  unsigned int v18; // r2
  char v19; // r4
  unsigned int v20; // r2
  int v21; // r8
  int v22; // r3
  char v23; // r4
  unsigned int v24; // r2
  int v25; // r1
  int v26; // r8
  int v27; // r0
  int v28; // r3
  unsigned __int8 *v29; // r3
  int v30; // r2
  int v31; // r3
  int v33[6]; // [sp+8h] [bp-18h] BYREF

  v33[0] = a4;
  v6 = IovpEnabledInThePast;
  __dmb(0xBu);
  if ( !v6 && (MmVerifierData & 0x20) == 0 )
  {
    if ( (IopFunctionPointerMask & 2) != 0 )
      return IopPerfCallDriver(a1, a2);
    v10 = (char)(*(_BYTE *)(a2 + 35) - 1);
    *(_BYTE *)(a2 + 35) = v10;
    if ( v10 <= 0 )
      KeBugCheckEx(53, a2, 0, 0, 0);
    v11 = (unsigned __int8 *)(*(_DWORD *)(a2 + 96) - 40);
    *(_DWORD *)(a2 + 96) = v11;
    v12 = *v11;
    *((_DWORD *)v11 + 6) = a1;
    if ( v12 == 22 && ((v13 = v11[1], v13 == 2) || v13 == 3) )
      v8 = IopPoHandleIrp(a2, a2, 22, v13);
    else
      v8 = (*(int (__fastcall **)(int, int))(*(_DWORD *)(a1 + 8) + 4 * v12 + 56))(a1, a2);
    return v8;
  }
  v14 = KeGetCurrentIrql(a1);
  if ( v14 > 2 )
  {
    KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
    }
    else
    {
      do
        v15 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
      while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
      __dmb(0xBu);
      if ( v15 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
    }
    VfBugcheckTmpData = 201;
    dword_909044 = 16;
    dword_909048 = v14;
    dword_90904C = 0;
    dword_909050 = 0;
    VfBugCheckNoStackUsage();
  }
  if ( !VfIrpAllocateCallDriverData(a2, v33) )
    return IovpCallDriverWithStackBuffer(a1, a2, a3);
  v16 = v33[0];
  if ( !v33[0] )
    return IovpCallDriverNoIrpTracking(a1, a2, a3);
  *(_DWORD *)(v33[0] + 96) = a1;
  *(_DWORD *)(v16 + 100) = a2;
  *(_DWORD *)(v16 + 104) = a3;
  if ( **(_WORD **)(v16 + 100) != 6 )
  {
    v17 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
    }
    else
    {
      do
        v18 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
      while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
      __dmb(0xBu);
      if ( v18 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
    }
    *(_BYTE *)(v16 + 93) = v17;
    VfBugcheckTmpData = 201;
    dword_909044 = 3;
    dword_909048 = *(_DWORD *)(v16 + 100);
    dword_90904C = 0;
    dword_909050 = 0;
    VfBugCheckNoStackUsage();
  }
  if ( !IovpValidateDeviceObject(*(_DWORD *)(v16 + 96)) )
  {
    v19 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
    }
    else
    {
      do
        v20 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
      while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
      __dmb(0xBu);
      if ( v20 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
    }
    *(_BYTE *)(v16 + 93) = v19;
    VfBugcheckTmpData = 201;
    dword_909044 = 4;
    dword_909048 = *(_DWORD *)(v16 + 96);
    dword_90904C = 0;
    dword_909050 = 0;
    VfBugCheckNoStackUsage();
  }
  v21 = *(_DWORD *)(a2 + 96);
  if ( !*(_BYTE *)(v21 - 40) )
  {
    v22 = *(_DWORD *)(v21 - 12);
    if ( v22 )
    {
      if ( (*(_DWORD *)(v22 + 44) & 0x204000) == 2113536 )
      {
        v23 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
        }
        else
        {
          do
            v24 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
          while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
          __dmb(0xBu);
          if ( v24 )
            KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
        }
        *(_BYTE *)(v16 + 93) = v23;
        VfBugcheckTmpData = 201;
        dword_909044 = 15;
        dword_909048 = *(_DWORD *)(v16 + 96);
        dword_90904C = *(_DWORD *)(v16 + 100);
        dword_909050 = *(_DWORD *)(v21 - 12);
        VfBugCheckNoStackUsage();
      }
    }
  }
  v26 = VfBeforeCallDriver(a1, a2, v16);
  if ( (IopFunctionPointerMask & 2) != 0 )
  {
    v27 = IopPerfCallDriver(a1, a2);
  }
  else
  {
    v28 = (char)(*(_BYTE *)(a2 + 35) - 1);
    *(_BYTE *)(a2 + 35) = v28;
    if ( v28 <= 0 )
      KeBugCheckEx(53, a2, 0, 0, 0);
    v29 = (unsigned __int8 *)(*(_DWORD *)(a2 + 96) - 40);
    *(_DWORD *)(a2 + 96) = v29;
    v30 = *v29;
    *((_DWORD *)v29 + 6) = a1;
    if ( v30 == 22 && ((v31 = v29[1], v31 == 2) || v31 == 3) )
      v27 = IopPoHandleIrp(a2, v25, 22, v31);
    else
      v27 = (*(int (__fastcall **)(int, int))(*(_DWORD *)(a1 + 8) + 4 * v30 + 56))(a1, a2);
  }
  *(_DWORD *)(v16 + 108) = v27;
  VfAfterCallDriver(v16, v16 + 108, v26);
  v9 = *(_DWORD *)(v16 + 108);
  ExFreeToNPagedLookasideList((int)&ViIrpCallDriverDataList, (_DWORD *)v16);
  return v9;
}
