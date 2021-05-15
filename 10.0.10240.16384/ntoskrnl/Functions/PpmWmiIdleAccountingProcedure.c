// PpmWmiIdleAccountingProcedure 
 
_DWORD *PpmWmiIdleAccountingProcedure()
{
  _DWORD *result; // r0

  result = (_DWORD *)ExAllocatePoolWithTag(512, 16);
  if ( result )
  {
    result[2] = PpmWmiIdleAccountingWork;
    result[3] = result;
    *result = 0;
    result = (_DWORD *)ExQueueWorkItem(result, 1);
  }
  return result;
}
