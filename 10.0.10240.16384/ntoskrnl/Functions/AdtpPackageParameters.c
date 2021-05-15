// AdtpPackageParameters 
 
int __fastcall AdtpPackageParameters(_DWORD *a1, int a2, int a3, _WORD *a4, int a5)
{
  int v5; // r10
  unsigned int v7; // r5
  unsigned int v8; // r9
  int v9; // r6
  _DWORD *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r3
  _DWORD *v13; // r7
  int v14; // r2
  int v15; // r0
  unsigned __int16 v16; // r3
  int v17; // r4
  int v18; // r0
  _DWORD *v19; // r2
  BOOL v20; // r9
  BOOL v21; // r4
  int *v22; // r1
  _DWORD *v23; // r10
  int v24; // r4
  char *v25; // r0
  int v26; // r3
  int v27; // r3
  char **v28; // r2
  int v29; // r7
  int v30; // r0
  int v31; // r2
  int v32; // r3
  int v33; // r1
  int v34; // r0
  int v35; // r2
  int v36; // r3
  _DWORD *v37; // r3
  _DWORD *v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r4
  __int16 v42; // r1
  _DWORD *v43; // r2
  int v44; // r4
  unsigned int v45; // r9
  _DWORD *v46; // r3
  int v47; // r1
  unsigned int v48; // r3
  unsigned int v49; // r3
  void *v50; // r2
  int v51; // r1
  int result; // r0
  unsigned int *v53; // r0
  int v54; // r4
  unsigned int v55; // r3
  _DWORD *v56; // r1
  _DWORD *v57; // r0
  _DWORD *v58; // r2
  int v59; // r3
  _DWORD *v60; // r3
  int v61; // r1
  _DWORD *v62; // r2
  int v63; // r3
  _DWORD *v64; // r2
  int v65; // r3
  int v66; // r1
  _DWORD *v67; // r2
  int v68; // r3
  int v69; // r1
  int v70; // r1
  unsigned int v71; // r2
  unsigned int v72; // r1
  _DWORD *v73; // r1
  char v74[4]; // [sp+20h] [bp-8F0h] BYREF
  int v75; // [sp+24h] [bp-8ECh] BYREF
  char v76; // [sp+28h] [bp-8E8h] BYREF
  char v77[3]; // [sp+29h] [bp-8E7h] BYREF
  unsigned int v78; // [sp+2Ch] [bp-8E4h]
  unsigned int v79; // [sp+30h] [bp-8E0h]
  int v80; // [sp+34h] [bp-8DCh]
  _DWORD *v81; // [sp+38h] [bp-8D8h]
  char *v82; // [sp+40h] [bp-8D0h] BYREF
  _WORD *v83; // [sp+48h] [bp-8C8h]
  __int16 v84; // [sp+50h] [bp-8C0h] BYREF
  char v85[158]; // [sp+52h] [bp-8BEh] BYREF
  __int16 v86; // [sp+F0h] [bp-820h] BYREF
  char v87[2046]; // [sp+F2h] [bp-81Eh] BYREF

  v5 = a5;
  v83 = a4;
  v80 = a5;
  v81 = a1;
  v7 = 0;
  v8 = 0;
  v79 = 0;
  v9 = 0;
  v86 = 0;
  memset(v87, 0, sizeof(v87));
  v84 = 0;
  memset(v85, 0, sizeof(v85));
  v10 = v81;
  v75 = 0;
  v11 = v81[2];
  v12 = 2;
  v78 = 2;
  if ( v11 <= 2 )
    goto LABEL_66;
  while ( v7 < 0x2A && v8 < 0xE )
  {
    v13 = &v10[5 * v12];
    v14 = v13[6];
    switch ( v14 )
    {
      case 0:
        AdtpEtwBuildDashString(a3 + 16 * v7, &AdtpNullSid);
        goto LABEL_7;
      case 1:
        if ( !AdtpIsCorrectlyFormedUnicodeString(v13[10]) )
          goto LABEL_65;
        v15 = AdtpEtwBuildString(a3 + 16 * v7, v47, &v86, &v75, v5 + v7);
        goto LABEL_6;
      case 2:
        v17 = v13[10];
        if ( !AdtpIsCorrectlyFormedUnicodeString(v17) )
          goto LABEL_65;
        AdtpSubstituteDriveLetter(v17);
        v18 = AdtpEtwBuildString(a3 + 16 * v7, v17, &v86, &v75, v5 + v7);
        goto LABEL_13;
      case 3:
        v15 = AdtpBuildUlongString(v13[8], 0, a3 + 16 * v7, &v86, &v75, v5 + v7);
        goto LABEL_6;
      case 4:
        v44 = v13[10];
        v45 = 4 * (*(unsigned __int8 *)(v44 + 1) + 2);
        if ( v13[7] < v45 || !RtlValidSid(v13[10], &AdtpNullSid) )
        {
          v9 = -1073741704;
          goto LABEL_66;
        }
        v46 = (_DWORD *)(a3 + 16 * v7);
        v46[1] = 0;
        v46[2] = v45;
        v8 = v79;
        *v46 = v44;
        v46[3] = 0;
LABEL_7:
        v16 = v7 + 1;
LABEL_8:
        v7 = v16;
LABEL_9:
        v10 = v81;
        if ( ++v78 >= v81[2] )
          goto LABEL_66;
        v12 = v78;
        break;
      case 5:
      case 26:
      case 33:
      case 35:
        v77[0] = 0;
        v76 = 0;
        v74[0] = 0;
        v20 = v14 == 33;
        v21 = v14 == 35;
        v82 = 0;
        if ( v14 == 35 )
          v22 = (int *)&v82;
        else
          v22 = 0;
        v23 = v13 + 8;
        v9 = AdtpBuildLogonIdStrings(v13 + 8, v22, v77, &v84 + 4 * v79, &v76, &v85[8 * v79 + 6], v74);
        if ( v21 )
        {
          v24 = (unsigned __int8)v77[0];
          v25 = v82;
        }
        else
        {
          v24 = 0;
          v25 = (char *)v81[10];
        }
        if ( v9 < 0 )
          goto LABEL_66;
        v26 = v13[6];
        if ( v26 == 5 || v26 == 35 )
        {
          if ( !v25 )
          {
            LOBYTE(v24) = 0;
            v25 = &AdtpNullSid;
          }
          v27 = (unsigned __int8)v25[1];
          v28 = (char **)(a3 + 16 * v7);
          *v28 = v25;
          goto LABEL_26;
        }
        if ( v20 )
        {
          v70 = v13[10];
          v28 = (char **)(a3 + 16 * v7);
          v27 = *(unsigned __int8 *)(v70 + 1);
          *v28 = (char *)v70;
LABEL_26:
          v29 = v80;
          v28[1] = 0;
          v28[2] = (char *)(4 * (v27 + 2));
          v28[3] = 0;
          *(_BYTE *)(v29 + v7) = v24;
          v7 = (unsigned __int16)(v7 + 1);
          goto LABEL_27;
        }
        if ( v24 && v25 )
          ExFreePoolWithTag(v25, 0);
        v29 = v80;
LABEL_27:
        v30 = v79;
        v31 = a3 + 16 * v7;
        *(_QWORD *)v31 = *((unsigned int *)&v84 + 2 * v79 + 1);
        v32 = (unsigned __int16)*(&v84 + 4 * v30);
        *(_DWORD *)(v31 + 12) = 0;
        *(_DWORD *)(v31 + 8) = v32 + 2;
        *(_BYTE *)(v29 + v7) = v76;
        v33 = (unsigned __int16)(v7 + 1);
        v34 = (unsigned __int16)(v30 + 1);
        v35 = a3 + 16 * v33;
        *(_QWORD *)v35 = *((unsigned int *)&v84 + 2 * v34 + 1);
        v36 = (unsigned __int16)*(&v84 + 4 * v34);
        *(_DWORD *)(v35 + 12) = 0;
        *(_DWORD *)(v35 + 8) = v36 + 2;
        *(_BYTE *)(v29 + v33) = v74[0];
        v8 = (unsigned __int16)(v34 + 1);
        v37 = (_DWORD *)(a3 + 16 * (unsigned __int16)(v7 + 2));
        *v37 = v23;
        v37[1] = 0;
        v5 = v80;
        v37[2] = 8;
        v37[3] = 0;
        v16 = v7 + 3;
        v79 = v8;
        goto LABEL_8;
      case 6:
        v38 = (_DWORD *)(a3 + 16 * v7);
        v39 = 4 * ((unsigned __int8)byte_9278D9 + 2);
        v38[1] = 0;
        v38[2] = v39;
        *v38 = &AdtpNullSid;
        v40 = (unsigned __int16)(v7 + 1);
        v38[3] = 0;
        v41 = 2;
        do
        {
          AdtpEtwBuildDashString(a3 + 16 * v40, v40);
          v40 = (unsigned __int16)(v42 + 1);
          --v41;
        }
        while ( v41 );
        v43 = (_DWORD *)(a3 + 16 * v40);
        *v43 = &AdtpNullLuid;
        v43[2] = 8;
        v16 = v40 + 1;
        goto LABEL_31;
      case 7:
        v48 = v13[9];
        if ( v48 >= v78 )
          goto LABEL_65;
        v56 = &v81[5 * v48];
        if ( v56[6] != 1 )
          goto LABEL_65;
        v15 = AdtpBuildAccessesString(v81[15], v56[10], v13[8]);
        goto LABEL_6;
      case 8:
        v53 = (unsigned int *)v13[10];
        if ( !v53 )
          goto LABEL_65;
        v71 = *v53;
        v72 = *v53 ? 12 * (v71 - 1) + 20 : 8;
        if ( v13[7] < v72 || v71 && v71 > 0x41 )
          goto LABEL_65;
        v15 = AdtpBuildPrivilegeAuditString(v53, 0);
        goto LABEL_6;
      case 9:
        v49 = v13[9];
        if ( v49 >= v78 )
          goto LABEL_65;
        v57 = &v81[5 * v49];
        if ( v57[6] != 1 )
          goto LABEL_65;
        AdtpBuildObjectTypeStrings(v81[15], v57[10], v13[10], v13[7] / 0x18u, &v84 + 4 * v8, v5 + v7);
        v58 = (_DWORD *)(a3 + 16 * v7);
        *v58 = *((_DWORD *)&v84 + 2 * v8 + 1);
        v58[1] = 0;
        v59 = (unsigned __int16)*(&v84 + 4 * v8);
        v58[3] = 0;
        v58[2] = v59 + 2;
        v8 = (unsigned __int16)(v8 + 1);
        v79 = v8;
        goto LABEL_7;
      case 10:
      case 11:
      case 27:
        v19 = (_DWORD *)(a3 + 16 * v7);
        *v19 = v13 + 8;
        v19[1] = 0;
        v19[2] = 4;
        v19[3] = 0;
        goto LABEL_16;
      case 12:
      case 14:
      case 15:
      case 18:
        return sub_552C08(&v84, &AdtpNullSid);
      case 13:
        v50 = (void *)v13[10];
        if ( !v50 )
          v50 = &AdtpNullGuid;
        v60 = (_DWORD *)(a3 + 16 * v7);
        *v60 = v50;
        v60[1] = 0;
        v60[2] = 16;
        v60[3] = 0;
LABEL_16:
        v16 = v7 + 1;
        goto LABEL_8;
      case 16:
        v15 = AdtpBuildStringListString(v13[10], &AdtpNullSid, a3 + 16 * v7, &v86, &v75, v5 + v7);
        goto LABEL_6;
      case 17:
        v15 = AdtpBuildSidListString(v13[10], &AdtpNullSid, a3 + 16 * v7, &v86, &v75, v5 + v7);
        goto LABEL_6;
      case 19:
        v9 = AdtpBuildUserAccountControlString(v13[8], v13[9], &v84 + 4 * v8);
        if ( v9 < 0 )
          goto LABEL_66;
        v61 = 3;
        do
        {
          v62 = (_DWORD *)(a3 + 16 * v7);
          *v62 = *((_DWORD *)&v84 + 2 * v8 + 1);
          v62[1] = 0;
          v63 = (unsigned __int16)*(&v84 + 4 * v8);
          v62[3] = 0;
          v62[2] = v63 + 2;
          v8 = (unsigned __int16)(v8 + 1);
          v7 = (unsigned __int16)(v7 + 1);
          --v61;
        }
        while ( v61 );
        v79 = v8;
        goto LABEL_9;
      case 20:
        v51 = 3;
        do
        {
          AdtpEtwBuildDashString(a3 + 16 * v7, v51);
          v7 = (unsigned __int16)(v7 + 1);
          v51 = v66 - 1;
        }
        while ( v51 );
        goto LABEL_9;
      case 21:
        v15 = AdtpBuildMessageString(v13[8], &AdtpNullSid, a3 + 16 * v7, &v86, &v75, v5 + v7);
        goto LABEL_6;
      case 23:
        v9 = AdtpBuildSockAddrString(v13[10], &v84 + 4 * v8, v5 + v7);
        if ( v9 < 0 )
          goto LABEL_66;
        v67 = (_DWORD *)(a3 + 16 * v7);
        *v67 = *((_DWORD *)&v84 + 2 * v8 + 1);
        v67[1] = 0;
        v68 = (unsigned __int16)*(&v84 + 4 * v8);
        v67[3] = 0;
        v67[2] = v68 + 2;
        v69 = (unsigned __int16)(v8 + 1);
        v43 = (_DWORD *)(a3 + 16 * (unsigned __int16)(v7 + 1));
        *v43 = *((_DWORD *)&v84 + 2 * v69 + 1);
        v43[2] = (unsigned __int16)*(&v84 + 4 * v69) + 2;
        v8 = (unsigned __int16)(v8 + 2);
        v79 = v8;
        v16 = v7 + 2;
LABEL_31:
        v43[3] = 0;
        v43[1] = 0;
        goto LABEL_8;
      case 24:
        v9 = AdtpBuildSecurityDescriptorChangeString(v13[8], v13[10], v13[15]);
        ++v78;
        if ( v9 < 0 )
          goto LABEL_66;
        v16 = v7 + 2;
        goto LABEL_8;
      case 28:
        v9 = AdtpBuildSockAddrString(v13[10], &v84 + 4 * v8, v5 + v7);
        if ( v9 < 0 )
          goto LABEL_66;
        v64 = (_DWORD *)(a3 + 16 * v7);
        *v64 = *((_DWORD *)&v84 + 2 * v8 + 1);
        v64[1] = 0;
        v65 = (unsigned __int16)*(&v84 + 4 * v8);
        v64[3] = 0;
        v64[2] = v65 + 2;
        v7 = (unsigned __int16)(v7 + 1);
        v8 = (unsigned __int16)(v8 + 1);
        v79 = v8;
        goto LABEL_9;
      case 29:
        goto LABEL_64;
      case 30:
        if ( v13[8] || v13[9] )
          goto LABEL_65;
LABEL_64:
        v54 = v13[10];
        v55 = *(_DWORD *)(v54 + 132);
        if ( v55 >= v78 )
          goto LABEL_65;
        v73 = &v81[5 * v55];
        if ( v73[6] != 1 )
          goto LABEL_65;
        v18 = AdtpBuildAccessReasonAuditString(v81[15], v73[10], v54, v14 == 30);
LABEL_13:
        v9 = v18;
        if ( v18 >= 0 )
          goto LABEL_7;
        goto LABEL_66;
      case 31:
        if ( v13[8] != 32 || v13[9] )
          goto LABEL_65;
        v15 = AdtpBuildSecurityDescriptorUnicodeString(32, v13[10], 0, a3 + 16 * v7, &v86, &v75, v5 + v7);
        goto LABEL_6;
      case 34:
        v15 = AdtpBuildMultiSzStringListString(v13[10], a3 + 16 * v7, v5 + v7);
LABEL_6:
        v9 = v15;
        if ( v15 >= 0 )
          goto LABEL_7;
        goto LABEL_66;
      default:
        goto LABEL_65;
    }
  }
LABEL_65:
  v9 = -1073741811;
LABEL_66:
  result = v9;
  *v83 = v7;
  return result;
}
