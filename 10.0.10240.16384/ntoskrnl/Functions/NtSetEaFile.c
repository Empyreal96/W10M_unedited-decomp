// NtSetEaFile 
 
int __fastcall NtSetEaFile(int a1, int *a2, unsigned int a3, unsigned int a4)
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
  int *v27; // r3
  int v28; // r0
  int v29; // r8
  int v30; // r3
  int v31; // r8
  int v32; // r3
  int v33; // r0
  int *v34; // r9
  int v35; // r8
  int v36; // r0
  int v37; // r9
  int v38; // r0
  _BYTE v40[2]; // [sp+10h] [bp-68h] BYREF
  char v41; // [sp+12h] [bp-66h]
  int v42; // [sp+14h] [bp-64h]
  int v43; // [sp+18h] [bp-60h]
  unsigned __int8 *v44; // [sp+1Ch] [bp-5Ch]
  int v45; // [sp+20h] [bp-58h]
  int *v46; // [sp+24h] [bp-54h]
  int v47; // [sp+28h] [bp-50h] BYREF
  int v48; // [sp+2Ch] [bp-4Ch]
  int v49; // [sp+30h] [bp-48h]
  int v50; // [sp+34h] [bp-44h]
  unsigned __int8 *v51; // [sp+3Ch] [bp-3Ch]
  _DWORD v52[2]; // [sp+40h] [bp-38h] BYREF
  int v53; // [sp+48h] [bp-30h]
  _DWORD _50[16]; // [sp+50h] [bp-28h] BYREF

  _50[15] = a4;
  v48 = a3;
  _50[14] = a3;
  v46 = a2;
  _50[13] = a2;
  _50[12] = a1;
  v45 = 0;
  v50 = 0;
  v44 = (unsigned __int8 *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v51 = v44;
  v7 = (char)v44[346];
  v42 = v7;
  v40[1] = v7;
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
  v10 = ObReferenceObjectByHandle(a1, 16, (int)IoFileObjectType, v7, (int)v52, 0);
  v11 = (_DWORD *)v52[0];
  if ( v10 >= 0 )
  {
    v12 = *(_DWORD **)(v52[0] + 124);
    if ( v12 )
    {
      if ( (*v12 & 4) != 0 )
      {
        v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v47 = 0;
        v14 = PsReferencePrimaryToken(v13);
        SeQueryInformationToken(v14, 29, &v47);
        ObfDereferenceObject(v14);
        if ( v47 )
        {
          ObfDereferenceObject((int)v11);
          v10 = -1073739504;
        }
      }
    }
  }
  v53 = v10;
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
    v21 = IopAcquireFileObjectLock((int)v11, v42, (v11[11] & 4) != 0, v40);
    v53 = v21;
    if ( !v40[0] )
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
  v45 = v23;
  v50 = v23;
  if ( !v23 )
  {
    v15 = -1073741670;
    goto LABEL_37;
  }
  KeInitializeEvent(v23, 1, 0);
  v22 = 0;
LABEL_39:
  v40[0] = v22;
  v43 = v22;
  if ( (v11[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v11 + 23));
  v49 = IoGetRelatedDeviceObject(v11);
  v52[1] = v49;
  v25 = pIoAllocateIrp(v49, *(char *)(v49 + 48), 0, _50[11]);
  v26 = (_DWORD *)v25;
  v51 = (unsigned __int8 *)v25;
  if ( !v25 )
  {
    if ( (v11[11] & 2) == 0 )
      ExFreePoolWithTag(v45);
    IopAllocateIrpCleanup((int)v11, 0);
    return -1073741670;
  }
  *(_DWORD *)(v25 + 100) = v11;
  *(_DWORD *)(v25 + 80) = v44;
  *(_BYTE *)(v25 + 32) = v42;
  if ( v22 )
  {
    *(_DWORD *)(v25 + 44) = 0;
    v27 = v46;
  }
  else
  {
    *(_DWORD *)(v25 + 44) = v45;
    v27 = _50;
    *(_DWORD *)(v25 + 8) = 4;
  }
  *(_DWORD *)(v25 + 40) = v27;
  *(_DWORD *)(v25 + 48) = 0;
  v28 = *(_DWORD *)(v25 + 96) - 40;
  v44 = (unsigned __int8 *)v28;
  v47 = v28;
  *(_BYTE *)v28 = 8;
  *(_DWORD *)(v28 + 28) = v11;
  v29 = v49;
  v30 = *(_DWORD *)(v49 + 28);
  if ( (v30 & 4) != 0 )
  {
    if ( a4 )
    {
      v41 = 0;
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v32 = 40;
        else
          v32 = 32;
        v31 = ExAllocatePoolWithTagPriority(512, a4, 538996553, v32);
        if ( !v31 )
          RtlRaiseStatus(-1073741670);
      }
      else
      {
        v31 = ExAllocatePoolWithQuotaTag(0x200u, a4, 538996553);
      }
      v26[3] = v31;
      memmove(v31, v48, a4);
      v33 = IoCheckEaBufferValidity(v31, a4);
      v53 = v33;
      if ( v33 < 0 )
      {
        v41 = 1;
        v34 = v46;
        *v46 = v33;
        v34[1] = v48;
        RtlRaiseStatus(v33);
      }
      v35 = v43;
      v28 = (int)v44;
      v26[2] |= 0x30u;
      goto LABEL_68;
    }
    v26[3] = 0;
  }
  else if ( (v30 & 0x10) != 0 )
  {
    if ( a4 )
    {
      v36 = IoAllocateMdl(v48, a4, 0, 1, (int)v26);
      if ( !v36 )
        RtlRaiseStatus(-1073741670);
      sub_564C48(v36, v42, 0, v29, *v44);
      v35 = v43;
      v28 = (int)v44;
      goto LABEL_68;
    }
  }
  else
  {
    v26[15] = v48;
  }
  v35 = v43;
LABEL_68:
  *(_DWORD *)(v28 + 8) = a4;
  v37 = v42;
  v38 = IopSynchronousServiceTail(v49, (int)v26, v11, 0, v42, v35, 2);
  v15 = v38;
  if ( !v35 )
    v15 = IopSynchronousApiServiceTail(v38, v45, (int)v26, v37, _50, v46);
  return v15;
}
