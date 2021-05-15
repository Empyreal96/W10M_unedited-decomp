// NtQueryQuotaInformationFile 
 
int __fastcall NtQueryQuotaInformationFile(int a1, _DWORD *a2, unsigned int a3, int a4, char a5, unsigned int a6, unsigned int a7, unsigned int a8, char a9)
{
  int v10; // r5
  unsigned int v11; // r9
  _BYTE *v12; // r8
  _DWORD *v13; // r2
  unsigned int v14; // r0
  unsigned __int8 *v15; // r3
  _BYTE *v16; // r3
  unsigned int v17; // r1
  int v18; // r6
  int v19; // r3
  unsigned int v20; // r8
  int v21; // r4
  int v22; // r3
  int v23; // r4
  int v24; // r9
  _DWORD *v25; // r8
  _DWORD *v26; // r3
  int v27; // r0
  int v28; // r4
  unsigned int v29; // r2
  unsigned int *v30; // r2
  unsigned int v31; // r1
  unsigned int v32; // r1
  __int16 v33; // r3
  int v34; // r4
  int v35; // r9
  int v36; // r0
  int v37; // r3
  int v38; // r0
  _DWORD *v39; // r4
  unsigned __int8 *v40; // r9
  int v41; // r0
  int v42; // r3
  int v43; // r0
  int v44; // r3
  int v45; // r10
  int v46; // r0
  unsigned int v47; // r10
  int v48; // r2
  int v49; // r5
  int v50; // r0
  _BYTE v52[4]; // [sp+10h] [bp-78h] BYREF
  int v53; // [sp+14h] [bp-74h] BYREF
  int v54; // [sp+18h] [bp-70h]
  unsigned int v55; // [sp+1Ch] [bp-6Ch] BYREF
  unsigned int v56; // [sp+20h] [bp-68h]
  int v57; // [sp+24h] [bp-64h]
  int v58; // [sp+28h] [bp-60h]
  int v59; // [sp+2Ch] [bp-5Ch]
  int v60; // [sp+30h] [bp-58h]
  unsigned int v61; // [sp+34h] [bp-54h]
  _DWORD *v62; // [sp+38h] [bp-50h]
  int v63; // [sp+3Ch] [bp-4Ch]
  int v64; // [sp+40h] [bp-48h]
  int v65; // [sp+44h] [bp-44h]
  unsigned int v66; // [sp+48h] [bp-40h]
  int v67; // [sp+4Ch] [bp-3Ch]
  unsigned int v68; // [sp+50h] [bp-38h]
  int v69; // [sp+54h] [bp-34h]
  int v70; // [sp+58h] [bp-30h]
  int v71; // [sp+5Ch] [bp-2Ch]
  _DWORD _60[16]; // [sp+60h] [bp-28h] BYREF

  v61 = a4;
  _60[15] = a4;
  v60 = a3;
  _60[14] = a3;
  v62 = a2;
  _60[13] = a2;
  v54 = a1;
  _60[12] = a1;
  v59 = 0;
  v67 = 0;
  v10 = 0;
  v63 = 0;
  v11 = 0;
  v12 = 0;
  v53 = 0;
  v70 = 0;
  v64 = 0;
  v69 = 0;
  v66 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v68 = v66;
  v57 = *(char *)(v66 + 0x15A);
  v52[1] = v57;
  if ( v57 )
  {
    v13 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v13 = (_DWORD *)MmUserProbeAddress;
    *v13 = *v13;
    v14 = ProbeForWrite(a3, a4, 8);
    v65 = a8;
    if ( a8 )
    {
      v15 = (unsigned __int8 *)(a8 + 1);
      if ( a8 + 1 >= MmUserProbeAddress )
        v15 = (unsigned __int8 *)MmUserProbeAddress;
      v55 = *v15;
      v14 = RtlLengthRequiredSid(v55);
      v11 = v14;
      if ( v14 )
      {
        if ( (a8 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v14);
        v16 = (_BYTE *)MmUserProbeAddress;
        if ( v14 + a8 > MmUserProbeAddress || v14 + a8 < a8 )
        {
          *(_BYTE *)MmUserProbeAddress = 0;
          v16 = (_BYTE *)MmUserProbeAddress;
        }
LABEL_15:
        if ( a6 && (v56 = a7) != 0 )
        {
          if ( (a6 & 3) != 0 )
            ExRaiseDatatypeMisalignment(v14);
          if ( a6 + a7 > (unsigned int)v16 || a6 + a7 < a6 )
            *v16 = 0;
          v17 = (a7 + 3) & 0xFFFFFFFC;
          if ( v17 > -1 - v11 )
          {
            v18 = -1073741811;
            v58 = -1073741811;
            return v18;
          }
          if ( v17 < a7 )
          {
            v18 = -1073741811;
            v58 = -1073741811;
            return v18;
          }
          if ( ViVerifierDriverAddedThunkListHead )
          {
            if ( (MmVerifierData & 0x10) != 0 )
              v19 = 40;
            else
              v19 = 32;
            v10 = ExAllocatePoolWithTagPriority(512, v17 + v11, 538996553, v19);
            if ( !v10 )
              RtlRaiseStatus(-1073741670);
          }
          else
          {
            v10 = ExAllocatePoolWithQuotaTag(0x200u, v17 + v11, 538996553);
          }
          v63 = v10;
          v64 = v10;
          v69 = v10;
          v20 = v56;
          memmove(v10, a6, v56);
        }
        else
        {
          v20 = 0;
          v56 = 0;
          v21 = a8;
          if ( !a8 )
            goto LABEL_45;
          if ( ViVerifierDriverAddedThunkListHead )
          {
            if ( (MmVerifierData & 0x10) != 0 )
              v22 = 40;
            else
              v22 = 32;
            v10 = ExAllocatePoolWithTagPriority(1, v11, 538996553, v22);
            if ( !v10 )
              RtlRaiseStatus(-1073741670);
            v20 = v56;
          }
          else
          {
            v10 = ExAllocatePoolWithQuotaTag(1u, v11, 538996553);
          }
          v63 = v10;
        }
        v21 = a8;
LABEL_45:
        if ( v21 )
        {
          v53 = ((v20 + 3) & 0xFFFFFFFC) + v10;
          v70 = v53;
          memmove(v53, v21, v11);
          *(_BYTE *)(v53 + 1) = v55;
        }
        v12 = (_BYTE *)v53;
        goto LABEL_54;
      }
    }
    else
    {
      v55 = 0;
    }
    v16 = (_BYTE *)MmUserProbeAddress;
    goto LABEL_15;
  }
  if ( a6 )
  {
    v56 = a7;
    if ( a7 )
      v64 = a6;
  }
  else
  {
    v56 = a7;
  }
  v65 = a8;
  if ( a8 )
    v12 = (_BYTE *)a8;
LABEL_54:
  if ( v64 )
  {
    v55 = 0;
    v23 = IopCheckGetQuotaBufferValidity(v64, v56, &v55);
    if ( v23 < 0 )
    {
      v62[1] = v55;
      if ( v10 )
        ExFreePoolWithTag(v10);
      return v23;
    }
  }
  if ( v12 && !RtlValidSid(v12) )
  {
    if ( v10 )
      ExFreePoolWithTag(v10);
    return -1073741704;
  }
  v24 = ObReferenceObjectByHandle(v54, 0, (int)IoFileObjectType, v57, (int)&v55, 0);
  v25 = (_DWORD *)v55;
  if ( v24 >= 0 )
  {
    v26 = *(_DWORD **)(v55 + 124);
    if ( v26 )
    {
      if ( (*v26 & 4) != 0 )
      {
        v27 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v53 = 0;
        v28 = PsReferencePrimaryToken(v27);
        SeQueryInformationToken(v28, 29, &v53);
        ObfDereferenceObject(v28);
        if ( v53 )
        {
          ObfDereferenceObject((int)v25);
          v24 = -1073739504;
        }
      }
    }
  }
  if ( v24 < 0 )
  {
    if ( v10 )
      ExFreePoolWithTag(v10);
    return v24;
  }
  if ( (v25[11] & 2) != 0 )
  {
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v29 + 308);
    __dmb(0xBu);
    v30 = v25 + 17;
    do
      v31 = __ldrex(v30);
    while ( __strex(1u, v30) );
    __dmb(0xBu);
    if ( !v31 )
    {
      ObfReferenceObject((int)v25);
LABEL_86:
      v35 = 1;
      goto LABEL_99;
    }
    v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v33 = *(_WORD *)(v32 + 0x134) + 1;
    *(_WORD *)(v32 + 308) = v33;
    if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
      KiCheckForKernelApcDelivery(1);
    v34 = IopAcquireFileObjectLock((int)v25, v57, (v25[11] & 4) != 0, v52);
    if ( !v52[0] )
      goto LABEL_86;
    if ( v10 )
      ExFreePoolWithTag(v10);
    v18 = v34;
LABEL_97:
    ObfDereferenceObject((int)v25);
    return v18;
  }
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v37 = 40;
    else
      v37 = 32;
    v36 = ExAllocatePoolWithTagPriority(512, 0x10u, 538996553, v37);
  }
  else
  {
    v36 = ExAllocatePoolWithTag(512, 16, 538996553);
  }
  v59 = v36;
  v67 = v36;
  if ( !v36 )
  {
    if ( v10 )
      ExFreePoolWithTag(v10);
    v18 = -1073741670;
    goto LABEL_97;
  }
  KeInitializeEvent(v36, 1, 0);
  v35 = 0;
