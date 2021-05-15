// SeDeleteObjectAuditAlarmWithTransaction 
 
int __fastcall SeDeleteObjectAuditAlarmWithTransaction(int a1, int a2, _DWORD *a3, int a4)
{
  int v8[8]; // [sp+8h] [bp-20h] BYREF

  SeCaptureSubjectContext(v8, a2, (int)a3, a4);
  SepAdtDeleteObjectAuditAlarm((int)&SeSubsystemName, a2, v8, a1, a3, 1u);
  return SeReleaseSubjectContext((int)v8);
}
