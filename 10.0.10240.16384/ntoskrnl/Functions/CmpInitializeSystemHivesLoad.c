// CmpInitializeSystemHivesLoad 
 
int CmpInitializeSystemHivesLoad()
{
  __int16 **v0; // r5
  unsigned int v1; // r7
  __int16 **v2; // r4
  int v3; // r2
  int v4; // r2
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r0
  __int16 *v9; // r8
  int v10; // r2
  int result; // r0
  int v12; // r2
  int v13; // r3
  unsigned int i; // r4
  BOOL v15; // r2
  int v16; // r0
  __int16 **v17; // r1
  int v18; // r0
  unsigned __int16 v19[2]; // [sp+10h] [bp-B0h] BYREF
  char *v20; // [sp+14h] [bp-ACh]
  int v21; // [sp+18h] [bp-A8h] BYREF
  char v22; // [sp+20h] [bp-A0h] BYREF

  CmpNoWrite = 0;
  if ( (MEMORY[0xFFFF92D0] & 0x10000) != 0
    && CmpSystemCacheBackedHivesDesired
    && CmpSendBootDeviceUsageNotification(0) >= 0 )
  {
    CmpBootDeviceUsageNotificationSent = 1;
    CmpSystemCacheBackedHivesAllowed = 1;
  }
  KeInitializeEvent((int)&CmpLoadWorkerEvent, 1, 0);
  KeInitializeEvent((int)&CmpLoadWorkerDebugEvent, 1, 0);
  v0 = CmpMachineHiveList;
  v1 = 0;
  v2 = CmpMachineHiveList;
  do
  {
    KeInitializeEvent((int)(v2 + 10), 0, 0);
    KeInitializeEvent((int)(v2 + 14), 1, 0);
    KeInitializeEvent((int)(v2 + 18), 0, 0);
    v19[0] = 0;
    v19[1] = 128;
    v20 = &v22;
    RtlAppendUnicodeToString(v19, (int)L"\\REGISTRY\\", v3, 128);
    RtlAppendUnicodeToString(v19, (int)v2[1], v4, v5);
    v7 = (int)v2[5];
    if ( (v7 & 1) == 0 )
      RtlAppendUnicodeToString(v19, (int)*v2, v6, v7);
    v8 = ExAllocatePoolWithTag(1, 128, 842419523);
    v9 = (__int16 *)v8;
    if ( !v8 )
      KeBugCheckEx(116, 2, 5, v1, 0);
    v2[23] = (__int16 *)v8;
    *((_WORD *)v2 + 45) = 128;
    *((_WORD *)v2 + 44) = 0;
    if ( CmpQueryHiveRedirectionFileList((int)v19, (unsigned __int16 *)v2 + 44) )
      return sub_810030();
    *((_WORD *)v2 + 44) = 0;
    *((_WORD *)v2 + 45) = 128;
    v2[23] = v9;
    RtlAppendUnicodeToString((unsigned __int16 *)v2 + 44, (int)L"\\SystemRoot\\System32\\Config\\", v10, 128);
    RtlAppendUnicodeToString((unsigned __int16 *)v2 + 44, (int)*v2, v12, v13);
    ++v1;
    v2 += 24;
  }
  while ( v1 < 6 );
  if ( CmpShareSystemHives )
  {
    v17 = CmpMachineHiveList;
    v18 = 6;
    do
    {
      if ( *v17 )
        v17[4] = (__int16 *)((unsigned int)v17[4] & 0xFFFDFFFF | 0x8001);
      v17 += 24;
      --v18;
    }
    while ( v18 );
  }
  CmpSpecialBootCondition = 1;
  for ( i = 0; i < 6; ++i )
  {
    v15 = ((unsigned int)v0[4] & 1) != 0 || i == 3 || i == 2 || CmpInitRmLogOnLoad;
    if ( !v0[2] )
      v0[2] = *v0;
    if ( v15 )
      KeSetEvent((int)(v0 + 10), 0, 0);
    v16 = PsCreateSystemThread((int)&v21, 0x1FFFFF, 0);
    if ( v16 < 0 )
      KeBugCheckEx(116, 2, 3, i, v16);
    result = ZwClose();
    v0 += 24;
  }
  return result;
}
