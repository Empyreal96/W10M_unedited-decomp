// SeCloseObjectAuditAlarm 
 
int __fastcall SeCloseObjectAuditAlarm(int result, int a2, int a3, int a4)
{
  int v5; // r5
  int v6[6]; // [sp+8h] [bp-18h] BYREF

  v5 = result;
  if ( a3 )
  {
    SeCaptureSubjectContext(v6, a2, a3, a4);
    SepAdtCloseObjectAuditAlarm((int)&SeSubsystemName, a2, v6, v5, 1u);
    result = SeReleaseSubjectContext((int)v6);
  }
  return result;
}
