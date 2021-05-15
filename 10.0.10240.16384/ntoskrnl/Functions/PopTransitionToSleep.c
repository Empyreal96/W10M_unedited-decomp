// PopTransitionToSleep 
 
int __fastcall PopTransitionToSleep(int a1)
{
  int v2; // r4
  int v3; // r0
  int v4; // r2
  int v5; // r7
  __int64 v6; // r0
  char v8[8]; // [sp+8h] [bp-30h] BYREF
  int (*v9)(); // [sp+10h] [bp-28h] BYREF
  int (__fastcall *v10)(int); // [sp+14h] [bp-24h]
  int (__fastcall *v11)(__int64, __int64); // [sp+18h] [bp-20h]
  int v12; // [sp+1Ch] [bp-1Ch]
  int v13; // [sp+20h] [bp-18h]

  v2 = *(_DWORD *)(a1 + 48);
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v8[0] = 0;
  dword_61EF1C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v2 == 3 || v2 == 6 )
  {
    if ( PopEnlargeHiberFile(v8) >= 0 )
      v4 = (unsigned __int8)v8[0];
    else
      v4 = 1;
    v9 = xHalPciEarlyRestore;
    v10 = PopEndMirroring;
    v11 = PopMirrorPhysicalMemory;
    v12 = 0;
    if ( v2 == 6 || v4 )
    {
      v13 = 17;
      MmTrimFilePagesFromWorkingSets();
    }
    else
    {
      v13 = 20;
    }
    PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_FLUSHALLPAGES);
    if ( v2 == 3 )
      MmFlushAllPages();
    PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_FLUSHALLPAGES_END);
    PopHibernatePowerStateHandlerType = v2;
    PopSleeperHandoff = a1;
    v3 = MmDuplicateMemory((int)&v9);
    PopSleeperHandoff = 0;
    PopHibernatePowerStateHandlerType = 7;
  }
  else
  {
    KeSetEvent(a1, 0, 1);
    KeWaitForSingleObject(a1 + 16, 0, 0, 0, 0);
    v3 = PopInvokeSystemStateHandler(v2);
  }
  v5 = v3;
  LODWORD(v6) = ReadTimeStampCounter();
  *(_QWORD *)&dword_61F098 = v6;
  *(_DWORD *)(a1 + 52) = v5;
  return KeSetEvent(a1 + 32, 0, 0);
}
