// PopFxRegisterDeviceWorker 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopFxRegisterDeviceWorker(int *a1, int a2, int *a3, int a4, unsigned int a5, int a6, char a7, int a8, int a9, int a10, _DWORD *a11)
{
  int v12; // r9
  _BYTE *v15; // r0
  unsigned int v16; // r6
  unsigned int v17; // r4
  unsigned int v18; // r7
  unsigned int v19; // lr
  _DWORD *v20; // r1
  unsigned int v21; // r2
  unsigned int v22; // r3
  int v23; // r1
  int v24; // r8
  int v25; // r6
  int v26; // r4
  int v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r0
  _DWORD *v31; // r6
  int v32; // r4
  _BYTE *v33; // r7
  int v34; // r10
  _DWORD *v35; // r2
  _DWORD *v36; // r1
  int v37; // r3
  int v38; // r2
  int v39; // r2
  _DWORD *v40; // lr
  unsigned int v41; // r2
  _DWORD *v42; // lr
  _BYTE *v43; // r4 OVERLAPPED
  int v44; // r0
  unsigned int j; // r4
  unsigned int v46; // lr
  int v47; // r1
  int v48; // r0
  _BYTE *v49; // r2
  int v50; // r1
  int v51; // r3
  unsigned int v52; // r5
  int v53; // r3
  int *v54; // lr
  int v55; // r0
  int v56; // r1
  int v57; // r2
  int v58; // r3
  int v59; // r2
  int v60; // r3
  unsigned int v61; // r1
  int v62; // r2
  unsigned int v63; // r0
  unsigned int v64; // r3
  int v65; // r1
  int v66; // r2
  int v67; // r3
  int v68; // r3
  int (__fastcall *v69)(_DWORD *); // r3
  unsigned int v70; // r2
  int v71; // r3
  int v72; // r3
  _DWORD *v73; // r1
  int v74; // r3
  int v75; // r1
  int v76; // r1
  int v77; // r2
  int v78; // r3
  int v79; // r0
  __int64 v80; // r2
  unsigned int v81; // [sp+8h] [bp-80h]
  unsigned int v82; // [sp+8h] [bp-80h]
  unsigned int v83; // [sp+Ch] [bp-7Ch]
  unsigned int v84; // [sp+Ch] [bp-7Ch]
  unsigned int v85; // [sp+10h] [bp-78h]
  unsigned int v86; // [sp+10h] [bp-78h]
  unsigned int v87; // [sp+14h] [bp-74h]
  unsigned int v88; // [sp+14h] [bp-74h]
  _DWORD *v89; // [sp+18h] [bp-70h]
  _DWORD *v90; // [sp+1Ch] [bp-6Ch]
  char *v91; // [sp+20h] [bp-68h]
  int v92; // [sp+24h] [bp-64h]
  _DWORD *v93; // [sp+28h] [bp-60h] BYREF
  int v94; // [sp+2Ch] [bp-5Ch]
  _DWORD *v95; // [sp+30h] [bp-58h] BYREF
  _DWORD *v96; // [sp+34h] [bp-54h]
  int *v97; // [sp+38h] [bp-50h]
  _BYTE *v98; // [sp+3Ch] [bp-4Ch]
  int v99; // [sp+40h] [bp-48h]
  _DWORD *v100; // [sp+44h] [bp-44h]
  _BYTE *v101; // [sp+48h] [bp-40h]
  unsigned int v102; // [sp+4Ch] [bp-3Ch]
  int v103; // [sp+50h] [bp-38h]
  unsigned int v104; // [sp+54h] [bp-34h]
  unsigned int v105; // [sp+58h] [bp-30h]
  unsigned int v106; // [sp+5Ch] [bp-2Ch]
  int *v107; // [sp+60h] [bp-28h]
  int i; // [sp+64h] [bp-24h]
  int v109; // [sp+68h] [bp-20h]

  v96 = (_DWORD *)a4;
  v97 = a3;
  v12 = 0;
  v103 = a2;
  v107 = a1;
  v95 = 0;
  v93 = 0;
  if ( !a5 )
    return sub_812744();
  v15 = (_BYTE *)ExAllocatePoolWithTag(1, 12 * a5, 1297630800);
  v98 = v15;
  if ( !v15 )
    return -1073741670;
  v16 = 0;
  v99 = 0;
  v17 = 0;
  memset(v15, 0, 12 * a5);
  v18 = 0;
  v19 = (unsigned int)v98;
  v20 = (_DWORD *)a4;
  do
  {
    v21 = v20[7];
    if ( !v21 || v21 > 1 && (!*a3 || !a3[1] || !a3[2] || v20[6] >= v21) || v21 + v17 < v17 )
      goto LABEL_63;
    v17 += v21;
    v22 = v20[9];
    if ( v22 )
    {
      if ( v22 < a5 )
      {
        v62 = v22 + v16;
        if ( v22 + v16 >= v16 )
        {
          v16 += v22;
          v63 = 0;
          v99 = v62;
          while ( 1 )
          {
            v64 = *(_DWORD *)(v20[10] + 4 * v63);
            if ( v64 >= a5 )
              break;
            ++v63;
            ++*(_DWORD *)(v19 + 12 * v64 + 8);
            if ( v63 >= v20[9] )
              goto LABEL_9;
          }
        }
      }
LABEL_63:
      v32 = -1073741811;
      goto LABEL_24;
    }
LABEL_9:
    ++v18;
    v20 += 12;
  }
  while ( v18 < a5 );
  v105 = (4 * a5 + 7) & 0xFFFFFFF8;
  v23 = 3 * v17;
  v87 = (v105 + 192 * a5 + 7) & 0xFFFFFFF8;
  v24 = v87 + 24 * v17;
  v104 = 0;
  if ( a7 > 0 )
  {
    v104 = (v24 + 7) & 0xFFFFFFF8;
    v24 = v104 + 152;
  }
  v100 = 0;
  v101 = 0;
  v81 = 0;
  v83 = 0;
  if ( v16 )
  {
    v81 = (v24 + 3) & 0xFFFFFFFC;
    v83 = (v81 + 8 * v16 + 3) & 0xFFFFFFFC;
    v24 = v83 + 8 * v16;
  }
  v25 = v103;
  v26 = ((((4 * a5 + 19) & 0xFFFFFFF8) + 40 * a5 + 7) & 0xFFFFFFF8) + 24 * v17;
  v92 = ((((4 * a5 + 19) & 0xFFFFFFF8) + 40 * a5 + 7) & 0xFFFFFFF8) + 8 * v23;
  v85 = (4 * a5 + 19) & 0xFFFFFFF8;
  v27 = PopFxFindAcpiDeviceByUniqueId(v103, (int *)&v95);
  v12 = (int)v95;
  if ( v27 >= 0 )
  {
    v31 = v95;
    v93 = v95;
LABEL_18:
    v33 = (_BYTE *)ExAllocatePoolWithTag(512, v24, 1297630800);
    if ( !v33 || (v34 = ExAllocatePoolWithTag(512, v26, 1297630800)) == 0 )
    {
      v32 = -1073741670;
      goto LABEL_21;
    }
    memset(v33, 0, v24);
    v54 = v97;
    v31[97] = a5;
    v31[98] = v33;
    v55 = *v54;
    v56 = v54[1];
    v57 = v54[2];
    v58 = v54[3];
    v54 += 4;
    v31[15] = v55;
    v31[16] = v56;
    v31[17] = v57;
    v31[18] = v58;
    v59 = v54[1];
    v60 = v54[2];
    v31[19] = *v54;
    v31[20] = v59;
    v31[21] = v60;
    v31[22] = a6;
    v31[86] = 0;
    __dmb(0xBu);
    do
      v61 = __ldrex((unsigned int *)&PopFxDeviceAccountingLevel);
    while ( !v61 && __strex(0, (unsigned int *)&PopFxDeviceAccountingLevel) );
    v106 = v61;
    __dmb(0xBu);
    v31[89] = v61;
    v31[88] = 5;
    memset((_BYTE *)v34, 0, v92);
    *(_DWORD *)(v34 + 8) = a5;
    *(_DWORD *)v34 = a9;
    *(_DWORD *)(v34 + 4) = a10;
    v43 = &v33[v105];
    v91 = &v33[v87];
    if ( v99 )
    {
      v100 = &v33[v81];
      v101 = &v33[v83];
    }
    v90 = (_DWORD *)(((((4 * a5 + 19) & 0xFFFFFFF8) + 40 * a5 + 7) & 0xFFFFFFF8) + v34);
    v41 = 0;
    v94 = 0;
    v109 = v85 + v34;
    v89 = (_DWORD *)(v85 + v34);
    v84 = (4 * a5 + 19) & 0xFFFFFFF8;
    v42 = v96;
    v82 = (unsigned int)v98;
    v44 = -20 - (_DWORD)v33;
    for ( i = -20 - (_DWORD)v33; ; v44 = i )
    {
      *(_DWORD *)(v31[98] + 4 * v41) = v43;
      if ( (unsigned int)&v43[v44 + 20] > v24 - 192 )
        goto LABEL_76;
      v65 = v42[1];
      v66 = v42[2];
      v67 = v42[3];
      *(_DWORD *)v43 = *v42;
      *((_DWORD *)v43 + 1) = v65;
      *((_DWORD *)v43 + 2) = v66;
      *((_DWORD *)v43 + 3) = v67;
      v68 = v94;
      *((_DWORD *)v43 + 12) = v31;
      *((_DWORD *)v43 + 4) = v68;
      v69 = PopFxComponentWork;
      *(_QWORD *)(v43 + 28) = *(_QWORD *)(&v43 - 1);
      *((_DWORD *)v43 + 5) = 0;
      KeInitializeEvent((int)(v43 + 64), 0, 1);
      v40 = v96;
      v70 = 0;
      *((_DWORD *)v43 + 20) = 0;
      *((_DWORD *)v43 + 27) = v40[7];
      *((_DWORD *)v43 + 28) = v91;
      v71 = v40[6];
      *((_DWORD *)v43 + 36) = 0;
      *((_DWORD *)v43 + 29) = v71;
      *((_DWORD *)v43 + 39) = v106;
      *((_DWORD *)v43 + 38) = -1;
      v72 = v40[9];
      if ( v72 )
      {
        v73 = v100;
        *((_DWORD *)v43 + 30) = v72;
        *((_DWORD *)v43 + 31) = v73;
        do
        {
          v74 = *(_DWORD *)(v40[10] + 4 * v70++);
          *v73 = v74;
          v73 += 2;
        }
        while ( v70 < *((_DWORD *)v43 + 30) );
        v100 = v73;
      }
      if ( *(_DWORD *)(v82 + 8) )
      {
        v75 = (int)v101;
        *((_DWORD *)v43 + 34) = v101;
        v101 = (_BYTE *)(v75 + 8 * *(_DWORD *)(v82 + 8));
      }
      *(_DWORD *)(v34 + 4 * v94 + 12) = v89;
      if ( v84 > v92 - 40 )
        goto LABEL_76;
      v76 = v40[1];
      v77 = v40[2];
      v78 = v40[3];
      *v89 = *v40;
      v89[1] = v76;
      v89[2] = v77;
      v89[3] = v78;
      v36 = v89;
      v52 = a5;
      v89[4] = v40[4];
      v89[5] = v40[5];
      v89[7] = v40[7];
      v89[8] = v90;
      v89[6] = v40[6];
      v88 = 0;
      if ( *((_DWORD *)v43 + 27) )
        break;
LABEL_35:
      v89 = v36 + 10;
      v41 = v94 + 1;
      v42 = v40 + 12;
      v43 += 192;
      v82 += 12;
      v84 += 40;
      v94 = v41;
      v96 = v42;
      if ( v41 >= a5 )
      {
        if ( v99 )
        {
          v32 = PopFxVerifyDependencies(v98, v31, a5);
          if ( v32 < 0 )
            goto LABEL_49;
        }
        for ( j = 0; j < a5; ++j )
        {
          v46 = 0;
          v47 = *(_DWORD *)(v31[98] + 4 * j);
          if ( *(_DWORD *)(v47 + 120) )
          {
            do
            {
              v79 = *(_DWORD *)(v31[98] + 4 * *(_DWORD *)(*(_DWORD *)(v47 + 124) + 8 * v46));
              v80 = *(_QWORD *)(v79 + 132);
              *(_DWORD *)(HIDWORD(v80) + 8 * v80) = j;
              *(_DWORD *)(*(_DWORD *)(v79 + 136) + 8 * v80 + 4) = v46++;
              ++*(_DWORD *)(v79 + 132);
            }
            while ( v46 < *(_DWORD *)(v47 + 120) );
          }
          PopFxActivateComponent((int)v31, v47, 0, 1);
        }
        if ( a7 <= 0 || (v31[3] = &v33[v104], v48 = IoAllocateIrp(a7 + 2, 0), (v31[2] = v48) != 0) )
        {
          if ( !PopFxRegisterDeviceWithPep(v107, v103, (int)v31, v34) )
            PopFxBugCheck(1537, (int)v31, v34, 0);
          v49 = &v33[v105];
          v50 = v109;
          do
          {
            if ( (*(_DWORD *)(v50 + 16) & 2) != 0 )
            {
              v53 = *((_DWORD *)v49 + 14) | 2;
              __dmb(0xBu);
              *((_DWORD *)v49 + 14) = v53;
            }
            v51 = *(_DWORD *)(v50 + 28);
            v50 += 40;
            *((_DWORD *)v49 + 27) = v51;
            v49 += 192;
            --v52;
          }
          while ( v52 );
          v12 = (int)v95;
          v33 = 0;
          *a11 = v93;
          v31 = 0;
          v32 = 0;
LABEL_49:
          ExFreePoolWithTag(v34);
LABEL_21:
          if ( v31 && !v12 )
            ExFreePoolWithTag((unsigned int)v31);
          if ( v33 )
            ExFreePoolWithTag((unsigned int)v33);
          goto LABEL_24;
        }
LABEL_76:
        v32 = -1073741670;
        goto LABEL_49;
      }
    }
    v86 = (unsigned int)v90 - v34;
    v39 = 0;
    v97 = 0;
    v102 = v91 - v33;
    while ( 1 )
    {
      v35 = (_DWORD *)(v39 + v40[8]);
      if ( v102 > v24 - 24 )
        goto LABEL_76;
      *((_DWORD *)v91 + 4) = v35[4];
      *(_DWORD *)v91 = *v35;
      *((_DWORD *)v91 + 1) = v35[1];
      *((_DWORD *)v91 + 2) = v35[2];
      *((_DWORD *)v91 + 3) = v35[3];
      v91 += 24;
      v102 += 24;
      v36 = v89;
      if ( v86 > v92 - 24 )
        goto LABEL_76;
      v90[4] = v35[4];
      *v90 = *v35;
      v90[1] = v35[1];
      v90[2] = v35[2];
      v37 = v35[3];
      v38 = (int)v97;
      v90[3] = v37;
      v39 = v38 + 24;
      v86 += 24;
      v90 += 6;
      v97 = (int *)v39;
      ++v88;
      v40 = v96;
      if ( v88 >= *((_DWORD *)v43 + 27) )
        goto LABEL_35;
    }
  }
  if ( v27 == -1073741738 )
  {
    v32 = -1073741661;
    v12 = (int)v95;
    goto LABEL_24;
  }
  v30 = PopFxCreateDeviceCommon(v25, v28, v29, 0, &v93);
  v31 = v93;
  v32 = v30;
  if ( v93 )
  {
    v26 = v92;
    goto LABEL_18;
  }
LABEL_24:
  ExFreePoolWithTag((unsigned int)v98);
  if ( v12 )
    PopFxReleaseAcpiRefDevice(v12);
  return v32;
}
