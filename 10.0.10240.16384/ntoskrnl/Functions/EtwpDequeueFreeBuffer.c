// EtwpDequeueFreeBuffer 
 
int __fastcall EtwpDequeueFreeBuffer(int a1)
{
  int v1; // r7
  int v2; // r8
  int v3; // r3
  int v4; // r0
  int v5; // r9
  unsigned int v6; // r6
  unsigned int v8; // r2
  __int64 v9; // r2
  int v10; // r4
  __int64 v11; // r2
  int v12; // r1
  unsigned int *v13; // r9
  unsigned int v14; // r2
  int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r6
  unsigned int v19; // r2
  __int64 v20; // kr00_8
  int v21; // r2
  unsigned int *v22; // r2
  unsigned int v23; // r1
  int v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r2
  int v27; // r4
  unsigned int v28; // r2
  unsigned int v29; // r7
  int v30; // r2
  int v31; // r3
  char v32; // r5
  unsigned __int8 *v33; // r4
  unsigned int v34; // r0
  unsigned int v35; // r2
  unsigned int v36; // r3
  int v37; // r4
  int v38; // r3
  int v39; // r3
  __int16 v40; // r3
  unsigned __int8 *v41; // r3
  unsigned int v42; // r2
  int v43; // r2
  int v44; // r1
  unsigned int v45; // r2
  int v46; // r1
  int v47; // r1
  unsigned int v48; // r0
  unsigned int v49; // r2
  int v50; // r0
  unsigned int v51; // r2
  unsigned int v52; // r7
  int v53; // r2
  int v54; // r3
  char v55; // r5
  unsigned __int8 *v56; // r4
  unsigned int v57; // r2
  unsigned int v58; // r3
  int v59; // r4
  int v60; // r3
  int v61; // r3
  __int16 v62; // r3
  unsigned __int8 *v63; // r3
  unsigned int v64; // r2
  int v65; // r2
  int v66; // r1
  unsigned int v67; // r2
  __int64 v68; // r2
  int v69; // r1
  int v70; // r1
  unsigned int v71; // r0
  unsigned int v72; // r2
  unsigned int v73; // r7
  int v74; // r2
  int v75; // r3
  unsigned __int8 *v76; // r4
  char v77; // r5
  unsigned int v78; // r2
  unsigned int v79; // r3
  int v80; // r3
  int v81; // r3
  __int16 v82; // r3
  unsigned __int8 *v83; // r3
  unsigned int v84; // r2
  int v85; // r1
  int v86; // r2
  int v87; // [sp+8h] [bp-30h]
  unsigned int v88; // [sp+10h] [bp-28h]
  unsigned int v89; // [sp+14h] [bp-24h]
  unsigned int v90; // [sp+18h] [bp-20h]

  v1 = 0;
  v2 = a1;
  v87 = 0;
  if ( *(_DWORD *)(a1 + 48) == *(_DWORD *)(a1 + 52) && *(_DWORD *)(a1 + 60) == *(_DWORD *)(a1 + 64) )
    return 0;
  v3 = *(_DWORD *)(a1 + 224);
  if ( (*(_DWORD *)(a1 + 12) & 0x400) != 0 )
  {
    v4 = 4092;
    if ( v3 != 1 )
    {
      v5 = KfRaiseIrql(15);
      v87 = v5;
      v6 = v2 + 508;
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_54C3A8();
      do
        v8 = __ldrex((unsigned int *)v6);
      while ( __strex(1u, (unsigned int *)v6) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v2 + 508));
      goto LABEL_9;
    }
    v6 = v2 + 508;
    if ( !KiAbEnabled || (v6 & 0x7FFFFFFC) == 0 )
    {
      v37 = 0;
      do
LABEL_100:
        v45 = __ldrex((unsigned __int8 *)v6);
      while ( __strex(v45 | 1, (unsigned __int8 *)v6) );
      __dmb(0xBu);
      if ( (v45 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 508), v37, v2 + 508);
      v5 = 0;
      if ( v37 )
        *(_BYTE *)(v37 + 14) |= 1u;
LABEL_9:
      v9 = *(_QWORD *)(v2 + 60);
      v10 = 0;
      if ( (_DWORD)v9 != HIDWORD(v9) )
      {
        v46 = *(_DWORD *)v9;
        *(_DWORD *)v9 = **(_DWORD **)v9;
        if ( v46 == *(_DWORD *)(v2 + 64) )
          *(_DWORD *)(v2 + 64) = *(_DWORD *)(v2 + 60);
        v10 = v46 - 32;
      }
      if ( !v10 )
      {
        v11 = *(_QWORD *)(v2 + 48);
        v10 = 0;
        if ( (_DWORD)v11 != HIDWORD(v11) )
        {
          v12 = *(_DWORD *)v11;
          *(_DWORD *)v11 = **(_DWORD **)v11;
          if ( v12 == *(_DWORD *)(v2 + 52) )
            *(_DWORD *)(v2 + 52) = *(_DWORD *)(v2 + 48);
          v10 = v12 - 32;
        }
      }
      if ( *(_DWORD *)(v2 + 224) == 1 )
      {
        __pld((void *)v6);
        v47 = *(_DWORD *)v6;
        if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
          v48 = 0;
        else
          v48 = v47 - 16;
        if ( (v47 & 2) != 0 )
          goto LABEL_117;
        __dmb(0xBu);
        do
          v49 = __ldrex((unsigned int *)v6);
        while ( v49 == v47 && __strex(v48, (unsigned int *)v6) );
        if ( v49 != v47 )
LABEL_117:
          ExfReleasePushLock((_DWORD *)v6, v47);
        KeAbPostRelease(v6);
      }
      else
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v6);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v6 = 0;
        }
        KfLowerIrql(v5);
      }
      if ( !v10 )
        return 0;
      v13 = (unsigned int *)(v2 + 156);
      while ( 1 )
      {
        __dmb(0xBu);
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 - 1, v13) );
        __dmb(0xBu);
        v15 = *(_DWORD *)(v10 + 12);
        __dmb(0xBu);
        if ( !v15 )
        {
          __dmb(0xBu);
          v16 = (unsigned int *)(v10 + 44);
          do
            v17 = __ldrex(v16);
          while ( !v17 && __strex(1u, v16) );
          __dmb(0xBu);
          if ( !v17 )
          {
            *(_DWORD *)(v10 + 4) = 0;
            __dmb(0xBu);
            *(_DWORD *)(v10 + 8) = 72;
            *(_WORD *)(v10 + 54) = 0;
            *(_DWORD *)(v10 + 32) = 0;
            goto LABEL_29;
          }
        }
        v50 = EtwpEnqueueOverflowBuffer(v2, v10);
        if ( *(_DWORD *)(v2 + 224) == 1 )
          break;
        v87 = KfRaiseIrql(15);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v6);
        }
        else
        {
          do
            v51 = __ldrex((unsigned int *)v6);
          while ( __strex(1u, (unsigned int *)v6) );
          __dmb(0xBu);
          if ( v51 )
            KxWaitForSpinLockAndAcquire((unsigned int *)v6);
        }
