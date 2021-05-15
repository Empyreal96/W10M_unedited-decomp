// MiCloneVads 
 
int __fastcall MiCloneVads(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // r5
  unsigned int *v6; // r10
  int v7; // r7
  int v8; // r4
  int v9; // r6
  int v10; // r5
  int v11; // r0
  _DWORD *v12; // r9
  unsigned int *v13; // r4
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r2
  unsigned int v17; // r0
  unsigned int v18; // r1
  _DWORD *v19; // r6
  int v20; // r4
  int v21; // r8
  unsigned int *v22; // r7
  _DWORD *v23; // r4
  int v24; // r2
  _DWORD *v25; // r3
  int v26; // r1
  _DWORD *v27; // r3
  _DWORD *v28; // r5
  unsigned int *v29; // r8
  _DWORD *v30; // r3
  _DWORD *v31; // r6
  _DWORD *v32; // r2
  unsigned int v33; // r4
  unsigned int v34; // r7
  int v35; // r9
  int v36; // r6
  int v37; // r4
  unsigned __int8 *v38; // r3
  unsigned int v39; // r1
  unsigned int v40; // r2
  unsigned int v41; // r0
  unsigned int v42; // r1
  int v43; // r3
  unsigned int v44; // r0
  unsigned int v45; // r4
  _WORD *v46; // r8
  unsigned int *v47; // r6
  _DWORD *v48; // r4
  int v49; // r1
  _DWORD *v50; // r0
  int v51; // r4
  int *v52; // r2
  _DWORD *v53; // r3
  _DWORD *v54; // r4
  unsigned int v55; // r8
  unsigned int v56; // r7
  unsigned int *v57; // r2
  unsigned int v58; // r1
  _DWORD *v59; // r6
  _DWORD *v60; // r5
  int v61; // r2
  _DWORD *v62; // r3
  _DWORD *v63; // r3
  _DWORD *v64; // r2
  unsigned int v65; // r6
  _DWORD *v66; // r4
  int v67; // r2
  _DWORD *v68; // r1
  int v71; // [sp+2Ch] [bp-134h]
  _DWORD *v72; // [sp+2Ch] [bp-134h]
  unsigned int *v74; // [sp+30h] [bp-130h]
  _DWORD *v75; // [sp+34h] [bp-12Ch]
  int v76; // [sp+38h] [bp-128h]
  int v77; // [sp+3Ch] [bp-124h]
  _DWORD *v78; // [sp+3Ch] [bp-124h]
  unsigned int v79; // [sp+40h] [bp-120h]
  int v80; // [sp+44h] [bp-11Ch] BYREF
  int v81; // [sp+48h] [bp-118h]
  unsigned int v82; // [sp+4Ch] [bp-114h]
  unsigned int *v83; // [sp+50h] [bp-110h]
  unsigned int v84; // [sp+54h] [bp-10Ch]
  unsigned int v85; // [sp+58h] [bp-108h]
  int v86; // [sp+60h] [bp-100h] BYREF
  int v87; // [sp+64h] [bp-FCh]
  _DWORD *v88; // [sp+68h] [bp-F8h]
  unsigned int *v89; // [sp+6Ch] [bp-F4h]
  int v90; // [sp+70h] [bp-F0h]
  int v91; // [sp+74h] [bp-ECh]
  char v92[12]; // [sp+78h] [bp-E8h] BYREF
  unsigned int *v93; // [sp+84h] [bp-DCh]
  _WORD *v94; // [sp+90h] [bp-D0h]
  int v95; // [sp+A8h] [bp-B8h] BYREF
  char v96; // [sp+ACh] [bp-B4h]
  char v97; // [sp+ADh] [bp-B3h]
  int v98; // [sp+B0h] [bp-B0h]
  int v99; // [sp+B4h] [bp-ACh]
  int v100; // [sp+B8h] [bp-A8h]
  int v101; // [sp+BCh] [bp-A4h]

  v90 = a4;
  v5 = (int)a2;
  v71 = 0;
  v77 = 0;
  v79 = 0;
  v86 = 0;
  v87 = 0;
  v85 = 0;
  v80 = 0;
  v6 = (unsigned int *)a1;
  v83 = (unsigned int *)a1;
  v7 = 0;
  v82 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v84 = 0x80000000;
  while ( 1 )
  {
    v8 = v6[69];
    if ( !v8 )
      v8 = 1;
    v75 = (_DWORD *)MiBuildNewCloneDescriptor(v6, v8, MEMORY[0xC0402140], MEMORY[0xC0402144]);
    if ( !v75 )
      return -1073741670;
    v9 = 16 * v8 + 12;
    v10 = PsChargeProcessNonPagedPoolQuota(v5, v9);
    if ( v10 < 0 )
      goto LABEL_119;
    v11 = ExAllocatePoolWithTag(512, 48);
    v12 = (_DWORD *)v11;
    v88 = (_DWORD *)v11;
    if ( !v11 )
    {
      PsReturnProcessNonPagedPoolQuota((int)a2, 16 * v8 + 12);
      v10 = -1073741670;
LABEL_119:
      v68 = v75;
LABEL_120:
      MiFreeCloneDescriptor(v6, v68);
      return v10;
    }
    *(_DWORD *)(v11 + 32) = v9;
    v13 = v6 + 123;
    v76 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v6 + 123);
    }
    else
    {
      v14 = (unsigned __int8 *)v6 + 495;
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x80, v14) );
      __dmb(0xBu);
      if ( v15 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v6 + 123);
      v16 = v84;
      while ( 1 )
      {
        v17 = *v13;
        if ( (*v13 & 0xBFFFFFFF) == v16 )
          break;
        if ( (v17 & 0x40000000) == 0 )
        {
          do
            v18 = __ldrex(v13);
          while ( v18 == v17 && __strex(v17 | 0x40000000, v13) );
          __dmb(0xBu);
          v16 = 0x80000000;
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( v6[69] <= v75[5] )
      break;
    MiUnlockWorkingSetExclusive((int)(v6 + 123), v76);
    MiFreeCloneDescriptor(v6, v75);
    v5 = (int)a2;
    PsReturnProcessNonPagedPoolQuota((int)a2, v9);
    ExFreePoolWithTag(v12);
  }
  v19 = v75;
  *v12 = a3;
  v6[66] = v82;
  v20 = v75[3];
  v81 = v20;
  if ( MiInitializeForkMaps(a2, v92) )
  {
    v22 = (unsigned int *)v20;
    v23 = (_DWORD *)v6[68];
    v24 = 0;
    v74 = v22;
    if ( v23 )
    {
      while ( 1 )
      {
        if ( MiCloneCompare((int)v75, (int)v23) < 0 )
        {
          v25 = (_DWORD *)*v23;
          if ( !*v23 )
          {
            v24 = 0;
            break;
          }
        }
        else
        {
          v25 = (_DWORD *)v23[1];
          if ( !v25 )
          {
            v24 = 1;
            break;
          }
        }
        v23 = v25;
      }
    }
    RtlAvlInsertNodeEx((int)(v6 + 68), (int)v23, v24, v75);
    v99 = 0;
    v95 = 1;
    v96 = 0;
    v97 = 0;
    v100 = 0;
    v98 = 33;
    v101 = 0;
    v27 = (_DWORD *)a2[159];
    v28 = 0;
    while ( v27 )
    {
      v28 = v27;
      v27 = (_DWORD *)*v27;
    }
    if ( v28 )
    {
      v29 = v6 + 123;
      v89 = v6 + 123;
      do
      {
        v30 = (_DWORD *)v28[1];
        v31 = v28;
        v82 = (unsigned int)v28;
        v32 = v28;
        if ( v30 )
        {
          do
          {
            v28 = v30;
            v30 = (_DWORD *)*v30;
            v72 = v28;
          }
          while ( v30 );
        }
        else
        {
          v28 = (_DWORD *)(v28[2] & 0xFFFFFFFC);
          v72 = v28;
          if ( v28 )
          {
            do
            {
              if ( (_DWORD *)*v28 == v32 )
                break;
              v32 = v28;
              v28 = (_DWORD *)(v28[2] & 0xFFFFFFFC);
            }
            while ( v28 );
            v72 = v28;
          }
        }
        v33 = v31[3] << 12;
        v78 = MiLocateAddress(v33);
        if ( !MiVadMapsLargeImage((int)v31) && (v31[7] & 7) != 5 )
        {
          v34 = ((v33 >> 10) & 0x3FFFFC) - 0x40000000;
          v35 = v82;
          v36 = (v31[4] & 0xFFFFF) - 0x10000000;
          v91 = v36;
          do
          {
            MiFlushTbList((unsigned int)&v95, v26);
            if ( ExSpinLockIsContended(v29) || KeShouldYieldProcessor() )
            {
              MiUnlockWorkingSetExclusive((int)v29, v76);
              v37 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v29);
              }
              else
              {
                v38 = (unsigned __int8 *)v29 + 3;
                do
                  v39 = __ldrex(v38);
                while ( __strex(v39 | 0x80, v38) );
                __dmb(0xBu);
                if ( v39 >> 7 )
                  ExpWaitForSpinLockExclusiveAndAcquire(v29);
                v40 = v84;
                while ( 1 )
                {
                  v41 = *v29;
                  if ( (*v29 & 0xBFFFFFFF) == v40 )
                    break;
                  if ( (v41 & 0x40000000) == 0 )
                  {
                    do
                      v42 = __ldrex(v29);
                    while ( v42 == v41 && __strex(v41 | 0x40000000, v29) );
                    __dmb(0xBu);
                    v40 = 0x80000000;
                  }
                  __dmb(0xAu);
                  __yield();
                }
                v6 = v83;
              }
              v43 = v37;
              v76 = v37;
            }
            else
            {
              v43 = v76;
            }
            v44 = MiUpdateForkMaps(v92, v34, 4 * v36, &v80, v6, v43);
            v34 = v44;
            if ( (*(_DWORD *)(v35 + 28) & 7) != 7 )
            {
              if ( v44 > 4 * v36 )
                break;
              v45 = (v44 & 0xFFFFF000) + 4092;
              v46 = v94;
              if ( v45 > 4 * v36 )
                v45 = 4 * v36;
              v47 = v93;
              do
              {
                if ( MiBuildForkPte(
                       v6,
                       v26,
                       v34,
                       v47,
                       v90,
                       v74,
                       &v80,
                       v46,
                       (unsigned int)&v95,
                       (int)v78,
                       v35,
                       a5,
                       v76,
                       &v86) )
                {
                  v74 += 4;
                }
                v34 += 4;
                ++v47;
              }
              while ( v34 <= v45 );
              v36 = v91;
              v29 = v89;
            }
          }
          while ( v34 <= 4 * v36 );
          v28 = v72;
          if ( (*(_DWORD *)(v35 + 28) & 7) == 4 )
          {
            v48 = MiLocateVadEvent((int)v78, 4);
            v50 = MiLocateVadEvent(v35, v49);
            memmove(v50[3], v48[3], (unsigned int)(v50[2] + 7) >> 3);
          }
        }
      }
      while ( v28 );
      v21 = v86;
      v51 = v80;
      v12 = v88;
      v22 = v74;
      v19 = v75;
      v71 = v87;
      v77 = v86;
    }
    else
    {
      v51 = 0;
      v21 = 0;
    }
    MiFlushTbList((unsigned int)&v95, v26);
    MiFreeForkMaps(v92);
    v52 = (int *)v19[7];
    a2[69] += v51;
    v7 = ((int)v22 - v81) >> 4;
    v81 = v7;
    if ( v7 )
    {
      *v52 = v7;
      v19[5] = v7;
      v19[6] = v7;
    }
    else
    {
      RtlAvlRemoveNode((int)(v6 + 68), (int)v19);
    }
    v53 = (_DWORD *)v6[68];
    v54 = 0;
    while ( v53 )
    {
      v54 = v53;
      v53 = (_DWORD *)*v53;
    }
    if ( v54 )
    {
      v55 = 0;
      v56 = 0;
      do
      {
        v57 = (unsigned int *)(v54[7] + 4);
        do
          v58 = __ldrex(v57);
        while ( __strex(v58 + 1, v57) );
        v59 = (_DWORD *)*v12;
        v55 += v12[8];
        v56 += v54[8];
        memmove((int)v92, (int)v54, 0x30u);
        __dmb(0xBu);
        memmove((int)v12, (int)v92, 0x30u);
        v60 = (_DWORD *)a2[68];
        v61 = 0;
        if ( v60 )
        {
          while ( 1 )
          {
            if ( MiCloneCompare((int)v12, (int)v60) < 0 )
            {
              v62 = (_DWORD *)*v60;
              if ( !*v60 )
              {
                v61 = 0;
                break;
              }
            }
            else
            {
              v62 = (_DWORD *)v60[1];
              if ( !v62 )
              {
                v61 = 1;
                break;
              }
            }
            v60 = v62;
          }
        }
        RtlAvlInsertNodeEx((int)(a2 + 68), (int)v60, v61, v12);
        v63 = (_DWORD *)v54[1];
        v12 = v59;
        v64 = v54;
        if ( v63 )
        {
          do
          {
            v54 = v63;
            v63 = (_DWORD *)*v63;
          }
          while ( v63 );
        }
        else
        {
          while ( 1 )
          {
            v54 = (_DWORD *)(v54[2] & 0xFFFFFFFC);
            if ( !v54 || (_DWORD *)*v54 == v64 )
              break;
            v64 = v54;
          }
        }
      }
      while ( v54 );
      v6 = v83;
      v19 = v75;
      v85 = v56;
      v7 = v81;
      v79 = v55;
      v21 = v77;
    }
    v10 = 0;
  }
  else
  {
    MiFreeForkMaps(v92);
    v10 = -1073741670;
    v21 = 0;
  }
  v6[66] = 0;
  MiUnlockWorkingSetExclusive((int)(v6 + 123), v76);
  if ( v12 )
  {
    v65 = v79;
    do
    {
      v66 = (_DWORD *)*v12;
      v65 += v12[8];
      ExFreePoolWithTag(v12);
      v12 = v66;
    }
    while ( v66 );
    v79 = v65;
    v19 = v75;
  }
  v67 = v85;
  if ( v79 > v85 )
    PsReturnProcessNonPagedPoolQuota((int)a2, v79 - v85);
  if ( v21 )
    MiReturnFullProcessCommitment(a2, v21);
  if ( v71 )
    MiReturnFullProcessCharges((int)a2, v71, v67, v71);
  if ( !v7 || v10 < 0 )
  {
    v68 = v19;
    goto LABEL_120;
  }
  return v10;
}
