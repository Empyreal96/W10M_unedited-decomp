// PpmIdleSelectStates 
 
int *__fastcall PpmIdleSelectStates(int a1, _QWORD *a2, int *a3, int a4, int a5, int a6, bool *a7)
{
  int v7; // r6
  int v8; // r5
  __int16 v9; // r7
  int v10; // r8
  int v11; // r9
  char v12; // r10
  int *v13; // r2
  int v14; // r4
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r3
  char v21; // r2
  int v22; // r1
  int v23; // r3
  int *result; // r0
  int *v25; // r1
  int *v26; // r0
  int v27; // r4
  int v28; // r2
  int v29; // r3
  int *v30; // r9
  int v31; // r1
  int v32; // r10
  int *v33; // r2
  int v34; // r8
  int v35; // r4
  int v36; // r7
  __int64 v37; // r0
  int v38; // r7
  int v39; // r0
  int v40; // r1
  int v41; // r2
  int v42; // r3
  bool v43; // r3
  char v44; // r1
  int v45; // r3
  int *v46; // r1
  int *v47; // r2
  int v48; // r3
  _BYTE *v49; // r2
  int v50; // r4
  void **v51; // lr
  int v52; // t1
  int v53; // r4
  int *v54; // r0
  int v55; // r3
  int v56; // r3
  unsigned int v57; // r2
  int *v58; // r2
  int v59; // r1
  int v60; // r0
  int v61; // r7
  int v62; // r9
  int v63; // r1
  unsigned int v64; // r9
  int v65; // r3
  __int64 v66; // r0
  int v67; // r3
  int v68; // r10
  unsigned int v69; // r3
  unsigned int v70; // r2
  int v71; // r3
  int v72; // r1
  int v73; // r3
  unsigned int v74; // r2
  bool v75; // cf
  unsigned int *v76; // r3
  unsigned int v77; // lr
  unsigned int v78; // r0
  unsigned int v79; // r2
  int v80; // r3
  int v81; // r3
  int v82; // [sp+18h] [bp-C8h]
  int v83; // [sp+18h] [bp-C8h]
  int v85; // [sp+20h] [bp-C0h] BYREF
  int *v86; // [sp+24h] [bp-BCh]
  int *v87; // [sp+28h] [bp-B8h]
  int v88; // [sp+2Ch] [bp-B4h] BYREF
  int v89; // [sp+30h] [bp-B0h] BYREF
  int v90; // [sp+34h] [bp-ACh]
  int v91; // [sp+38h] [bp-A8h]
  int v92; // [sp+3Ch] [bp-A4h] BYREF
  int v93; // [sp+40h] [bp-A0h]
  int *v94; // [sp+44h] [bp-9Ch]
  int v95; // [sp+48h] [bp-98h]
  int v96[2]; // [sp+50h] [bp-90h] BYREF
  int v97; // [sp+58h] [bp-88h] BYREF
  int v98; // [sp+5Ch] [bp-84h]
  int *v99; // [sp+60h] [bp-80h]
  bool *v100; // [sp+64h] [bp-7Ch]
  unsigned int *v101; // [sp+68h] [bp-78h]
  int *v102; // [sp+6Ch] [bp-74h]
  int *v103; // [sp+70h] [bp-70h]
  int v104; // [sp+74h] [bp-6Ch]
  int v105; // [sp+78h] [bp-68h]
  int v106; // [sp+7Ch] [bp-64h]
  int v107; // [sp+80h] [bp-60h]
  int v108; // [sp+84h] [bp-5Ch]
  int v109[2]; // [sp+88h] [bp-58h] BYREF
  _BYTE *v110; // [sp+90h] [bp-50h]
  int v111; // [sp+94h] [bp-4Ch]
  int *v112; // [sp+98h] [bp-48h]
  int *v113; // [sp+9Ch] [bp-44h]
  int *v114; // [sp+A0h] [bp-40h] BYREF
  int v115; // [sp+A4h] [bp-3Ch]
  int v116; // [sp+A8h] [bp-38h]
  int v117; // [sp+ACh] [bp-34h]
  __int16 v118[2]; // [sp+B0h] [bp-30h] BYREF
  int v119; // [sp+B4h] [bp-2Ch]
  int v120; // [sp+B8h] [bp-28h]

  v110 = (_BYTE *)a4;
  v7 = 0;
  v113 = (int *)a5;
  v8 = *(_DWORD *)(a1 + 2944);
  v111 = v8;
  v112 = (int *)a6;
  v100 = a7;
  v82 = 1;
  v106 = 0;
  v9 = 0;
  v101 = *(unsigned int **)(a1 + 2948);
  v102 = a3;
  v108 = -1;
  v104 = 0;
  v88 = 0;
  v89 = 0;
  v10 = 0;
  v11 = 0;
  v103 = (int *)PpmPlatformStates;
  v85 = 0;
  v86 = 0;
  v94 = 0;
  v95 = 0;
  v99 = 0;
  v114 = 0;
  v115 = 0;
  v93 = 0;
  v90 = 0;
  v12 = 0;
  v107 = PopFxSystemLatencyHint;
  __dmb(0xBu);
  *a2 = PpmIdleEvaluateConstraints();
  v13 = v102;
  *(_WORD *)(v8 + 68) = 1;
  *(_WORD *)(v8 + 70) = 1;
  *(_DWORD *)(v8 + 72) = 0;
  *(_DWORD *)(v8 + 76) = 0;
  v91 = *v13;
  v98 = v13[1];
  v14 = *(_DWORD *)(a1 + 2944);
  if ( *(_BYTE *)(a1 + 17) || !KiSerializeTimerExpiration )
  {
    v18 = 0;
    v17 = 0;
  }
  else
  {
    v15 = PpmGetPlatformIdleDurationHint();
    v17 = v16;
    v18 = v15;
  }
  PpmEstimateIdleDuration(a1, 0, v91, v98, v18, v17, v96, v109, &v97, &v92);
  v19 = v109[0];
  v20 = v109[1];
  *(_WORD *)(v14 + 36) |= v92;
  v21 = v97;
  *(_DWORD *)(v14 + 152) = v19;
  *(_DWORD *)(v14 + 156) = v20;
  v22 = v96[0];
  v23 = v96[1];
  *(_BYTE *)(v14 + 173) = v21;
  v105 = -1;
  *(_DWORD *)(v14 + 144) = v22;
  *(_DWORD *)(v14 + 148) = v23;
  if ( *(_DWORD *)(v8 + 92) )
    return (int *)sub_54F9E8();
  v25 = v103;
  v98 = -2147483645;
  if ( v103 )
  {
    *(_WORD *)(v8 + 200) = 1;
    *(_WORD *)(v8 + 202) = 1;
    *(_DWORD *)(v8 + 204) = 0;
    *(_DWORD *)(v8 + 208) = 0;
    v50 = (unsigned __int16)KeNumberNodes;
    if ( KeNumberNodes )
    {
      v51 = &KeNodeBlock;
      do
      {
        v52 = (int)*v51++;
        *(_DWORD *)(v8 + 208) |= *(_DWORD *)(v52 + 128);
        --v50;
      }
      while ( v50 );
    }
    v53 = v8 + 236;
    *(_DWORD *)(v8 + 208) |= 1 << *(_DWORD *)(a1 + 20);
    v54 = *(int **)(v8 + 216);
    v109[0] = v25[8];
    v55 = *v25;
    v86 = v54;
    memset(v54, 0, 4 * (v55 + 2));
    v56 = *(_DWORD *)(v8 + 228);
    v57 = 0;
    v92 = 0;
    if ( v56 )
    {
      v59 = 0;
      v60 = (int)v86;
      v27 = 0;
      v61 = (int)v103;
      v87 = v86;
      v91 = 0;
      v62 = 0;
      do
      {
        v63 = v59 + *(_DWORD *)(v8 + 232);
        if ( *(_BYTE *)(v63 + 1) )
        {
          v64 = *(_DWORD *)(v63 + 4);
          if ( PpmDripsStateIndex == -1 || v64 < PpmDripsStateIndex || !PpmCheckPreConditionsForDeepSleep(a1) )
          {
            if ( v27 == 1 )
            {
              v65 = 1;
              v82 = 1;
            }
            else
            {
              v65 = v82;
            }
            v27 = 0;
          }
          else
          {
            if ( v27 )
            {
              v65 = v82;
            }
            else
            {
              v65 = 1;
              v82 = 1;
            }
            v27 = 1;
          }
          if ( v65 )
          {
            v82 = 0;
            PpmEstimateIdleDuration(a1, v27, *v102, v102[1], 0, 0, &v114, &v89, &v85, &v88);
            v93 = v115;
            v94 = v114;
          }
          *(_DWORD *)(v8 + 240) = 0;
          v96[0] = -1;
          v66 = PpmIdleCheckCoordinatedStateEligibility(a1, v105, v107);
          v67 = *(unsigned __int8 *)(v61 + 12);
          v7 = v96[0];
          v97 = HIDWORD(v66);
          v68 = v66;
          if ( !v67 && !v66 )
          {
            v66 = (unsigned int)(*(int (__fastcall **)(_DWORD, int, unsigned int))(v61 + 16))(
                                  *(_DWORD *)(v8 + 120),
                                  v96[0],
                                  v64);
            v97 = 0;
            v68 = v66;
          }
          PpmIdleUpdateSelectionStatistics(v68, HIDWORD(v66), v109[0] + 992 * v64 + 72);
          if ( !(v68 | v97) )
          {
            result = v86;
            *v100 = 1;
            v70 = v61 + (v64 << 8);
            *result = v64;
            if ( *(_BYTE *)(v70 + 157) )
              v108 = v64;
            v71 = *(_DWORD *)(v8 + 76) & ~*(_DWORD *)(v70 + 172);
            v118[1] = 1;
            v118[0] = 1;
            v119 = 0;
            v120 = v71;
            if ( v71 )
            {
              PpmUnlockProcessors(v8 + 68, v118);
              v9 = v88;
              v10 = v89;
              v11 = v90;
              v12 = v85;
LABEL_84:
              result = v86;
            }
            else
            {
              v9 = v88;
              v10 = v89;
              v11 = v90;
              v12 = v85;
            }
            v40 = 0;
            goto LABEL_25;
          }
          if ( v68 == v98 && !v97 )
            v106 = 1;
          PpmIdleRollbackCoordinatedSelection(v8 + 236, 0);
          v60 = (int)v87;
          v62 = v95;
          v57 = v92;
          v87[2] = v68;
        }
        else
        {
          *(_DWORD *)(v60 + 8) = -2;
        }
        v69 = *(_DWORD *)(v8 + 228);
        v60 += 4;
        v59 = v91 + 16;
        ++v62;
        ++v57;
        v91 += 16;
        v92 = v57;
        v87 = (int *)v60;
        v95 = v62;
      }
      while ( v57 < v69 );
      v9 = v88;
      v10 = v89;
      v11 = v90;
      v12 = v85;
      v53 = v8 + 236;
    }
    v58 = v86;
    *(_DWORD *)(v53 + 4) = 0;
    *v58 = -1;
    PpmUnlockProcessors(v8 + 68, v8 + 68);
  }
  v83 = 1;
  v26 = *(int **)(v8 + 212);
  LOBYTE(v27) = 0;
  v28 = 4 * (*(_DWORD *)(v8 + 28) + 2);
  v87 = 0;
  v99 = v26;
  memset(v26, 0, v28);
  v29 = *(_DWORD *)(v8 + 220);
  v96[0] = 0;
  if ( !v29 )
    goto LABEL_84;
  v30 = v99;
  v31 = 0;
  v32 = (int)v103;
  v33 = &v88;
  v91 = 0;
  v92 = (int)v99;
  v34 = 0;
  while ( 1 )
  {
    v35 = *(_DWORD *)(v8 + 224) + v31;
    v7 = *(_DWORD *)(v35 + 4);
    if ( !v32 && v7 == *(_DWORD *)(v8 + 28) - 1 && *(_BYTE *)(v8 + 172) && PpmCheckPreConditionsForDeepSleep(a1) )
    {
      if ( v34 )
      {
        v36 = v83;
      }
      else
      {
        v36 = 1;
        v83 = 1;
      }
      v34 = 1;
    }
    else
    {
      if ( v34 == 1 )
      {
        v36 = 1;
        v83 = 1;
      }
      else
      {
        v36 = v83;
      }
      v34 = 0;
    }
    v87 = (int *)v34;
    if ( v36 )
    {
      v83 = 0;
      PpmEstimateIdleDuration(a1, v34, *v102, v102[1], 0, 0, &v114, &v89, &v85, v33);
      v93 = v115;
      v94 = v114;
    }
    if ( !v7 )
    {
      LODWORD(v37) = 0;
LABEL_19:
      v38 = 0;
      goto LABEL_20;
    }
    v37 = PpmIdleCheckProcessorStateEligibility(a1, v105, v107);
    v38 = HIDWORD(v37);
    if ( !v37 )
    {
      LODWORD(v37) = (*(int (__fastcall **)(_DWORD, int, int))(v8 + 96))(*(_DWORD *)(v8 + 120), v7, -1);
      goto LABEL_19;
    }
LABEL_20:
    v39 = PpmIdleUpdateSelectionStatistics(v37, v38, &v101[246 * *(_DWORD *)(v35 + 4) + 20]);
    if ( !(v39 | v38) )
      break;
    if ( v39 == v98 && !v38 )
      v106 = 1;
    v72 = v91;
    v73 = v92;
    v74 = v96[0];
    *(_DWORD *)(v92 + 8) = v39;
    v92 = v73 + 4;
    ++v74;
    v31 = v72 + 16;
    v75 = v74 >= *(_DWORD *)(v8 + 220);
    v96[0] = v74;
    v33 = &v88;
    v91 = v31;
    if ( v75 )
    {
      v9 = v88;
      v10 = v89;
      v11 = v90;
      v12 = v85;
      LOBYTE(v27) = (_BYTE)v87;
      goto LABEL_84;
    }
  }
  v7 = *(_DWORD *)(v35 + 4);
  v40 = v96[0];
  v41 = v8 + (v7 << 6);
  *v30 = v7;
  v42 = *(unsigned __int8 *)(v41 + 310);
  v104 = v40;
  v43 = !v42 || v32 && (!*(_BYTE *)(v41 + 313) || v7);
  v9 = v88;
  v10 = v89;
  v11 = v90;
  v12 = v85;
  result = v86;
  LOBYTE(v27) = (_BYTE)v87;
  *v100 = v43;
LABEL_25:
  if ( *v100 )
  {
    v76 = (unsigned int *)(a1 + 3000);
    __pld((void *)(a1 + 3000));
    v101 = v76;
    v77 = *v76;
    do
    {
      v78 = v77;
      __dmb(0xBu);
      do
        v79 = __ldrex(v76);
      while ( v79 == v77 && __strex(v77 & 0xFFFFFF | 0x1000000, v76) );
      v77 = v79;
      __dmb(0xBu);
    }
    while ( v79 != v78 );
    v8 = v111;
    v40 = v104;
    result = v86;
  }
  if ( (dword_682608 & 0x200000) != 0 )
  {
    if ( result )
    {
      v80 = v95;
      result[1] = v95;
      v115 = 0;
      v116 = 4 * (v80 + 2);
      v114 = result;
      v117 = 0;
      result = EtwTraceKernelEvent((int *)&v114, 1, 0x40200000u, 4670, 1538);
      v40 = v104;
    }
    v81 = (int)v99;
    if ( v99 )
    {
      v99[1] = v40;
      v114 = (int *)v81;
      v115 = 0;
      v116 = 4 * (v40 + 2);
      v117 = 0;
      result = EtwTraceKernelEvent((int *)&v114, 1, 0x40200000u, 4669, 1538);
    }
  }
  v44 = v106;
  v45 = (int)v94;
  *(_WORD *)(v8 + 36) |= v9;
  *(_BYTE *)(v8 + 6) = v44;
  *(_DWORD *)(v8 + 144) = v45;
  v46 = v112;
  v47 = v113;
  *(_DWORD *)(v8 + 148) = v93;
  *(_DWORD *)(v8 + 152) = v10;
  v48 = v108;
  *(_DWORD *)(v8 + 156) = v11;
  *(_BYTE *)(v8 + 173) = v12;
  *v47 = v7;
  v49 = v110;
  *v46 = v48;
  *v49 = v27;
  return result;
}
