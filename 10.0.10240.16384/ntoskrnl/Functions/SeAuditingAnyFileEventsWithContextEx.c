// SeAuditingAnyFileEventsWithContextEx 
 
BOOL __fastcall SeAuditingAnyFileEventsWithContextEx(int a1, int a2, _BYTE *a3)
{
  if ( a3 )
    *a3 = SepAdtAuditThisEventWithContext(129, 1, 1, a2);
  return SepAdtAuditThisEventWithContext(116, 1, 1, a2) || SepAdtAuditThisEventByCategoryWithContext(3, 51, a2);
}
