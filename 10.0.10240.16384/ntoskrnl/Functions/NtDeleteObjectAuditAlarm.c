// NtDeleteObjectAuditAlarm 
 
int __fastcall NtDeleteObjectAuditAlarm(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v6; // r5
  int v7; // r3
  char v8; // r8
  int v9; // r4
  int v11[2]; // [sp+8h] [bp-30h] BYREF
  int _10[16]; // [sp+10h] [bp-28h] BYREF

  _10[12] = (int)a1;
  _10[14] = a3;
  _10[15] = a4;
  _10[13] = a2;
  v6 = 0;
  v11[0] = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_BYTE *)(v7 + 346);
  if ( !a3 )
    return 0;
  SeCaptureSubjectContext(_10, a2, a3, v7);
  if ( !_10[2] )
  {
    v9 = -1073741700;
LABEL_5:
    SepAuditFailed();
    return v9;
  }
  if ( SeCheckAuditPrivilege(_10, v8) )
  {
    v9 = SepProbeAndCaptureString_U(a1, v11);
    v11[1] = v9;
    v6 = v11[0];
    if ( v9 >= 0 )
      SepAdtDeleteObjectAuditAlarm(v11[0], a2, _10, 0, 0, 0);
  }
  else
  {
    v9 = -1073741727;
  }
  SeReleaseSubjectContext((int)_10);
  if ( v6 )
    ExFreePoolWithTag(v6);
  if ( v9 == -1073741670 )
    goto LABEL_5;
  return v9;
}
