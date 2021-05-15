// NtQueryVolumeInformationFile 
 
int __fastcall NtQueryVolumeInformationFile(int a1, _DWORD *a2, _DWORD *a3, unsigned int a4, unsigned int a5)
{
  int v7; // r0
  int v8; // r5
  _DWORD *v9; // r2
  int v10; // r8
  _DWORD *v11; // r6
  _DWORD *v12; // r3
  int v13; // r0
  int v14; // r4
  int v15; // r2
  int v16; // r0
  _DWORD *v17; // r4
  int v18; // r3
  _DWORD *v19; // r3
  unsigned int v20; // r2
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25; // r0
  int v26; // r10
  unsigned int v27; // r8
  _BYTE *v28; // r4
  int v29; // r3
  int v30; // r0
  int v31; // r8
  _DWORD *v32; // r3
  unsigned int *v33; // r2
  unsigned int v34; // r1
  int v35; // r0
  unsigned int v36; // r1
  __int16 v37; // r3
  int v38; // r4
  int v39; // r0
  int v40; // r3
  int v41; // r0
  int v42; // r4
  int v43; // r8
  int v44; // r0
  int v45; // r3
  unsigned int v46; // r1
  _DWORD *v47; // r9
  int v48; // lr
  int v49; // r8
  int v50; // r0
  char v52[3]; // [sp+11h] [bp-5Fh] BYREF
  unsigned int v53; // [sp+14h] [bp-5Ch]
  int v54; // [sp+18h] [bp-58h]
  int v55; // [sp+1Ch] [bp-54h]
  _DWORD *v56; // [sp+20h] [bp-50h]
  _DWORD *v57; // [sp+24h] [bp-4Ch] BYREF
  int v58; // [sp+2Ch] [bp-44h]
  int v59; // [sp+30h] [bp-40h]
  unsigned int v60; // [sp+34h] [bp-3Ch] BYREF
  _BYTE *v61; // [sp+38h] [bp-38h]
  unsigned int v62; // [sp+3Ch] [bp-34h]
  int v63; // [sp+40h] [bp-30h]
  int v64; // [sp+44h] [bp-2Ch]
  _DWORD _48[16]; // [sp+48h] [bp-28h] BYREF

  v53 = a4;
  _48[15] = a4;
  _48[14] = a3;
  v56 = a2;
  _48[13] = a2;
  _48[12] = a1;
  v54 = 0;
  v59 = 0;
  v62 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v60 = v62;
  v7 = *(char *)(v62 + 0x15A);
  v55 = v7;
  if ( v7 )
  {
    if ( a5 >= 0xE || !*((_BYTE *)IopQueryFsOperationLength + a5) )
      return -1073741821;
    if ( a4 < *((unsigned __int8 *)IopQueryFsOperationLength + a5) )
      return -1073741820;
    v9 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v9 = (_DWORD *)MmUserProbeAddress;
    *v9 = *v9;
    ProbeForWrite((unsigned int)a3, a4, *((unsigned __int8 *)IopQuerySetFsAlignmentRequirement + a5));
    LOBYTE(v7) = v55;
  }
  v10 = ObReferenceObjectByHandle(a1, IopQueryFsOperationAccess[a5], (int)IoFileObjectType, v7, (int)&v57, 0);
  v11 = v57;
  if ( v10 >= 0 )
  {
    v12 = (_DWORD *)v57[31];
    if ( v12 )
    {
      if ( (*v12 & 4) != 0 )
      {
        v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v60 = 0;
        v14 = PsReferencePrimaryToken(v13);
        SeQueryInformationToken(v14, 29, &v60);
        ObfDereferenceObject(v14);
        if ( v60 )
        {
          ObfDereferenceObject((int)v11);
          v10 = -1073739504;
        }
      }
    }
  }
  if ( v10 < 0 )
    return v10;
  v15 = v11[11];
  if ( (v15 & 0x800) != 0 )
  {
    if ( a5 != 4 )
    {
      v8 = -1073741808;
LABEL_76:
      ObfDereferenceObject((int)v11);
      return v8;
    }
  }
  else if ( a5 != 4 )
  {
    goto LABEL_30;
  }
  if ( (v15 & 0x800) != 0 || *(_DWORD *)(v11[1] + 44) != 20 )
  {
    v16 = 0;
    v17 = (_DWORD *)v11[1];
    if ( v17[9] )
      v16 = IopGetMountFlag(v11[1]);
    if ( v53 >= 8 )
    {
      *a3 = v17[11];
      v18 = v17[8];
      a3[1] = v18;
      if ( v16 )
        a3[1] = v18 | 0x20;
      v19 = v56;
      *v56 = 0;
      v19[1] = 8;
      v8 = 0;
      v58 = 0;
    }
    else
    {
      v8 = -1073741820;
    }
    goto LABEL_76;
  }
LABEL_30:
  if ( (v15 & 2) != 0 )
  {
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v20 + 308);
    __dmb(0xBu);
    v21 = v11 + 17;
    do
      v22 = __ldrex(v21);
    while ( __strex(1u, v21) );
    __dmb(0xBu);
    if ( v22 )
    {
      v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v24 = *(_WORD *)(v23 + 0x134) + 1;
      *(_WORD *)(v23 + 308) = v24;
      if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
        KiCheckForKernelApcDelivery(1);
      v25 = IopAcquireFileObjectLock(v11, v55, (v11[11] & 4) != 0, v52);
      if ( v52[0] )
      {
        v8 = v25;
        goto LABEL_76;
      }
    }
    else
    {
      ObfReferenceObject((int)v11);
    }
    v26 = 1;
  }
  else
  {
    v26 = 0;
  }
  v52[0] = v26;
  if ( a5 == 9 )
  {
    v61 = 0;
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v29 = 40;
      else
        v29 = 32;
      v27 = v53;
      v28 = (_BYTE *)ExAllocatePoolWithTagPriority(512, v53, 538996553, v29);
      if ( !v28 )
        RtlRaiseStatus(-1073741670);
    }
    else
    {
      v27 = v53;
      v28 = (_BYTE *)ExAllocatePoolWithQuotaTag(0x200u, v53, 538996553);
    }
    v61 = v28;
    memmove((int)v28, (int)a3, v27);
    v30 = IopGetDriverPathInformation((int)v11, (int)v28, v27);
    v31 = v30;
    v58 = v30;
    if ( v30 < 0 )
      RtlRaiseStatus(v30);
    *(_BYTE *)a3 = *v28;
    v32 = v56;
    *v56 = 0;
    v32[1] = 12;
    if ( v28 )
      ExFreePoolWithTag((unsigned int)v28);
    if ( (v11[11] & 2) != 0 )
    {
      __dmb(0xBu);
      v33 = v11 + 17;
      do
        v34 = __ldrex(v33);
      while ( __strex(0, v33) );
      __dmb(0xBu);
      if ( v11[16] )
        KeSetEvent((int)(v11 + 19), 0, 0);
      v35 = ObfDereferenceObject((int)v11);
      v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v37 = *(_WORD *)(v36 + 0x134) + 1;
      *(_WORD *)(v36 + 308) = v37;
      if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
        KiCheckForKernelApcDelivery(v35);
    }
    v8 = v31;
    goto LABEL_76;
  }
  if ( (v11[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v11 + 23));
  v38 = IoGetRelatedDeviceObject(v11);
  v60 = v38;
  v64 = v38;
  if ( (v11[11] & 2) == 0 )
  {
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v40 = 40;
      else
        v40 = 32;
      v39 = ExAllocatePoolWithTagPriority(512, 0x10u, 538996553, v40);
    }
    else
    {
      v39 = ExAllocatePoolWithTag(512, 16, 538996553);
    }
    v54 = v39;
    v59 = v39;
    if ( !v39 )
    {
      v8 = -1073741670;
      goto LABEL_76;
    }
    KeInitializeEvent(v39, 1, 0);
  }
  v41 = pIoAllocateIrp(v38, *(char *)(v38 + 48), 0, _48[11]);
  v42 = v41;
  v63 = v41;
  if ( v41 )
  {
    *(_DWORD *)(v41 + 100) = v11;
    *(_DWORD *)(v41 + 80) = v62;
    *(_BYTE *)(v41 + 32) = v55;
    if ( v26 )
    {
      *(_DWORD *)(v41 + 44) = 0;
      *(_DWORD *)(v41 + 40) = v56;
    }
    else
    {
      *(_DWORD *)(v41 + 44) = v54;
      *(_DWORD *)(v41 + 40) = _48;
      *(_DWORD *)(v41 + 8) = 4;
    }
    *(_DWORD *)(v41 + 48) = 0;
    v43 = *(_DWORD *)(v41 + 96) - 40;
    v62 = v43;
    *(_BYTE *)v43 = 10;
    *(_DWORD *)(v43 + 28) = v11;
    *(_DWORD *)(v41 + 60) = a3;
    *(_DWORD *)(v41 + 12) = 0;
    *(_DWORD *)(v41 + 4) = 0;
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v45 = 40;
      else
        v45 = 32;
      v44 = ExAllocatePoolWithTagPriority(512, v53, 538996553, v45);
      if ( !v44 )
        RtlRaiseStatus(-1073741670);
    }
    else
    {
      v44 = ExAllocatePoolWithQuotaTag(0x200u, v53, 538996553);
    }
    *(_DWORD *)(v42 + 12) = v44;
    v46 = v53;
    v47 = v56;
    v48 = v60;
    *(_DWORD *)(v42 + 8) |= 0x870u;
    *(_DWORD *)(v43 + 8) = v46;
    *(_DWORD *)(v43 + 12) = a5;
    v49 = v55;
    v50 = IopSynchronousServiceTail(v48, v42, v11, 1, v55, v26, 2);
    v8 = v50;
    if ( !v26 )
      v8 = IopSynchronousApiServiceTail(v50, v54, v42, v49, _48, v47);
  }
  else
  {
    if ( (v11[11] & 2) == 0 )
      ExFreePoolWithTag(v54);
    IopAllocateIrpCleanup(v11, 0);
    v8 = -1073741670;
  }
  return v8;
}
