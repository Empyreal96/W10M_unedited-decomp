// PspUpdateSharedReadyQueueAffinityProcessCallback 
 
int __fastcall PspUpdateSharedReadyQueueAffinityProcessCallback(int a1, int a2, int a3)
{
  if ( (*(_DWORD *)(a1 + 192) & 8) == 0 )
    KeUpdateProcessSharedReadyQueueAffinity(a1, a2, a3);
  return 0;
}
