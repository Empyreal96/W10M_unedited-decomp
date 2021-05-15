// MiIdentifyPfn 
 
unsigned int __fastcall MiIdentifyPfn(int *a1, int *a2)
{
  int v3; // r3
  int v4; // r4
  int v5; // r5
  unsigned int v6; // r3
  int v7; // r2
  unsigned int v8; // r4
  int v9; // r1
  unsigned int v10; // r3
  unsigned int v11; // r1
  unsigned int result; // r0
  int *v13; // r5
  char v14; // r3
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r3
  int v21; // r3
  unsigned int v22; // r2
  int v23; // r1
  unsigned int v24; // r1
  int v25; // r2
  char v26; // r1
  int v27; // r2
  unsigned int v28; // r6
  int v29; // r3
  unsigned int v30; // r2
  unsigned int v31; // r2
  unsigned int v32; // r1
  unsigned int v33; // r3
  int v34; // r2
  unsigned int v35; // r3
  _DWORD *v36; // r7
  int v37; // r6
  unsigned int *v38; // r4
  unsigned int v39; // r2
  __int64 v40; // kr00_8
  unsigned int v41; // r3
  unsigned __int8 *v42; // r3
  unsigned int v43; // r1
  unsigned int v44; // r1
  unsigned int v45; // r1
  int v46; // r2
  int v47; // r1
  int v48; // r3
  char v49; // r1
  int v50; // r3
  int v51; // r3
  unsigned int v52; // r3
  int v53; // r2
  unsigned int v54; // r2
  int v55; // r3
  int v56; // r2
  unsigned int v57; // r2
  int v58; // r2
  unsigned int v59; // r4
  int v60; // r3
  int v61; // r3
  __int64 v62; // kr10_8
  int v63; // r1
  int v64; // r2
  unsigned int *v65; // r2
  int *v66; // r3
  int v67; // r2
  int v68; // r3
  int v69; // r1
  int v70; // r2
  unsigned int *v71; // r2
  int v72; // r1
  int v73; // r2
  unsigned int *v74; // r2
  unsigned int v76; // [sp+4h] [bp-44h] BYREF
  int *v77; // [sp+8h] [bp-40h]
  int *v78; // [sp+Ch] [bp-3Ch] BYREF
  unsigned int v79; // [sp+10h] [bp-38h] BYREF
  int v80; // [sp+14h] [bp-34h]
  int v81; // [sp+18h] [bp-30h]
  int v82; // [sp+1Ch] [bp-2Ch]
  int v83; // [sp+20h] [bp-28h]
  unsigned int v84; // [sp+24h] [bp-24h]
  int vars4; // [sp+4Ch] [bp+4h]

  v3 = a1[1];
  v4 = a1[2];
  v5 = a1[3];
  v79 = *a1;
  v80 = v3;
  v81 = v4;
  v82 = v5;
  v6 = a1[5];
  v83 = a1[4];
  v84 = v6;
  a2[2] = ((int)a1 - MmPfnDatabase) / 24;
  v7 = a2[1];
  v8 = v79;
  v9 = BYTE2(v83) & 7;
  v10 = *a2;
  a2[1] = v7;
  v77 = (int *)v9;
  *a2 = v10 & 0xFFFFFF8F | (16 * v9);
  v11 = *a2;
  result = 256;
  v13 = (int *)((HIBYTE(v83) >> 3) & 1);
  v14 = HIBYTE(v83) & 7;
  if ( v13 == (int *)1 )
    v14 = 5;
  v15 = v14 & 7;
  v16 = a2[1];
  *a2 = v11;
  v17 = v16 & 0xF1FFFFFF | (v15 << 25);
  v18 = v11;
  v19 = v17;
  a2[1] = v17;
  v20 = (v18 >> 4) & 7;
  v78 = v13;
  if ( v20 > 1 )
  {
    if ( v20 <= 4 )
    {
      if ( (_WORD)v83 )
      {
        *a2 = v18 | 0x100;
        a2[1] = v19;
      }
      if ( (v82 & 0x40000000) != 0 )
      {
        if ( (v84 & 0x8000000) == 0 )
          a2[3] = (v80 & 0xFFFFFFFC) << 10;
        goto LABEL_30;
      }
    }
    else
    {
      if ( v20 == 5 )
        return result;
      if ( v20 != 6 )
      {
        v21 = v18 | 0x100;
        v22 = v84;
        *a2 = v21;
        a2[1] = v19;
        v23 = v80;
        if ( (v22 & 0x8000000) == 0 )
          a2[3] = ((v80 | 0x80000000) & 0xFFFFFFFC) << 10;
        if ( (v22 & 0x7000000) == 0x1000000 )
        {
          v24 = v79 >> 23;
          v25 = a2[1];
          *a2 ^= (*a2 ^ (v79 << 9)) & 0xFFFFFE00;
          a2[1] = v25 & 0xFE000000 | v24 & 0x1FFFFFF;
          v26 = 9;
LABEL_133:
          v35 = *a2 & 0xFFFFFFF0 | v26 & 0xF;
          goto LABEL_134;
        }
        v27 = v22 & 0xFFFFF;
        if ( v27 == 1048573 )
        {
LABEL_12:
          v26 = 10;
          goto LABEL_133;
        }
        if ( v27 == 0xFFFFF && (v23 | 0x80000000) == -1073741824 )
        {
LABEL_15:
          v26 = 5;
          goto LABEL_133;
        }
LABEL_30:
        v35 = *a2 & 0xFFFFFFF0;
LABEL_134:
        a2[1] = a2[1];
        goto LABEL_135;
      }
      if ( !v8 || v13 || (unsigned __int16)v83 > 1u )
      {
        *a2 = v18 | 0x100;
        a2[1] = v19;
      }
    }
    v28 = v84;
    if ( (v84 & 0x8000000) != 0 )
    {
      if ( (v81 & 0x400) == 0 )
      {
        v29 = v80;
        v30 = v80 | 0x80000000;
        a2[3] = v80 | 0x80000000;
        if ( v29 >= 0 )
        {
          a2[3] = v30 | 1;
          v31 = *(_DWORD *)(v30 - 8);
          v32 = v31 >> 23;
          v33 = *a2 ^ (*a2 ^ (v31 << 9)) & 0xFFFFFE00;
          v34 = a2[1];
          *a2 = v33;
          a2[1] = v34 & 0xFE000000 | v32 & 0x1FFFFFF;
        }
        v26 = 2;
        goto LABEL_133;
      }
      v36 = (_DWORD *)(v81 & 0xFFFFF800 | (2 * (v81 & 0x3FC)));
      v37 = *v36;
      v38 = (unsigned int *)(*v36 + 36);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        result = ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(*v36 + 36));
      }
      else
      {
        v42 = (unsigned __int8 *)(*v36 + 39);
        do
          v43 = __ldrex(v42);
        while ( __strex(v43 | 0x80, v42) );
        __dmb(0xBu);
        if ( v43 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v38);
        while ( 1 )
        {
          result = *v38;
          if ( (*v38 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (result & 0x40000000) == 0 )
          {
            do
              v44 = __ldrex(v38);
            while ( v44 == result && __strex(result | 0x40000000, v38) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      v39 = *(_DWORD *)(v37 + 32) & 0xFFFFFFF8;
      if ( !v39 )
      {
        v40 = *(_QWORD *)a2;
        v41 = *a2 & 0xFFFFFEFF;
        *a2 = v41;
        a2[1] = HIDWORD(v40);
        *a2 = v41 & 0xFFFFFF8F | 0x10;
        a2[1] = HIDWORD(v40);
        if ( (dword_682604 & 0x10000) != 0 )
          return ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v38, vars4);
        __dmb(0xBu);
        *v38 = 0;
        return result;
      }
      a2[3] = *(_DWORD *)(v39 + 12);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        result = ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v38, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v38 = 0;
      }
      a2[3] = a2[3] & 0xFFFFFFFE | (*(_DWORD *)(v37 + 28) >> 5) & 1;
      v45 = v36[1];
      if ( v45 )
      {
        if ( (*((_WORD *)v36 + 9) & 2) == 0 || (*(_DWORD *)(v37 + 28) & 0x4000000) == 0 )
          v45 = v80 | 0x80000000;
        result = MiStartingOffset(v36, v45);
        v46 = a2[1];
        *a2 ^= (result ^ *a2) & 0xFFFFFE00;
        a2[1] = v46 & 0xFE000000 | v47 & 0x1FFFFFF;
      }
      v48 = *(_DWORD *)(v37 + 28);
      if ( (v48 & 8) != 0 && (v48 & 1) == 0 )
      {
        v26 = 8;
        goto LABEL_133;
      }
      v49 = 1;
      a2[1] = a2[1];
      goto LABEL_59;
    }
    result = v80;
    if ( v80 && (v84 & 0x7000000) != 0x1000000 )
      result = v80 | 0x80000000;
    if ( result >= dword_63389C )
    {
      v51 = *((unsigned __int8 *)&MiState[2423]
            + ((int)(((result >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
      if ( v51 == 5 || v51 == 13 )
      {
        v52 = *a2 ^ (*a2 ^ ((result - 352) << 9)) & 0xFFFFFE00;
        v53 = a2[1];
        *a2 = v52;
        v54 = v53 & 0xFE000000 | ((result - 352) >> 23) & 0x1FFFFFF;
        *a2 = v52 & 0xFFFFFFF0 | 3;
        a2[1] = v54;
        v55 = -1070596096;
        a2[1] = v54;
LABEL_68:
        a2[3] = v55;
        return result;
      }
    }
    if ( result == -4 )
    {
      v56 = a2[1];
      *a2 = *a2 & 0xFFFFFFF0 | 5;
      a2[1] = v56;
      v55 = MmBadPointer;
      goto LABEL_68;
    }
    v57 = HIBYTE(v84) & 7;
    v76 = v57;
    if ( v57 == 1 )
    {
      v58 = a2[1];
      *a2 ^= (*a2 ^ (v8 << 9)) & 0xFFFFFE00;
      a2[1] = v58 & 0xFE000000 | (v8 >> 23) & 0x1FFFFFF;
      a2[1] = a2[1];
      if ( result + 0x40000000 > 0x3FFFFF )
      {
        v49 = 9;
      }
      else
      {
        a2[3] = (result & 0xFFFFFFFC) << 10;
        v49 = 13;
      }
LABEL_59:
      v50 = *a2;
      goto LABEL_60;
    }
    if ( result )
      v59 = result << 10;
    else
      v59 = 0;
    if ( v59 >= dword_63389C )
    {
      if ( *((_BYTE *)&MiState[2423] + ((int)(((v59 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 5 )
      {
        v26 = 5;
        a2[3] = v59;
        goto LABEL_133;
      }
      v57 = v76;
    }
    a2[3] = v59 & 0xFFFFF000;
    if ( (v28 & 0xFFFFF) == 1048573 )
    {
      if ( v59 < dword_63389C
        || *((_BYTE *)&MiState[2423] + ((int)(((v59 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) != 9 )
      {
        goto LABEL_12;
      }
LABEL_85:
      v26 = 6;
      goto LABEL_133;
    }
    if ( v59 > MmHighestUserAddress )
    {
      if ( v57 == 2 )
      {
        v26 = 11;
        goto LABEL_133;
      }
      result = dword_63389C;
      if ( v59 >= dword_63389C )
      {
        v57 = ((unsigned int)dword_63389C >> 20) & 0xFFC;
        v60 = *((unsigned __int8 *)&MiState[2423] + ((int)(((v59 >> 20) & 0xFFC) - v57) >> 2));
        switch ( v60 )
        {
          case 1:
          case 11:
            result = MiGetTopLevelPfn((int)a1, 0, v57, v60);
            if ( (*(_DWORD *)(result + 12) & 0x40000000) != 0 )
            {
              *(_QWORD *)a2 &= 0xFE000000000001FFui64;
            }
            else
            {
              v63 = *(_DWORD *)result >> 23;
              v64 = a2[1];
              *a2 ^= (*a2 ^ (*(_DWORD *)result << 9)) & 0xFFFFFE00;
              a2[1] = v64 & 0xFE000000 | v63 & 0x1FFFFFF;
            }
            if ( (int *)result != a1 )
            {
              __dmb(0xBu);
              v65 = (unsigned int *)(result + 12);
              do
                result = __ldrex(v65);
              while ( __strex(result & 0x7FFFFFFF, v65) );
            }
            v26 = 7;
            goto LABEL_133;
          case 6:
          case 14:
            v26 = 4;
            goto LABEL_133;
          case 9:
          case 12:
            goto LABEL_85;
        }
      }
      if ( PsNtosImageBase
        && (v59 >= PsNtosImageBase && v59 < PsNtosImageEnd || v59 >= PsHalImageBase && v59 < PsHalImageEnd) )
      {
        goto LABEL_85;
      }
      if ( v59 )
      {
        if ( v59 >= dword_63389C )
        {
          v57 = ((unsigned int)dword_63389C >> 20) & 0xFFC;
          v61 = *((unsigned __int8 *)&MiState[2423] + ((int)(((v59 >> 20) & 0xFFC) - v57) >> 2));
          if ( v61 == 7 || v61 == 13 )
          {
            v62 = *(_QWORD *)a2;
            *a2 = *a2 & 0xFFFFFFF0 | 4;
            a2[1] = HIDWORD(v62);
            result = MmQuerySpecialPoolBlockType(v59);
            if ( (result & 1) != 0 )
              return result;
            goto LABEL_15;
          }
        }
      }
    }
    v66 = v77;
    if ( v77 != (int *)6 || v79 && (v66 = v78) == 0 )
    {
      result = MiGetTopLevelPfn((int)a1, &v76, v57, (int)v66);
      v72 = *(_DWORD *)result >> 23;
      v73 = a2[1];
      *a2 ^= (*a2 ^ (*(_DWORD *)result << 9)) & 0xFFFFFE00;
      a2[1] = v73 & 0xFE000000 | v72 & 0x1FFFFFF;
      if ( (int *)result != a1 )
      {
        __dmb(0xBu);
        v74 = (unsigned int *)(result + 12);
        do
          result = __ldrex(v74);
        while ( __strex(result & 0x7FFFFFFF, v74) );
      }
      if ( v76 != 2 )
      {
        v26 = 3;
        goto LABEL_133;
      }
      goto LABEL_30;
    }
    if ( v59 > MmHighestUserAddress
      && (MiPageInRange((int)&v79, 0xC0301000, (((unsigned int)dword_633894 >> 10) & 0x3FFFFC) - 0x40000000, 0)
       || (result = MiSystemWsMetaPage((int)&v79, &v78)) != 0) )
    {
      result = MiGetTopLevelPfn((int)a1, &v76, v67, v68);
      v69 = *(_DWORD *)result >> 23;
      v70 = a2[1];
      *a2 ^= (*a2 ^ (*(_DWORD *)result << 9)) & 0xFFFFFE00;
      a2[1] = v70 & 0xFE000000 | v69 & 0x1FFFFFF;
      if ( (int *)result != a1 )
      {
        __dmb(0xBu);
        v71 = (unsigned int *)(result + 12);
        do
          result = __ldrex(v71);
        while ( __strex(result & 0x7FFFFFFF, v71) );
      }
      v26 = 12;
      goto LABEL_133;
    }
    v50 = *a2;
    a2[1] = a2[1];
    if ( v59 + 0x40000000 > 0x3FFFFF )
      v49 = 5;
    else
      v49 = 3;
LABEL_60:
    v35 = v50 & 0xFFFFFFF0 | v49 & 0xF;
LABEL_135:
    *a2 = v35;
  }
  return result;
}
