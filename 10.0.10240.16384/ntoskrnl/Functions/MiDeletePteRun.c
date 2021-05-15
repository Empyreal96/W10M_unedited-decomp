// MiDeletePteRun 
 
unsigned int __fastcall MiDeletePteRun(unsigned int result, unsigned int a2, int a3, int a4, int a5)
{
  int v5; // r10
  unsigned int v6; // r6
  int v7; // r5
  int v8; // r4
  int v9; // r3
  unsigned int v10; // r7
  int v11; // r10
  int v12; // r9
  int v13; // r4
  int v14; // r2
  unsigned int v15; // r8
  int v16; // r8
  int v17; // lr
  int v18; // r5
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  int v21; // r7
  unsigned int v22; // r2
  int v23; // r8
  unsigned int *v24; // r2
  unsigned int v25; // r0
  unsigned __int8 *v26; // r3
  unsigned int v27; // r1
  int v28; // r2
  unsigned int *v29; // r2
  unsigned int v30; // r5
  unsigned int v31; // r3
  unsigned __int8 *v32; // r3
  unsigned int v33; // r0
  int v34; // r0
  unsigned int *v35; // lr
  unsigned int v36; // r1
  unsigned __int8 *v37; // r2
  unsigned int v38; // r0
  int v39; // r0
  int v40; // r0
  unsigned __int8 *v41; // r1
  int v42; // r3
  unsigned int v43; // r2
  int v44; // r0
  int v45; // r0
  int v46; // r0
  unsigned __int8 *v47; // r1
  int v48; // r3
  unsigned int v49; // r2
  unsigned __int8 *v50; // r1
  int v51; // r3
  unsigned int v52; // r2
  int v53; // r0
  int v54; // r0
  int v55; // r4
  unsigned int *v56; // r2
  unsigned int v57; // r0
  int v58; // r0
  int v59; // [sp+8h] [bp-E0h]
  int v60; // [sp+Ch] [bp-DCh]
  int v61; // [sp+14h] [bp-D4h]
  __int16 *v63; // [sp+20h] [bp-C8h]
  unsigned int v64; // [sp+2Ch] [bp-BCh]
  unsigned int *v65; // [sp+34h] [bp-B4h]
  _DWORD v68[16]; // [sp+48h] [bp-A0h] BYREF
  _DWORD v69[24]; // [sp+88h] [bp-60h] BYREF

  v5 = a3;
  v6 = result;
  v7 = 0;
  v8 = 0;
  v60 = 0;
  v59 = 0;
  v63 = 0;
  if ( result <= a2 )
  {
    result = 0;
    v65 = (unsigned int *)(a3 + 276);
    while ( 1 )
    {
      v9 = *(_DWORD *)v6;
      if ( (*(_DWORD *)v6 & 2) != 0 )
        goto LABEL_7;
      if ( !v9 )
      {
        if ( v7 )
        {
          v39 = MiDeleteBatch(v69, v68, v7, v8, 0);
          v7 = 0;
          v59 = 0;
          *(_DWORD *)(a5 + 4) += v39;
          result = 0;
        }
        goto LABEL_7;
      }
      if ( (v9 & 0x400) == 0 )
      {
        if ( v7 )
        {
          v54 = MiDeleteBatch(v69, v68, v7, v8, 0);
          v7 = 0;
          v59 = 0;
          *(_DWORD *)(a5 + 4) += v54;
        }
        v34 = MiDeleteTransitionPte(v6, 1);
        if ( v34 != 1 )
        {
          v35 = (unsigned int *)(v5 + 276);
          do
            v36 = __ldrex(v35);
          while ( __strex(v36 - 1, v35) );
          if ( v34 == 3 )
          {
            ++*(_DWORD *)(a5 + 4);
            result = 0;
            goto LABEL_7;
          }
          goto LABEL_77;
        }
        v55 = *(_DWORD *)v6;
        MiReleasePageFileSpace(MiSystemPartition, *(_DWORD *)v6, 1);
        if ( (v55 & 2) != 0 || (v55 & 0x400) != 0 || (v55 & 0x800) != 0 || (v55 & 0x10) != 0 )
        {
          v56 = (unsigned int *)(v5 + 276);
          do
            v57 = __ldrex(v56);
          while ( __strex(v57 - 1, v56) );
        }
        if ( v6 + 0x40000000 > 0x3FFFFF )
        {
          result = 0;
          *(_DWORD *)v6 = 0;
LABEL_137:
          v8 = v60;
          goto LABEL_7;
        }
        __dmb(0xBu);
        result = 0;
        *(_DWORD *)v6 = 0;
        if ( v6 + 1070596096 > 0xFFF )
          goto LABEL_137;
        v58 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v58, v58 + 4 * (v6 & 0xFFF), 0);
LABEL_126:
        v8 = v60;
LABEL_77:
        result = 0;
        goto LABEL_7;
      }
      v10 = v9 & 0xFFFFFBFF | 2;
      v11 = 0;
      v61 = 0;
      v12 = 0;
      v64 = 0;
      if ( !MI_IS_PFN(v10 >> 12) )
        return sub_536840();
      v13 = MmPfnDatabase + 24 * (v10 >> 12);
      v14 = *(_DWORD *)(v13 + 4);
      v15 = v14 | 0x80000000;
      if ( (*(_DWORD *)(v13 + 20) & 0x8000000) == 0 )
      {
        if ( v7 )
        {
          v59 = 0;
          *(_DWORD *)(a5 + 4) += MiDeleteBatch(v69, v68, v7, v60, 0);
        }
        if ( v15 != v6 )
          KeBugCheckEx(26, 1027, v6);
        v18 = MmPfnDatabase + 24 * (*(_DWORD *)(v13 + 20) & 0xFFFFF);
        do
          v31 = __ldrex(v65);
        while ( __strex(v31 - 1, v65) );
        v32 = (unsigned __int8 *)(v13 + 15);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 | 0x80, v32) );
        __dmb(0xBu);
        if ( v33 >> 7 )
        {
          v47 = (unsigned __int8 *)(v13 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v48 = *(_DWORD *)(v13 + 12);
              __dmb(0xBu);
            }
            while ( (v48 & 0x80000000) != 0 );
            do
              v49 = __ldrex(v47);
            while ( __strex(v49 | 0x80, v47) );
            __dmb(0xBu);
          }
          while ( v49 >> 7 );
        }
        *(_DWORD *)(v13 + 12) |= 0x40000000u;
        goto LABEL_29;
      }
      if ( v6 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 )
        break;
      if ( v6 < 0xC0000000 )
        goto LABEL_18;
      if ( (v14 & 0x80000000) == 0 )
      {
        v17 = v59;
        v11 = v14 | 0x80000000;
        if ( !v59 )
        {
          v16 = 0;
          goto LABEL_19;
        }
        v44 = MiDeleteBatch(v69, v68, v59, v60, 0);
        v17 = 0;
        v59 = 0;
        *(_DWORD *)(a5 + 4) += v44;
        goto LABEL_100;
      }
      if ( !*(_DWORD *)(a3 + 272) )
      {
LABEL_18:
        v16 = 0;
        v17 = v59;
        goto LABEL_19;
      }
      v64 = v14 | 0x80000000;
      v17 = v59;
      v16 = MiLocateCloneAddress(a3, v15);
      v61 = v16;
      if ( v16 && v59 )
      {
        v45 = MiDeleteBatch(v69, v68, v59, v60, 0);
        v17 = 0;
        v59 = 0;
        *(_DWORD *)(a5 + 4) += v45;
      }
