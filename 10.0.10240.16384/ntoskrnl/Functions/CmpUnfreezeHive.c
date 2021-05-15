// CmpUnfreezeHive 
 
int __fastcall CmpUnfreezeHive(int a1)
{
  int result; // r0

  *(_BYTE *)(a1 + 2532) = 0;
  if ( *(_DWORD *)(a1 + 2536) )
  {
    if ( CmWorkerEngineDequeueWorkItem() )
      CmpDereferenceHive(a1);
    *(_DWORD *)(a1 + 2536) = 0;
  }
  result = *(_DWORD *)(a1 + 2528);
  if ( result )
  {
    result = CmpDereferenceKeyControlBlockWithLock(result, 1);
    *(_DWORD *)(a1 + 2528) = 0;
  }
  return result;
}
