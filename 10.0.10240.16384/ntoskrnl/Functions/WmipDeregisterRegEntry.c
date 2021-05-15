// WmipDeregisterRegEntry 
 
int __fastcall WmipDeregisterRegEntry(_DWORD *a1)
{
  int v2; // r8
  unsigned int v4; // r2
  unsigned int *v5; // r2
  unsigned int v6; // r6
  int v7; // r8
  unsigned int v8; // r2
  int v9; // r1
  _DWORD *v10; // r2
  int v11; // r0
  char v12[4]; // [sp+8h] [bp-28h] BYREF
  int v13; // [sp+Ch] [bp-24h]
  int var20[9]; // [sp+10h] [bp-20h] BYREF

  v12[0] = 1;
  v12[1] = 0;
  v12[2] = 4;
  v13 = 0;
  var20[1] = (int)var20;
  var20[0] = (int)var20;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5544CC();
  do
    v4 = __ldrex((unsigned int *)&WmipRegistrationSpinLock);
  while ( __strex(1u, (unsigned int *)&WmipRegistrationSpinLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&WmipRegistrationSpinLock);
  a1[5] = v12;
  __dmb(0xBu);
  v5 = a1 + 6;
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0xA0000000, v5) );
  __dmb(0xBu);
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
  KeReleaseMutex((int)&WmipSMMutex);
  WmipUnreferenceRegEntry((int)a1);
  KeWaitForSingleObject((unsigned int)v12, 0, 0, 0, 0);
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(&WmipRegistrationSpinLock);
  }
  else
  {
    do
      v8 = __ldrex((unsigned int *)&WmipRegistrationSpinLock);
    while ( __strex(1u, (unsigned int *)&WmipRegistrationSpinLock) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&WmipRegistrationSpinLock);
  }
  v9 = *a1;
  --WmipInUseRegEntryCount;
  v10 = (_DWORD *)a1[1];
  if ( *(_DWORD **)(v9 + 4) != a1 || (_DWORD *)*v10 != a1 )
    __fastfail(3u);
  *v10 = v9;
  *(_DWORD *)(v9 + 4) = v10;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&WmipRegistrationSpinLock);
  }
  else
  {
    __dmb(0xBu);
    WmipRegistrationSpinLock = 0;
  }
  KfLowerIrql(v7);
  KeReleaseMutex((int)&WmipSMMutex);
  if ( (v6 & 0x10000000) == 0 )
    ObfDereferenceObjectWithTag(a1[2]);
  v11 = a1[3];
  if ( v11 )
    ObfDereferenceObjectWithTag(v11);
  WmipRemoveDS(a1);
  return ExFreeToNPagedLookasideList((int)&WmipRegLookaside, a1);
}
