// NtPrivilegeObjectAuditAlarm 
 
int __fastcall NtPrivilegeObjectAuditAlarm(_DWORD *a1, int a2, int a3, int a4, unsigned int a5, unsigned __int8 a6)
{
  int v6; // r10
  unsigned int *v9; // r6
  char v10; // r4
  int v11; // r4
  int v12; // r0
  int v13; // r8
  int v14; // r0
  unsigned int v15; // r9
  int v16; // r3
  unsigned int v17; // r10
  int v18; // r0
  unsigned int v19; // r4
  unsigned int v21; // [sp+1Ch] [bp-44h] BYREF
  int v22; // [sp+20h] [bp-40h]
  int v23; // [sp+24h] [bp-3Ch]
  int v24; // [sp+28h] [bp-38h]
  int v25; // [sp+2Ch] [bp-34h] BYREF
  int _30[18]; // [sp+30h] [bp-30h] BYREF

  _30[14] = (int)a1;
  _30[16] = a3;
  v6 = a4;
  v22 = a4;
  _30[17] = a4;
  v23 = a2;
  _30[15] = a2;
  v21 = 0;
  v9 = 0;
  v24 = 0;
  v10 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  SeCaptureSubjectContext(_30, a2, a3, 0);
  if ( !SeCheckAuditPrivilege(_30, v10) )
  {
    v11 = -1073741727;
LABEL_10:
    SeReleaseSubjectContext((int)_30);
    return v11;
  }
  v11 = ObReferenceObjectByHandle(a3, 8, SeTokenObjectType, v10, (int)&v25, 0);
  if ( v11 >= 0 )
  {
    v13 = v25;
    if ( *(_DWORD *)(v25 + 168) == 2 && *(int *)(v25 + 172) < 1 )
    {
      ObfDereferenceObject(v25);
      v11 = -1073741659;
      goto LABEL_10;
    }
    v14 = SepProbeAndCaptureString_U(a1, &v21);
    v11 = v14;
    if ( v14 >= 0 )
    {
      if ( (a5 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v14);
      v15 = *(_DWORD *)a5;
      if ( *(_DWORD *)a5 && v15 > 0x41 )
      {
        v11 = -1073741811;
      }
      else
      {
        v16 = 12 * (v15 - 1);
        v17 = v16 + 20;
        if ( v16 != -20 && (v17 + a5 > MmUserProbeAddress || v17 + a5 < a5) )
          *(_BYTE *)MmUserProbeAddress = 0;
        v18 = ExAllocatePoolWithTag(1, v17, 1917871443);
        v9 = (unsigned int *)v18;
        v24 = v18;
        if ( v18 )
        {
          memmove(v18, a5, v17);
          *v9 = v15;
        }
        else
        {
          v11 = -1073741670;
        }
        v6 = v22;
      }
    }
    if ( v11 >= 0 )
    {
      v19 = v21;
      SepAdtPrivilegeObjectAuditAlarm(v21, 0, 0, v23, v13, _30[2], _30[3], v6, (int)v9, a6);
      if ( v9 )
        ExFreePoolWithTag((unsigned int)v9);
      if ( v19 )
        ExFreePoolWithTag(v19);
      SeReleaseSubjectContext((int)_30);
      ObfDereferenceObject(v13);
      v11 = 0;
    }
    else
    {
      if ( v9 )
        ExFreePoolWithTag((unsigned int)v9);
      if ( v21 )
        ExFreePoolWithTag(v21);
      SeReleaseSubjectContext((int)_30);
      ObfDereferenceObject(v13);
      if ( v11 == -1073741670 )
      {
        v12 = -1073741670;
        goto LABEL_6;
      }
    }
  }
  else
  {
    SeReleaseSubjectContext((int)_30);
    if ( v11 != -1073741816 )
    {
      v12 = v11;
LABEL_6:
      SepAuditFailed(v12);
      return v11;
    }
  }
  return v11;
}
