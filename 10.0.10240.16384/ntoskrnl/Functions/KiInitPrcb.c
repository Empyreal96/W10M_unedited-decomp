// KiInitPrcb 
 
int __fastcall KiInitPrcb(int a1, int a2)
{
  _DWORD *v4; // r3
  int v5; // r2
  unsigned int v6; // r2
  _DWORD *v7; // r3
  int result; // r0

  *(_DWORD *)(a1 + 1940) = 1;
  *(_DWORD *)(a1 + 1932) = 0;
  *(_DWORD *)(a1 + 1540) = 0;
  v4 = (_DWORD *)(a1 + 2048);
  v5 = 32;
  do
  {
    *v4 = v4;
    v4[1] = v4;
    v4 += 2;
    --v5;
  }
  while ( v5 );
  v6 = 0;
  **(_DWORD **)(a1 + 3460) = 0;
  *(_DWORD *)(*(_DWORD *)(a1 + 3460) + 4) = 0;
  do
  {
    v7 = (_DWORD *)(*(_DWORD *)(a1 + 3460) + v6 + 8);
    v6 += 8;
    *v7 = v7;
    v7[1] = v7;
  }
  while ( v6 < 0x100 );
  memset((_BYTE *)(*(_DWORD *)(a1 + 3460) + 264), 127, 32);
  *(_BYTE *)(*(_DWORD *)(a1 + 3460) + 296) = 1;
  *(_BYTE *)(*(_DWORD *)(a1 + 3460) + 297) = *(_BYTE *)(a1 + 1053);
  *(_BYTE *)(*(_DWORD *)(a1 + 3460) + 298) = 1;
  *(_BYTE *)(*(_DWORD *)(a1 + 3460) + 299) = 1;
  *(_DWORD *)(*(_DWORD *)(a1 + 3460) + 304) = *(_DWORD *)(a1 + 1048);
  *(_DWORD *)(a1 + 28) = *(_DWORD *)(a1 + 3460) + 264;
  KiInitializeDpcList((_DWORD *)(a1 + 1680));
  *(_DWORD *)(a1 + 1688) = 0;
  *(_DWORD *)(a1 + 1692) = 0;
  *(_DWORD *)(a1 + 1696) = 0;
  *(_DWORD *)(a1 + 1756) = 0;
  *(_BYTE *)(a1 + 1754) = 0;
  *(_DWORD *)(a1 + 1736) = KiMaximumDpcQueueDepth;
  *(_DWORD *)(a1 + 1744) = KiMinimumDpcRate;
  *(_DWORD *)(a1 + 2324) = KiAdjustDpcThreshold;
  KeInitializeDpc(a1 + 1812, (int)KiDpcWatchdog, 0);
  *(_BYTE *)(a1 + 1813) = 2;
  *(_WORD *)(a1 + 1814) = a2 + 32;
  *(_DWORD *)(a1 + 1920) = a1 + 1920;
  *(_DWORD *)(a1 + 1924) = a1 + 1920;
  *(_DWORD *)(a1 + 3368) = 0;
  *(_DWORD *)(a1 + 3372) = 0;
  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14) = a1 + 1152;
  *(_DWORD *)(a1 + 1188) = &CcVacbSpinLock;
  *(_DWORD *)(a1 + 1264) = 0;
  *(_DWORD *)(a1 + 1268) = &CcBcbSpinLock;
  *(_DWORD *)(a1 + 1220) = &CcWorkQueueSpinLock;
  *(_DWORD *)(a1 + 1192) = 0;
  *(_DWORD *)(a1 + 1196) = &CcMasterSpinLock;
  *(_DWORD *)(a1 + 1204) = &NonPagedPoolLock;
  *(_DWORD *)(a1 + 1184) = 0;
  *(_DWORD *)(a1 + 1216) = 0;
  *(_DWORD *)(a1 + 1212) = &IopCancelSpinLock;
  *(_DWORD *)(a1 + 1200) = 0;
  *(_DWORD *)(a1 + 1208) = 0;
  *(_DWORD *)(a1 + 1228) = &IopVpbSpinLock;
  *(_DWORD *)(a1 + 1224) = 0;
  *(_DWORD *)(a1 + 1232) = 0;
  *(_DWORD *)(a1 + 1236) = &IopDatabaseLock;
  *(_DWORD *)(a1 + 1240) = 0;
  *(_DWORD *)(a1 + 1248) = 0;
  *(_DWORD *)(a1 + 1244) = &IopCompletionLock;
  *(_DWORD *)(a1 + 1256) = 0;
  *(_DWORD *)(a1 + 1252) = &NtfsStructLock;
  *(_DWORD *)(a1 + 1260) = &AfdWorkQueueSpinLock;
  *(_DWORD *)(a1 + 1280) = 0;
  *(_DWORD *)(a1 + 1284) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 1928) = 0;
  *(_DWORD *)(a1 + 1844) = 1;
  *(_DWORD *)(a1 + 2424) = (3 * (_WORD)a2) & 0x3FF;
  KeInitializeDpc(a1 + 2684, (int)KiEntropyDpcRoutine, a1 + 2424);
  if ( !a2 )
  {
    KiReverseStallIpiLock = 0;
    CcBcbSpinLock = 0;
    CcMasterSpinLock = 0;
    CcVacbSpinLock = 0;
    CcWorkQueueSpinLock = 0;
    IopCancelSpinLock = 0;
    IopCompletionLock = 0;
    IopDatabaseLock = 0;
    IopVpbSpinLock = 0;
    NonPagedPoolLock = 0;
    NtfsStructLock = 0;
    AfdWorkQueueSpinLock = 0;
    KiClockPollCycle = KiClockKeepAliveCycle;
  }
  KiIntSteerInitPrcb(a1);
  result = KeInitializeDpc(a1 + 17416, (int)KiAbDeferredProcessingWorker, 0);
  *(_WORD *)(a1 + 17418) = a2 + 32;
  return result;
}
