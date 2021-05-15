// CmGetVisibleSubkeyCount 
 
int __fastcall CmGetVisibleSubkeyCount(int a1, int a2, int a3)
{
  int result; // r0

  if ( a3 )
    result = sub_7D25C4();
  else
    result = *(_DWORD *)(a2 + 24) + *(_DWORD *)(a2 + 20);
  return result;
}
