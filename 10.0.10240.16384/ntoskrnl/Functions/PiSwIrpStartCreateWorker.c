// PiSwIrpStartCreateWorker 
 
int __fastcall PiSwIrpStartCreateWorker(_DWORD *a1, int a2)
{
  int v2; // r8
  int v3; // r9
  int v4; // r10
  int v7; // r7
  int v8; // r4
  int v9; // r3
  int v10; // r2
  int v11; // r3
  int v12; // r0
  unsigned int **v14; // r0
  int (__fastcall *v15)(int, int); // r2
  int v16; // r3
  int v17; // r10
  unsigned int *v18; // r1
  unsigned int v19; // r2
  unsigned int *v20; // r1
  unsigned int v21; // r0
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25; // r0
  int v26; // r0
  unsigned int v27; // r2
  unsigned int *v28; // r0
  unsigned int v29; // r3
  unsigned int v30; // r3
  unsigned int *v31; // r0
  unsigned int v32; // r1
  int v33; // r0
  int v34; // r2
  char v35[4]; // [sp+8h] [bp-38h] BYREF
  unsigned int *v36; // [sp+Ch] [bp-34h] BYREF
  int v37; // [sp+10h] [bp-30h]
  int v38; // [sp+14h] [bp-2Ch] BYREF
  int v39[10]; // [sp+18h] [bp-28h] BYREF

  v37 = 0;
  v38 = 0;
  v36 = 0;
  v2 = 0;
  v35[0] = 0;
  v3 = 0;
  v4 = 0;
  v39[0] = 0;
  v7 = 0;
  v8 = PiSwValidateCreateData();
  v9 = 0;
  if ( v8 < 0 )
    goto LABEL_32;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(__int16 *)(v10 + 0x134) - 1;
  *(_WORD *)(v10 + 308) = v11;
  v12 = ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v10, v11);
  if ( a2 )
  {
    v7 = *(_DWORD *)(a2 + 96);
    if ( *(_DWORD *)(*(_DWORD *)(v7 + 28) + 16) )
      return sub_7E0720(v12);
  }
  v8 = PiSwDeviceCreate(&v38);
  if ( v8 >= 0 )
  {
    v8 = PiSwInstanceInfoInit(v38 + 8, a1);
    if ( v8 >= 0 )
    {
      v14 = (unsigned int **)RtlInsertElementGenericTableAvl((int)&PiSwDeviceInstanceTable, (int)&v38, 4, (int)v35);
      v17 = (unsigned __int8)v35[0];
      if ( !v14 )
      {
        v8 = -1073741670;
LABEL_27:
        if ( v8 >= 0 )
        {
LABEL_28:
          v4 = v37;
          goto LABEL_29;
        }
        goto LABEL_48;
      }
      v18 = *v14;
      v36 = *v14;
      if ( v35[0] )
      {
        v38 = 0;
        __dmb(0xBu);
        do
          v19 = __ldrex(v18);
        while ( __strex(v19 + 1, v18) );
        __dmb(0xBu);
        v8 = PiSwPnPInfoInit(v36 + 4, a1);
        if ( v8 < 0 )
          goto LABEL_48;
        v36[21] = a1[11];
        if ( a1[12] )
        {
          v25 = ExAllocatePoolWithTag(1, a1[11], 1466986064);
          v36[20] = v25;
          v16 = (int)v36;
          v26 = v36[20];
          if ( !v26 )
          {
            v8 = -1073741670;
            goto LABEL_48;
          }
          memmove(v26, a1[12], a1[11]);
        }
        v8 = PnpCopyDevPropertyArray(a1[13], a1[14]);
        if ( v8 < 0 || (v8 = PiSwBusRelationAdd(a1[1], v36), v8 < 0) )
        {
LABEL_48:
          if ( v17 )
          {
            RtlDeleteElementGenericTableAvl((int)&PiSwDeviceInstanceTable, (int)&v36, (int)v15, v16);
            PiSwDeviceDereference(v36);
            if ( v36[15] )
              PiSwBusRelationRemove();
          }
          goto LABEL_28;
        }
        goto LABEL_15;
      }
      __dmb(0xBu);
      do
        v27 = __ldrex(v18);
      while ( __strex(v27 + 1, v18) );
      __dmb(0xBu);
      v28 = v36;
      v29 = v36[1];
      if ( (v29 & 1) != 0 )
      {
        v8 = -1073741771;
LABEL_56:
        v4 = 0;
        goto LABEL_29;
      }
      if ( (v29 & 2) != 0 )
      {
        v8 = PiSwQueuedCreateInfoCreate(v36 + 12, a1);
        if ( v8 >= 0 )
          goto LABEL_16;
        goto LABEL_56;
      }
      v30 = v36[16];
      if ( v30 && (*(_DWORD *)(*(_DWORD *)(v30 + 40) + 4) & 2) == 0 )
      {
        if ( !PiSwDoesCreateChangesRequireReEnum() )
        {
          v8 = PnpCopyDevPropertyArray(a1[13], a1[14]);
          if ( v8 >= 0 )
          {
            v31 = v36;
            v32 = v36[22];
            if ( v32 )
            {
              PnpFreeDevPropertyArray(v36[23], v32);
              v31 = v36;
            }
            v31[23] = v39[1];
            v36[22] = v39[2];
            goto LABEL_17;
          }
          goto LABEL_56;
        }
        v28 = v36;
      }
      if ( v28[12] )
      {
        PiSwQueuedCreateInfoFree(v28[12]);
        v36[12] = 0;
        v28 = v36;
      }
      v8 = PiSwQueuedCreateInfoCreate(v28 + 12, a1);
      if ( v8 >= 0 )
      {
        v36[1] |= 2u;
LABEL_15:
        v2 = PnpDeviceObjectFromDeviceInstance(v36[15]);
LABEL_16:
        v3 = 1;
LABEL_17:
        if ( a2 )
        {
          if ( v3 )
          {
            __dmb(0xBu);
            v15 = PiSwIrpCancelStartCreate;
            v20 = (unsigned int *)(a2 + 56);
            do
              v21 = __ldrex(v20);
            while ( __strex((unsigned int)PiSwIrpCancelStartCreate, v20) );
            __dmb(0xBu);
            v16 = *(unsigned __int8 *)(a2 + 36);
            if ( *(_BYTE *)(a2 + 36) )
            {
              v8 = -1073741536;
              goto LABEL_48;
            }
            v36[19] = a2;
            *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
          }
          else
          {
            v8 = RtlStringCbCopyW(*(_DWORD *)(a2 + 12), *(_DWORD *)(v7 + 8));
            if ( v8 < 0 )
              goto LABEL_48;
            v33 = RtlStringCbLengthW(*(_DWORD *)(a2 + 12), *(_DWORD *)(v7 + 8), v39);
            v16 = v39[0];
            v8 = v33;
            v37 = v39[0];
            if ( v33 < 0 )
              goto LABEL_48;
          }
        }
        v15 = (int (__fastcall *)(int, int))v36;
        v16 = v36[1] | 1;
        v36[1] = v16;
        if ( a2 )
        {
          v15 = *(int (__fastcall **)(int, int))(v7 + 28);
          *((_DWORD *)v15 + 4) = v36;
          v16 = 0;
          v36 = 0;
        }
        if ( v2 )
          IoInvalidateDeviceRelations(v2, 5);
        goto LABEL_27;
      }
      goto LABEL_56;
    }
  }
