// SeReportSecurityEvent 
 
int __fastcall SeReportSecurityEvent(int a1, unsigned __int16 *a2, int a3, _DWORD *a4)
{
  if ( a4 )
    *a4 = 3;
  return SeReportSecurityEventWithSubCategory(a1, a2, a3, (int)a4, 122);
}
