// VfFaultsInjectPoolAllocationFailure 
 
int __fastcall VfFaultsInjectPoolAllocationFailure(int a1)
{
  int v2; // r5
  int v3; // r7
  unsigned int v4; // r2
  int v5; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  if ( (MmVerifierData & 4) == 0 )
    return 0;
  if ( !ViFaultsInitialized )
  {
    ++dword_90864C;
    return 0;
  }
  if ( ViFaultsDisabled )
  {
    ++dword_908674;
    return 0;
  }
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ViFaultInjectionLock);
  }
  else
  {
    do
      v4 = __ldrex((unsigned int *)&ViFaultInjectionLock);
    while ( __strex(1u, (unsigned int *)&ViFaultInjectionLock) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ViFaultInjectionLock);
  }
  ViFaultLockOwner = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = ViFaultsIsTagTarget(a1);
  ViFaultLockOwner = 0;
  v2 = v5;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ViFaultInjectionLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    ViFaultInjectionLock = 0;
  }
  KfLowerIrql(v3);
  if ( v2 )
    v2 = VfFaultsInjectResourceFailure(1);
  return v2;
}
