// SepAdtRegNotificationCallback 
 
int SepAdtRegNotificationCallback()
{
  int v0; // r0
  int v1; // r1
  int v2; // r2
  int v3; // r3

  v0 = SepAdtInitializeCrashOnFail();
  SepAdtInitializePrivilegeAuditing(v0, v1, v2, v3);
  SepAdtInitializeBounds();
  return NtNotifyChangeKey(
           SepAdtRegNotifyHandle,
           0,
           (int)&SepAdtLsaRegWatchWorkItem,
           1,
           (int)&SepAdtIoStatusBlock,
           5,
           0,
           0,
           0,
           1u);
}
