// SeAuditingFileEventsWithContextEx 
 
BOOL __fastcall SeAuditingFileEventsWithContextEx(int a1, int a2, int a3, _BYTE *a4)
{
  int v6; // r5

  if ( a1 )
    v6 = 3;
  else
    v6 = 48;
  if ( a4 )
    *a4 = SepAdtAuditThisEventWithContext(129, a1, a1 == 0, a3);
  return SepAdtAuditThisEventWithContext(116, a1, a1 == 0, a3) || SepAdtAuditThisEventByCategoryWithContext(3, v6, a3);
}
