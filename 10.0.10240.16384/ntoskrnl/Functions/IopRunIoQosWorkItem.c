// IopRunIoQosWorkItem 
 
int __fastcall IopRunIoQosWorkItem(_DWORD *a1)
{
  ExQueueWorkItem(a1, 1);
  return KeWaitForSingleObject((unsigned int)(a1 + 20), a1[25], 0, 0, 0);
}
