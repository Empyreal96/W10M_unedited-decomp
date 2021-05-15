// VfTriageSystem 
 
int VfTriageSystem()
{
  int v0; // r0
  int v1; // r3
  const char *v3; // r2

  v0 = DbgPrintEx(93, 3, (int)"CRASH TRIAGE: verifier triage global/registry settings %X \n", ViVerifyTriage);
  v1 = MmVerifyDriverLevel;
  if ( MmVerifyDriverLevel != -1 || (v1 = ViVerifyAllDrivers) != 0 )
  {
    v3 = "CRASH TRIAGE: driver verifier settings present.\n";
  }
  else
  {
    v1 = ViVerifyTriage;
    if ( ViVerifyTriage != -1 )
      return sub_96F0A0(v0);
    v3 = "CRASH TRIAGE: triage skipped because it is not enabled by default.\n";
  }
  DbgPrintEx(93, 3, (int)v3, v1);
  return 0;
}
