// PiSwIrpCancelStartCreate 
 
int __fastcall PiSwIrpCancelStartCreate(int a1, int a2)
{
  int v3; // r5
  int v4; // r6
  int v5; // r2
  int v6; // r3
  int result; // r0
  unsigned int v8; // r1
  __int16 v9; // r3

  v3 = 0;
  v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 96) + 28) + 16);
  KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a2 + 37));
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(__int16 *)(v5 + 0x134) - 1;
  *(_WORD *)(v5 + 308) = v6;
  ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v5, v6);
  if ( *(_DWORD *)(v4 + 76) )
  {
    v3 = 1;
    *(_DWORD *)(v4 + 76) = 0;
  }
  result = ExReleaseResourceLite((int)&PiSwLockObj);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( v3 )
  {
    *(_DWORD *)(a2 + 24) = -1073741536;
    *(_DWORD *)(a2 + 28) = 0;
    result = pIofCompleteRequest(a2, 0);
  }
  return result;
}
