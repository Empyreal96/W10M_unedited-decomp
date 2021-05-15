// IoReportTargetDeviceChange 
 
int __fastcall IoReportTargetDeviceChange(int a1, int a2)
{
  int v4; // r3
  GUID *v5; // r5
  unsigned int v6; // r3
  signed int v7; // r2
  int result; // r0
  int v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r5
  int v13; // r2
  int v14; // r2
  int v15; // r3
  int v16; // [sp+8h] [bp-28h] BYREF
  char v17[32]; // [sp+10h] [bp-20h] BYREF

  if ( !a1 )
    goto LABEL_28;
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v4 || (*(_DWORD *)(v4 + 268) & 0x20000) != 0 )
  {
    IoAddTriageDumpDataBlock(a1, *(unsigned __int16 *)(a1 + 2));
    v9 = *(_DWORD *)(a1 + 8);
    if ( v9 )
    {
      IoAddTriageDumpDataBlock(v9, *(__int16 *)(v9 + 2));
      v10 = *(_DWORD *)(a1 + 8);
      if ( *(_WORD *)(v10 + 28) )
      {
        IoAddTriageDumpDataBlock(v10 + 28, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 32), *(unsigned __int16 *)(*(_DWORD *)(a1 + 8) + 28));
      }
    }
    v11 = *(_DWORD *)(a1 + 176);
    v12 = *(_DWORD *)(v11 + 20);
    if ( v12 )
    {
      IoAddTriageDumpDataBlock(*(_DWORD *)(v11 + 20), 460);
      if ( *(_WORD *)(v12 + 20) )
      {
        IoAddTriageDumpDataBlock(v12 + 20, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v12 + 24), *(unsigned __int16 *)(v12 + 20));
      }
      v13 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
      if ( *(_WORD *)(v13 + 28) )
      {
        IoAddTriageDumpDataBlock(v13 + 28, 2);
        IoAddTriageDumpDataBlock(
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 32),
          *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 28));
      }
      v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
      if ( v14 && *(_WORD *)(v14 + 28) )
      {
        IoAddTriageDumpDataBlock(v14 + 28, 2);
        v15 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v15 + 32), *(unsigned __int16 *)(v15 + 28));
      }
    }
LABEL_28:
    KeBugCheckEx(202, 2, a1, 0, 0);
  }
  v5 = (GUID *)(a2 + 4);
  if ( (GUID *)(a2 + 4) == &GUID_TARGET_DEVICE_QUERY_REMOVE )
    return -1073741808;
  if ( RtlCompareMemory((unsigned __int8 *)(a2 + 4), (int)&GUID_TARGET_DEVICE_QUERY_REMOVE, 16) == 16 )
    return -1073741808;
  if ( v5 == &GUID_TARGET_DEVICE_REMOVE_CANCELLED )
    return -1073741808;
  if ( RtlCompareMemory((unsigned __int8 *)(a2 + 4), (int)&GUID_TARGET_DEVICE_REMOVE_CANCELLED, 16) == 16 )
    return -1073741808;
  if ( v5 == &GUID_TARGET_DEVICE_REMOVE_COMPLETE )
    return -1073741808;
  if ( RtlCompareMemory((unsigned __int8 *)(a2 + 4), (int)&GUID_TARGET_DEVICE_REMOVE_COMPLETE, 16) == 16 )
    return -1073741808;
  v6 = *(unsigned __int16 *)(a2 + 2);
  if ( v6 < 0x1C )
    return -1073741808;
  v7 = *(_DWORD *)(a2 + 24);
  if ( v7 != -1 && v7 > (int)(v6 - 28) )
    return -1073741808;
  KeInitializeEvent((int)v17, 0, 0);
  result = PnpSetCustomTargetEvent(a1, (int)v17, (int)&v16, 0, 0, a2);
  if ( result >= 0 )
  {
    KeWaitForSingleObject((unsigned int)v17, 0, 0, 0, 0);
    result = v16;
  }
  return result;
}
