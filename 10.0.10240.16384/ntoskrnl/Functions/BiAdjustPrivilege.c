// BiAdjustPrivilege 
 
int __fastcall BiAdjustPrivilege(int a1, int a2, char *a3)
{
  int v6; // r4
  bool v7; // zf
  char v8; // r3
  int v9; // [sp+20h] [bp-28h]
  char v10; // [sp+2Ch] [bp-1Ch]

  if ( !BiIsImpersonating() )
    JUMPOUT(0x81465E);
  if ( ZwOpenThreadTokenEx() < 0 )
    return sub_814648();
  v6 = ZwAdjustPrivilegesToken();
  if ( v6 == 262 )
    v6 = -1073741727;
  if ( v6 >= 0 )
  {
    if ( v9 )
      v7 = (v10 & 2) == 0;
    else
      v7 = a2 == 0;
    v8 = !v7;
    *a3 = v8;
  }
  return v6;
}
