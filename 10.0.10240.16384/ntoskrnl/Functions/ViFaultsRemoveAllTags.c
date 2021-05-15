// ViFaultsRemoveAllTags 
 
__int64 ViFaultsRemoveAllTags()
{
  int v0; // r7
  unsigned int v1; // r2
  unsigned int v2; // r3
  int *v3; // r0
  int *v4; // r4
  int vars4; // [sp+1Ch] [bp+4h]

  v0 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ViFaultInjectionLock);
  }
  else
  {
    do
      v1 = __ldrex((unsigned int *)&ViFaultInjectionLock);
    while ( __strex(1u, (unsigned int *)&ViFaultInjectionLock) );
    __dmb(0xBu);
    if ( v1 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ViFaultInjectionLock);
  }
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = (int *)ViFaultTagsList;
  ViFaultLockOwner = v2;
  if ( (int *)ViFaultTagsList != &ViFaultTagsList )
  {
    do
    {
      v4 = (int *)*v3;
      ExFreePoolWithTag((unsigned int)v3);
      v3 = v4;
    }
    while ( v4 != &ViFaultTagsList );
  }
  ViFaultTagsList = (int)&ViFaultTagsList;
  dword_61CECC = (int)&ViFaultTagsList;
  ViHaveFaultTags = 0;
  ViFaultLockOwner = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ViFaultInjectionLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    ViFaultInjectionLock = 0;
  }
  return KfLowerIrql(v0);
}
