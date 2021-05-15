// EtwpQueuePerfMemInfoWorkItem 
 
_DWORD *__fastcall EtwpQueuePerfMemInfoWorkItem(int a1)
{
  _DWORD *result; // r0

  result = (_DWORD *)ExAllocatePoolWithTag(512, 20, 1467446341);
  if ( result )
  {
    result[3] = result;
    result[4] = a1;
    result[2] = EtwpPerfMemInfoWork;
    *result = 0;
    result = (_DWORD *)ExQueueWorkItem(result, 0);
  }
  return result;
}
