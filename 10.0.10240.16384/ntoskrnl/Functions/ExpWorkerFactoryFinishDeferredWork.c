// ExpWorkerFactoryFinishDeferredWork 
 
int __fastcall ExpWorkerFactoryFinishDeferredWork(int result)
{
  int v1; // r4

  v1 = result;
  if ( (*(_DWORD *)(result + 20) & 1) != 0 )
  {
    result = AlpciDestroyDeferredMessageContext(result);
    *(_DWORD *)(v1 + 20) &= 0xFFFFFFFE;
  }
  return result;
}
