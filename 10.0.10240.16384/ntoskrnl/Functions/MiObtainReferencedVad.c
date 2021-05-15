// MiObtainReferencedVad 
 
int __fastcall MiObtainReferencedVad(unsigned int a1, int *a2)
{
  unsigned int v3; // r9
  int v4; // lr
  int v5; // r0
  unsigned int v6; // r10
  unsigned int v7; // r6
  int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r4
  int v15; // r3
  int v16; // r3
  unsigned int v17; // r2
  int v18; // r2
  _DWORD *v19; // r6
  unsigned int v20; // r8
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r1
  int v24; // r0
  int v25; // r3
  unsigned __int8 *v26; // r10
  int v27; // r5
  unsigned int v28; // r7
  int v29; // r2
  int v30; // r3
  unsigned int v31; // r2
  unsigned int v32; // r1
  int v33; // r3
  unsigned int v34; // r1
  unsigned int v35; // r4
  int v36; // r3
  unsigned int v37; // r2
  __int16 v38; // r3
  int v39; // r3
  int v40; // r3
  int v41; // r0
  __int16 v42; // r3
  unsigned __int8 *v43; // r4
  char v44; // r5
  unsigned int v45; // r0
  unsigned __int8 *v46; // r3
  unsigned int v47; // r2
  unsigned __int8 *v48; // r4
  char v49; // r5
  unsigned int v50; // r0
  char v51; // r3
  unsigned __int8 *v52; // r3
  unsigned int v53; // r2

  *a2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(_DWORD *)(v3 + 0x74);
  --*(_WORD *)(v3 + 310);
  --*(_WORD *)(v3 + 310);
  v5 = (int)&KiAbEnabled;
  v6 = v4 + 252;
  if ( !KiAbEnabled || (v6 & 0x7FFFFFFC) == 0 )
  {
    v14 = 0;
    goto LABEL_14;
  }
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (__get_CPSR() & 0x80) != 0 )
    return sub_5342F0();
  __disable_irq();
  v9 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  __enable_irq();
  if ( (v9 & 0x10001) != 0 )
  {
    KeGetCurrentIrql(&KiAbEnabled);
    KeBugCheckEx(402, v7, v4 + 252);
  }
  --*(_WORD *)(v7 + 310);
  if ( !*(_BYTE *)(v7 + 484) )
  {
    if ( !*(_BYTE *)(v7 + 810) )
    {
      v14 = 0;
      if ( (dword_682604 & 0x200) != 0 )
        v5 = EtwTraceAutoBoostEntryExhaustion(v7, v4 + 252);
      goto LABEL_82;
    }
    v43 = (unsigned __int8 *)(v7 + 810);
    v44 = *(_BYTE *)(v7 + 810);
    __dmb(0xBu);
    do
      v45 = __ldrex(v43);
    while ( __strex(v45 & ~v44, v43) );
    __dmb(0xBu);
    *(_BYTE *)(v7 + 484) |= v44;
  }
  v10 = *(unsigned __int8 *)(v7 + 484);
  v5 = 1;
  v11 = __clz(__rbit(v10));
  v12 = v10 & ~(1 << v11);
  v13 = v7 + 48 * v11;
  v14 = v13 + 488;
  *(_BYTE *)(v7 + 484) = v12;
  if ( v13 == -488 )
  {
LABEL_82:
    v46 = (unsigned __int8 *)(v7 + 81);
    do
      v47 = __ldrex(v46);
    while ( __strex(v47 | 0x80, v46) );
    goto LABEL_13;
  }
  if ( v6 >= dword_63389C
    && ((v15 = *((unsigned __int8 *)&MiState[2423]
               + ((int)(((v6 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v15 == 1)
     || v15 == 11) )
  {
    v5 = MmGetSessionIdEx(*(_DWORD *)(v7 + 116));
  }
  else
  {
    v5 = -1;
  }
  *(_DWORD *)(v14 + 20) = v5;
  *(_DWORD *)(v14 + 16) = v6 & 0x7FFFFFFC;
LABEL_13:
  v16 = (__int16)(*(_WORD *)(v7 + 310) + 1);
  *(_WORD *)(v7 + 310) = v16;
  if ( !v16 && *(_DWORD *)(v7 + 100) != v7 + 100 )
    KiCheckForKernelApcDelivery(v5);
  do
LABEL_14:
    v17 = __ldrex((unsigned int *)v6);
  while ( !v17 && __strex(0x11u, (unsigned int *)v6) );
  __dmb(0xBu);
  if ( v17 )
    ExfAcquirePushLockSharedEx(v6, v14, v6);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  *(_BYTE *)(v3 + 968) |= 2u;
  if ( (*(_DWORD *)(v4 + 192) & 0x20) != 0 )
  {
    v40 = -1073741558;
    goto LABEL_69;
  }
  v18 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v19 = *(_DWORD **)(v18 + 640);
  if ( !v19 )
    goto LABEL_64;
  v20 = a1 >> 12;
  if ( v20 >= v19[3] && v20 <= v19[4] )
    goto LABEL_24;
  v19 = *(_DWORD **)(v18 + 636);
  if ( !v19 )
  {
LABEL_64:
    v40 = -1073741664;
LABEL_69:
    *a2 = v40;
    v41 = UNLOCK_ADDRESS_SPACE_SHARED(v3, v4, a2);
    v42 = *(_WORD *)(v3 + 310) + 1;
    *(_WORD *)(v3 + 310) = v42;
    if ( !v42 && *(_DWORD *)(v3 + 100) != v3 + 100 )
      KiCheckForKernelApcDelivery(v41);
    return 0;
  }
  while ( 1 )
  {
    if ( v20 > v19[4] )
    {
      v39 = 1;
    }
    else if ( v20 >= v19[3] )
    {
      v39 = 0;
    }
    else
    {
      v39 = -1;
    }
    if ( v39 < 0 )
    {
      v19 = (_DWORD *)*v19;
      goto LABEL_63;
    }
    if ( v39 <= 0 )
      break;
    v19 = (_DWORD *)v19[1];
LABEL_63:
    if ( !v19 )
      goto LABEL_64;
  }
  *(_DWORD *)(v18 + 640) = v19;
LABEL_24:
  v21 = v19 + 5;
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 + 1, v21) );
  __dmb(0xBu);
  *(_BYTE *)(v3 + 968) &= 0xFDu;
  __dmb(0xBu);
  do
    v23 = __ldrex((unsigned int *)v6);
  while ( v23 == 17 && __strex(0, (unsigned int *)v6) );
  if ( v23 != 17 )
    ExfReleasePushLockShared(v6, v23);
  v24 = KeAbPostRelease(v6);
  v25 = (__int16)(*(_WORD *)(v3 + 310) + 1);
  *(_WORD *)(v3 + 310) = v25;
  if ( !v25 && *(_DWORD *)(v3 + 100) != v3 + 100 )
    v24 = KiCheckForKernelApcDelivery(v24);
  --*(_WORD *)(v3 + 310);
  v26 = (unsigned __int8 *)(v19 + 6);
  if ( KiAbEnabled && (v27 = (unsigned int)v26 & 0x7FFFFFFC, ((unsigned int)v26 & 0x7FFFFFFC) != 0) )
  {
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v29 = 0;
    }
    else
    {
      __disable_irq();
      v29 = 1;
    }
    v30 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v29 )
      __enable_irq();
    if ( (v30 & 0x10001) != 0 )
    {
      KeGetCurrentIrql(v24);
      KeBugCheckEx(402, v28, v19 + 6);
    }
    --*(_WORD *)(v28 + 310);
    if ( *(_BYTE *)(v28 + 484) )
    {
LABEL_40:
      v31 = *(unsigned __int8 *)(v28 + 484);
      v24 = 1;
      v32 = __clz(__rbit(v31));
      v33 = v31 & ~(1 << v32);
      v34 = v28 + 48 * v32;
      v35 = v34 + 488;
      *(_BYTE *)(v28 + 484) = v33;
      if ( v34 != -488 )
      {
        if ( MmIsSessionAddress((unsigned int)(v19 + 6)) )
          v24 = MmGetSessionIdEx(*(_DWORD *)(v28 + 116));
        else
          v24 = -1;
        *(_DWORD *)(v35 + 20) = v24;
        *(_DWORD *)(v35 + 16) = v27;
        goto LABEL_44;
      }
    }
    else
    {
      if ( *(_BYTE *)(v28 + 810) )
      {
        v48 = (unsigned __int8 *)(v28 + 810);
        v49 = *(_BYTE *)(v28 + 810);
        __dmb(0xBu);
        do
          v50 = __ldrex(v48);
        while ( __strex(v50 & ~v49, v48) );
        __dmb(0xBu);
        v51 = *(_BYTE *)(v28 + 484) | v49;
        v27 = (unsigned int)v26 & 0x7FFFFFFC;
        *(_BYTE *)(v28 + 484) = v51;
        goto LABEL_40;
      }
      v35 = 0;
      if ( (dword_682604 & 0x200) != 0 )
        v24 = EtwTraceAutoBoostEntryExhaustion(v28, v19 + 6);
    }
    v52 = (unsigned __int8 *)(v28 + 81);
    do
      v53 = __ldrex(v52);
    while ( __strex(v53 | 0x80, v52) );
LABEL_44:
    v36 = (__int16)(*(_WORD *)(v28 + 310) + 1);
    *(_WORD *)(v28 + 310) = v36;
    if ( !v36 && *(_DWORD *)(v28 + 100) != v28 + 100 )
      v24 = KiCheckForKernelApcDelivery(v24);
  }
  else
  {
    v35 = 0;
  }
  do
    v37 = __ldrex(v26);
  while ( __strex(v37 | 1, v26) );
  __dmb(0xBu);
  if ( (v37 & 1) != 0 )
    v24 = ExfAcquirePushLockExclusiveEx(v19 + 6, v35, v19 + 6);
  if ( v35 )
    *(_BYTE *)(v35 + 14) |= 1u;
  *(_BYTE *)(v3 + 968) |= 0x80u;
  v38 = *(_WORD *)(v3 + 310);
  *(_WORD *)(v3 + 310) = v38 + 1;
  if ( v38 == -1 && *(_DWORD *)(v3 + 100) != v3 + 100 )
    KiCheckForKernelApcDelivery(v24);
  if ( (int)v19[7] < 0 )
  {
    MiWaitForVadDeletion(v19);
    MiUnlockAndDereferenceVad((int)v19);
    *a2 = -1073741664;
    return 0;
  }
  if ( v20 < v19[3] || v20 > v19[4] )
  {
    MiUnlockAndDereferenceVad((int)v19);
    *a2 = -1073741664;
    return 0;
  }
  return (int)v19;
}
