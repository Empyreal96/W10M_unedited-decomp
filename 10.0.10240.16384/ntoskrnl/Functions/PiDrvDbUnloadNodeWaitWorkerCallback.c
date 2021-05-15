// PiDrvDbUnloadNodeWaitWorkerCallback 
 
int __fastcall PiDrvDbUnloadNodeWaitWorkerCallback(int a1)
{
  int v2; // r9
  int v3; // r2
  int v4; // r3
  __int64 v5; // r6
  int result; // r0
  unsigned int v7; // r1
  __int16 v8; // r3
  int v9; // r1
  int v10; // r3
  __int16 v11; // [sp+8h] [bp-58h] BYREF
  int v12[21]; // [sp+Ch] [bp-54h] BYREF

  v2 = ZwWaitForSingleObject();
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  ExAcquireResourceExclusiveLite(a1 + 44, 1, v3, v4);
  if ( !*(_BYTE *)(a1 + 281) )
  {
    *(_BYTE *)(a1 + 281) = 1;
    v5 = PnpEtwHandle;
    v12[0] = v2;
    if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DriverDatabaseUnload_Stop) )
      return sub_555578();
    v12[0] = v2;
    if ( v5 && EtwEventEnabled(v5, SHIDWORD(v5), (int)KMPnPEvt_DriverDatabaseLoaded_Stop) )
    {
      v9 = *(unsigned __int16 *)(a1 + 8);
      v11 = *(_WORD *)(a1 + 8) >> 1;
      v12[1] = (int)&v11;
      v12[2] = 0;
      v12[3] = 2;
      v12[4] = 0;
      v10 = *(_DWORD *)(a1 + 12);
      v12[7] = v9;
      v12[5] = v10;
      v12[6] = 0;
      v12[8] = 0;
      v12[9] = (int)v12;
      v12[10] = 0;
      v12[11] = 4;
      v12[12] = 0;
      EtwWrite(v5, SHIDWORD(v5), (int)KMPnPEvt_DriverDatabaseLoaded_Stop, 0);
    }
  }
  result = ExpReleaseResourceForThreadLite(a1 + 44, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
