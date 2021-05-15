// SmKmStoreHelperWorker 
 
int __fastcall SmKmStoreHelperWorker(int a1)
{
  int result; // r0

  KeSetActualBasePriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 25);
  KeWaitForSingleObject(a1 + 4, 0, 0);
  result = KeResetEvent(a1 + 4);
  if ( *(_WORD *)(a1 + 38) != 1 )
    result = sub_52641C(result);
  return result;
}
