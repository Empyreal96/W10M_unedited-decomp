// NtFlushBuffersFileEx 
 
int __fastcall NtFlushBuffersFileEx(int a1, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // r4
  _DWORD *v6; // r2
  int v7; // r5
  _DWORD *v8; // r6
  _DWORD *v9; // r3
  int v10; // r3
  int v11; // r4
  int v12; // r1
  int v13; // r3
  unsigned int v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r9
  unsigned int v20; // r8
  int v21; // r0
  int v22; // r3
  int v23; // r5
  int v24; // r0
  int v25; // r4
  int v26; // r2
  int v27; // r10
  int v28; // r3
  int v29; // r0
  char v31[4]; // [sp+10h] [bp-48h] BYREF
  int v32; // [sp+14h] [bp-44h]
  int v33; // [sp+18h] [bp-40h]
  _DWORD *v34; // [sp+1Ch] [bp-3Ch] BYREF
  unsigned int v35; // [sp+20h] [bp-38h]
  int v36; // [sp+24h] [bp-34h]
  int v37; // [sp+2Ch] [bp-2Ch]
  _DWORD _30[16]; // [sp+30h] [bp-28h] BYREF

  _30[14] = a3;
  _30[15] = a4;
  v36 = a2;
  _30[13] = a2;
  _30[12] = a1;
  if ( a3 || a4 )
    return -1073741811;
  v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v34 = (_DWORD *)v35;
  v5 = *(char *)(v35 + 0x15A);
  v32 = v5;
  v31[0] = v5;
  if ( v5 )
  {
    v33 = a5;
    v6 = (_DWORD *)a5;
    if ( a5 >= MmUserProbeAddress )
      v6 = (_DWORD *)MmUserProbeAddress;
    *v6 = *v6;
  }
  else
  {
    v33 = a5;
  }
  v7 = ObReferenceObjectByHandle(a1, 0, IoFileObjectType, v5, &v34);
  v8 = v34;
  if ( v7 >= 0 )
  {
    v9 = (_DWORD *)v34[31];
    if ( v9 && (*v9 & 4) != 0 )
    {
      v10 = __mrc(15, 0, 13, 0, 3);
      v34 = 0;
      v11 = PsReferencePrimaryToken(*(_DWORD *)((v10 & 0xFFFFFFC0) + 0x74));
      SeQueryInformationToken(v11, 29, &v34);
      ObfDereferenceObject(v11);
      if ( v34 )
      {
        ObfDereferenceObject((int)v8);
        v7 = -1073739504;
      }
      v5 = v32;
    }
    if ( v7 >= 0 )
    {
      v12 = v8[11];
      if ( (v12 & 0x80) != 0 )
        v13 = 0;
      else
        v13 = 4;
      if ( ((v13 | 2) & v37) == 0 )
      {
        v7 = -1073741790;
LABEL_39:
        ObfDereferenceObject((int)v8);
        return v7;
      }
      if ( (v12 & 2) != 0 )
      {
        v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v14 + 308);
        __dmb(0xBu);
        v15 = v8 + 17;
        do
          v16 = __ldrex(v15);
        while ( __strex(1u, v15) );
        __dmb(0xBu);
        if ( v16 )
        {
          v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v18 = *(_WORD *)(v17 + 0x134) + 1;
          *(_WORD *)(v17 + 308) = v18;
          if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
            KiCheckForKernelApcDelivery(1);
          v7 = IopAcquireFileObjectLock(v8, v5, (v8[11] & 4) != 0, v31);
          if ( v31[0] )
            goto LABEL_39;
        }
        else
        {
          ObfReferenceObject((int)v8);
        }
        v19 = 1;
        v20 = 0;
      }
      else
      {
        if ( ViVerifierDriverAddedThunkListHead )
        {
          if ( (MmVerifierData & 0x10) != 0 )
            v22 = 40;
          else
            v22 = 32;
          v21 = ExAllocatePoolWithTagPriority(512, 0x10u, 538996553, v22);
        }
        else
        {
          v21 = ExAllocatePoolWithTag(512, 16, 538996553);
        }
        v20 = v21;
        if ( !v21 )
        {
          v7 = -1073741670;
          goto LABEL_39;
        }
        KeInitializeEvent(v21, 1, 0);
        v19 = 0;
      }
      if ( (v8[11] & 0x4000000) == 0 )
        KeResetEvent((int)(v8 + 23));
      v23 = IoGetRelatedDeviceObject(v8);
      v24 = pIoAllocateIrp(v23, *(char *)(v23 + 48), 0, _30[11]);
      v25 = v24;
      if ( v24 )
      {
        *(_DWORD *)(v24 + 100) = v8;
        *(_DWORD *)(v24 + 80) = v35;
        v26 = v32;
        *(_BYTE *)(v24 + 32) = v32;
        if ( v19 )
        {
          *(_DWORD *)(v24 + 44) = 0;
          v27 = v33;
          *(_DWORD *)(v24 + 40) = v33;
        }
        else
        {
          *(_DWORD *)(v24 + 44) = v20;
          *(_DWORD *)(v24 + 40) = _30;
          *(_DWORD *)(v24 + 8) = 4;
          v27 = v33;
        }
        *(_DWORD *)(v24 + 48) = 0;
        v28 = *(_DWORD *)(v24 + 96);
        *(_BYTE *)(v28 - 40) = 9;
        *(_DWORD *)(v28 - 12) = v8;
        if ( (v36 & 1) != 0 )
        {
          *(_BYTE *)(v28 - 39) = 2;
        }
        else if ( (v36 & 2) != 0 )
        {
          *(_BYTE *)(v28 - 39) = 3;
        }
        v29 = IopSynchronousServiceTail(v23, v24, v8, 0, v26, v19, 2);
        v7 = v29;
        if ( !v19 )
          v7 = IopSynchronousApiServiceTail(v29, v20, v25, v32, _30, v27);
      }
      else
      {
        if ( v20 )
          ExFreePoolWithTag(v20);
        IopAllocateIrpCleanup(v8, 0);
        v7 = -1073741670;
      }
    }
  }
  return v7;
}
