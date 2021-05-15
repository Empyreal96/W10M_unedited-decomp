// MiGetWorkingSetInfoList 
 
int __fastcall MiGetWorkingSetInfoList(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r4
  int v8; // r0
  int v9; // r10
  int v10; // r2
  unsigned int v11; // r9
  unsigned int *v12; // r5
  int v13; // r3
  _DWORD *v14; // r8
  int v15; // r1
  int v16; // r0
  int i; // r3
  int v18; // r6
  unsigned int v19; // r5
  unsigned int v20; // r2
  unsigned int *v21; // r0
  unsigned int v22; // r1
  unsigned int v23; // r2
  int v24; // r3
  unsigned int *v25; // r0
  unsigned int v26; // r1
  unsigned int v27; // r2
  int v28; // r2
  unsigned int *v29; // r5
  _DWORD *v30; // r0
  unsigned int *v31; // r4
  int v32; // r0
  unsigned int v33; // r1
  unsigned int v34; // r1
  unsigned int v35; // r2
  _DWORD *v36; // r9
  int v37; // r4
  int *v38; // r8
  _DWORD *v39; // r2
  _DWORD *v40; // t1
  unsigned int v41; // r5
  int v42; // r1
  int v43; // r3
  int v44; // r6
  char v45; // r3
  int v46; // r0
  int v47; // r4
  unsigned int v48; // r2
  unsigned int v49; // r8
  int v50; // r6
  int v51; // r4
  int v52; // r2
  int v53; // r3
  char v54; // r1
  unsigned int v55; // r3
  int v56; // r2
  int v57; // r9
  unsigned int v58; // r6
  int v59; // lr
  char v60; // r3
  unsigned int v61; // r4
  __int16 v62; // r3
  unsigned int v63; // r0
  unsigned int v64; // r5
  bool v65; // zf
  unsigned int v66; // r2
  int v67; // r5
  unsigned int *v68; // r0
  unsigned int v69; // r1
  unsigned int v70; // r2
  __int16 v71; // r3
  int v73; // [sp+0h] [bp-F8h]
  int v74; // [sp+8h] [bp-F0h]
  int v75; // [sp+Ch] [bp-ECh]
  unsigned int v76; // [sp+10h] [bp-E8h]
  _DWORD *v77; // [sp+18h] [bp-E0h]
  int v79; // [sp+30h] [bp-C8h] BYREF
  int v80; // [sp+34h] [bp-C4h]
  unsigned int *v81; // [sp+38h] [bp-C0h]
  int v82; // [sp+3Ch] [bp-BCh]
  int v83; // [sp+40h] [bp-B8h]
  int v84; // [sp+44h] [bp-B4h]
  _DWORD *v85; // [sp+48h] [bp-B0h] BYREF
  unsigned int *v86; // [sp+4Ch] [bp-ACh]
  int v87; // [sp+50h] [bp-A8h]
  int v88; // [sp+54h] [bp-A4h] BYREF
  unsigned int v89; // [sp+58h] [bp-A0h]
  int v90; // [sp+5Ch] [bp-9Ch] BYREF
  int v91; // [sp+60h] [bp-98h]
  _DWORD *v92; // [sp+64h] [bp-94h]
  int v93; // [sp+68h] [bp-90h]
  unsigned int v94; // [sp+6Ch] [bp-8Ch]
  _DWORD v95[20]; // [sp+70h] [bp-88h] BYREF
  _DWORD _C0[20]; // [sp+C0h] [bp-38h] BYREF

  _C0[16] = a1;
  _C0[17] = a2;
  _C0[18] = a3;
  v91 = a4;
  _C0[19] = a4;
  v4 = a3;
  v82 = a2 >> 3;
  v81 = (unsigned int *)(a2 >> 3);
  if ( !(a2 >> 3) )
    return -1073741820;
  if ( (a4 & 3) == 3 || (a4 & 0xFFFFFFFC) != 0 )
    return -1073741811;
  v8 = ExAllocatePoolWithTag(512, 4 * (((a2 & 0xFFF) != 0) + (a2 >> 12) + 8), 538996045);
  v9 = v8;
  v83 = v8;
  if ( !v8 )
    return -1073741670;
  *(_DWORD *)v8 = 0;
  v10 = a1 & 0xFFF;
  *(_WORD *)(v8 + 4) = 4 * (((v10 + a2 + 4095) >> 12) + 7);
  *(_WORD *)(v8 + 6) = 0;
  *(_DWORD *)(v8 + 16) = a1 & 0xFFFFF000;
  *(_DWORD *)(v8 + 24) = v10;
  *(_DWORD *)(v8 + 20) = a2;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v76 = v11;
  MmProbeAndLockPages(v8, *(char *)(v11 + 0x15A), 1);
  if ( (*(_WORD *)(v9 + 6) & 5) != 0 )
    v12 = *(unsigned int **)(v9 + 12);
  else
    v12 = (unsigned int *)MmMapLockedPagesSpecifyCache(v9, 0, 1, 0, 0, 1073741840);
  v86 = v12;
  if ( v12 )
  {
    if ( *(_DWORD *)(v11 + 116) == v4 )
    {
      v13 = 0;
    }
    else
    {
      KiStackAttachProcess(v4, 0);
      v13 = 1;
    }
    v84 = v13;
    v14 = 0;
    v77 = 0;
    v15 = 17;
    v74 = 17;
    v16 = 0;
    v75 = 0;
    v90 = 0;
    v7 = -1073741558;
    v93 = 4194300;
    v87 = -1073741824;
    v83 = 0x400000;
    v92 = (_DWORD *)(v4 + 492);
    for ( i = v82; ; i = --v82 )
    {
      if ( !i )
      {
        if ( v15 != 17 )
        {
          v68 = (unsigned int *)(a3 + 492);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v68);
          }
          else
          {
            __dmb(0xBu);
            do
              v69 = __ldrex(v68);
            while ( __strex(v69 & 0xBFFFFFFF, v68) );
            __dmb(0xBu);
            do
              v70 = __ldrex(v68);
            while ( __strex(v70 - 1, v68) );
          }
          KfLowerIrql(v74);
          v16 = v75;
        }
        if ( v16 )
          v16 = MiLockProtoPage(0, v16, 17);
        if ( v14 )
        {
          if ( v14 == v95 )
          {
            v71 = *(_WORD *)(v11 + 310) + 1;
            *(_WORD *)(v11 + 310) = v71;
            if ( !v71 && *(_DWORD *)(v11 + 100) != v11 + 100 )
              KiCheckForKernelApcDelivery(v16);
          }
          else
          {
            MiUnlockAndDereferenceVad(v14);
          }
        }
        if ( v84 == 1 )
          KiUnstackDetachProcess(_C0, 0);
        MmUnlockPages(v9);
        ExFreePoolWithTag(v9, 0);
        return 0;
      }
      v18 = 0;
      v19 = *v12;
      v94 = v19;
      if ( v19 <= MmHighestUserAddress )
        break;
LABEL_188:
      v67 = (int)v86;
      v86[1] = v18;
      v12 = (unsigned int *)(v67 + 8);
      v86 = v12;
    }
    v20 = v19 >> 12;
    v89 = v19 >> 12;
    if ( v14 == v95 )
    {
      if ( v15 != 17 )
      {
        v21 = (unsigned int *)(a3 + 492);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v21);
        }
        else
        {
          __dmb(0xBu);
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 & 0xBFFFFFFF, v21) );
          __dmb(0xBu);
          do
            v23 = __ldrex(v21);
          while ( __strex(v23 - 1, v21) );
        }
        v16 = KfLowerIrql(v74);
        v74 = 17;
      }
      v24 = (__int16)(*(_WORD *)(v11 + 310) + 1);
      *(_WORD *)(v11 + 310) = v24;
      if ( !v24 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v16);
    }
    else if ( v14 )
    {
      if ( v20 < v14[3] || v20 > v14[4] )
      {
        if ( v16 )
        {
          MiLockProtoPage(0, v16, v15);
          v75 = 0;
          v15 = v74;
        }
        if ( v15 != 17 )
        {
          v25 = (unsigned int *)(a3 + 492);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v25);
          }
          else
          {
            __dmb(0xBu);
            do
              v26 = __ldrex(v25);
            while ( __strex(v26 & 0xBFFFFFFF, v25) );
            __dmb(0xBu);
            do
              v27 = __ldrex(v25);
            while ( __strex(v27 - 1, v25) );
          }
          KfLowerIrql(v74);
          v74 = 17;
        }
        MiUnlockAndDereferenceVad(v14);
        v14 = 0;
        v77 = 0;
      }
      if ( v14 )
        goto LABEL_52;
    }
    if ( (v19 & 0xFFFFF000) != 2147352576 || (*(_DWORD *)(a3 + 736) & 1) != 0 )
    {
      v14 = (_DWORD *)MiObtainReferencedVad(v19, &v90);
      v77 = v14;
      if ( !v14 )
      {
        if ( v90 == -1073741558 )
        {
          if ( v84 == 1 )
            KiUnstackDetachProcess(_C0, 0);
          goto LABEL_191;
        }
        goto LABEL_187;
      }
    }
    else
    {
      v14 = v95;
      v77 = v95;
      memset(v95, 0, 76);
      v95[7] &= 0xFFFFFFF8;
      --*(_WORD *)(v11 + 310);
    }
