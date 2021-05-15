// WheapAttemptPhysicalPageOfflineWorker 
 
int __fastcall WheapAttemptPhysicalPageOfflineWorker(int a1)
{
  *(_DWORD *)(a1 + 8) = WheapAttemptPhysicalPageOffline(*(_DWORD *)a1, *(_BYTE *)(a1 + 4), *(unsigned __int8 *)(a1 + 5));
  return KeSetEvent(a1 + 12, 0, 0);
}
