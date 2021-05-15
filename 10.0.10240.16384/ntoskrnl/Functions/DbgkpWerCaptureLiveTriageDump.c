// DbgkpWerCaptureLiveTriageDump 
 
int __fastcall DbgkpWerCaptureLiveTriageDump(_DWORD *a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r4
  int v7; // r0
  int v8; // r3
  const char *v9; // r2
  _DWORD v11[108]; // [sp+10h] [bp-1B0h] BYREF

  DbgPrintEx(5, 3, (int)"DBGK: Creating mini live dump. ComponentName %ws\n", (int)a1);
  a1[16] = 1048572;
  memset(v11, 0, 416);
  v2 = ExAllocatePoolWithTag(1, 0x20000, 1466393156);
  a1[24] = v2;
  if ( !v2 )
    return -1073741801;
  RtlCaptureContext(v11, v3, v4, v5);
  v7 = KeCapturePersistentThreadState((int)v11, 0, a1[8], a1[9], a1[10], a1[11], a1[12], a1[24]);
  if ( v7 )
  {
    a1[25] = v7;
    v6 = DbgkpWerInvokeCallbacks(a1);
    if ( v6 >= 0 )
    {
      v6 = DbgkpWerWriteTriageDump(a1);
      if ( v6 >= 0 )
      {
        v6 = WerLiveKernelSubmitReport_0();
        if ( v6 >= 0 )
        {
          a1[20] |= 1u;
          return v6;
        }
        v9 = "DBGK: DbgkpWerCaptureLiveTriageDump: WerLiveKernelSubmitReport failed with status 0x%X\n";
      }
      else
      {
        v9 = "DBGK: DbgkpWerWriteTriageDump failed, status 0x%X\n";
      }
    }
    else
    {
      v9 = "DBGK: DbgkpWerInvokeCallbacks failed, status 0x%X\n";
    }
    DbgPrintEx(5, 0, (int)v9, v6);
  }
  else
  {
    DbgPrintEx(5, 0, (int)"DBGK: KeCapturePersistentThreadState failed\n", v8);
    v6 = -1073741823;
  }
  return v6;
}
