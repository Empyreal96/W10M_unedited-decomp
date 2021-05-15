// sub_7E5A94 
 
void __fastcall sub_7E5A94(int a1, int a2, int a3, int a4, int a5, int a6, __int64 a7, int a8)
{
  _DWORD *v8; // r5
  int v9; // r6
  char v10; // r8

  a5 = 1;
  a6 = 1;
  a7 = SeSecurityPrivilege;
  a8 = 0;
  if ( !SePrivilegeCheck(&a5, v8 + 7, v10) )
  {
    SePrivilegedServiceAuditAlarm(0, v8 + 7, (int)&a5, 0);
    JUMPOUT(0x6EFFA6);
  }
  v8[4] &= ~v9;
  v8[5] |= v9;
  SeAppendPrivileges((int)v8, &a5);
  JUMPOUT(0x6EFF68);
}
