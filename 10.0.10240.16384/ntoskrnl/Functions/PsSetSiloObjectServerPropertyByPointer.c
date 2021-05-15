// PsSetSiloObjectServerPropertyByPointer 
 
int __fastcall PsSetSiloObjectServerPropertyByPointer(int a1, _DWORD *a2)
{
  int v4; // r4
  int v5; // r4
  _BYTE *v6; // r0
  _DWORD *v7; // r6
  int v8; // r0
  int v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v21[10]; // [sp+8h] [bp-58h] BYREF
  char v22[4]; // [sp+30h] [bp-30h] BYREF
  int v23; // [sp+34h] [bp-2Ch]
  int v24[4]; // [sp+38h] [bp-28h] BYREF
  int v25; // [sp+48h] [bp-18h]

  v4 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( PsIsCurrentThreadInServerSilo() || !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v4) )
    return -1073741727;
  if ( *(_DWORD *)(a1 + 84) )
    return -1073741811;
  v6 = (_BYTE *)ExAllocatePoolWithTag(512, 68);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  memset(v6, 0, 68);
  *v7 = -1;
  v5 = PspAllocateMonitorContextArrayServerSilo(v7);
  v8 = a1;
  if ( v5 < 0 )
  {
LABEL_10:
    PspServerSiloDelete(v8);
    return v5;
  }
  v9 = ObGetRootDirectoryNameByPointer(a1, v7 + 1);
  v5 = v9;
  if ( v9 < 0 )
    goto LABEL_12;
  KeQuerySystemTime(v21);
  v21[4] = 24;
  v21[5] = 0;
  v21[6] = (int)(v7 + 1);
  v21[7] = 576;
  v21[8] = 0;
  v21[9] = 0;
  v5 = ZwOpenDirectoryObject();
  if ( v5 < 0 )
  {
LABEL_12:
    v8 = a1;
    goto LABEL_10;
  }
  v7[15] = *a2;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(__int16 *)(v10 + 0x136) - 1;
  *(_WORD *)(v10 + 310) = v11;
  ExAcquireResourceExclusiveLite(a1 + 28, 1, v10, v11);
  if ( *(_DWORD *)(a1 + 144) )
  {
    PspServerSiloDelete(a1);
    v5 = -1073741791;
  }
  else
  {
    *(_DWORD *)(a1 + 144) = v7;
    v7[14] = 1;
    ObfReferenceObject(a1);
  }
  v12 = ExpReleaseResourceForThreadLite(a1 + 28, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x136) + 1;
  *(_WORD *)(v13 + 310) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 )
    KiCheckForKernelApcDelivery(v12);
  if ( v5 >= 0 )
  {
    if ( PsIsSystemProcess(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74)) )
    {
      v5 = PspInitializeServerSiloDeferred(a1);
    }
    else
    {
      v22[0] = 1;
      v22[1] = 0;
      v22[2] = 4;
      v23 = 0;
      v24[1] = (int)v24;
      v24[0] = (int)v24;
      v24[2] = (int)PspInitializeServerSiloDeferred;
      v24[3] = a1;
      v25 = 0;
      v21[2] = (int)PspDeferredWorkerRoutine;
      v21[3] = (int)v22;
      v21[0] = 0;
      ExQueueWorkItem(v21, 1);
      KeWaitForSingleObject((unsigned int)v22, 6, 0, 0, 0);
      v5 = v25;
    }
    if ( v5 < 0 )
    {
      v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v16 = *(__int16 *)(v15 + 0x136) - 1;
      *(_WORD *)(v15 + 310) = v16;
      ExAcquireResourceExclusiveLite(a1 + 28, 1, v15, v16);
      v7[14] = 3;
      v17 = ExpReleaseResourceForThreadLite(a1 + 28, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = *(_WORD *)(v18 + 0x136) + 1;
      *(_WORD *)(v18 + 310) = v19;
      if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 )
        KiCheckForKernelApcDelivery(v17);
      ObfDereferenceObjectWithTag(a1);
    }
  }
  return v5;
}
