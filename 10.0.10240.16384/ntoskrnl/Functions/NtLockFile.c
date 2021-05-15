// NtLockFile 
 
int __fastcall NtLockFile(int a1, int a2, int a3, int a4, _DWORD *a5, int *a6, int *a7, int a8, unsigned __int8 a9, unsigned __int8 a10)
{
  int v11; // r9
  int v12; // r10
  int v13; // r6
  int v14; // r5
  _DWORD *v15; // r3
  int v16; // r0
  int v17; // r4
  _DWORD *v18; // r2
  int v19; // r0
  int v20; // r0
  int v21; // r0
  int v22; // r10
  int v23; // r3
  int (__fastcall *v24)(int, int *, int *, _DWORD, int, _DWORD, _DWORD, int *, int); // r8
  int v25; // r4
  int v26; // r10
  int v27; // r3
  _DWORD *v28; // r2
  int v29; // r1
  int v30; // r6
  int *v31; // r0
  unsigned int v32; // r2
  unsigned int *v33; // r2
  unsigned int v34; // r1
  unsigned int v35; // r1
  __int16 v36; // r3
  int v37; // r4
  int v38; // r10
  int v39; // r0
  int v40; // r8
  int v41; // r4
  _DWORD *v42; // r0
  int v43; // r3
  _BYTE v45[4]; // [sp+18h] [bp-70h] BYREF
  int v46; // [sp+1Ch] [bp-6Ch] BYREF
  int v47; // [sp+20h] [bp-68h] BYREF
  int v48; // [sp+24h] [bp-64h] BYREF
  int v49; // [sp+28h] [bp-60h] BYREF
  int v50; // [sp+2Ch] [bp-5Ch]
  int v51; // [sp+30h] [bp-58h]
  int v52; // [sp+34h] [bp-54h]
  _DWORD *v53; // [sp+38h] [bp-50h]
  int v54; // [sp+3Ch] [bp-4Ch]
  int v55; // [sp+40h] [bp-48h]
  unsigned int v56; // [sp+44h] [bp-44h]
  int v57; // [sp+48h] [bp-40h] BYREF
  int v58; // [sp+4Ch] [bp-3Ch]
  int v59; // [sp+50h] [bp-38h] BYREF
  int v60; // [sp+54h] [bp-34h]
  int v61; // [sp+58h] [bp-30h]
  int v62; // [sp+5Ch] [bp-2Ch]
  int v63; // [sp+60h] [bp-28h]
  char v64; // [sp+64h] [bp-24h]
  int vars4; // [sp+8Ch] [bp+4h]
  int varg_r0; // [sp+90h] [bp+8h]
  int varg_r1; // [sp+94h] [bp+Ch]
  int varg_r2; // [sp+98h] [bp+10h]
  int varg_r3; // [sp+9Ch] [bp+14h]

  varg_r0 = a1;
  v55 = a4;
  varg_r3 = a4;
  v54 = a3;
  varg_r2 = a3;
  varg_r1 = a2;
  v11 = 0;
  v52 = 0;
  v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v47 = v56;
  v12 = *(char *)(v56 + 0x15A);
  v51 = v12;
  v45[1] = v12;
  v13 = ObReferenceObjectByHandle(a1, 0, IoFileObjectType, v12, &v48);
  v14 = v48;
  if ( v13 >= 0 )
  {
    v15 = *(_DWORD **)(v48 + 124);
    if ( v15 )
    {
      if ( (*v15 & 4) != 0 )
      {
        v16 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v46 = 0;
        v17 = PsReferencePrimaryToken(v16);
        SeQueryInformationToken(v17, 29, &v46);
        ObfDereferenceObject(v17);
        if ( v46 )
        {
          ObfDereferenceObject(v14);
          v13 = -1073739504;
        }
      }
    }
    if ( v13 >= 0 )
    {
      if ( v12 )
      {
        if ( (v64 & 3) == 0 )
        {
          v13 = -1073741790;
LABEL_58:
          ObfDereferenceObject(v14);
          return v13;
        }
        v53 = a5;
        v18 = a5;
        if ( (unsigned int)a5 >= MmUserProbeAddress )
          v18 = (_DWORD *)MmUserProbeAddress;
        *v18 = *v18;
        if ( ((unsigned __int8)a6 & 3) != 0 )
          ExRaiseDatatypeMisalignment(&pIoAllocateIrp);
        v59 = *a6;
        v60 = a6[1];
        if ( ((unsigned __int8)a7 & 3) != 0 )
          ExRaiseDatatypeMisalignment(&pIoAllocateIrp);
        v57 = *a7;
        v58 = a7[1];
        if ( *(_DWORD *)(v14 + 108) && v54 )
        {
          ObfDereferenceObject(v14);
          v13 = -1073741811;
          v46 = -1073741811;
          return v13;
        }
      }
      else
      {
        v59 = *a6;
        v60 = a6[1];
        v57 = *a7;
        v58 = a7[1];
        v53 = a5;
      }
      *(_BYTE *)(v14 + 36) = 1;
      v19 = IopSetLockOperationProcess(v14, *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0);
      if ( v19 < 0 )
        return v19;
      if ( a2 )
      {
        v20 = ObReferenceObjectByHandle(a2, 2, ExEventObjectType, v12, &v47);
        v11 = v47;
        v52 = v47;
        if ( v20 >= 0 )
          KeResetEvent(v47);
      }
      v21 = IoGetRelatedDeviceObject((_DWORD *)v14);
      v22 = v21;
      v47 = v21;
      v63 = v21;
      v23 = *(_DWORD *)(*(_DWORD *)(v21 + 8) + 40);
      if ( v23
        && (v24 = *(int (__fastcall **)(int, int *, int *, _DWORD, int, _DWORD, _DWORD, int *, int))(v23 + 24)) != 0 )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v25 = VfFastIoSnapState(v21);
        else
          v25 = 0;
        v62 = a10;
        v61 = a9;
        v26 = v24(v14, &v59, &v57, *(_DWORD *)(v56 + 116), a8, a9, a10, &v49, v22);
        if ( v25 )
          VfFastIoCheckState(v25, v24);
        if ( v26 )
        {
          v27 = v49;
          v28 = v53;
          *v53 = v49;
          v29 = v50;
          v28[1] = v50;
          v30 = v55;
          if ( v11 )
          {
            if ( (*(_DWORD *)(v14 + 44) & 0x8000000) == 0 )
              KeSetEvent(v11, 0, 0);
            ObfDereferenceObject(v11);
            v29 = v50;
            v27 = v49;
          }
          v31 = *(int **)(v14 + 108);
          if ( v31
            && v30
            && (*(_DWORD *)(v14 + 44) & 0x2000000) == 0
            && IoSetIoCompletion(*v31, v31[1], v30, v27, v29, 1u) < 0 )
          {
            v49 = -1073741670;
          }
          ObfDereferenceObject(v14);
          return v49;
        }
      }
      else
      {
        v62 = a10;
        v61 = a9;
      }
      if ( (*(_DWORD *)(v14 + 44) & 2) != 0 )
      {
        v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v32 + 308);
        __dmb(0xBu);
        v33 = (unsigned int *)(v14 + 68);
        do
          v34 = __ldrex(v33);
        while ( __strex(1u, v33) );
        __dmb(0xBu);
        if ( v34 )
        {
          v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v36 = *(_WORD *)(v35 + 0x134) + 1;
          *(_WORD *)(v35 + 308) = v36;
          if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
            KiCheckForKernelApcDelivery(1);
          v37 = IopAcquireFileObjectLock(v14, v51, (*(_DWORD *)(v14 + 44) & 4) != 0, v45);
          if ( v45[0] )
          {
            if ( v11 )
              ObfDereferenceObject(v11);
            v13 = v37;
            goto LABEL_58;
          }
        }
        else
        {
          ObfReferenceObject(v14);
        }
        v38 = 1;
      }
      else
      {
        v38 = 0;
      }
      v45[0] = v38;
      if ( (*(_DWORD *)(v14 + 44) & 0x4000000) == 0 )
        KeResetEvent(v14 + 92);
      v39 = pIoAllocateIrp(v47, *(char *)(v47 + 48), v38 == 0, vars4);
      v40 = v39;
      v49 = v39;
      if ( !v39 )
      {
        IopAllocateIrpCleanup(v14, v11);
        return -1073741670;
      }
      *(_DWORD *)(v39 + 100) = v14;
      *(_DWORD *)(v39 + 80) = v56;
      *(_BYTE *)(v39 + 32) = v51;
      *(_DWORD *)(v39 + 44) = v11;
      *(_DWORD *)(v39 + 40) = v53;
      *(_DWORD *)(v39 + 48) = v54;
      *(_DWORD *)(v39 + 52) = v55;
      v41 = *(_DWORD *)(v39 + 96);
      *(_BYTE *)(v41 - 40) = 17;
      *(_BYTE *)(v41 - 39) = 1;
      *(_DWORD *)(v41 - 12) = v14;
      *(_BYTE *)(v41 - 38) = 0;
      if ( v61 )
        *(_BYTE *)(v41 - 38) = 1;
      if ( v62 )
        *(_BYTE *)(v41 - 38) |= 2u;
      *(_DWORD *)(v41 - 28) = a8;
      *(_DWORD *)(v41 - 24) = v59;
      *(_DWORD *)(v41 - 20) = v60;
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v43 = 40;
        else
          v43 = 32;
        v42 = (_DWORD *)ExAllocatePoolWithTagPriority(512, 8u, 538996553, v43);
        if ( !v42 )
          RtlRaiseStatus(-1073741670);
      }
      else
      {
        v42 = (_DWORD *)ExAllocatePoolWithQuotaTag(0x200u, 8u, 538996553);
      }
      *v42 = v57;
      v42[1] = v58;
      *(_DWORD *)(v40 + 84) = v42;
      *(_DWORD *)(v41 - 32) = v42;
      return IopSynchronousServiceTail(v47, v40, v14, 0, v51, v38, 2);
    }
  }
  return v13;
}
