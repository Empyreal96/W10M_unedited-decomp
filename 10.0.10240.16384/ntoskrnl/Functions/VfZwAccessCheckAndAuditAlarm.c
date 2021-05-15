// VfZwAccessCheckAndAuditAlarm 
 
int __fastcall VfZwAccessCheckAndAuditAlarm(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned __int8 a8, int a9, int a10, int a11)
{
  if ( ViZwShouldCheck() )
  {
    ViZwCheckUnicodeString(a1);
    ViZwCheckUnicodeString(a3);
    ViZwCheckUnicodeString(a4);
    ViZwCheckVirtualAddress(a5);
    ViZwCheckVirtualAddress(a7);
    ViZwCheckVirtualAddress(a9);
    ViZwCheckVirtualAddress(a11);
  }
  return pXdvZwAccessCheckAndAuditAlarm(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}
