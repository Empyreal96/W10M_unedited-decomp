// SepInitSystemDacls 
 
int __fastcall SepInitSystemDacls(int a1, int a2)
{
  int v2; // r5
  int v3; // r0
  int v4; // r10
  int v5; // r2
  int v6; // r4
  int v7; // r9
  int v8; // r1
  int v9; // r7
  int v10; // r8
  int v11; // r5
  int v12; // r6
  int v13; // r4
  int v14; // r1
  int v15; // r5
  int v18; // [sp+8h] [bp-20h]

  v2 = *(unsigned __int8 *)(SeAliasAdminsSid + 1);
  v3 = *(unsigned __int8 *)(SeLocalSystemSid + 1);
  v4 = v3 + v2 + 12;
  v5 = *(unsigned __int8 *)(SeWorldSid + 1);
  v18 = 4 * (v5 + 5) + 4 * v4;
  v6 = *(unsigned __int8 *)(SeRestrictedSid + 1);
  v7 = v6 + 5;
  v8 = *(unsigned __int8 *)(SeLocalServiceSid + 1);
  v9 = v8 + v5 + v3 + v2 + 22;
  v10 = *(unsigned __int8 *)(SeOwnerRightsSid + 1) + v3 + v2 + 17;
  v11 = 4
      * (*(unsigned __int8 *)(SeAllAppPackagesSid + 1)
       + *(unsigned __int8 *)(SeServiceSid + 1)
       + *(unsigned __int8 *)(SeNetworkServiceSid + 1)
       + v8
       + v6
       + 25);
  v12 = *(unsigned __int8 *)(SeMediumMandatorySid + 1) + 7;
  SePublicDefaultDacl = ExAllocatePoolWithTag(17, v18, 1665230163);
  SePublicDefaultUnrestrictedDacl = ExAllocatePoolWithTag(17, v18 + 4 * (v6 + 5), 1665230163);
  SePublicOpenDacl = ExAllocatePoolWithTag(17, v18, 1665230163);
  SePublicOpenUnrestrictedDacl = ExAllocatePoolWithTag(17, v18 + 4 * (v6 + 5), 1665230163);
  SeSystemDefaultDacl = ExAllocatePoolWithTag(17, 4 * v4, 1665230163);
  SeLocalServicePublicDacl = ExAllocatePoolWithTag(17, 4 * v9, 1665230163);
  SeAtomDacl = ExAllocatePoolWithTag(17, v18 + 4 * (v6 + 5), 1665230163);
  SepDefaultCapeDacl = ExAllocatePoolWithTag(17, 4 * v10, 1665230163);
  SepDefaultRecoveryCapeDacl = ExAllocatePoolWithTag(17, v11 + 4 * v10, 1665230163);
  v13 = ExAllocatePoolWithTag(17, 4 * v12, 1665230163);
  SeMediumSacl = v13;
  RtlCreateAcl(SePublicDefaultDacl, v18, 2);
  RtlCreateAcl(SePublicDefaultUnrestrictedDacl, v18 + 4 * v7, 2);
  RtlCreateAcl(SePublicOpenDacl, v18, 2);
  RtlCreateAcl(SePublicOpenUnrestrictedDacl, v18 + 4 * v7, 2);
  RtlCreateAcl(SeSystemDefaultDacl, 4 * v4, 2);
  RtlCreateAcl(SeLocalServicePublicDacl, 4 * v9, 2);
  RtlCreateAcl(SeAtomDacl, v18 + 4 * v7, 2);
  RtlCreateAcl(SepDefaultCapeDacl, 4 * v10, 2);
  RtlCreateAcl(SepDefaultRecoveryCapeDacl, v11 + 4 * v10, 2);
  RtlCreateAcl(v13, 4 * v12, 2);
  RtlAddAccessAllowedAce(SePublicDefaultDacl, 2, 0x20000000, SeWorldSid);
  RtlAddAccessAllowedAce(SePublicDefaultUnrestrictedDacl, 2, 0x20000000, SeWorldSid);
  RtlAddAccessAllowedAce(SePublicOpenDacl, 2, -536870912, SeWorldSid);
  RtlAddAccessAllowedAce(SePublicOpenUnrestrictedDacl, 2, -536870912, SeWorldSid);
  RtlAddAccessAllowedAce(SeLocalServicePublicDacl, 2, 0x20000000, SeWorldSid);
  RtlAddAccessAllowedAce(SeAtomDacl, 2, 0x20000, SeWorldSid);
  RtlAddAccessAllowedAce(SePublicDefaultDacl, 2, 0x10000000, SeLocalSystemSid);
  RtlAddAccessAllowedAce(SePublicDefaultUnrestrictedDacl, 2, 0x10000000, SeLocalSystemSid);
  RtlAddAccessAllowedAce(SePublicOpenDacl, 2, 0x10000000, SeLocalSystemSid);
  RtlAddAccessAllowedAce(SePublicOpenUnrestrictedDacl, 2, 0x10000000, SeLocalSystemSid);
  RtlAddAccessAllowedAce(SeSystemDefaultDacl, 2, 0x10000000, SeLocalSystemSid);
  RtlAddAccessAllowedAce(SeLocalServicePublicDacl, 2, 0x10000000, SeLocalSystemSid);
  RtlAddAccessAllowedAce(SeAtomDacl, 2, 2031616, SeLocalSystemSid);
  RtlAddAccessAllowedAce(SePublicDefaultDacl, 2, 0x10000000, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(SePublicDefaultUnrestrictedDacl, 2, 0x10000000, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(SePublicOpenDacl, 2, 0x10000000, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(SePublicOpenUnrestrictedDacl, 2, 0x10000000, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(SeSystemDefaultDacl, 2, -1610481664, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(SeLocalServicePublicDacl, 2, 0x10000000, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(SeAtomDacl, 2, 2031616, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(SePublicDefaultUnrestrictedDacl, 2, 0x20000000, SeRestrictedSid);
  RtlAddAccessAllowedAce(SePublicOpenUnrestrictedDacl, 2, -1610612736, SeRestrictedSid);
  RtlAddAccessAllowedAce(SeAtomDacl, 2, 0x20000, SeRestrictedSid);
  RtlAddAccessAllowedAce(SeLocalServicePublicDacl, 2, 0x10000000, SeLocalServiceSid);
  RtlAddAccessAllowedAce(SepDefaultCapeDacl, 2, 0x1FFFFF, SeLocalSystemSid);
  RtlAddAccessAllowedAce(SepDefaultCapeDacl, 2, 0x1FFFFF, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(SepDefaultCapeDacl, 2, 0, SeOwnerRightsSid);
  RtlAddAccessAllowedAce(SepDefaultRecoveryCapeDacl, 2, 0x1FFFFF, SeLocalSystemSid);
  RtlAddAccessAllowedAce(SepDefaultRecoveryCapeDacl, 2, 0x1FFFFF, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(SepDefaultRecoveryCapeDacl, 2, 0, SeOwnerRightsSid);
  RtlAddAccessAllowedAce(SepDefaultRecoveryCapeDacl, 2, 0x1FFFFF, SeLocalServiceSid);
  RtlAddAccessAllowedAce(SepDefaultRecoveryCapeDacl, 2, 0x1FFFFF, SeNetworkServiceSid);
  RtlAddAccessAllowedAce(SepDefaultRecoveryCapeDacl, 2, 0x1FFFFF, SeRestrictedSid);
  RtlAddAccessAllowedAce(SepDefaultRecoveryCapeDacl, 2, 0x1FFFFF, SeServiceSid);
  RtlAddAccessAllowedAce(SepDefaultRecoveryCapeDacl, 2, 1179817, SeAllAppPackagesSid);
  RtlAddMandatoryAce((unsigned __int8 *)SeMediumSacl, v14, 0, SeMediumMandatorySid, a2, 2);
  SePublicDefaultSd = (int)SepPublicDefaultSd;
  RtlCreateSecurityDescriptor(SepPublicDefaultSd, 1);
  RtlSetDaclSecurityDescriptor((int)SepPublicDefaultSd, 1, SePublicDefaultDacl, 0);
  SePublicDefaultUnrestrictedSd = (int)SepPublicDefaultUnrestrictedSd;
  RtlCreateSecurityDescriptor(SepPublicDefaultUnrestrictedSd, 1);
  RtlSetDaclSecurityDescriptor((int)SepPublicDefaultUnrestrictedSd, 1, SePublicDefaultUnrestrictedDacl, 0);
  SePublicOpenSd = (int)SepPublicOpenSd;
  RtlCreateSecurityDescriptor(SepPublicOpenSd, 1);
  RtlSetDaclSecurityDescriptor((int)SepPublicOpenSd, 1, SePublicOpenDacl, 0);
  SePublicOpenUnrestrictedSd = (int)SepPublicOpenUnrestrictedSd;
  RtlCreateSecurityDescriptor(SepPublicOpenUnrestrictedSd, 1);
  RtlSetDaclSecurityDescriptor((int)SepPublicOpenUnrestrictedSd, 1, SePublicOpenUnrestrictedDacl, 0);
  SeSystemDefaultSd = (int)SepSystemDefaultSd;
  RtlCreateSecurityDescriptor(SepSystemDefaultSd, 1);
  RtlSetDaclSecurityDescriptor(SeSystemDefaultSd, 1, SeSystemDefaultDacl, 0);
  SeLocalServicePublicSd = (int)SepLocalServicePublicSd;
  RtlCreateSecurityDescriptor(SepLocalServicePublicSd, 1);
  RtlSetDaclSecurityDescriptor((int)SepLocalServicePublicSd, 1, SeLocalServicePublicDacl, 0);
  SeAtomSd = (int)SepAtomSd;
  RtlCreateSecurityDescriptor(SepAtomSd, 1);
  RtlSetDaclSecurityDescriptor((int)SepAtomSd, 1, SeAtomDacl, 0);
  SeDefaultCapeSd = (int)SepDefaultCapeSd;
  RtlCreateSecurityDescriptor(SepDefaultCapeSd, 1);
  RtlSetDaclSecurityDescriptor((int)SepDefaultCapeSd, 1, SepDefaultCapeDacl, 0);
  v15 = SeLocalSystemSid;
  RtlSetOwnerSecurityDescriptor((int)SepDefaultCapeSd, SeLocalSystemSid, 0);
  RtlSetGroupSecurityDescriptor((int)SepDefaultCapeSd, v15, 0);
  SeDefaultRecoveryCapeSd = (int)SepDefaultRecoveryCapeSd;
  RtlCreateSecurityDescriptor(SepDefaultRecoveryCapeSd, 1);
  RtlSetDaclSecurityDescriptor((int)SepDefaultRecoveryCapeSd, 1, SepDefaultRecoveryCapeDacl, 0);
  RtlSetOwnerSecurityDescriptor((int)SepDefaultRecoveryCapeSd, v15, 0);
  RtlSetGroupSecurityDescriptor((int)SepDefaultRecoveryCapeSd, v15, 0);
  SeNullDaclSd = (int)SepNullDaclSd;
  RtlCreateSecurityDescriptor(SepNullDaclSd, 1);
  SeMediumDaclSd = (int)SepMediumDaclSd;
  RtlCreateSecurityDescriptor(SepMediumDaclSd, 1);
  RtlSetSaclSecurityDescriptor((int)SepMediumDaclSd, 1, SeMediumSacl, 0);
  RtlSetOwnerSecurityDescriptor((int)SepMediumDaclSd, v15, 0);
  return RtlSetGroupSecurityDescriptor((int)SepMediumDaclSd, v15, 0);
}
