// ViPendingWorkerThread 
 
void __fastcall __noreturn ViPendingWorkerThread(int a1)
{
  unsigned int v2; // r0

  while ( 1 )
  {
    KeWaitForSingleObject(a1 + 8, 0, 0, 0, 0);
    v2 = *(_DWORD *)(a1 + 4);
    ++*(_DWORD *)(a1 + 24);
    ViPendingCompleteAfterWait(v2);
    *(_DWORD *)(a1 + 4) = 0;
  }
}
