// NtSetInformationThread 
 
int __fastcall NtSetInformationThread(int *a1, int a2, unsigned int a3, unsigned int a4)
{
  int v6; // r4
  int v7; // lr
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r5
  int v11; // r4
  int v12; // r4
  int *v13; // r6
  int v14; // r9
  int v15; // r4
  int v16; // r3
  int v17; // r1
  int v18; // r4
  int v19; // r4
  int v20; // r4
  int *v21; // r9
  _DWORD *v22; // r6
  unsigned int v23; // r2
  unsigned int v24; // r0
  unsigned int v25; // r4
  unsigned int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r9
  int v30; // r10
  unsigned int *v31; // r6
  int v32; // r0
  unsigned int v33; // r3
  int v34; // r4
  int v35; // r2
  int v36; // r4
  unsigned int v37; // r2
  int v38; // r0
  int v39; // r1
  __int16 v40; // r3
  unsigned __int8 v41; // r4
  int v42; // r6
  int v43; // r2
  int v44; // r3
  unsigned __int8 v45; // r1
  int *v46; // r4
  int v47; // r4
  unsigned int v48; // r9
  int v49; // r6
  int *v50; // r4
  int *i; // r0
  int v52; // r8
  unsigned int *v53; // r0
  unsigned int v54; // r4
  unsigned int v55; // r1
  int v56; // r2
  int v57; // r2
  _DWORD *v58; // r3
  unsigned int *v59; // r0
  unsigned int v60; // r4
  unsigned int v61; // r1
  int *v62; // r0
  unsigned int *v63; // r2
  unsigned int v64; // r4
  int v65; // r4
  int *v66; // r5
  unsigned int *v67; // r2
  unsigned int v68; // r0
  unsigned int v69; // r4
  unsigned int v70; // r4
  int v71; // r3
  int v72; // r6
  int *v73; // r5
  unsigned int *v74; // r5
  unsigned int v75; // r0
  unsigned int v76; // r6
  unsigned int v77; // r1
  int v78; // r9
  int v79; // r4
  int *v80; // r5
  unsigned int v81; // r4
  int v82; // r1
  int v83; // r2
  unsigned int *v84; // r5
  int v85; // r0
  unsigned int v86; // lr
  unsigned int v87; // r1
  int *v88; // r4
  int v89; // r0
  int v90; // r1
  int v91; // r2
  int v92; // r3
  int *v93; // r6
  int v94; // r3
  _BYTE *v95; // r4
  int *v96; // r3
  int v97; // r9
  unsigned int v98; // r3
  int v99; // r0
  int v100; // r4
  int v101; // r1
  int v102; // r4
  _DWORD *v103; // r3
  int v104; // r4
  int *v106[2]; // [sp+14h] [bp-B4h] BYREF
  int v107; // [sp+1Ch] [bp-ACh]
  int *v108; // [sp+20h] [bp-A8h]
  int v109; // [sp+24h] [bp-A4h]
  int v110[2]; // [sp+28h] [bp-A0h] BYREF
  char v111; // [sp+30h] [bp-98h]
  int v112; // [sp+34h] [bp-94h]
  int v113; // [sp+3Ch] [bp-8Ch]
  int v114; // [sp+40h] [bp-88h]
  int v115; // [sp+44h] [bp-84h]
  int v116[2]; // [sp+48h] [bp-80h] BYREF
  unsigned int v117; // [sp+50h] [bp-78h]
  int v118; // [sp+54h] [bp-74h]
  int v119; // [sp+58h] [bp-70h]
  unsigned int v120; // [sp+60h] [bp-68h]
  int v121; // [sp+64h] [bp-64h]
  int v122; // [sp+68h] [bp-60h]
  int v123; // [sp+6Ch] [bp-5Ch]
  int v124; // [sp+70h] [bp-58h]
  int v125; // [sp+78h] [bp-50h]
  int v126; // [sp+7Ch] [bp-4Ch]
  int v127; // [sp+80h] [bp-48h]
  int v128; // [sp+84h] [bp-44h]
  unsigned int v129; // [sp+88h] [bp-40h]
  int v130; // [sp+8Ch] [bp-3Ch]
  _DWORD v131[2]; // [sp+90h] [bp-38h] BYREF
  int v132; // [sp+98h] [bp-30h] BYREF
  int v133; // [sp+9Ch] [bp-2Ch]
  int v134; // [sp+A0h] [bp-28h]
  int *varg_r0; // [sp+D0h] [bp+8h]
  int varg_r1; // [sp+D4h] [bp+Ch]
  unsigned int varg_r2; // [sp+D8h] [bp+10h]
  unsigned int varg_r3; // [sp+DCh] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  varg_r1 = a2;
  v108 = a1;
  v106[1] = a1;
  v112 = a3;
  v110[0] = a4;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v109 = v6;
  v110[1] = v6;
  v7 = *(char *)(v6 + 346);
  v107 = v7;
  if ( v7 )
  {
    if ( a2 >= 5 && a2 < 7 )
    {
LABEL_6:
      v8 = 4;
    }
    else
    {
      switch ( a2 )
      {
        case 7:
        case 32:
          v8 = 1;
          break;
        default:
          goto LABEL_6;
      }
    }
    if ( a4 )
    {
      if ( ((v8 - 1) & a3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v9 = a4 + a3;
      if ( a4 + a3 > MmUserProbeAddress || v9 < a3 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  if ( a2 == 5 )
  {
    if ( a4 == 4 )
    {
      v104 = *(_DWORD *)a3;
      v118 = *(_DWORD *)a3;
      v10 = ObReferenceObjectByHandleWithTag(a1, 128, PsThreadType, v7, 2035381072, v106, 0);
      if ( v10 >= 0 )
      {
        v10 = PsAssignImpersonationToken(v106[0], v104);
        ObfDereferenceObjectWithTag((int)v106[0]);
      }
    }
    else
    {
LABEL_16:
      v10 = -1073741820;
    }
  }
  else
  {
    switch ( a2 )
    {
      case 2:
        if ( a4 != 4 )
          goto LABEL_16;
        v122 = *(_DWORD *)a3;
        v11 = v122;
        if ( (unsigned int)(v122 - 1) > 0x1E )
          goto LABEL_24;
        if ( v122 >= 16 )
        {
          if ( !SeCheckPrivilegedObject(SeIncreaseBasePriorityPrivilege, dword_9227C4, v108, 1024, v7) )
            return -1073741727;
          v7 = v107;
          a1 = v108;
        }
        v10 = ObReferenceObjectByHandleWithTag(a1, 1024, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          KeSetPriorityThread((int)v106[0], v11);
          ObfDereferenceObjectWithTag((int)v106[0]);
          v10 = 0;
        }
        return v10;
      case 3:
        if ( a4 != 4 )
          goto LABEL_16;
        v12 = *(_DWORD *)a3;
        v113 = *(_DWORD *)a3;
        v10 = ObReferenceObjectByHandleWithTag(a1, 1024, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          v13 = v106[0];
          v14 = v106[0][84];
          if ( (v12 > 2 || v12 < -2) && v12 != 16 && v12 != -16 )
          {
            v15 = *(_DWORD *)(v109 + 116);
            if ( v15 != *((_DWORD *)PsGetServerSiloGlobals(0) + 5) && *(_BYTE *)(v14 + 375) != 4 )
            {
              v10 = -1073741811;
              goto LABEL_193;
            }
          }
          v16 = *(_DWORD *)(v14 + 288);
          __dmb(0xBu);
          if ( v16 && (*(_DWORD *)(v16 + 400) & 0x20) != 0 && *(_BYTE *)(v14 + 375) != 4 )
          {
            v17 = v113;
            if ( v113 > 0 )
            {
              v13 = v106[0];
              goto LABEL_193;
            }
          }
          else
          {
            v17 = v113;
          }
          v13 = v106[0];
          KeSetBasePriorityThread((int)v106[0], v17);
          goto LABEL_193;
        }
        return v10;
      case 4:
        if ( a4 != 4 )
          goto LABEL_16;
        v132 = *(_DWORD *)a3;
        v20 = v132;
        if ( !v132 )
          goto LABEL_24;
        v10 = ObReferenceObjectByHandleWithTag(a1, 1024, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          v21 = v106[0];
          v22 = (_DWORD *)(v106[0][84] + 172);
          __pld(v22);
          v23 = *v22 & 0xFFFFFFFE;
          do
            v24 = __ldrex(v22);
          while ( v24 == v23 && __strex(v23 + 2, v22) );
          __dmb(0xBu);
          if ( v24 == v23 || ExfAcquireRundownProtection(v22) )
          {
            if ( KeSetLegacyAffinityThread((int)v21, v20) )
              v10 = 0;
            else
              v10 = -1073741811;
            __pld(v22);
            v25 = *v22 & 0xFFFFFFFE;
            __dmb(0xBu);
            do
              v26 = __ldrex(v22);
            while ( v26 == v25 && __strex(v25 - 2, v22) );
            if ( v26 != v25 )
              ExfReleaseRundownProtection((unsigned __int8 *)v22);
          }
          else
          {
            v10 = -1073741558;
          }
          goto LABEL_69;
        }
        return v10;
      case 7:
        if ( a4 != 1 )
          goto LABEL_16;
        v19 = *(unsigned __int8 *)a3;
        v111 = *(_BYTE *)a3;
        v10 = ObReferenceObjectByHandleWithTag(a1, 32, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          KeSetAutoAlignmentThread(v106[0], v19);
          ObfDereferenceObjectWithTag((int)v106[0]);
          v10 = 0;
        }
        return v10;
      case 9:
        goto LABEL_24;
      case 10:
        if ( a4 != 4 )
          goto LABEL_16;
        v48 = *(_DWORD *)a3;
        v115 = *(_DWORD *)a3;
        v49 = v109;
        v10 = ObReferenceObjectByHandleWithTag(a1, 32, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 < 0 )
          return v10;
        v50 = v106[0];
        ObfDereferenceObjectWithTag((int)v106[0]);
        if ( v50 != (int *)v49 )
          goto LABEL_24;
        v110[0] = v50[84];
        v112 = v110[0];
        for ( i = PsGetNextProcessThread(v110[0], 0); ; i = PsGetNextProcessThread(v110[0], v52) )
        {
          v52 = (int)i;
          v106[0] = i;
          if ( !i )
            break;
          v53 = (unsigned int *)(i + 235);
          __pld((void *)(v52 + 940));
          v54 = *(_DWORD *)(v52 + 940) & 0xFFFFFFFE;
          do
            v55 = __ldrex(v53);
          while ( v55 == v54 && __strex(v54 + 2, v53) );
          __dmb(0xBu);
          if ( v55 == v54 || ExfAcquireRundownProtection(v53) )
          {
            v56 = *(_DWORD *)(v52 + 156);
            if ( v56 )
            {
              if ( v48 < 0x40 )
              {
                *(_DWORD *)(v56 + 4 * (v48 + 900)) = 0;
              }
              else if ( v48 < 0x440 )
              {
                v57 = *(_DWORD *)(v56 + 3988);
                if ( v57 )
                {
                  v58 = (_DWORD *)(v57 + 4 * (v48 - 64));
                  if ( (unsigned int)v58 >= MmUserProbeAddress )
                    v58 = (_DWORD *)MmUserProbeAddress;
                  *v58 = 0;
                }
              }
            }
            v59 = (unsigned int *)(v52 + 940);
            __pld((void *)(v52 + 940));
            v60 = *(_DWORD *)(v52 + 940) & 0xFFFFFFFE;
            __dmb(0xBu);
            do
              v61 = __ldrex(v59);
            while ( v61 == v60 && __strex(v60 - 2, v59) );
            if ( v61 != v60 )
              ExfReleaseRundownProtection((unsigned __int8 *)v59);
          }
        }
        return v10;
      case 13:
        if ( a4 != 4 )
          goto LABEL_16;
        v117 = *(_DWORD *)a3;
        v41 = v117;
        v42 = v109;
        if ( v117 > 0x20 )
          goto LABEL_24;
        v10 = ObReferenceObjectByHandleWithTag(a1, 32, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 < 0 )
          return v10;
        v45 = v41;
        v46 = v106[0];
        v10 = KeSetIdealProcessorThread((int)v106[0], v45, v43, v44);
        if ( (v46[19] & 0x400) == 0 )
          PspWriteTebIdealProcessor(v42, v46);
LABEL_107:
        ObfDereferenceObjectWithTag((int)v46);
        return v10;
      case 14:
        if ( a4 != 4 )
          goto LABEL_16;
        v47 = *(_DWORD *)a3;
        v123 = *(_DWORD *)a3;
        v10 = ObReferenceObjectByHandleWithTag(a1, 1024, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          KeSetDisableBoostThread(v106[0], v47 != 0);
          ObfDereferenceObjectWithTag((int)v106[0]);
        }
        return v10;
      case 15:
      case 19:
        return -1073741822;
      case 17:
        if ( a4 )
          goto LABEL_16;
        v10 = ObReferenceObjectByHandleWithTag(a1, 32, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          __dmb(0xBu);
          v62 = v106[0];
          v63 = (unsigned int *)(v106[0] + 240);
          do
            v64 = __ldrex(v63);
          while ( __strex(v64 | 4, v63) );
          __dmb(0xBu);
          ObfDereferenceObjectWithTag((int)v62);
        }
        return v10;
      case 18:
        if ( a4 != 4 )
          goto LABEL_16;
        v65 = *(_DWORD *)a3;
        v119 = *(_DWORD *)a3;
        if ( !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v7, (int)&SeDebugPrivilege) )
          return -1073741727;
        v10 = ObReferenceObjectByHandleWithTag(v108, 32, PsThreadType, v107, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          __dmb(0xBu);
          v66 = v106[0];
          v67 = (unsigned int *)(v106[0] + 240);
          if ( v65 )
          {
            do
              v68 = __ldrex(v67);
            while ( __strex(v68 | 0x20, v67) );
          }
          else
          {
            do
              v69 = __ldrex(v67);
            while ( __strex(v69 & 0xFFFFFFDF, v67) );
          }
          __dmb(0xBu);
          ObfDereferenceObjectWithTag((int)v66);
          v10 = 0;
        }
        return v10;
      case 22:
        if ( a4 == 4 )
        {
          v70 = *(_DWORD *)a3;
          __dmb(0xBu);
          v114 = v70;
          v72 = 0;
        }
        else
        {
          if ( a4 != 8 )
            goto LABEL_16;
          v70 = *(_DWORD *)a3;
          v71 = *(_DWORD *)(a3 + 4);
          __dmb(0xBu);
          v120 = v70;
          v121 = v71;
          v72 = (unsigned __int8)v71;
          v114 = v70;
        }
        if ( v70 >= 4 )
        {
LABEL_24:
          v10 = -1073741811;
        }
        else
        {
          if ( v70 >= 3 )
          {
            if ( !SeCheckPrivilegedObject(SeIncreaseBasePriorityPrivilege, dword_9227C4, v108, 32, v7) )
              return -1073741727;
            v7 = v107;
            a1 = v108;
          }
          v10 = ObReferenceObjectByHandleWithTag(a1, 32, PsThreadType, v7, 2035381072, v106, 0);
          if ( v10 >= 0 )
          {
            v73 = v106[0];
            if ( v72 == 1 && (int)(((unsigned int)v106[0][240] >> 9) & 7) < (int)v70 )
              IoBoostThreadIoPriority((int)v106[0], v70, 0);
            v74 = (unsigned int *)(v73 + 240);
            v75 = *v74;
            __dmb(0xBu);
            do
            {
              v76 = v75;
              __dmb(0xBu);
              do
                v77 = __ldrex(v74);
              while ( v77 == v75 && __strex(v75 & 0xFFFFF1FF | (v70 << 9), v74) );
              v75 = v77;
              __dmb(0xBu);
            }
            while ( v77 != v76 );
            v78 = (v76 >> 9) & 7;
            v79 = v114;
            v80 = v106[0];
            if ( (dword_682604 & 0x2000) != 0 )
              EtwTracePriority(v106[0], 1332, v78, v114, 0);
            if ( v79 != v78 )
              KeAbProcessBaseIoPriorityChange((int)v80, v78, v79);
            ObfDereferenceObjectWithTag((int)v80);
            v10 = 0;
          }
        }
        break;
      case 24:
        if ( a4 != 4 )
          goto LABEL_16;
        v81 = *(_DWORD *)a3;
        __dmb(0xBu);
        v112 = v81;
        if ( v81 > MmGetDefaultPagePriority() || v81 < MmGetMinWsPagePriority() )
          goto LABEL_24;
        v10 = ObReferenceObjectByHandleWithTag(v108, 32, PsThreadType, v83, 2035381072, v106, v82);
        if ( v10 >= 0 )
        {
          v84 = (unsigned int *)(v106[0] + 240);
          v85 = v106[0][240];
          __dmb(0xBu);
          do
          {
            v86 = v85;
            __dmb(0xBu);
            do
              v87 = __ldrex(v84);
            while ( v87 == v85 && __strex(v85 & 0xFFFF8FFF | (v81 << 12), v84) );
            v85 = v87;
            __dmb(0xBu);
          }
          while ( v87 != v86 );
          v88 = v106[0];
          if ( (dword_682604 & 0x2000) != 0 )
            EtwTracePriority(v106[0], 1331, (v86 >> 12) & 7, v112, 0);
          ObfDereferenceObjectWithTag((int)v88);
          v10 = 0;
        }
        return v10;
      case 25:
        if ( a4 != 4 )
          goto LABEL_16;
        v113 = *(_DWORD *)a3;
        v18 = v113;
        if ( (unsigned int)(v113 - 1) > 0x1E )
          goto LABEL_24;
        v10 = ObReferenceObjectByHandleWithTag(a1, 1024, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 < 0 )
          return v10;
        v13 = v106[0];
        if ( *(_BYTE *)(v106[0][84] + 375) == 4
          || v18 < 16
          || SeSinglePrivilegeCheck(SeIncreaseBasePriorityPrivilege, dword_9227C4, v107, (int)&SeDebugPrivilege) )
        {
          KeSetActualBasePriorityThread((int)v13, v18);
        }
        else
        {
          v10 = -1073741727;
        }
LABEL_193:
        ObfDereferenceObjectWithTag((int)v13);
        return v10;
      case 29:
        v10 = ObReferenceObjectByHandleWithTag(a1, 16, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 < 0 )
          return v10;
        ObfDereferenceObjectWithTag((int)v106[0]);
        return -1073741822;
      case 30:
        if ( a4 != 12 )
          goto LABEL_16;
        v27 = *(_DWORD *)(a3 + 4);
        v28 = *(_DWORD *)(a3 + 8);
        v132 = *(_DWORD *)a3;
        v133 = v27;
        v134 = v28;
        v29 = (unsigned __int16)v27;
        if ( (unsigned __int16)v27 >= (unsigned int)KeQueryActiveGroupCount()
          || (dword_681D78[(unsigned __int16)v133] & v132) != v132
          || HIWORD(v134) | (unsigned __int16)v134 | HIWORD(v133) )
        {
          goto LABEL_24;
        }
        v10 = ObReferenceObjectByHandleWithTag(v108, 32, PsThreadType, v107, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          v10 = 0;
          v30 = v106[0][84];
          --*(_WORD *)(v6 + 308);
          v31 = (unsigned int *)(v30 + 168);
          v32 = KeAbPreAcquire(v30 + 168, 0, 0);
          v34 = v32;
          do
          {
            v35 = __ldrex(v31);
            if ( v35 )
              break;
            v33 = __strex(0x11u, v31);
          }
          while ( v33 );
          __dmb(0xBu);
          if ( v35 )
            ExfAcquirePushLockSharedEx((_DWORD *)(v30 + 168), v32, v30 + 168);
          if ( v34 )
          {
            v33 = *(unsigned __int8 *)(v34 + 14) | 1;
            *(_BYTE *)(v34 + 14) = v33;
          }
          v36 = *(_DWORD *)(v30 + 288);
          __dmb(0xBu);
          if ( v36 )
          {
            ExAcquireResourceSharedLite(v36 + 32, 1);
            v33 = *(_DWORD *)(v36 + 400);
            if ( (v33 & 0x10) == 0
              || (v33 = *(_DWORD *)(v36 + 4 * v29 + 356)) != 0 && (v35 = v132, v33 &= v132, v33 == v132) )
            {
              v10 = 0;
            }
            else
            {
              v10 = -1073741823;
            }
          }
          v21 = v106[0];
          if ( v10 >= 0 )
            KeSetAffinityThread((int)v106[0], (int)&v132, v35, v33);
          if ( v36 )
            ExReleaseResourceLite(v36 + 32);
          __dmb(0xBu);
          do
            v37 = __ldrex(v31);
          while ( v37 == 17 && __strex(0, v31) );
          if ( v37 != 17 )
            ExfReleasePushLockShared((_DWORD *)(v30 + 168));
          v38 = KeAbPostRelease(v30 + 168);
          v39 = v109;
          v40 = *(_WORD *)(v109 + 308) + 1;
          *(_WORD *)(v109 + 308) = v40;
          if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
            KiCheckForKernelApcDelivery(v38);
LABEL_69:
          ObfDereferenceObjectWithTag((int)v21);
        }
        return v10;
      case 32:
        if ( a4 != 24 )
          goto LABEL_16;
        v89 = *(_DWORD *)a3;
        v90 = *(_DWORD *)(a3 + 4);
        v91 = *(_DWORD *)(a3 + 8);
        v92 = *(_DWORD *)(a3 + 12);
        v93 = (int *)(a3 + 16);
        v125 = v89;
        v126 = v90;
        v127 = v91;
        v128 = v92;
        v94 = v93[1];
        v129 = *v93;
        v130 = v94;
        v95 = (_BYTE *)v129;
        if ( (v129 & 7) != 0 )
          ExRaiseDatatypeMisalignment(v89);
        if ( v129 >= MmUserProbeAddress )
          *(_BYTE *)MmUserProbeAddress = 0;
        *v95 = *v95;
        v95[440] = v95[440];
        v10 = ObReferenceObjectByHandleWithTag(v108, 32, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 < 0 )
          return v10;
        v96 = (int *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
        v13 = v106[0];
        if ( v106[0] == v96 )
        {
          if ( v128 )
            v10 = KeEnableProfiling(v106[0], v127, v125, v126, v95);
          else
            v10 = KeDisableProfiling((int)v106[0], (int)v95);
        }
        else
        {
          v10 = -1073741637;
        }
        goto LABEL_193;
      case 33:
        if ( a4 != 4 )
          goto LABEL_16;
        v110[0] = *(_DWORD *)a3;
        v97 = v109;
        v10 = ObReferenceObjectByHandleWithTag(a1, 32, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 < 0 )
          return v10;
        v46 = v106[0];
        v10 = KeSetIdealProcessorThreadByNumber((int)v106[0], (unsigned __int16 *)v110, (int)v110, v98);
        if ( v10 >= 0 )
        {
          if ( (v46[19] & 0x400) == 0 )
            PspWriteTebIdealProcessor(v97, v46);
          *(_DWORD *)a3 = v110[0];
        }
        goto LABEL_107;
      case 34:
        if ( a1 != (int *)-2 )
          goto LABEL_24;
        if ( a4 != 4 )
          goto LABEL_16;
        v99 = *(_DWORD *)a3;
        __dmb(0xBu);
        v124 = v99;
        if ( v99 )
        {
          v10 = ObReferenceObjectByHandleWithTag(v99, 2, MmSessionObjectType, v7, 2035381072, v116, 0);
          if ( v10 >= 0 )
          {
            v100 = v116[0];
            v101 = *(_DWORD *)(v116[0] + 20);
            if ( v101 )
            {
              if ( KeSetThreadChargeOnlySchedulingGroup(v109, v101) )
              {
                *(_DWORD *)(v109 + 848) = v100;
                v10 = 0;
              }
              else
              {
                ObfDereferenceObjectWithTag(v100);
                v10 = -1073740714;
              }
            }
            else
            {
              ObfDereferenceObjectWithTag(v116[0]);
              v10 = -1073740715;
            }
          }
        }
        else if ( KeSetThreadChargeOnlySchedulingGroup(v6, 0) )
        {
          ObfDereferenceObject(*(_DWORD *)(v6 + 848));
          *(_DWORD *)(v6 + 848) = 0;
          v10 = 0;
        }
        else
        {
          v10 = -1073740713;
        }
        return v10;
      case 36:
        if ( a4 != 4 )
          goto LABEL_16;
        v102 = MEMORY[4];
        v116[1] = MEMORY[4];
        if ( MEMORY[4] > 8u )
          goto LABEL_24;
        v10 = ObReferenceObjectByHandleWithTag(a1, 1024, PsThreadType, v7, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          KeSetUserHeteroCpuPolicyThread((int)v106[0], v102);
          ObfDereferenceObjectWithTag((int)v106[0]);
        }
        return v10;
      case 39:
        if ( (a4 & 7) != 0 || a4 > 8 )
          goto LABEL_16;
        memmove((int)v131, a3, a4);
        v10 = ObReferenceObjectByHandleWithTag(v108, 1024, PsThreadType, v107, 2035381072, v106, 0);
        if ( v10 >= 0 )
        {
          v10 = KeSetSelectedCpuSetsThread(v106[0], a4 >> 3, v131, v103);
          ObfDereferenceObjectWithTag((int)v106[0]);
        }
        return v10;
      default:
        return -1073741821;
    }
  }
  return v10;
}
