// SepAdtAuditPrivilegeUseWithContext 
 
int __fastcall SepAdtAuditPrivilegeUseWithContext(int a1, int a2, int a3, int a4)
{
  int v7; // r9
  int v8; // r0
  int result; // r0

  v7 = SepAdtAuditThisEventWithContext(130, a2, a3, a4);
  v8 = SepAdtAuditThisEventWithContext(131, a2, a3, a4);
  if ( v7 || v8 )
    result = sub_7DC4F8(v8);
  else
    result = 0;
  return result;
}
