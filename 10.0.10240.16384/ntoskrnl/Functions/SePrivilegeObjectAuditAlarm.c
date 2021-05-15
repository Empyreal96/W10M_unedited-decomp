// SePrivilegeObjectAuditAlarm 
 
int __fastcall SePrivilegeObjectAuditAlarm(int result, _DWORD *a2, int a3, int a4, unsigned __int8 a5, char a6)
{
  if ( a6 )
    result = SepAdtPrivilegeObjectAuditAlarm(&SeSubsystemName, 0, 0, result, *a2, a2[2], a2[3], a3, a4, a5);
  return result;
}
