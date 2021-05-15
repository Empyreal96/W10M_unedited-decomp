// NtUnlockFile 
 
int __fastcall NtUnlockFile(int a1, _DWORD *a2, int *a3, int *a4, int a5)
{
  int v8; // r10
  int v9; // r0
  int v10; // r6
  _DWORD *v11; // r5
  _DWORD *v12; // r2
  int v13; // r0
  int v14; // r4
  int v15; // r3
  int (__fastcall *v16)(_DWORD *, int *, int *, _DWORD, int, int *, int); // r8
  int v17; // r4
  int v18; // r9
  _DWORD *v19; // r2
  unsigned int v20; // r2
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25; // r0
  int v26; // r10
  unsigned int v27; // r8
  int v28; // r0
  int v29; // r3
  int v30; // r0
  int v31; // r4
  int v32; // r9
  _DWORD *v33; // r0
  int v34; // r3
  int v35; // r0
  int v36; // r1
  int v37; // r0
  char v39[3]; // [sp+11h] [bp-67h] BYREF
  _DWORD *v40; // [sp+14h] [bp-64h] BYREF
  int v41; // [sp+18h] [bp-60h]
  int v42; // [sp+1Ch] [bp-5Ch]
  _DWORD *v43; // [sp+20h] [bp-58h]
  unsigned int v44; // [sp+28h] [bp-50h]
  int v45; // [sp+2Ch] [bp-4Ch]
  unsigned int v46; // [sp+30h] [bp-48h]
  int v47; // [sp+38h] [bp-40h] BYREF
  int v48; // [sp+3Ch] [bp-3Ch]
  int v49; // [sp+40h] [bp-38h] BYREF
  int v50; // [sp+44h] [bp-34h]
  int v51; // [sp+48h] [bp-30h] BYREF
  int v52; // [sp+4Ch] [bp-2Ch]
  _DWORD _50[16]; // [sp+50h] [bp-28h] BYREF

  _50[12] = a1;
  _50[14] = a3;
  _50[15] = a4;
  v43 = a2;
  _50[13] = a2;
  v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v46 = v44;
  v8 = *(char *)(v44 + 0x15A);
  v41 = v8;
  v9 = ObReferenceObjectByHandle(a1, 0, IoFileObjectType, v8, &v40);
  v10 = v9;
  if ( v9 >= 0 )
  {
    if ( v8 )
    {
      if ( (v48 & 3) == 0 )
      {
        v10 = -1073741790;
        v11 = v40;
LABEL_47:
        ObfDereferenceObject((int)v11);
        return v10;
      }
      v12 = a2;
      if ( (unsigned int)a2 >= MmUserProbeAddress )
        v12 = (_DWORD *)MmUserProbeAddress;
      *v12 = *v12;
      if ( ((unsigned __int8)a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v9);
      v51 = *a3;
      v52 = a3[1];
      if ( ((unsigned __int8)a4 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v9);
      v49 = *a4;
      v50 = a4[1];
      v11 = v40;
    }
    else
    {
      v51 = *a3;
      v52 = a3[1];
      v49 = *a4;
      v50 = a4[1];
      v11 = v40;
    }
    if ( (v11[11] & 0x800) != 0 )
      v13 = IoGetAttachedDevice(v11[1]);
    else
      v13 = IoGetRelatedDeviceObject(v11);
    v14 = v13;
    v46 = v13;
    v42 = v13;
    v15 = *(_DWORD *)(*(_DWORD *)(v13 + 8) + 40);
    if ( v15 )
    {
      v16 = *(int (__fastcall **)(_DWORD *, int *, int *, _DWORD, int, int *, int))(v15 + 28);
      if ( v16 )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v17 = VfFastIoSnapState(v13);
        else
          v17 = 0;
        v18 = v16(v11, &v51, &v49, *(_DWORD *)(v44 + 116), a5, &v47, v42);
        if ( v17 )
          VfFastIoCheckState(v17, v16);
        if ( v18 )
        {
          v19 = v43;
          *v43 = v47;
          v19[1] = v48;
          ObfDereferenceObject((int)v11);
          return v47;
        }
        v14 = v42;
      }
    }
    if ( (v11[11] & 2) != 0 )
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
        v25 = IopAcquireFileObjectLock(v11, v41, (v11[11] & 4) != 0, v39);
        if ( v39[0] )
        {
          v10 = v25;
          goto LABEL_47;
        }
      }
      else
      {
        ObfReferenceObject((int)v11);
      }
      v26 = 1;
      v27 = 0;
      v45 = 0;
    }
    else
    {
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v29 = 40;
        else
          v29 = 32;
        v28 = ExAllocatePoolWithTagPriority(512, 0x10u, 538996553, v29);
      }
      else
      {
        v28 = ExAllocatePoolWithTag(512, 16, 538996553);
      }
      v27 = v28;
      v45 = v28;
      if ( !v28 )
      {
        v10 = -1073741670;
        goto LABEL_47;
      }
      KeInitializeEvent(v28, 1, 0);
      v26 = 0;
    }
    v39[0] = v26;
    if ( (v11[11] & 0x4000000) == 0 )
      KeResetEvent((int)(v11 + 23));
    v30 = pIoAllocateIrp(v14, *(char *)(v14 + 48), 0, _50[11]);
    v31 = v30;
    v47 = v30;
    if ( v30 )
    {
      *(_DWORD *)(v30 + 100) = v11;
      *(_DWORD *)(v30 + 80) = v44;
      *(_BYTE *)(v30 + 32) = v41;
      if ( v26 )
      {
        *(_DWORD *)(v30 + 44) = 0;
        *(_DWORD *)(v30 + 40) = v43;
      }
      else
      {
        *(_DWORD *)(v30 + 44) = v27;
        *(_DWORD *)(v30 + 40) = _50;
        *(_DWORD *)(v30 + 8) = 4;
      }
      *(_DWORD *)(v30 + 48) = 0;
      v32 = *(_DWORD *)(v30 + 96) - 40;
      v44 = v32;
      *(_BYTE *)v32 = 17;
      *(_BYTE *)(v32 + 1) = 2;
      *(_DWORD *)(v32 + 28) = v11;
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v34 = 40;
        else
          v34 = 32;
        v33 = (_DWORD *)ExAllocatePoolWithTagPriority(512, 8u, 538996553, v34);
        if ( !v33 )
          RtlRaiseStatus(-1073741670);
      }
      else
      {
        v33 = (_DWORD *)ExAllocatePoolWithQuotaTag(0x200u, 8u, 538996553);
      }
      *v33 = v49;
      v33[1] = v50;
      *(_DWORD *)(v31 + 84) = v33;
      *(_DWORD *)(v32 + 8) = v33;
      v35 = v42;
      v36 = v41;
      *(_DWORD *)(v32 + 12) = a5;
      *(_DWORD *)(v32 + 16) = v51;
      *(_DWORD *)(v32 + 20) = v52;
      v37 = IopSynchronousServiceTail(v35, v31, v11, 0, v36, v26, 2);
      v10 = v37;
      if ( !v26 )
        v10 = IopSynchronousApiServiceTail(v37, v27, v31, v41, _50, v43);
    }
    else
    {
      if ( v27 )
        ExFreePoolWithTag(v27);
      IopAllocateIrpCleanup(v11, 0);
      v10 = -1073741670;
    }
  }
  return v10;
}
