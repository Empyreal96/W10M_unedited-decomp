// SeMakeSystemToken 
 
int *SeMakeSystemToken()
{
  int v0; // r3
  unsigned __int16 *v1; // r10
  unsigned int v2; // r2
  int v3; // r3
  int v4; // r4
  int v5; // r0
  unsigned int v6; // r7
  int v7; // r5
  int v8; // r0
  unsigned __int8 *v9; // r6
  _BYTE *v11; // r0
  int v12; // r5
  int v13; // r4
  int v14; // r1
  int v15; // r2
  int v16; // [sp+0h] [bp-418h]
  int v17; // [sp+4h] [bp-414h]
  int v18; // [sp+40h] [bp-3D8h] BYREF
  int v19; // [sp+44h] [bp-3D4h]
  __int16 v20; // [sp+48h] [bp-3D0h]
  __int16 v21; // [sp+4Ah] [bp-3CEh]
  __int16 v22; // [sp+4Ch] [bp-3CCh]
  __int16 v23; // [sp+4Eh] [bp-3CAh]
  int *v24; // [sp+50h] [bp-3C8h] BYREF
  int v25; // [sp+54h] [bp-3C4h] BYREF
  unsigned __int16 *v26; // [sp+58h] [bp-3C0h]
  unsigned int v27; // [sp+5Ch] [bp-3BCh]
  int v28[6]; // [sp+60h] [bp-3B8h] BYREF
  __int64 v29; // [sp+78h] [bp-3A0h] BYREF
  int v30[6]; // [sp+80h] [bp-398h] BYREF
  __int64 v31; // [sp+98h] [bp-380h]
  int v32; // [sp+A0h] [bp-378h]
  int v33; // [sp+A4h] [bp-374h]
  int v34; // [sp+A8h] [bp-370h]
  int v35; // [sp+ACh] [bp-36Ch]
  int v36; // [sp+B0h] [bp-368h]
  int v37; // [sp+B4h] [bp-364h]
  int v38; // [sp+B8h] [bp-360h]
  int v39; // [sp+BCh] [bp-35Ch]
  int v40; // [sp+C0h] [bp-358h]
  int v41; // [sp+C4h] [bp-354h]
  int v42; // [sp+C8h] [bp-350h]
  int v43; // [sp+CCh] [bp-34Ch]
  int v44; // [sp+D0h] [bp-348h]
  int v45; // [sp+D4h] [bp-344h]
  int v46; // [sp+D8h] [bp-340h]
  int v47; // [sp+DCh] [bp-33Ch]
  int v48; // [sp+E0h] [bp-338h]
  int v49; // [sp+E4h] [bp-334h]
  int v50; // [sp+E8h] [bp-330h]
  int v51; // [sp+ECh] [bp-32Ch]
  int v52; // [sp+F0h] [bp-328h]
  int v53; // [sp+F4h] [bp-324h]
  int v54; // [sp+F8h] [bp-320h]
  int v55; // [sp+FCh] [bp-31Ch]
  int v56; // [sp+100h] [bp-318h]
  __int64 v57; // [sp+104h] [bp-314h]
  int v58; // [sp+10Ch] [bp-30Ch]
  int v59; // [sp+110h] [bp-308h]
  int v60; // [sp+114h] [bp-304h]
  int v61; // [sp+118h] [bp-300h]
  int v62; // [sp+11Ch] [bp-2FCh]
  int v63; // [sp+120h] [bp-2F8h]
  int v64; // [sp+124h] [bp-2F4h]
  int v65; // [sp+128h] [bp-2F0h]
  int v66; // [sp+12Ch] [bp-2ECh]
  int v67; // [sp+130h] [bp-2E8h]
  int v68; // [sp+134h] [bp-2E4h]
  int v69; // [sp+138h] [bp-2E0h]
  int v70; // [sp+13Ch] [bp-2DCh]
  int v71; // [sp+140h] [bp-2D8h]
  int v72; // [sp+144h] [bp-2D4h]
  int v73; // [sp+148h] [bp-2D0h]
  int v74; // [sp+14Ch] [bp-2CCh]
  int v75; // [sp+150h] [bp-2C8h]
  int v76; // [sp+154h] [bp-2C4h]
  int v77; // [sp+158h] [bp-2C0h]
  int v78; // [sp+15Ch] [bp-2BCh]
  int v79; // [sp+160h] [bp-2B8h]
  int v80; // [sp+164h] [bp-2B4h]
  int v81; // [sp+168h] [bp-2B0h]
  int v82; // [sp+16Ch] [bp-2ACh]
  int v83; // [sp+170h] [bp-2A8h]
  int v84; // [sp+174h] [bp-2A4h]
  int v85; // [sp+178h] [bp-2A0h]
  int v86; // [sp+17Ch] [bp-29Ch]
  int v87; // [sp+180h] [bp-298h]
  int v88; // [sp+184h] [bp-294h]
  int v89; // [sp+188h] [bp-290h]
  int v90; // [sp+18Ch] [bp-28Ch]
  int v91; // [sp+190h] [bp-288h]
  int v92; // [sp+194h] [bp-284h]
  int v93; // [sp+198h] [bp-280h]
  int v94; // [sp+19Ch] [bp-27Ch]
  int v95; // [sp+1A0h] [bp-278h]
  int v96; // [sp+1A4h] [bp-274h]
  int v97; // [sp+1A8h] [bp-270h]
  __int64 v98; // [sp+1ACh] [bp-26Ch]
  int v99; // [sp+1B4h] [bp-264h]
  int v100; // [sp+1B8h] [bp-260h]
  int v101; // [sp+1BCh] [bp-25Ch]
  int v102; // [sp+1C0h] [bp-258h]
  int v103; // [sp+1C4h] [bp-254h]
  int v104; // [sp+1C8h] [bp-250h]
  int v105; // [sp+1CCh] [bp-24Ch]
  int v106; // [sp+1D0h] [bp-248h]
  int v107; // [sp+1D4h] [bp-244h]
  int v108; // [sp+1D8h] [bp-240h]
  int v109; // [sp+1DCh] [bp-23Ch]
  int v110; // [sp+1E0h] [bp-238h]
  int v111; // [sp+1E4h] [bp-234h]
  _DWORD v112[136]; // [sp+1F8h] [bp-220h] BYREF

  v25 = 1;
  v18 = 68536;
  v19 = 65537;
  v20 = 1;
  v21 = 1;
  v22 = 1;
  v23 = 1;
  RtlTimeFieldsToTime((__int16 *)&v18, &v29);
  v19 = 0;
  v112[0] = SeAliasAdminsSid;
  v112[1] = 14;
  v112[3] = 7;
  v112[4] = SeAuthenticatedUsersSid;
  v112[5] = 7;
  v112[6] = SeSystemMandatorySid;
  v112[7] = 96;
  v0 = *(unsigned __int8 *)(SeAuthenticatedUsersSid + 1);
  v1 = (unsigned __int16 *)SeLocalSystemSid;
  v26 = (unsigned __int16 *)SeAliasAdminsSid;
  v2 = (4 * v0 + 11) & 0xFFFFFFFC;
  v3 = *(unsigned __int8 *)(SeSystemMandatorySid + 1);
  v18 = SeLocalSystemSid;
  v112[2] = SeWorldSid;
  v27 = ((4 * *(unsigned __int8 *)(SeWorldSid + 1) + 11) & 0xFFFFFFFC)
      + v2
      + ((4 * v3 + 11) & 0xFFFFFFFC)
      + ((4 * *(unsigned __int8 *)(SeAliasAdminsSid + 1) + 11) & 0xFFFFFFFC)
      + 8;
  v30[0] = SeTcbPrivilege;
  v30[1] = dword_9227BC;
  v30[2] = 3;
  v30[3] = SeCreateTokenPrivilege;
  v30[4] = dword_922A04;
  v30[5] = 0;
  v31 = SeTakeOwnershipPrivilege;
  v32 = 0;
  v33 = SeCreatePagefilePrivilege;
  v34 = dword_922BAC;
  v35 = 3;
  v36 = SeLockMemoryPrivilege;
  v37 = dword_922B7C;
  v38 = 3;
  v39 = SeAssignPrimaryTokenPrivilege;
  v40 = dword_9227D4;
  v41 = 0;
  v42 = SeIncreaseQuotaPrivilege;
  v43 = dword_922794;
  v44 = 0;
  v45 = SeIncreaseBasePriorityPrivilege;
  v46 = dword_9227C4;
  v47 = 3;
  v48 = SeCreatePermanentPrivilege;
  v49 = dword_9227A4;
  v50 = 3;
  v51 = SeDebugPrivilege;
  v52 = dword_922784;
  v53 = 3;
  v54 = SeAuditPrivilege;
  v55 = dword_9229DC;
  v56 = 3;
  v57 = SeSecurityPrivilege;
  v58 = 0;
  v59 = SeSystemEnvironmentPrivilege;
  v60 = dword_9229F4;
  v61 = 0;
  v62 = SeChangeNotifyPrivilege;
  v63 = dword_9229EC;
  v64 = 3;
  v65 = SeBackupPrivilege;
  v66 = dword_922BA4;
  v67 = 0;
  v68 = SeRestorePrivilege;
  v69 = dword_922B9C;
  v70 = 0;
  v71 = SeShutdownPrivilege;
  v72 = dword_922B8C;
  v73 = 0;
  v74 = SeLoadDriverPrivilege;
  v75 = dword_922B84;
  v76 = 0;
  v77 = SeProfileSingleProcessPrivilege;
  v78 = dword_922B94;
  v79 = 3;
  v80 = SeSystemtimePrivilege;
  v81 = dword_9229E4;
  v82 = 0;
  v83 = SeUndockPrivilege;
  v84 = dword_9229BC;
  v85 = 0;
  v86 = SeManageVolumePrivilege;
  v87 = dword_9229A4;
  v88 = 0;
  v89 = SeImpersonatePrivilege;
  v90 = dword_92299C;
  v91 = 3;
  v92 = SeCreateGlobalPrivilege;
  v93 = dword_92279C;
  v94 = 3;
  v95 = SeTrustedCredManAccessPrivilege;
  v96 = dword_9229B4;
  v97 = 0;
  v98 = SeRelabelPrivilege;
  v99 = 0;
  v100 = SeIncreaseWorkingSetPrivilege;
  v101 = dword_9227CC;
  v102 = 3;
  v103 = SeTimeZonePrivilege;
  v104 = dword_9229AC;
  v105 = 3;
  v106 = SeCreateSymbolicLinkPrivilege;
  v107 = dword_922994;
  v108 = 3;
  v109 = SeSystemProfilePrivilege;
  v110 = dword_922A0C;
  v111 = 3;
  v4 = *(unsigned __int8 *)(SeLocalSystemSid + 1) + 6;
  v5 = ExAllocatePoolWithTag(1, 4 * v4, 1665230163);
  v6 = v5;
  if ( !v5 )
    JUMPOUT(0x96C668);
  RtlCreateAcl(v5, 4 * v4, 2);
  v7 = *(unsigned __int8 *)(SeProcTrustWinTcbSid + 1) + 6;
  v8 = ExAllocatePoolWithTag(1, 4 * v7, 1665230163);
  v9 = (unsigned __int8 *)v8;
  if ( !v8 )
    return (int *)sub_96C660();
  RtlCreateAcl(v8, 4 * v7, 2);
  RtlAddAccessAllowedAce(v6, 2, 983551, SeLocalSystemSid);
  RtlAddProcessTrustLabelAce(v9, 2u, 0, (_BYTE *)SeProcTrustWinTcbSid, 20, 131096);
  v11 = (_BYTE *)ExAllocatePoolWithTag(1, 20, 1683187027);
  v12 = (int)v11;
  if ( !v11 )
  {
    ExFreePoolWithTag(v6);
    JUMPOUT(0x96C662);
  }
  RtlCreateSecurityDescriptor(v11, 1);
  RtlSetDaclSecurityDescriptor(v12, 1, v6, 0);
  RtlSetSaclSecurityDescriptor(v12, 1, (int)v9, 0);
  v13 = SeAliasAdminsSid;
  RtlSetOwnerSecurityDescriptor(v12, SeAliasAdminsSid, 0);
  RtlSetGroupSecurityDescriptor(v12, v13, 0);
  v28[0] = 24;
  v28[1] = 0;
  v28[2] = 0;
  v28[3] = 0;
  v28[4] = v12;
  v28[5] = 0;
  SepCreateToken(
    (int *)&v24,
    v14,
    v15,
    (int)v28,
    v16,
    v17,
    (int)SeSystemAuthenticationId,
    &v29,
    (unsigned __int16 **)&v18,
    4u,
    (int)v112,
    v27,
    0x1Eu,
    (int)v30,
    v26,
    v1,
    SeSystemDefaultDacl);
  SeSetMandatoryPolicyToken(v24, &v25);
  ExFreePoolWithTag(v6);
  ExFreePoolWithTag((unsigned int)v9);
  ExFreePoolWithTag(v12);
  return v24;
}
