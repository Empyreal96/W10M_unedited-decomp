// SepAdtPrivilegeObjectAuditAlarm 
 
int __fastcall SepAdtPrivilegeObjectAuditAlarm(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, unsigned __int8 a10)
{
  int result; // r0
  char v11[4]; // [sp+8h] [bp-2C8h] BYREF
  int v12; // [sp+Ch] [bp-2C4h]
  int v13; // [sp+14h] [bp-2BCh]

  v13 = a4;
  v12 = 0;
  if ( SepAdtAuditPrivilegeUseWithContext(a9, a10, a10 == 0, 0, v11) )
    result = sub_7DC388();
  else
    result = 0;
  return result;
}
