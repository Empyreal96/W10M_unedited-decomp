// KiFlushQueuedDpcsWorker 
 
int __fastcall KiFlushQueuedDpcsWorker(int result)
{
  if ( *(_DWORD *)(result + 1716) | *(_DWORD *)(result + 1692) )
    result = sub_51C0F0();
  return result;
}
