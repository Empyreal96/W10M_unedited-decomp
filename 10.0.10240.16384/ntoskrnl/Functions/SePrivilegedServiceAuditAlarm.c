// SePrivilegedServiceAuditAlarm 
 
int __fastcall SePrivilegedServiceAuditAlarm(int a1, int *a2, int a3, int a4)
{
  int v5; // r5
  int v9; // r1
  unsigned __int16 *v10; // r7
  int result; // r0
  int v12; // r8

  v5 = *a2;
  if ( *a2 )
    v9 = *a2;
  else
    v9 = a2[2];
  v10 = **(unsigned __int16 ***)(v9 + 148);
  result = RtlEqualSid((unsigned __int16 *)SeLocalSystemSid, v10);
  if ( !result )
  {
    if ( (v12 = SeExports, !RtlEqualSid(*(unsigned __int16 **)(SeExports + 300), v10))
      && !RtlEqualSid(*(unsigned __int16 **)(v12 + 296), v10)
      || (result = SepFilterPrivilegeAudits(1, a3)) != 0 )
    {
      result = SepAdtPrivilegedServiceAuditAlarm(a2, &SeSubsystemName, a1, v5, a2[2], a3, a4);
    }
  }
  return result;
}
