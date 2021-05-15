// CmGetBoundTransaction 
 
int __fastcall CmGetBoundTransaction(int a1, int a2)
{
  int result; // r0

  if ( a1 )
    result = *(_DWORD *)(a2 + 28);
  else
    result = 0;
  return result;
}
