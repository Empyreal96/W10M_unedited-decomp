// VfBeforeCallDriver 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall VfBeforeCallDriver(int a1, int a2, int a3)
{
  int v4; // r4 OVERLAPPED
  int v7; // r1
  int v8; // r4
  char v9; // r7
  unsigned int v10; // r1
  int v11; // r3
  int v12; // r0
  int v13; // r2
  int v14; // r3

  v4 = a2;
  if ( *(_BYTE *)(a2 + 32) != 1 && (MmVerifierData & 0x100) != 0 && !*(_DWORD *)(a2 + 4) )
  {
    if ( (*(_DWORD *)(a2 + 8) & 0x10) != 0 )
      v7 = *(_DWORD *)(a2 + 12);
    else
      v7 = *(_DWORD *)(a2 + 60);
    ViIrpCheckKernelAddressForIrp(a2, v7);
  }
  if ( !a3 )
    return VfDeadlockBeforeCallDriver(v4);
  if ( !KeAreInterruptsEnabled() )
  {
    v9 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
    }
    else
    {
      do
        v10 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
      while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
      __dmb(0xBu);
      if ( v10 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
    }
    VfBugcheckTmpData = 196;
    v11 = 192;
    *(_QWORD *)&dword_909044 = *(_QWORD *)(&v4 - 1);
    dword_90904C = 0;
    dword_909050 = 0;
    *(_BYTE *)(a3 + 93) = v9;
    VfBugCheckNoStackUsage();
  }
  v12 = VfGetPristineDispatchRoutine(*(_DWORD *)(a1 + 8), *(unsigned __int8 *)(*(_DWORD *)(v4 + 96) - 40));
  *(_DWORD *)(a3 + 24) = v12;
  *(_BYTE *)(a3 + 92) = KeGetCurrentIrql(v12);
  *(_DWORD *)(a3 + 112) = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134);
  if ( *(char *)(v4 + 35) == *(char *)(v4 + 34) + 1 )
  {
    v13 = *(_DWORD *)(v4 + 44);
    if ( v13 )
    {
      if ( !*(_BYTE *)(v4 + 32) && *(_DWORD *)(v13 + 4) )
        *(_DWORD *)(a3 + 88) |= 2u;
    }
  }
  v8 = VfDeadlockBeforeCallDriver(v4);
  v14 = VfIoDisabled;
  __dmb(0xBu);
  if ( !v14 )
  {
    *(_DWORD *)(a3 + 88) |= 1u;
    IovpCallDriver1((int *)a3);
  }
  return v8;
}
