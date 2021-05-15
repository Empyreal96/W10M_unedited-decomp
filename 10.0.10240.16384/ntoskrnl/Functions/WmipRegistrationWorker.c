// WmipRegistrationWorker 
 
unsigned int __spoils<R0,R2,R3,R12> WmipRegistrationWorker()
{
  int v0; // r0
  _DWORD *v1; // r5
  __int64 v2; // r2
  int v3; // r4
  int v4; // r3
  unsigned int result; // r0
  unsigned int v6; // r2
  unsigned int v7; // r2

  do
  {
    IoControlPnpDeviceActionQueue(1);
    IoControlPnpDeviceActionQueue(0);
    v0 = KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    v1 = WmipRegWorkList;
    v2 = *(_QWORD *)WmipRegWorkList;
    if ( *((void ***)WmipRegWorkList + 1) != &WmipRegWorkList || *(void **)(v2 + 4) != WmipRegWorkList )
      sub_7EF134(v0);
    WmipRegWorkList = *(void **)WmipRegWorkList;
    *(_DWORD *)(v2 + 4) = &WmipRegWorkList;
    KeReleaseMutex((int)&WmipSMMutex);
    v3 = v1[3];
    if ( v3 )
    {
      v4 = v1[2];
      if ( v4 )
      {
        if ( v4 == 1 )
          WmipRegisterOrUpdateDS((_DWORD *)v1[3], 1);
      }
      else
      {
        WmipRegisterDS(v1[3]);
      }
      WmipUnreferenceRegEntry(v3);
    }
    result = ExFreePoolWithTag((unsigned int)v1);
    __dmb(0xBu);
    do
    {
      v6 = __ldrex((unsigned int *)&WmipRegWorkItemCount);
      v7 = v6 - 1;
    }
    while ( __strex(v7, (unsigned int *)&WmipRegWorkItemCount) );
    __dmb(0xBu);
  }
  while ( v7 );
  return result;
}
