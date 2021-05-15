// IoWMIWriteEvent 
 
int __fastcall IoWMIWriteEvent(int a1)
{
  int result; // r0
  int v3; // r3
  int v4; // r4
  int v5; // r7
  int v6; // r6
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r6
  unsigned int *v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r1
  unsigned int v14; // r1
  int v15; // r2
  int v16; // r0

  if ( !WmipServiceDeviceObject )
    return sub_51B934();
  v3 = *(_DWORD *)(a1 + 44);
  v4 = v3 & 0x20000;
  if ( (v3 & 0x20000) != 0 || (v3 & 0x40000) != 0 )
  {
    v15 = *(_DWORD *)a1;
    v16 = *(unsigned __int16 *)(a1 + 8);
    if ( *(_DWORD *)a1 < 0x30u )
      return -1073741789;
    if ( v4 )
    {
      if ( (unsigned int)v15 > 0xFFFF )
        return -2147483643;
    }
    else if ( v15 < 0 )
    {
      return -2147483643;
    }
    result = EtwTraceEvent(v16, 0, a1, 48, -1073086464, 0);
    if ( v4 )
      return result;
  }
  v5 = ExAllocatePoolWithTag(512, 16, 2003397975);
  if ( !v5 )
    return -1073741670;
  v6 = *(_DWORD *)(a1 + 4);
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
      KxWaitForSpinLockAndAcquire(&WmipRegistrationSpinLock);
  }
  v9 = WmipDoFindRegEntryByDevice(v6);
  v10 = v9;
  if ( v9 )
  {
    __dmb(0xBu);
    v11 = (unsigned int *)(v9 + 24);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + 1, v11) );
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
  KfLowerIrql(v7);
  *(_DWORD *)(a1 + 40) = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(v5 + 8) = v10;
  *(_DWORD *)(v5 + 12) = a1;
  ExInterlockedInsertTailList(&WmipNPEvent, v5, &WmipNPNotificationSpinlock);
  __dmb(0xBu);
  do
  {
    v13 = __ldrex((unsigned int *)&WmipEventWorkItems);
    v14 = v13 + 1;
  }
  while ( __strex(v14, (unsigned int *)&WmipEventWorkItems) );
  __dmb(0xBu);
  if ( v14 == 1 )
    ExQueueWorkItem(&WmipEventWorkQueueItem, 1);
  return 0;
}
