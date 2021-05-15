// ObKillProcess 
 
int __fastcall ObKillProcess(int result)
{
  int v1; // r5
  int v2; // r6
  int v3; // r4

  v1 = *(_DWORD *)(result + 336);
  v2 = result;
  if ( v1 )
  {
    v3 = IoSetThreadHardErrorMode(0);
    ExSweepHandleTable(v1, 0);
    IoSetThreadHardErrorMode(v3);
    *(_DWORD *)(v2 + 336) = 0;
    ExpRemoveHandleTable(v1);
    result = ExpFreeHandleTable(v1);
  }
  return result;
}
