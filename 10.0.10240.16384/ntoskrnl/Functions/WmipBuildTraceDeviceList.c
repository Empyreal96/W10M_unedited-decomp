// WmipBuildTraceDeviceList 
 
int __fastcall WmipBuildTraceDeviceList(int a1, int *a2, unsigned int *a3)
{
  int v3; // r6
  int v4; // r9
  unsigned int v5; // r2
  unsigned int v6; // r7
  int v7; // r5
  int v8; // r0
  unsigned int v9; // r5
  void ***v10; // r8
  void **v11; // r0
  int v12; // r2
  int v13; // r9
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int v18; // [sp+Ch] [bp-2Ch]
  int vars4; // [sp+3Ch] [bp+4h]

  v3 = 0;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v4 = KfRaiseIrql(2);
  v18 = v4;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&WmipRegistrationSpinLock);
  }
  else
  {
    do
      v5 = __ldrex((unsigned int *)&WmipRegistrationSpinLock);
    while ( __strex(1u, (unsigned int *)&WmipRegistrationSpinLock) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&WmipRegistrationSpinLock);
  }
  v6 = WmipInUseRegEntryCount;
  if ( !WmipInUseRegEntryCount )
  {
    v7 = -1073741632;
LABEL_10:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&WmipRegistrationSpinLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      WmipRegistrationSpinLock = 0;
    }
    KfLowerIrql(v4);
    KeReleaseMutex((int)&WmipSMMutex);
    goto LABEL_29;
  }
  v8 = ExAllocatePoolWithTag(512, 8 * WmipInUseRegEntryCount);
  v3 = v8;
  if ( !v8 )
  {
    v7 = -1073741670;
    goto LABEL_10;
  }
  v9 = 0;
  v10 = (void ***)v8;
  v11 = (void **)WmipInUseRegEntryHead;
  if ( WmipInUseRegEntryHead != &WmipInUseRegEntryHead )
  {
    do
    {
      v12 = (int)v11[6];
      v13 = (v12 >> 4) & 0xF00000;
      if ( (v12 & 0x40000000) != 0 && (v13 & a1) != 0 && v11[2] && v9 < v6 )
      {
        __dmb(0xBu);
        v14 = (unsigned int *)(v11 + 6);
        do
          v15 = __ldrex(v14);
        while ( __strex(v15 + 1, v14) );
        __dmb(0xBu);
        *v10 = v11;
        v10[1] = (void **)v13;
        ++v9;
        v10 += 2;
      }
      v11 = (void **)*v11;
    }
    while ( v11 != &WmipInUseRegEntryHead );
    v4 = v18;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&WmipRegistrationSpinLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    WmipRegistrationSpinLock = 0;
  }
  KfLowerIrql(v4);
  KeReleaseMutex((int)&WmipSMMutex);
  if ( v9 )
  {
    *a2 = v3;
    *a3 = v9;
    return 0;
  }
  v7 = -1073741632;
LABEL_29:
  if ( v3 )
    WmipFreeTraceDeviceList(v3, 0);
  return v7;
}
