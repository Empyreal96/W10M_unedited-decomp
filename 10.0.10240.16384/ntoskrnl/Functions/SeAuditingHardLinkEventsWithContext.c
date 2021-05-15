// SeAuditingHardLinkEventsWithContext 
 
int __fastcall SeAuditingHardLinkEventsWithContext(int a1, int a2)
{
  int result; // r0

  if ( (*(_WORD *)(a2 + 2) & 0x10) != 0 )
    result = sub_7EB24C();
  else
    result = 0;
  return result;
}
