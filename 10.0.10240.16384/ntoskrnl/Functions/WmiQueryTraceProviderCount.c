// WmiQueryTraceProviderCount 
 
int WmiQueryTraceProviderCount()
{
  int v0; // r5
  int v1; // r7
  unsigned int v3; // r2
  void **i; // r2
  unsigned int v5; // r3

  v0 = 0;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v1 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_519CD8();
  do
    v3 = __ldrex((unsigned int *)&WmipRegistrationSpinLock);
  while ( __strex(1u, (unsigned int *)&WmipRegistrationSpinLock) );
  __dmb(0xBu);
  if ( v3 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&WmipRegistrationSpinLock);
  for ( i = (void **)WmipInUseRegEntryHead; i != &WmipInUseRegEntryHead; i = (void **)*i )
  {
    v5 = (unsigned int)i[6];
    if ( (v5 & 0x40000000) != 0 && (v5 & 0x4000000) != 0 )
    {
      if ( i[2] )
        ++v0;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&WmipRegistrationSpinLock);
  }
  else
  {
    __dmb(0xBu);
    WmipRegistrationSpinLock = 0;
  }
  KfLowerIrql(v1);
  KeReleaseMutex((int)&WmipSMMutex);
  return v0;
}