LABEL_52:
    v28 = v14[7];
    if ( (v28 & 7) == 1 )
    {
      v18 = (16 * (MmProtectToValue[(unsigned __int8)v28 >> 3] & 0x7FF)) | 0x400001;
LABEL_187:
      v16 = v75;
      v15 = v74;
      goto LABEL_188;
    }
    v85 = (_DWORD *)(((v19 >> 20) & 0xFFC) - 1070596096);
    v29 = (unsigned int *)((v93 & (v19 >> 10)) - 0x40000000);
    v81 = v29;
    if ( v74 == 17 )
    {
      v74 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        v30 = v92;
LABEL_74:
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v30);
LABEL_80:
        v36 = v85;
        while ( 2 )
        {
          v18 = 0;
          v80 = 0;
          v37 = 0;
          v38 = (int *)&v85;
          while ( !v37 )
          {
            v40 = (_DWORD *)*v38++;
            v39 = v40;
            v41 = *v40;
            if ( !*v40 )
              goto LABEL_105;
            if ( (v41 & 2) == 0 )
            {
              v42 = 0;
              v43 = (v41 >> 11) & 1;
              if ( v43 || (v41 & 0x10) != 0 )
              {
                if ( (v91 & 1) != 0 )
                {
                  v44 = v18 | 0x200000;
                  if ( v43 )
                    v45 = 1;
                  else
                    v45 = 2;
                  v18 = v44 & 0xFF3FFFFF | ((v45 & 3) << 22);
                  v80 = v18;
                }
                else if ( (v91 & 2) != 0 )
                {
                  v73 = 0;
                  MiMakeSystemAddressValid((_DWORD)v39 << 10, 0);
                  v42 = 1;
                }
              }
              if ( !v42 )
                goto LABEL_185;
            }
            v37 = 1;
          }
          if ( (*v36 & 0x400) != 0 )
          {
            v56 = (v89 & 0x3FF) + (*v36 >> 12);
            v49 = v18 | 0x800001;
            LOBYTE(v41) = 0;
          }
          else
          {
            v41 = *v81;
            if ( (*v81 & 2) == 0 )
            {
              if ( (v41 & 0x400) != 0 )
              {
                v14 = v77;
              }
              else
              {
                if ( (v41 & 0x800) != 0 )
                {
                  if ( !MiQueryPfnUnsafe(v41 >> 12, v81, *v81, &v79, v73) )
                    continue;
                  v14 = v77;
LABEL_131:
                  v18 = v80;
                  goto LABEL_186;
                }
                if ( (v41 & 0x10) != 0 )
                {
                  v18 = v18 & 0xFF3FFFFF | 0x800000;
                  goto LABEL_185;
                }
                if ( v41 )
                  goto LABEL_185;
LABEL_105:
                v14 = v77;
                if ( v77 == v95 || (v77[7] & 0x8000) != 0 )
                  goto LABEL_186;
              }
              v46 = 0;
              if ( v14 == v95 )
              {
                v46 = dword_6337D8;
                goto LABEL_114;
              }
              if ( (v14[7] & 0x8000) != 0
                || (v46 = MiGetProtoPteAddress(v14, v89, 1, &v88), v41) && (v41 & 0xFFFFE000) != -8192 )
              {
                v47 = (v41 & 0x1FC | (v41 >> 2) & 0x3FFFFE00) - 0x40000000;
              }
              else
              {
LABEL_114:
                v47 = v46;
              }
              if ( v47 )
              {
                v80 = v18 | 0x8000;
                if ( v47 == v46 )
                  v80 = v18 | 0x40008000;
                if ( ((v47 ^ v75) & 0xFFFFF000) != 0 )
                {
                  v75 = MiLockProtoPage(v47, v75, v74);
                  continue;
                }
                while ( 1 )
                {
                  v48 = *(_DWORD *)v47;
                  if ( (*(_DWORD *)v47 & 2) == 0 )
                  {
                    if ( (v48 & 0x400) != 0 )
                      goto LABEL_131;
                    if ( (v48 & 0x800) == 0 )
                      break;
                  }
                  if ( MiQueryPfnUnsafe(v48 >> 12, v47, v48, &v79, v73) )
                    goto LABEL_131;
                }
                if ( (v48 & 0x10) != 0 )
                {
                  v18 = v80 & 0xFF3FFFFF | 0x800000;
                }
                else
                {
                  if ( v48 )
                    goto LABEL_131;
                  v18 = 0;
                }
              }
LABEL_186:
              v11 = v76;
              v7 = -1073741558;
              goto LABEL_187;
            }
            v49 = v18 | 1;
            v50 = v77[7];
            if ( (v50 & 7) == 6 )
            {
              v51 = MmPfnDatabase + 24 * (v41 >> 12);
              if ( MI_IS_PFN(v41 >> 12) && (*(_BYTE *)(v51 + 19) & 0x40) != 0 )
                v49 |= 0x80000000;
              if ( MiRotatedToFrameBuffer(v81) )
              {
                if ( (v41 & 0x80) != 0 )
                  v52 = 4;
                else
                  v52 = 1;
                v53 = (unsigned __int8)v50 >> 6;
                if ( v53 == 3 && (v50 & 0x38) != 0 )
                {
                  v52 |= 0x18u;
                }
                else if ( v53 == 1 )
                {
                  v52 |= 8u;
                }
              }
              else
              {
                if ( (*(_BYTE *)(v51 + 19) & 8) != 0 )
                  v54 = 5;
                else
                  v54 = *(_BYTE *)(v51 + 19) & 7;
                v49 = v49 & 0xF8C0FFFF | (((*(_DWORD *)(v51 + 20) >> 28) | ((v54 & 7) << 8)) << 16);
                v52 = (*(_DWORD *)(v51 + 8) >> 5) & 0x1F;
                if ( (*(_DWORD *)(v51 + 4) & 0x80000000) == 0 )
                {
                  v55 = *(_DWORD *)(v51 + 12) & ~v87;
                  if ( v55 >= 7 )
                    LOBYTE(v55) = 7;
                  v49 = ((unsigned __int8)v49 ^ (unsigned __int8)(2 * v55)) & 0xE ^ (v49 | 0x8000);
                  v52 = MmMakeProtectNotWriteCopy[v52];
                }
              }
              v18 = (v49 ^ (16 * MmProtectToValue[v52])) & 0x7FF0 ^ v49;
LABEL_185:
              v14 = v77;
              goto LABEL_186;
            }
            v56 = v41 >> 12;
          }
          break;
        }
        v57 = MmPfnDatabase + 24 * v56;
        v58 = *(_DWORD *)(v57 + 20);
        v59 = (v58 >> 27) & 1;
        if ( (*(_BYTE *)(v57 + 19) & 8) != 0 )
          v60 = 5;
        else
          v60 = *(_BYTE *)(v57 + 19) & 7;
        v61 = (((unsigned __int16)v49 ^ (unsigned __int16)((v59 != 0) << 15)) & 0x8000 ^ v49) & 0xF8C0FFFF | (((v58 >> 28) | ((v60 & 7) << 8)) << 16);
        if ( (*(_BYTE *)(v57 + 19) & 0x40) != 0 )
          v61 |= 0x80000000;
        if ( (v61 & 0x800000) != 0 )
          goto LABEL_181;
        if ( (HIBYTE(v58) & 7) == 1 )
        {
          if ( v59 )
          {
LABEL_181:
            v14 = v77;
            v18 = v61 & 0xFFFF800F | (16 * (MmProtectToValue[(unsigned __int8)v77[7] >> 3] & 0x7FF | 0x40000));
            if ( v59 )
            {
              v66 = *(_DWORD *)(v57 + 12) & ~v87;
              if ( v66 >= 7 )
                LOBYTE(v66) = 7;
              v18 = v18 & 0xFFFFFFF1 | (2 * (v66 & 7 | 0x20000000));
            }
            goto LABEL_186;
          }
          if ( (v41 & 0x20) != 0 )
          {
            if ( (v41 & 0x80) != 0 )
              v62 = 4;
            else
              v62 = 2;
          }
          else
          {
            v62 = 1;
          }
          v18 = v61 & 0xFFFF800F | (16 * (v62 & 0x7FF)) | v83;
          goto LABEL_185;
        }
        v63 = MiLocateWsle(v94, a3 + 492, *(_DWORD *)v57);
        if ( v63 < MEMORY[0xC0402004] )
          v61 |= v83;
        if ( (*(_DWORD *)(v57 + 20) & 0x8000000) == 0 )
        {
          v18 = v61 & 0xFFFF8001 | (16 * (MmProtectToValue[(*(_DWORD *)(v57 + 8) >> 5) & 0x1F] & 0x7FF));
          goto LABEL_185;
        }
        v64 = *(_DWORD *)(v57 + 12) & ~v87;
        if ( v64 >= 7 )
          LOBYTE(v64) = 7;
        v18 = v61 & 0xFFFF8001 | (2
                                * (v64 & 7 | (8
                                            * (MmProtectToValue[MiGetPfnProtection(
                                                                  v57,
                                                                  MEMORY[0xC0402024] * v63 - 1069537344)] & 0x7FF))));
        v14 = v77;
        if ( v77 == v95 )
        {
          v18 |= 0x40000000u;
          goto LABEL_186;
        }
        if ( (v77[7] & 0x8000) != 0 )
          goto LABEL_186;
        v65 = MiGetProtoPteAddress(v77, v89, 1, &v88) == (*(_DWORD *)(v57 + 4) | 0x80000000);
        v7 = -1073741558;
        v11 = v76;
        v15 = v74;
        v16 = v75;
        if ( v65 )
          v18 |= 0x40000000u;
        goto LABEL_188;
      }
      v31 = v92;
      v32 = *v92 & 0x7FFFFFFF;
      do
        v33 = __ldrex(v31);
      while ( v33 == v32 && __strex(v32 + 1, v31) );
    }
    else
    {
      if ( (((unsigned int)(v29 + 1) & 0x3C) != 0 || !ExSpinLockIsContended(a3 + 492)) && !KeShouldYieldProcessor() )
        goto LABEL_80;
      v31 = (unsigned int *)(a3 + 492);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v31);
      }
      else
      {
        __dmb(0xBu);
        do
          v34 = __ldrex(v31);
        while ( __strex(v34 & 0xBFFFFFFF, v31) );
        __dmb(0xBu);
        do
          v35 = __ldrex(v31);
        while ( __strex(v35 - 1, v31) );
      }
      KfLowerIrql(v74);
      if ( v75 )
      {
        MiLockProtoPage(0, v75, 17);
        v75 = 0;
      }
      v74 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        v30 = (_DWORD *)(a3 + 492);
        goto LABEL_74;
      }
      v32 = *v31 & 0x7FFFFFFF;
      do
        v33 = __ldrex(v31);
      while ( v33 == v32 && __strex(v32 + 1, v31) );
    }
    __dmb(0xBu);
    if ( v33 != v32 )
      ExpWaitForSpinLockSharedAndAcquire(v31, v33);
    goto LABEL_80;
  }
  v7 = -1073741670;
LABEL_191:
  MmUnlockPages(v9);
  ExFreePoolWithTag(v9, 0);
  return v7;
}
