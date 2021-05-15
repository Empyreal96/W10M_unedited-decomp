// WmipAllocRegEntry 
 
int __fastcall WmipAllocRegEntry(int a1, int a2)
{
  _BYTE *v4; // r0
  _BYTE *v5; // r5
  int v6; // r7
  unsigned int v8; // r2
  void ***v9; // r1

  v4 = (_BYTE *)ExAllocateFromNPagedLookasideList((int)&WmipRegLookaside);
  v5 = v4;
  if ( v4 )
  {
    memset(v4, 0, 32);
    *((_DWORD *)v5 + 6) = a2 & 0xFF000000 | 1;
    *((_DWORD *)v5 + 2) = a1;
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_50B8FC();
    do
      v8 = __ldrex((unsigned int *)&WmipRegistrationSpinLock);
    while ( __strex(1u, (unsigned int *)&WmipRegistrationSpinLock) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&WmipRegistrationSpinLock);
    ++WmipInUseRegEntryCount;
    v9 = (void ***)off_6174C8[0];
    *(_DWORD *)v5 = &WmipInUseRegEntryHead;
    *((_DWORD *)v5 + 1) = v9;
    if ( *v9 != &WmipInUseRegEntryHead )
      __fastfail(3u);
    *v9 = (void **)v5;
    off_6174C8[0] = (void **)v5;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&WmipRegistrationSpinLock);
    }
    else
    {
      __dmb(0xBu);
      WmipRegistrationSpinLock = 0;
    }
    KfLowerIrql(v6);
    KeReleaseMutex((int)&WmipSMMutex);
  }
  return (int)v5;
}
