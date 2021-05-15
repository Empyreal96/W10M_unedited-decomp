// SeRmInitPhase1 
 
int SeRmInitPhase1()
{
  int v0; // r0
  int v1; // r0
  __int64 v2; // r2
  int v3; // r0
  int v4; // r1
  char v6[8]; // [sp+10h] [bp-40h] BYREF
  int v7[14]; // [sp+18h] [bp-38h] BYREF

  memset(v7, 0, 24);
  LOWORD(v7[0]) = 1;
  HIWORD(v7[0]) |= 1u;
  v7[1] = (int)SepRmServerSiloCreateNotify;
  v7[2] = (int)SepRmServerSiloTerminateNotify;
  if ( PsRegisterMonitorServerSilo(0, L"NTOS_SE_RM", (unsigned __int16 *)v7, (unsigned int *)&SeRmSiloMonitor) < 0 )
    return 0;
  if ( PsStartMonitorServerSilo((_DWORD *)SeRmSiloMonitor) < 0 )
  {
    PsUnregisterMonitorServerSilo(SeRmSiloMonitor);
    return 0;
  }
  RtlInitUnicodeString((unsigned int)v6, L"\\SeRmCommandPort");
  v7[6] = 24;
  v7[7] = 0;
  v7[9] = 0;
  v7[8] = (int)v6;
  v7[10] = 0;
  v7[11] = 0;
  v0 = ZwCreatePort();
  if ( v0 < 0 )
    return 0;
  v1 = SepAdtInitializeAuditingOptions(v0);
  if ( SepInitializeSingletonAttributesStructures(v1) < 0 )
    return 0;
  LODWORD(v2) = 0;
  TraceLoggingRegisterEx((int)&dword_920188, v2);
  if ( PsCreateSystemThread((int)&dword_922BDC, 56, 0) < 0 )
    return 0;
  v3 = InitializeSidLookupTable();
  AuthzBasepInitializeSystemSecurityAttributes(v3, v4);
  ZwClose();
  dword_922BDC = 0;
  return 1;
}
