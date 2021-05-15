// CmpGenerateAppHiveSecurityDescriptor 
 
int CmpGenerateAppHiveSecurityDescriptor()
{
  int v0; // r4
  int v1; // r6
  int v2; // r0
  int *v3; // r8
  int v4; // r0
  _DWORD *v5; // r7
  int v6; // r4
  int v7; // r5
  int v8; // r1
  int v10; // [sp+0h] [bp-188h]
  int *v11; // [sp+8h] [bp-180h] BYREF
  _DWORD *v12; // [sp+Ch] [bp-17Ch] BYREF
  char v13[24]; // [sp+10h] [bp-178h] BYREF
  char v14[88]; // [sp+28h] [bp-160h] BYREF
  char v15[264]; // [sp+80h] [bp-108h] BYREF

  v11 = 0;
  v12 = 0;
  v0 = 0;
  RtlCreateSecurityDescriptor(v13, 1);
  v1 = PsReferencePrimaryToken(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  v2 = SeQueryInformationToken(v1, 4, &v11);
  v3 = v11;
  if ( v2 >= 0 )
  {
    v4 = SeQueryInformationToken(v1, 5, &v12);
    v5 = v12;
    if ( v4 >= 0 )
    {
      v6 = *v3;
      v7 = *v12;
      RtlCreateSecurityDescriptor(v13, 1);
      RtlSetOwnerSecurityDescriptor(v13, v6, 0);
      RtlSetGroupSecurityDescriptor(v13, v7, 0);
      RtlCreateAcl(v15, 236, 2);
      RtlAddAccessAllowedAceEx(v15, 2, 2, 983103, SeWorldSid);
      RtlAddAccessAllowedAceEx(v15, 2, 2, 983103, SeAllAppPackagesSid);
      RtlAddAccessAllowedAceEx(v15, 2, 2, 983103, SeRestrictedSid);
      RtlSetDaclSecurityDescriptor(v13, 1, v15, 0, v10);
      RtlCreateAcl(v14, 84, 2);
      RtlAddMandatoryAce(v14, v8, 0, SeLowMandatorySid);
      RtlSetSaclSecurityDescriptor(v13, 1, v14, 0);
      v11 = 0;
      RtlAbsoluteToSelfRelativeSD(v13, 0, &v11);
      v0 = ExAllocatePoolWithTag(1, v11, 1699966275);
      if ( v0 )
        RtlAbsoluteToSelfRelativeSD(v13, v0, &v11);
    }
    if ( v5 )
      ExFreePoolWithTag(v5, 0);
  }
  if ( v3 )
    ExFreePoolWithTag(v3, 0);
  if ( v1 )
    ObfDereferenceObjectWithTag(v1);
  return v0;
}
