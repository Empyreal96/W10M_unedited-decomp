// PiDrvDbUnloadNodeWorkerCallback 
 
int __fastcall PiDrvDbUnloadNodeWorkerCallback(int a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r0
  __int64 v5; // r6
  int result; // r0
  unsigned int v7; // r1
  int v8; // r3
  int v9; // r1
  int v10; // r3
  __int16 v11; // [sp+8h] [bp-48h] BYREF
  __int16 *v12; // [sp+10h] [bp-40h]
  int v13; // [sp+14h] [bp-3Ch]
  int v14; // [sp+18h] [bp-38h]
  int v15; // [sp+1Ch] [bp-34h]
  int v16; // [sp+20h] [bp-30h]
  int v17; // [sp+24h] [bp-2Ch]
  int v18; // [sp+28h] [bp-28h]
  int v19; // [sp+2Ch] [bp-24h]

  PiDrvDbUnloadNodeReset(a1);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x134) - 1;
  *(_WORD *)(v2 + 308) = v3;
  v4 = ExAcquireResourceExclusiveLite(a1 + 44, 1, v2, v3);
  if ( *(_BYTE *)(a1 + 280) )
  {
    v5 = PnpEtwHandle;
    if ( PnpEtwHandle )
      return sub_81B4FC(v4);
    if ( *(_DWORD *)(a1 + 36) )
    {
      ZwClose();
      v5 = PnpEtwHandle;
      *(_DWORD *)(a1 + 36) = 0;
    }
    *(_BYTE *)(a1 + 280) = 0;
    *(_BYTE *)(a1 + 281) = 0;
    if ( v5 && EtwEventEnabled(v5, SHIDWORD(v5), (int)KMPnPEvt_DriverDatabaseUnload_Pend) )
    {
      v9 = *(unsigned __int16 *)(a1 + 8);
      v11 = *(_WORD *)(a1 + 8) >> 1;
      v12 = &v11;
      v13 = 0;
      v14 = 2;
      v15 = 0;
      v10 = *(_DWORD *)(a1 + 12);
      v18 = v9;
      v16 = v10;
      v17 = 0;
      v19 = 0;
      EtwWrite(v5, SHIDWORD(v5), (int)KMPnPEvt_DriverDatabaseUnload_Pend, 0);
    }
    *(_DWORD *)(a1 + 256) = PiDrvDbUnloadNodeWaitWorkerCallback;
    *(_DWORD *)(a1 + 260) = a1;
    *(_DWORD *)(a1 + 248) = 0;
    ExQueueWorkItem((_DWORD *)(a1 + 248), 1);
  }
  result = ExReleaseResourceLite(a1 + 44);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = (__int16)(*(_WORD *)(v7 + 0x134) + 1);
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
