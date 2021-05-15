// IopSessionChangeWorker 
 
int __fastcall IopSessionChangeWorker(int a1)
{
  int v2; // r0

  ExNotifyWithProcessing(IopSessionCallbackObject, a1, 0, 0);
  MmSetSessionObjectIoEvent(*(_DWORD *)(a1 + 32));
  ObfDereferenceObjectWithTag(*(_DWORD *)(a1 + 32));
  v2 = *(_DWORD *)(a1 + 28);
  if ( v2 )
    ExFreePoolWithTag(v2);
  return ExFreePoolWithTag(a1);
}
