// PerfDiagpRequestState 
 
int __fastcall PerfDiagpRequestState(int result)
{
  int v1; // r4

  v1 = result;
  if ( result < 8 )
  {
    result = ExAllocatePoolWithTag(512, 20, 1682330192);
    if ( result )
    {
      *(_DWORD *)(result + 8) = PerfDiagpProxyWorker;
      *(_DWORD *)(result + 12) = result;
      *(_DWORD *)result = 0;
      *(_DWORD *)(result + 16) = v1;
      result = ExQueueWorkItem((_DWORD *)result, 1);
    }
  }
  return result;
}
