// NtAllocateUserPhysicalPages 
 
int __fastcall NtAllocateUserPhysicalPages(int a1, int *a2, int a3)
{
  unsigned int v3; // r8
  int *v4; // lr
  char v5; // r5
  int v6; // r10
  int v7; // r4
  int v8; // r2
  int v9; // r9
  int v10; // r6
  _DWORD *v11; // r8
  _BYTE *v12; // r4
  int **v13; // r6
  int *v14; // r4
  int v15; // r6
  int *v16; // r0
  int v17; // r6
  int v18; // r2
  __int16 *v19; // lr
  unsigned __int64 v20; // kr00_8
  int v21; // r1
  unsigned int v22; // r0
  unsigned int *v23; // lr
  int v24; // r8
  unsigned int v25; // t1
  int v26; // r4
  unsigned int *v27; // r2
  unsigned int v28; // r0
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r4
  _DWORD *v32; // r3
  int v33; // r4
  _DWORD *i; // r3
  _DWORD *v35; // r4
  unsigned int *v36; // r2
  unsigned int v37; // r4
  int v39; // [sp+20h] [bp-A8h]
  _DWORD *v40; // [sp+20h] [bp-A8h]
  int v41; // [sp+24h] [bp-A4h]
  int v43; // [sp+2Ch] [bp-9Ch]
  unsigned int v44; // [sp+38h] [bp-90h]
  int **v45; // [sp+3Ch] [bp-8Ch]
  unsigned int v46; // [sp+40h] [bp-88h]
  unsigned int *v47; // [sp+40h] [bp-88h]
  __int16 *v48; // [sp+44h] [bp-84h]
  unsigned int v49; // [sp+48h] [bp-80h]
  int v50; // [sp+48h] [bp-80h]
  int *v51; // [sp+4Ch] [bp-7Ch]
  _DWORD *v52; // [sp+4Ch] [bp-7Ch]
  int v53; // [sp+54h] [bp-74h]
  _DWORD *v54; // [sp+58h] [bp-70h]
  _DWORD *v55; // [sp+60h] [bp-68h] BYREF
  unsigned int v56; // [sp+64h] [bp-64h]
  int v57; // [sp+68h] [bp-60h]
  _DWORD *v58; // [sp+6Ch] [bp-5Ch]
  int v59; // [sp+70h] [bp-58h]
  int v60; // [sp+74h] [bp-54h]
  unsigned int v61; // [sp+78h] [bp-50h]
  int v62; // [sp+7Ch] [bp-4Ch]
  int *v63; // [sp+80h] [bp-48h]
  unsigned int v64; // [sp+84h] [bp-44h]
  unsigned int v65; // [sp+88h] [bp-40h]
  int v66; // [sp+8Ch] [bp-3Ch]
  _BYTE v67[56]; // [sp+90h] [bp-38h] BYREF

  v3 = a3;
  v53 = a3;
  v4 = a2;
  v51 = a2;
  v59 = a1;
  v60 = a3;
  v5 = 0;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v41 = v6;
  v62 = v6;
  v7 = *(_DWORD *)(v6 + 0x74);
  v8 = *(char *)(v6 + 0x15A);
  v39 = v8;
  if ( *(_BYTE *)(v6 + 0x15A) )
  {
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      a2 = (int *)MmUserProbeAddress;
    *a2 = *a2;
    v56 = *v4;
    v9 = v56;
    if ( !v56 )
      return 0;
    if ( v56 > 0x3FFFFFFF )
      return -1073741584;
    ProbeForWrite(v3, 4 * v56, 4);
    v8 = v39;
  }
  else
  {
    v9 = *a2;
    v56 = *a2;
  }
  if ( a1 == -1 )
  {
    v11 = (_DWORD *)v7;
    v55 = (_DWORD *)v7;
  }
  else
  {
    v10 = ObReferenceObjectByHandleWithTag(a1, 8, PsProcessType, v8, 1750101325, (int *)&v55, 0);
    if ( v10 < 0 )
      return v10;
    v11 = v55;
    v8 = v39;
  }
  v58 = v11;
  if ( !SeSinglePrivilegeCheck(SeLockMemoryPrivilege, dword_922B7C, v8, (int)&SeLockMemoryPrivilege) )
  {
    if ( a1 != -1 )
      ObfDereferenceObjectWithTag((int)v11);
    return -1073741727;
  }
  if ( (_DWORD *)v7 != v11 )
  {
    KiStackAttachProcess((int)v11, 0, (int)v67);
    v5 = 4;
  }
  v43 = 0;
  v12 = 0;
  v13 = (int **)v11[82];
  v45 = v13;
  if ( v13 )
  {
    if ( *v13 )
      v5 |= 1u;
LABEL_25:
    if ( (v5 & 1) != 0 )
    {
      LOCK_ADDRESS_SPACE_SHARED(v6, (int)v11);
    }
    else
    {
      v5 |= 2u;
      LOCK_ADDRESS_SPACE(v6, (int)v11);
    }
    if ( (v11[48] & 0x20) != 0 )
    {
      if ( v12 )
        MiFreeAweInfo((unsigned int)v12);
      v10 = -1073741558;
      goto LABEL_78;
    }
    if ( v12 )
    {
      v13 = (int **)MiInsertAweInfo((int)v11, (int)v12);
      v45 = v13;
    }
    if ( !MiChargeProcessPhysicalPages((int)v11, v9) || (v5 |= 0x10u, !MiChargeProcessCommitment(v11, v9)) )
    {
      v10 = -1073741523;
      goto LABEL_78;
    }
    v5 |= 8u;
    v63 = *v13;
    v14 = v63;
    if ( !v63 )
    {
      v15 = dword_633850 + 1;
      v44 = (((dword_633850 + 1) & 0x1F) != 0) + ((unsigned int)(dword_633850 + 1) >> 5) + 2;
      v16 = (int *)ExAllocatePoolWithTag(512, 4 * v44, 1281646934);
      v14 = v16;
      v63 = v16;
      if ( !v16 )
        goto LABEL_22;
      *v16 = v15;
      v16[1] = (int)(v16 + 2);
      RtlClearAllBits((int)v16);
      v10 = PsChargeProcessNonPagedPoolQuota((int)v11, 4 * v44);
      if ( v10 < 0 )
      {
        ExFreePoolWithTag((unsigned int)v14);
        goto LABEL_78;
      }
      *v45 = v14;
    }
    v17 = *v14;
    if ( (v5 & 1) != 0 )
    {
      UNLOCK_ADDRESS_SPACE_SHARED(v6, (int)v11);
      v5 &= 0xFEu;
    }
    else
    {
      UNLOCK_ADDRESS_SPACE(v6, (int)v11);
      v5 &= 0xFDu;
    }
    v57 = *(unsigned __int16 *)(*((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)(v6 + 364)) + 590) + 266);
    v40 = 0;
    v19 = MiGetThreadPartition();
    v48 = v19;
    v20 = (unsigned __int64)(unsigned int)(v17 - 1) << 12;
    v64 = HIDWORD(v20);
    v61 = v20;
    v10 = 0;
    v65 = 1048574;
    while ( 1 )
    {
      v21 = 0;
      v54 = 0;
      v22 = v9 - v43;
      v49 = v9 - v43;
      if ( v9 - v43 > v65 )
      {
        v22 = v65;
        v49 = v65;
      }
      if ( v22 >= 0x400 && (v5 & 0x20) == 0 )
      {
        v46 = v22 & 0xFFFFFC00;
        v21 = MiAllocatePagesForMdl(
                v19,
                0i64,
                __SPAIR64__(v64, v61),
                0x400000i64,
                (v22 & 0xFFFFFC00) << 12,
                v18,
                v57,
                -2147483552);
        v54 = (_DWORD *)v21;
        v19 = v48;
        if ( v21 )
        {
          v22 = v46;
        }
        else
        {
          v5 |= 0x20u;
          v22 = v49;
        }
      }
      if ( !v21 )
      {
        v21 = MiAllocatePagesForMdl(v19, 0i64, __SPAIR64__(v64, v61), 0i64, v22 << 12, 1, v57, 0x80000000);
        v54 = (_DWORD *)v21;
        if ( !v21 )
          break;
      }
      v50 = *(_DWORD *)(v21 + 20) >> 12;
      v47 = (unsigned int *)(v21 + 28);
      v66 = v14[1];
      LOCK_ADDRESS_SPACE_SHARED(v6, (int)v11);
      if ( (v11[48] & 0x20) != 0 )
      {
        UNLOCK_ADDRESS_SPACE_SHARED(v6, (int)v11);
        MiFreePagesFromMdl(v48, (int)v54, 1);
        ExFreePoolWithTag((unsigned int)v54);
        v10 = -1073741558;
        v31 = v43;
        goto LABEL_67;
      }
      v23 = v47;
      v24 = v66;
      do
      {
        v25 = *v23++;
        v26 = 1 << (v25 & 0x1F);
        v27 = (unsigned int *)(v24 + 4 * (v25 >> 5));
        do
          v28 = __ldrex(v27);
        while ( __strex(v28 | v26, v27) );
      }
      while ( v23 != &v47[v50] );
      v11 = v58;
      v6 = v41;
      UNLOCK_ADDRESS_SPACE_SHARED(v41, (int)v58);
      *v54 = v40;
      v40 = v54;
      v29 = (unsigned int *)(v48 + 2062);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 + v50, v29) );
      v31 = v43 + v50;
      v43 = v31;
      if ( v31 == v9 )
        goto LABEL_67;
      v14 = v63;
      v18 = 1;
      v19 = v48;
    }
    v31 = v43;
    if ( !v43 )
      v10 = -1073741670;
