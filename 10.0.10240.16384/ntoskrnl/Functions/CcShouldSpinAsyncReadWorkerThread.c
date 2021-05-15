// CcShouldSpinAsyncReadWorkerThread 
 
int __fastcall CcShouldSpinAsyncReadWorkerThread(int a1, int a2)
{
  unsigned int v2; // r3
  int result; // r0

  if ( !CcMaxAsyncReadWorkerThreads )
    JUMPOUT(0x522E20);
  v2 = *(_DWORD *)(CcReaderThreadsStats + 404 * a2);
  if ( v2 == -1 || v2 >= CcMaxAsyncReadItemsPerThread )
    result = sub_522E18(CcMaxAsyncReadItemsPerThread, 404, 0);
  else
    result = 0;
  return result;
}
