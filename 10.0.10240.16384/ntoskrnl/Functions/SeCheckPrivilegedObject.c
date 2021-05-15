// SeCheckPrivilegedObject 
 
int __fastcall SeCheckPrivilegedObject(int a1, int a2, int a3, int a4, char a5)
{
  int v7; // r4
  int v9[4]; // [sp+8h] [bp-38h] BYREF
  int var28[16]; // [sp+18h] [bp-28h] BYREF

  var28[14] = a3;
  var28[15] = a4;
  var28[0] = 1;
  var28[1] = 1;
  var28[12] = a1;
  var28[13] = a2;
  var28[2] = a1;
  var28[3] = a2;
  var28[4] = 0;
  SeCaptureSubjectContext(v9, a2, a3, 0);
  v7 = SePrivilegeCheck(var28, v9, a5);
  if ( a5 )
    SePrivilegeObjectAuditAlarm(a3, v9, a4, (int)var28, v7, a5);
  SeReleaseSubjectContext((int)v9);
  return v7;
}
