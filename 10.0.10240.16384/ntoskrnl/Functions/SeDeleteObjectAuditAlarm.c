// SeDeleteObjectAuditAlarm 
 
int __fastcall SeDeleteObjectAuditAlarm(int a1, int a2)
{
  return SeDeleteObjectAuditAlarmWithTransaction(a1, a2, 0);
}
