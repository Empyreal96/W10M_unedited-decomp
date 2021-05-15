// SeTokenDefaultDaclChangedAuditAlarm 
 
int __fastcall SeTokenDefaultDaclChangedAuditAlarm(int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v7; // r5
  char v8; // r4
  int v9; // r6
  int v10; // r7
  int v11; // r0
  int v12; // r8
  int v14; // r4
  int v15; // r9
  int v16; // [sp+18h] [bp-68h] BYREF
  unsigned int v17; // [sp+1Ch] [bp-64h] BYREF
  int v18; // [sp+20h] [bp-60h] BYREF
  int v19; // [sp+24h] [bp-5Ch]
  int v20[2]; // [sp+28h] [bp-58h] BYREF
  int v21; // [sp+30h] [bp-50h]
  char v22; // [sp+38h] [bp-48h] BYREF
  char v23[19]; // [sp+39h] [bp-47h] BYREF
  char v24; // [sp+50h] [bp-30h] BYREF
  char v25[19]; // [sp+51h] [bp-2Fh] BYREF

  v19 = a3;
  v7 = 0;
  v22 = 0;
  v8 = 0;
  v17 = 0;
  memset(v23, 0, sizeof(v23));
  v24 = 0;
  memset(v25, 0, sizeof(v25));
  v9 = 0;
  v10 = 0;
  v16 = 0;
  v18 = 0;
  v11 = SeCaptureSubjectContext(v20);
  v12 = v20[0];
  if ( !v20[0] )
  {
    v12 = v21;
    if ( !v21 )
      return sub_7DC0C0(v11);
  }
  if ( SepAdtAuditThisEventWithContext(140, 1, 0, v20) )
  {
    if ( !SepIsAclEqual(a4, a5) )
      v8 = 4;
    if ( (v8 & 4) != 0 )
    {
      if ( !a2 )
        goto LABEL_13;
      v14 = SepQueryTypeString(a2, &v17);
      v7 = v17;
      if ( v14 < 0 )
      {
LABEL_22:
        if ( v7 )
          ExFreePoolWithTag(v7);
        if ( v9 )
          SeReleaseSecurityDescriptor(v9, 0, 1);
        if ( v10 )
          SeReleaseSecurityDescriptor(v10, 0, 1);
        if ( v14 < 0 )
          SepAuditFailed(v14);
        return SeReleaseSubjectContext((int)v20);
      }
      if ( v17 )
        v15 = v17;
      else
LABEL_13:
        v15 = 0;
      v14 = RtlCreateSecurityDescriptor(&v22, 1);
      if ( v14 >= 0 )
      {
        v14 = RtlSetDaclSecurityDescriptor((int)&v22, 1, a4, 0);
        if ( v14 >= 0 )
        {
          v14 = SeCaptureSecurityDescriptor(&v22, 0, 1, 1, &v16);
          if ( v14 < 0
            || (v14 = RtlCreateSecurityDescriptor(&v24, 1), v14 < 0)
            || (v14 = RtlSetDaclSecurityDescriptor((int)&v24, 1, a5, 0), v14 < 0) )
          {
            v9 = v16;
          }
          else
          {
            v14 = SeCaptureSecurityDescriptor(&v24, 0, 1, 1, &v18);
            v10 = v18;
            v9 = v16;
            if ( v14 >= 0 )
              SepAdtSecurityDescriptorChangedAuditAlarm(
                v20,
                &SeSubsystemName,
                v15,
                0,
                v19,
                **(_DWORD **)(v12 + 148),
                v16,
                4,
                v18);
          }
        }
      }
      goto LABEL_22;
    }
  }
  return SeReleaseSubjectContext((int)v20);
}