LABEL_162:
        v68 = *(_QWORD *)(v2 + 48);
        v10 = 0;
        if ( (_DWORD)v68 != HIDWORD(v68) )
        {
          v69 = *(_DWORD *)v68;
          *(_DWORD *)v68 = **(_DWORD **)v68;
          if ( v69 == *(_DWORD *)(v2 + 52) )
            *(_DWORD *)(v2 + 52) = *(_DWORD *)(v2 + 48);
          v10 = v69 - 32;
        }
        if ( *(_DWORD *)(v2 + 224) == 1 )
        {
          __pld((void *)v6);
          v70 = *(_DWORD *)v6;
          if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
            v71 = 0;
          else
            v71 = v70 - 16;
          if ( (v70 & 2) != 0 )
            goto LABEL_179;
          __dmb(0xBu);
          do
            v72 = __ldrex((unsigned int *)v6);
          while ( v72 == v70 && __strex(v71, (unsigned int *)v6) );
          if ( v72 != v70 )
LABEL_179:
            ExfReleasePushLock((_DWORD *)v6, v70);
          KeAbPostRelease(v6);
        }
        else
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v6);
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v6 = 0;
          }
          KfLowerIrql(v87);
        }
        if ( !v10 )
          return 0;
      }
      if ( !KiAbEnabled || (v6 & 0x7FFFFFFC) == 0 )
      {
        v59 = 0;
        do
LABEL_157:
          v67 = __ldrex((unsigned __int8 *)v6);
        while ( __strex(v67 | 1, (unsigned __int8 *)v6) );
        __dmb(0xBu);
        if ( (v67 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)v6, v59, v6);
        if ( v59 )
          *(_BYTE *)(v59 + 14) |= 1u;
        goto LABEL_162;
      }
      v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v53 = 0;
      }
      else
      {
        __disable_irq();
        v53 = 1;
      }
      v54 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
      if ( v53 )
        __enable_irq();
      if ( (v54 & 0x10001) != 0 )
      {
        KeGetCurrentIrql(v50);
        KeBugCheckEx(402, v52, v6);
      }
      --*(_WORD *)(v52 + 310);
      if ( !*(_BYTE *)(v52 + 484) )
      {
        if ( !*(_BYTE *)(v52 + 810) )
        {
          v59 = 0;
          if ( (dword_682604 & 0x200) != 0 )
            v50 = EtwTraceAutoBoostEntryExhaustion(v52, v6);
          goto LABEL_150;
        }
        v55 = *(_BYTE *)(v52 + 810);
        v56 = (unsigned __int8 *)(v52 + 810);
        __dmb(0xBu);
        do
          v50 = __ldrex(v56);
        while ( __strex(v50 & ~v55, v56) );
        __dmb(0xBu);
        *(_BYTE *)(v52 + 484) |= v55;
      }
      v57 = *(unsigned __int8 *)(v52 + 484);
      v89 = __clz(__rbit(v57));
      *(_BYTE *)(v52 + 484) = v57 & ~(unsigned __int8)(1 << v89);
      v58 = v52 + 48 * v89;
      v59 = v58 + 488;
      if ( v58 != -488 )
      {
        v50 = (int)MiState;
        if ( v6 >= dword_63389C
          && ((v60 = *((unsigned __int8 *)&MiState[2423]
                     + ((int)(((v6 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
               v60 == 1)
           || v60 == 11)
          && (v65 = *(_DWORD *)(v52 + 116), (v66 = *(_DWORD *)(v65 + 324)) != 0)
          && v65 != PsInitialSystemProcess )
        {
          v61 = *(_DWORD *)(v66 + 8);
        }
        else
        {
          v61 = -1;
        }
        *(_DWORD *)(v59 + 20) = v61;
        *(_DWORD *)(v59 + 16) = v6 & 0x7FFFFFFC;
LABEL_144:
        v62 = *(_WORD *)(v52 + 310) + 1;
        *(_WORD *)(v52 + 310) = v62;
        if ( !v62 && *(_DWORD *)(v52 + 100) != v52 + 100 )
          KiCheckForKernelApcDelivery(v50);
        goto LABEL_157;
      }
LABEL_150:
      v63 = (unsigned __int8 *)(v52 + 81);
      do
        v64 = __ldrex(v63);
      while ( __strex(v64 | 0x80, v63) );
      goto LABEL_144;
    }
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v30 = 0;
    }
    else
    {
      __disable_irq();
      v30 = 1;
    }
    v31 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v30 )
      __enable_irq();
    if ( (v31 & 0x10001) != 0 )
    {
      KeGetCurrentIrql(4092);
      KeBugCheckEx(402, v29, v2 + 508);
    }
    --*(_WORD *)(v29 + 310);
    if ( !*(_BYTE *)(v29 + 484) )
    {
      if ( !*(_BYTE *)(v29 + 810) )
      {
        v37 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          v4 = EtwTraceAutoBoostEntryExhaustion(v29, v2 + 508);
        goto LABEL_93;
      }
      v32 = *(_BYTE *)(v29 + 810);
      v33 = (unsigned __int8 *)(v29 + 810);
      __dmb(0xBu);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 & ~v32, v33) );
      __dmb(0xBu);
      v4 = 4092;
      *(_BYTE *)(v29 + 484) |= v32;
    }
    v35 = *(unsigned __int8 *)(v29 + 484);
    v88 = __clz(__rbit(v35));
    *(_BYTE *)(v29 + 484) = v35 & ~(unsigned __int8)(1 << v88);
    v36 = v29 + 48 * v88;
    v37 = v36 + 488;
    if ( v36 != -488 )
    {
      if ( v6 >= dword_63389C
        && ((v38 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((v6 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v38 == 1)
         || v38 == 11)
        && (v43 = *(_DWORD *)(v29 + 116), (v44 = *(_DWORD *)(v43 + 324)) != 0)
        && v43 != PsInitialSystemProcess )
      {
        v39 = *(_DWORD *)(v44 + 8);
      }
      else
      {
        v39 = -1;
      }
      *(_DWORD *)(v37 + 20) = v39;
      *(_DWORD *)(v37 + 16) = v6 & 0x7FFFFFFC;
LABEL_87:
      v40 = *(_WORD *)(v29 + 310) + 1;
      *(_WORD *)(v29 + 310) = v40;
      if ( !v40 && *(_DWORD *)(v29 + 100) != v29 + 100 )
        KiCheckForKernelApcDelivery(v4);
      goto LABEL_100;
    }
LABEL_93:
    v41 = (unsigned __int8 *)(v29 + 81);
    do
      v42 = __ldrex(v41);
    while ( __strex(v42 | 0x80, v41) );
    goto LABEL_87;
  }
  if ( v3 != 1 )
  {
    v1 = KfRaiseIrql(15);
    v18 = v2 + 508;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v2 + 508);
    }
    else
    {
      do
        v19 = __ldrex((unsigned int *)v18);
      while ( __strex(1u, (unsigned int *)v18) );
      __dmb(0xBu);
      if ( v19 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v2 + 508));
    }
    goto LABEL_36;
  }
  v18 = a1 + 508;
  if ( KiAbEnabled && (v18 & 0x7FFFFFFC) != 0 )
  {
    v73 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v74 = 0;
    }
    else
    {
      __disable_irq();
      v74 = 1;
    }
    v75 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v74 )
      __enable_irq();
    if ( (v75 & 0x10001) != 0 )
    {
      KeGetCurrentIrql(a1);
      KeBugCheckEx(402, v73, v2 + 508);
    }
    --*(_WORD *)(v73 + 310);
    if ( !*(_BYTE *)(v73 + 484) )
    {
      if ( !*(_BYTE *)(v73 + 810) )
      {
        v27 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          a1 = EtwTraceAutoBoostEntryExhaustion(v73, a1 + 508);
        goto LABEL_210;
      }
      v76 = (unsigned __int8 *)(v73 + 810);
      v77 = *(_BYTE *)(v73 + 810);
      __dmb(0xBu);
      do
        a1 = __ldrex(v76);
      while ( __strex(a1 & ~v77, v76) );
      __dmb(0xBu);
      *(_BYTE *)(v73 + 484) |= v77;
    }
    v78 = *(unsigned __int8 *)(v73 + 484);
    v90 = __clz(__rbit(v78));
    *(_BYTE *)(v73 + 484) = v78 & ~(unsigned __int8)(1 << v90);
    v79 = v73 + 48 * v90;
    v27 = v79 + 488;
    if ( v79 != -488 )
    {
      if ( v18 >= dword_63389C
        && ((a1 = 4092,
             v80 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((v18 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v80 == 1)
         || v80 == 11)
        && (v85 = *(_DWORD *)(v73 + 116), (v86 = *(_DWORD *)(v85 + 324)) != 0)
        && v85 != PsInitialSystemProcess )
      {
        v81 = *(_DWORD *)(v86 + 8);
      }
      else
      {
        v81 = -1;
      }
      *(_DWORD *)(v27 + 20) = v81;
      *(_DWORD *)(v27 + 16) = v18 & 0x7FFFFFFC;
      goto LABEL_204;
    }
LABEL_210:
    v83 = (unsigned __int8 *)(v73 + 81);
    do
      v84 = __ldrex(v83);
    while ( __strex(v84 | 0x80, v83) );
LABEL_204:
    v82 = *(_WORD *)(v73 + 310) + 1;
    *(_WORD *)(v73 + 310) = v82;
    if ( !v82 && *(_DWORD *)(v73 + 100) != v73 + 100 )
      KiCheckForKernelApcDelivery(a1);
    v1 = 0;
    goto LABEL_58;
  }
  v27 = 0;
  do
LABEL_58:
    v28 = __ldrex((unsigned __int8 *)v18);
  while ( __strex(v28 | 1, (unsigned __int8 *)v18) );
  __dmb(0xBu);
  if ( (v28 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 508), v27, v2 + 508);
  if ( v27 )
    *(_BYTE *)(v27 + 14) |= 1u;
LABEL_36:
  v20 = *(_QWORD *)(v2 + 48);
  v10 = 0;
  if ( (_DWORD)v20 != HIDWORD(v20) )
  {
    v21 = *(_DWORD *)v20;
    *(_DWORD *)v20 = **(_DWORD **)v20;
    if ( v21 == *(_DWORD *)(v2 + 52) )
      *(_DWORD *)(v2 + 52) = *(_DWORD *)(v2 + 48);
    v10 = v21 - 32;
  }
  if ( *(_DWORD *)(v2 + 224) == 1 )
  {
    __pld((void *)v18);
    v24 = *(_DWORD *)v18;
    if ( (*(_DWORD *)v18 & 0xFFFFFFF0) > 0x10 )
      v25 = v24 - 16;
    else
      v25 = 0;
    if ( (v24 & 2) != 0 )
      goto LABEL_66;
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)v18);
    while ( v26 == v24 && __strex(v25, (unsigned int *)v18) );
    if ( v26 != v24 )
LABEL_66:
      ExfReleasePushLock((_DWORD *)v18, v24);
    KeAbPostRelease(v18);
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v18);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v18 = 0;
    }
    KfLowerIrql(v1);
  }
  if ( v10 )
  {
    *(_DWORD *)(v10 + 4) = 0;
    __dmb(0xBu);
    *(_DWORD *)(v10 + 8) = 72;
    *(_WORD *)(v10 + 54) = 0;
    *(_DWORD *)(v10 + 32) = 0;
    *(_DWORD *)(v10 + 44) = 1;
    __dmb(0xBu);
    v22 = (unsigned int *)(v2 + 156);
    do
      v23 = __ldrex(v22);
    while ( __strex(v23 - 1, v22) );
    __dmb(0xBu);
LABEL_29:
    if ( *(_DWORD *)(v2 + 4) != *(_DWORD *)v10 )
      KeBugCheckEx(285, 7, v10);
    return v10;
  }
  return 0;
}
