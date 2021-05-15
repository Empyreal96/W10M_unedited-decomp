// BuildKnownDlls 
 
unsigned int BuildKnownDlls()
{
  int v0; // r5
  int v1; // r0
  unsigned int v2; // r4
  int v3; // r8
  int v4; // r0
  unsigned __int8 *v5; // r5
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v10; // [sp+8h] [bp-68h]
  int v11; // [sp+Ch] [bp-64h] BYREF
  int v12[2]; // [sp+10h] [bp-60h] BYREF
  char v13[8]; // [sp+18h] [bp-58h] BYREF
  char v14[24]; // [sp+20h] [bp-50h] BYREF
  int v15; // [sp+38h] [bp-38h] BYREF
  int v16; // [sp+3Ch] [bp-34h]
  int *v17; // [sp+40h] [bp-30h]
  int v18; // [sp+44h] [bp-2Ch]
  char *v19; // [sp+48h] [bp-28h]
  int v20; // [sp+4Ch] [bp-24h]

  RtlCreateSecurityDescriptor(v14, 1);
  v0 = *(unsigned __int8 *)(SeAliasAdminsSid + 1)
     + *(unsigned __int8 *)(SeAllAppPackagesSid + 1)
     + *(unsigned __int8 *)(SeRestrictedSid + 1)
     + *(unsigned __int8 *)(SeWorldSid + 1)
     + 22;
  v1 = ExAllocatePoolWithTag(1, 4 * v0, 1953066569);
  v2 = v1;
  if ( !v1 )
    sub_96C69C();
  RtlCreateAcl(v1, 4 * v0, 2);
  v3 = *(unsigned __int8 *)(SeProcTrustLiteWinTcbSid + 1) + 7;
  v4 = ExAllocatePoolWithTag(1, 4 * v3, 1953066569);
  v5 = (unsigned __int8 *)v4;
  if ( !v4 )
    KeBugCheckEx(109, -1073741670, 1, 1, 0);
  RtlCreateAcl(v4, 4 * v3, 2);
  RtlAddAccessAllowedAce(v2, 2, 0x10000000, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(v2, 2, -1610612736, SeWorldSid);
  RtlAddAccessAllowedAce(v2, 2, -1610612736, SeRestrictedSid);
  RtlAddAccessAllowedAce(v2, 2, -1610612736, SeAllAppPackagesSid);
  RtlSetDaclSecurityDescriptor((int)v14, 1, v2, 0);
  RtlAddProcessTrustLabelAce(v5, 2u, 0, (_BYTE *)SeProcTrustLiteWinTcbSid, 20, 131075);
  RtlSetSaclSecurityDescriptor((int)v14, 1, (int)v5, 0);
  v15 = 24;
  v16 = 0;
  v18 = 80;
  v17 = &NtKnownDllsObjectDirectoryName;
  v19 = v14;
  v20 = 0;
  v6 = ZwCreateDirectoryObject();
  if ( v6 < 0 )
    KeBugCheckEx(109, v6, 1, 2, 0);
  RtlCreateSecurityDescriptor(v14, 1);
  RtlSetDaclSecurityDescriptor((int)v14, 1, v2, 0);
  RtlInitUnicodeString((unsigned int)v13, (unsigned __int16 *)NtKnownDllsPath);
  v7 = ExpandKnownDllsPath(v13, v12);
  if ( v7 < 0 )
    KeBugCheckEx(109, v7, 1, 4, 0);
  v15 = 24;
  v16 = v10;
  v17 = &NtKnownDllsPathSymLink;
  v18 = 80;
  v19 = v14;
  v20 = 0;
  v8 = NtCreateSymbolicLinkObject((unsigned int)&v11, 983041, (int)&v15, v12);
  if ( v8 < 0 )
    KeBugCheckEx(109, v8, 1, 5, 0);
  ZwClose();
  ZwClose();
  ExFreePoolWithTag(v12[1]);
  ExFreePoolWithTag((unsigned int)v5);
  return ExFreePoolWithTag(v2);
}
