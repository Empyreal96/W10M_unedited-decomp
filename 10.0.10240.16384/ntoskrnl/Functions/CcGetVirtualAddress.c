// CcGetVirtualAddress 
 
int __fastcall CcGetVirtualAddress(int a1, int a2, unsigned int a3, int a4, _DWORD *a5, _DWORD *a6, int a7, int a8)
{
  int v9; // r10
  int v10; // r3
  int v11; // r9
  int v13; // r0
  unsigned int *v14; // r8
  unsigned int v15; // r6
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r1
  int v20; // r3
  unsigned int v21; // r1
  unsigned int v22; // r4
  int v23; // r3
  __int16 v24; // r3
  int v25; // r1
  unsigned int v26; // r2
  int v27; // r3
  _DWORD *v28; // r6
  unsigned int *v29; // r2
  unsigned int v30; // r1
  unsigned int v31; // r1
  unsigned int v32; // r1
  unsigned int v33; // r0
  unsigned int v34; // r2
  int v35; // r9
  int v36; // r5
  int v37; // r3
  int v38; // r2
  unsigned __int8 *v39; // lr
  int v40; // r7
  unsigned int v41; // r1
  unsigned int v42; // r0
  int v43; // r2
  int v44; // r4
  __int16 v45; // r3
  int v46; // r2
  __int16 v47; // r3
  unsigned int v48; // r7
  int v49; // r8
  __int64 v50; // r2
  unsigned int v51; // r1
  unsigned int v52; // r0
  unsigned int v53; // r2
  int v54; // r1
  int v55; // r0
  int v56; // r2
  unsigned int v57; // r3
  int v58; // r3
  int v59; // r3
  unsigned int v60; // r3
  int v61; // r2
  unsigned __int8 *v62; // r4
  char v63; // r5
  unsigned int v64; // r0
  char v65; // r2
  unsigned int v66; // r0
  unsigned __int8 *v67; // r3
  unsigned int v68; // r2
  unsigned int *v69; // r2
  unsigned int v70; // r1
  __int64 v71; // [sp+8h] [bp-50h]
  int v72; // [sp+10h] [bp-48h]
  int v74; // [sp+1Ch] [bp-3Ch]
  int v75; // [sp+20h] [bp-38h]
  BOOL v76; // [sp+24h] [bp-34h]
  int v77; // [sp+28h] [bp-30h]
  __int64 v78[5]; // [sp+30h] [bp-28h] BYREF
  int varg_r0; // [sp+60h] [bp+8h]
  int varg_r1; // [sp+64h] [bp+Ch]
  unsigned int varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v9 = a3 & 0x3FFFF;
  v77 = 0;
  HIDWORD(v71) = a3 - (a3 & 0x3FFFF);
  v72 = a3 & 0x3FFFF;
  LODWORD(v71) = HIDWORD(v71);
  v10 = *(_DWORD *)(a1 + 96) & 0x200;
  varg_r2 = a3;
  varg_r3 = a4;
  v11 = a1;
  v76 = v10 != 0;
  if ( v10 || a7 )
  {
    v75 = 1;
    if ( (unsigned int)CcNumberOfFreeVacbs < 5 )
      return sub_52CCF0();
  }
  else
  {
    v75 = 0;
    if ( (unsigned int)CcNumberOfFreeVacbs < 5 )
      JUMPOUT(0x52CD00);
  }
  if ( __SPAIR64__(a4, a3) > *(_QWORD *)(a1 + 24) )
    KeBugCheckEx(52, 1353, -1073740768);
  v74 = -1;
  v13 = (int)MiState;
  v14 = (unsigned int *)(v11 + 72);
  if ( !KiAbEnabled || ((unsigned int)v14 & 0x7FFFFFFC) == 0 )
  {
    v22 = 0;
    goto LABEL_22;
  }
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v16 = 0;
  }
  else
  {
    __disable_irq();
    v16 = 1;
  }
  v17 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v16 )
    __enable_irq();
  if ( (v17 & 0x10001) != 0 )
  {
    KeGetCurrentIrql(MiState);
    KeBugCheckEx(402, v15, v11 + 72);
  }
  --*(_WORD *)(v15 + 310);
  if ( !*(_BYTE *)(v15 + 484) )
  {
    if ( !*(_BYTE *)(v15 + 810) )
    {
      v22 = 0;
      if ( (dword_682604 & 0x200) != 0 )
        v13 = EtwTraceAutoBoostEntryExhaustion(v15, v11 + 72);
      goto LABEL_124;
    }
    v62 = (unsigned __int8 *)(v15 + 810);
    v63 = *(_BYTE *)(v15 + 810);
    __dmb(0xBu);
    do
      v64 = __ldrex(v62);
    while ( __strex(v64 & ~v63, v62) );
    __dmb(0xBu);
    v13 = (int)MiState;
    *(_BYTE *)(v15 + 484) |= v63;
  }
  v18 = *(unsigned __int8 *)(v15 + 484);
  v19 = __clz(__rbit(v18));
  v20 = v18 & ~(1 << v19);
  LODWORD(v78[0]) = v19;
  v21 = v15 + 48 * v19;
  v22 = v21 + 488;
  *(_BYTE *)(v15 + 484) = v20;
  if ( v21 == -488 )
  {
LABEL_124:
    v67 = (unsigned __int8 *)(v15 + 81);
    do
      v68 = __ldrex(v67);
    while ( __strex(v68 | 0x80, v67) );
    goto LABEL_19;
  }
  if ( (unsigned int)v14 >= dword_63389C
    && ((v23 = *((unsigned __int8 *)&MiState[2423]
               + ((int)((((unsigned int)v14 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v23 == 1)
     || v23 == 11) )
  {
    v13 = MmGetSessionIdEx(*(_DWORD *)(v15 + 116));
  }
  else
  {
    v13 = -1;
  }
  *(_DWORD *)(v22 + 20) = v13;
  *(_DWORD *)(v22 + 16) = (unsigned int)v14 & 0x7FFFFFFC;
LABEL_19:
  v24 = *(_WORD *)(v15 + 310) + 1;
  *(_WORD *)(v15 + 310) = v24;
  if ( !v24 && *(_DWORD *)(v15 + 100) != v15 + 100 )
    KiCheckForKernelApcDelivery(v13);
LABEL_22:
  v25 = 17;
  do
    v26 = __ldrex(v14);
  while ( !v26 && __strex(0x11u, v14) );
  __dmb(0xBu);
  if ( v26 )
    ExfAcquirePushLockSharedEx(v11 + 72, v22, v11 + 72);
  if ( v22 )
    *(_BYTE *)(v22 + 14) |= 1u;
  if ( a8
    || (v27 = *(_DWORD *)(v11 + 96), (v27 & 0x200) != 0) && (v27 & 0x800000) == 0
    || (v27 & 0x1000) != 0
    || (v25 = HIDWORD(v71), (v71 & 0xFFFFF00000000i64) != 0)
    || v71 <= 0
    || (LODWORD(v50) = *(_DWORD *)(v11 + 220), HIDWORD(v50) = *(_DWORD *)(v11 + 216), v71 == v50) )
  {
    v77 = 1;
  }
  if ( *(__int64 *)(v11 + 24) > 0x2000000 )
    v28 = (_DWORD *)CcGetVacbLargeOffset(v11, v25, varg_r2, varg_r3);
  else
    v28 = *(_DWORD **)(*(_DWORD *)(v11 + 64) + 4 * (varg_r2 >> 18));
  if ( v28 )
  {
    __dmb(0xBu);
    v29 = v28 + 2;
    do
    {
      v30 = __ldrex(v29);
      v31 = v30 + 1;
    }
    while ( __strex(v31, v29) );
    __dmb(0xBu);
    if ( !(_WORD)v31 )
      KeBugCheckEx(52, 2410, -1073740768);
    __pld(v14);
    v32 = *v14;
    if ( (*v14 & 0xFFFFFFF0) > 0x10 )
      v33 = v32 - 16;
    else
      v33 = 0;
    if ( (v32 & 2) != 0 )
      goto LABEL_100;
    __dmb(0xBu);
    do
      v34 = __ldrex(v14);
    while ( v34 == v32 && __strex(v33, v14) );
    if ( v34 != v32 )
LABEL_100:
      v33 = ExfReleasePushLock(v11 + 72);
    if ( !KiAbEnabled )
      goto LABEL_68;
    if ( ((unsigned int)v14 & 0x7FFFFFFC) == 0 )
    {
LABEL_67:
      v9 = v72;
LABEL_68:
      v48 = HIDWORD(v71);
LABEL_69:
      v49 = HIDWORD(v71);
      goto LABEL_70;
    }
    v35 = 0;
    v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (unsigned int)v14 >= dword_63389C )
    {
      v33 = 4092;
      v37 = *((unsigned __int8 *)&MiState[2423]
            + ((int)((((unsigned int)v14 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
      if ( v37 == 1 || v37 == 11 )
      {
        v33 = MmGetSessionIdEx(*(_DWORD *)(v36 + 116));
        v74 = v33;
      }
    }
    if ( (unsigned int)KeGetCurrentIrql(v33) <= 1 )
    {
      v35 = 1;
      --*(_WORD *)(v36 + 310);
    }
    v38 = *(char *)(v36 + 484);
    __dmb(0xBu);
    v39 = (unsigned __int8 *)(v36 + 810);
    v40 = (v38 | *(char *)(v36 + 810)) ^ 0x3F;
    v41 = __clz(v40);
    v42 = 31 - v41;
    if ( 1 == (unsigned __int8)(v41 >> 5) )
    {
LABEL_94:
      if ( (*(_DWORD *)(v36 + 80) & 0x8000) == 0 )
        KeBugCheckEx(354, v36, v14);
      if ( !v35 )
        goto LABEL_66;
      v58 = (__int16)(*(_WORD *)(v36 + 310) + 1);
      *(_WORD *)(v36 + 310) = v58;
      if ( v58 || *(_DWORD *)(v36 + 100) == v36 + 100 )
        goto LABEL_66;
    }
    else
    {
      v43 = 2147483644;
      while ( 1 )
      {
        v40 &= ~(1 << v42);
        v44 = v36 + 48 * v42 + 488;
        if ( (*(_BYTE *)(v36 + 48 * v42 + 502) & 1) != 0
          && (*(_DWORD *)(v36 + 48 * v42 + 504) & 1) == 0
          && (*(_DWORD *)(v36 + 48 * v42 + 504) & 0x7FFFFFFC) == ((unsigned int)v14 & 0x7FFFFFFC)
          && *(_DWORD *)(v36 + 48 * v42 + 508) == v74 )
        {
          *(_BYTE *)(v36 + 48 * v42 + 502) &= 0xFEu;
          if ( *(_DWORD *)(v36 + 48 * v42 + 504) )
            break;
        }
        v57 = __clz(v40);
        v42 = 31 - v57;
        if ( 1 == (unsigned __int8)(v57 >> 5) )
          goto LABEL_94;
      }
      *(_BYTE *)(v36 + 48 * v42 + 504) |= 2u;
      if ( *(int *)(v36 + 48 * v42 + 504) < 0 )
      {
        KiAbEntryRemoveFromTree(v44);
        v39 = (unsigned __int8 *)(v36 + 810);
      }
      v45 = *(_WORD *)(v44 + 44);
      if ( v45 )
      {
        if ( (v45 & 1) != 0 )
        {
          __dmb(0xBu);
          v69 = (unsigned int *)(v36 + 804);
          do
            v70 = __ldrex(v69);
          while ( __strex(v70 - 1, v69) );
          __dmb(0xBu);
          PsBoostThreadIoEx(v36, 1, 0);
          v39 = (unsigned __int8 *)(v36 + 810);
        }
        if ( (*(_WORD *)(v44 + 44) & 0xFFFE) != 0 )
        {
          KiAbThreadUnboostCpuPriority(v36, v44, v43, *(_WORD *)(v44 + 44) & 0xFFFE);
          v39 = (unsigned __int8 *)(v36 + 810);
        }
        if ( (dword_682604 & 0x200) != 0 )
        {
          EtwTraceAutoBoostClearFloor(
            v36,
            *(_DWORD *)(v44 + 16) & 0xFFFFFFFC | 0x80000000,
            *(unsigned __int16 *)(v44 + 44));
          v39 = (unsigned __int8 *)(v36 + 810);
        }
        *(_WORD *)(v44 + 44) = 0;
      }
      *(_BYTE *)(v44 + 13) &= 0xFEu;
      *(_DWORD *)(v44 + 16) = 0;
      v42 = (unsigned __int64)(715827883i64 * (v44 - v36 - 488)) >> 32;
      v46 = (v44 - v36 - 488) / 48;
      if ( !v35 )
      {
        __dmb(0xBu);
        v65 = 1 << v46;
        do
          v66 = __ldrex(v39);
        while ( __strex(v66 | v65, v39) );
        __dmb(0xBu);
        goto LABEL_66;
      }
      *(_BYTE *)(v36 + 484) |= 1 << v46;
      v47 = *(_WORD *)(v36 + 310) + 1;
      *(_WORD *)(v36 + 310) = v47;
      if ( v47 || *(_DWORD *)(v36 + 100) == v36 + 100 )
      {
LABEL_66:
        v11 = a1;
        goto LABEL_67;
      }
    }
    KiCheckForKernelApcDelivery(v42);
    goto LABEL_66;
  }
  __pld(v14);
  v51 = *v14;
  if ( (*v14 & 0xFFFFFFF0) > 0x10 )
    v52 = v51 - 16;
  else
    v52 = 0;
  if ( (v51 & 2) != 0 )
    goto LABEL_121;
  __dmb(0xBu);
  do
    v53 = __ldrex(v14);
  while ( v53 == v51 && __strex(v52, v14) );
  if ( v53 != v51 )
LABEL_121:
    ExfReleasePushLock(v11 + 72);
  KeAbPostRelease(v11 + 72);
  v55 = CcGetVacbMiss(v11, v54, varg_r2, varg_r3, v76, v75);
  v56 = *(_DWORD *)(v11 + 96);
  v28 = (_DWORD *)v55;
  v48 = HIDWORD(v71);
  if ( (v56 & 0x200) == 0 )
    goto LABEL_69;
  v49 = HIDWORD(v71);
  if ( (v56 & 0x8001000) == 0 && (v71 & 0xFFFFF00000000i64) == 0 && v71 > 0 )
  {
    v49 = (__PAIR64__(HIDWORD(v71), HIDWORD(v71)) - 0x100000) >> 32;
    v48 = HIDWORD(v71) - 0x100000;
    v78[0] = __PAIR64__(HIDWORD(v71), HIDWORD(v71)) - 0x100000;
    CcUnmapVacbArray(v11, v78, 0x100000, 1, 0);
  }
LABEL_70:
  if ( !v77 )
  {
    if ( (*(_DWORD *)(v11 + 96) & 0x800000) != 0 )
    {
      if ( v49 < 0 || v49 <= 0 && v48 < 0x840000 )
      {
        v59 = 0x40000;
        goto LABEL_106;
      }
    }
    else if ( v49 < 0 || v49 <= 0 && v48 < 0x800000 )
    {
      v59 = 0;
LABEL_106:
      LODWORD(v78[0]) = v59;
      v60 = 0;
      v61 = v48;
LABEL_107:
      HIDWORD(v78[0]) = v60;
      CcUnmapVacbArray(v11, v78, v61, 1, 0);
      goto LABEL_71;
    }
    LODWORD(v78[0]) = v48 - 0x800000;
    __SET_PAIR__(v60, v60, __PAIR64__(v49, v48) - 0x800000);
    v61 = 0x800000;
    goto LABEL_107;
  }
LABEL_71:
  *a5 = v28;
  *a6 = 0x40000 - v9;
  return *v28 + v9;
}
