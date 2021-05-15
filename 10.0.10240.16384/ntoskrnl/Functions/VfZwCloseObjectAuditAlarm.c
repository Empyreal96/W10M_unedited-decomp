// VfZwCloseObjectAuditAlarm 
 
int __fastcall VfZwCloseObjectAuditAlarm(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckUnicodeString(a1);
  return pXdvZwCloseObjectAuditAlarm(a1, a2, a3);
}
