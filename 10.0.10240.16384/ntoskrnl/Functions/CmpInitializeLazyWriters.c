// CmpInitializeLazyWriters 
 
int CmpInitializeLazyWriters()
{
  _DWORD *v0; // r4
  unsigned int v1; // r5
  int v3[6]; // [sp+10h] [bp-18h] BYREF

  v0 = &CmpLazyWriterData;
  v1 = 0;
  dword_60E2A0 = CmpLazyFlushIntervalInSeconds;
  dword_60E320 = CmpLazyReconcileIntervalInSeconds;
  do
  {
    KeInitializeTimerEx(v0, 0);
    KeInitializeEvent((int)(v0 + 20), 1, 0);
    KeInitializeDpc((int)(v0 + 12), (int)CmpLazyFlushDpcRoutine, (int)v0);
    v0[24] = 0;
    if ( PsCreateSystemThread((int)v3, 0x1FFFFF, 0) < 0 )
      sub_7F2114();
    NtClose();
    ++v1;
    v0 += 32;
  }
  while ( v1 < 2 );
  CmpUserPresent = 1;
  return PoRegisterPowerSettingCallback(0, &GUID_GLOBAL_USER_PRESENCE, (int)CmpUserPresenceCallback, 0, 0);
}
