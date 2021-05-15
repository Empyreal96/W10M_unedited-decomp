// IopParseDevice 
 
int __fastcall IopParseDevice(_DWORD *a1, void *a2, int a3, char a4, int a5, unsigned __int16 *a6, unsigned __int16 *a7, int a8, int a9, int *a10)
{
  int v10; // r9
  _DWORD *v11; // r6
  int *v12; // r8
  unsigned int v13; // r10
  int v14; // r4
  _DWORD *v15; // r2
  int v16; // r3
  int v17; // r3
  BOOL v18; // r4
  BOOL v19; // r3
  int v20; // r0
  int v21; // r3
  _DWORD *v22; // r0
  _DWORD *v23; // r8
  int v24; // r4
  int v25; // r0
  int v26; // r4
  _DWORD *v27; // r4
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r9
  int v32; // r5
  BOOL v33; // r2
  int v34; // r4
  int v35; // r1
  int v36; // r2
  int v37; // r5
  int v38; // r3
  int v39; // r0
  int v40; // r3
  int v41; // r4
  int v42; // r8
  int v43; // r4
  int v44; // r0
  int v45; // r2
  int v46; // r0
  __int16 v47; // r3
  int v48; // r8
  _DWORD *v49; // r4
  int v50; // r0
  __int16 v51; // r3
  _DWORD *v52; // r5
  __int16 v53; // r3
  int v54; // r3
  int v55; // r2
  int v56; // r1
  int v57; // r5
  _DWORD *v58; // r9
  int v59; // r2
  _DWORD *v60; // r10
  int v61; // r4
  int v62; // r8
  _DWORD *v63; // r5
  int v64; // r0
  int v65; // r1
  __int16 v66; // r3
  int v67; // r10
  int v68; // r5
  _DWORD *v69; // r4
  int v70; // r0
  __int16 v71; // r3
  _DWORD *v72; // r0
  int v73; // r2
  int v74; // r4
  int v75; // r2
  unsigned __int16 *v76; // r5
  _DWORD *v77; // r8
  int v78; // r3
  int v79; // r4
  _DWORD *v80; // r5
  int v81; // r2
  int v82; // r0
  __int16 v83; // r3
  int v84; // r0
  int v85; // r5
  int v86; // r4
  int v87; // r9
  int v88; // r2
  int v89; // r3
  char v90; // r3
  _DWORD *v91; // r4
  int v92; // r0
  int v93; // r8
  int v94; // r4
  int v95; // r3
  unsigned int v96; // r3
  int v97; // r0
  int v98; // r0
  _DWORD *v99; // r2
  int (__fastcall *v100)(int, _DWORD, _DWORD *); // r4
  int v101; // r10
  int v102; // r2
  unsigned int v103; // r0
  int v104; // r4
  unsigned __int16 *v105; // r1
  unsigned __int16 *i; // r3
  int v107; // r0
  unsigned int v108; // r2
  _WORD *v109; // r3
  _DWORD *v111; // r2
  unsigned int v112; // r2
  int v113; // r0
  int v114; // r4
  int v115; // r0
  unsigned int v116; // r9
  int v117; // r3
  int v118; // r9
  int v119; // r4
  int v120; // r3
  unsigned int v121; // r1
  unsigned __int16 *v122; // r9
  int v123; // r4
  unsigned int v124; // r0
  int v125; // r1
  int v126; // r8
  int v127; // r3
  int v128; // r2
  _DWORD *v129; // r0
  _DWORD *v130; // r5
  _DWORD *v131; // r10
  int v132; // r3
  unsigned int v133; // r3
  int v134; // r9
  _DWORD *v135; // r2
  int (__fastcall *v136)(int, int, _DWORD, int *, _DWORD *); // r4
  int v137; // r0
  int v138; // r0
  int v139; // r3
  unsigned int v140; // r5
  int (__fastcall *v141)(int, int, _DWORD, int *, _DWORD *); // r10
  int v142; // r0
  _DWORD *v146; // [sp+1Ch] [bp-FCh]
  unsigned int v147; // [sp+20h] [bp-F8h]
  char v148; // [sp+24h] [bp-F4h] BYREF
  unsigned __int8 v149; // [sp+25h] [bp-F3h]
  int v150; // [sp+28h] [bp-F0h] BYREF
  _DWORD *v151; // [sp+2Ch] [bp-ECh] BYREF
  _DWORD *v152; // [sp+30h] [bp-E8h] BYREF
  int v153; // [sp+34h] [bp-E4h] BYREF
  unsigned int v154; // [sp+38h] [bp-E0h]
  char v155[4]; // [sp+3Ch] [bp-DCh] BYREF
  int v156; // [sp+40h] [bp-D8h] BYREF
  unsigned __int16 *v157; // [sp+44h] [bp-D4h]
  unsigned __int16 *v158; // [sp+48h] [bp-D0h]
  int v159; // [sp+4Ch] [bp-CCh]
  _DWORD *v160; // [sp+50h] [bp-C8h]
  int v161; // [sp+54h] [bp-C4h] BYREF
  int v162; // [sp+58h] [bp-C0h]
  int v163; // [sp+5Ch] [bp-BCh]
  unsigned __int16 *v164; // [sp+60h] [bp-B8h] BYREF
  int v165; // [sp+64h] [bp-B4h]
  _DWORD *v166; // [sp+68h] [bp-B0h] BYREF
  int v167; // [sp+6Ch] [bp-ACh]
  int *v168; // [sp+70h] [bp-A8h]
  unsigned int v169; // [sp+74h] [bp-A4h]
  _DWORD *v170; // [sp+78h] [bp-A0h] BYREF
  int v171; // [sp+80h] [bp-98h] BYREF
  int v172; // [sp+84h] [bp-94h]
  int v173; // [sp+88h] [bp-90h] BYREF
  int v174; // [sp+8Ch] [bp-8Ch]
  _DWORD *v175; // [sp+90h] [bp-88h]
  int v176; // [sp+94h] [bp-84h]
  int v177; // [sp+98h] [bp-80h]
  unsigned int v178; // [sp+9Ch] [bp-7Ch]
  _DWORD *v179; // [sp+A0h] [bp-78h]
  unsigned int v180; // [sp+A4h] [bp-74h] BYREF
  _DWORD *v181; // [sp+A8h] [bp-70h] BYREF
  int v182; // [sp+ACh] [bp-6Ch]
  _BYTE v183[8]; // [sp+B0h] [bp-68h] BYREF
  int v184; // [sp+B8h] [bp-60h] BYREF
  int v185; // [sp+BCh] [bp-5Ch] BYREF
  _DWORD *v186; // [sp+C0h] [bp-58h] BYREF
  int v187; // [sp+C4h] [bp-54h] BYREF
  _DWORD v188[4]; // [sp+C8h] [bp-50h] BYREF
  int v189; // [sp+D8h] [bp-40h] BYREF
  int v190; // [sp+DCh] [bp-3Ch] BYREF
  int v191; // [sp+E0h] [bp-38h] BYREF
  int v192; // [sp+E4h] [bp-34h] BYREF
  _DWORD v193[12]; // [sp+E8h] [bp-30h] BYREF
  __int64 savedregs; // [sp+118h] [bp+0h]

  v159 = a4;
  v10 = a3;
  v179 = a1;
  v157 = a6;
  v158 = a7;
  v11 = (_DWORD *)a8;
  v175 = (_DWORD *)a8;
  v12 = a10;
  v168 = a10;
  v178 = 0;
  v167 = 0;
  v160 = 0;
  v169 = 0;
  if ( a2 != IoFileObjectType )
    return -1073741788;
  v154 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = v148 & 0xE9 | 4;
  RtlInitUnicodeString((unsigned int)v183, L"File");
  v162 = 0x400000;
  v182 = 262145;
  v176 = 0x2000000;
  v174 = 0x20000;
  v165 = -2147483623;
  while ( 1 )
  {
    *v12 = 0;
    v156 = 0;
    if ( !a8 || *(_WORD *)a8 != 8 || *(_WORD *)(a8 + 2) != 112 )
      return -1073741788;
    v14 = (int)v179;
    v15 = v179;
    v146 = v179;
    if ( *(_DWORD *)(a8 + 16) == 1 )
    {
      *(_DWORD *)(a8 + 16) = -1096154543;
      *(_DWORD *)(a8 + 20) = v14;
      *(_DWORD *)(a8 + 8) = 0;
      ObfReferenceObject(v14);
      return 0;
    }
    if ( (*(_DWORD *)(a8 + 88) & 0x10) != 0 )
    {
      v17 = v179[11];
      if ( *(_DWORD *)(a8 + 12) == -1610612733 )
      {
        if ( v17 != 7 && v17 != 2 && v17 != 36 && v17 != 31 && v17 != 17 )
          goto LABEL_15;
      }
      else
      {
        v18 = v17 == 7 || v17 == 2 || v17 == 36 || v17 == 31 || v17 == 17;
        v19 = v17 == 20 || v17 == 16 || v17 == 40 || v17 == 6 || v17 == 54 || v17 == 53;
        if ( !v18 && !v19 )
        {
LABEL_15:
          v16 = -1073741192;
          *(_DWORD *)(a8 + 8) = -1073741192;
          return v16;
        }
        v20 = IopSymlinkEnforceEnabledTypes(*(_DWORD *)(a8 + 88) & 8, v18, *(_DWORD *)(a8 + 100), v19);
        if ( v20 < 0 )
        {
          *(_DWORD *)(a8 + 8) = v20;
          return v20;
        }
        v15 = v146;
      }
    }
    v21 = *(_DWORD *)(a8 + 20);
    if ( v21 )
    {
      v15 = *(_DWORD **)(v21 + 4);
      v146 = v15;
    }
    v22 = (_DWORD *)IopCheckDeviceAndDriver(a8, v15);
    v150 = (int)v22;
    v153 = (int)v22;
    if ( (int)v22 < 0 )
    {
      *(_DWORD *)(a8 + 8) = v22;
      return (int)v22;
    }
    v23 = v146;
    if ( (*(_DWORD *)(v146[44] + 16) & 0x400) != 0 && !*(_DWORD *)(a8 + 20) )
    {
      v24 = PsGetServerSiloServiceSessionId(-1);
      if ( v24 != PsGetCurrentProcessSessionId()
        || IopSessionZeroAccessCheckEnabled && (*(_DWORD *)(a8 + 40) & 0x40000) == 0 )
      {
        v25 = IopGetDevicePDO((int)v146);
        v26 = v25;
        if ( v25 )
        {
          if ( !IopCheckSessionDeviceAccess(v25) )
          {
            ObfDereferenceObject(v26);
            IopDecrementDeviceObjectRef(v146, 0, 0);
            v16 = -1073741790;
            *(_DWORD *)(a8 + 8) = -1073741790;
            return v16;
          }
          ObfDereferenceObject(v26);
        }
      }
    }
    RtlMapGenericMask(v10 + 16, (char *)IoFileObjectType + 52);
    RtlMapGenericMask(v10 + 24, (char *)IoFileObjectType + 52);
    v27 = (_DWORD *)(*(_DWORD *)(v10 + 48) + 4);
    v28 = *((_DWORD *)IoFileObjectType + 14);
    v29 = *((_DWORD *)IoFileObjectType + 15);
    v30 = *((_DWORD *)IoFileObjectType + 16);
    *v27 = *((_DWORD *)IoFileObjectType + 13);
    v27[1] = v28;
    v27[2] = v29;
    v27[3] = v30;
    v31 = *(_DWORD *)(v10 + 16);
    v163 = v31;
    v32 = v159;
    v33 = v159 || (*(_DWORD *)(a8 + 56) & 1) != 0;
    v34 = a3;
    IopCheckBackupRestorePrivilege(a3, a8 + 40, v33, *(_DWORD *)(a8 + 60));
    v35 = *(unsigned __int8 *)(a8 + 80);
    if ( *(_BYTE *)(a8 + 80) && !*v158 || (*(_DWORD *)(a3 + 12) & 0x100) != 0 )
    {
      v31 |= *(_DWORD *)(a3 + 20);
      v163 = v31;
    }
    v36 = *(_DWORD *)(a8 + 20);
    if ( v36 && (*(_DWORD *)(v36 + 44) & v162) != 0 && !*v158 )
      v167 = 1;
    if ( (v32 || (*(_DWORD *)(a8 + 56) & 1) != 0) && (!v36 || v167) && !v35 )
    {
      v37 = v13 & 0xDF;
      v38 = v146[8];
      if ( *v158 )
      {
        if ( ((v38 & v174) == 0 || (v38 & 0x100) != 0)
          && v159
          && (v155[0] = 0, SeIsAppContainerOrIdentifyLevelContext((char *)(a3 + 28), v155), v155[0]) )
        {
          v151 = v160;
          --*(_WORD *)(v154 + 308);
          ExAcquireResourceSharedLite((int)&IopSecurityResource, 1);
          SeLockSubjectContext(a3 + 28);
          v48 = SeAccessCheck(
                  v146[38],
                  a3 + 28,
                  1,
                  v31 | 0x20,
                  0,
                  (int)&v151,
                  (int)IoFileObjectType + 52,
                  1,
                  (int)&v161,
                  (int)&v191);
          v49 = v151;
          if ( v151 )
          {
            SeAppendPrivileges(a3, v151);
            ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v49);
          }
          v34 = a3;
          SeUnlockSubjectContext(a3 + 28);
          ExReleaseResourceLite((int)&IopSecurityResource);
          v50 = v154;
          v51 = *(_WORD *)(v154 + 308) + 1;
          *(_WORD *)(v154 + 308) = v51;
          if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
            KiCheckForKernelApcDelivery(v50);
          v13 = (v48 ^ v37) & 1 ^ v37;
          v23 = v146;
        }
        else if ( (*(_DWORD *)(a3 + 12) & 1) != 0 )
        {
          v13 = v37 | 1;
        }
        else
        {
          --*(_WORD *)(v154 + 308);
          ExAcquireResourceSharedLite((int)&IopSecurityResource, 1);
          v13 = (SeFastTraverseCheck(v146[38], a3, 32) ^ v37) & 1 ^ v37;
          if ( (v13 & 1) == 0 )
          {
            v152 = 0;
            SeLockSubjectContext(a3 + 28);
            v13 = (v13 | 0x20) & 0xFFFFFFFE | SeAccessCheck(
                                                v146[38],
                                                a3 + 28,
                                                1,
                                                32,
                                                0,
                                                (int)&v152,
                                                (int)IoFileObjectType + 52,
                                                1,
                                                (int)&v161,
                                                (int)&v153) & 1;
            v52 = v152;
            v160 = v152;
            v34 = a3;
            if ( v152 )
            {
              SeAppendPrivileges(a3, v152);
              ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v52);
            }
            v150 = v153;
          }
          ExReleaseResourceLite((int)&IopSecurityResource);
          v46 = v154;
          v53 = *(_WORD *)(v154 + 308) + 1;
          *(_WORD *)(v154 + 308) = v53;
          if ( !v53 && *(_DWORD *)(v46 + 100) != v46 + 100 && !*(_WORD *)(v46 + 310) )
            goto LABEL_109;
        }
        goto LABEL_111;
      }
      if ( (v38 & v182) != 0 && (v31 & 0xFFEDFF7F) != 0 )
      {
        v39 = PsGetCurrentProcessSessionId();
        v40 = MEMORY[0xFFFF92D8];
        __dmb(0xBu);
        if ( v40 != v39 )
        {
          v41 = PsGetServerSiloServiceSessionId(-1);
          if ( v41 == PsGetCurrentProcessSessionId() )
          {
            v34 = a3;
          }
          else
          {
            v34 = a3;
            if ( !IopAllowRemoteDASD() )
            {
              v42 = 1;
LABEL_76:
              v160 = 0;
              v152 = 0;
              --*(_WORD *)(v154 + 308);
              ExAcquireResourceSharedLite((int)&IopSecurityResource, 1);
              SeLockSubjectContext(v34 + 28);
              v43 = v37 | 0x20;
              if ( !v42 )
                goto LABEL_81;
              v44 = *(_DWORD *)(a3 + 28);
              if ( !v44 )
                v44 = *(_DWORD *)(a3 + 36);
              if ( SeTokenIsAdmin(v44) )
              {
LABEL_81:
                v23 = v146;
                v13 = v43 & 0xFFFFFFFE | SeAccessCheck(
                                           v146[38],
                                           a3 + 28,
                                           1,
                                           v31,
                                           0,
                                           (int)&v152,
                                           (int)IoFileObjectType + 52,
                                           1,
                                           (int)&v161,
                                           (int)&v153) & 1;
                v160 = v152;
                v34 = a3;
                if ( v152 )
                {
                  SeAppendPrivileges(a3, v152);
                  ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v160);
                }
                if ( (v13 & 1) != 0 )
                {
                  v45 = v161;
                  *(_DWORD *)(a3 + 20) |= v161;
                  *(_DWORD *)(a3 + 16) &= ~(v45 | v176);
                  *(_BYTE *)(a8 + 80) = 1;
                }
                v150 = v153;
              }
              else
              {
                v13 = v43 & 0xFE;
                v150 = -1073741790;
                v153 = -1073741790;
                v23 = v146;
                v34 = a3;
              }
              SeOpenObjectAuditAlarm((int)v183, (int)v23, (int)v157, v23[38], v34, 0, v13 & 1, 1);
              ExReleaseResourceLite((int)&IopSecurityResource);
              v46 = v154;
              v47 = *(_WORD *)(v154 + 308);
              *(_WORD *)(v154 + 308) = v47 + 1;
              if ( v47 == -1 && *(_DWORD *)(v46 + 100) != v46 + 100 && !*(_WORD *)(v46 + 310) )
LABEL_109:
                KiCheckForKernelApcDelivery(v46);
LABEL_111:
              if ( (v13 & 0x20) != 0 )
                SeUnlockSubjectContext(v34 + 28);
              if ( (v13 & 1) == 0 )
                goto LABEL_176;
              goto LABEL_114;
            }
          }
        }
      }
      v42 = 0;
      goto LABEL_76;
    }
