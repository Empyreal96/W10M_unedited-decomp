// NtNotifyChangeDirectoryFile 
 
int __fastcall NtNotifyChangeDirectoryFile(int a1, int a2, int a3, int a4, unsigned int a5, int a6, unsigned int a7, int a8, char a9)
{
  int v11; // r9
  int v12; // r2
  _DWORD *v13; // r2
  int v14; // r6
  int v15; // r8
  _DWORD *v16; // r5
  _DWORD *v17; // r3
  int v18; // r0
  int v19; // r4
  int v20; // r8
  int v21; // r0
  unsigned int v22; // r2
  unsigned int *v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // r1
  __int16 v26; // r3
  int v27; // r4
  int v28; // r10
  int v29; // r9
  int v30; // r0
  int v31; // r4
  int v32; // r1
  int v33; // r0
  unsigned __int8 *v34; // r8
  unsigned int v35; // r1
  int v36; // r3
  int v37; // r0
  int v38; // r3
  int v39; // r0
  int v40; // r2
  char v42[3]; // [sp+11h] [bp-57h] BYREF
  int v43; // [sp+14h] [bp-54h]
  unsigned int v44; // [sp+18h] [bp-50h]
  int v45; // [sp+1Ch] [bp-4Ch]
  int v46; // [sp+20h] [bp-48h]
  int v47; // [sp+24h] [bp-44h]
  _DWORD *v48; // [sp+28h] [bp-40h] BYREF
  unsigned int v49; // [sp+2Ch] [bp-3Ch]
  int v50; // [sp+30h] [bp-38h]
  int v51; // [sp+38h] [bp-30h] BYREF
  unsigned int v52; // [sp+3Ch] [bp-2Ch]
  unsigned __int8 *v53; // [sp+40h] [bp-28h]
  int _44[15]; // [sp+44h] [bp-24h] BYREF

  v53 = (unsigned __int8 *)a4;
  _44[14] = a4;
  v50 = a3;
  _44[13] = a3;
  _44[12] = a2;
  _44[11] = a1;
  v11 = 0;
  v46 = 0;
  v47 = 0;
  v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  _44[0] = v52;
  v12 = *(char *)(v52 + 0x15A);
  v43 = v12;
  if ( v12 )
  {
    v49 = a5;
    v13 = (_DWORD *)a5;
    if ( a5 >= MmUserProbeAddress )
      v13 = (_DWORD *)MmUserProbeAddress;
    *v13 = *v13;
    v44 = a7;
    v45 = a6;
    if ( a7 )
      ProbeForWrite(a6, a7, 4);
    v12 = v43;
    if ( (a8 & 0xFFFFF000) != 0 || !a8 )
      return -1073741811;
  }
  else
  {
    v44 = a7;
    v45 = a6;
    v49 = a5;
  }
  v15 = ObReferenceObjectByHandle(a1, 1, IoFileObjectType, v12, &v48);
  v16 = v48;
  if ( v15 >= 0 )
  {
    v17 = (_DWORD *)v48[31];
    if ( v17 )
    {
      if ( (*v17 & 4) != 0 )
      {
        v18 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v51 = 0;
        v19 = PsReferencePrimaryToken(v18);
        SeQueryInformationToken(v19, 29, &v51);
        ObfDereferenceObject(v19);
        if ( v51 )
        {
          ObfDereferenceObject((int)v16);
          v15 = -1073739504;
        }
      }
    }
  }
  if ( v15 < 0 )
    return v15;
  if ( v16[27] && v50 )
  {
    v14 = -1073741811;
LABEL_37:
    ObfDereferenceObject((int)v16);
    return v14;
  }
  v20 = v43;
  if ( a2 )
  {
    v21 = ObReferenceObjectByHandle(a2, 2, ExEventObjectType, v43, _44);
    v11 = _44[0];
    v46 = _44[0];
    v47 = _44[0];
    if ( v21 < 0 )
    {
      v14 = v21;
      goto LABEL_37;
    }
    KeResetEvent(_44[0]);
  }
  if ( (v16[11] & 2) != 0 )
  {
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v22 + 308);
    __dmb(0xBu);
    v23 = v16 + 17;
    do
      v24 = __ldrex(v23);
    while ( __strex(1u, v23) );
    __dmb(0xBu);
    if ( v24 )
    {
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v26 = *(_WORD *)(v25 + 0x134) + 1;
      *(_WORD *)(v25 + 308) = v26;
      if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
        KiCheckForKernelApcDelivery(1);
      v27 = IopAcquireFileObjectLock(v16, v20, (v16[11] & 4) != 0, v42);
      if ( v42[0] )
      {
        if ( v11 )
          ObfDereferenceObject(v11);
        v14 = v27;
        goto LABEL_37;
      }
    }
    else
    {
      ObfReferenceObject((int)v16);
    }
    v28 = 1;
  }
  else
  {
    v28 = 0;
  }
  v42[0] = v28;
  if ( (v16[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v16 + 23));
  v29 = IoGetRelatedDeviceObject(v16);
  _44[0] = v29;
  v30 = pIoAllocateIrp(v29, *(char *)(v29 + 48), v28 == 0, _44[10]);
  v31 = v30;
  v51 = v30;
  v32 = v46;
  if ( v30 )
  {
    *(_DWORD *)(v30 + 100) = v16;
    *(_DWORD *)(v30 + 80) = v52;
    v33 = v43;
    *(_BYTE *)(v31 + 32) = v43;
    *(_DWORD *)(v31 + 44) = v32;
    *(_DWORD *)(v31 + 40) = v49;
    *(_DWORD *)(v31 + 48) = v50;
    *(_DWORD *)(v31 + 52) = v53;
    v34 = (unsigned __int8 *)(*(_DWORD *)(v31 + 96) - 40);
    v53 = v34;
    *v34 = 12;
    v34[1] = 2;
    *((_DWORD *)v34 + 7) = v16;
    v35 = v44;
    if ( v44 )
    {
      v36 = *(_DWORD *)(v29 + 28);
      if ( (v36 & 4) != 0 )
      {
        if ( ViVerifierDriverAddedThunkListHead )
        {
          if ( (MmVerifierData & 0x10) != 0 )
            v38 = 40;
          else
            v38 = 32;
          v37 = ExAllocatePoolWithTagPriority(512, v44, 538996553, v38);
          if ( !v37 )
            RtlRaiseStatus(-1073741670);
        }
        else
        {
          v37 = ExAllocatePoolWithQuotaTag(0x200u, v44, 538996553);
        }
        *(_DWORD *)(v31 + 12) = v37;
        v35 = v44;
        v33 = v43;
        *(_DWORD *)(v31 + 60) = v45;
        *(_DWORD *)(v31 + 8) = 112;
      }
      else if ( (v36 & 0x10) != 0 )
      {
        v39 = IoAllocateMdl(v45, v44, 0, 1, v31);
        if ( !v39 )
          RtlRaiseStatus(-1073741670);
        sub_564C10(v39, v43, v40, v29, *v34);
        v35 = v44;
        v33 = v43;
      }
      else
      {
        *(_DWORD *)(v31 + 60) = v45;
        v33 = v43;
      }
    }
    *((_DWORD *)v34 + 2) = v35;
    *((_DWORD *)v34 + 3) = a8;
    if ( a9 )
      v34[2] = 1;
    v14 = IopSynchronousServiceTail(v29, v31, v16, 0, v33, v28, 2);
  }
  else
  {
    IopAllocateIrpCleanup(v16, v46);
    v14 = -1073741670;
  }
  return v14;
}
