// NtPrivilegedServiceAuditAlarm 
 
int __fastcall NtPrivilegedServiceAuditAlarm(_DWORD *a1, _DWORD *a2, int a3, unsigned int a4, unsigned __int8 a5)
{
  unsigned int *v7; // r6
  int v8; // r9
  int v9; // r8
  int v10; // r4
  int v11; // r4
  int v12; // r0
  int v13; // r0
  int v14; // r10
  unsigned int v15; // r5
  _DWORD *v16; // r3
  int v17; // r0
  int v19; // [sp+14h] [bp-4Ch] BYREF
  int v20; // [sp+18h] [bp-48h] BYREF
  unsigned int v21; // [sp+1Ch] [bp-44h]
  int v22; // [sp+20h] [bp-40h]
  int v23; // [sp+24h] [bp-3Ch] BYREF
  _DWORD *v24; // [sp+28h] [bp-38h]
  int v25[12]; // [sp+30h] [bp-30h] BYREF

  v21 = a4;
  v24 = a2;
  v7 = 0;
  v22 = 0;
  v8 = 0;
  v19 = 0;
  v9 = 0;
  v20 = 0;
  v10 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  SeCaptureSubjectContext(v25);
  if ( !SeCheckAuditPrivilege(v25, v10) )
  {
    v11 = -1073741727;
LABEL_10:
    SeReleaseSubjectContext((int)v25);
    return v11;
  }
  v12 = ObReferenceObjectByHandle(a3, 8, SeTokenObjectType, v10, &v23);
  v11 = v12;
  if ( v12 >= 0 )
  {
    v14 = v23;
    if ( *(_DWORD *)(v23 + 168) == 2 && *(int *)(v23 + 172) < 1 )
    {
      ObfDereferenceObject(v23);
      v11 = -1073741659;
      goto LABEL_10;
    }
    if ( !a1 || (v12 = SepProbeAndCaptureString_U(a1, &v19), v11 = v12, v8 = v19, v12 >= 0) )
    {
      if ( !v24 || (v12 = SepProbeAndCaptureString_U(v24, &v20), v11 = v12, v9 = v20, v12 >= 0) )
      {
        if ( (v21 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v12);
        v15 = *(_DWORD *)v21;
        if ( *(_DWORD *)v21 && v15 > 0x41 )
        {
          v11 = -1073741811;
        }
        else
        {
          v16 = (_DWORD *)(12 * (v15 - 1) + 20);
          v24 = v16;
          if ( 12 * (v15 - 1) != -20 && ((unsigned int)v16 + v21 > MmUserProbeAddress || (unsigned int)v16 + v21 < v21) )
            *(_BYTE *)MmUserProbeAddress = 0;
          v17 = ExAllocatePoolWithTag(1, (int)v16, 1917871443);
          v7 = (unsigned int *)v17;
          v22 = v17;
          if ( v17 )
          {
            memmove(v17, v21, (unsigned int)v24);
            *v7 = v15;
          }
          else
          {
            v11 = -1073741670;
          }
        }
      }
    }
    if ( v11 >= 0 )
    {
      SepAdtPrivilegedServiceAuditAlarm((int)v25, v8, v9, v14, v25[2], (int)v7, a5);
      if ( v8 )
        ExFreePoolWithTag(v8);
      if ( v9 )
        ExFreePoolWithTag(v9);
      if ( v7 )
        ExFreePoolWithTag((unsigned int)v7);
      ObfDereferenceObject(v14);
      SeReleaseSubjectContext((int)v25);
      v11 = 0;
    }
    else
    {
      if ( v8 )
        ExFreePoolWithTag(v8);
      if ( v9 )
        ExFreePoolWithTag(v9);
      if ( v7 )
        ExFreePoolWithTag((unsigned int)v7);
      SeReleaseSubjectContext((int)v25);
      ObfDereferenceObject(v14);
      if ( v11 == -1073741670 )
      {
        v13 = -1073741670;
        goto LABEL_6;
      }
    }
  }
  else
  {
    SeReleaseSubjectContext((int)v25);
    if ( v11 != -1073741816 )
    {
      v13 = v11;
LABEL_6:
      SepAuditFailed(v13);
      return v11;
    }
  }
  return v11;
}
