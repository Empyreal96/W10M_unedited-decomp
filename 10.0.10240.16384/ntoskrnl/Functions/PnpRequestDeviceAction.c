// PnpRequestDeviceAction 
 
int __fastcall PnpRequestDeviceAction(int *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r9
  int v8; // r6
  int v9; // r8
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  _DWORD *v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r0
  int v24; // r8
  unsigned int v25; // r2
  int **v26; // r1
  int *v28; // [sp+0h] [bp-48h] BYREF
  int *v29; // [sp+4h] [bp-44h]
  int v30; // [sp+8h] [bp-40h]
  int v31; // [sp+Ch] [bp-3Ch]
  int v32; // [sp+10h] [bp-38h]
  int v33; // [sp+14h] [bp-34h]
  int v34; // [sp+18h] [bp-30h]
  int v35; // [sp+1Ch] [bp-2Ch]
  int v36; // [sp+20h] [bp-28h]
  int v37; // [sp+24h] [bp-24h]
  int *varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v31 = a4;
  v32 = a3;
  varg_r1 = a2;
  v28 = a1;
  v29 = a1;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v7 = 0;
  v33 = 0;
  if ( dword_630874 )
    return -1073741431;
  v8 = ExAllocatePoolWithTag(512, 48, 846229072);
  v30 = v8;
  if ( !v8 )
    return -1073741670;
  v9 = (int)v28;
  if ( !v28 )
  {
    v9 = *(_DWORD *)(IopRootDeviceNode + 16);
    v29 = (int *)v9;
  }
  ObfReferenceObjectWithTag(v9);
  *(_DWORD *)(v8 + 8) = v9;
  *(_DWORD *)(v8 + 12) = a2;
  *(_BYTE *)(v8 + 16) = v32;
  *(_DWORD *)(v8 + 20) = v31;
  *(_DWORD *)(v8 + 24) = a5;
  *(_DWORD *)(v8 + 28) = a6;
  if ( !a2 )
    goto LABEL_15;
  if ( a2 != 6 )
  {
    if ( a2 <= 8 )
    {
LABEL_14:
      v10 = 1;
      goto LABEL_16;
    }
    if ( a2 > 10 && a2 != 14 )
    {
      if ( a2 <= 16 || a2 > 18 )
        goto LABEL_14;
LABEL_15:
      v10 = 0;
LABEL_16:
      if ( v10 )
      {
        if ( (__get_CPSR() & 0x80) != 0 )
        {
          v11 = 0;
        }
        else
        {
          __disable_irq();
          v11 = 1;
        }
        v12 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
        if ( v11 )
          __enable_irq();
        if ( (v12 & 0x10001) == 0 )
        {
          v28 = 0;
          EtwActivityIdControlKernel(1, &v28);
          if ( v28 )
          {
            v13 = v28[1];
            v14 = v28[2];
            v15 = v28[3];
            v34 = *v28;
            v35 = v13;
            v36 = v14;
            v37 = v15;
          }
          else if ( PnpIsSafeToExamineUserModeTeb() && PsGetCurrentThreadTeb() )
          {
            v16 = (_DWORD *)PsGetCurrentThreadTeb();
            v17 = v16[981];
            v18 = v16[982];
            v19 = v16[983];
            v34 = v16[980];
            v35 = v17;
            v36 = v18;
            v37 = v19;
          }
        }
      }
      goto LABEL_28;
    }
  }
LABEL_28:
  v20 = v35;
  v21 = v36;
  v22 = v37;
  *(_DWORD *)(v8 + 32) = v34;
  *(_DWORD *)(v8 + 36) = v20;
  *(_DWORD *)(v8 + 40) = v21;
  *(_DWORD *)(v8 + 44) = v22;
  if ( v9 )
    v23 = *(_DWORD *)(*(_DWORD *)(v9 + 176) + 20);
  else
    v23 = 0;
  PnpLogActionQueueEvent(v23, a2, 0);
  v24 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(&PnpSpinLock);
  }
  else
  {
    do
      v25 = __ldrex((unsigned int *)&PnpSpinLock);
    while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
    __dmb(0xBu);
    if ( v25 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
  }
  v26 = (int **)dword_62FB84;
  *(_DWORD *)v8 = &PnpEnumerationRequestList;
  *(_DWORD *)(v8 + 4) = v26;
  if ( *v26 != &PnpEnumerationRequestList )
    __fastfail(3u);
  *v26 = (int *)v8;
  dword_62FB84 = v8;
  if ( a2 == 7 || a2 == 10 )
  {
    PnpEnumerationInProgress = 1;
    KeResetEvent((int)&PnpEnumerationLock);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PnpSpinLock);
    }
    else
    {
      __dmb(0xBu);
      PnpSpinLock = 0;
    }
    KfLowerIrql(v24);
    PnpDeviceActionWorker();
  }
  else if ( !PnPBootDriversLoaded || PnpEnumerationInProgress )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PnpSpinLock);
    }
    else
    {
      __dmb(0xBu);
      PnpSpinLock = 0;
    }
    KfLowerIrql(v24);
  }
  else
  {
    PnpEnumerationInProgress = 1;
    KeResetEvent((int)&PnpEnumerationLock);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PnpSpinLock);
    }
    else
    {
      __dmb(0xBu);
      PnpSpinLock = 0;
    }
    KfLowerIrql(v24);
    dword_62FBB8 = (int)PnpDeviceActionWorker;
    dword_62FBBC = 0;
    PnpDeviceEnumerationWorkItem = 0;
    ExQueueWorkItem(&PnpDeviceEnumerationWorkItem, 1);
  }
  return v7;
}
