// sub_947F10 
 
int __fastcall sub_947F10(int a1, int a2, int a3)
{
  int v3; // r3
  int (*v6)(); // r5

  v3 = *(_DWORD *)(a3 + 1000);
  if ( v3 )
  {
    if ( v3 != 1 )
      return 0;
    v6 = PopIrpWorkerControl;
  }
  else
  {
    v6 = CcQueueLazyWriteScanThread;
  }
  if ( (int (*)())PsQueryThreadStartAddress(a2, 0) == v6 )
  {
    ObfReferenceObject(a2);
    *(_DWORD *)(a3 + 1000) = a2;
  }
  return 0;
}
