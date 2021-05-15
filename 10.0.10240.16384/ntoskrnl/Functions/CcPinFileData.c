// CcPinFileData 
 
int __fastcall CcPinFileData(int a1, _DWORD *a2, int a3, int a4, char a5, char a6, int **a7, int *a8, _DWORD *a9)
{
  int v10; // r5
  __int64 v11; // kr00_8
  int *v12; // r10
  char v13; // r8
  unsigned int v14; // r5
  int v15; // r6
  int v16; // r1
  unsigned int v17; // r2
  int v18; // r6
  int *v19; // r6
  unsigned int v20; // r1
  int v21; // lr
  int v22; // r1
  int v23; // r2
  unsigned int v24; // r0
  int v25; // r1
  int *v26; // r0
  int v27; // r2
  int v28; // r6
  unsigned int v29; // r1
  int v30; // r0
  unsigned int v31; // r1
  int v32; // r1
  unsigned int v33; // r2
  unsigned int v34; // r1
  int *v35; // r0
  unsigned int v36; // r1
  int v37; // r1
  unsigned int v38; // r2
  unsigned int v39; // r1
  int v40; // r0
  unsigned int v41; // r1
  int v42; // r2
  int v43; // r0
  int v44; // r1
  unsigned int v45; // r2
  unsigned int v46; // r1
  unsigned int v47; // r1
  int v48; // r1
  unsigned int v49; // r2
  unsigned int v50; // r1
  unsigned int v51; // r1
  int v52; // r2
  int v53; // r0
  unsigned int v54; // r1
  int v55; // r3
  int v56; // r0
  unsigned int *v57; // r2
  unsigned int v58; // r1
  int v59; // r0
  int v60; // r5
  unsigned int *v61; // r6
  int v62; // r8
  unsigned int v63; // r1
  int v64; // r3
  int v65; // r0
  unsigned int *v66; // r2
  unsigned int v67; // r1
  int v68; // r0
  int *v69; // r1
  unsigned __int8 v71; // [sp+10h] [bp-68h]
  int *v72; // [sp+14h] [bp-64h] BYREF
  int v73; // [sp+18h] [bp-60h]
  int v74; // [sp+1Ch] [bp-5Ch]
  int v75; // [sp+20h] [bp-58h] BYREF
  int v76; // [sp+24h] [bp-54h]
  int v77; // [sp+28h] [bp-50h]
  int v78; // [sp+2Ch] [bp-4Ch]
  int v79; // [sp+30h] [bp-48h] BYREF
  int v80; // [sp+34h] [bp-44h]
  unsigned int v81; // [sp+38h] [bp-40h]
  int v82; // [sp+3Ch] [bp-3Ch]
  __int64 v83; // [sp+40h] [bp-38h] BYREF
  __int64 v84; // [sp+48h] [bp-30h] BYREF
  __int64 v85[5]; // [sp+50h] [bp-28h] BYREF
  int varg_r0; // [sp+80h] [bp+8h]
  _DWORD *varg_r1; // [sp+84h] [bp+Ch]
  int varg_r2; // [sp+88h] [bp+10h]
  int varg_r3; // [sp+8Ch] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v74 = a4;
  LOBYTE(varg_r3) = a4;
  v81 = a3;
  varg_r1 = a2;
  v72 = 0;
  v76 = 0;
  v77 = 0;
  v75 = 0;
  v10 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  LODWORD(v84) = v10;
  v78 = v10;
  v11 = (unsigned int)a3 + *(_QWORD *)a2;
  if ( v11 > *(_QWORD *)(v10 + 24) )
    KeBugCheckEx(52, 263, -1073740768);
  *a7 = 0;
  v12 = a8;
  *a8 = 0;
  v13 = a6;
  v80 = a6 & 4;
  if ( (a6 & 4) != 0 )
  {
    v79 = 0x40000 - (*a2 & 0x3FFFF);
    CcReferenceFileOffset(v10, v11, *a2, a2[1]);
  }
  else
  {
    *a8 = CcGetVirtualAddress(v10, v11, *a2, a2[1], &v75, &v79, (a6 & 0x40) != 0, 0);
    v77 = v75;
  }
  v14 = v10 + 180;
  v15 = KeAbPreAcquire(v14, 0, 0);
  v16 = KfRaiseIrql(1);
  LODWORD(v83) = v16;
  do
    v17 = __ldrex((unsigned __int8 *)v14);
  while ( __strex(v17 & 0xFE, (unsigned __int8 *)v14) );
  __dmb(0xBu);
  if ( (v17 & 1) == 0 )
  {
    ExpAcquireFastMutexContended(v14, v15);
    v16 = v83;
  }
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  *(_DWORD *)(v14 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v14 + 28) = v16;
  v73 = 1;
  v85[0] = *(_QWORD *)a2 + v81;
  v18 = v84;
  if ( CcFindBcb(v84, a2, v85, &v72) )
  {
    if ( (*(_DWORD *)(v18 + 96) & 0x200) != 0 )
    {
      v40 = v74;
    }
    else
    {
      v40 = 1;
      v74 = 1;
      LOBYTE(varg_r3) = 1;
    }
    v19 = v72;
    if ( v72[29] )
    {
      if ( (a6 & 1) != 0 )
      {
        ++v72[13];
        *(_DWORD *)(v14 + 4) = 0;
        LODWORD(v84) = *(_DWORD *)(v14 + 28);
        __dmb(0xBu);
        do
          v51 = __ldrex((unsigned int *)v14);
        while ( !v51 && __strex(1u, (unsigned int *)v14) );
        if ( v51 )
          ExpReleaseFastMutexContended((unsigned int *)v14, v51);
        KfLowerIrql((unsigned __int8)v84);
        KeAbPostRelease(v14);
        v73 = 0;
        if ( !v74 )
        {
          v53 = (int)(v19 + 14);
          if ( (a6 & 2) != 0 )
            ExAcquireResourceExclusiveLite(v53, 1, v52, 0);
          else
            ExAcquireSharedStarveExclusive(v53, 1);
        }
      }
      else
      {
        if ( !v40 && !ExAcquireSharedStarveExclusive(v72 + 14, 0) )
        {
          v19 = 0;
          v72 = 0;
          v71 = 0;
          v20 = 2;
          goto LABEL_162;
        }
        ++v19[13];
        *(_DWORD *)(v14 + 4) = 0;
        LODWORD(v84) = *(_DWORD *)(v14 + 28);
        __dmb(0xBu);
        do
          v54 = __ldrex((unsigned int *)v14);
        while ( !v54 && __strex(1u, (unsigned int *)v14) );
        if ( v54 )
          ExpReleaseFastMutexContended((unsigned int *)v14, v54);
        KfLowerIrql((unsigned __int8)v84);
        KeAbPostRelease(v14);
        v73 = 0;
      }
      v20 = 2;
      *a8 = v19[29] + *a2 - v19[2];
LABEL_161:
      v71 = 1;
      goto LABEL_162;
    }
    *a8 += v72[2] - *a2;
    v83 = *((_QWORD *)v19 + 1);
    LODWORD(v83) = v19[1];
    v84 = (unsigned int)v83;
    if ( (a6 & 1) != 0 )
    {
      ++v19[13];
      *(_DWORD *)(v14 + 4) = 0;
      LODWORD(v84) = *(_DWORD *)(v14 + 28);
      __dmb(0xBu);
      do
        v41 = __ldrex((unsigned int *)v14);
      while ( !v41 && __strex(1u, (unsigned int *)v14) );
      if ( v41 )
        ExpReleaseFastMutexContended((unsigned int *)v14, v41);
      KfLowerIrql((unsigned __int8)v84);
      KeAbPostRelease(v14);
      v73 = 0;
      if ( !v74 )
      {
        v43 = (int)(v19 + 14);
        if ( (a6 & 2) != 0 )
          ExAcquireResourceExclusiveLite(v43, 1, v42, 0);
        else
          ExAcquireSharedStarveExclusive(v43, 1);
      }
      if ( v80 )
        goto LABEL_61;
      CcMapAndRead(v83, 0, 1, *a8);
      v81 = KeAbPreAcquire(v14, 0, 0);
      v44 = KfRaiseIrql(1);
      LODWORD(v84) = v44;
      do
        v45 = __ldrex((unsigned __int8 *)v14);
      while ( __strex(v45 & 0xFE, (unsigned __int8 *)v14) );
      __dmb(0xBu);
      if ( (v45 & 1) == 0 )
      {
        ExpAcquireFastMutexContended(v14, v81);
        v44 = v84;
      }
      if ( v81 )
        *(_BYTE *)(v81 + 14) |= 1u;
      *(_DWORD *)(v14 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v14 + 28) = v44;
      if ( !v19[29] )
      {
        v19[29] = *a8;
        v19[12] = v77;
        v75 = 0;
      }
      *(_DWORD *)(v14 + 4) = 0;
      LODWORD(v84) = *(_DWORD *)(v14 + 28);
      __dmb(0xBu);
      do
        v46 = __ldrex((unsigned int *)v14);
      while ( !v46 && __strex(1u, (unsigned int *)v14) );
      if ( v46 )
        ExpReleaseFastMutexContended((unsigned int *)v14, v46);
    }
    else
    {
      if ( !v40 && !ExAcquireSharedStarveExclusive(v19 + 14, 0) )
      {
        v19 = 0;
        v72 = 0;
        v71 = 0;
        v20 = 2;
        goto LABEL_162;
      }
      ++v19[13];
      *(_DWORD *)(v14 + 4) = 0;
      LODWORD(v84) = *(_DWORD *)(v14 + 28);
      __dmb(0xBu);
      do
        v47 = __ldrex((unsigned int *)v14);
      while ( !v47 && __strex(1u, (unsigned int *)v14) );
      if ( v47 )
        ExpReleaseFastMutexContended((unsigned int *)v14, v47);
      KfLowerIrql((unsigned __int8)v84);
      KeAbPostRelease(v14);
      v73 = 0;
      if ( !CcMapAndRead(v19[1], 0, 0, *a8) )
      {
        v71 = 0;
        v20 = 2;
        goto LABEL_162;
      }
      v81 = KeAbPreAcquire(v14, 0, 0);
      v48 = KfRaiseIrql(1);
      LODWORD(v84) = v48;
      do
        v49 = __ldrex((unsigned __int8 *)v14);
      while ( __strex(v49 & 0xFE, (unsigned __int8 *)v14) );
      __dmb(0xBu);
      if ( (v49 & 1) == 0 )
      {
        ExpAcquireFastMutexContended(v14, v81);
        v48 = v84;
      }
      if ( v81 )
        *(_BYTE *)(v81 + 14) |= 1u;
      *(_DWORD *)(v14 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v14 + 28) = v48;
      if ( !v19[29] )
      {
        v19[29] = *a8;
        v19[12] = v77;
        v75 = 0;
      }
      *(_DWORD *)(v14 + 4) = 0;
      LODWORD(v84) = *(_DWORD *)(v14 + 28);
      __dmb(0xBu);
      do
        v50 = __ldrex((unsigned int *)v14);
      while ( !v50 && __strex(1u, (unsigned int *)v14) );
      if ( v50 )
        ExpReleaseFastMutexContended((unsigned int *)v14, v50);
    }
    goto LABEL_140;
  }
  if ( (a6 & 8) == 0 )
  {
    v83 = *(_QWORD *)a2;
    v21 = v83;
    v84 = v85[0] - v83;
    v22 = v83 & 0xFFF;
    v23 = v22 + LODWORD(v85[0]) - v83;
    LODWORD(v84) = v23;
    v24 = v22 + v79;
    v79 += v22;
    if ( !v74 && (v12 = a8, (*(_DWORD *)(v18 + 96) & 4) == 0) || a5 )
    {
      v76 = 2;
      v82 = 2;
      v13 = a6;
      if ( (v83 & 0xFFF) != 0 || v81 < 0x1000 )
      {
        v25 = v76;
      }
      else
      {
        v25 = 3;
        v76 = 3;
        v82 = 3;
      }
      if ( (v23 & 0xFFF) == 0 )
      {
        v76 = v25 | 4;
        v82 = v25 | 4;
      }
    }
    if ( (*(_DWORD *)(v18 + 96) & 0x200) == 0 )
    {
      v74 = 1;
      LOBYTE(varg_r3) = 1;
    }
    v79 = (v23 + 4095) & 0xFFFFF000;
    LODWORD(v84) = v79;
    *v12 -= *a2 & 0xFFF;
    LODWORD(v83) = v21 & 0xFFFFF000;
    if ( ((v23 + 4095) & 0xFFFFF000) > v24 )
    {
      v79 = v24;
      LODWORD(v84) = v24;
    }
    if ( (v13 & 1) != 0 )
    {
      v26 = (int *)CcAllocateInitializeBcb(v18, v72, &v83, &v84);
      v19 = v26;
      v72 = v26;
      if ( !v26 )
      {
        *(_DWORD *)(v14 + 4) = 0;
        v28 = *(_DWORD *)(v14 + 28);
        __dmb(0xBu);
        do
          v29 = __ldrex((unsigned int *)v14);
        while ( !v29 && __strex(1u, (unsigned int *)v14) );
        if ( v29 )
          ExpReleaseFastMutexContended((unsigned int *)v14, v29);
        KfLowerIrql((unsigned __int8)v28);
        KeAbPostRelease(v14);
        v73 = 0;
        RtlRaiseStatus(-1073741670);
      }
      if ( !v74 )
      {
        v30 = (int)(v26 + 14);
        if ( (v13 & 2) != 0 )
        {
          if ( !ExAcquireResourceExclusiveLite(v30, 0, v27, 0) )
            KeBugCheckEx(52, 131542, v19);
        }
        else if ( !ExAcquireSharedStarveExclusive(v30, 0) )
        {
          KeBugCheckEx(52, 131549, v19);
        }
      }
      *(_DWORD *)(v14 + 4) = 0;
      LODWORD(v84) = *(_DWORD *)(v14 + 28);
      __dmb(0xBu);
      do
        v31 = __ldrex((unsigned int *)v14);
      while ( !v31 && __strex(1u, (unsigned int *)v14) );
      if ( v31 )
        ExpReleaseFastMutexContended((unsigned int *)v14, v31);
      KfLowerIrql((unsigned __int8)v84);
      KeAbPostRelease(v14);
      v73 = 0;
      if ( !v80 )
      {
        CcMapAndRead(v79, v76, 1, *v12);
        v81 = KeAbPreAcquire(v14, 0, 0);
        v32 = KfRaiseIrql(1);
        LODWORD(v84) = v32;
        do
          v33 = __ldrex((unsigned __int8 *)v14);
        while ( __strex(v33 & 0xFE, (unsigned __int8 *)v14) );
        __dmb(0xBu);
        if ( (v33 & 1) == 0 )
        {
          ExpAcquireFastMutexContended(v14, v81);
          v32 = v84;
        }
        if ( v81 )
          *(_BYTE *)(v81 + 14) |= 1u;
        *(_DWORD *)(v14 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v14 + 28) = v32;
        if ( !v19[29] )
        {
          v19[29] = *v12;
          v19[12] = v77;
          v75 = 0;
        }
        *(_DWORD *)(v14 + 4) = 0;
        LODWORD(v84) = *(_DWORD *)(v14 + 28);
        __dmb(0xBu);
        do
          v34 = __ldrex((unsigned int *)v14);
        while ( !v34 && __strex(1u, (unsigned int *)v14) );
        if ( v34 )
          ExpReleaseFastMutexContended((unsigned int *)v14, v34);
        KfLowerIrql((unsigned __int8)v84);
        KeAbPostRelease(v14);
        *v12 = v19[29] + *a2 - v19[2];
      }
LABEL_61:
      v20 = 2;
      goto LABEL_161;
    }
    v35 = (int *)CcAllocateInitializeBcb(v18, v72, &v83, &v84);
    v19 = v35;
    v72 = v35;
    if ( !v35 )
    {
      v71 = 0;
      v20 = 2;
      goto LABEL_162;
    }
    if ( !v74 && !ExAcquireSharedStarveExclusive(v35 + 14, 0) )
      KeBugCheckEx(52, 131647, v19);
    *(_DWORD *)(v14 + 4) = 0;
    LODWORD(v84) = *(_DWORD *)(v14 + 28);
    __dmb(0xBu);
    do
      v36 = __ldrex((unsigned int *)v14);
    while ( !v36 && __strex(1u, (unsigned int *)v14) );
    if ( v36 )
      ExpReleaseFastMutexContended((unsigned int *)v14, v36);
    KfLowerIrql((unsigned __int8)v84);
    KeAbPostRelease(v14);
    v73 = 0;
    if ( !CcMapAndRead(v79, v76, 0, *v12) )
    {
      v71 = 0;
      v20 = 2;
      goto LABEL_162;
    }
    v81 = KeAbPreAcquire(v14, 0, 0);
    v37 = KfRaiseIrql(1);
    LODWORD(v84) = v37;
    do
      v38 = __ldrex((unsigned __int8 *)v14);
    while ( __strex(v38 & 0xFE, (unsigned __int8 *)v14) );
    __dmb(0xBu);
    if ( (v38 & 1) == 0 )
    {
      ExpAcquireFastMutexContended(v14, v81);
      v37 = v84;
    }
    if ( v81 )
      *(_BYTE *)(v81 + 14) |= 1u;
    *(_DWORD *)(v14 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v14 + 28) = v37;
    if ( !v19[29] )
    {
      v19[29] = *v12;
      v19[12] = v77;
      v75 = 0;
    }
    *(_DWORD *)(v14 + 4) = 0;
    LODWORD(v84) = *(_DWORD *)(v14 + 28);
    __dmb(0xBu);
    do
      v39 = __ldrex((unsigned int *)v14);
    while ( !v39 && __strex(1u, (unsigned int *)v14) );
    if ( v39 )
      ExpReleaseFastMutexContended((unsigned int *)v14, v39);
LABEL_140:
    KfLowerIrql((unsigned __int8)v84);
    KeAbPostRelease(v14);
    *v12 = *a2 - v19[2] + v19[29];
    v20 = 2;
    goto LABEL_161;
  }
  v19 = 0;
  v72 = 0;
  v71 = 0;
  v20 = 2;
LABEL_162:
  if ( v80 && (v13 & 2) != 0 && v19 && v19[29] )
  {
    v55 = v19[12];
    v56 = *(_DWORD *)(v55 + 4);
    __dmb(0xBu);
    v57 = (unsigned int *)(v55 + 8);
    do
    {
      v58 = __ldrex(v57);
      v20 = v58 - 1;
    }
    while ( __strex(v20, v57) );
    __dmb(0xBu);
    if ( !(_WORD)v20 )
    {
      v59 = *(_DWORD *)(v56 + 116);
      if ( v59 )
        KeSetEvent(v59, 0, 0);
    }
    v19[29] = 0;
    v19[12] = 0;
  }
  v60 = v78;
  if ( v73 )
  {
    v61 = (unsigned int *)(v78 + 180);
    *(_DWORD *)(v78 + 184) = 0;
    v62 = *(_DWORD *)(v60 + 208);
    __dmb(0xBu);
    do
      v63 = __ldrex(v61);
    while ( !v63 && __strex(1u, v61) );
    if ( v63 )
      ExpReleaseFastMutexContended((unsigned int *)(v60 + 180), v63);
    KfLowerIrql((unsigned __int8)v62);
    KeAbPostRelease(v60 + 180);
  }
  v64 = v75;
  if ( v75 )
  {
    v65 = *(_DWORD *)(v75 + 4);
    __dmb(0xBu);
    v66 = (unsigned int *)(v64 + 8);
    do
    {
      v67 = __ldrex(v66);
      v20 = v67 - 1;
    }
    while ( __strex(v20, v66) );
    __dmb(0xBu);
    if ( !(_WORD)v20 )
    {
      v68 = *(_DWORD *)(v65 + 116);
      if ( v68 )
        KeSetEvent(v68, 0, 0);
    }
  }
  if ( (a6 & 4) != 0 )
    CcDereferenceFileOffset(v60, v20, *varg_r1, varg_r1[1]);
  if ( v71 )
  {
    v69 = v72;
    *a7 = v72;
    *a9 = v69[6];
    a9[1] = v69[7];
  }
  else
  {
    *a8 = 0;
    if ( v72 )
      CcUnpinFileDataEx((int)v72, (unsigned __int8)varg_r3, 0);
  }
  LOBYTE(v84) = v71;
  return v71;
}
