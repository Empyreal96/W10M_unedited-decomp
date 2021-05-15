// IopIncrementVpbRefCount 
 
int __fastcall IopIncrementVpbRefCount(int a1, int a2)
{
  int result; // r0

  if ( a2 )
  {
    result = IopInterlockedIncrementUlong(9, a1 + 20);
  }
  else
  {
    result = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = result;
  }
  if ( result <= 0 )
    sub_53BFBC();
  return result;
}
