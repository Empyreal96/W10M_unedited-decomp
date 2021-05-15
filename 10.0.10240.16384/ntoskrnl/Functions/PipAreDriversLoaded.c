// PipAreDriversLoaded 
 
int __fastcall PipAreDriversLoaded(int a1)
{
  return PipAreDriversLoadedWorker(*(_DWORD *)(a1 + 172), *(_DWORD *)(a1 + 176));
}
