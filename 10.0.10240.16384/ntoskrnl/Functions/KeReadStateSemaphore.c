// KeReadStateSemaphore 
 
int __fastcall KeReadStateSemaphore(int a1)
{
  return *(_DWORD *)(a1 + 4);
}
