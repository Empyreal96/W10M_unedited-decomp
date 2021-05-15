// RtlCheckTokenMembershipEx 
 
int __fastcall RtlCheckTokenMembershipEx(int a1, int a2, int a3, _BYTE *a4)
{
  char v5; // r7
  int v7; // r6
  int v9; // r5
  int v10; // r4
  int v11; // r0
  int v12; // r7
  int v13; // [sp+0h] [bp-1C0h]
  int *v14; // [sp+4h] [bp-1BCh]
  int v15; // [sp+20h] [bp-1A0h] BYREF
  int v16; // [sp+24h] [bp-19Ch] BYREF
  _DWORD v17[2]; // [sp+28h] [bp-198h] BYREF
  int v18; // [sp+30h] [bp-190h]
  int v19; // [sp+34h] [bp-18Ch]
  char *v20; // [sp+38h] [bp-188h] BYREF
  int v21[7]; // [sp+3Ch] [bp-184h] BYREF
  char v22[24]; // [sp+58h] [bp-168h] BYREF
  int v23[2]; // [sp+70h] [bp-150h] BYREF
  char v24; // [sp+78h] [bp-148h]
  char v25; // [sp+79h] [bp-147h]
  char v26[72]; // [sp+80h] [bp-140h] BYREF
  char v27[160]; // [sp+C8h] [bp-F8h] BYREF
  char v28; // [sp+168h] [bp-58h] BYREF

  v15 = 0;
  v17[0] = 0;
  v17[1] = 0;
  v18 = 0;
  v19 = 0;
  *a4 = 0;
  v5 = a3;
  v7 = a1;
  if ( (a3 & 0xFFFFFFFE) != 0 )
    return sub_5154A8();
  v9 = 0;
  if ( a1 )
  {
    v21[1] = 24;
    v21[2] = 0;
    v21[4] = 512;
    v21[3] = 0;
    v21[5] = 0;
    v23[0] = 12;
    v23[1] = 2;
    v24 = 1;
    v25 = 0;
    v21[6] = (int)v23;
    v14 = &v15;
    v13 = 2;
    v10 = ZwDuplicateToken();
    if ( v10 < 0 )
      goto LABEL_22;
    v7 = 0;
  }
  else
  {
    SeCaptureSubjectContext(v17);
    v9 = 1;
  }
  RtlCreateSecurityDescriptor(v22, 1);
  RtlSetOwnerSecurityDescriptor(v22, a2, 0);
  RtlSetGroupSecurityDescriptor(v22, a2, 0);
  RtlCreateAcl(v27, 160, 2);
  RtlAddAccessAllowedAce(v27, 2, 1, a2);
  if ( (v5 & 1) != 0 )
  {
    RtlInitializeSidEx(v26, &RtlpAppPackageAuthority, 2, 2, 1, v14);
    RtlAddAccessAllowedAce(v27, 2, 1, v26);
  }
  RtlSetDaclSecurityDescriptor(v22, 1, v27, 0, v13);
  v20 = &v28;
  if ( v9 )
  {
    v12 = v18;
  }
  else
  {
    v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 176);
    v11 = ObReferenceObjectByHandle(v15, 8, SeTokenObjectType, 0, &v16, 0);
    v12 = v16;
    v10 = v11;
    v18 = v16;
    if ( v11 < 0 )
      goto LABEL_16;
  }
  SeAccessCheckWithHint(
    v22,
    0,
    v17,
    0,
    1,
    0,
    &v20,
    RtlpCheckTokenMembershipGenericMapping,
    *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A),
    v21,
    &v16);
  if ( !v9 )
    ObfDereferenceObjectWithTag(v12, 1953261124);
  v10 = 0;
  if ( v16 )
  {
    if ( v16 == -1073741790 )
      goto LABEL_15;
LABEL_25:
    v10 = v16;
    goto LABEL_15;
  }
  if ( v21[0] != 1 )
    goto LABEL_25;
  *a4 = 1;
LABEL_15:
  if ( !v9 )
    goto LABEL_16;
  SeReleaseSubjectContext(v17);
LABEL_22:
  if ( !v7 )
  {
LABEL_16:
    if ( v15 )
      ZwClose();
  }
  return v10;
}
