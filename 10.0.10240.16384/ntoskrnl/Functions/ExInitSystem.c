// ExInitSystem 
 
int ExInitSystem()
{
  int result; // r0
  int *v1; // r0

  if ( InitializationPhase )
  {
    if ( InitializationPhase != 1 )
      sub_96C1F0();
    result = ExpInitSystemPhase1();
  }
  else
  {
    v1 = sub_95935C(
           (int)L"\\Registry\\Machine\\System\\Setup",
           9224560,
           9224668,
           (int)L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ProductOptions",
           (int)L"ProductType",
           (int)L"LanmanNT",
           (int)L"ServerNT",
           (int)L"WinNT",
           (int)L"ProductSuite",
           (int)L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\LicenseInfoSuites",
           (int)L"ConcurrentLimit",
           (int)L"Small Business",
           (int)L"Enterprise",
           (int)L"CommunicationServer",
           (int)L"BackOffice",
           (int)L"Small Business(Restricted)",
           (int)L"Terminal Server",
           (int)L"EmbeddedNT",
           (int)L"DataCenter",
           (int)L"Personal",
           (int)L"Blade",
           (int)L"Embedded(Restricted)",
           (int)L"Security Appliance",
           (int)L"Storage Server",
           (int)L"Compute Server",
           (int)L"WH Server",
           (int)L"SystemSetupInProgress",
           (int)L"PhoneNT");
    result = ExpInitSystemPhase0(v1);
  }
  return result;
}
