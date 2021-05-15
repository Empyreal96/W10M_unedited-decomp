// IoReportTargetDeviceChangeAsynchronous 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IoReportTargetDeviceChangeAsynchronous(int a1, int a2, int a3, int a4)
{
  int v8; // r1
  GUID *v9; // r4
  int v11; // r4 OVERLAPPED
  int (*v12)(); // r3
  int v13; // r0
  int v14; // r2
  int v15; // r3
  int v16; // r4
  int v17; // r2
  int v18; // r2
  int v19; // r3

  if ( !a1 )
    goto LABEL_30;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v8 || (*(_DWORD *)(v8 + 268) & 0x20000) != 0 )
  {
    IoAddTriageDumpDataBlock(a1, *(unsigned __int16 *)(a1 + 2));
    v13 = *(_DWORD *)(a1 + 8);
    if ( v13 )
    {
      IoAddTriageDumpDataBlock(v13, *(__int16 *)(v13 + 2));
      v14 = *(_DWORD *)(a1 + 8);
      if ( *(_WORD *)(v14 + 28) )
      {
        IoAddTriageDumpDataBlock(v14 + 28, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 32), *(unsigned __int16 *)(*(_DWORD *)(a1 + 8) + 28));
      }
    }
    v15 = *(_DWORD *)(a1 + 176);
    v16 = *(_DWORD *)(v15 + 20);
    if ( v16 )
    {
      IoAddTriageDumpDataBlock(*(_DWORD *)(v15 + 20), 460);
      if ( *(_WORD *)(v16 + 20) )
      {
        IoAddTriageDumpDataBlock(v16 + 20, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v16 + 24), *(unsigned __int16 *)(v16 + 20));
      }
      v17 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
      if ( *(_WORD *)(v17 + 28) )
      {
        IoAddTriageDumpDataBlock(v17 + 28, 2);
        IoAddTriageDumpDataBlock(
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 32),
          *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 28));
      }
      v18 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
      if ( v18 && *(_WORD *)(v18 + 28) )
      {
        IoAddTriageDumpDataBlock(v18 + 28, 2);
        v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v19 + 32), *(unsigned __int16 *)(v19 + 28));
      }
    }
LABEL_30:
    KeBugCheckEx(202, 2, a1);
  }
  v9 = (GUID *)(a2 + 4);
  if ( (GUID *)(a2 + 4) == &GUID_TARGET_DEVICE_QUERY_REMOVE
    || RtlCompareMemory(a2 + 4) == 16
    || v9 == &GUID_TARGET_DEVICE_REMOVE_CANCELLED
    || RtlCompareMemory(a2 + 4) == 16
    || v9 == &GUID_TARGET_DEVICE_REMOVE_COMPLETE
    || RtlCompareMemory(a2 + 4) == 16
    || *(unsigned __int16 *)(a2 + 2) < 0x1Cu )
  {
    return -1073741808;
  }
  if ( *(_DWORD *)(a2 + 24) != -1 )
    return sub_51525C();
  if ( KeGetCurrentIrql() != 2 )
    return PnpSetCustomTargetEvent(a1, 0, 0, a3);
  v11 = ExAllocatePoolWithTag(512, *(unsigned __int16 *)(a2 + 2) + 32, 946892368);
  if ( !v11 )
    return -1073741670;
  ObfReferenceObjectWithTag(a1, 1953261124);
  *(_DWORD *)(v11 + 28) = v11 + 32;
  *(_DWORD *)(v11 + 16) = a1;
  memmove(v11 + 32, a2, *(unsigned __int16 *)(a2 + 2));
  v12 = PnpReportTargetDeviceChangeAsyncWorker;
  *(_DWORD *)(v11 + 20) = a3;
  *(_DWORD *)(v11 + 24) = a4;
  *(_QWORD *)(v11 + 8) = *(_QWORD *)(&v11 - 1);
  *(_DWORD *)v11 = 0;
  ExQueueWorkItem(v11, 1);
  return 259;
}