LABEL_19:
      v18 = MmPfnDatabase + 24 * (*(_DWORD *)(((v6 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
      if ( !v17 )
        goto LABEL_20;
      if ( v18 != v60 )
        goto LABEL_111;
      if ( MiSystemPartition != v63 )
        goto LABEL_111;
      v37 = (unsigned __int8 *)(v13 + 15);
      do
        v38 = __ldrex(v37);
      while ( __strex(v38 | 0x80, v37) );
      __dmb(0xBu);
      if ( v38 >> 7 )
      {
LABEL_111:
        v59 = 0;
        *(_DWORD *)(a5 + 4) += MiDeleteBatch(v69, v68, v17, v60, 0);
LABEL_20:
        v60 = v18;
        v19 = (unsigned __int8 *)(v13 + 15);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 | 0x80, v19) );
        __dmb(0xBu);
        if ( v20 >> 7 )
        {
          v41 = (unsigned __int8 *)(v13 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v42 = *(_DWORD *)(v13 + 12);
              __dmb(0xBu);
            }
            while ( (v42 & 0x80000000) != 0 );
            do
              v43 = __ldrex(v41);
            while ( __strex(v43 | 0x80, v41) );
            __dmb(0xBu);
          }
          while ( v43 >> 7 );
        }
      }
      if ( (v10 & 0x200) == 0 )
        v12 = MiCaptureDirtyBitToPfn(v13);
      if ( (*(_BYTE *)(v13 + 18) & 7) == 6
        && (*(_DWORD *)(v13 + 8) & 0x400) == 0
        && (*(_BYTE *)(v13 + 18) & 0x10) != 0
        && !v11
        && !v16 )
      {
        v69[v59] = v13;
        v68[v59] = v12;
        if ( !v59 )
          v63 = MiSystemPartition;
        if ( v6 + 0x40000000 > 0x3FFFFF )
        {
          result = 0;
          *(_DWORD *)v6 = 0;
        }
        else
        {
          __dmb(0xBu);
          result = 0;
          *(_DWORD *)v6 = 0;
          if ( v6 >= 0xC0300000 && v6 <= 0xC0300FFF )
          {
            v46 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v46, v46 + 4 * (v6 & 0xFFF), 0);
            result = 0;
          }
        }
        v7 = v59 + 1;
        v8 = v60;
        v59 = v7;
        if ( v7 == 16 )
        {
          v7 = 0;
          v5 = a3;
          v59 = 0;
          *(_DWORD *)(a5 + 4) += MiDeleteBatch(v69, v68, 16, v60, 0);
          result = 0;
        }
        else
        {
          v5 = a3;
        }
        goto LABEL_7;
      }
      v63 = MiSystemPartition;
      if ( v59 )
      {
        *(_DWORD *)(a5 + 4) += MiDeleteBatch(v69, v68, v59, v60, 1);
        v59 = 0;
      }
