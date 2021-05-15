// IopCompleteUnloadOrDelete 
 
int __fastcall IopCompleteUnloadOrDelete(_DWORD *a1, int a2, int a3)
{
  int v4; // r6
  int v5; // r3
  int v7; // r10
  int v8; // r8
  int v9; // r9
  int v11; // r4
  int v12; // r10
  int v13; // r0
  _DWORD *v14; // r8
  int v15; // r0
  void (__fastcall *v16)(int, _DWORD *); // r8
  int v17; // r7
  _DWORD *v18; // r1
  _DWORD *v19; // r2
  int v20; // r3
  int v22[4]; // [sp+10h] [bp-48h] BYREF
  char v23[4]; // [sp+20h] [bp-38h] BYREF
  int v24; // [sp+24h] [bp-34h]
  int v25[12]; // [sp+28h] [bp-30h] BYREF

  v4 = a1[2];
  v5 = *(_DWORD *)(a1[44] + 16);
  v7 = a2;
  v8 = 0;
  v9 = 1;
  if ( (v5 & 4) != 0 )
    return sub_527EAC();
  v11 = 1;
  if ( (v5 & 2) == 0 )
    goto LABEL_29;
  if ( (v5 & 1) == 0 || (*(_DWORD *)(v4 + 8) & 1) != 0 )
    v9 = 0;
  v12 = a1[4];
  if ( v12 )
  {
    v14 = *(_DWORD **)(*(_DWORD *)(v12 + 8) + 40);
    IopIncrementDeviceObjectRefCount((int)a1, 0);
    v15 = KeReleaseQueuedSpinLock(10, a3);
    if ( v14 )
    {
      if ( *v14 > 0x34u )
      {
        v16 = (void (__fastcall *)(int, _DWORD *))v14[13];
        if ( v16 )
        {
          v17 = (MmVerifierData & 0x10) != 0 ? VfFastIoSnapState(v15) : 0;
          v16(v12, a1);
          if ( v17 )
            VfFastIoCheckState(v17, v16);
        }
      }
    }
    a3 = KeAcquireQueuedSpinLock(10);
    IopDecrementDeviceObjectRefCount(a1, 0);
    if ( a1[4] || a1[1] )
    {
      v11 = 0;
LABEL_21:
      KeReleaseQueuedSpinLock(10, a3);
      return v11;
    }
  }
  KeReleaseQueuedSpinLock(10, a3);
  v13 = a1[38];
  if ( v13 )
    ObDereferenceSecurityDescriptor(v13, 1);
  IopInsertRemoveDevice(a1[2], a1, 0);
  ObfDereferenceObject((int)a1);
  v8 = 1;
  if ( v9 )
  {
    a3 = KeAcquireQueuedSpinLock(10);
    if ( (*(_DWORD *)(v4 + 8) & 1) != 0 )
      goto LABEL_21;
    v7 = a2;
LABEL_29:
    v18 = *(_DWORD **)(v4 + 4);
    v19 = v18;
    if ( v18 )
    {
      while ( !v19[1] && !v19[4] && (*(_DWORD *)(v19[44] + 16) & 6) == 0 )
      {
        v19 = (_DWORD *)v19[3];
        if ( !v19 )
          goto LABEL_36;
      }
      v9 = 0;
    }
LABEL_36:
    v20 = *(_DWORD *)(v4 + 8);
    if ( (v20 & 0x80) != 0 && v18 )
      v9 = 0;
    if ( v9 )
      *(_DWORD *)(v4 + 8) = v20 | 1;
    KeReleaseQueuedSpinLock(10, a3);
    if ( v9 )
    {
      v23[0] = 0;
      v23[1] = 0;
      v23[2] = 4;
      v24 = 0;
      v25[1] = (int)v25;
      v25[2] = v4;
      v25[0] = (int)v25;
      if ( v7 )
      {
        IopLoadUnloadDriver(v22);
      }
      else
      {
        v22[2] = (int)IopLoadUnloadDriver;
        v22[3] = (int)v22;
        v22[0] = 0;
        ExQueueWorkItem(v22, 1);
        KeWaitForSingleObject((unsigned int)v23, 0, 0, 0, 0);
      }
      ObMakeTemporaryObject(v4);
      ObfDereferenceObject(v4);
    }
    return v8;
  }
  return 1;
}
