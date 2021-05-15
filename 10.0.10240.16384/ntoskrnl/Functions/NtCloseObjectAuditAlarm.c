// NtCloseObjectAuditAlarm 
 
int __fastcall NtCloseObjectAuditAlarm(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v6; // r5
  char v7; // r8
  int v8; // r4
  _DWORD v10[2]; // [sp+8h] [bp-30h] BYREF
  int _10[16]; // [sp+10h] [bp-28h] BYREF

  _10[12] = (int)a1;
  _10[14] = a3;
  _10[15] = a4;
  _10[13] = a2;
  v6 = 0;
  v10[0] = 0;
  v7 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !a3 )
    return 0;
  SeCaptureSubjectContext(_10);
  if ( SeCheckAuditPrivilege(_10, v7) )
  {
    v8 = SepProbeAndCaptureString_U(a1, v10);
    v10[1] = v8;
    v6 = v10[0];
    if ( v8 >= 0 )
      SepAdtCloseObjectAuditAlarm(v10[0], a2, _10);
  }
  else
  {
    v8 = -1073741727;
  }
  if ( v6 )
    ExFreePoolWithTag(v6);
  SeReleaseSubjectContext((int)_10);
  if ( v8 == -1073741670 )
    SepAuditFailed(-1073741670);
  return v8;
}
