// ExGetSharedWaiterCount 
 
int __fastcall ExGetSharedWaiterCount(int a1)
{
  return *(_DWORD *)(a1 + 40);
}
