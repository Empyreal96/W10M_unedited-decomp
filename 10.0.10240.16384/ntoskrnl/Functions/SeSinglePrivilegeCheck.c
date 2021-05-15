// SeSinglePrivilegeCheck 
 
int __fastcall SeSinglePrivilegeCheck(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r0
  int v6; // r5
  _BYTE v8[16]; // [sp-4h] [bp-30h] BYREF
  int var20[14]; // [sp+Ch] [bp-20h] BYREF

  var20[12] = a3;
  var20[13] = a4;
  var20[0] = 1;
  v4 = (char)a3;
  var20[3] = a2;
  var20[4] = 0;
  var20[10] = a1;
  var20[11] = a2;
  var20[1] = 1;
  var20[2] = a1;
  SeCaptureSubjectContextEx(
    __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0,
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
    v8);
  v5 = SePrivilegeCheck(var20, v8, v4);
  v6 = v5;
  if ( v4 )
    SePrivilegedServiceAuditAlarm(0, v8, var20, v5);
  SeReleaseSubjectContext(v8);
  return v6;
}
