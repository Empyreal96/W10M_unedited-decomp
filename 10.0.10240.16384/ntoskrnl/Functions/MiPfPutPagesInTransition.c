// MiPfPutPagesInTransition 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiPfPutPagesInTransition(_DWORD *a1, _DWORD *a2)
{
  int v2; // r3
  _DWORD *v3; // r8
  int v4; // r3
  _DWORD *v5; // r10
  int v6; // r6
  int v7; // r1
  int v8; // r7
  int v9; // r3
  int v10; // r4
  int v11; // r3
  _DWORD *v12; // r5
  int v13; // r1
  _QWORD *v14; // r6
  int v15; // r8
  int *v16; // r9
  unsigned int v17; // r4
  _DWORD *v18; // r3
  int v19; // r2
  _DWORD *v20; // r0
  unsigned int i; // r2
  int v22; // r5
  _DWORD *v23; // r0
  int v24; // t1
  unsigned int v25; // r5
  int v27; // r0
  int v28; // r4
  unsigned int v29; // r8
  int v30; // r6
  _DWORD *v31; // r4
  int v32; // r7
  int v33; // r4
  int v34; // r5
  int v35; // r0
  int v36; // r0
  unsigned int *v37; // r2
  unsigned int v38; // r0
  _QWORD *v39; // r0
  int v40; // r1 OVERLAPPED
  _DWORD *v41; // r2 OVERLAPPED
  int v42; // r2
  int v43; // r3
  __int16 v44; // r3
  int v45; // r2
  int v46; // r0
  int v47; // r3
  int v48; // r10
  unsigned int v49; // r8
  BOOL v50; // r6
  _DWORD *v51; // r1
  int v52; // r9
  int v53; // r3
  _DWORD *v54; // r2
  int v55; // r7
  int *v56; // r1
  int *v57; // lr
  int v58; // r2
  int v59; // r2
  int v60; // r1
  int v61; // r2
  int v62; // r3
  _DWORD *v63; // r0
  int v64; // r3
  _DWORD *v65; // r4
  int v66; // [sp+8h] [bp-88h]
  char v67[4]; // [sp+Ch] [bp-84h] BYREF
  _QWORD *v68; // [sp+10h] [bp-80h]
  _DWORD *v69; // [sp+14h] [bp-7Ch]
  int v70; // [sp+18h] [bp-78h]
  int v71; // [sp+1Ch] [bp-74h]
  int v72; // [sp+20h] [bp-70h] BYREF
  int v73; // [sp+24h] [bp-6Ch]
  _DWORD *v74; // [sp+28h] [bp-68h]
  _DWORD *v75; // [sp+2Ch] [bp-64h]
  int v76; // [sp+30h] [bp-60h]
  _DWORD *v77; // [sp+34h] [bp-5Ch]
  int v78; // [sp+38h] [bp-58h]
  int *v79; // [sp+3Ch] [bp-54h]
  int v80; // [sp+40h] [bp-50h]
  int v81; // [sp+44h] [bp-4Ch]
  int v82; // [sp+48h] [bp-48h]
  unsigned int v83; // [sp+4Ch] [bp-44h]
  _WORD *v84; // [sp+50h] [bp-40h] BYREF
  __int16 v85; // [sp+54h] [bp-3Ch]
  unsigned __int16 v86; // [sp+56h] [bp-3Ah]
  int v87; // [sp+58h] [bp-38h]
  int *v88; // [sp+5Ch] [bp-34h]
  unsigned int v89; // [sp+60h] [bp-30h]
  unsigned int v90; // [sp+64h] [bp-2Ch]
  _QWORD *v91; // [sp+68h] [bp-28h]
  _DWORD *v92; // [sp+6Ch] [bp-24h]
  int v93; // [sp+70h] [bp-20h]

  v2 = a1[6];
  v3 = 0;
  v92 = a2;
  v81 = v2;
  v4 = a1[7];
  v5 = a1;
  v74 = a1;
  v75 = 0;
  v80 = v4;
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v83 = 0;
  v7 = a1[6];
  v73 = 17;
  v67[0] = 17;
  v8 = 0;
  v66 = 0;
  v87 = a1[8];
  v93 = v7;
  v9 = __mrc(15, 0, 13, 0, 3);
  v10 = ((*(_DWORD *)(*(_DWORD *)((v9 & 0xFFFFFFC0) + 0x150) + 192) & 0x100000) != 0
      || ((*(_DWORD *)((v9 & 0xFFFFFFC0) + 0x3C0) >> 9) & 7u) < 2)
     && ((v9 & 0xFFFFFFC0) != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || !*(_DWORD *)((v9 & 0xFFFFFFC0) + 0x3E8));
  v68 = (_QWORD *)a1[14];
  v11 = a1[1];
  v78 = v7 & 7 | 0x18;
  v12 = 0;
  v13 = (*(_DWORD *)(v11 + 28) >> 20) & 0x3F;
  v76 = v10;
  v69 = 0;
  MI_INITIALIZE_COLOR_BASE(v6 + 492, v13, &v84);
  v14 = v68;
  v88 = v5 + 14;
  if ( v68 == (_QWORD *)(v5 + 14) )
    goto LABEL_42;
  v15 = 4194300;
  v71 = 4194300;
  while ( 2 )
  {
    v91 = v14;
    if ( v10 == 1 )
    {
      *((_BYTE *)v14 + 113) |= 0x40u;
    }
    else if ( (v5[11] & 1) != 0 )
    {
      *((_BYTE *)v14 + 113) |= 0x10u;
    }
    v16 = (int *)*((_DWORD *)v14 + 34);
    *((_DWORD *)v14 + 34) = *v16 & 0xFFFFFFFC;
    v90 = *v16 & 0xFFFFFFFC;
    v17 = *((_DWORD *)v14 + 29) + 4;
    v18 = (_DWORD *)*((_DWORD *)v14 + 36);
    v89 = v17;
    v19 = v18[6];
    v77 = v18;
    v20 = v18 + 7;
    for ( i = ((((_WORD)v19 + (unsigned __int16)v18[4]) & 0xFFFu) + v18[5] + 4095) >> 12; i; ++v20 )
    {
      --i;
      *v20 = dword_6348FC;
    }
    v22 = 0;
    v70 = 0;
    if ( !v69 )
    {
      v23 = (_DWORD *)MiGetInPageSupportBlock(0);
      v69 = v23;
      if ( v23 )
      {
        v23[35] = 0;
        MiSetInPagePriority();
      }
    }
    if ( (unsigned int)v16 >= v17 )
      goto LABEL_33;
    while ( 1 )
    {
      v24 = *v16++;
      v79 = v16;
      v25 = v24 & 0xFFFFFFFC;
      if ( v8 )
      {
        if ( v83 != (v15 & (v25 >> 10)) - 0x40000000 )
          return sub_538E7C();
      }
      else
      {
        v83 = (v15 & (v25 >> 10)) - 0x40000000;
        while ( 1 )
        {
          v36 = MiLockProtoPoolPage(v25, v67);
          v66 = v36;
          if ( v36 )
            break;
          MmAccessFault(1, v25, 0, 0);
        }
        v5 = v74;
        v8 = v36;
        v73 = (unsigned __int8)v67[0];
      }
      v27 = MiLockLeafPage((unsigned int *)v25, 0);
      v28 = v27;
      v29 = *(_DWORD *)v25;
      if ( v27 )
      {
        MiUpdatePfnPriority(v27, v93, 0);
        __dmb(0xBu);
        v37 = (unsigned int *)(v28 + 12);
        do
          v38 = __ldrex(v37);
        while ( __strex(v38 & 0x7FFFFFFF, v37) );
        goto LABEL_31;
      }
      if ( (v29 & 0x400) != 0 )
      {
        v30 = 1;
      }
      else
      {
        if ( (v29 & 2) == 0 && (v29 & 0x800) == 0 && (v29 & 0x10) == 0 || !v69 )
          goto LABEL_31;
        v30 = 2;
      }
      v31 = (_DWORD *)v5[5];
      v32 = 0;
      v82 = 0;
      if ( !v31 )
        break;
      v5[5] = *v31;
      v72 = ((int)v31 - MmPfnDatabase) / 24;
LABEL_23:
      if ( (*(v16 - 1) & 1) != 0 && v31[2] )
      {
        v32 = 1;
        v82 = 1;
      }
      if ( v30 == 1 )
      {
        v14 = v68;
        if ( !*((_DWORD *)v68 + 35) )
          *((_DWORD *)v68 + 35) = v31;
        ++v70;
        MiInitializeReadInProgressPfn(-1, &v72, 1, v25, v14 + 2, v78);
        MiReferenceControlAreaPfn(v5[1], v29 & 0xFFFFF800 | (2 * (v29 & 0x3FC)), 1);
        v33 = v72;
        v77[((int)(v25 - v90) >> 2) + 7] = v72;
        if ( !*((_DWORD *)v14 + 23) )
        {
          MiObtainProtoReference(v66, 0);
          *((_DWORD *)v14 + 23) = v66;
        }
        if ( v32 == 1 )
        {
          MiUnlockProtoPoolPage(v66, v73);
          v8 = 0;
          v66 = 0;
          MiZeroPhysicalPage(v33, 1, *(unsigned __int8 *)(MmPfnDatabase + 24 * v33 + 18) >> 6);
          goto LABEL_31;
        }
      }
      else
      {
        MiReturnCommit(MiSystemPartition, 1);
        MiInitializeReadInProgressPfn(-1, &v72, 1, v25, v69 + 4, v78);
        v47 = (v29 >> 4) & 1;
        v48 = (v29 >> 2) & 1;
        if ( v47 )
          v49 = v29 >> 13;
        else
          v49 = 0;
        if ( v47 )
          v50 = v48 == dword_63F99C;
        else
          v50 = 0;
        v51 = v69;
        v52 = *(_DWORD *)&MiSystemPartition[2 * v48 + 1800];
        v53 = v76;
        v54 = v69 + 38;
        v69[36] = v69 + 38;
        if ( v53 == 1 )
          *((_BYTE *)v51 + 113) |= 0x40u;
        *v54 = 0;
        *((_WORD *)v54 + 3) = 0;
        v54[4] = 0;
        v54[6] = 0;
        v54[5] = 4096;
        *((_WORD *)v54 + 2) = 32;
        v55 = v72;
        *((_WORD *)v51 + 79) |= 0x4042u;
        v51[45] = v55;
        MiObtainProtoReference(v66, 0);
        v56 = v69;
        v57 = v88;
        v69[23] = v66;
        v58 = *v57;
        *v56 = *v57;
        v56[1] = (int)v57;
        if ( *(int **)(v58 + 4) != v57 )
          __fastfail(3u);
        *(_DWORD *)(v58 + 4) = v56;
        v59 = (int)v74;
        *v57 = (int)v56;
        v60 = v73;
        ++*(_DWORD *)(v59 + 48);
        MiUnlockProtoPoolPage(v66, v60);
        v66 = 0;
        if ( v82 == 1 )
          MiZeroPhysicalPage(v55, 1, *(unsigned __int8 *)(MmPfnDatabase + 24 * v55 + 18) >> 6);
        v61 = (int)v69;
        v69[32] = 0;
        if ( v50 )
        {
          *(_DWORD *)(v61 + 56) = v49 & 0xFFFFFFF | (v48 << 28);
          *(_DWORD *)(v61 + 60) = 0;
          *(_BYTE *)(v61 + 113) |= 0x80u;
        }
        else
        {
          *(_DWORD *)(v61 + 56) = v49 << 12;
          *(_DWORD *)(v61 + 60) = 0;
        }
        v62 = *(_DWORD *)(v52 + 32);
        *(_DWORD *)(v61 + 136) = v25;
        *(_DWORD *)(v61 + 140) = v31;
        *(_DWORD *)(v61 + 116) = v62;
        *(_BYTE *)(v61 + 115) |= 0x10u;
        v63 = (_DWORD *)MiGetInPageSupportBlock(0);
        v69 = v63;
        if ( v63 )
        {
          v63[35] = 0;
          MiSetInPagePriority();
        }
        v14 = v68;
        v5 = v74;
        v16 = v79;
      }
      v8 = v66;
LABEL_31:
      v15 = v71;
      if ( (unsigned int)v16 >= v89 )
        goto LABEL_32;
    }
    if ( !MiPrefetchNormally((int)MiSystemPartition) )
      goto LABEL_99;
    if ( v92 )
    {
      if ( !*v92 )
        goto LABEL_99;
      --*v92;
    }
    if ( !MiObtainFaultCharges(MiSystemPartition, 1, 1) )
      goto LABEL_99;
    v44 = *v84 + 1;
    *v84 = v44;
    if ( (*(v16 - 1) & 1) != 0 )
      v45 = 2;
    else
      v45 = 0;
    v46 = MiGetPage((int)MiSystemPartition, (unsigned __int16)(v44 & v85) | v86, v45);
    v72 = v46;
    if ( v46 != -1 )
    {
      v31 = (_DWORD *)(MmPfnDatabase + 24 * v46);
      goto LABEL_23;
    }
    MiReturnFaultCharges(MiSystemPartition, 1, 1);
LABEL_99:
    v15 = v71;
    v8 = v66;
    v14 = v68;
LABEL_32:
    v22 = v70;
LABEL_33:
    if ( v8 )
    {
      MiUnlockProtoPoolPage(v8, v73);
      v8 = 0;
      v66 = 0;
    }
    if ( v22 )
    {
      v34 = (int)v77;
      v35 = MiReduceMdl((int)v77);
      if ( v35 )
      {
        v14[7] += (unsigned int)(v35 << 12);
        v42 = MmPfnDatabase + 24 * *(_DWORD *)(v34 + 28);
        v43 = *(_DWORD *)(v42 + 4);
        *((_DWORD *)v14 + 35) = v42;
        *((_DWORD *)v14 + 34) = v43 | 0x80000000;
      }
      if ( (_QWORD *)v34 != v14 + 19 && *(_DWORD *)(v34 + 20) <= 0x10000u )
      {
        memmove((int)(v14 + 19), v34, *(__int16 *)(v34 + 4));
        v64 = (int)v75;
        v75 = (_DWORD *)v34;
        *(_DWORD *)v34 = v64;
        *((_DWORD *)v14 + 36) = v14 + 19;
      }
      v14 = *(_QWORD **)v14;
      v68 = v14;
    }
    else
    {
      v39 = v91;
      v14 = *(_QWORD **)v14;
      *(_QWORD *)&v40 = *v91;
      v68 = v14;
      if ( *(_QWORD **)(v40 + 4) != v91 || (_QWORD *)*v41 != v91 )
        __fastfail(3u);
      *v41 = v40;
      *(_DWORD *)(v40 + 4) = v41;
      --v5[12];
      MiFreeInPageSupportBlock(v39);
    }
    if ( v14 != (_QWORD *)(v5 + 14) )
    {
      v10 = v76;
      continue;
    }
    break;
  }
  v12 = v69;
  v3 = v75;
LABEL_42:
  MiFreeReadListPages(v5);
  if ( v3 )
  {
    do
    {
      v65 = (_DWORD *)*v3;
      ExFreePoolWithTag(v3, 0);
      v3 = v65;
    }
    while ( v65 );
  }
  if ( v12 )
    MiFreeInPageSupportBlock(v12);
  return 0;
}
