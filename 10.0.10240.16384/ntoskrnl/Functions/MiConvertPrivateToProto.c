// MiConvertPrivateToProto 
 
int __fastcall MiConvertPrivateToProto(int a1, unsigned int a2, unsigned int a3, __int16 **a4, int a5, int a6)
{
  unsigned int v6; // r9
  unsigned int v9; // r5
  int v10; // r6
  int v11; // r7
  int v12; // r0
  int v13; // r5
  int v14; // r4
  int v15; // r9
  int v16; // r1
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned int v19; // r7
  int v20; // r9
  unsigned int v21; // r5
  unsigned __int8 *v22; // r1
  unsigned int v23; // r2
  unsigned int v24; // r1
  int v25; // r4
  int v26; // r5
  int v27; // r5
  unsigned int *v28; // r2
  unsigned int v29; // r0
  int v30; // r4
  unsigned __int8 *v31; // r1
  unsigned int v32; // r2
  int v33; // r2
  unsigned int *v34; // r2
  unsigned int v35; // r0
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // r7
  unsigned int v39; // r9
  unsigned __int8 *v40; // r1
  unsigned int v41; // r2
  unsigned __int8 *v42; // r1
  unsigned int v43; // r2
  char v44; // r2
  int v45; // r3
  unsigned int *v46; // r2
  unsigned int v47; // r0
  unsigned int v48; // r4
  unsigned int v49; // r3
  int v50; // r7
  unsigned int *v51; // r2
  unsigned int v52; // r5
  int v53; // r3
  unsigned __int8 *v54; // r1
  unsigned int v55; // r2
  unsigned int *v56; // r2
  unsigned int v57; // r0
  __int16 *v58; // r5
  unsigned int v59; // r0
  unsigned int v60; // r0
  int v61; // r3
  int v62; // r3
  unsigned int v63; // r1
  __int16 v64; // r3
  int v65; // r3
  int v66; // r0
  int v67; // r5
  int v68; // r0
  int v69; // r3
  unsigned int v70; // r2
  unsigned int *v71; // r2
  unsigned int v72; // r4
  unsigned int *v73; // r2
  unsigned int v74; // r0
  int v75; // r3
  unsigned int v76; // r2
  unsigned int v77; // r2
  int v78; // r0
  int v79; // r3
  unsigned int *v80; // r2
  unsigned int v81; // r0
  unsigned int v84; // [sp+14h] [bp-74h]
  int v85; // [sp+1Ch] [bp-6Ch]
  int v86; // [sp+24h] [bp-64h]
  _DWORD *v87; // [sp+28h] [bp-60h]
  int v88; // [sp+2Ch] [bp-5Ch]
  int v89; // [sp+30h] [bp-58h]
  int v91; // [sp+38h] [bp-50h]

  v6 = a3;
  v89 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( (dword_682604 & 0x8000001) != 0 )
    return sub_54F140();
  v9 = *(_DWORD *)a2;
  v10 = MmPfnDatabase + 24 * (*(_DWORD *)a2 >> 12);
  v85 = *(_DWORD *)(a1 + 92);
  v84 = a2 << 10;
  if ( a6 == -1 )
  {
    v11 = MiLockProtoPoolPage(a3, 0);
    if ( v11 )
    {
      v12 = MiLockLeafPage((unsigned int *)v6, 0);
      v13 = v12;
      if ( !v12 )
      {
LABEL_166:
        MiUnlockProtoPoolPage(v11, 17);
        return 0;
      }
      if ( (*(_BYTE *)(v12 + 19) & 0x40) != 0 || (*(_BYTE *)(v12 + 18) & 7) != 6 && (*(_BYTE *)(v12 + 18) & 0x20) != 0 )
      {
        __dmb(0xBu);
        v80 = (unsigned int *)(v12 + 12);
        do
          v81 = __ldrex(v80);
        while ( __strex(v81 & 0x7FFFFFFF, v80) );
        goto LABEL_166;
      }
      v14 = MiMapPageInHyperSpaceWorker((v12 - MmPfnDatabase) / 24, 0, 0x80000000);
      v15 = MiComparePages(v14, v84);
      MiUnmapPageInHyperSpaceWorker(v14, 17, 0x80000000);
      if ( v15 == 1 )
      {
        if ( (*(_BYTE *)(v10 + 19) & 8) != 0 )
          v16 = 5;
        else
          v16 = *(_BYTE *)(v10 + 19) & 7;
        MiUpdatePfnPriority(v13, v16, 0);
      }
      __dmb(0xBu);
      v17 = (unsigned int *)(v13 + 12);
      do
        v18 = __ldrex(v17);
      while ( __strex(v18 & 0x7FFFFFFF, v17) );
      MiUnlockProtoPoolPage(v11, 17);
      if ( !v15 )
        return 0;
      v19 = *(_DWORD *)v10;
      if ( dword_634484 && (*(_DWORD *)a2 & 0x10) != 0 )
      {
        v20 = a1;
        if ( (*(_DWORD *)(*(_DWORD *)(v85 + 36) * v19 + *(_DWORD *)(v85 + 252)) & 0xE00) != 3584 )
          MiLogPageAccess(a1, a2);
      }
      else
      {
        v20 = a1;
      }
      v21 = a3 & 0x1FC | (4 * (a3 & 0xFFFFFE00 | 0x100));
      v22 = (unsigned __int8 *)(v10 + 15);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 | 0x80, v22) );
      __dmb(0xBu);
      if ( v23 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v75 = *(_DWORD *)(v10 + 12);
            __dmb(0xBu);
          }
          while ( (v75 & 0x80000000) != 0 );
          do
            v76 = __ldrex(v22);
          while ( __strex(v76 | 0x80, v22) );
          __dmb(0xBu);
        }
        while ( v76 >> 7 );
      }
      if ( (*(_DWORD *)(v10 + 12) & 0x3FFFFFFF) == 1 && *(_WORD *)(v10 + 16) == 1 )
      {
        v24 = *(_DWORD *)a2;
        __dmb(0xBu);
        if ( (v24 & 0x10) != 0 )
          goto LABEL_23;
        __dmb(0xBu);
        do
          v77 = __ldrex((unsigned int *)a2);
        while ( v77 == v24 && __strex(v21, (unsigned int *)a2) );
        __dmb(0xBu);
        if ( v77 != v24 )
        {
LABEL_23:
          if ( a2 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)a2 = v21;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)a2 = v21;
            if ( a2 >= 0xC0300000 && a2 <= 0xC0300FFF )
            {
              v78 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v78, (_DWORD *)(v78 + 4 * (a2 & 0xFFF)), v21);
            }
          }
          v25 = 1;
        }
        else
        {
          v25 = 0;
        }
        v26 = *(_DWORD *)(v10 + 20);
        *(_DWORD *)(v10 + 12) |= 0x40000000u;
        v27 = v26 & 0xFFFFF;
        __dmb(0xBu);
        v28 = (unsigned int *)(v10 + 12);
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 & 0x7FFFFFFF, v28) );
        if ( v25 == 1 )
          MiInsertTbFlushEntry(a5, v84, 1, 0);
        --*(_DWORD *)(v20 + 64);
        if ( v84 < 0xC0000000 || v84 > 0xC03FFFFF )
          --*(_DWORD *)(v20 + 56);
        MiRemoveWsle(v19, v20);
        MiReleaseWsle(v19, (_DWORD *)v20, v84, 1);
        v30 = MmPfnDatabase + 24 * v27;
        v31 = (unsigned __int8 *)(v30 + 15);
        do
          v32 = __ldrex(v31);
        while ( __strex(v32 | 0x80, v31) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v32 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
            v79 = *(_DWORD *)(v30 + 12);
            __dmb(0xBu);
          }
          while ( (v79 & 0x80000000) != 0 );
          do
            v32 = __ldrex(v31);
          while ( __strex(v32 | 0x80, v31) );
        }
        v33 = *(_DWORD *)(v30 + 12);
        if ( (*(_BYTE *)(v30 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v30 - MmPfnDatabase) / 24);
        *(_DWORD *)(v30 + 12) = v33 & 0xC0000000 | ((v33 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
        if ( (v33 & 0x3FFFFFFF) == 1 )
          MiPfnShareCountIsZero(v30, 0);
        __dmb(0xBu);
        v34 = (unsigned int *)(v30 + 12);
        do
          v35 = __ldrex(v34);
        while ( __strex(v35 & 0x7FFFFFFF, v34) );
        MiResolveProtoCombine(a2, v20, a3);
LABEL_41:
        if ( (*(_BYTE *)(v20 + 112) & 7) == 0 )
        {
          v36 = (unsigned int *)(v89 + 276);
          do
            v37 = __ldrex(v36);
          while ( __strex(v37 - 1, v36) );
        }
        return v10;
      }
      goto LABEL_143;
    }
  }
  else
  {
    v38 = MmPfnDatabase + 24 * a6;
    v87 = (_DWORD *)v38;
    if ( MiFillCombinePage(a1, v38, v10, a2 << 10) )
    {
      v86 = v6 & 0x7FFFFFFF;
      v39 = 0;
      v88 = *(_DWORD *)(((a3 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
      v40 = (unsigned __int8 *)(v10 + 15);
      v91 = MmPfnDatabase + 24 * v88;
      do
        v41 = __ldrex(v40);
      while ( __strex(v41 | 0x80, v40) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v41 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v62 = *(_DWORD *)(v10 + 12);
          __dmb(0xBu);
        }
        while ( (v62 & 0x80000000) != 0 );
        do
          v41 = __ldrex(v40);
        while ( __strex(v41 | 0x80, v40) );
      }
      if ( (*(_DWORD *)(v10 + 12) & 0x3FFFFFFF) == 1 && *(_WORD *)(v10 + 16) == 1 )
      {
        if ( (v9 & 0x200) == 0 )
          LOWORD(v9) = v9 | 0x200;
        if ( (*(_BYTE *)(v10 + 18) & 0x10) == 0 )
        {
          v61 = *(_DWORD *)(v10 + 8);
          if ( (v61 & 2) == 0 && (v61 & 0x400) == 0 && (v61 & 0x800) == 0 && (v61 & 0x10) == 0 )
            *(_BYTE *)(v10 + 18) |= 0x10u;
        }
        if ( (*(_DWORD *)(v10 + 8) & 8) != 0 )
        {
          v63 = *(_DWORD *)(v10 + 8);
          v64 = *(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * ((v63 >> 2) & 1) + 1800] + 96);
          if ( (v64 & 0x10) != 0 || (v64 & 0x20) != 0 && (v63 & 8) != 0 )
          {
            v39 = *(_DWORD *)(v10 + 8);
            if ( (v39 & 0x10) != 0 )
            {
              *(_DWORD *)(v10 + 8) = v39 & 0xFFFFFFEF;
            }
            else if ( (v39 & 8) == 0 )
            {
              v39 = 0;
            }
            *(_BYTE *)(v10 + 18) |= 0x10u;
          }
          else
          {
            v39 = *(_DWORD *)(v10 + 8);
          }
          *(_DWORD *)(v10 + 8) &= 0xFFFFFFF7;
        }
        v42 = (unsigned __int8 *)(v38 + 15);
        do
          v43 = __ldrex(v42);
        while ( __strex(v43 | 0x80, v42) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v43 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
            v65 = *(_DWORD *)(v38 + 12);
            __dmb(0xBu);
          }
          while ( (v65 & 0x80000000) != 0 );
          do
            v43 = __ldrex(v42);
          while ( __strex(v43 | 0x80, v42) );
        }
        MiFinalizePageAttribute(v38, *(unsigned __int8 *)(v10 + 18) >> 6, 1);
        MiCopyPfnEntry(v38, (int *)v10);
        v44 = *(_BYTE *)(v38 + 19);
        if ( (v44 & 8) == 0 && (v44 & 7u) < 5 )
          *(_BYTE *)(v38 + 19) = v44 & 0xF8 | 5;
        *(_DWORD *)(v38 + 4) = v86;
        *(_DWORD *)(v38 + 20) = *(_DWORD *)(v38 + 20) & 0xFFF00000 | v88 | 0x8000000;
        v45 = *(_DWORD *)(v38 + 8);
        if ( (v45 & 0x80) != 0 )
          *(_DWORD *)(v38 + 8) = v45 | 0x20;
        __dmb(0xBu);
        v46 = (unsigned int *)(v38 + 12);
        do
          v47 = __ldrex(v46);
        while ( __strex(v47 & 0x7FFFFFFF, v46) );
        if ( (*(_DWORD *)(v10 + 8) & 0x10) != 0 )
        {
          *(_DWORD *)(v10 + 8) &= 0xFFFFFFEF;
          if ( v39 )
            v39 &= 0xFFFFFFEF;
        }
        v48 = v9 & 0xFFF | (a6 << 12);
        if ( (v9 & 0x80) != 0 )
          v48 = v48 & 0xFFFFFE7F | 0x100;
        if ( a2 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)a2 = v48;
        }
        else
        {
          v49 = *(_DWORD *)a2;
          v50 = 0;
          __dmb(0xBu);
          *(_DWORD *)a2 = v48;
          if ( (v49 & 2) == 0 && (v48 & 2) != 0 )
            v50 = 1;
          if ( a2 >= 0xC0300000 && a2 <= 0xC0300FFF )
          {
            v66 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v66, (_DWORD *)(v66 + 4 * (a2 & 0xFFF)), v48);
          }
          if ( v50 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        *(_DWORD *)a3 = 0;
        if ( a3 + 0x40000000 <= 0x3FFFFF )
        {
          v67 = 0;
          __dmb(0xBu);
          *(_DWORD *)a3 = v48;
          if ( (v48 & 2) != 0 )
            v67 = 1;
          if ( a3 + 1070596096 <= 0xFFF )
          {
            v68 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v68, (_DWORD *)(v68 + 4 * (a3 & 0xFFF)), v48);
          }
          if ( v67 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        else
        {
          *(_DWORD *)a3 = v48;
        }
        *(_DWORD *)(v10 + 12) |= 0x40000000u;
        __dmb(0xBu);
        v51 = (unsigned int *)(v10 + 12);
        do
          v52 = __ldrex(v51);
        while ( __strex(v52 & 0x7FFFFFFF, v51) );
        MiInsertTbFlushEntry(a5, v84, 1, 0);
        if ( v39 )
          MiReleasePageFileInfo((int)MiSystemPartition, v39, 1, v53);
        v54 = (unsigned __int8 *)(v91 + 15);
        do
          v55 = __ldrex(v54);
        while ( __strex(v55 | 0x80, v54) );
        __dmb(0xBu);
        if ( v55 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v69 = *(_DWORD *)(v91 + 12);
              __dmb(0xBu);
            }
            while ( (v69 & 0x80000000) != 0 );
            do
              v70 = __ldrex(v54);
            while ( __strex(v70 | 0x80, v54) );
            __dmb(0xBu);
          }
          while ( v70 >> 7 );
        }
        *(_DWORD *)(v91 + 12) = *(_DWORD *)(v91 + 12) & 0xC0000000 | (*(_DWORD *)(v91 + 12) + 1) & 0x3FFFFFFF;
        __dmb(0xBu);
        v56 = (unsigned int *)(v91 + 12);
        do
          v57 = __ldrex(v56);
        while ( __strex(v57 & 0x7FFFFFFF, v56) );
        v58 = *a4;
        if ( *a4 == MiSystemPartition )
        {
          MiReturnResidentAvailable(1);
          do
            v59 = __ldrex(&dword_634A2C[39]);
          while ( __strex(v59 + 1, &dword_634A2C[39]) );
        }
        else
        {
          v71 = (unsigned int *)(v58 + 1920);
          do
            v72 = __ldrex(v71);
          while ( __strex(v72 + 1, v71) );
        }
        MiReturnCommit((int)v58, 1);
        do
          v60 = __ldrex((unsigned int *)&dword_634D94);
        while ( __strex(v60 - 1, (unsigned int *)&dword_634D94) );
        v20 = a1;
        if ( (*(_BYTE *)(a1 + 112) & 7) == 0 )
          *(_DWORD *)(*v87 * *(_DWORD *)(v85 + 36) + *(_DWORD *)(v85 + 252)) &= 0xFFFFFE0F;
        --*(_DWORD *)(a1 + 64);
        if ( v84 < 0xC0000000 || v84 > 0xC03FFFFF )
          --*(_DWORD *)(a1 + 56);
        goto LABEL_41;
      }
LABEL_143:
      __dmb(0xBu);
      v73 = (unsigned int *)(v10 + 12);
      do
        v74 = __ldrex(v73);
      while ( __strex(v74 & 0x7FFFFFFF, v73) );
      return 0;
    }
  }
  return 0;
}
