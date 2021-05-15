// AdtpInitializeAuditingCommon 
 
int AdtpInitializeAuditingCommon()
{
  int v0; // r4

  AdtpNullSid = 1;
  byte_9278D9 = 1;
  AdtpRegisteredWithEtw = 1;
  v0 = AdtpInitializeDriveLetters();
  if ( v0 >= 0 )
  {
    v0 = AdtpObjsInitialize();
    if ( v0 >= 0 )
      AdtpDbInitializePrivilegeObject();
  }
  return v0;
}
