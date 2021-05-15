// IopSetEaOrQuotaInformationFile 
 
int __fastcall IopSetEaOrQuotaInformationFile(int a1, int *a2, unsigned int a3, unsigned int a4)
{
  int v7; // r0
  int *v8; // r2
  unsigned int v9; // r3
  int v10; // r8
  _DWORD *v11; // r5
  _DWORD *v12; // r3
  int v13; // r0
  int v14; // r4
  int v15; // r6
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r1
  __int16 v20; // r3
  int v21; // r0
  int v22; // r8
  int v23; // r0
  int v24; // r3
  int v25; // r0
  _DWORD *v26; // r4
  int v27; // r0
  int v28; // r3
  int v29; // r8
  int v30; // r3
  int v31; // r0
  int *v32; // r9
  int v33; // r8
  int v34; // r0
  int v35; // r9
  int v36; // r0
  _BYTE v38[2]; // [sp+10h] [bp-68h] BYREF
  char v39; // [sp+12h] [bp-66h]
  int v40; // [sp+14h] [bp-64h]
  int v41; // [sp+18h] [bp-60h]
  int v42; // [sp+1Ch] [bp-5Ch]
  unsigned int v43; // [sp+20h] [bp-58h]
  int v44; // [sp+24h] [bp-54h] BYREF
  int *v45; // [sp+28h] [bp-50h]
  int v46; // [sp+2Ch] [bp-4Ch] BYREF
  int v47; // [sp+30h] [bp-48h]
  int v48; // [sp+38h] [bp-40h]
  unsigned int v49; // [sp+3Ch] [bp-3Ch]
  _DWORD v50[2]; // [sp+40h] [bp-38h] BYREF
  int v51; // [sp+48h] [bp-30h]
  _DWORD _50[16]; // [sp+50h] [bp-28h] BYREF

  _50[15] = a4;
  v44 = a3;
  _50[14] = a3;
  v45 = a2;
  _50[13] = a2;
  _50[12] = a1;
  v41 = 0;
  v48 = 0;
  v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v49 = v43;
  v7 = *(char *)(v43 + 0x15A);
  v40 = v7;
  v38[1] = v7;
  if ( v7 )
  {
    v8 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v8 = (int *)MmUserProbeAddress;
    *v8 = *v8;
    if ( a4 )
    {
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v7);
      v9 = a3 + a4;
      if ( a3 + a4 > MmUserProbeAddress || v9 < a3 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  v10 = ObReferenceObjectByHandle(a1, 2, (int)IoFileObjectType, v7, (int)v50, 0);
  v11 = (_DWORD *)v50[0];
  if ( v10 >= 0 )
  {
    v12 = *(_DWORD **)(v50[0] + 124);
    if ( v12 )
    {
      if ( (*v12 & 4) != 0 )
      {
        v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v46 = 0;
        v14 = PsReferencePrimaryToken(v13);
        SeQueryInformationToken(v14, 29, &v46);
        ObfDereferenceObject(v14);
        if ( v46 )
        {
          ObfDereferenceObject((int)v11);
          v10 = -1073739504;
        }
      }
    }
  }
  v51 = v10;
  if ( v10 < 0 )
    return v10;
  if ( (v11[11] & 2) != 0 )
  {
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v16 + 308);
    __dmb(0xBu);
    v17 = v11 + 17;
    do
      v18 = __ldrex(v17);
    while ( __strex(1u, v17) );
    __dmb(0xBu);
    if ( !v18 )
    {
      ObfReferenceObject((int)v11);
LABEL_28:
      v22 = 1;
      goto LABEL_39;
    }
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x134) + 1;
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(1);
    v21 = IopAcquireFileObjectLock((int)v11, v40, (v11[11] & 4) != 0, v38);
    v51 = v21;
    if ( !v38[0] )
      goto LABEL_28;
    v15 = v21;
LABEL_37:
    ObfDereferenceObject((int)v11);
    return v15;
  }
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v24 = 40;
    else
      v24 = 32;
    v23 = ExAllocatePoolWithTagPriority(512, 0x10u, 538996553, v24);
  }
  else
  {
    v23 = ExAllocatePoolWithTag(512, 16, 538996553);
  }
  v41 = v23;
  v48 = v23;
  if ( !v23 )
  {
    v15 = -1073741670;
    goto LABEL_37;
  }
  KeInitializeEvent(v23, 1, 0);
  v22 = 0;
