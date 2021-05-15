// sub_7C4AF0 
 
int __fastcall sub_7C4AF0(int a1, int a2, int a3, char a4, char a5)
{
  int v5; // r3
  int v6; // r10
  int v7; // r10
  int v8; // r0
  int v9; // r3
  int v10; // r0
  bool v11; // r1
  int v12; // r0
  int v13; // r3
  int v14; // r2
  int v15; // r7
  int v16; // r0
  _DWORD *v17; // r4
  _DWORD *v18; // r0
  int result; // r0
  int v20; // r7
  int v21; // r1
  int v22; // r6
  _DWORD *v23; // r4
  int v24; // r8
  int v25; // r0
  int v26; // r6
  int v27; // r1
  int v28; // r2
  int v29; // r3
  int v30; // r1
  int v31; // r2
  int v32; // r3
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r1
  int v37; // r2
  int v38; // r3
  int v39; // r1
  int v40; // r2
  int v41; // r3
  int v42; // r1
  int v43; // r2
  int v44; // r3
  int v45; // r1
  int v46; // r2
  int v47; // r3
  int v48; // r6
  int *v49; // r5
  int v50; // r6
  int v51; // r7
  int v52; // r8
  int v53; // r9
  int v54; // lr
  int v55; // r5
  unsigned int *v56; // r4
  int v57; // r1
  unsigned int v58; // r0
  unsigned int v59; // r2
  int v60; // r0
  unsigned int v61; // r1
  __int16 v62; // r3
  int v63; // r5
  unsigned int *v64; // r4
  int v65; // r1
  unsigned int v66; // r0
  unsigned int v67; // r2
  int v68; // r0
  unsigned int v69; // r1
  __int16 v70; // r3
  int v71; // r7
  unsigned int *v72; // r6
  int v73; // r1
  unsigned int v74; // r0
  unsigned int v75; // r2
  int v76; // r0
  unsigned int v77; // r1
  int v78; // r3
  int v79; // r7
  unsigned int *v80; // r5
  int v81; // r1
  unsigned int v82; // r0
  unsigned int v83; // r2
  int v84; // r0
  unsigned int v85; // r1
  __int16 v86; // r3
  int v87; // r3
  unsigned int *v88; // r2
  unsigned int v89; // r1
  unsigned int *v90; // r0
  int v91; // r1
  unsigned int v92; // lr
  unsigned int v93; // r2
  int v94; // r0
  unsigned int v95; // r1
  int v96; // r3
  int v97; // r3
  unsigned int *v98; // r2
  unsigned int v99; // r1
  unsigned int v100; // r1
  int v101; // r3
  unsigned int *v102; // r2
  unsigned int v103; // r1
  unsigned int v104; // r1
  int v105; // r3
  unsigned int *v106; // r2
  unsigned int v107; // r1
  unsigned int v108; // r1
  bool v109[4]; // [sp+20h] [bp-E8h] BYREF
  _DWORD *v110; // [sp+24h] [bp-E4h] BYREF
  int v111; // [sp+28h] [bp-E0h] BYREF
  _DWORD *v112; // [sp+2Ch] [bp-DCh] BYREF
  int v113; // [sp+30h] [bp-D8h]
  _DWORD *v114; // [sp+34h] [bp-D4h]
  int v115; // [sp+38h] [bp-D0h]
  int v116; // [sp+3Ch] [bp-CCh]
  unsigned int *v117; // [sp+40h] [bp-C8h]
  int v118; // [sp+48h] [bp-C0h] BYREF
  int v119; // [sp+4Ch] [bp-BCh]
  char v120; // [sp+5Ah] [bp-AEh]
  int v121; // [sp+60h] [bp-A8h] BYREF
  _DWORD v122[11]; // [sp+68h] [bp-A0h] BYREF
  int v123; // [sp+94h] [bp-74h]
  int v124; // [sp+98h] [bp-70h]
  int v125; // [sp+9Ch] [bp-6Ch]
  int v126; // [sp+A0h] [bp-68h]
  int v127; // [sp+A4h] [bp-64h]
  int v128; // [sp+A8h] [bp-60h]
  int v129; // [sp+ACh] [bp-5Ch]
  int v130; // [sp+B0h] [bp-58h]
  int v131; // [sp+B4h] [bp-54h]
  int v132; // [sp+B8h] [bp-50h]
  int v133; // [sp+BCh] [bp-4Ch]
  int v134; // [sp+C0h] [bp-48h]
  int v135; // [sp+C4h] [bp-44h]
  int v136; // [sp+C8h] [bp-40h]
  int v137; // [sp+CCh] [bp-3Ch]
  int v138; // [sp+D0h] [bp-38h]
  int v139; // [sp+D4h] [bp-34h]
  int v140; // [sp+D8h] [bp-30h]
  int (__fastcall *v141)(int); // [sp+104h] [bp-4h]

  v54 = v50 - *(unsigned __int8 *)((a4 & 3) + a3);
  v5 = *(unsigned __int8 *)(v50 + 15);
  v111 = v54;
  v6 = ObpLookupObjectName(
         *(_DWORD *)(v53 + 4),
         v54 + 4,
         *(_DWORD *)v53,
         ObTypeIndexTable[*(unsigned __int8 *)(v50 + 12) ^ BYTE1(v50) ^ (unsigned __int8)ObHeaderCookie],
         (v5 & a2) == 0,
         a1,
         *(_DWORD *)(v53 + 28),
         v51,
         v52,
         (int)&v118,
         &v110);
  if ( v6 < 0 )
  {
    ObpDecrementHandleCount(v113, v50);
    result = v141(v6);
  }
  else
  {
    v7 = (int)v110;
    if ( v110 == (_DWORD *)v51 )
    {
      v114 = 0;
      v115 = 0;
      v110 = 0;
      v109[0] = 0;
      v116 = 0;
      v8 = *(_DWORD *)v111;
      if ( *(_DWORD *)v111 )
      {
        if ( (*(_DWORD *)(v8 + 168) & 8) != 0 || ObpObjectSecurityInheritance )
          v116 = 3;
        v112 = (_DWORD *)ObpGetObjectSecurity(v8, (unsigned int *)&v110, v109, a5);
        if ( (int)v112 < 0 )
        {
          v17 = v112;
          goto LABEL_105;
        }
        v114 = v110;
        v115 = v109[0];
      }
      v9 = *(_DWORD *)v111;
      v10 = v52;
      v11 = 0;
      v110 = (_DWORD *)v52;
      if ( v9 && ((*(_DWORD *)(v9 + 168) & 8) != 0 || ObpObjectSecurityInheritance) )
      {
        v12 = *(_DWORD *)(v52 + 44);
        if ( v12 )
        {
          v111 = RtlGetDaclSecurityDescriptor(v12, &v111, &v121, v109);
          if ( v111 < 0 )
          {
            if ( v114 )
              ObReleaseObjectSecurity((int)v114, v115);
            ObpDeleteDirectoryEntry(&v118);
            if ( v120 )
            {
              v55 = v118;
              v56 = (unsigned int *)(v118 + 148);
              __pld((void *)(v118 + 148));
              v57 = *v56;
              if ( (*v56 & 0xFFFFFFF0) <= 0x10 )
                v58 = 0;
              else
                v58 = v57 - 16;
              if ( (v57 & 2) != 0 )
                goto LABEL_65;
              __dmb(0xBu);
              do
                v59 = __ldrex(v56);
              while ( v59 == v57 && __strex(v58, v56) );
              if ( v59 != v57 )
LABEL_65:
                ExfReleasePushLock(v56, v57);
              KeAbPostRelease((unsigned int)v56);
              v60 = ObfDereferenceObject(v55);
              v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v62 = *(_WORD *)(v61 + 0x134) + 1;
              *(_WORD *)(v61 + 308) = v62;
              if ( !v62 && *(_DWORD *)(v61 + 100) != v61 + 100 && !*(_WORD *)(v61 + 310) )
                KiCheckForKernelApcDelivery(v60);
            }
            if ( v119 )
              ObfDereferenceObject(v119);
            ObpDecrementHandleCount(v113, v50);
            v18 = (_DWORD *)v111;
            return v141((int)v18);
          }
          v112 = (_DWORD *)RtlGetControlSecurityDescriptor(*(unsigned __int8 **)(v52 + 44), &v111, &v112);
          if ( (int)v112 < 0 )
          {
            if ( v114 )
              ObReleaseObjectSecurity((int)v114, v115);
            ObpDeleteDirectoryEntry(&v118);
            if ( v120 )
            {
              v63 = v118;
              v64 = (unsigned int *)(v118 + 148);
              __pld((void *)(v118 + 148));
              v65 = *v64;
              if ( (*v64 & 0xFFFFFFF0) <= 0x10 )
                v66 = 0;
              else
                v66 = v65 - 16;
              if ( (v65 & 2) != 0 )
                goto LABEL_84;
              __dmb(0xBu);
              do
                v67 = __ldrex(v64);
              while ( v67 == v65 && __strex(v66, v64) );
              if ( v67 != v65 )
LABEL_84:
                ExfReleasePushLock(v64, v65);
              KeAbPostRelease((unsigned int)v64);
              v68 = ObfDereferenceObject(v63);
              v69 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v70 = *(_WORD *)(v69 + 0x134) + 1;
              *(_WORD *)(v69 + 308) = v70;
              if ( !v70 && *(_DWORD *)(v69 + 100) != v69 + 100 && !*(_WORD *)(v69 + 310) )
                KiCheckForKernelApcDelivery(v68);
            }
            if ( v119 )
              ObfDereferenceObject(v119);
            ObpDecrementHandleCount(v113, v50);
            v18 = v112;
            return v141((int)v18);
          }
          if ( !v121 && (v111 & 0x1000) == 0 )
          {
            v27 = *(_DWORD *)(v52 + 4);
            v28 = *(_DWORD *)(v52 + 8);
            v29 = *(_DWORD *)(v52 + 12);
            v122[0] = *(_DWORD *)v52;
            v122[1] = v27;
            v122[2] = v28;
            v122[3] = v29;
            v30 = *(_DWORD *)(v52 + 20);
            v31 = *(_DWORD *)(v52 + 24);
            v32 = *(_DWORD *)(v52 + 28);
            v122[4] = *(_DWORD *)(v52 + 16);
            v122[5] = v30;
            v122[6] = v31;
            v122[7] = v32;
            v33 = *(_DWORD *)(v52 + 36);
            v34 = *(_DWORD *)(v52 + 40);
            v35 = *(_DWORD *)(v52 + 44);
            v122[8] = *(_DWORD *)(v52 + 32);
            v122[9] = v33;
            v122[10] = v34;
            v123 = v35;
            v36 = *(_DWORD *)(v52 + 52);
            v37 = *(_DWORD *)(v52 + 56);
            v38 = *(_DWORD *)(v52 + 60);
            v124 = *(_DWORD *)(v52 + 48);
            v125 = v36;
            v126 = v37;
            v127 = v38;
            v39 = *(_DWORD *)(v52 + 68);
            v40 = *(_DWORD *)(v52 + 72);
            v41 = *(_DWORD *)(v52 + 76);
            v128 = *(_DWORD *)(v52 + 64);
            v129 = v39;
            v130 = v40;
            v131 = v41;
            v42 = *(_DWORD *)(v52 + 84);
            v43 = *(_DWORD *)(v52 + 88);
            v44 = *(_DWORD *)(v52 + 92);
            v132 = *(_DWORD *)(v52 + 80);
            v133 = v42;
            v134 = v43;
            v135 = v44;
            v45 = *(_DWORD *)(v52 + 100);
            v46 = *(_DWORD *)(v52 + 104);
            v47 = *(_DWORD *)(v52 + 108);
            v136 = *(_DWORD *)(v52 + 96);
            v137 = v45;
            v138 = v46;
            v139 = v47;
            v140 = *(_DWORD *)(v52 + 112);
            v123 = 0;
            v49 = (int *)v117;
            v110 = v122;
            goto LABEL_37;
          }
          v11 = 0;
        }
        v10 = v52;
      }
      if ( *(_DWORD *)(v52 + 44) )
      {
        v13 = v116;
LABEL_20:
        v14 = v51;
        v15 = (int)v114;
        v16 = ObpAssignSecurity(
                v10,
                (int)v114,
                v14,
                ObTypeIndexTable[BYTE1(v50) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v50 + 12)],
                v13,
                v11);
        v17 = (_DWORD *)v16;
        if ( v15 )
        {
          ObReleaseObjectSecurity(v15, v115);
        }
        else
        {
          if ( v16 < 0 )
            goto LABEL_105;
          SeReleaseSecurityDescriptor(*(_DWORD *)(v53 + 24), *(_BYTE *)(v53 + 8), 1);
          *(_DWORD *)(v53 + 24) = 0;
          *(_DWORD *)(v52 + 44) = 0;
        }
        if ( (int)v17 >= 0 )
        {
          if ( v120 )
          {
            v71 = v118;
            v72 = (unsigned int *)(v118 + 148);
            __pld((void *)(v118 + 148));
            v73 = *v72;
            if ( (*v72 & 0xFFFFFFF0) <= 0x10 )
              v74 = 0;
            else
              v74 = v73 - 16;
            if ( (v73 & 2) != 0 )
              goto LABEL_100;
            __dmb(0xBu);
            do
              v75 = __ldrex(v72);
            while ( v75 == v73 && __strex(v74, v72) );
            if ( v75 != v73 )
LABEL_100:
              ExfReleasePushLock(v72, v73);
            KeAbPostRelease((unsigned int)v72);
            v76 = ObfDereferenceObject(v71);
            v77 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v78 = (__int16)(*(_WORD *)(v77 + 0x134) + 1);
            *(_WORD *)(v77 + 308) = v78;
            if ( !v78 && *(_DWORD *)(v77 + 100) != v77 + 100 && !*(_WORD *)(v77 + 310) )
              KiCheckForKernelApcDelivery(v76);
          }
          if ( v119 )
            ObfDereferenceObject(v119);
          goto LABEL_26;
        }
LABEL_105:
        ObpDeleteDirectoryEntry(&v118);
        if ( v120 )
        {
          v79 = v118;
          v80 = (unsigned int *)(v118 + 148);
          __pld((void *)(v118 + 148));
          v81 = *v80;
          if ( (*v80 & 0xFFFFFFF0) <= 0x10 )
            v82 = 0;
          else
            v82 = v81 - 16;
          if ( (v81 & 2) != 0 )
            goto LABEL_114;
          __dmb(0xBu);
          do
            v83 = __ldrex(v80);
          while ( v83 == v81 && __strex(v82, v80) );
          if ( v83 != v81 )
LABEL_114:
            ExfReleasePushLock(v80, v81);
          KeAbPostRelease((unsigned int)v80);
          v84 = ObfDereferenceObject(v79);
          v85 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v86 = *(_WORD *)(v85 + 0x134) + 1;
          *(_WORD *)(v85 + 308) = v86;
          if ( !v86 && *(_DWORD *)(v85 + 100) != v85 + 100 && !*(_WORD *)(v85 + 310) )
            KiCheckForKernelApcDelivery(v84);
        }
        if ( v119 )
          ObfDereferenceObject(v119);
        ObpDecrementHandleCount(v113, v50);
        v18 = v17;
        return v141((int)v18);
      }
LABEL_37:
      v13 = v116;
      v10 = (int)v110;
      v11 = v116 != 0;
      goto LABEL_20;
    }
    v20 = 0;
    v110 = 0;
    if ( v120 )
    {
      v20 = v7 - 24;
      v110 = (_DWORD *)(v7 - 24);
      ObfReferenceObject(v7);
      v87 = ObpInfoMaskToOffset[*(_BYTE *)(v7 - 10) & 3];
      __dmb(0xBu);
      v88 = (unsigned int *)(v7 - 24 - v87 + 12);
      do
        v89 = __ldrex(v88);
      while ( __strex(v89 + 1, v88) );
      __dmb(0xBu);
      v90 = (unsigned int *)(v118 + 148);
      __pld((void *)(v118 + 148));
      v117 = v90;
      v91 = *v90;
      if ( (*v90 & 0xFFFFFFF0) <= 0x10 )
        v92 = 0;
      else
        v92 = v91 - 16;
      if ( (v91 & 2) != 0 )
        goto LABEL_131;
      __dmb(0xBu);
      do
        v93 = __ldrex(v90);
      while ( v93 == v91 && __strex(v92, v90) );
      if ( v93 != v91 )
      {
LABEL_131:
        ExfReleasePushLock(v90, v91);
        v90 = v117;
      }
      KeAbPostRelease((unsigned int)v90);
      v94 = ObfDereferenceObject(v118);
      v95 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v96 = (__int16)(*(_WORD *)(v95 + 0x134) + 1);
      *(_WORD *)(v95 + 308) = v96;
      if ( !v96 && *(_DWORD *)(v95 + 100) != v95 + 100 && !*(_WORD *)(v95 + 310) )
        KiCheckForKernelApcDelivery(v94);
    }
    if ( v119 )
      ObfDereferenceObject(v119);
    v21 = v50;
    v22 = v113;
    ObpDecrementHandleCount(v113, v21);
    if ( (*(_DWORD *)v53 & 0x80) != 0 )
    {
      *(_DWORD *)(v52 + 16) = *(_DWORD *)(v52 + 24);
      *(_DWORD *)(v52 + 20) = 0;
      v23 = v112;
      v24 = ObpGrantAccess(1, v7, v52, a5, *(_DWORD *)v53, v112);
      if ( v24 >= 0 )
      {
        v25 = ObpIncrementHandleCountEx(1, (int)v23, v22, v7, a5, *(_DWORD *)v53, 0);
        v26 = (int)v110;
        v17 = (_DWORD *)v25;
        if ( v110 )
        {
          v105 = ObpInfoMaskToOffset[*((_BYTE *)v110 + 14) & 3];
          __dmb(0xBu);
          v106 = (unsigned int *)(v26 - v105 + 12);
          do
          {
            v107 = __ldrex(v106);
            v108 = v107 - 1;
          }
          while ( __strex(v108, v106) );
          __dmb(0xBu);
          if ( !v108 )
            ObpDeleteNameCheck(v26);
          ObfDereferenceObject(v26 + 24);
        }
        if ( (int)v17 < 0 )
        {
          ObfDereferenceObject(v7);
          v18 = v17;
          return v141((int)v18);
        }
LABEL_26:
        *v49 = v7;
        v18 = v17;
        return v141((int)v18);
      }
      v48 = (int)v110;
      if ( v110 )
      {
        v101 = ObpInfoMaskToOffset[*((_BYTE *)v110 + 14) & 3];
        __dmb(0xBu);
        v102 = (unsigned int *)(v48 - v101 + 12);
        do
        {
          v103 = __ldrex(v102);
          v104 = v103 - 1;
        }
        while ( __strex(v104, v102) );
        __dmb(0xBu);
        if ( !v104 )
          ObpDeleteNameCheck(v48);
        ObfDereferenceObject(v48 + 24);
      }
      ObfDereferenceObject(v7);
      result = v141(v24);
    }
    else
    {
      if ( v20 )
      {
        v97 = ObpInfoMaskToOffset[*(_BYTE *)(v20 + 14) & 3];
        __dmb(0xBu);
        v98 = (unsigned int *)(v20 - v97 + 12);
        do
        {
          v99 = __ldrex(v98);
          v100 = v99 - 1;
        }
        while ( __strex(v100, v98) );
        __dmb(0xBu);
        if ( !v100 )
          ObpDeleteNameCheck(v20);
        ObfDereferenceObject(v20 + 24);
      }
      ObfDereferenceObject(v7);
      result = v141(-1073741771);
    }
  }
  return result;
}
