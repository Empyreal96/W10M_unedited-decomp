// VfAfterCallDriver 
 
_DWORD *__fastcall VfAfterCallDriver(int a1, int *a2, int a3)
{
  _DWORD *result; // r0
  int v6; // r2
  char v7; // r6
  unsigned int v8; // r1
  int v9; // r3
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r1
  int v13; // r3
  char v14; // r6
  unsigned int v15; // r1
  int v16; // r3

  if ( !a1 )
    return (_DWORD *)VfDeadlockAfterCallDriver(a3);
  if ( !KeAreInterruptsEnabled() )
  {
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
    }
    else
    {
      do
        v8 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
      while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
    }
    VfBugcheckTmpData = 196;
    dword_909044 = 193;
    v9 = *(_DWORD *)(a1 + 24);
    *(_BYTE *)(a1 + 93) = v7;
    dword_909048 = v9;
    dword_90904C = 0;
    dword_909050 = 0;
    VfBugCheckNoStackUsage();
  }
  v10 = VfDeadlockAfterCallDriver(v6);
  result = (_DWORD *)KeGetCurrentIrql(v10);
  if ( (_DWORD *)*(unsigned __int8 *)(a1 + 92) != result )
  {
    v11 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
    }
    else
    {
      do
        v12 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
      while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
      __dmb(0xBu);
      if ( v12 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
    }
    VfBugcheckTmpData = 201;
    dword_909044 = 18;
    v13 = *(_DWORD *)(a1 + 24);
    *(_BYTE *)(a1 + 93) = v11;
    dword_909048 = v13;
    dword_90904C = *(unsigned __int8 *)(a1 + 92);
    dword_909050 = v11;
    VfBugCheckNoStackUsage();
  }
  if ( *(_DWORD *)(a1 + 112) != *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
  {
    v14 = KfRaiseIrql(2);
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
    VfBugcheckTmpData = 196;
    dword_909044 = 197;
    v16 = *(_DWORD *)(a1 + 24);
    *(_BYTE *)(a1 + 93) = v14;
    dword_909048 = v16;
    dword_90904C = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134);
    dword_909050 = *(_DWORD *)(a1 + 112);
    VfBugCheckNoStackUsage();
  }
  if ( (MmVerifierData & 0x10) != 0 && (*(_DWORD *)(a1 + 88) & 2) != 0 && *a2 == 259 )
    return (_DWORD *)VfErrorReport1(775, *(_DWORD *)(a1 + 104), *(_DWORD *)(a1 + 100));
  if ( (*(_DWORD *)(a1 + 88) & 1) != 0 )
    result = IovpCallDriver2((_DWORD *)a1, a2);
  return result;
}
