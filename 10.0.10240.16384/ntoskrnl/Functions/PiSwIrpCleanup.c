// PiSwIrpCleanup 
 
int __fastcall PiSwIrpCleanup(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r2
  int v7; // r3
  BOOL v8; // r6
  int i; // r3
  unsigned __int16 *v10; // r7
  int v11; // r0
  int v12; // r3
  int result; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  int v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r1
  _DWORD v19[6]; // [sp+0h] [bp-18h] BYREF

  v19[0] = a3;
  v19[1] = a4;
  v5 = 0;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(__int16 *)(v6 + 0x134) - 1;
  *(_WORD *)(v6 + 308) = v7;
  ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v6, v7);
  v8 = a1[24] == 0;
  if ( a1[24] )
  {
    for ( i = a1[15]; ; i = *(_DWORD *)(v16 + 60) )
    {
      v10 = *(unsigned __int16 **)(i + 4);
      if ( wcsnicmp((int)v10, L"SWD\\", 4) )
        break;
      v16 = PiSwFindSwDevice((int)v10);
      if ( !v16 )
        goto LABEL_17;
      if ( !*(_DWORD *)(v16 + 96) )
        return sub_819C54();
    }
    RtlInitUnicodeString((unsigned int)v19, v10);
    v11 = PnpDeviceObjectFromDeviceInstance((int)v19);
    if ( v11 )
    {
      ObfDereferenceObject(v11);
      goto LABEL_6;
    }
LABEL_17:
    v8 = 1;
  }
LABEL_6:
  v12 = a1[19];
  if ( v12 )
  {
    __dmb(0xBu);
    v17 = (unsigned int *)(v12 + 56);
    do
      v18 = __ldrex(v17);
    while ( __strex(0, v17) );
    __dmb(0xBu);
    if ( v18 )
    {
      v5 = a1[19];
      a1[19] = 0;
    }
  }
  a1[1] &= 0xFFFFFFFE;
  if ( v8 )
  {
    PiSwCloseDecendents(a1 + 10);
    PiSwCloseDevice(a1);
  }
  result = ExReleaseResourceLite((int)&PiSwLockObj);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( v5 )
  {
    *(_DWORD *)(v5 + 24) = -1073741536;
    *(_DWORD *)(v5 + 28) = 0;
    result = IofCompleteRequest(v5, 0);
  }
  return result;
}
