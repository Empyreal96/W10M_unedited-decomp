// PnpDeviceActionWorker 
 
int PnpDeviceActionWorker()
{
  int v0; // r3
  unsigned int v1; // r1
  int v2; // r9
  int v3; // r10
  int v4; // r7
  int v5; // r4
  unsigned int v7; // r2
  int v8; // r6
  __int64 v9; // r2
  int v10; // r0
  int v11; // r5
  int v12; // r3
  int v13; // r0
  int v14; // r0
  int v15; // r5
  int *v16; // r4
  __int64 v17; // r2
  int *v18; // r3
  int v19; // r0
  unsigned int v20; // r2
  int v21; // r3
  int v22; // r0
  int v23; // r0
  int v24; // r1
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // [sp+10h] [bp-68h] BYREF
  int v29; // [sp+14h] [bp-64h]
  int v30; // [sp+18h] [bp-60h]
  int v31; // [sp+20h] [bp-58h] BYREF
  char v32; // [sp+24h] [bp-54h]
  _DWORD v33[8]; // [sp+28h] [bp-50h] BYREF
  _DWORD v34[12]; // [sp+48h] [bp-30h] BYREF

  v0 = __mrc(15, 0, 13, 0, 3);
  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&PnpDeviceActionThread);
  while ( __strex(v0 & 0xFFFFFFC0, (unsigned int *)&PnpDeviceActionThread) );
  __dmb(0xBu);
  v2 = 0;
  v3 = 0;
  v30 = 0;
  PpDevNodeLockTree(1, v1);
  while ( 1 )
  {
    v28 = 0;
    v29 = 1;
    v4 = 0;
    v5 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_51FEC0();
    do
      v7 = __ldrex((unsigned int *)&PnpSpinLock);
    while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
    v8 = PnpEnumerationRequestList;
    if ( (int *)PnpEnumerationRequestList == &PnpEnumerationRequestList )
      break;
    v9 = *(_QWORD *)PnpEnumerationRequestList;
    if ( *(int **)(PnpEnumerationRequestList + 4) != &PnpEnumerationRequestList
      || *(_DWORD *)(v9 + 4) != PnpEnumerationRequestList )
    {
      __fastfail(3u);
    }
    PnpEnumerationRequestList = *(_DWORD *)PnpEnumerationRequestList;
    *(_DWORD *)(v9 + 4) = &PnpEnumerationRequestList;
LABEL_13:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PnpSpinLock);
    }
    else
    {
      __dmb(0xBu);
      PnpSpinLock = 0;
    }
    v10 = KfLowerIrql(v5);
    if ( v8 )
    {
      if ( memcmp((unsigned int)&NullGuid, v8 + 32, 16) )
      {
        v28 = (int)v34;
        v25 = *(_DWORD *)(v8 + 36);
        v26 = *(_DWORD *)(v8 + 40);
        v27 = *(_DWORD *)(v8 + 44);
        v34[0] = *(_DWORD *)(v8 + 32);
        v34[1] = v25;
        v34[2] = v26;
        v34[3] = v27;
        EtwActivityIdControlKernel(2, &v28);
        v28 = 1;
      }
      *(_DWORD *)v8 = v8;
      *(_DWORD *)(v8 + 4) = v8;
      if ( dword_630874 )
      {
        v4 = -1073741431;
      }
      else
      {
        v11 = *(_DWORD *)(v8 + 8);
        if ( v11 )
          v12 = *(_DWORD *)(*(_DWORD *)(v11 + 176) + 20);
        else
          v12 = 0;
        if ( *(_DWORD *)(v12 + 172) == 788 )
        {
LABEL_75:
          v4 = -1073741823;
        }
        else
        {
          switch ( *(_DWORD *)(v8 + 12) )
          {
            case 0:
              v2 = 1;
              break;
            case 1:
            case 3:
              v14 = PiProcessClearDeviceProblem(v8);
              goto LABEL_26;
            case 2:
              v14 = PpProcessClearProblem(v8);
              goto LABEL_26;
            case 4:
              v14 = PiProcessHaltDevice(v8);
              goto LABEL_26;
            case 5:
              if ( v11 )
                v22 = *(_DWORD *)(*(_DWORD *)(v11 + 176) + 20);
              else
                v22 = 0;
              v14 = PiQueryPowerRelations(v22, 0);
              goto LABEL_26;
            case 6:
              v14 = PnpProcessRebalance(v8);
              goto LABEL_26;
            case 7:
              v3 = 1;
              break;
            case 8:
            case 9:
            case 0xA:
            case 0xE:
              v13 = PiProcessReenumeration(v8);
              goto LABEL_24;
            case 0xB:
              v14 = PiProcessRequeryDeviceState(v8);
              goto LABEL_26;
            case 0xC:
            case 0x10:
              v14 = PiRestartDevice(v8);
              goto LABEL_26;
            case 0xD:
              v4 = PiProcessResourceRequirementsChanged(v8);
              if ( v4 < 0 )
              {
                v2 = 1;
                v4 = 0;
              }
              break;
            case 0xF:
              v14 = PiProcessSetDeviceProblem(v8);
              goto LABEL_26;
            case 0x11:
              v13 = PiProcessStartSystemDevices(v8);
LABEL_24:
              v29 = 0;
              v4 = v13;
              break;
            case 0x12:
              v30 = 1;
              break;
            case 0x13:
              memset(v33, 0, sizeof(v33));
              v33[0] = 1835009;
              v33[1] = -51042058;
              v33[2] = 1202825263;
              v33[3] = 1350580909;
              v33[4] = 682445913;
              v33[5] = 0;
              v33[6] = -1;
              IoReportTargetDeviceChangeAsynchronous(v11, (int)v33, 0, 0);
              v23 = *(_DWORD *)(v8 + 8);
              v24 = 21;
              goto LABEL_72;
            case 0x14:
              v24 = 17;
              v23 = *(_DWORD *)(v8 + 8);
LABEL_72:
              PiPnpRtlPdoRaiseNtPlugPlayPropertyChangeEvent(v23, v24);
              break;
            case 0x15:
            case 0x16:
            case 0x17:
            case 0x18:
              v14 = PiConfigureDevice(v8);
LABEL_26:
              v4 = v14;
              break;
            default:
              goto LABEL_75;
          }
        }
      }
      v15 = 1;
      do
      {
        v16 = *(int **)v8;
        v17 = *(_QWORD *)*(_DWORD *)v8;
        if ( HIDWORD(v17) != v8 || *(int **)(v17 + 4) != v16 )
          __fastfail(3u);
        *(_DWORD *)v8 = v17;
        *(_DWORD *)(v17 + 4) = v8;
        v18 = (int *)v16[7];
        if ( v18 )
          *v18 = v4;
        v19 = v16[6];
        if ( v19 )
          KeSetEvent(v19, 0, 0);
        if ( v16 == (int *)v8 )
        {
          v15 = 0;
          if ( v29 )
            ObfDereferenceObject(v16[2]);
        }
        ExFreePoolWithTag(v16, 846229072);
      }
      while ( v15 );
      if ( v28 )
      {
        v28 = 0;
        EtwActivityIdControlKernel(2, &v28);
      }
    }
    else if ( v3 || v2 )
    {
      v31 = 3;
      v32 = PnPBootDriversInitialized;
      ObfReferenceObject(*(_DWORD *)(IopRootDeviceNode + 16));
      if ( v3 )
        v21 = 0;
      else
        v21 = 3;
      PipProcessDevNodeTree(IopRootDeviceNode, 0, &v31, v21, v2, 0, 0);
      v2 = 0;
      v3 = 0;
    }
    else
    {
      PnpCompleteSystemStartProcess(v10);
      v30 = 0;
    }
  }
  if ( v3 || v2 || v30 )
  {
    v8 = 0;
    goto LABEL_13;
  }
  PnpEnumerationInProgress = 0;
  KeSetEvent((int)&PnpEnumerationLock, 0, 0);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PnpSpinLock);
  }
  else
  {
    __dmb(0xBu);
    PnpSpinLock = 0;
  }
  KfLowerIrql(v5);
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)&PnpDeviceActionThread);
  while ( __strex(0, (unsigned int *)&PnpDeviceActionThread) );
  __dmb(0xBu);
  return PpDevNodeUnlockTree(1, &PnpDeviceActionThread, v20);
}
