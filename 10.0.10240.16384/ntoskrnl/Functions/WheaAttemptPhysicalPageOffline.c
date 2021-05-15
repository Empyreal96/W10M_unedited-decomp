// WheaAttemptPhysicalPageOffline 
 
int __fastcall WheaAttemptPhysicalPageOffline(int a1, unsigned __int8 a2)
{
  int v5[4]; // [sp+8h] [bp-38h] BYREF
  int v6[10]; // [sp+18h] [bp-28h] BYREF

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 1 )
    return WheapAttemptPhysicalPageOffline(a1, a2, 0);
  memset(v6, 0, 28);
  v6[0] = a1;
  LOWORD(v6[1]) = a2;
  KeInitializeEvent((int)&v6[3], 0, 0);
  v5[2] = (int)WheapAttemptPhysicalPageOfflineWorker;
  v5[3] = (int)v6;
  v5[0] = 0;
  ExQueueWorkItem(v5, 1);
  KeWaitForSingleObject((unsigned int)&v6[3], 0, 0, 0, 0);
  return v6[2];
}
