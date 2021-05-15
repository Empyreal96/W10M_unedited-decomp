// PpInitializeBootDDB 
 
int __fastcall PpInitializeBootDDB(int a1, int a2)
{
  int v3; // r0
  int v4; // r0
  int v5; // r3
  int v6; // r1
  int v7; // r0
  int v8; // r5
  unsigned __int16 v10[12]; // [sp+8h] [bp-18h] BYREF

  if ( a2 )
    return 0;
  PpDDBHandle = 0;
  PpBootDDB = 0;
  v3 = ExInitializeResourceLite((int)&PiDDBLock);
  PiDDBPath = (int)L"\\SystemRoot\\AppPatch\\drvmain.sdb";
  v4 = PiInitializeDDBCache(v3);
  if ( InitIsWinPEMode )
    goto LABEL_16;
  v5 = *(_DWORD *)(a1 + 132);
  v6 = *(_DWORD *)(v5 + 44);
  if ( !v6 || !*(_DWORD *)(v5 + 40) )
  {
    if ( (PiLoggedErrorEventsMask & 1) == 0 )
      return sub_965BA0(v4);
    goto LABEL_16;
  }
  v7 = ExAllocatePoolWithTag(1, v6, 538996816);
  v8 = v7;
  PpBootDDB = v7;
  if ( v7 )
  {
    memmove(v7, *(_DWORD *)(*(_DWORD *)(a1 + 132) + 40), *(_DWORD *)(*(_DWORD *)(a1 + 132) + 44));
    PpDDBHandle = SdbInitDatabaseInMemory(v8, *(_DWORD *)(*(_DWORD *)(a1 + 132) + 44));
    if ( PpDDBHandle )
      return 0;
    ExFreePoolWithTag(PpBootDDB);
    PpBootDDB = 0;
    if ( (PiLoggedErrorEventsMask & 4) == 0 )
      JUMPOUT(0x965BA6);
LABEL_16:
    JUMPOUT(0x965BBC);
  }
  if ( (PiLoggedErrorEventsMask & 2) == 0 )
  {
    PiLoggedErrorEventsMask |= 2u;
    RtlInitUnicodeString((unsigned int)v10, L"OUT OF MEMORY");
    PnpLogEvent(v10, 0, -1073740947, 0, 0);
  }
  return -1073741670;
}
