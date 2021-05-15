// ViFaultsInitializeTagsList 
 
int ViFaultsInitializeTagsList()
{
  int v0; // r5
  int v1; // r7
  unsigned int v2; // r2
  int vars4; // [sp+14h] [bp+4h]

  v0 = 0;
  v1 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ViFaultInjectionLock);
  }
  else
  {
    do
      v2 = __ldrex((unsigned int *)&ViFaultInjectionLock);
    while ( __strex(1u, (unsigned int *)&ViFaultInjectionLock) );
    __dmb(0xBu);
    if ( v2 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ViFaultInjectionLock);
  }
  __mrc(15, 0, 13, 0, 3);
  ViHaveFaultTags = 0;
  ViFaultTagsList = (int)&ViFaultTagsList;
  dword_61CECC = (int)&ViFaultTagsList;
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
  KfLowerIrql(v1);
  if ( VerifierFaultTagsBufferSize != -1 && (unsigned int)(VerifierFaultTagsBufferSize - 2) <= 0xFE )
    v0 = ViFaultsAddAllTags(VerifierFaultTagsBuffer, (unsigned int)(VerifierFaultTagsBufferSize - 2) >> 1);
  return v0;
}
