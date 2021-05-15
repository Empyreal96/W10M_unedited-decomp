// NtWaitForWorkViaWorkerFactory 
 
int __fastcall NtWaitForWorkViaWorkerFactory(int a1, int a2, unsigned int a3, _DWORD *a4, int *a5)
{
  unsigned int v5; // r9
  int v6; // lr
  _DWORD *v7; // r5
  int v8; // r10
  char v9; // r4
  int v10; // r0
  _DWORD *v11; // r2
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r6
  _DWORD *v19; // r2
  int v20; // r3
  int v22; // [sp+10h] [bp-C0h] BYREF
  char v23; // [sp+14h] [bp-BCh]
  _DWORD *v24; // [sp+18h] [bp-B8h]
  _DWORD *v25; // [sp+1Ch] [bp-B4h]
  _DWORD *v26; // [sp+20h] [bp-B0h] BYREF
  _DWORD *v27; // [sp+24h] [bp-ACh]
  int v28; // [sp+28h] [bp-A8h]
  _DWORD *v29; // [sp+2Ch] [bp-A4h]
  int v30; // [sp+30h] [bp-A0h]
  unsigned int v31; // [sp+34h] [bp-9Ch]
  _BYTE v32[8]; // [sp+38h] [bp-98h] BYREF
  int v33; // [sp+40h] [bp-90h]
  int v34; // [sp+44h] [bp-8Ch]
  int v35; // [sp+48h] [bp-88h]
  int v36; // [sp+4Ch] [bp-84h]
  unsigned int v37; // [sp+50h] [bp-80h]
  int v38[6]; // [sp+58h] [bp-78h] BYREF
  _DWORD _70[30]; // [sp+70h] [bp-60h] BYREF

  _70[26] = a1;
  _70[27] = a2;
  _70[29] = a4;
  v27 = a4;
  v5 = a3;
  _70[28] = a3;
  v28 = a2;
  v6 = a1;
  v30 = a1;
  v38[4] = a1;
  v38[3] = a2;
  v26 = a4;
  v22 = 0;
  v7 = 0;
  v29 = 0;
  v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v37 = v31;
  v8 = *(char *)(v31 + 0x15A);
  v23 = *(_BYTE *)(v31 + 0x15A);
  v24 = _70;
  v25 = _70;
  v9 = 0;
  v36 = 0;
  if ( a3 && a3 <= 0xFFFFFFF )
  {
    if ( v8 )
    {
      v10 = ProbeForWrite(v28, 16 * a3, 4);
      v11 = v27;
      if ( (unsigned int)v27 >= MmUserProbeAddress )
        v11 = (_DWORD *)MmUserProbeAddress;
      *v11 = *v11;
      if ( ((unsigned __int8)a5 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v10);
      if ( (unsigned int)(a5 + 4) > MmUserProbeAddress || a5 + 4 < a5 )
        *(_BYTE *)MmUserProbeAddress = 0;
      v12 = a5[1];
      v13 = a5[2];
      v14 = a5[3];
      v33 = *a5;
      v34 = v12;
      v35 = v13;
      v36 = v14;
      v9 = v14;
      v6 = v30;
    }
    else
    {
      v15 = a5[1];
      v16 = a5[2];
      v17 = a5[3];
      v33 = *a5;
      v34 = v15;
      v35 = v16;
      v36 = v17;
      v9 = v17;
    }
    v18 = ObReferenceObjectByHandle(v6, 2, ExpWorkerFactoryObjectType, v8, &v26, 0);
    v7 = v26;
    v29 = v26;
    if ( v18 >= 0 )
    {
      if ( v5 > 0x10 )
      {
        v24 = (_DWORD *)ExAllocatePoolWithTag(512, 4 * v5, 1701736270);
        v25 = v24;
        if ( !v24 )
        {
          v5 = 16;
          v24 = _70;
          v25 = _70;
        }
      }
      KeAcquireInStackQueuedSpinLock(v7[1], v38);
      if ( *(_BYTE *)(v7[1] + 21) )
      {
        KeReleaseInStackQueuedSpinLock(v38);
        v18 = 128;
        goto LABEL_46;
      }
      if ( (v7[22] & 0x200) != 0 )
        ExpLeaveWorkerFactoryAwayMode((int)v7);
      ++*(_DWORD *)(v7[1] + 16);
      while ( v7[15] >= v7[16] && !*(_BYTE *)(v7[1] + 21) )
      {
        KeReleaseInStackQueuedSpinLock(v38);
        ExpWorkerFactoryStartDeferredWork((int)v32, v8);
        v18 = IoRemoveIoCompletion(*(_DWORD *)(v7[1] + 4), v28, v24, v5, &v22, v8, 0, 1);
        ExpWorkerFactoryFinishDeferredWork((int)v32);
        KeAcquireInStackQueuedSpinLock(v7[1], v38);
        if ( v18 == 258 )
        {
          if ( !v7[20] && v7[16] < (unsigned int)(v7[15] + 1) )
          {
            v19 = (_DWORD *)v7[1];
            if ( v19[4] <= 1u && (*(_DWORD *)(v19[1] + 4) || v19[3]) )
              continue;
          }
          if ( v7[16] <= v7[14] || *(_DWORD *)(v31 + 908) != v31 + 908 )
            continue;
        }
        goto LABEL_34;
      }
      v18 = 258;
LABEL_34:
      --*(_DWORD *)(v7[1] + 16);
      if ( v18 == 258 )
      {
        --v7[16];
        --v7[17];
        ExpRemoveCurrentThreadFromThreadHistory((unsigned int)v7);
      }
      else
      {
        ExpAddCurrentThreadToThreadHistory((unsigned int)v7);
      }
      if ( ExpTryEnterWorkerFactoryAwayMode(v7) )
        ExpWorkerFactoryCheckCreate(v7, v38, 0, v20);
      else
        KeReleaseInStackQueuedSpinLock(v38);
      if ( !v18 )
      {
        if ( v8 )
        {
          *v27 = v22;
          v9 = v36;
          goto LABEL_46;
        }
        *v27 = v22;
      }
      v9 = v36;
    }
  }
  else
  {
    v18 = -1073741811;
  }
LABEL_46:
  if ( v24 != _70 )
    ExFreePoolWithTag(v24, 0);
  if ( v7 )
    ObfDereferenceObject(v7);
  if ( (v9 & 1) != 0 )
    NtAlpcSendWaitReceivePort(v34, v35, v33, 0, 0, 0, 0, 0);
  return v18;
}
