// PnpDeviceCompletionRoutine 
 
int __fastcall PnpDeviceCompletionRoutine(int a1, int a2, _DWORD *a3)
{
  int v4; // r7
  unsigned int *v6; // r0
  unsigned int v7; // r4
  int v9; // r0

  v4 = 0;
  *(_DWORD *)(a3[2] + 36) = 0;
  if ( *(_BYTE *)(a2 + 33) )
    a3[5] = 1;
  a3[7] = *(_DWORD *)(a2 + 28);
  a3[6] = *(_DWORD *)(a2 + 24);
  __dmb(0xBu);
  v6 = a3 + 8;
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + 1, v6) );
  __dmb(0xBu);
  if ( (int)a3[6] < 0 )
  {
    v9 = IoFindDeviceThatFailedIrp(a2);
    if ( v9 )
      v4 = *(_DWORD *)(v9 + 8);
  }
  PnpDeviceCompletionQueueDispatchedEntryCompleted();
  if ( a3[4] == 781 )
  {
    if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceEnum_Stop) )
      return sub_518924();
  }
  else
  {
    PnpTraceStartDevice(a3[2], a3[6], v4);
  }
  PnpDeviceCompletionRequestDestroy(a3);
  pIoFreeIrp(a2);
  return -1073741802;
}
