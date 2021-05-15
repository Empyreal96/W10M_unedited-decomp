// DbgkpWerCaptureLiveFullDump 
 
int __fastcall DbgkpWerCaptureLiveFullDump(_DWORD *a1, _BYTE *a2)
{
  _BYTE *v4; // r0
  int v5; // r3
  _DWORD *v6; // r6
  int v7; // r4
  const char *v8; // r2
  int v9; // r0
  _DWORD *v10; // r0
  int v12[5]; // [sp+14h] [bp-14h] BYREF

  a1[16] = 0x10000000;
  *a2 = 1;
  DbgPrintEx(5, 3, (int)"DBGK: Creating full dump.  ComponentName %ws, Defer = %d\n", (int)a1);
  v4 = (_BYTE *)ExAllocatePoolWithTag(1, 36, 1466393156);
  v6 = v4;
  if ( !v4 )
  {
    DbgPrintEx(5, 0, (int)"DBGK: Could not allocate an Io Control.\n", v5);
    return -1073741801;
  }
  memset(v4, 0, 36);
  a1[22] = v6;
  *v6 = 1;
  v6[1] = 36;
  if ( (a1[15] & 1) != 0 )
    v6[4] |= 4u;
  v7 = WerLiveKernelOpenDumpFile_0();
  if ( v7 < 0 )
  {
    v8 = "DBGK: WerLiveKernelOpenDumpFile failed. Status = 0x%X\n";
LABEL_7:
    DbgPrintEx(5, 0, (int)v8, v7);
    return v7;
  }
  v6[2] = 0;
  a1[20] |= 2u;
  v6[4] |= 8u;
  v7 = DbgkpWerInitializeDeferredLiveDump(a1);
  if ( v7 >= 0 )
  {
    v7 = DbgkpWerInvokeCallbacks(a1);
    if ( v7 >= 0 )
    {
      v9 = IoCaptureLiveDump(a1[8], a1[9], a1[10], a1[11], a1[12], v6, v12);
      v7 = v9;
      if ( v9 >= 0 || v9 == -1073741802 )
      {
        v10 = (_DWORD *)a1[21];
        a1[23] = v12[0];
        ExQueueWorkItem(v10, 1);
        v7 = 0;
        *a2 = 0;
        return v7;
      }
      v8 = "DBGK: DbgkpWerCaptureLiveFullDump: IoCaptureLiveDump failed with status 0x%X\n";
      goto LABEL_7;
    }
  }
  return v7;
}
