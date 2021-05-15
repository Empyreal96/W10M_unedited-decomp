// NtCreateWorkerFactory 
 
int __fastcall NtCreateWorkerFactory(unsigned int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  _DWORD *v11; // r8
  _DWORD *v12; // r4
  int v13; // r0
  unsigned int v14; // r6
  int v15; // r4
  int v16; // r0
  int v17; // r3
  int v18; // r10
  int v19; // r0
  int v20; // r1
  int v21; // r0
  int v22; // r5
  int v23; // r3
  int v24; // r3
  __int64 v25; // r0
  int v26; // r0
  char v28; // [sp+18h] [bp-50h]
  int v30; // [sp+20h] [bp-48h] BYREF
  int v31; // [sp+24h] [bp-44h]
  _DWORD v32[2]; // [sp+28h] [bp-40h] BYREF
  int v33; // [sp+30h] [bp-38h] BYREF
  _DWORD _38[18]; // [sp+38h] [bp-30h] BYREF

  _38[17] = a4;
  _38[16] = a3;
  v31 = a2;
  _38[15] = a2;
  v11 = (_DWORD *)a1;
  _38[14] = a1;
  v28 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v28 )
  {
    v12 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v12 = (_DWORD *)MmUserProbeAddress;
    *v12 = *v12;
  }
  v13 = ExAllocatePoolWithQuotaTag(0x208u, 0x18u, 1666674772);
  v14 = v13;
  if ( !v13 )
    return -1073741801;
  *(_DWORD *)v13 = 0;
  *(_DWORD *)(v13 + 12) = 0;
  *(_DWORD *)(v13 + 16) = 0;
  *(_BYTE *)(v13 + 20) = 0;
  *(_BYTE *)(v13 + 21) = 0;
  *(_BYTE *)(v13 + 22) = 0;
  v15 = ObReferenceObjectByHandle(a4, 2, IoCompletionObjectType, v28, v32);
  v16 = v32[0];
  *(_DWORD *)(v14 + 4) = v32[0];
  if ( v15 < 0 )
  {
LABEL_25:
    ExFreePoolWithTag(v14);
    return v15;
  }
  KeDisableQueueingPriorityIncrement(v16);
  v15 = ObReferenceObjectByHandleWithTag(a5, 42, PsProcessType, v28, 1717008453, v32, 0);
  if ( v15 < 0 )
  {
LABEL_24:
    ObfDereferenceObject(*(_DWORD *)(v14 + 4));
    goto LABEL_25;
  }
  v17 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v18 = v32[0];
  if ( v17 != v32[0] )
  {
    v15 = -1073741811;
LABEL_23:
    ObfDereferenceObjectWithTag(v18);
    goto LABEL_24;
  }
  v15 = ObOpenObjectByPointer(v32[0], 512, 0, 42, PsProcessType, 0, &v30);
  if ( v15 < 0 )
    goto LABEL_23;
  v19 = IoAllocateMiniCompletionPacket(ExpWorkerFactoryCompletionPacketRoutine, v14);
  *(_DWORD *)(v14 + 8) = v19;
  if ( !v19 )
  {
    v15 = -1073741801;
LABEL_16:
    ObCloseHandle(v30);
    goto LABEL_23;
  }
  v15 = ObCreateObject(v28, ExpWorkerFactoryObjectType, a3, v28, 0, 248, 0, 0, v32);
  if ( v15 < 0 )
  {
    v21 = *(_DWORD *)(v14 + 8);
    *(_DWORD *)(v21 + 28) = 0;
    IopFreeMiniCompletionPacket(v21, v20);
    goto LABEL_16;
  }
  v22 = v32[0];
  *(_DWORD *)(v32[0] + 4) = v14;
  *(_QWORD *)(v22 + 48) = -10000000i64 * ExpWorkerFactoryThreadIdleTimeoutInSeconds;
  *(_DWORD *)(v22 + 56) = 0;
  *(_DWORD *)(v22 + 60) = a8;
  *(_DWORD *)(v22 + 76) = 0;
  *(_DWORD *)(v22 + 64) = 0;
  *(_DWORD *)(v22 + 68) = 0;
  v23 = a9;
  if ( !a9 )
    v23 = 0x10000;
  *(_DWORD *)(v22 + 24) = v23;
  v24 = a10;
  if ( !a10 )
    v24 = 4096;
  *(_DWORD *)(v22 + 92) = 0;
  *(_DWORD *)(v22 + 28) = v24;
  *(_DWORD *)(v22 + 8) = a6;
  *(_DWORD *)(v22 + 12) = a7;
  *(_DWORD *)(v22 + 80) = 0;
  *(_DWORD *)(v22 + 88) = 0;
  *(_DWORD *)(v22 + 84) = 0;
  *(_DWORD *)(v22 + 96) = 0;
  *(_DWORD *)(v22 + 16) = v30;
  *(_DWORD *)(v22 + 20) = v18;
  *(_DWORD *)(v22 + 72) = 0;
  *(_DWORD *)(v22 + 244) = 0;
  *(_DWORD *)(v22 + 216) = 1;
  KeInitializeTimer2(v22 + 104, 0, 0, 8);
  LODWORD(v25) = v22;
  v26 = ExpInitializeThreadHistory(v25);
  v15 = ObInsertObject(v26, 0, v31, 0, 0, &v33);
  v31 = v15;
  if ( v15 >= 0 )
  {
    *v11 = v33;
    ObfReferenceObject(v22);
    KeRegisterObjectNotification(v22 + 104, (unsigned int)&ExpWorkerFactoryManagerQueue, v22 + 192);
    _38[0] = 0;
    _38[1] = 0;
    _38[2] = -1;
    _38[3] = -1;
    KeSetTimer2((int *)(v22 + 104), *(_QWORD *)(v22 + 48), -*(_QWORD *)(v22 + 48), (int)_38);
  }
  return v15;
}
