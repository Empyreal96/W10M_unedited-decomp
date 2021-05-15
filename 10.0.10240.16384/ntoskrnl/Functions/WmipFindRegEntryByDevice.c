// WmipFindRegEntryByDevice 
 
int __fastcall WmipFindRegEntryByDevice(int a1)
{
  int v2; // r7
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r5
  unsigned int *v7; // r2
  unsigned int v8; // r1

  KeWaitForSingleObject(&WmipSMMutex, 0, 0);
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51B9B8();
  do
    v4 = __ldrex((unsigned int *)&WmipRegistrationSpinLock);
  while ( __strex(1u, (unsigned int *)&WmipRegistrationSpinLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire(&WmipRegistrationSpinLock);
  v5 = WmipDoFindRegEntryByDevice(a1);
  v6 = v5;
  if ( v5 )
  {
    __dmb(0xBu);
    v7 = (unsigned int *)(v5 + 24);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 + 1, v7) );
    __dmb(0xBu);
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
  KfLowerIrql(v2);
  KeReleaseMutex(&WmipSMMutex, 0);
  return v6;
}
