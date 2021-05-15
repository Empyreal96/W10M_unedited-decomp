// NtSetVolumeInformationFile 
 
int __fastcall NtSetVolumeInformationFile(int a1, _DWORD *a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  unsigned int v6; // r10
  int v7; // lr
  int v8; // r6
  _DWORD *v9; // r2
  int v10; // r8
  _DWORD *v11; // r5
  _DWORD *v12; // r3
  int v13; // r0
  int v14; // r4
  int v15; // r8
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r1
  __int16 v20; // r3
  int v21; // r4
  int v22; // r0
  int v23; // r3
  int v24; // r0
  int v25; // r4
  int v26; // r3
  unsigned int v27; // r9
  int v28; // r0
  int v29; // r3
  int v30; // r1
  int v31; // r9
  unsigned int v32; // r0
  char v33; // r3
  int v34; // r3
  int v35; // r0
  _BYTE v37[4]; // [sp+10h] [bp-88h] BYREF
  int v38; // [sp+14h] [bp-84h] BYREF
  int v39; // [sp+18h] [bp-80h]
  _DWORD *v40; // [sp+1Ch] [bp-7Ch] BYREF
  unsigned int v41; // [sp+20h] [bp-78h]
  _DWORD *v42; // [sp+24h] [bp-74h]
  unsigned int v43; // [sp+2Ch] [bp-6Ch]
  int v44; // [sp+30h] [bp-68h]
  int v45; // [sp+34h] [bp-64h]
  int v46; // [sp+38h] [bp-60h]
  _DWORD *v47; // [sp+3Ch] [bp-5Ch]
  int v48; // [sp+40h] [bp-58h]
  int v49; // [sp+44h] [bp-54h]
  int v50; // [sp+48h] [bp-50h]
  int v51; // [sp+4Ch] [bp-4Ch]
  _DWORD v52[2]; // [sp+50h] [bp-48h] BYREF
  _WORD v53[2]; // [sp+58h] [bp-40h] BYREF
  int v54; // [sp+5Ch] [bp-3Ch]
  int v55; // [sp+60h] [bp-38h]
  int v56; // [sp+64h] [bp-34h]
  int v57; // [sp+68h] [bp-30h]
  int v58; // [sp+6Ch] [bp-2Ch]
  int v59; // [sp+70h] [bp-28h]
  int vars4; // [sp+9Ch] [bp+4h]
  int varg_r0; // [sp+A0h] [bp+8h]
  _DWORD *varg_r1; // [sp+A4h] [bp+Ch]
  unsigned int varg_r2; // [sp+A8h] [bp+10h]
  unsigned int varg_r3; // [sp+ACh] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v43 = a4;
  varg_r3 = a4;
  v48 = a3;
  v42 = a2;
  v38 = a1;
  v47 = a2;
  v40 = (_DWORD *)a3;
  v6 = 0;
  v45 = 0;
  v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v44 = v41;
  v7 = *(char *)(v41 + 0x15A);
  v39 = v7;
  v37[1] = v7;
  if ( v7 )
  {
    if ( a5 >= 0xE || !*((_BYTE *)IopSetFsOperationLength + a5) )
      return -1073741821;
    if ( a4 < *((unsigned __int8 *)IopSetFsOperationLength + a5) )
      return -1073741820;
    v9 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v9 = (_DWORD *)MmUserProbeAddress;
    *v9 = *v9;
    if ( a4 )
    {
      if ( ((*((unsigned __int8 *)IopQuerySetFsAlignmentRequirement + a5) - 1) & a3) != 0 )
        ExRaiseDatatypeMisalignment(&pIoAllocateIrp);
      if ( a3 + a4 > MmUserProbeAddress || a3 + a4 < a3 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  v10 = ObReferenceObjectByHandle(a1, IopSetFsOperationAccess[a5], (int)IoFileObjectType, v7, (int)&v40, 0);
  v11 = v40;
  if ( v10 >= 0 )
  {
    v12 = (_DWORD *)v40[31];
    if ( v12 )
    {
      if ( (*v12 & 4) != 0 )
      {
        v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v38 = 0;
        v14 = PsReferencePrimaryToken(v13);
        SeQueryInformationToken(v14, 29, &v38);
        ObfDereferenceObject(v14);
        if ( v38 )
        {
          ObfDereferenceObject((int)v11);
          v10 = -1073739504;
        }
      }
    }
  }
  if ( v10 < 0 )
    return v10;
  if ( IoGetRelatedTargetDevice((int)v11, &v38) >= 0 )
  {
    v15 = v38;
  }
  else
  {
    v15 = 0;
    v38 = 0;
  }
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
    if ( v18 )
    {
      v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v20 = *(_WORD *)(v19 + 0x134) + 1;
      *(_WORD *)(v19 + 308) = v20;
      if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
        KiCheckForKernelApcDelivery(1);
      v21 = IopAcquireFileObjectLock((int)v11, v39, (v11[11] & 4) != 0, v37);
      if ( v37[0] )
      {
        ObfDereferenceObject((int)v11);
        if ( v15 )
          ObfDereferenceObject(v15);
        return v21;
      }
    }
    else
    {
      ObfReferenceObject((int)v11);
    }
    v46 = 1;
    v37[0] = 1;
  }
  else
  {
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v23 = 40;
      else
        v23 = 32;
      v22 = ExAllocatePoolWithTagPriority(512, 0x10u, 538996553, v23);
    }
    else
    {
      v22 = ExAllocatePoolWithTag(512, 16, 538996553);
    }
    v6 = v22;
    v45 = v22;
    if ( !v22 )
    {
      ObfDereferenceObject((int)v11);
LABEL_48:
      if ( v15 )
        ObfDereferenceObject(v15);
      return -1073741670;
    }
    KeInitializeEvent(v22, 1, 0);
    v46 = 0;
    v37[0] = 0;
  }
  if ( (v11[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v11 + 23));
  v44 = IoGetRelatedDeviceObject(v11);
  v49 = v44;
  v24 = pIoAllocateIrp(v44, *(char *)(v44 + 48), 0, vars4);
  v25 = v24;
  v51 = v24;
  if ( !v24 )
  {
    if ( (v11[11] & 2) == 0 )
      ExFreePoolWithTag(v6);
    IopAllocateIrpCleanup((int)v11, 0);
    goto LABEL_48;
  }
  *(_DWORD *)(v24 + 100) = v11;
  *(_DWORD *)(v24 + 80) = v41;
  *(_BYTE *)(v24 + 32) = v39;
  if ( v46 )
  {
    *(_DWORD *)(v24 + 44) = 0;
    *(_DWORD *)(v24 + 40) = v42;
  }
  else
  {
    *(_DWORD *)(v24 + 44) = v6;
    *(_DWORD *)(v24 + 40) = v52;
    *(_DWORD *)(v24 + 8) = 4;
  }
  *(_DWORD *)(v24 + 48) = 0;
  v26 = *(_DWORD *)(v24 + 96) - 40;
  v41 = v26;
  v50 = v26;
  *(_BYTE *)v26 = 11;
  *(_DWORD *)(v26 + 28) = v11;
  *(_DWORD *)(v24 + 12) = 0;
  *(_DWORD *)(v24 + 4) = 0;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v29 = 40;
    else
      v29 = 32;
    v27 = v43;
    v28 = ExAllocatePoolWithTagPriority(512, v43, 538996553, v29);
    if ( !v28 )
      RtlRaiseStatus(-1073741670);
  }
  else
  {
    v27 = v43;
    v28 = ExAllocatePoolWithQuotaTag(0x200u, v43, 538996553);
  }
  *(_DWORD *)(v25 + 12) = v28;
  memmove(v28, v48, v27);
  v30 = v41;
  v31 = v46;
  v32 = v43;
  v33 = v39;
  if ( v39 && a5 == 2 )
  {
    v34 = **(_DWORD **)(v25 + 12);
    if ( v34 < 0 || v34 + 4 > v43 )
    {
      IopExceptionCleanup((int)v11, v25, 0, v6);
      if ( v15 )
        ObfDereferenceObject(v15);
      return -1073741811;
    }
    v33 = v39;
  }
  *(_DWORD *)(v25 + 8) |= 0x30u;
  *(_DWORD *)(v30 + 8) = v32;
  *(_DWORD *)(v30 + 12) = a5;
  v35 = IopSynchronousServiceTail(v44, v25, v11, 0, v33, v31, 2);
  v8 = v35;
  if ( !v31 )
    v8 = IopSynchronousApiServiceTail(v35, v6, v25, v39, v52, v42);
  if ( v15 )
  {
    if ( v8 >= 0 )
    {
      v53[0] = 1;
      v58 = 0;
      v59 = -1;
      v53[1] = 28;
      v54 = 1936942410;
      v55 = 298877226;
      v56 = 575422;
      v57 = 789176875;
      IoReportTargetDeviceChange(v15, v53);
    }
    ObfDereferenceObject(v15);
  }
  return v8;
}
