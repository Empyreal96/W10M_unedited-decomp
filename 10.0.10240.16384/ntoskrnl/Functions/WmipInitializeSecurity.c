// WmipInitializeSecurity 
 
int WmipInitializeSecurity()
{
  int v0; // r4
  int v1; // r0
  unsigned int v2; // r6
  int v4; // r4
  int v5; // r5
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // [sp+0h] [bp-78h] BYREF
  int v10[22]; // [sp+8h] [bp-70h] BYREF

  v0 = *(unsigned __int8 *)(SeLocalSystemSid + 1)
     + *(unsigned __int8 *)(*(_DWORD *)(SeExports + 300) + 1)
     + *(unsigned __int8 *)(*(_DWORD *)(SeExports + 296) + 1)
     + *(unsigned __int8 *)(SeAliasUsersSid + 1)
     + *(unsigned __int8 *)(SeAliasAdminsSid + 1)
     + 29;
  v1 = ExAllocatePoolWithTag(1, 4 * v0, 1885957463);
  v2 = v1;
  if ( !v1 )
    return sub_969198();
  v4 = RtlCreateAcl(v1, 4 * v0, 2);
  if ( v4 < 0 )
    goto LABEL_14;
  v4 = RtlAddAccessAllowedAce(v2, 2, 0x1FFFFF, SeLocalSystemSid);
  if ( v4 < 0 )
    goto LABEL_14;
  v4 = RtlAddAccessAllowedAce(v2, 2, 2048, SeAliasUsersSid);
  if ( v4 < 0 )
    goto LABEL_14;
  v4 = RtlAddAccessAllowedAce(v2, 2, 18874367, SeAliasAdminsSid);
  if ( v4 < 0 )
    goto LABEL_14;
  v4 = RtlAddAccessAllowedAce(v2, 2, 0x1FFFFF, *(_DWORD *)(SeExports + 296));
  if ( v4 < 0 )
    goto LABEL_14;
  v4 = RtlAddAccessAllowedAce(v2, 2, 0x1FFFFF, *(_DWORD *)(SeExports + 300));
  if ( v4 < 0 )
    goto LABEL_14;
  WmipDefaultAccessSd = (int)WmipDefaultAccessSecurityDescriptor;
  RtlCreateSecurityDescriptor(WmipDefaultAccessSecurityDescriptor, 1);
  v4 = RtlSetDaclSecurityDescriptor((int)WmipDefaultAccessSecurityDescriptor, 1, v2, 0);
  if ( v4 < 0 )
    goto LABEL_14;
  v5 = SeAliasAdminsSid;
  v4 = RtlSetOwnerSecurityDescriptor((int)WmipDefaultAccessSecurityDescriptor, SeAliasAdminsSid, 0);
  if ( v4 < 0 )
    goto LABEL_14;
  v4 = RtlSetGroupSecurityDescriptor((int)WmipDefaultAccessSecurityDescriptor, v5, 0);
  if ( v4 < 0 )
    goto LABEL_14;
  SeCaptureSubjectContext(&WmipSystemSubjectContext, v6, v7, v8);
  memset(v10, 0, sizeof(v10));
  LOWORD(v10[0]) = 88;
  v10[2] = 256;
  v10[3] = 1;
  v10[4] = 2;
  v10[5] = 16;
  v10[6] = 1183743;
  v10[7] = 2035711;
  BYTE2(v10[0]) = BYTE2(v10[0]) & 0xE7 | 8;
  v10[9] = 512;
  v10[11] = 108;
  v10[17] = (int)WmipSecurityMethod;
  v10[15] = (int)WmipDeleteMethod;
  RtlInitUnicodeString((unsigned int)&v9, L"WmiGuid");
  v4 = ObCreateObjectType();
  if ( v4 < 0 )
  {
LABEL_14:
    ExFreePoolWithTag(v2);
    WmipDefaultAccessSd = 0;
  }
  return v4;
}
