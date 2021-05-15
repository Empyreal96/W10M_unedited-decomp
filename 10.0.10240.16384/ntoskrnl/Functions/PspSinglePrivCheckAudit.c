// PspSinglePrivCheckAudit 
 
int __fastcall PspSinglePrivCheckAudit(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(_BYTE *)(a3 + 36) )
  {
    if ( a2 == 1 )
      SePrivilegedServiceAuditAlarm(&PspWorkingSetAdjustService, a3, a3 + 16, *(unsigned __int8 *)(a3 + 37));
    result = SeReleaseSubjectContext(a3);
  }
  return result;
}
