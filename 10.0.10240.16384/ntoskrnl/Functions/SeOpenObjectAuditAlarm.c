// SeOpenObjectAuditAlarm 
 
int __fastcall SeOpenObjectAuditAlarm(int result, int a2, int a3, int a4, int a5, unsigned __int8 a6, int a7, char a8)
{
  if ( a8 )
    result = SeOpenObjectAuditAlarmWithTransaction(result, a2, a3, a4, a5, a6);
  return result;
}
