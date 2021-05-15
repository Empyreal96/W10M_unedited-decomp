// ViFaultsIsCurrentAppTarget 
 
int ViFaultsIsCurrentAppTarget()
{
  int v0; // r7
  unsigned int v1; // r2
  BOOL v2; // r5
  int vars4; // [sp+14h] [bp+4h]

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
  __mrc(15, 0, 13, 0, 3);
  v2 = ViFaultApplicationsList == (_DWORD)&ViFaultApplicationsList;
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
  KfLowerIrql(v0);
  if ( !v2 )
  {
    if ( (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 188) & 0x10000) == 0 )
    {
      ++dword_908658;
      return 0;
    }
    ++dword_90865C;
  }
  return 1;
}
