// SeCheckAuditPrivilege 
 
int __fastcall SeCheckAuditPrivilege(int *a1, char a2)
{
  int v3; // r0
  int v4; // r4
  int v5; // r0
  int v6; // r5
  _DWORD v8[2]; // [sp+8h] [bp-28h] BYREF
  int v9[8]; // [sp+10h] [bp-20h] BYREF

  v8[0] = 1;
  v8[1] = 1;
  v3 = a1[2];
  v9[0] = SeAuditPrivilege;
  v4 = a2;
  v9[1] = dword_9229DC;
  v9[2] = 0;
  v5 = SepPrivilegeCheck(v3, v9, 1, 1, a2);
  v6 = v5;
  if ( v4 )
    SePrivilegedServiceAuditAlarm(0, a1, (int)v8, v5);
  return v6;
}