LABEL_114:
    v54 = *(_BYTE *)(a8 + 81) || *(_BYTE *)(a8 + 82);
    v55 = (v13 ^ (v54 << 6)) & 0x40 ^ v13;
    v56 = *v158;
    if ( *v158 || *(_DWORD *)(a8 + 20) || (v31 & 0xFEE1FF7F) != 0 || (v55 & 0x40) != 0 )
      v57 = v55 & 0xF7;
    else
      v57 = v55 | 8;
    v147 = v57;
    v58 = 0;
    v151 = 0;
    v59 = *(_DWORD *)(a8 + 20);
    if ( !v59 || (*(_DWORD *)(v59 + 44) & 0x800) != 0 )
    {
      v60 = v23;
      v152 = v23;
      v166 = v23;
      if ( v23[9] && (v57 & 8) == 0 )
      {
        if ( (v23[8] & 0x100) != 0
          && (*(_DWORD *)(v23[44] + 16) & 0x800) == 0
          && (v159 || (*(_DWORD *)(a8 + 56) & 1) != 0)
          && (v59 || v56)
          && !v167 )
        {
          v160 = 0;
          v150 = 0;
          v67 = v154;
          --*(_WORD *)(v154 + 308);
          ExAcquireResourceSharedLite((int)&IopSecurityResource, 1);
          SeLockSubjectContext(v34 + 28);
          v68 = SeAccessCheck(
                  v23[38],
                  v34 + 28,
                  1,
                  v163,
                  0,
                  (int)&v150,
                  (int)IoFileObjectType + 52,
                  1,
                  (int)&v161,
                  (int)&v190);
          v69 = (_DWORD *)v150;
          if ( v150 )
          {
            SeAppendPrivileges(a3, (_DWORD *)v150);
            ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v69);
          }
          SeOpenObjectAuditAlarm((int)v183, (int)v23, (int)v157, v23[38], a3, 0, v68, 1);
          SeUnlockSubjectContext(a3 + 28);
          v70 = ExReleaseResourceLite((int)&IopSecurityResource);
          v71 = *(_WORD *)(v67 + 308) + 1;
          *(_WORD *)(v67 + 308) = v71;
          if ( !v71 && *(_DWORD *)(v67 + 100) != v67 + 100 && !*(_WORD *)(v67 + 310) )
            KiCheckForKernelApcDelivery(v70);
          if ( !v68 )
            goto LABEL_176;
          v57 = v147;
        }
        v72 = (_DWORD *)IopCheckVpbMounted(a8, (int)v23, v158, &v153);
        v58 = v72;
        v151 = v72;
        v16 = v153;
        if ( !v72 )
          return v16;
        v60 = (_DWORD *)v72[2];
        v152 = v60;
        v166 = v60;
        v150 = v153;
      }
      if ( (*(_DWORD *)(a8 + 88) & 1) != 0 )
      {
        v57 |= 2u;
        v147 = v57;
      }
      else if ( v60[4] )
      {
        v60 = (_DWORD *)IoGetAttachedDevice((int)v60);
        v152 = v60;
        v166 = v60;
      }
    }
    else
    {
      v60 = v179;
      v152 = v179;
      v166 = v179;
      v61 = *(_DWORD *)(v59 + 8);
      if ( v61 )
      {
        v58 = *(_DWORD **)(v59 + 8);
        v151 = v58;
        if ( (v23[8] & 0x100) != 0
          && (*(_DWORD *)(v23[44] + 16) & 0x800) == 0
          && (v159 || (*(_DWORD *)(a8 + 56) & 1) != 0)
          && !v167 )
        {
          v160 = 0;
          v181 = 0;
          --*(_WORD *)(v154 + 308);
          ExAcquireResourceSharedLite((int)&IopSecurityResource, 1);
          SeLockSubjectContext(a3 + 28);
          v62 = SeAccessCheck(
                  v23[38],
                  a3 + 28,
                  1,
                  v163,
                  0,
                  (int)&v181,
                  (int)IoFileObjectType + 52,
                  1,
                  (int)&v161,
                  (int)&v192);
          v63 = v181;
          if ( v181 )
          {
            SeAppendPrivileges(a3, v181);
            ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v63);
          }
          SeOpenObjectAuditAlarm((int)v183, (int)v146, (int)v157, v146[38], a3, 0, v62, 1);
          SeUnlockSubjectContext(a3 + 28);
          v64 = ExReleaseResourceLite((int)&IopSecurityResource);
          v65 = v154;
          v66 = *(_WORD *)(v154 + 308) + 1;
          *(_WORD *)(v154 + 308) = v66;
          if ( !v66 && *(_DWORD *)(v65 + 100) != v65 + 100 && !*(_WORD *)(v65 + 310) )
            KiCheckForKernelApcDelivery(v64);
          if ( !v62 )
          {
            IopDecrementDeviceObjectRef(v146, 0, 0);
            return -1073741790;
          }
          v57 = v147;
          v23 = v146;
        }
        IopIncrementVpbRefCount(v61, 1);
      }
      if ( (*(_DWORD *)(a8 + 88) & 1) != 0 )
      {
        if ( v58 )
        {
          v60 = (_DWORD *)v58[2];
          v152 = v60;
          v166 = v60;
        }
        v57 |= 2u;
        v147 = v57;
      }
    }
    v73 = v23[8];
    if ( (v73 & v182) == 0 || (v23[7] & 0x600100) != 0 )
    {
      v74 = a3;
    }
    else
    {
      v74 = a3;
      if ( (v73 & 0x100) == 0 )
      {
        v148 = 0;
        SeIsAppContainerOrIdentifyLevelContext((char *)(a3 + 28), &v148);
        if ( v148 )
        {
          if ( !v58 )
            goto LABEL_176;
          if ( (*(_DWORD *)(v58[2] + 28) & v174) == 0 )
          {
            IopDereferenceVpbAndFree((int)v58);
LABEL_176:
            IopDecrementDeviceObjectRef(v23, 0, 0);
            return -1073741790;
          }
        }
      }
    }
    if ( (v57 & 2) != 0 )
    {
      v75 = (unsigned __int8)(v57 & 8) >> 3;
      v76 = v158;
      v77 = (_DWORD *)IopCheckTopDeviceHint(&v166, a8, v75, v158);
      v150 = (int)v77;
      if ( (int)v77 < 0 )
      {
        if ( v58 )
          IopDereferenceVpbAndFree((int)v58);
        IopDecrementDeviceObjectRef(v146, 0, 0);
        return (int)v77;
      }
      v60 = v166;
      v152 = v166;
      v23 = v146;
    }
    else
    {
      v76 = v158;
    }
    v78 = *(_DWORD *)(a8 + 88);
    if ( (v78 & 0x10) != 0 )
      *(_DWORD *)(a8 + 88) = v78 & 0xFFFFFFEF;
    if ( (v60[8] & 0x100) != 0 && (v159 || (*(_DWORD *)(a8 + 56) & 1) != 0) && (*(_DWORD *)(a8 + 20) || *v76) && !v167 )
    {
      v160 = 0;
      v170 = 0;
      --*(_WORD *)(v154 + 308);
      ExAcquireResourceSharedLite((int)&IopSecurityResource, 1);
      SeLockSubjectContext(v74 + 28);
      v79 = SeAccessCheck(
              v23[38],
              v74 + 28,
              1,
              v163,
              0,
              (int)&v170,
              (int)IoFileObjectType + 52,
              1,
              (int)&v161,
              (int)&v189);
      v80 = v170;
      if ( v170 )
      {
        SeAppendPrivileges(a3, v170);
        ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v80);
      }
      if ( v79 )
      {
        v81 = v161;
        *(_DWORD *)(a3 + 20) |= v161;
        *(_DWORD *)(a3 + 16) &= ~(v81 | v176);
      }
      SeOpenObjectAuditAlarm((int)v183, (int)v60, (int)v157, v23[38], a3, 0, v79, 1);
      SeUnlockSubjectContext(a3 + 28);
      ExReleaseResourceLite((int)&IopSecurityResource);
      v82 = v154;
      v83 = *(_WORD *)(v154 + 308);
      *(_WORD *)(v154 + 308) = v83 + 1;
      if ( v83 == -1 && *(_DWORD *)(v82 + 100) != v82 + 100 && !*(_WORD *)(v82 + 310) )
        KiCheckForKernelApcDelivery(v82);
      if ( !v79 )
      {
        IopDecrementDeviceObjectRef(v23, 0, 0);
        if ( v58 )
          IopDereferenceVpbAndFree((int)v58);
        return -1073741790;
      }
    }
    v84 = pIoAllocateIrp(v60, *((char *)v60 + 48), 0, HIDWORD(savedregs));
    v85 = v84;
    if ( !v84 )
    {
      IopDecrementDeviceObjectRef(v23, 0, 0);
      if ( v58 )
        IopDereferenceVpbAndFree((int)v58);
      return -1073741670;
    }
    *(_DWORD *)(v84 + 80) = v154;
    *(_BYTE *)(v84 + 32) = v159;
    *(_DWORD *)(v84 + 8) = 2180;
    v188[0] = a9;
    v188[1] = a3;
    v86 = v163;
    v188[2] = v163;
    v188[3] = *(_DWORD *)(a8 + 40);
    v87 = *(_DWORD *)(v84 + 96);
    *(_BYTE *)(v87 - 37) = 0;
    v88 = *(_DWORD *)(a8 + 72);
    if ( v88 )
    {
      v90 = v88 == 1 ? 1 : 19;
      *(_BYTE *)(v87 - 40) = v90;
      *(_DWORD *)(v87 - 20) = *(_DWORD *)(a8 + 76);
    }
    else
    {
      *(_BYTE *)(v87 - 40) = 0;
      *(_DWORD *)(v87 - 20) = *(_DWORD *)(a8 + 52);
      v89 = *(_DWORD *)(a8 + 56);
      *(_BYTE *)(v87 - 38) = v89;
      if ( (a5 & 0x40) == 0 )
        *(_BYTE *)(v87 - 38) = v89 | 0x80;
    }
    *(_DWORD *)(v84 + 48) = *(_DWORD *)(a8 + 32);
    *(_DWORD *)(v84 + 52) = *(_DWORD *)(a8 + 36);
    *(_DWORD *)(v84 + 12) = *(_DWORD *)(a8 + 48);
    *(_DWORD *)(v87 - 28) = *(_DWORD *)(a8 + 40) & 0xFFFFFF | (*(_DWORD *)(a8 + 60) << 24);
    *(_WORD *)(v87 - 24) = *(_WORD *)(a8 + 44);
    *(_WORD *)(v87 - 22) = *(_WORD *)(a8 + 46);
    *(_DWORD *)(v87 - 32) = v188;
    *(_DWORD *)(v84 + 60) = *(_DWORD *)(a8 + 100);
    *(_DWORD *)(v84 + 40) = &v171;
    *(_DWORD *)(v84 + 4) = 0;
    *(_BYTE *)(v84 + 33) = 0;
    *(_BYTE *)(v84 + 36) = 0;
    *(_DWORD *)(v84 + 44) = 0;
    *(_DWORD *)(v84 + 56) = 0;
    *(_DWORD *)(v84 + 84) = 0;
    if ( *(_BYTE *)(a8 + 81) )
    {
      v94 = *(_DWORD *)(a8 + 84);
      memset((_BYTE *)v94, 0, 160);
      v93 = v94 + 24;
      v156 = v94 + 24;
      *(_BYTE *)(v94 + 12) = ObHeaderCookie ^ *((_BYTE *)IoFileObjectType + 20) ^ BYTE1(v94);
      *(_DWORD *)v94 = 1;
      if ( (a5 & 0x40) == 0 )
        *(_DWORD *)(v94 + 68) |= v174;
      *(_WORD *)v93 = 5;
      *(_WORD *)(v94 + 26) = 128;
      *(_DWORD *)(v94 + 56) = *(_DWORD *)(a8 + 20);
      *(_DWORD *)(v94 + 28) = v146;
      if ( (*(_DWORD *)(a8 + 88) & 0x20) != 0
        && v159
        && ((v60[7] & 0x40000) != 0 || (v95 = v60[11], v95 == 8) || v95 == 3 || v95 == 32 || v95 == 20 || v95 == 53) )
      {
        v91 = (_DWORD *)IopRetrieveTransactionParameters((int)v60, a8, v163, v94 + 24);
        if ( (int)v91 < 0 )
        {
          IoFreeIrp(v85);
          IopDecrementDeviceObjectRef(v146, 0, 0);
          if ( v151 )
          {
            IopDereferenceVpbAndFree((int)v151);
            *(_DWORD *)(a8 + 8) = v91;
            return (int)v91;
          }
          goto LABEL_222;
        }
      }
      else
      {
        v91 = (_DWORD *)v150;
      }
    }
    else
    {
      v91 = (_DWORD *)IopAllocRealFileObject((int)&v156, (int)v60, (int)v23, a5, v159, a8, 0, v86);
      if ( (int)v91 < 0 )
      {
        IoFreeIrp(v85);
        IopDecrementDeviceObjectRef(v23, 0, 0);
        if ( v151 )
          IopDereferenceVpbAndFree((int)v151);
        v92 = v156;
        if ( v156 )
        {
          *(_DWORD *)(v156 + 4) = 0;
          ObfDereferenceObject(v92);
        }
LABEL_222:
        *(_DWORD *)(a8 + 8) = v91;
        return (int)v91;
      }
      v93 = v156;
    }
    if ( (v147 & 8) != 0 )
      *(_DWORD *)(v93 + 44) |= 0x800u;
    *(_DWORD *)(v85 + 100) = v93;
    *(_DWORD *)(v87 - 12) = v93;
    v96 = *v158;
    if ( *v158 )
    {
      if ( v96 >= 0x38 )
      {
        if ( v96 >= 0x78 )
        {
          if ( v96 < 0xF8 )
            v96 = 248;
        }
        else
        {
          v96 = 120;
        }
      }
      else
      {
        v96 = 56;
      }
      *(_WORD *)(v93 + 50) = v96;
      v97 = ExAllocatePoolWithTag(1, v96, 1833856841);
      *(_DWORD *)(v93 + 52) = v97;
      if ( !v97 )
      {
        IoFreeIrp(v85);
        IopDecrementDeviceObjectRef(v146, 0, 0);
        if ( v151 )
          IopDereferenceVpbAndFree((int)v151);
        *(_DWORD *)(v93 + 4) = 0;
        if ( !*(_BYTE *)(a8 + 81) )
        {
          ObfDereferenceObject(v93);
          return -1073741670;
        }
        return -1073741670;
      }
    }
    v98 = RtlCopyUnicodeString((unsigned __int16 *)(v93 + 48), v158);
    if ( *(_BYTE *)(a8 + 81) )
    {
      v99 = *(_DWORD **)(v60[2] + 40);
      if ( v99 )
      {
        if ( *v99 > 0x60u )
        {
          v100 = (int (__fastcall *)(int, _DWORD, _DWORD *))v99[24];
          if ( v100 )
          {
            --*(_BYTE *)(v85 + 35);
            *(_DWORD *)(v85 + 96) -= 40;
            *(_DWORD *)(v87 - 16) = v60;
            if ( (MmVerifierData & 0x10) != 0 )
              v101 = VfFastIoSnapState(v98);
            else
              v101 = 0;
            v170 = (_DWORD *)v100(v85, *(_DWORD *)(a8 + 68), v152);
            if ( v101 )
              VfFastIoCheckState(v101, v100);
            *(_DWORD *)(a8 + 100) = *(_DWORD *)(v85 + 60);
            if ( v170 )
            {
              v102 = *(_DWORD *)(v85 + 24);
              *(_DWORD *)(a8 + 8) = v102;
              *(_DWORD *)(a8 + 12) = *(_DWORD *)(v85 + 28);
              if ( v102 == 260 )
              {
                v103 = *(_DWORD *)(v85 + 84);
                if ( v103 )
                {
                  ExFreePoolWithTag(v103);
                  *(_DWORD *)(v85 + 84) = 0;
                  *(_DWORD *)(a8 + 20) = 0;
                }
              }
              if ( *(_WORD *)(v93 + 48) )
                ExFreePoolWithTag(*(_DWORD *)(v93 + 52));
              if ( *(_DWORD *)(v93 + 124) )
                IopDeleteFileObjectExtension(v93);
              IopDecrementDeviceObjectRef(v146, 0, 0);
              if ( v151 )
                IopDereferenceVpbAndFree((int)v151);
              IoFreeIrp(v85);
              *(_DWORD *)(a8 + 16) = -1096154543;
              v20 = 0;
              if ( !*(_BYTE *)(a8 + 83) )
                *(_DWORD *)(*(_DWORD *)(a8 + 64) + 32) = *(_DWORD *)(*(_DWORD *)(a8 + 68) + 48);
              return v20;
            }
            *(_DWORD *)(v85 + 96) += 40;
            ++*(_BYTE *)(v85 + 35);
            v60 = v152;
          }
        }
      }
      v91 = (_DWORD *)IopAllocRealFileObject((int)&v156, (int)v60, (int)v146, a5, v159, a8, 1, v163);
      v150 = (int)v91;
      if ( (int)v91 < 0 )
      {
        v104 = v156;
        if ( *(_WORD *)(v156 + 48) )
          ExFreePoolWithTag(*(_DWORD *)(v156 + 52));
        if ( *(_DWORD *)(v104 + 124) )
          IopDeleteFileObjectExtension(v104);
        IopDecrementDeviceObjectRef(v146, 0, 0);
        if ( v151 )
          IopDereferenceVpbAndFree((int)v151);
        IoFreeIrp(v85);
        return v150;
      }
      v93 = v156;
      *(_DWORD *)(v87 - 12) = v156;
      *(_DWORD *)(v85 + 100) = v93;
    }
    if ( !*(_DWORD *)(a8 + 72) )
    {
      v91 = (_DWORD *)IoGetIrpExtraCreateParameter(v85, &v184);
      if ( v184 )
      {
        if ( IopSymlinkGetECP(v184, (int)&v164) != -1073741275 )
        {
          v105 = v164;
          for ( i = (unsigned __int16 *)*((_DWORD *)v164 + 2); i; i = (unsigned __int16 *)*((_DWORD *)i + 2) )
            v105 = i;
          if ( !v105[2] )
          {
            v107 = IopSymlinkUpdateECP(v85, (int)v105, *v105, v157, *v157 - *v158, v105[1]);
            v91 = (_DWORD *)v107;
            if ( v107 < 0 )
            {
              *(_DWORD *)(v85 + 24) = v107;
              *(_DWORD *)(v85 + 28) = 0;
              v147 &= 0xFBu;
            }
          }
        }
      }
    }
    KeInitializeEvent(v93 + 92, 0, 0);
    *(_DWORD *)(a8 + 4) = v93;
    v108 = v147;
    if ( (v147 & 4) != 0 )
    {
      IopQueueThreadIrp(v85);
      if ( (*(_BYTE *)(v85 + 39) & 0x80) == 0 && (v109 = *(_WORD **)(v85 + 104)) != 0 && (*v109 & 2) != 0 )
      {
        EtwActivityIdControlKernel(1, &v187);
        v111 = *(_DWORD **)(v85 + 104);
        v193[0] = v111[3];
        v193[1] = v111[4];
        v193[2] = v111[5];
        v193[3] = v111[6];
        v186 = v193;
        EtwActivityIdControlKernel(2, &v186);
        v91 = (_DWORD *)IofCallDriver((int)v60, v85);
        v185 = v187;
        EtwActivityIdControlKernel(2, &v185);
      }
      else
      {
        v91 = (_DWORD *)IofCallDriver((int)v60, v85);
      }
      v108 = v147;
    }
    if ( v91 == (_DWORD *)259 )
    {
      if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0 )
        v112 = v108 & 0x7F;
      else
        v112 = v108 | 0x80;
      v147 = v112;
      while ( KeWaitForSingleObject(v93 + 92, 0, 0, (_DWORD *)(v112 >> 7), 0) == 257 )
      {
        v113 = KfRaiseIrql(1);
        if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) != 0
          || !*(_DWORD *)(v93 + 96) && *(_BYTE *)(v85 + 36) )
        {
          KfLowerIrql(v113);
          IopCancelAlertedRequest(v93 + 92, v85);
          break;
        }
        KfLowerIrql(v113);
        v112 = v147;
      }
    }
    IoGetIrpExtraCreateParameter(v85, &v173);
    v114 = v173;
    if ( *(_DWORD *)(v85 + 24) == 260 )
    {
      v169 = *(_DWORD *)(v85 + 84);
      if ( !v173 || IopSymlinkGetECP(v173, (int)&v164) == -1073741275 )
      {
        v115 = IopSymlinkCreateECP(v85, v93, v157, (unsigned __int16)(*v157 - *v158), (int *)&v164);
        if ( v115 >= 0 )
        {
          if ( !v114 )
          {
            IoGetIrpExtraCreateParameter(v85, &v173);
            v114 = v173;
          }
        }
        else
        {
          *(_DWORD *)(v85 + 28) = 0;
          *(_DWORD *)(v85 + 24) = v115;
        }
      }
      if ( *(_DWORD *)(v85 + 24) == 260 )
      {
        v116 = v169;
        IopSymlinkProcessReparse(v85, v93, v169, *(_DWORD *)(a8 + 56) & 8);
        v117 = *(_DWORD *)(v85 + 28);
        if ( v117 == -1610612733 || v117 == -1610612724 || v117 == v165 )
        {
          v147 ^= ((unsigned __int8)v147 ^ (unsigned __int8)(16 * (*(_WORD *)(v116 + 6) == 0))) & 0x10;
          if ( (*(_DWORD *)(a8 + 56) & 8) == 0 )
          {
            ExFreePoolWithTag(v116);
            v169 = 0;
          }
        }
      }
    }
    if ( !*(_DWORD *)(v85 + 24) && !*(_DWORD *)(a8 + 72) )
    {
      v118 = IopSymlinkPropagateToExtensionIfNeeded(v93, v114, v157);
      if ( v118 < 0 )
      {
        IoCancelFileOpen(v60, v93);
        *(_DWORD *)(v85 + 28) = 0;
        *(_DWORD *)(v85 + 24) = v118;
      }
    }
    if ( v114 )
      *(_DWORD *)(a8 + 100) = v114;
    v119 = *(_DWORD *)(v85 + 24);
    v171 = v119;
    v172 = *(_DWORD *)(v85 + 28);
    *(_DWORD *)(v93 + 96) = 1;
    if ( (v147 & 4) != 0 )
    {
      *(_DWORD *)(v85 + 80) = v154;
      IopDequeueIrpFromThread((_DWORD *)v85);
    }
    if ( (*(_DWORD *)(v85 + 8) & 0x30) == 48 )
      ExFreePoolWithTag(*(_DWORD *)(v85 + 12));
    IoFreeIrp(v85);
    v120 = v172;
    *(_DWORD *)(a8 + 12) = v172;
    if ( v119 < 0 )
      break;
    if ( v119 != 260 )
    {
      v129 = (_DWORD *)IoGetRelatedDeviceObject((_DWORD *)v93);
      v130 = v129;
      if ( v60 != v129 )
      {
        v129 = *(_DWORD **)(v93 + 8);
        v131 = v151;
        if ( v129 != v151 )
        {
          if ( v129 )
            v129 = (_DWORD *)IopIncrementVpbRefCount((int)v129, 1);
          if ( v131 )
            v129 = (_DWORD *)IopDereferenceVpbAndFree((int)v131);
        }
      }
      if ( (v147 & 0x40) == 0 )
      {
        *v168 = v93;
        *(_DWORD *)(a8 + 16) = -1096154543;
        ObfReferenceObject(v93);
        v132 = *(_DWORD *)(v93 + 32);
        if ( v132 && (*(_DWORD *)(v132 + 44) & v162) == 0 )
          goto LABEL_407;
        if ( *(_WORD *)(v93 + 48) )
          goto LABEL_407;
        v133 = v130[11];
        if ( v133 >= 4 && v133 < 8 )
          goto LABEL_407;
        if ( v133 > 9 )
        {
          if ( v133 != 32 )
          {
LABEL_407:
            v16 = v171;
            *(_DWORD *)(a8 + 8) = v171;
            return v16;
          }
        }
        else if ( v133 < 8 && v133 != 3 )
        {
          goto LABEL_407;
        }
        *(_DWORD *)(v93 + 44) |= v162;
        goto LABEL_407;
      }
      if ( *(_BYTE *)(a8 + 81) )
      {
        v134 = 0;
        v149 = 0;
        v135 = *(_DWORD **)(v130[2] + 40);
        if ( *(_BYTE *)(a8 + 83) )
        {
          if ( v135 )
          {
            if ( *v135 > 0x38u )
            {
              v141 = (int (__fastcall *)(int, int, _DWORD, int *, _DWORD *))v135[14];
              if ( v141 )
              {
                v168 = (int *)((MmVerifierData & 0x10) != 0 ? VfFastIoSnapState(v129) : 0);
                v134 = v141(v93, 1, *(_DWORD *)(a8 + 68), &v171, v130);
                if ( v168 )
                  VfFastIoCheckState(v168, v141);
              }
            }
          }
          if ( !v134 )
          {
            v142 = IoQueryFileInformation(v93, 34, 56, *(_DWORD *)(a8 + 68), (int)&v180);
            v119 = v142;
            if ( v142 < 0 && (v142 == -1073741811 || v142 == -1073741822) )
              v119 = IopGetNetworkOpenInformation(v93, a8);
          }
          goto LABEL_447;
        }
        v164 = 0;
        if ( v135 )
          v136 = (int (__fastcall *)(int, int, _DWORD, int *, _DWORD *))v135[4];
        else
          v136 = 0;
        v162 = (int)v136;
        if ( v136 )
        {
          if ( (MmVerifierData & 0x10) != 0 )
            v137 = VfFastIoSnapState(v129);
          else
            v137 = 0;
          v177 = v137;
          v149 = v136(v93, 1, *(_DWORD *)(a8 + 64), &v171, v130);
          if ( v177 )
            VfFastIoCheckState(v177, v162);
          v11 = v175;
          v134 = v149;
          v93 = v156;
        }
        if ( v134 )
        {
          v119 = v171;
        }
        else
        {
          if ( ViVerifierDriverAddedThunkListHead )
          {
            if ( (MmVerifierData & 0x10) != 0 )
              v139 = 40;
            else
              v139 = 32;
            v138 = ExAllocatePoolWithTagPriority(512, 0x28u, 538996553, v139);
          }
          else
          {
            v138 = ExAllocatePoolWithTag(512, 40, 538996553);
          }
          v140 = v138;
          v164 = (unsigned __int16 *)v138;
          if ( v138 )
          {
            v119 = IoQueryFileInformation(v93, 4, 40, v138, (int)&v180);
            v153 = v119;
            if ( v119 >= 0 )
              memmove(v11[16], v140, v180);
            ExFreePoolWithTag(v140);
            goto LABEL_447;
          }
          v119 = -1073741670;
        }
        v153 = v119;
      }
LABEL_447:
      v11[4] = -1096154543;
      IopCloseFile(0, (_DWORD *)v93, 1, 1);
      ObfDereferenceObject(v93);
      v11[1] = 0;
      v11[2] = v119;
      return v119;
    }
    if ( !v120 || (v120 == -1610612733 || v120 == -1610612724 || v120 == v165) && (*(_DWORD *)(a8 + 56) & 8) == 0 )
    {
      v121 = *(unsigned __int16 *)(v93 + 48);
      v122 = v157;
      if ( v157[1] < v121 )
      {
        v123 = ExAllocatePoolWithTag(1, v121, 1665560393);
        if ( !v123 )
        {
          v16 = -1073741670;
          *(_DWORD *)(a8 + 8) = -1073741670;
          return v16;
        }
        v124 = *((_DWORD *)v122 + 1);
        if ( v124 )
          ExFreePoolWithTag(v124);
        *((_DWORD *)v122 + 1) = v123;
        v122[1] = *(_WORD *)(v93 + 48);
      }
      RtlCopyUnicodeString(v122, (unsigned __int16 *)(v93 + 48));
      if ( v172 == -1610612733 || v172 == -1610612724 || v172 == v165 )
        *(_DWORD *)(a8 + 20) = 0;
    }
    else
    {
      v122 = v157;
    }
    if ( *(_WORD *)(v93 + 48) )
    {
      ExFreePoolWithTag(*(_DWORD *)(v93 + 52));
      *(_WORD *)(v93 + 48) = 0;
    }
    *(_DWORD *)(v93 + 4) = 0;
    ObfDereferenceObject(v93);
    *(_DWORD *)(a8 + 4) = 0;
    IopDecrementDeviceObjectRef(v146, 0, 0);
    if ( v151 )
      IopDereferenceVpbAndFree((int)v151);
    v125 = v172;
    if ( v172 != 1 )
    {
      *(_DWORD *)(a8 + 20) = 0;
      v126 = v165;
      if ( v125 == -1610612733 || v125 == -1610612724 || v125 == v165 )
      {
        v127 = *(_DWORD *)(a8 + 88) | 0x10;
        *(_DWORD *)(a8 + 88) = v127;
        v128 = v146[11];
        if ( v128 == 7 || v128 == 2 || v128 == 36 || v128 == 31 || v128 == 17 )
          *(_DWORD *)(a8 + 88) = v127 | 8;
        else
          *(_DWORD *)(a8 + 88) = v127 & 0xFFFFFFF7;
      }
      if ( *(_BYTE *)(a8 + 80) )
        KeBugCheckEx(249, (int)v146, (int)v60, (int)v122, v125);
      if ( (*(_DWORD *)(v146[44] + 16) & 0x800) == 0 )
      {
        *(_DWORD *)(a3 + 16) = *(_DWORD *)(a3 + 24);
        *(_DWORD *)(a3 + 20) = 0;
        *(_DWORD *)(a3 + 12) &= 0xFFFFFEFF;
      }
      if ( v125 != -1610612733 && v125 != -1610612724 && v125 != v126 )
        goto LABEL_388;
      if ( (*(_DWORD *)(a8 + 56) & 8) != 0 )
      {
        *(_DWORD *)(a8 + 12) = v169;
        v16 = -2147483603;
        *(_DWORD *)(a8 + 8) = -2147483603;
        return v16;
      }
      if ( v125 == v126 )
        v16 = 872;
      else
LABEL_388:
        v16 = 260;
      return v16;
    }
    ++v178;
    v13 = v147;
    v10 = a3;
    v12 = v168;
    if ( v178 > 0x20 )
      return -1073741823;
  }
  if ( (*(_DWORD *)(v93 + 44) & 0x200000) != 0 )
  {
    ObfDereferenceObject(v93);
  }
  else
  {
    if ( *(_WORD *)(v93 + 48) )
    {
      ExFreePoolWithTag(*(_DWORD *)(v93 + 52));
      *(_WORD *)(v93 + 48) = 0;
    }
    *(_DWORD *)(v93 + 4) = 0;
    ObfDereferenceObject(v93);
    IopDecrementDeviceObjectRef(v146, 0, 0);
    if ( v151 )
      IopDereferenceVpbAndFree((int)v151);
  }
  *(_DWORD *)(a8 + 4) = 0;
  *(_DWORD *)(a8 + 8) = v119;
  return v119;
}