LABEL_39:
  v38[0] = v22;
  v42 = v22;
  if ( (v11[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v11 + 23));
  v47 = IoGetRelatedDeviceObject(v11);
  v50[1] = v47;
  v25 = pIoAllocateIrp(v47, *(char *)(v47 + 48), 0, _50[11]);
  v26 = (_DWORD *)v25;
  v49 = v25;
  if ( !v25 )
  {
    if ( (v11[11] & 2) == 0 )
      ExFreePoolWithTag(v41);
    IopAllocateIrpCleanup((int)v11, 0);
    return -1073741670;
  }
  *(_DWORD *)(v25 + 100) = v11;
  *(_DWORD *)(v25 + 80) = v43;
  *(_BYTE *)(v25 + 32) = v40;
  if ( v22 )
  {
    *(_DWORD *)(v25 + 44) = 0;
    *(_DWORD *)(v25 + 40) = v45;
    *(_BYTE *)(v25 + 39) |= 2u;
  }
  else
  {
    *(_DWORD *)(v25 + 44) = v41;
    *(_DWORD *)(v25 + 40) = _50;
    *(_DWORD *)(v25 + 8) = 4;
  }
  *(_DWORD *)(v25 + 48) = 0;
  v27 = *(_DWORD *)(v25 + 96) - 40;
  v43 = v27;
  v46 = v27;
  *(_BYTE *)v27 = 26;
  *(_DWORD *)(v27 + 28) = v11;
  v28 = *(_DWORD *)(v47 + 28);
  if ( (v28 & 4) != 0 )
  {
    if ( a4 )
    {
      v39 = 0;
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v30 = 40;
        else
          v30 = 32;
        v29 = ExAllocatePoolWithTagPriority(512, a4, 538996553, v30);
        if ( !v29 )
          RtlRaiseStatus(-1073741670);
      }
      else
      {
        v29 = ExAllocatePoolWithQuotaTag(0x200u, a4, 538996553);
      }
      v26[3] = v29;
      memmove(v29, v44, a4);
      v31 = IoCheckQuotaBufferValidity(v29, a4, &v44);
      v51 = v31;
      if ( v31 < 0 )
      {
        v39 = 1;
        v32 = v45;
        *v45 = v31;
        v32[1] = v44;
        RtlRaiseStatus(v31);
      }
      v33 = v42;
      v27 = v43;
      v26[2] |= 0x30u;
      goto LABEL_68;
    }
    v26[3] = 0;
  }
  else if ( (v28 & 0x10) != 0 )
  {
    if ( a4 )
    {
      v34 = IoAllocateMdl(v44, a4, 0, 1, (int)v26);
      if ( !v34 )
        RtlRaiseStatus(-1073741670);
      sub_45D8F0(v34, v40, 0);
      v33 = v42;
      v27 = v43;
      goto LABEL_68;
    }
    goto LABEL_67;
  }
  v26[15] = v44;
LABEL_67:
  v33 = v42;
LABEL_68:
  *(_DWORD *)(v27 + 8) = a4;
  v35 = v40;
  v36 = IopSynchronousServiceTail(v47, (int)v26, v11, 0, v40, v33, 2);
  v15 = v36;
  if ( !v33 )
    v15 = IopSynchronousApiServiceTail(v36, v41, (int)v26, v35, _50, v45);
  return v15;
}