LABEL_29:
  v22 = ExReleaseResourceLite((int)&PiSwLockObj);
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    KiCheckForKernelApcDelivery(v22);
  if ( !v3 && v8 >= 0 )
  {
    v34 = a1[14];
    if ( v34 )
    {
      v8 = PiSwPropertySet(*(unsigned __int16 **)(a2 + 12), 1, v34, a1[13]);
      if ( v8 == -1073741772 )
        v8 = 0;
    }
  }
  v9 = 0;
LABEL_32:
  if ( !a2 )
  {
    if ( v8 >= 0 )
    {
      v36[24] = 1;
      PiSwIrpCleanup(v36);
    }
    goto LABEL_36;
  }
  if ( v8 < 0 )
    goto LABEL_82;
  if ( !v3 )
  {
    v9 = v4 + 2;
LABEL_82:
    *(_DWORD *)(a2 + 24) = v8;
    *(_DWORD *)(a2 + 28) = v9;
    IofCompleteRequest(a2, 0);
    goto LABEL_36;
  }
  v8 = 259;
LABEL_36:
  if ( v36 )
    PiSwDeviceDereference(v36);
  if ( v38 )
    PiSwDeviceDereference(v38);
  if ( v2 )
    ObfDereferenceObject(v2);
  return v8;
}