LABEL_99:
  v52[0] = v35;
  v54 = v35;
  if ( (v25[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v25 + 23));
  v53 = IoGetRelatedDeviceObject(v25);
  v68 = v53;
  v38 = pIoAllocateIrp(v53, *(char *)(v53 + 48), 0, _60[11]);
  v39 = (_DWORD *)v38;
  v71 = v38;
  if ( !v38 )
  {
    if ( (v25[11] & 2) == 0 )
      ExFreePoolWithTag(v59);
    IopAllocateIrpCleanup((int)v25, 0);
    if ( v10 )
      ExFreePoolWithTag(v10);
    return -1073741670;
  }
  *(_DWORD *)(v38 + 100) = v25;
  *(_DWORD *)(v38 + 80) = v66;
  *(_BYTE *)(v38 + 32) = v57;
  if ( v35 )
  {
    *(_DWORD *)(v38 + 44) = 0;
    *(_DWORD *)(v38 + 40) = v62;
  }
  else
  {
    *(_DWORD *)(v38 + 44) = v59;
    *(_DWORD *)(v38 + 40) = _60;
    *(_DWORD *)(v38 + 8) = 4;
  }
  *(_DWORD *)(v38 + 48) = 0;
  v40 = (unsigned __int8 *)(*(_DWORD *)(v38 + 96) - 40);
  v66 = (unsigned int)v40;
  *v40 = 25;
  *((_DWORD *)v40 + 7) = v25;
  *(_DWORD *)(v38 + 84) = v10;
  *((_DWORD *)v40 + 4) = v64;
  *((_DWORD *)v40 + 5) = v56;
  v41 = v53;
  v42 = *(_DWORD *)(v53 + 28);
  if ( (v42 & 4) != 0 )
  {
    if ( v61 )
    {
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v44 = 40;
        else
          v44 = 32;
        v43 = ExAllocatePoolWithTagPriority(512, v61, 538996553, v44);
        if ( !v43 )
          RtlRaiseStatus(-1073741670);
      }
      else
      {
        v43 = ExAllocatePoolWithQuotaTag(0x200u, v61, 538996553);
      }
      v39[3] = v43;
      v45 = v54;
      v41 = v53;
      v39[15] = v60;
      v39[2] |= 0x70u;
      goto LABEL_130;
    }
    v39[3] = 0;
  }
  else if ( (v42 & 0x10) != 0 )
  {
    if ( v61 )
    {
      v46 = IoAllocateMdl(v60, v61, 0, 1, (int)v39);
      v47 = v46;
      if ( !v46 )
        RtlRaiseStatus(-1073741670);
      v60 = *v40;
      MmProbeAndLockPages(v46);
      if ( (MmTrackLockedPages & 1) != 0 )
        MmUpdateMdlTracker(v47, *(_DWORD *)(*(_DWORD *)(v53 + 8) + 4 * v60 + 56), v53, *(_DWORD *)(v53 + 8) + 4 * v60);
      v45 = v54;
      v41 = v53;
      goto LABEL_130;
    }
    goto LABEL_129;
  }
  v39[15] = v60;
LABEL_129:
  v45 = v54;
LABEL_130:
  *((_DWORD *)v40 + 2) = v61;
  v48 = v65;
  *((_DWORD *)v40 + 3) = v65;
  v40[2] = 0;
  if ( a9 )
    v40[2] = 1;
  if ( a5 )
    v40[2] |= 2u;
  if ( v48 )
    v40[2] |= 4u;
  v49 = v57;
  v50 = IopSynchronousServiceTail(v41, (int)v39, v25, 0, v57, v45, 2);
  v18 = v50;
  if ( !v45 )
    v18 = IopSynchronousApiServiceTail(v50, v59, (int)v39, v49, _60, v62);
  return v18;
}
