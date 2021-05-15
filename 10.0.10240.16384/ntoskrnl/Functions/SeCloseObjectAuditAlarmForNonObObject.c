// SeCloseObjectAuditAlarmForNonObObject 
 
int __fastcall SeCloseObjectAuditAlarmForNonObObject(int result, int a2, int *a3, int a4)
{
  if ( a4 )
    result = SepAdtCloseObjectAuditAlarm(result, a2, a3, 0, 1u);
  return result;
}
