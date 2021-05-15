// NtQueryInformationThread 
 
int __fastcall NtQueryInformationThread(int a1, int a2, int a3, unsigned int a4, unsigned int *a5)
{
  BOOL *v6; // r5
  int v7; // lr
  int v8; // r0
  int v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r2
  unsigned int *v12; // r9
  int *v13; // r8
  int v14; // r0
  int v15; // r1
  int v16; // r8
  int v17; // r6
  unsigned int *v18; // r10
  unsigned int v19; // r3
  unsigned int v20; // r0
  int v21; // r3
  unsigned int v22; // r4
  int v23; // r1
  int v24; // r2
  int v25; // r3
  _DWORD *v26; // r5
  int v27; // r2
  int v28; // r3
  int v29; // r6
  int v30; // r6
  int v31; // r2
  int v32; // r3
  int v33; // r3
  int v34; // r1
  int v35; // r2
  int v36; // r3
  _DWORD *v37; // r5
  int v38; // r1
  unsigned __int64 v39; // r2
  int v40; // r6
  int v41; // r10
  int v42; // r3
  BOOL v43; // r10
  BOOL v44; // r6
  BOOL v45; // r6
  BOOL v46; // r6
  int v47; // r0
  int v48; // r3
  int v49; // r6
  BOOL v50; // r1
  BOOL v51; // r2
  BOOL v52; // r3
  int v53; // r10
  int v54; // lr
  unsigned int v55; // r2
  unsigned int v56; // r3
  unsigned int *v57; // r0
  unsigned int v58; // r4
  unsigned int v59; // r1
  int v60; // r2
  unsigned int *v61; // r0
  unsigned int v62; // r4
  unsigned int v63; // r1
  int v64; // r0
  int v65; // r3
  int v66; // r6
  int v67; // r4
  unsigned int v68; // r2
  char v69; // r3
  unsigned int v70; // r0
  char v71; // r3
  int v72; // r1
  int v73; // r2
  int v74; // r3
  int v76[2]; // [sp+10h] [bp-98h] BYREF
  int v77; // [sp+18h] [bp-90h] BYREF
  unsigned __int8 v78; // [sp+1Ch] [bp-8Ch]
  unsigned __int8 v79; // [sp+1Dh] [bp-8Bh]
  bool v80; // [sp+1Eh] [bp-8Ah]
  bool v81; // [sp+1Fh] [bp-89h]
  int v82; // [sp+20h] [bp-88h]
  int v83; // [sp+24h] [bp-84h] BYREF
  char v84; // [sp+28h] [bp-80h]
  BOOL *v85; // [sp+2Ch] [bp-7Ch] BYREF
  int v86; // [sp+38h] [bp-70h] BYREF
  int v87; // [sp+3Ch] [bp-6Ch]
  int v88; // [sp+40h] [bp-68h]
  int v89; // [sp+44h] [bp-64h]
  unsigned __int64 v90; // [sp+48h] [bp-60h]
  unsigned __int64 v91; // [sp+50h] [bp-58h]
  BOOL v92; // [sp+58h] [bp-50h]
  BOOL v93; // [sp+5Ch] [bp-4Ch]
  _DWORD v94[4]; // [sp+60h] [bp-48h] BYREF
  BOOL v95; // [sp+70h] [bp-38h] BYREF
  int v96; // [sp+74h] [bp-34h]
  int v97; // [sp+78h] [bp-30h]
  _DWORD v98[2]; // [sp+80h] [bp-28h] BYREF
  int v99; // [sp+88h] [bp-20h]
  int varg_r0; // [sp+B0h] [bp+8h]
  int varg_r1; // [sp+B4h] [bp+Ch]
  int varg_r2; // [sp+B8h] [bp+10h]
  unsigned int varg_r3; // [sp+BCh] [bp+14h]

  varg_r3 = a4;
  v6 = (BOOL *)a3;
  varg_r2 = a3;
  varg_r1 = a2;
  v77 = a1;
  varg_r0 = a1;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v85 = (BOOL *)v7;
  v76[0] = v7;
  v8 = *(char *)(v7 + 0x15A);
  v83 = v8;
  v84 = v8;
  if ( v8 )
  {
    if ( a4 )
    {
      if ( a4 >= 4 )
        v9 = 4;
      else
        v9 = 1;
      if ( ((v9 - 1) & a3) != 0 )
        ExRaiseDatatypeMisalignment(v8);
      v10 = a3 + a4;
      v11 = MmUserProbeAddress;
      if ( (unsigned int)v6 + a4 > MmUserProbeAddress || v10 < (unsigned int)v6 )
      {
        *(_BYTE *)MmUserProbeAddress = 0;
        v11 = MmUserProbeAddress;
      }
    }
    else
    {
      v11 = MmUserProbeAddress;
    }
    v12 = a5;
    if ( a5 )
    {
      v13 = (int *)a5;
      if ( (unsigned int)a5 >= v11 )
        v13 = (int *)v11;
      v99 = *v13;
      *v13 = v99;
    }
  }
  else
  {
    v12 = a5;
  }
  switch ( a2 )
  {
    case 0:
      if ( a4 != 28 )
        return -1073741820;
      v14 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v14 < 0 )
        return v14;
      v17 = v76[0];
      if ( !*(_BYTE *)(v76[0] + 4) )
        goto LABEL_34;
      v18 = (unsigned int *)(v76[0] + 940);
      __pld((void *)(v76[0] + 940));
      v19 = *(_DWORD *)(v76[0] + 940) & 0xFFFFFFFE;
      do
        v20 = __ldrex(v18);
      while ( v20 == v19 && __strex(v19 + 2, v18) );
      __dmb(0xBu);
      if ( v20 == v19 || ExfAcquireRundownProtection((_DWORD *)(v17 + 940)) )
      {
        __pld(v18);
        v22 = *v18 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v15 = __ldrex(v18);
        while ( v15 == v22 && __strex(v22 - 2, v18) );
        if ( v15 != v22 )
          ExfReleaseRundownProtection((unsigned __int8 *)(v17 + 940));
LABEL_34:
        v21 = 259;
      }
      else
      {
        v21 = *(_DWORD *)(v17 + 984);
      }
      v86 = v21;
      v87 = *(_DWORD *)(v17 + 156);
      v88 = *(_DWORD *)(v17 + 876);
      v89 = *(_DWORD *)(v17 + 880);
      LODWORD(v90) = *(_DWORD *)(v17 + 340);
      HIDWORD(v90) = *(char *)(v17 + 123);
      LODWORD(v91) = KeQueryBasePriorityThread(v17, v15, SHIDWORD(v90), v90);
      ObfDereferenceObjectWithTag(v17);
      v23 = v87;
      v24 = v88;
      v25 = v89;
      *v6 = v86;
      v6[1] = v23;
      v6[2] = v24;
      v6[3] = v25;
      v26 = v6 + 4;
      v27 = HIDWORD(v90);
      v28 = v91;
      *v26 = v90;
      v26[1] = v27;
      v26[2] = v28;
      if ( v12 )
        *v12 = 28;
      return 0;
    case 1:
      if ( a4 != 32 )
        return -1073741820;
      v14 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v14 < 0 )
        return v14;
      v90 = (unsigned int)KeMaximumIncrement * (unsigned __int64)*(unsigned int *)(v76[0] + 404);
      v91 = (unsigned int)KeMaximumIncrement * (unsigned __int64)*(unsigned int *)(v76[0] + 448);
      v86 = *(_DWORD *)(v76[0] + 832);
      v87 = *(_DWORD *)(v76[0] + 836);
      if ( *(_BYTE *)(v76[0] + 4) )
      {
        v88 = *(_DWORD *)(v76[0] + 840);
        v33 = *(_DWORD *)(v76[0] + 844);
      }
      else
      {
        v33 = 0;
        v88 = 0;
      }
      v89 = v33;
      ObfDereferenceObjectWithTag(v76[0]);
      v34 = v87;
      v35 = v88;
      v36 = v89;
      *v6 = v86;
      v6[1] = v34;
      v6[2] = v35;
      v6[3] = v36;
      v37 = v6 + 4;
      v38 = HIDWORD(v90);
      v39 = v91;
      *v37 = v90;
      v37[1] = v38;
      *((_QWORD *)v37 + 1) = v39;
      if ( v12 )
        *v12 = 32;
      return 0;
    case 6:
      v16 = ObReferenceObjectByHandleWithTag(v77, 64, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 < 0 )
        return v16;
      v16 = xKdEnumerateDebuggingDevices();
      goto LABEL_58;
    case 9:
      if ( a4 != 4 )
        return -1073741820;
      v40 = ObReferenceObjectByHandleWithTag(v77, 64, PsThreadType, v8, 2035381072, v76, 0);
      v82 = v40;
      if ( v40 >= 0 )
      {
        v41 = *(_DWORD *)(v76[0] + 924);
        ObfDereferenceObjectWithTag(v76[0]);
        *v6 = v41;
        if ( v12 )
          *v12 = 4;
      }
      return v40;
    case 11:
      if ( a4 != 8 )
        return -1073741820;
      v40 = ObReferenceObjectByHandleWithTag(v77, 64, PsThreadType, v8, 2035381072, v76, 0);
      v82 = v40;
      if ( v40 >= 0 )
      {
        ObfDereferenceObjectWithTag(v76[0]);
        *v6 = 0;
        v6[1] = 0;
        if ( v12 )
          *v12 = 8;
      }
      return v40;
    case 12:
      if ( a4 != 4 )
        return -1073741820;
      v42 = *(_DWORD *)(*(_DWORD *)(v7 + 336) + 404);
      __dmb(0xBu);
      *v6 = v42 == 1;
      if ( v12 )
        *v12 = 4;
      return 0;
    case 14:
      if ( a4 != 4 )
        return -1073741820;
      v40 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      v82 = v40;
      if ( v40 >= 0 )
      {
        v43 = (*(_DWORD *)(v76[0] + 80) & 2) != 0;
        ObfDereferenceObjectWithTag(v76[0]);
        *v6 = v43;
        if ( v12 )
          *v12 = 4;
      }
      return v40;
    case 16:
      if ( a4 != 4 )
        return -1073741820;
      v14 = ObReferenceObjectByHandleWithTag(v77, 64, PsThreadType, v8, 2035381072, v76, 0);
      if ( v14 < 0 )
        return v14;
      v44 = *(_DWORD *)(v76[0] + 908) != v76[0] + 908;
      ObfDereferenceObjectWithTag(v76[0]);
      *v6 = v44;
      if ( v12 )
        *v12 = 4;
      return 0;
    case 17:
      if ( a4 != 1 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 64, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 < 0 )
        return v16;
      v47 = v76[0];
      *(_BYTE *)v6 = (*(_DWORD *)(v76[0] + 960) & 4) != 0;
      if ( v12 )
        *v12 = 1;
      goto LABEL_113;
    case 18:
      if ( a4 != 4 )
        return -1073741820;
      v14 = ObReferenceObjectByHandleWithTag(v77, 64, PsThreadType, v8, 2035381072, v76, 0);
      if ( v14 < 0 )
        return v14;
      v45 = (*(_DWORD *)(v76[0] + 960) & 0x20) != 0;
      ObfDereferenceObjectWithTag(v76[0]);
      *v6 = v45;
      if ( v12 )
        *v12 = 4;
      return 0;
    case 20:
      if ( a4 != 4 )
        return -1073741820;
      v14 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v14 < 0 )
        return v14;
      v46 = (*(_DWORD *)(v76[0] + 960) & 1) != 0;
      ObfDereferenceObjectWithTag(v76[0]);
      *v6 = v46;
      if ( v12 )
        *v12 = 4;
      return 0;
    case 21:
      v16 = ObReferenceObjectByHandleWithTag(v77, 8, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 >= 0 )
      {
        v16 = PspQueryLastCallThread(v76[0], v6, a4, v12);
        ObfDereferenceObjectWithTag(v76[0]);
      }
      return v16;
    case 22:
      if ( a4 != 4 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      v82 = v16;
      if ( v16 < 0 )
        return v16;
      v47 = v76[0];
      v48 = (*(_DWORD *)(v76[0] + 960) >> 9) & 7;
      __dmb(0xBu);
      *v6 = v48;
      if ( v12 )
        *v12 = 4;
      goto LABEL_113;
    case 23:
      if ( a4 != 16 )
        return -1073741820;
      v49 = v77;
      if ( v77 == -2 )
      {
        v76[0] = v7;
        v16 = 0;
      }
      else
      {
        v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
        if ( v16 < 0 )
          return v16;
        v7 = v76[0];
        v85 = (BOOL *)v76[0];
      }
      *v6 = KeQueryTotalCycleTimeThread(v7);
      v6[1] = v50;
      v6[2] = v92;
      v6[3] = v93;
      if ( v12 )
        *v12 = 16;
      v47 = (int)v85;
      if ( v49 != -2 )
        goto LABEL_113;
      return v16;
    case 24:
      if ( a4 != 4 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 < 0 )
        return v16;
      v47 = v76[0];
      *v6 = (*(_DWORD *)(v76[0] + 960) >> 12) & 7;
      if ( v12 )
        *v12 = 4;
      goto LABEL_113;
    case 25:
      if ( a4 != 4 )
        return -1073741820;
      v14 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v14 < 0 )
        return v14;
      v29 = *(char *)(v76[0] + 347);
      ObfDereferenceObjectWithTag(v76[0]);
      *v6 = v29;
      if ( v12 )
        *v12 = 4;
      return 0;
    case 26:
      if ( a4 != 12 )
        return -1073741820;
      if ( v8 )
      {
        v51 = v6[1];
        v52 = v6[2];
        v94[0] = *v6;
        v94[1] = v51;
        v94[2] = v52;
        ProbeForWrite(v94[0], v52, 1);
        v8 = v83;
        v6 = v94;
      }
      v85 = v6;
      v16 = ObReferenceObjectByHandleWithTag(v77, 24, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 < 0 )
        return v16;
      v53 = v76[0];
      if ( (*(_DWORD *)(v76[0] + 76) & 0x400) != 0 )
      {
        ObfDereferenceObjectWithTag(v76[0]);
        return -1073741816;
      }
      v54 = *(_DWORD *)(v76[0] + 336);
      v77 = v54;
      v55 = v6[2];
      if ( v55 && (v56 = v6[1], v56 < 0x1000) && v55 <= 4096 - v56 )
      {
        v57 = (unsigned int *)(v76[0] + 940);
        __pld((void *)(v76[0] + 940));
        v58 = *(_DWORD *)(v76[0] + 940) & 0xFFFFFFFE;
        do
          v59 = __ldrex(v57);
        while ( v59 == v58 && __strex(v58 + 2, v57) );
        __dmb(0xBu);
        if ( v59 != v58 )
        {
          if ( !ExfAcquireRundownProtection(v57) )
          {
            ObfDereferenceObjectWithTag(v53);
            return -1073741749;
          }
          v54 = v77;
        }
        v60 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        if ( v54 == v60 )
          memmove(*v6, v6[1] + *(_DWORD *)(v53 + 156), v6[2]);
        else
          v16 = MmCopyVirtualMemory(v54, *(_DWORD *)(v53 + 156) + v6[1], v60, *v6, v6[2], v83, &v85);
        v61 = (unsigned int *)(v76[0] + 940);
        __pld((void *)(v76[0] + 940));
        v62 = *v61 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v63 = __ldrex(v61);
        while ( v63 == v62 && __strex(v62 - 2, v61) );
        if ( v63 != v62 )
          ExfReleaseRundownProtection((unsigned __int8 *)v61);
        ObfDereferenceObjectWithTag(v76[0]);
        if ( v16 >= 0 )
        {
          if ( v12 )
            *v12 = v6[2];
          v16 = 0;
          v82 = 0;
        }
      }
      else
      {
        ObfDereferenceObjectWithTag(v76[0]);
        v16 = -1073741811;
      }
      return v16;
    case 29:
      v16 = ObReferenceObjectByHandleWithTag(v77, 8, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 >= 0 )
      {
        ObfDereferenceObjectWithTag(v76[0]);
        v16 = -1073741822;
      }
      return v16;
    case 30:
      if ( a4 != 12 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 < 0 )
        return v16;
      v30 = v76[0];
      KeQueryAffinityThread(v76[0], (int)&v95);
      v31 = v96;
      v32 = v97;
      *v6 = v95;
      v6[1] = v31;
      v6[2] = v32;
      if ( v12 )
        *v12 = 12;
      goto LABEL_47;
    case 32:
      if ( a4 != 1 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 64, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 >= 0 )
      {
        v64 = v76[0];
        *(_BYTE *)v6 = *(_DWORD *)(v76[0] + 236) != 0;
        ObfDereferenceObjectWithTag(v64);
        if ( v12 )
          *v12 = 1;
      }
      return v16;
    case 33:
      if ( a4 != 4 )
        return -1073741820;
      v14 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v14 < 0 )
        return v14;
      v83 = 0x200000;
      KeSetIdealProcessorThreadByNumber(v76[0], (unsigned __int16 *)&v83, (int)&v83, 0);
      ObfDereferenceObjectWithTag(v76[0]);
      *v6 = v83;
      if ( v12 )
        *v12 = 4;
      return 0;
    case 34:
      if ( !a4 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 64, PsThreadType, v8, 2035381072, v76, 0);
      v82 = v16;
      if ( v16 >= 0 )
      {
        v65 = *(_DWORD *)(v76[0] + 68);
        __dmb(0xBu);
        *(_BYTE *)v6 = v65 != 0;
        if ( v12 )
          *v12 = 1;
        v16 = v82;
LABEL_58:
        ObfDereferenceObjectWithTag(v76[0]);
      }
      return v16;
    case 35:
      if ( a4 != 4 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 < 0 )
        return v16;
      v47 = v76[0];
      *v6 = *(char *)(v76[0] + 396) + ((*(_DWORD *)(v76[0] + 80) >> 13) & 1);
      if ( v12 )
        *v12 = 4;
      goto LABEL_113;
    case 36:
      if ( a4 != 4 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 < 0 )
        return v16;
      v30 = v76[0];
      *v6 = KeQueryHeteroCpuPolicyThread(v76[0], 1);
      if ( v12 )
        *v12 = 4;
      goto LABEL_47;
    case 37:
      if ( a4 != 16 )
        return -1073741820;
      v66 = v77;
      if ( v77 == -2 )
      {
        v76[0] = v7;
      }
      else
      {
        v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
        if ( v16 < 0 )
          return v16;
        v7 = v76[0];
        v85 = (BOOL *)v76[0];
      }
      v16 = PsGetEffectiveContainerId(4, v7, (int)&v86);
      if ( v16 >= 0 )
      {
        *v6 = v86;
        v6[1] = v87;
        v6[2] = v88;
        v6[3] = v89;
        if ( v12 )
          *v12 = 16;
        v47 = (int)v85;
        if ( v66 != -2 )
LABEL_113:
          ObfDereferenceObjectWithTag(v47);
      }
      return v16;
    case 39:
      if ( (a4 & 7) != 0 || a4 > 8 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 >= 0 )
      {
        v67 = KeQueryCpuSetsThread(v76[0], v98);
        ObfDereferenceObjectWithTag(v76[0]);
        v68 = 8 * v67;
        if ( v12 )
          *v12 = v68;
        if ( v68 >= a4 )
          v68 = a4;
        memmove((int)v6, (int)v98, v68);
      }
      return v16;
    case 40:
      if ( a4 != 64 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      v82 = v16;
      if ( v16 < 0 )
        return v16;
      v30 = v76[0];
      KeQueryValuesThread(v76[0], (int)&v77);
      if ( (*(_DWORD *)(v30 + 76) & 0x400) != 0 )
      {
        v70 = *(_DWORD *)(v30 + 924);
      }
      else
      {
        v69 = *(_BYTE *)(v30 + 968);
        __dmb(0xBu);
        if ( (v69 & 8) != 0
          || (v70 = *(_DWORD *)(v76[0] + 856), __dmb(0xFu), v71 = *(_BYTE *)(v30 + 968), __dmb(0xBu), (v71 & 8) != 0) )
        {
          v70 = 0;
        }
        v16 = v82;
        v30 = v76[0];
      }
      if ( v70 > MmHighestUserAddress )
        v70 = 0;
      v6[13] = v78;
      v6[14] = v79;
      v6[11] = v81;
      v6[10] = v80;
      v6[6] = v77;
      v72 = KeMaximumIncrement;
      *(_QWORD *)v6 = (unsigned int)KeMaximumIncrement * (unsigned __int64)*(unsigned int *)(v30 + 404);
      *((_QWORD *)v6 + 1) = (unsigned int)v72 * (unsigned __int64)*(unsigned int *)(v30 + 448);
      v6[4] = *(_DWORD *)(v30 + 832);
      v6[5] = *(_DWORD *)(v30 + 836);
      v6[12] = *(_DWORD *)(v30 + 128);
      v6[8] = *(_DWORD *)(v30 + 876);
      v6[9] = *(_DWORD *)(v30 + 880);
      v6[7] = v70;
      if ( v12 )
        *v12 = 64;
      goto LABEL_47;
    case 41:
      if ( a4 != 12 )
        return -1073741820;
      v16 = ObReferenceObjectByHandleWithTag(v77, 2048, PsThreadType, v8, 2035381072, v76, 0);
      if ( v16 >= 0 )
      {
        v30 = v76[0];
        KeQueryActualAffinityThread(v76[0], (int)&v95);
        v73 = v96;
        v74 = v97;
        *v6 = v95;
        v6[1] = v73;
        v6[2] = v74;
        if ( v12 )
          *v12 = 12;
LABEL_47:
        ObfDereferenceObjectWithTag(v30);
      }
      return v16;
    default:
      return -1073741821;
  }
}
