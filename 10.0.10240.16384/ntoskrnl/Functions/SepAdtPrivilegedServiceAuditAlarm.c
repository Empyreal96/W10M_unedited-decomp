// SepAdtPrivilegedServiceAuditAlarm 
 
int __fastcall SepAdtPrivilegedServiceAuditAlarm(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int8 a7)
{
  int result; // r0
  char v8[708]; // [sp+Ch] [bp-2C4h] BYREF

  result = SepAdtAuditPrivilegeUseWithContext(a6, a7, a7 == 0, a1, v8);
  if ( result )
    result = sub_7DC260();
  return result;
}
