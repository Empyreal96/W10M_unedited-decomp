// SeAccessCheckWithHint 
 
int __fastcall SeAccessCheckWithHint(int a1, char a2, int *a3, int a4, unsigned int a5, int a6, _DWORD *a7, int a8, char a9, _DWORD *a10, int *a11)
{
  int *v11; // lr
  __int16 v14; // r0
  unsigned int v15; // r1
  int v16; // r3
  int v17; // r3
  unsigned int v18; // r4
  int v19; // r2
  int v20; // r3
  int *v21; // r1
  int v22; // r5
  BOOL v23; // lr
  int v24; // r3
  int result; // r0
  int v26; // r0
  int v27; // r3
  int v28; // r0
  int v29; // r3
  unsigned __int16 *v30; // lr
  unsigned int *v31; // r8
  int v32; // r3
  int v33; // r7
  int v34; // r9
  unsigned int v35; // r0
  unsigned int v36; // r10
  int v37; // r2
  int v38; // r6
  unsigned int v39; // r5
  int v40; // r8
  int v41; // r4
  unsigned __int16 *v42; // r1
  unsigned __int16 **v43; // r2
  int v44; // r4
  unsigned int v45; // r10
  int v46; // r3
  int v47; // r1
  int v48; // r5
  int v49; // r8
  unsigned int v50; // r6
  int v51; // r4
  unsigned __int16 **v52; // r5
  unsigned int v53; // r1
  unsigned __int16 *v54; // t1
  int v55; // r9
  int v56; // r3
  int v57; // r2
  int v58; // r6
  int v59; // r3
  int v60; // r5
  int v61; // r2
  int v62; // r4
  int v63; // r3
  unsigned int v64; // r2
  int v65; // r0
  int v66; // r1
  int v67; // r5
  int v68; // r6
  int v69; // r4
  int v70; // r0
  char v71[4]; // [sp+40h] [bp-B8h] BYREF
  int *v72; // [sp+44h] [bp-B4h]
  int v73; // [sp+48h] [bp-B0h]
  unsigned __int16 *v74; // [sp+4Ch] [bp-ACh]
  char v75; // [sp+50h] [bp-A8h] BYREF
  char v76[3]; // [sp+51h] [bp-A7h] BYREF
  unsigned int *v77; // [sp+54h] [bp-A4h]
  int v78; // [sp+58h] [bp-A0h]
  int v79; // [sp+5Ch] [bp-9Ch] BYREF
  int v80; // [sp+60h] [bp-98h]
  int v81; // [sp+64h] [bp-94h]
  int v82; // [sp+68h] [bp-90h]
  int v83; // [sp+6Ch] [bp-8Ch]
  int v84; // [sp+70h] [bp-88h]
  int v85; // [sp+74h] [bp-84h]
  BOOL v86; // [sp+78h] [bp-80h]
  unsigned int v87; // [sp+7Ch] [bp-7Ch]
  int v88; // [sp+80h] [bp-78h]
  int v89; // [sp+84h] [bp-74h]
  int v90; // [sp+8Ch] [bp-6Ch]
  int v91; // [sp+90h] [bp-68h] BYREF
  int v92; // [sp+94h] [bp-64h]
  int v93; // [sp+98h] [bp-60h]
  unsigned int v94; // [sp+9Ch] [bp-5Ch]
  int v95; // [sp+A4h] [bp-54h]
  BOOL v96; // [sp+A8h] [bp-50h]
  int v97[6]; // [sp+B0h] [bp-48h] BYREF
  char v98; // [sp+C8h] [bp-30h]
  int v99; // [sp+C9h] [bp-2Fh]
  int v100; // [sp+CDh] [bp-2Bh]
  int v101; // [sp+D1h] [bp-27h]
  int v102; // [sp+D5h] [bp-23h]
  __int16 v103; // [sp+D9h] [bp-1Fh]
  char v104; // [sp+DBh] [bp-1Dh]

  v11 = a3;
  v72 = a3;
  v92 = 0;
  v93 = 0;
  v94 = 0;
  v98 = 0;
  v79 = 0;
  v89 = a1;
  v83 = -1;
  v99 = 0;
  v100 = 0;
  v101 = 0;
  v102 = 0;
  v103 = 0;
  v104 = 0;
  *a10 = 0;
  v80 = a4;
  v90 = 0;
  v91 = 0;
  v82 = 0;
  v78 = 0;
  v84 = 0;
  *a11 = -1073741790;
  v95 = -1073741790;
  if ( a7 )
    *a7 = 0;
  if ( a9 )
  {
    if ( !a1 )
      goto LABEL_165;
    if ( *a3 && a3[1] < 2 )
    {
      result = 0;
      *a11 = -1073741659;
      return result;
    }
    v87 = a5;
    if ( a5 )
    {
      if ( !a4 )
      {
        SeLockSubjectContext(a3);
        v11 = v72;
      }
      v14 = *(_WORD *)(a1 + 2);
      v75 = 0;
      v76[0] = 0;
      v15 = 0;
      while ( (v14 & 0x10) != 0 )
      {
        if ( (v14 & 0x8000) != 0 )
        {
          v16 = *(_DWORD *)(a1 + 12);
          if ( !v16 )
            break;
          v17 = v16 + a1;
        }
        else
        {
          v17 = *(_DWORD *)(a1 + 12);
        }
        if ( !v17 )
          break;
        v18 = 0;
        v19 = v17 + 8;
        if ( !*(_WORD *)(v17 + 4) )
          break;
        while ( v18 < v15 || *(_BYTE *)v19 != 20 )
        {
          ++v18;
          v19 += *(unsigned __int16 *)(v19 + 2);
          if ( v18 >= *(unsigned __int16 *)(v17 + 4) )
            goto LABEL_19;
        }
        v15 = v18;
        if ( v19 && (*(_BYTE *)(v19 + 1) & 8) == 0 )
        {
          v67 = *(_DWORD *)(v19 + 4);
          v68 = v19 + 8;
          if ( v19 == -8 )
          {
LABEL_21:
            v20 = -1;
            v83 = -1;
            *a11 = 0;
          }
          else
          {
            if ( !*v11 )
              goto LABEL_156;
            v69 = *(_DWORD *)(*v11 + 640);
            v70 = RtlSidDominatesForTrust(*(_DWORD *)(v11[2] + 640), v69, v76);
            if ( v70 < 0 )
              goto LABEL_169;
            if ( !v76[0] )
            {
              v11 = v72;
LABEL_156:
              v69 = *(_DWORD *)(v11[2] + 640);
            }
            v70 = RtlSidDominatesForTrust(v69, v68, &v75);
            if ( v70 < 0 )
            {
LABEL_169:
              v20 = v83;
            }
            else if ( v75 )
            {
              v20 = -1;
              v83 = -1;
            }
            else
            {
              v20 = v67 | 0x1000000;
              v83 = v67 | 0x1000000;
            }
            *a11 = v70;
            if ( v70 < 0 )
            {
LABEL_161:
              if ( !v80 )
                JUMPOUT(0x52DEEA);
              return 0;
            }
          }
          if ( (v20 & a5 & 0xFDFFFFFF) != (a5 & 0xFDFFFFFF) )
            JUMPOUT(0x52DEB4);
          v21 = v72;
          *a11 = 0;
          v22 = *v21;
          v73 = v22;
          if ( !v22 )
          {
            v22 = v21[2];
            v73 = v22;
          }
          v23 = (a2 & 2) != 0 && (*(_DWORD *)(v22 + 176) & 0x2000) != 0;
          v88 = 0;
          v96 = v23;
          if ( !(_BYTE)SepAllowAccessUponLogoff && (*(_DWORD *)(v22 + 176) & 0x20) == 0 )
          {
            v24 = *(_DWORD *)(v22 + 192);
            if ( v24 )
            {
              if ( (*(_DWORD *)(v24 + 24) & 0x20) != 0 )
                return sub_52DB00(0x2000);
            }
          }
          if ( !v23 )
          {
            v26 = SepMandatoryIntegrityCheck(a8, a1, (a2 & 2) != 0, v22, 0, &v91);
            *a11 = v26;
            if ( v26 < 0 )
              goto LABEL_161;
            if ( v93 && (v91 & a5 & 0xFDFFFFFF) != (a5 & 0xFDFFFFFF) )
            {
              *a11 = -1073741790;
              if ( (*(_DWORD *)(v22 + 176) & 0x4000) == 0 || v94 > 0x2000 )
                goto LABEL_161;
              v88 = 1;
            }
            else
            {
              *a11 = 0;
              if ( (a5 & 0x2000000) != 0 && (*(_DWORD *)(v22 + 176) & 0x4000) != 0 && v94 <= 0x2000 )
                v88 = 1;
            }
          }
          v27 = (unsigned __int8)SepRmEnforceCap;
          __dmb(0xBu);
          if ( v27 )
            JUMPOUT(0x52DB18);
          v28 = 0;
          v86 = (a2 & 1) != 0;
          if ( (a2 & 1) != 0 && (a5 & 0x2060000) == 0 )
          {
LABEL_76:
            v45 = a5;
            v44 = 0;
            goto LABEL_77;
          }
          if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
          {
            v29 = *(_DWORD *)(a1 + 4);
            if ( v29 )
              v30 = (unsigned __int16 *)(v29 + a1);
            else
              v30 = 0;
          }
          else
          {
            v30 = *(unsigned __int16 **)(a1 + 4);
          }
          v31 = (unsigned int *)(v22 + 204);
          v77 = (unsigned int *)(v22 + 204);
          v74 = v30;
          if ( v22 == -204 || !v30 )
            goto LABEL_75;
          v32 = *((unsigned __int8 *)v30 + 1);
          v33 = *v30;
          v34 = v32 + 2;
          v35 = LOBYTE(v30[2 * v32 + 2]);
          v85 = v32 + 2;
          v36 = v31[(v35 >> 4) + 18] & v31[(v35 & 0xF) + 2];
          v37 = 0;
          v81 = 0;
          if ( v36 )
          {
            do
            {
              v38 = (unsigned __int8)v36;
              if ( (_BYTE)v36 )
              {
                v39 = v31[1];
                do
                {
                  v40 = *((unsigned __int8 *)SidHashByteToIndexLookupTable + v38);
                  v41 = v40 + v37;
                  v42 = *(unsigned __int16 **)(v39 + 8 * (v40 + v37));
                  if ( *v42 == v33 )
                  {
                    if ( !memcmp((unsigned int)v30, (unsigned int)v42, 4 * v85) )
                    {
                      v31 = v77;
                      v43 = (unsigned __int16 **)(v39 + 8 * v41);
                      goto LABEL_50;
                    }
                    v37 = v81;
                    v30 = v74;
                  }
                  v63 = (1 << v40) ^ v38;
                  v38 = (unsigned __int8)v63;
                }
                while ( (_BYTE)v63 );
                v31 = v77;
              }
              v37 = (unsigned __int8)(v37 + 8);
              v81 = v37;
              v36 >>= 8;
            }
            while ( v36 );
            v34 = v85;
          }
          v50 = *v31;
          if ( *v31 <= 0x20 )
            goto LABEL_75;
          v51 = 32;
          if ( v50 <= 0x20 )
            goto LABEL_75;
          v52 = (unsigned __int16 **)(v31[1] + 256);
          while ( 1 )
          {
            v54 = *v52;
            v52 += 2;
            v53 = (unsigned int)v54;
            if ( *v54 == v33 && !memcmp((unsigned int)v30, v53, 4 * v34) )
              break;
            if ( ++v51 >= v50 )
              goto LABEL_75;
            v30 = v74;
          }
          v43 = v52 - 2;
LABEL_50:
          if ( !v43 )
          {
LABEL_75:
            v28 = v84;
            goto LABEL_76;
          }
          if ( v43 == (unsigned __int16 **)v31[1] && ((unsigned int)v43[1] & 0x10) == 0
            || ((unsigned int)v43[1] & 4) != 0 )
          {
            v44 = 1;
            if ( *(_DWORD *)(v73 + 128) )
              v44 = SepSidInToken(v73, 0, (int)v74, 0, 1);
          }
          else
          {
            v44 = 0;
          }
          v45 = a5;
          if ( v44
            && (a5 & 0x2060000) != 0
            && (v86
             || ((*(_WORD *)(v89 + 2) & 4) == 0 ? (v47 = 0) : (*(_WORD *)(v89 + 2) & 0x8000) == 0 ? (v47 = *(_DWORD *)(v89 + 16)) : (v46 = *(_DWORD *)(v89 + 16)) == 0 ? (v47 = 0) : (v47 = v46 + v89),
                 !RtlpOwnerAcesPresent(0, v47))) )
          {
            if ( (a5 & 0x2000000) != 0 )
            {
              v49 = a6 | 0x60000;
              v48 = 393216;
            }
            else
            {
              v48 = a5 & 0x60000;
              v49 = a5 & 0x60000 | a6;
            }
            v28 = v84;
            v45 = a5 & 0xFFF9FFFF;
            v77 = (unsigned int *)v49;
            v87 = a5 & 0xFFF9FFFF;
            if ( !v84 )
              v44 = 0;
          }
          else
          {
            v28 = v84;
LABEL_77:
            v49 = a6;
            v48 = 0;
            v77 = (unsigned int *)a6;
          }
          v55 = v73;
          if ( v45 || v28 )
          {
            memset(v97, 0, 20);
            v56 = *v72;
            v57 = v72[2];
            v97[0] = v48;
            v58 = SepAccessCheck(v89, 0, v57, v56, v45, 0, 0, a8, v49, a9, a10, a7, a11, 0, v44, v97, &v79, v71, 0);
            v59 = (unsigned __int8)SepRmEnforceCap;
            __dmb(0xBu);
            if ( v59 )
              JUMPOUT(0x52DBA4);
            v60 = v79;
            v61 = (int)a10;
            v62 = (unsigned __int8)v71[0];
            if ( !v96 && (v45 & 0x2000000) != 0 )
            {
              if ( (!v88 || !BYTE2(v97[4]) && !BYTE1(v97[4])) && v93 && (!BYTE1(v92) || !(_BYTE)v92 || !BYTE2(v92)) )
              {
                v61 = *a10 & v91;
                if ( v61 != *a10 )
                  JUMPOUT(0x52DE58);
              }
            }
            else if ( v88 && !BYTE2(v97[4]) && !BYTE1(v97[4]) )
            {
              *a11 = -1073741790;
              *a10 = 0;
              v62 = 0;
            }
            if ( (v45 & 0x2000000) != 0 )
            {
              v61 = v83;
              if ( v83 != -1 )
                JUMPOUT(0x52DE70);
            }
            if ( v55 && !v97[3] && (*(_DWORD *)(v55 + 176) & 0x4000) != 0 )
            {
              if ( *a11 < 0 )
              {
                v65 = SepLocateTokenTrustLevel(v72, (int)a11, v61, *a11);
                SeLogAccessFailure(v55, v66, v89, v65);
              }
              else if ( HIBYTE(v97[4]) )
              {
                JUMPOUT(0x52DE96);
              }
            }
            if ( v84 )
              JUMPOUT(0x52DEA4);
            if ( !v80 )
              SeUnlockSubjectContext(v72);
            if ( v60 )
            {
              AuthzBasepFreeSecurityAttributesList(v60);
              ExFreePoolWithTag(v60, 0);
            }
            result = v62 && v58;
          }
          else
          {
            if ( (*(_DWORD *)(v73 + 176) & 0x2000) == 0 )
              JUMPOUT(0x52DB9A);
            if ( !v80 )
              SeUnlockSubjectContext(v72);
            result = 1;
            *a10 = v49;
            *a11 = 0;
          }
          return result;
        }
LABEL_20:
        ++v15;
        if ( !v19 )
          goto LABEL_21;
      }
LABEL_19:
      v19 = 0;
      goto LABEL_20;
    }
    if ( !a6 )
    {
LABEL_165:
      *a11 = -1073741790;
      return 0;
    }
    *a10 = a6;
    *a11 = 0;
    if ( a7 )
      *a7 = 0;
    result = 1;
  }
  else
  {
    v64 = a5;
    if ( (a5 & 0x2000000) != 0 )
      v64 = a5 & 0xFDFFFFFF | *(_DWORD *)(a8 + 12);
    *a10 = a6 | v64;
    *a11 = 0;
    result = 1;
  }
  return result;
}