LABEL_29:
      if ( (*(_BYTE *)(v13 + 18) & 7) != 6 )
        KeBugCheckEx(78, 153, (v13 - MmPfnDatabase) / 24);
      v21 = 4;
      v22 = *(_DWORD *)(v13 + 12) & 0xC0000000 | (*(_DWORD *)(v13 + 12) - 1) & 0x3FFFFFFF;
      *(_DWORD *)(v13 + 12) = v22;
      if ( (v22 & 0x3FFFFFFF) != 0 )
      {
        v23 = v61;
      }
      else
      {
        v21 = MiPfnShareCountIsZero(v13, a4);
        v23 = v61;
        if ( v21 == 3 && (*(_DWORD *)(v13 + 20) & 0x8000000) != 0 && !v11 && !v61 )
          v21 = 4;
      }
      __dmb(0xBu);
      v24 = (unsigned int *)(v13 + 12);
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 & 0x7FFFFFFF, v24) );
      v26 = (unsigned __int8 *)(v18 + 15);
      do
        v27 = __ldrex(v26);
      while ( __strex(v27 | 0x80, v26) );
      __dmb(0xBu);
      if ( v27 >> 7 )
      {
        v50 = (unsigned __int8 *)(v18 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v51 = *(_DWORD *)(v18 + 12);
            __dmb(0xBu);
          }
          while ( (v51 & 0x80000000) != 0 );
          do
            v52 = __ldrex(v50);
          while ( __strex(v52 | 0x80, v50) );
          __dmb(0xBu);
        }
        while ( v52 >> 7 );
      }
      if ( (*(_BYTE *)(v18 + 18) & 7) != 6 )
        KeBugCheckEx(78, 153, (v18 - MmPfnDatabase) / 24);
      v28 = *(_DWORD *)(v18 + 12);
      *(_DWORD *)(v18 + 12) = v28 & 0xC0000000 | ((v28 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
      if ( (v28 & 0x3FFFFFFF) == 1 )
        MiPfnShareCountIsZero(v18, 0);
      __dmb(0xBu);
      v29 = (unsigned int *)(v18 + 12);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 & 0x7FFFFFFF, v29) );
      if ( v12 )
        MiReleasePageFileInfo(v63, v12, 1);
      if ( v11 )
      {
        v40 = MiDecrementCombinedPte(v11);
LABEL_98:
        v21 = v40;
        goto LABEL_46;
      }
      if ( v23 )
      {
        v40 = MiDecrementCloneBlockReference(v23, v64, a3);
        goto LABEL_98;
      }
LABEL_46:
      if ( v21 == 3 )
      {
        ++*(_DWORD *)(a5 + 4);
      }
      else if ( v21 == 5 )
      {
        ++*(_DWORD *)(a5 + 8);
      }
      if ( v6 + 0x40000000 > 0x3FFFFF )
      {
        result = 0;
        *(_DWORD *)v6 = 0;
      }
      else
      {
        __dmb(0xBu);
        result = 0;
        *(_DWORD *)v6 = 0;
        if ( v6 >= 0xC0300000 && v6 <= 0xC0300FFF )
        {
          v53 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v53, v53 + 4 * (v6 & 0xFFF), 0);
          v7 = v59;
          v5 = a3;
          goto LABEL_126;
        }
      }
      v7 = v59;
      v8 = v60;
      v5 = a3;
LABEL_7:
      v6 += 4;
      if ( v6 > a2 )
      {
        if ( v7 )
        {
          result = MiDeleteBatch(v69, v68, v7, v8, 0);
          *(_DWORD *)(a5 + 4) += result;
        }
        return result;
      }
    }
    v17 = v59;
LABEL_100:
    v16 = 0;
    goto LABEL_19;
  }
  return result;
}
