// SepAdtInitializeAuditingOptions 
 
int SepAdtInitializeAuditingOptions()
{
  int v0; // r4
  int v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v6; // [sp+0h] [bp-8h] BYREF

  v6 = 0;
  v0 = AdtpInitializeAuditingCommon();
  if ( v0 >= 0 )
  {
    v0 = SepAdtOpenEtwReadyEvent((unsigned int)&v6);
    if ( v0 >= 0 )
    {
      v0 = NtSetEvent(v6, 0);
      NtClose();
      if ( v0 >= 0 )
      {
        v0 = SepAdtOpenRegAndSetupNotification();
        if ( v0 >= 0 )
        {
          v1 = SepAdtInitializeCrashOnFail();
          SepAdtInitializePrivilegeAuditing(v1, v2, v3, v4);
          SepAdtInitializeBounds();
        }
      }
    }
  }
  return v0;
}
