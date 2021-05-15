// MiZeroCfgSystemWideBitmapWorker 
 
unsigned int *__fastcall MiZeroCfgSystemWideBitmapWorker(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v4; // r10
  unsigned int *v6; // r0
  unsigned int v7; // r6
  int v8; // r8
  int v9; // r9
  unsigned int *result; // r0
  unsigned int *v11; // r7
  int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r5
  unsigned int v15; // r1
  int v16; // r4
  int v17; // r2
  int v18; // lr
  int v19; // r6
  unsigned int v20; // r3
  int v21; // r3
  int v22; // r3
  int v23; // r0
  int v24; // r6
  unsigned int *v25; // r2
  unsigned int v26; // r0
  int v27; // r8
  _BYTE *v28; // r0
  int v29; // r4
  int v30; // r2
  int v31; // r2
  unsigned int *v32; // r2
  unsigned int v33; // r4
  int v34; // r4
  int v35; // r3
  unsigned int v36; // r3
  int v37; // r6
  int v38; // r0
  int v39; // r0
  unsigned int v40; // r9
  int v41; // r10
  _BYTE *v42; // r0
  int v43; // r4
  int v44; // r2
  unsigned int v45; // r0
  unsigned int *v46; // r2
  unsigned int v47; // r4
  unsigned int *v48; // r2
  unsigned int v49; // r0
  unsigned int v50; // r3
  unsigned int v51; // r2
  bool v52; // zf
  unsigned int v53; // r3
  int v54; // r6
  int v55; // r4
  unsigned int v56; // r3
  int v57; // r8
  int v58; // r0
  unsigned __int8 *v59; // r3
  unsigned int v60; // r1
  unsigned __int8 *v61; // r1
  int v62; // r3
  unsigned int v63; // r2
  unsigned int *v64; // r2
  unsigned int v65; // r0
  char v66[4]; // [sp+8h] [bp-68h] BYREF
  int v67; // [sp+Ch] [bp-64h] BYREF
  unsigned int v68; // [sp+10h] [bp-60h]
  unsigned int *v69; // [sp+14h] [bp-5Ch]
  int v70; // [sp+18h] [bp-58h]
  unsigned int v71; // [sp+1Ch] [bp-54h]
  int v72; // [sp+20h] [bp-50h]
  int v73; // [sp+24h] [bp-4Ch]
  unsigned int *v74; // [sp+28h] [bp-48h]
  int v75; // [sp+2Ch] [bp-44h]
  int v76; // [sp+30h] [bp-40h]
  int v77; // [sp+34h] [bp-3Ch]
  unsigned int v78; // [sp+38h] [bp-38h]
  int v79; // [sp+40h] [bp-30h] BYREF
  int v80; // [sp+44h] [bp-2Ch]
  int v81[10]; // [sp+48h] [bp-28h] BYREF

  v3 = a2 >> 3;
  v81[0] = ((a2 >> 3) + (a3 >> 3) - 1) >> 12;
  v4 = (a2 >> 3) & 0xFFF;
  v81[1] = 0;
  v76 = v4;
  v69 = (unsigned int *)(((unsigned __int16)(a2 >> 3) + (unsigned __int16)(a3 >> 3)) & 0xFFF);
  v6 = MiLocatePagefileSubsection(a1, (int)v81);
  v7 = v6[1];
  v79 = v3 >> 12;
  v8 = (int)v6;
  v74 = v6;
  v9 = v81[0];
  v80 = 0;
  result = MiLocatePagefileSubsection(a1, (int)&v79);
  v11 = result;
  if ( result[1] )
  {
    v12 = v79;
  }
  else
  {
    do
    {
      if ( v11 == (unsigned int *)v8 )
        return result;
      v11 = (unsigned int *)v11[2];
      v80 = 0;
      v12 = 0;
    }
    while ( !v11[1] );
  }
  v13 = v11[1];
  v14 = v13 + 4 * v12;
  if ( v11 == (unsigned int *)v8 )
    v15 = v7 + 4 * v9;
  else
    v15 = v13 + 4 * v11[7];
  v16 = 17;
  v17 = 0;
  v75 = 17;
  v66[0] = 17;
  v72 = 0;
  v18 = 0;
  v70 = 0;
  v68 = v15;
  if ( v4 )
    v71 = v14;
  else
    v71 = 0;
  result = v69;
  v19 = v7 + 4 * v9;
  if ( !v69 )
    v19 = 0;
  v77 = 0x40000000;
  v78 = 0x3FFFFF;
  v73 = v19;
  while ( v14 < v15 )
  {
LABEL_23:
    if ( ((v18 ^ v14) & 0xFFFFF000) != 0 && v18 )
    {
      MiUnlockProtoPoolPage(v17, v16);
      v17 = 0;
      v70 = 0;
      v72 = 0;
    }
    if ( !v17 )
    {
      v23 = MiLockProtoPoolPage(v14, v66);
      v16 = (unsigned __int8)v66[0];
      v17 = v23;
      v72 = v23;
      v75 = (unsigned __int8)v66[0];
      if ( !v23 )
      {
        v14 = (v14 & 0xFFFFF000) + 4096;
        goto LABEL_29;
      }
      v70 = v14;
    }
    v39 = MiLockLeafPage((unsigned int *)v14, 0);
    v40 = *(_DWORD *)v14;
    v41 = v39;
    v79 = v40;
    if ( (v40 & 2) != 0 )
    {
      v42 = (_BYTE *)MiMapPageInHyperSpaceWorker(v40 >> 12, 0, 0x80000000);
      v43 = (int)v42;
      if ( v14 == v71 )
      {
        v44 = 4096 - v76;
        v42 += v76;
        goto LABEL_73;
      }
      if ( v14 == v19 )
      {
        v44 = (int)v69;
LABEL_73:
        memset(v42, 0, v44);
      }
      else
      {
        KeZeroSinglePage(v42);
      }
      MiUnmapPageInHyperSpaceWorker(v43, 17, 0x80000000);
      v45 = MiCaptureDirtyBitToPfn(v41);
      __dmb(0xBu);
      v46 = (unsigned int *)(v41 + 12);
      do
        v47 = __ldrex(v46);
      while ( __strex(v47 & 0x7FFFFFFF, v46) );
      if ( v45 )
        MiReleasePageFileInfo((int)MiSystemPartition, v45, 1, 0);
      goto LABEL_49;
    }
    if ( (v40 & 0x400) == 0 )
    {
      if ( (v40 & 0x800) != 0 )
      {
        v27 = 0;
        if ( !*(_WORD *)(v39 + 16) )
        {
          if ( v14 == v71 || v14 == v19 )
          {
            v24 = 0;
            if ( (*(_BYTE *)(v39 + 18) & 0x10) == 0 )
            {
              v24 = 1;
              if ( !MiUnlinkPageFromList(v39, 0) )
              {
                MiDiscardTransitionPte(v41);
                __dmb(0xBu);
                v25 = (unsigned int *)(v41 + 12);
                do
                  v26 = __ldrex(v25);
                while ( __strex(v26 & 0x7FFFFFFF, v25) );
                v8 = (int)v74;
                goto LABEL_37;
              }
              v27 = MiCaptureDirtyBitToPfn(v41);
            }
            v28 = (_BYTE *)MiMapPageInHyperSpaceWorker(v40 >> 12, 0, 0x80000000);
            v29 = (int)v28;
            if ( v14 == v71 )
            {
              v30 = 4096 - v76;
              v28 += v76;
            }
            else
            {
              v30 = (int)v69;
            }
            memset(v28, 0, v30);
            MiUnmapPageInHyperSpaceWorker(v29, 17, 0x80000000);
            if ( v24 == 1 )
              MiInsertPageInList(v41, 8, v31);
          }
          else
          {
            if ( !MiUnlinkPageFromList(v39, 0) )
            {
              MiDiscardTransitionPte(v41);
              __dmb(0xBu);
              v48 = (unsigned int *)(v41 + 12);
              do
                v49 = __ldrex(v48);
              while ( __strex(v49 & 0x7FFFFFFF, v48) );
              v8 = (int)v74;
              v14 += 4;
              goto LABEL_38;
            }
            v50 = *(_DWORD *)(v41 + 8);
            v51 = v50;
            v52 = (v50 & 0x10) == 0;
            v53 = v50 & 0xFFFFFFF7;
            if ( v52 )
              v53 = 0;
            v79 = v53;
            if ( (v51 & 8) != 0 )
            {
              MI_SET_PAGING_FILE_INFO(
                &v67,
                (_DWORD *)(v41 + 8),
                *(_DWORD *)&MiSystemPartition[2 * ((v51 >> 2) & 1) + 1800],
                v51 >> 13,
                2);
              v54 = v67;
            }
            else
            {
              v54 = v51 & 0x3E0;
              v67 = v54;
              if ( (v51 & 2) == 0 && (v51 & 0xC00) == 0 && (v51 & 0x18) == 0 && (v51 & 0xFFFFE000) == 0x2000 )
              {
                v54 = v51 & 0x3E0 | 0x2000;
                v67 = v54;
              }
            }
            v55 = MmPfnDatabase + 24 * (*(_DWORD *)(v41 + 20) & 0xFFFFF);
            if ( v77 + v14 > v78 )
            {
              *(_DWORD *)v14 = v54;
            }
            else
            {
              v56 = *(_DWORD *)v14;
              v57 = 0;
              __dmb(0xBu);
              *(_DWORD *)v14 = v54;
              if ( (v56 & 2) == 0 && (v54 & 2) != 0 )
                v57 = 1;
              if ( v14 + 1070596096 <= 0xFFF )
              {
                v58 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v58, (_DWORD *)(v58 + 4 * (v14 & 0xFFF)), v54);
              }
              if ( v57 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
            }
            v59 = (unsigned __int8 *)(v55 + 15);
            do
              v60 = __ldrex(v59);
            while ( __strex(v60 | 0x80, v59) );
            __dmb(0xBu);
            if ( v60 >> 7 )
            {
              v61 = (unsigned __int8 *)(v55 + 15);
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v62 = *(_DWORD *)(v55 + 12);
                  __dmb(0xBu);
                }
                while ( (v62 & 0x80000000) != 0 );
                do
                  v63 = __ldrex(v61);
                while ( __strex(v63 | 0x80, v61) );
                __dmb(0xBu);
              }
              while ( v63 >> 7 );
            }
            if ( (*(_BYTE *)(v55 + 18) & 7) != 6 )
              KeBugCheckEx(
                78,
                153,
                (v55 - MmPfnDatabase) / 24,
                *(_BYTE *)(v55 + 18) & 7,
                *(_DWORD *)(v55 + 12) & 0x3FFFFFFF);
            if ( !MiUpdateShareCount(v55, -1) )
              MiPfnShareCountIsZero(v55, 0);
            __dmb(0xBu);
            v64 = (unsigned int *)(v55 + 12);
            do
              v65 = __ldrex(v64);
            while ( __strex(v65 & 0x7FFFFFFF, v64) );
            MiInsertPageInFreeOrZeroedList(v40 >> 12, 2);
            v27 = v79;
          }
        }
        __dmb(0xBu);
        v32 = (unsigned int *)(v41 + 12);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 & 0x7FFFFFFF, v32) );
        if ( v27 )
          MiReleasePageFileInfo((int)MiSystemPartition, v27, 1, 0);
        v8 = (int)v74;
      }
      else if ( v40 && v14 != v71 && v14 != v19 )
      {
        if ( (v40 & 8) != 0 )
        {
          MI_SET_PAGING_FILE_INFO(&v67, &v79, *(_DWORD *)&MiSystemPartition[2 * ((v40 >> 2) & 1) + 1800], v40 >> 13, 2);
          v34 = v67;
        }
        else
        {
          v34 = v40 & 0x3E0;
          v35 = 3096;
          v67 = v34;
          if ( (v40 & 0xC18) == 0 )
          {
            v35 = v40 & 0xFFFFE000;
            if ( (v40 & 0xFFFFE000) == 0x2000 )
            {
              v35 = 1;
              v34 = v40 & 0x3E0 | 0x2000;
              v67 = v34;
            }
          }
        }
        MiReleasePageFileSpace((int)MiSystemPartition, v40, 0, v35);
        if ( v14 + v77 > v78 )
        {
          *(_DWORD *)v14 = v34;
        }
        else
        {
          v36 = *(_DWORD *)v14;
          v37 = 0;
          __dmb(0xBu);
          *(_DWORD *)v14 = v34;
          if ( (v36 & 2) == 0 && (v34 & 2) != 0 )
            v37 = 1;
          if ( v14 + 1070596096 <= 0xFFF )
          {
            v38 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v38, (_DWORD *)(v38 + 4 * (v14 & 0xFFF)), v34);
          }
          if ( v37 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
      }
    }
LABEL_49:
    v16 = v75;
LABEL_37:
    v19 = v73;
    v14 += 4;
LABEL_38:
    v17 = v72;
    v9 = v81[0];
LABEL_29:
    v15 = v68;
    result = v69;
    v18 = v70;
  }
  while ( v11 != (unsigned int *)v8 )
  {
    v11 = (unsigned int *)v11[2];
    v20 = v11[1];
    if ( v20 )
    {
      v14 = v11[1];
      if ( v11 == (unsigned int *)v8 )
      {
        v21 = *(_DWORD *)(v8 + 4);
        if ( result )
        {
          v19 = v21 + 4 * v9;
          v73 = v19;
        }
        v22 = v21 + 4 * v9;
      }
      else
      {
        v22 = v20 + 4 * v11[7];
      }
      v68 = v22;
      goto LABEL_23;
    }
  }
  if ( v17 )
    result = (unsigned int *)MiUnlockProtoPoolPage(v17, v16);
  return result;
}
