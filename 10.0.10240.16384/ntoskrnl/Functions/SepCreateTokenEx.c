// SepCreateTokenEx 
 
int __fastcall SepCreateTokenEx(int *a1, char a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, unsigned __int16 **a9, unsigned int a10, int a11, unsigned int a12, unsigned int a13, int a14, unsigned __int16 *a15, unsigned __int16 *a16, int a17, _DWORD *a18, int a19, int a20, int a21, int a22, _DWORD *a23, char a24)
{
  int v24; // r10
  unsigned int v25; // r7
  int v26; // r5
  int v27; // r9
  int v28; // r4
  unsigned __int16 *v29; // r6
  unsigned int v30; // r8
  unsigned int *v31; // r9
  unsigned int v32; // r4
  unsigned int *v33; // r5
  unsigned int *v34; // r10
  unsigned __int16 *v35; // t1
  unsigned __int16 **v36; // r6
  unsigned __int16 *v37; // r4
  unsigned __int16 *v38; // r3
  int v39; // r1
  int v40; // r6
  int *v41; // r5
  int v42; // r9
  int v43; // r4
  int v44; // r3
  int v45; // r8
  int v46; // t1
  __int64 v47; // r0
  int v48; // r6
  int v49; // r5
  int v50; // r8
  int v51; // r10
  unsigned int *v52; // r0
  unsigned int v53; // r3
  unsigned int v54; // r2
  int v55; // r0
  int v56; // r4
  _DWORD *v57; // r0
  _DWORD *v58; // r9
  int v59; // r5
  unsigned int v60; // r4
  unsigned int v61; // r10
  int v62; // r1
  int v63; // r5
  int v64; // r0
  _DWORD *v65; // r2
  int v66; // r3
  int v67; // r2
  int v68; // r1
  int v69; // r2
  int v70; // r3
  int v71; // r1
  int v72; // r2
  int v73; // r0
  int v74; // r3
  int v75; // r2
  int v76; // r3
  int v77; // r2
  int v78; // r0
  int v79; // r0
  int v80; // r6
  unsigned __int16 *v81; // r7
  int v82; // r4
  int v83; // r3
  int v84; // r0
  int result; // r0
  int v86; // r2
  int v87; // r3
  int v88; // r3
  int v89; // r3
  int v90; // r3
  char v91[4]; // [sp+18h] [bp-1D8h] BYREF
  unsigned int v92; // [sp+1Ch] [bp-1D4h]
  int v93; // [sp+20h] [bp-1D0h]
  int v94; // [sp+24h] [bp-1CCh]
  int v95; // [sp+28h] [bp-1C8h]
  unsigned int v96; // [sp+2Ch] [bp-1C4h]
  unsigned int *v97; // [sp+30h] [bp-1C0h]
  unsigned __int16 *v98; // [sp+34h] [bp-1BCh]
  int v99; // [sp+38h] [bp-1B8h]
  unsigned __int16 **v100; // [sp+3Ch] [bp-1B4h]
  int v101; // [sp+40h] [bp-1B0h]
  int *v102; // [sp+44h] [bp-1ACh]
  int v103; // [sp+48h] [bp-1A8h]
  int v104; // [sp+4Ch] [bp-1A4h]
  int v105; // [sp+50h] [bp-1A0h]
  _DWORD *v106; // [sp+54h] [bp-19Ch]
  unsigned int v107; // [sp+58h] [bp-198h]
  int v108; // [sp+5Ch] [bp-194h]
  int v109; // [sp+60h] [bp-190h]
  int v110; // [sp+64h] [bp-18Ch]
  int v111; // [sp+68h] [bp-188h]
  int v112; // [sp+6Ch] [bp-184h]
  int v113; // [sp+70h] [bp-180h] BYREF
  int v114; // [sp+74h] [bp-17Ch]
  int v115; // [sp+78h] [bp-178h]
  int v116; // [sp+7Ch] [bp-174h]
  int v117; // [sp+80h] [bp-170h]
  int v118[2]; // [sp+88h] [bp-168h] BYREF
  char v119[120]; // [sp+90h] [bp-160h] BYREF
  char v120[232]; // [sp+108h] [bp-E8h] BYREF

  v116 = a4;
  v102 = a1;
  v106 = (_DWORD *)a7;
  v100 = a9;
  v98 = a16;
  v112 = a19;
  v24 = a11;
  v114 = a3;
  v111 = a20;
  v25 = a10;
  v115 = a22;
  v99 = 0;
  v104 = -1;
  v96 = 0;
  v97 = (unsigned int *)a14;
  v109 = a17;
  v26 = 0;
  v91[0] = 0;
  v94 = 0;
  v95 = 0;
  v27 = 0;
  v93 = 0;
  v108 = 0;
  v117 = a2;
  v101 = a11;
  v28 = SeCaptureObjectAttributeSecurityDescriptorPresent(a4, a2, v91);
  if ( v28 < 0 )
    return v28;
  v29 = *a9;
  v30 = 0;
  v92 = 0;
  if ( a10 )
  {
    v31 = (unsigned int *)a11;
    do
    {
      v32 = v30;
      if ( v30 < v25 )
      {
        v33 = v31;
        v34 = (unsigned int *)(v24 + 8 * v25);
        do
        {
          if ( *v29 == *(unsigned __int16 *)*v33
            && !memcmp((unsigned int)v29, *v33, 4 * (*((unsigned __int8 *)v29 + 1) + 2))
            && (v33[1] & 0x20) == 0 )
          {
            v34 -= 2;
            --v25;
            *v33 = *v34;
            v33[1] = v34[1];
          }
          else
          {
            ++v32;
            v33 += 2;
          }
        }
        while ( v32 < v25 );
        v30 = v92;
        v24 = v101;
      }
      ++v30;
      v35 = (unsigned __int16 *)*v31;
      v31 += 2;
      v29 = v35;
      v92 = v30;
    }
    while ( v30 < v25 );
    v26 = 0;
    v27 = 0;
  }
  v36 = v100;
  v37 = *v100;
  if ( RtlEqualSid(v98, *v100) )
  {
    v26 = 1;
    v94 = 1;
  }
  if ( a15 )
  {
    if ( RtlEqualSid(a15, v37) )
      return sub_51D508();
  }
  else
  {
    v99 = 0;
    v27 = 1;
    v93 = 1;
  }
  v38 = v36[1];
  if ( ((unsigned __int8)v38 & 0x10) != 0 )
  {
    if ( ((unsigned __int8)v38 & 6) != 0 )
      return -1073741811;
    v39 = 2048;
    v95 = 2048;
  }
  else
  {
    v39 = 0;
  }
  v40 = 0;
  if ( v25 )
  {
    v41 = (int *)v24;
    v42 = SeUntrustedMandatorySid;
    while ( 1 )
    {
      v43 = v41[1];
      if ( (v43 & 1) != 0 )
      {
        v44 = v43 | 6;
        LOBYTE(v43) = v43 | 6;
        v41[1] = v44;
      }
      if ( (v43 & 0x10) != 0 )
      {
        if ( (v43 & 6) != 0 )
          return -1073741811;
        v95 = v39 | 0x800;
      }
      v46 = *v41;
      v41 += 2;
      v45 = v46;
      RtlIdentifierAuthoritySid(v46);
      v47 = RtlIdentifierAuthoritySid(v42);
      if ( !memcmp(v47, HIDWORD(v47), 6) )
      {
        v86 = *(unsigned __int8 *)(v45 + 1);
        if ( *(_BYTE *)(v45 + 1) && *(_DWORD *)(v45 + 4 * v86 + 4) > 0x4000u )
          return -1073740730;
        if ( (v43 & 0x40) != 0 )
        {
          if ( v104 != -1 )
            return -1073741811;
          v104 = v40 + 1;
          if ( v86 && *(_DWORD *)(v45 + 4 * v86 + 4) >= 0x3000u )
          {
            v96 = 1;
            v95 |= 0x2000u;
          }
          else
          {
            v96 = 0;
            if ( v86 && *(_DWORD *)(v45 + 4 * v86 + 4) >= 0x2000u )
              v95 |= 0x2000u;
            else
              v108 = 1;
          }
        }
      }
      if ( !v94 )
        v94 = RtlEqualSid(v98, (unsigned __int16 *)v45);
      if ( !v93 && RtlEqualSid(a15, (unsigned __int16 *)v45) )
      {
        if ( (*(v41 - 1) & 8) == 0 )
          return -1073741734;
        v99 = v40 + 1;
        v93 = 1;
      }
      if ( ++v40 >= v25 )
      {
        v27 = v93;
        v26 = v94;
        break;
      }
      v39 = v95;
    }
  }
  if ( !v26 )
    return -1073741733;
  if ( !v27 )
    return -1073741734;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v93 = 0;
  v94 = 0;
  v51 = 0;
  v105 = 0;
  v103 = 0;
  if ( a13 )
  {
    do
    {
      v52 = v97;
      v53 = v97[2];
      if ( (v53 & 0x7FFFFFF8) != 0 )
        return -1073741811;
      v97[2] &= 3u;
      v54 = *v52;
      v97 = v52 + 3;
      if ( v54 > 0x23 )
        return -1073741728;
      v55 = 1 << (v54 - 32);
      v56 = 1 << v54;
      if ( v55 & v50 | (1 << v54) & v48 )
        return -1073741402;
      v48 |= v56;
      v50 |= v55;
      if ( (v53 & 2) != 0 )
      {
        v94 |= v56;
        v93 |= v55;
      }
      if ( (v53 & 1) != 0 )
      {
        v51 |= v56;
        v105 = v51;
        v103 |= v55;
      }
    }
    while ( ++v49 < a13 );
  }
  if ( a23 && (*a23 & 0xFFFFFFFC) != 0 )
    return -1073741811;
  v57 = (_DWORD *)ExAllocatePoolWithTag(1, 24, 1950442835);
  v58 = v57;
  if ( !v57 )
    return -1073741670;
  *v57 = 0;
  v57[1] = v57 + 1;
  v57[2] = v57 + 1;
  v57[3] = 0;
  v57[4] = v57 + 4;
  v57[5] = v57 + 4;
  ExAllocateLocallyUniqueId(v118);
  v59 = ExAllocatePoolWithTag(512, 56, 1817470291);
  v110 = v59;
  if ( !v59 )
  {
    ExFreePoolWithTag(v58, 0);
    return -1073741670;
  }
  if ( SepTokenSidSharingEnabled )
  {
    v60 = (8 * v25 + 11) & 0xFFFFFFFC;
    v107 = a12;
  }
  else
  {
    v107 = (a12 + 3) & 0xFFFFFFFC;
    v60 = ((8 * v25 + 3) & 0xFFFFFFFC)
        + ((RtlLengthRequiredSid(*((unsigned __int8 *)*v100 + 1)) + 3) & 0xFFFFFFFC)
        + v107
        + 8;
  }
  v92 = v60;
  v61 = (RtlLengthRequiredSid(*((unsigned __int8 *)v98 + 1)) + 3) & 0xFFFFFFFC;
  if ( v109 )
    v61 += (*(unsigned __int16 *)(v109 + 2) + 3) & 0xFFFFFFFC;
  if ( v61 >= 0x1000 )
    v62 = v60 + 656 + v61;
  else
    v62 = v60 + 4752;
  v97 = (unsigned int *)v62;
  v28 = ObCreateObject(v117, SeTokenObjectType, v116, 1, 0, v60 + 656, v62, 0, &v113);
  if ( v28 < 0 )
  {
    ExFreePoolWithTag(v58, 0);
    ExFreePoolWithTag(v59, 0);
    return v28;
  }
  v63 = v113;
  v64 = v110;
  *(_DWORD *)(v113 + 48) = v110;
  ExInitializeResourceLite(v64);
  ExAllocateLocallyUniqueId((int *)(v63 + 16));
  *(_DWORD *)(v63 + 32) = 0;
  *(_DWORD *)(v63 + 36) = 0;
  *(_DWORD *)(v63 + 196) = 0;
  v65 = v106;
  *(_DWORD *)(v63 + 200) = 0;
  *(_DWORD *)(v63 + 24) = *v65;
  v66 = v118[0];
  *(_DWORD *)(v63 + 28) = v65[1];
  v67 = v118[1];
  *(_BYTE *)(v63 + 180) = 0;
  *(_DWORD *)(v63 + 52) = v66;
  *(_DWORD *)(v63 + 56) = v67;
  *(_DWORD *)(v63 + 40) = *a8;
  *(_DWORD *)(v63 + 44) = a8[1];
  *(_DWORD *)(v63 + 168) = a5;
  *(_DWORD *)(v63 + 172) = a6;
  v68 = a18[1];
  v69 = a18[2];
  v70 = a18[3];
  *(_DWORD *)v63 = *a18;
  *(_DWORD *)(v63 + 4) = v68;
  *(_DWORD *)(v63 + 8) = v69;
  *(_DWORD *)(v63 + 12) = v70;
  v71 = v92;
  v72 = (int)v97;
  *(_DWORD *)(v63 + 176) = v95;
  v73 = v99;
  *(_DWORD *)(v63 + 120) = 0;
  *(_DWORD *)(v63 + 136) = v72 - (v71 + 656);
  *(_DWORD *)(v63 + 140) = 0;
  v74 = v104;
  *(_DWORD *)(v63 + 144) = v73;
  *(_DWORD *)(v63 + 164) = 0;
  *(_DWORD *)(v63 + 648) = 0;
  *(_DWORD *)(v63 + 652) = 0;
  *(_DWORD *)(v63 + 132) = v71;
  *(_QWORD *)(v63 + 184) = (unsigned int)v74;
  v75 = v93;
  v76 = v94;
  *(_DWORD *)(v63 + 64) = v48;
  *(_DWORD *)(v63 + 68) = v50;
  *(_DWORD *)(v63 + 72) = v76;
  *(_DWORD *)(v63 + 76) = v75;
  v77 = v103;
  *(_DWORD *)(v63 + 80) = v105;
  *(_DWORD *)(v63 + 84) = v77;
  *(_DWORD *)(v63 + 484) = 0;
  *(_DWORD *)(v63 + 488) = 0;
  *(_DWORD *)(v63 + 480) = 0;
  *(_DWORD *)(v63 + 628) = 0;
  *(_DWORD *)(v63 + 632) = 0;
  memset((_BYTE *)(v63 + 492), 0, 136);
  *(_DWORD *)(v63 + 640) = 0;
  *(_DWORD *)(v63 + 644) = 0;
  if ( a23 )
    *(_DWORD *)(v63 + 188) = *a23;
  if ( !v96 )
  {
    v87 = *(_DWORD *)(v63 + 76);
    *(_DWORD *)(v63 + 72) &= 0xDFE9F97B;
    *(_DWORD *)(v63 + 76) = v87 & 0xFFFFFFFE;
    v88 = *(_DWORD *)(v63 + 84);
    *(_DWORD *)(v63 + 80) &= 0xDFE9F97B;
    *(_DWORD *)(v63 + 84) = v88 & 0xFFFFFFFE;
  }
  if ( v108 == 1 )
  {
    v89 = *(_DWORD *)(v63 + 76);
    *(_DWORD *)(v63 + 72) &= 0x2800000u;
    *(_DWORD *)(v63 + 76) = v89 & 2;
    v90 = *(_DWORD *)(v63 + 84);
    *(_DWORD *)(v63 + 80) &= 0x2800000u;
    *(_DWORD *)(v63 + 84) = v90 & 2;
  }
  memset((_BYTE *)(v63 + 88), 0, 31);
  v78 = (int)v106;
  *(_DWORD *)(v63 + 476) = v58;
  *(_DWORD *)(v63 + 636) = 0;
  *(_DWORD *)(v63 + 160) = 0;
  v28 = SepReferenceLogonSession(v78, v63 + 192);
  if ( v28 < 0 )
  {
    *(_DWORD *)(v63 + 176) |= 0x20u;
    *(_DWORD *)(v63 + 192) = 0;
    goto LABEL_70;
  }
  if ( SepTokenSidSharingEnabled )
  {
    v28 = SepSetTokenUserAndGroups(v63, v100, v25, v101, v107);
    if ( v28 < 0 )
      goto LABEL_70;
  }
  else
  {
    *(_DWORD *)(v63 + 148) = v63 + 656;
    *(_DWORD *)(v63 + 124) = v25 + 1;
    v96 = v63 + 656 + 8 * v25 + 8;
    v92 = v92 - 8 * v25 - 8;
    RtlCopySidAndAttributesArray(1, v100);
    RtlCopySidAndAttributesArray(v25, v101);
  }
  RtlSidHashInitialize(*(int **)(v63 + 148), *(_DWORD *)(v63 + 124), v63 + 204);
  *(_DWORD *)(v63 + 152) = 0;
  *(_DWORD *)(v63 + 128) = 0;
  v79 = ExAllocatePoolWithTag(1, v61, 1683252563);
  v80 = v79;
  *(_DWORD *)(v63 + 160) = v79;
  if ( !v79 )
  {
    ObfDereferenceObjectWithTag(v63);
    return -1073741801;
  }
  v81 = v98;
  *(_DWORD *)(v63 + 156) = v79;
  v82 = RtlLengthRequiredSid(*((unsigned __int8 *)v81 + 1));
  RtlCopySid(v82, v80, v81);
  v83 = v109;
  v84 = ((v82 + 3) & 0xFFFFFFFC) + v80;
  if ( v109 )
  {
    *(_DWORD *)(v63 + 164) = v84;
    memmove(v84, v83, *(unsigned __int16 *)(v83 + 2));
  }
  v28 = SepSetTokenClaims(v63, v112, v111, a21, v115);
  if ( v28 < 0 )
    goto LABEL_70;
  if ( !a24 )
  {
    v28 = SeCreateAccessState(v119, v120, v114, SeTokenObjectType + 52);
    if ( v28 >= 0 )
    {
      v28 = ObInsertObject(v63, v119, 0, 1, 0, v102);
      SeDeleteAccessState(v119);
      if ( v28 < 0 )
        return v28;
      if ( !v91[0] )
        SepAppendAdminAceToTokenAcl(v63);
    }
    goto LABEL_70;
  }
  v28 = SepSetTokenTrust(v63, SeProcTrustWinTcbSid);
  if ( v28 < 0 )
  {
LABEL_70:
    ObfDereferenceObjectWithTag(v63);
    return v28;
  }
  if ( *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244) )
    v28 = ObInsertObject(v63, 0, 0, 0, 0, 0);
  if ( v28 < 0 )
  {
    *v102 = 0;
    return v28;
  }
  if ( !v91[0] )
    SepAppendAdminAceToTokenAcl(v63);
  result = v28;
  *v102 = v63;
  return result;
}