LABEL_67:
    if ( (v5 & 4) != 0 )
    {
      KiUnstackDetachProcess((unsigned int)v67, 0);
      v5 &= 0xFBu;
    }
    if ( v10 >= 0 )
      *v51 = v31;
    v32 = v40;
    v52 = v40;
    while ( v32 )
    {
      v33 = v32[5] >> 12;
      memmove(v53, (int)(v32 + 7), 4 * v33);
      v53 += 4 * v33;
      v60 = v53;
      v32 = (_DWORD *)*v52;
      v52 = (_DWORD *)*v52;
    }
    for ( i = v40; i; i = v35 )
    {
      v35 = (_DWORD *)*i;
      ExFreePoolWithTag((unsigned int)i);
    }
    v9 -= v43;
    goto LABEL_78;
  }
  v12 = MiAllocateAweInfo();
  if ( v12 )
    goto LABEL_25;
LABEL_22:
  v10 = -1073741670;
LABEL_78:
  if ( v9 )
  {
    if ( (v5 & 8) != 0 && (v5 & 3) == 0 )
    {
      v5 |= 1u;
      LOCK_ADDRESS_SPACE_SHARED(v41, (int)v11);
    }
    if ( (v5 & 8) != 0 )
      MiReturnProcessCommitment((int)v11, v9);
  }
  if ( (v5 & 1) != 0 )
  {
    UNLOCK_ADDRESS_SPACE_SHARED(v41, (int)v11);
  }
  else if ( (v5 & 2) != 0 )
  {
    UNLOCK_ADDRESS_SPACE(v41, (int)v11);
  }
  if ( v9 && (v5 & 0x10) != 0 )
  {
    v36 = v11 + 162;
    do
      v37 = __ldrex(v36);
    while ( __strex(v37 - v9, v36) );
  }
  if ( (v5 & 4) != 0 )
    KiUnstackDetachProcess((unsigned int)v67, 0);
  if ( a1 != -1 )
    ObfDereferenceObjectWithTag((int)v11);
  return v10;
}
