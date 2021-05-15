// SepVariableInitialization 
 
int SepVariableInitialization()
{
  int v0; // r1
  int result; // r0
  int v2; // r4
  int v3; // r7
  int v4; // r10
  int v5; // r9
  int v6; // r6
  int v7; // r8
  int v8; // r1
  int v9; // r0
  int v10; // r7
  int v11; // r0
  int v12; // r4
  int v13; // r0
  int v14; // r4
  int v15; // r0
  int v16; // r7
  int v17; // r0
  int v18; // r4
  int v19; // r10
  int v20; // r9
  int v21; // r8
  _DWORD *v22; // r6
  int v23; // r7
  int v24; // r5
  int v25; // r4
  int v26; // lr
  int v27; // r0
  int v28; // r1
  int v29; // r3
  int v30; // r2
  int v31; // r2
  int v32; // r3
  int v33; // r2
  int v34; // r2
  int v35; // r1
  int v36; // r0
  int v37; // r1
  int v38; // [sp+0h] [bp-F0h] BYREF
  __int16 v39; // [sp+4h] [bp-ECh]
  int v40; // [sp+8h] [bp-E8h]
  _BYTE *v41; // [sp+Ch] [bp-E4h]
  int v42; // [sp+10h] [bp-E0h] BYREF
  __int16 v43; // [sp+14h] [bp-DCh]
  int v44; // [sp+18h] [bp-D8h]
  int v45; // [sp+1Ch] [bp-D4h]
  int v46; // [sp+20h] [bp-D0h]
  int v47; // [sp+24h] [bp-CCh]
  int v48; // [sp+28h] [bp-C8h]
  int v49; // [sp+2Ch] [bp-C4h]
  int v50; // [sp+30h] [bp-C0h] BYREF
  __int16 v51; // [sp+34h] [bp-BCh]
  int v52; // [sp+38h] [bp-B8h] BYREF
  __int16 v53; // [sp+3Ch] [bp-B4h]
  int v54; // [sp+40h] [bp-B0h]
  int v55; // [sp+44h] [bp-ACh]
  int v56; // [sp+48h] [bp-A8h] BYREF
  __int16 v57; // [sp+4Ch] [bp-A4h]
  int v58; // [sp+50h] [bp-A0h] BYREF
  __int16 v59; // [sp+54h] [bp-9Ch]
  int v60; // [sp+58h] [bp-98h] BYREF
  __int16 v61; // [sp+5Ch] [bp-94h]
  int v62; // [sp+60h] [bp-90h] BYREF
  __int16 v63; // [sp+64h] [bp-8Ch]
  int v64; // [sp+68h] [bp-88h]
  int v65; // [sp+6Ch] [bp-84h]
  int v66; // [sp+70h] [bp-80h]
  int v67; // [sp+74h] [bp-7Ch]
  int v68; // [sp+78h] [bp-78h]
  int v69; // [sp+7Ch] [bp-74h]
  int v70; // [sp+80h] [bp-70h]
  int v71; // [sp+84h] [bp-6Ch]
  int v72; // [sp+88h] [bp-68h]
  int v73; // [sp+8Ch] [bp-64h]
  int v74; // [sp+90h] [bp-60h]
  int v75; // [sp+94h] [bp-5Ch]
  int v76; // [sp+98h] [bp-58h]
  int v77; // [sp+9Ch] [bp-54h]
  int v78; // [sp+A0h] [bp-50h]
  int v79; // [sp+A4h] [bp-4Ch]
  int v80; // [sp+A8h] [bp-48h]
  int v81; // [sp+ACh] [bp-44h]
  int v82; // [sp+B0h] [bp-40h]
  int v83; // [sp+B4h] [bp-3Ch]
  int v84; // [sp+B8h] [bp-38h]
  __int16 v85[2]; // [sp+C0h] [bp-30h] BYREF
  const __int16 *v86; // [sp+C4h] [bp-2Ch]
  __int16 v87[2]; // [sp+C8h] [bp-28h] BYREF
  const __int16 *v88; // [sp+CCh] [bp-24h]

  v87[0] = 40;
  v87[1] = 42;
  v88 = L"sessionImpersonation";
  v85[0] = 48;
  v85[1] = 50;
  v86 = L"constrainedImpersonation";
  v58 = 0;
  v59 = 0;
  v60 = 0;
  v61 = 256;
  v56 = 0;
  v57 = 512;
  v42 = 0;
  v43 = 768;
  v38 = 0;
  v39 = 1280;
  v52 = 0;
  v53 = 4096;
  v62 = 0;
  v63 = 3840;
  v50 = 0;
  v51 = 4864;
  v0 = *(_DWORD *)(*((_DWORD *)KeLoaderBlock_0 + 33) + 68);
  if ( (v0 & 0x40) != 0 || MEMORY[0xFFFF9264] != 1 || MEMORY[0xFFFF92E8] > 0x51400u )
    return sub_96C6F0();
  SepTokenSidSharingEnabled = 1;
  SepTokenCapabilitySidSharingEnabled = 1;
  SepOsLoaderTpmDriverLoaded = (v0 & 0x80) != 0;
  v44 = RtlLengthRequiredSid(0);
  v2 = RtlLengthRequiredSid(1u);
  v46 = RtlLengthRequiredSid(2u);
  v67 = RtlLengthRequiredSid(6u);
  v49 = RtlLengthRequiredSid(9u);
  v48 = RtlLengthRequiredSid(0xAu);
  SeNullSid = ExAllocatePoolWithTag(17, v2, 1767073107);
  SeCreatorOwnerSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeCreatorGroupSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeCreatorOwnerServerSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeCreatorGroupServerSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeWorldSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeLocalSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  v3 = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeOwnerRightsSid = v3;
  v47 = SeNullSid;
  if ( !SeNullSid )
    goto LABEL_60;
  v41 = (_BYTE *)SeWorldSid;
  if ( !SeWorldSid )
    goto LABEL_60;
  v40 = SeLocalSid;
  if ( !SeLocalSid )
    goto LABEL_60;
  v45 = SeCreatorOwnerSid;
  if ( !SeCreatorOwnerSid )
    goto LABEL_60;
  v4 = SeCreatorGroupSid;
  if ( !SeCreatorGroupSid )
    goto LABEL_60;
  v5 = SeCreatorOwnerServerSid;
  if ( !SeCreatorOwnerServerSid )
    goto LABEL_60;
  if ( !v3 )
    goto LABEL_60;
  v6 = SeCreatorGroupServerSid;
  if ( !SeCreatorGroupServerSid )
    goto LABEL_60;
  RtlInitializeSid(SeNullSid, (int)&v58, 1u);
  RtlInitializeSid((int)v41, (int)&v60, 1u);
  RtlInitializeSid(v40, (int)&v56, 1u);
  v7 = v45;
  RtlInitializeSid(v45, (int)&v42, 1u);
  RtlInitializeSid(v4, (int)&v42, 1u);
  RtlInitializeSid(v5, (int)&v42, 1u);
  RtlInitializeSid(v6, (int)&v42, 1u);
  RtlInitializeSid(v3, (int)&v42, 1u);
  v8 = v44;
  *(_DWORD *)(v47 + 8) = 0;
  *((_DWORD *)v41 + 2) = 0;
  *(_DWORD *)(v40 + 8) = 0;
  *(_DWORD *)(v7 + 8) = 0;
  *(_DWORD *)(v4 + 8) = 1;
  *(_DWORD *)(v5 + 8) = 2;
  *(_DWORD *)(v6 + 8) = 3;
  *(_DWORD *)(v3 + 8) = 4;
  SeNtAuthoritySid = ExAllocatePoolWithTag(17, v8, 1767073107);
  SeDialupSid = ExAllocatePoolWithTag(17, v2, 1767073107);
  SeNetworkSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeBatchSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeInteractiveSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SePrincipalSelfSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeServiceSid = ExAllocatePoolWithTag(17, v2, 1767073107);
  SeLocalSystemSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeAuthenticatedUsersSid = ExAllocatePoolWithTag(17, v2, 1767073107);
  SeRestrictedSid = ExAllocatePoolWithTag(17, v2, 1767073107);
  SeAnonymousLogonSid = ExAllocatePoolWithTag(17, v2, 1767073107);
  SeLocalServiceSid = ExAllocatePoolWithTag(17, v2, 1767073107);
  SeNetworkServiceSid = ExAllocatePoolWithTag(17, v2, 1767073107);
  v9 = ExAllocatePoolWithTag(17, v2, 1767073107);
  v10 = v46;
  SeIUserSid = v9;
  SeAliasAdminsSid = ExAllocatePoolWithTag(17, v46, 1767073107);
  SeAliasUsersSid = ExAllocatePoolWithTag(17, v10, 1767073107);
  SeAliasGuestsSid = ExAllocatePoolWithTag(17, v10, 1767073107);
  SeAliasPowerUsersSid = ExAllocatePoolWithTag(17, v10, 1767073107);
  SeAliasAccountOpsSid = ExAllocatePoolWithTag(17, v10, 1767073107);
  SeAliasSystemOpsSid = ExAllocatePoolWithTag(17, v10, 1767073107);
  SeAliasPrintOpsSid = ExAllocatePoolWithTag(17, v10, 1767073107);
  SeAliasBackupOpsSid = ExAllocatePoolWithTag(17, v10, 1767073107);
  SeUntrustedMandatorySid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeLowMandatorySid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeMediumMandatorySid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeHighMandatorySid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeSystemMandatorySid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SePackagePrefixSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  SeCapabilityPrefixSid = ExAllocatePoolWithTag(528, v2, 1767073107);
  v11 = ExAllocatePoolWithTag(528, v10, 1767073107);
  v12 = v67;
  SeAllAppPackagesSid = v11;
  SeUserModeDriversSid = ExAllocatePoolWithTag(528, v67, 1767073107);
  SeTrustedInstallerSid = ExAllocatePoolWithTag(528, v12, 1767073107);
  SeProcTrustWinTcbSid = ExAllocatePoolWithTag(528, v10, 1767073107);
  SeProcTrustWinSid = ExAllocatePoolWithTag(528, v10, 1767073107);
  SeProcTrustLiteWinTcbSid = ExAllocatePoolWithTag(528, v10, 1767073107);
  SeProcTrustLiteWinSid = ExAllocatePoolWithTag(528, v10, 1767073107);
  SeProcTrustNoneSid = ExAllocatePoolWithTag(528, v10, 1767073107);
  v13 = ExAllocatePoolWithTag(17, v10, 1767073107);
  v14 = v49;
  SeDefaultAccountAliasSid = v13;
  v15 = ExAllocatePoolWithTag(17, v49, 1767073107);
  v16 = v48;
  SeConstrainedImpersonationCapabilityGroupSid = v15;
  SeConstrainedImpersonationCapabilitySid = ExAllocatePoolWithTag(17, v48, 1767073107);
  SeSessionImpersonationCapabilityGroupSid = ExAllocatePoolWithTag(17, v14, 1767073107);
  v17 = ExAllocatePoolWithTag(17, v16, 1767073107);
  SeSessionImpersonationCapabilitySid = v17;
  if ( !SeNtAuthoritySid )
    goto LABEL_60;
  v79 = SeDialupSid;
  if ( !SeDialupSid )
    goto LABEL_60;
  v73 = SeNetworkSid;
  if ( !SeNetworkSid )
    goto LABEL_60;
  v83 = SeBatchSid;
  if ( !SeBatchSid )
    goto LABEL_60;
  v75 = SeInteractiveSid;
  if ( !SeInteractiveSid )
    goto LABEL_60;
  v65 = SeServiceSid;
  if ( !SeServiceSid )
    goto LABEL_60;
  v66 = SePrincipalSelfSid;
  if ( !SePrincipalSelfSid )
    goto LABEL_60;
  v68 = SeLocalSystemSid;
  if ( !SeLocalSystemSid )
    goto LABEL_60;
  v70 = SeAuthenticatedUsersSid;
  if ( !SeAuthenticatedUsersSid )
    goto LABEL_60;
  v72 = SeRestrictedSid;
  if ( !SeRestrictedSid )
    goto LABEL_60;
  v74 = SeAnonymousLogonSid;
  if ( !SeAnonymousLogonSid )
    goto LABEL_60;
  v76 = SeLocalServiceSid;
  if ( !SeLocalServiceSid )
    goto LABEL_60;
  v78 = SeNetworkServiceSid;
  if ( !SeNetworkServiceSid )
    goto LABEL_60;
  v80 = SeIUserSid;
  if ( !SeIUserSid )
    goto LABEL_60;
  v54 = SeAliasAdminsSid;
  if ( !SeAliasAdminsSid )
    goto LABEL_60;
  v56 = SeAliasUsersSid;
  if ( !SeAliasUsersSid )
    goto LABEL_60;
  v55 = SeAliasGuestsSid;
  if ( !SeAliasGuestsSid )
    goto LABEL_60;
  v82 = SeAliasPowerUsersSid;
  if ( !SeAliasPowerUsersSid )
    goto LABEL_60;
  v81 = SeAliasAccountOpsSid;
  if ( !SeAliasAccountOpsSid )
    goto LABEL_60;
  v64 = SeAliasSystemOpsSid;
  if ( !SeAliasSystemOpsSid )
    goto LABEL_60;
  v77 = SeAliasPrintOpsSid;
  if ( !SeAliasPrintOpsSid )
    goto LABEL_60;
  v40 = SeAliasBackupOpsSid;
  if ( !SeAliasBackupOpsSid )
    goto LABEL_60;
  v69 = SeUntrustedMandatorySid;
  if ( !SeUntrustedMandatorySid )
    goto LABEL_60;
  v84 = SeLowMandatorySid;
  if ( !SeLowMandatorySid )
    goto LABEL_60;
  v71 = SeMediumMandatorySid;
  if ( !SeMediumMandatorySid )
    goto LABEL_60;
  v48 = SeHighMandatorySid;
  if ( !SeHighMandatorySid )
    goto LABEL_60;
  v49 = SeSystemMandatorySid;
  if ( !SeSystemMandatorySid )
    goto LABEL_60;
  v46 = SePackagePrefixSid;
  if ( !SePackagePrefixSid )
    goto LABEL_60;
  v44 = SeCapabilityPrefixSid;
  if ( !SeCapabilityPrefixSid )
    goto LABEL_60;
  v47 = SeAllAppPackagesSid;
  if ( !SeAllAppPackagesSid )
    goto LABEL_60;
  v41 = (_BYTE *)SeUserModeDriversSid;
  if ( !SeUserModeDriversSid )
    goto LABEL_60;
  v45 = SeProcTrustWinTcbSid;
  if ( !SeProcTrustWinTcbSid )
    goto LABEL_60;
  v18 = SeProcTrustWinSid;
  v60 = SeProcTrustWinSid;
  if ( !SeProcTrustWinSid )
    goto LABEL_60;
  v19 = SeProcTrustLiteWinTcbSid;
  if ( !SeProcTrustLiteWinTcbSid )
    goto LABEL_60;
  v20 = SeProcTrustLiteWinSid;
  if ( !SeProcTrustLiteWinSid )
    goto LABEL_60;
  v21 = SeProcTrustNoneSid;
  if ( !SeProcTrustNoneSid )
    goto LABEL_60;
  v22 = (_DWORD *)SeTrustedInstallerSid;
  if ( !SeTrustedInstallerSid )
    goto LABEL_60;
  v23 = SeDefaultAccountAliasSid;
  if ( !SeDefaultAccountAliasSid )
    goto LABEL_60;
  v58 = SeConstrainedImpersonationCapabilitySid;
  if ( !SeConstrainedImpersonationCapabilitySid )
    goto LABEL_60;
  v42 = SeConstrainedImpersonationCapabilityGroupSid;
  if ( !SeConstrainedImpersonationCapabilityGroupSid )
    goto LABEL_60;
  if ( !v17 )
    goto LABEL_60;
  if ( !SeSessionImpersonationCapabilityGroupSid )
    goto LABEL_60;
  RtlInitializeSid(SeNtAuthoritySid, (int)&v38, 0);
  RtlInitializeSid(v79, (int)&v38, 1u);
  RtlInitializeSid(v73, (int)&v38, 1u);
  RtlInitializeSid(v83, (int)&v38, 1u);
  RtlInitializeSid(v75, (int)&v38, 1u);
  RtlInitializeSid(v65, (int)&v38, 1u);
  RtlInitializeSid(v66, (int)&v38, 1u);
  RtlInitializeSid(v68, (int)&v38, 1u);
  RtlInitializeSid(v70, (int)&v38, 1u);
  RtlInitializeSid(v72, (int)&v38, 1u);
  RtlInitializeSid(v74, (int)&v38, 1u);
  RtlInitializeSid(v76, (int)&v38, 1u);
  RtlInitializeSid(v78, (int)&v38, 1u);
  RtlInitializeSid(v80, (int)&v38, 1u);
  RtlInitializeSid(v54, (int)&v38, 2u);
  v24 = v56;
  RtlInitializeSid(v56, (int)&v38, 2u);
  RtlInitializeSid(v55, (int)&v38, 2u);
  RtlInitializeSid(v82, (int)&v38, 2u);
  RtlInitializeSid(v81, (int)&v38, 2u);
  RtlInitializeSid(v64, (int)&v38, 2u);
  RtlInitializeSid(v77, (int)&v38, 2u);
  RtlInitializeSid(v40, (int)&v38, 2u);
  RtlInitializeSid((int)v22, (int)&v38, 6u);
  RtlInitializeSid(v69, (int)&v52, 1u);
  RtlInitializeSid(v84, (int)&v52, 1u);
  RtlInitializeSid(v71, (int)&v52, 1u);
  RtlInitializeSid(v48, (int)&v52, 1u);
  RtlInitializeSid(v49, (int)&v52, 1u);
  RtlInitializeSid(v46, (int)&v62, 1u);
  RtlInitializeSid(v44, (int)&v62, 1u);
  RtlInitializeSid(v47, (int)&v62, 2u);
  memset(v41, 0, v67);
  RtlInitializeSid((int)v41, (int)&v38, 6u);
  RtlInitializeSid(v21, (int)&v50, 2u);
  RtlInitializeSid(v45, (int)&v50, 2u);
  RtlInitializeSid(v18, (int)&v50, 2u);
  RtlInitializeSid(v19, (int)&v50, 2u);
  RtlInitializeSid(v20, (int)&v50, 2u);
  *(_DWORD *)(v79 + 8) = 1;
  *(_DWORD *)(v73 + 8) = 2;
  *(_DWORD *)(v83 + 8) = 3;
  v25 = v81;
  v26 = v82;
  *(_DWORD *)(v75 + 8) = 4;
  v27 = v64;
  v28 = v77;
  *(_DWORD *)(v65 + 8) = 6;
  *(_DWORD *)(v66 + 8) = 10;
  *(_DWORD *)(v68 + 8) = 18;
  *(_DWORD *)(v70 + 8) = 11;
  *(_DWORD *)(v72 + 8) = 12;
  *(_DWORD *)(v74 + 8) = 7;
  *(_DWORD *)(v76 + 8) = 19;
  *(_DWORD *)(v78 + 8) = 20;
  *(_DWORD *)(v80 + 8) = 17;
  *(_DWORD *)(v54 + 8) = 32;
  v29 = v55;
  *(_DWORD *)(v24 + 8) = 32;
  *(_DWORD *)(v29 + 8) = 32;
  *(_DWORD *)(v26 + 8) = 32;
  *(_DWORD *)(v25 + 8) = 32;
  *(_DWORD *)(v27 + 8) = 32;
  *(_DWORD *)(v28 + 8) = 32;
  *(_DWORD *)(v40 + 8) = 32;
  *(_DWORD *)(v54 + 12) = 544;
  *(_DWORD *)(v24 + 12) = 545;
  v30 = v40;
  *(_DWORD *)(v55 + 12) = 546;
  *(_DWORD *)(v26 + 12) = 547;
  *(_DWORD *)(v25 + 12) = 548;
  *(_DWORD *)(v27 + 12) = 549;
  *(_DWORD *)(v28 + 12) = 550;
  *(_DWORD *)(v30 + 12) = 551;
  *(_DWORD *)(v69 + 8) = 0;
  v31 = v48;
  *(_DWORD *)(v84 + 8) = 4096;
  *(_DWORD *)(v71 + 8) = 0x2000;
  *(_DWORD *)(v31 + 8) = 12288;
  *(_DWORD *)(v49 + 8) = 0x4000;
  *(_DWORD *)(v46 + 8) = 2;
  *(_DWORD *)(v44 + 8) = 3;
  v32 = v47;
  *(_DWORD *)(v47 + 8) = 2;
  *(_DWORD *)(v32 + 12) = 1;
  *((_DWORD *)v41 + 2) = 84;
  v33 = v45;
  *(_DWORD *)(v21 + 8) = 0;
  *(_DWORD *)(v21 + 12) = 0;
  *(_DWORD *)(v33 + 8) = 1024;
  *(_DWORD *)(v33 + 12) = 0x2000;
  *(_QWORD *)(v60 + 8) = 0x100000000400i64;
  *(_DWORD *)(v19 + 8) = 512;
  *(_DWORD *)(v19 + 12) = 0x2000;
  *(_QWORD *)(v20 + 8) = 0x100000000200i64;
  v22[2] = 80;
  v22[3] = 956008885;
  v22[4] = -876444647;
  v22[5] = 1831038044;
  v22[6] = 1853292631;
  v22[7] = -2023488832;
  RtlInitializeSid(v23, (int)&v38, 2u);
  v34 = v58;
  v35 = v42;
  *(_DWORD *)(v23 + 8) = 32;
  *(_DWORD *)(v23 + 12) = 581;
  if ( RtlDeriveCapabilitySidsFromName((int)v85, v35, v34) < 0 )
    goto LABEL_60;
  v36 = RtlDeriveCapabilitySidsFromName(
          (int)v87,
          SeSessionImpersonationCapabilityGroupSid,
          SeSessionImpersonationCapabilitySid);
  if ( v36 < 0 )
    goto LABEL_60;
  SepInitSystemDacls(v36, v37);
  SeCreateTokenPrivilege = 2;
  dword_922A04 = 0;
  SeAssignPrimaryTokenPrivilege = 3;
  dword_9227D4 = 0;
  SeLockMemoryPrivilege = 4;
  dword_922B7C = 0;
  SeIncreaseQuotaPrivilege = 5;
  dword_922794 = 0;
  SeUnsolicitedInputPrivilege = 6;
  unk_9229FC = 0;
  SeTcbPrivilege = 7;
  SeSecurityPrivilege = 8i64;
  dword_9227BC = 0;
  SeTakeOwnershipPrivilege = 9i64;
  SeLoadDriverPrivilege = 10;
  dword_922B84 = 0;
  SeCreatePagefilePrivilege = 15;
  dword_922BAC = 0;
  SeIncreaseBasePriorityPrivilege = 14;
  dword_9227C4 = 0;
  SeSystemProfilePrivilege = 11;
  dword_922A0C = 0;
  SeSystemtimePrivilege = 12;
  dword_9229E4 = 0;
  SeProfileSingleProcessPrivilege = 13;
  dword_922B94 = 0;
  SeCreatePermanentPrivilege = 16;
  dword_9227A4 = 0;
  SeBackupPrivilege = 17;
  dword_922BA4 = 0;
  SeRestorePrivilege = 18;
  dword_922B9C = 0;
  SeShutdownPrivilege = 19;
  dword_922B8C = 0;
  SeDebugPrivilege = 20;
  dword_922784 = 0;
  SeAuditPrivilege = 21;
  dword_9229DC = 0;
  SeSystemEnvironmentPrivilege = 22;
  dword_9229F4 = 0;
  SeChangeNotifyPrivilege = 23;
  dword_9229EC = 0;
  SeRemoteShutdownPrivilege = 24;
  unk_9229C4 = 0;
  SeUndockPrivilege = 25;
  dword_9229BC = 0;
  SeSyncAgentPrivilege = 26;
  unk_9229D4 = 0;
  SeEnableDelegationPrivilege = 27;
  unk_9229CC = 0;
  *(_QWORD *)&SeIncreaseWorkingSetPrivilege = 33i64;
  SeManageVolumePrivilege = 28;
  dword_9229A4 = 0;
  SeImpersonatePrivilege = 29;
  dword_92299C = 0;
  SeCreateGlobalPrivilege = 30;
  dword_92279C = 0;
  SeTrustedCredManAccessPrivilege = 31;
  dword_9229B4 = 0;
  SeRelabelPrivilege = 32i64;
  SeTimeZonePrivilege = 34;
  dword_9229AC = 0;
  SeCreateSymbolicLinkPrivilege = 35;
  dword_922994 = 0;
  dword_9228B0 = SeNullSid;
  dword_9228B4 = SeWorldSid;
  dword_9228B8 = SeLocalSid;
  dword_9228BC = SeCreatorOwnerSid;
  dword_9228C0 = SeCreatorGroupSid;
  dword_922980 = SeOwnerRightsSid;
  dword_9228C4 = SeNtAuthoritySid;
  dword_9228C8 = SeDialupSid;
  dword_9228CC = SeNetworkSid;
  dword_9228D0 = SeBatchSid;
  dword_9228D4 = SeInteractiveSid;
  dword_9228D8 = SeLocalSystemSid;
  dword_9228FC = SeAuthenticatedUsersSid;
  dword_922900 = SeRestrictedSid;
  dword_922904 = SeAnonymousLogonSid;
  dword_922920 = SeLocalServiceSid;
  dword_922924 = SeNetworkServiceSid;
  dword_922968 = SeIUserSid;
  dword_9228DC = SeAliasAdminsSid;
  dword_9228E0 = SeAliasUsersSid;
  dword_9228E4 = SeAliasGuestsSid;
  dword_9228E8 = SeAliasPowerUsersSid;
  dword_9228EC = SeAliasAccountOpsSid;
  dword_9228F0 = SeAliasSystemOpsSid;
  dword_9228F4 = SeAliasPrintOpsSid;
  dword_9228F8 = SeAliasBackupOpsSid;
  dword_92296C = SeUntrustedMandatorySid;
  dword_922970 = SeLowMandatorySid;
  dword_922974 = SeMediumMandatorySid;
  dword_922978 = SeHighMandatorySid;
  dword_92297C = SeSystemMandatorySid;
  dword_922984 = SeAllAppPackagesSid;
  dword_922988 = SeUserModeDriversSid;
  dword_92298C = SeTrustedInstallerSid;
  SepExports = 2;
  dword_9227FC = 0;
  dword_922800 = 3;
  dword_922804 = 0;
  dword_922808 = 4;
  dword_92280C = 0;
  dword_922810 = 5;
  dword_922814 = 0;
  dword_922818 = 6;
  dword_92281C = 0;
  dword_922820 = 7;
  dword_922824 = 0;
  dword_922828 = 8;
  dword_92282C = 0;
  dword_922830 = 9;
  dword_922834 = 0;
  dword_922838 = 10;
  dword_92283C = 0;
  dword_922840 = 15;
  dword_922844 = 0;
  dword_922848 = 14;
  dword_92284C = 0;
  dword_922850 = 11;
  dword_922854 = 0;
  dword_922858 = 12;
  dword_92285C = 0;
  dword_922860 = 13;
  dword_922864 = 0;
  dword_922868 = 16;
  dword_92286C = 0;
  dword_922870 = 17;
  dword_922874 = 0;
  dword_922878 = 18;
  dword_92287C = 0;
  dword_922880 = 19;
  dword_922884 = 0;
  dword_922888 = 20;
  dword_92288C = 0;
  dword_922890 = 21;
  dword_922894 = 0;
  dword_922898 = 22;
  dword_92289C = 0;
  dword_9228A0 = 23;
  dword_9228A4 = 0;
  dword_9228A8 = 24;
  dword_9228AC = 0;
  dword_922908 = 25;
  dword_92290C = 0;
  dword_922910 = 26;
  dword_922914 = 0;
  dword_922918 = 27;
  dword_92291C = 0;
  dword_922928 = 28;
  dword_92292C = 0;
  dword_922930 = 29;
  dword_922934 = 0;
  dword_922938 = 30;
  unk_92293C = 0;
  unk_922940 = 31;
  unk_922944 = 0;
  unk_922948 = 32;
  unk_92294C = 0;
  unk_922950 = 33i64;
  unk_922958 = 34;
  unk_92295C = 0;
  unk_922960 = 35;
  dword_922964 = 0;
  SeExports = (int)&SepExports;
  SepInitializeSessionLowboxStructures();
  if ( SepInitializeSharedSidMap() >= 0 )
    result = 1;
  else
LABEL_60:
    result = 0;
  return result;
}
