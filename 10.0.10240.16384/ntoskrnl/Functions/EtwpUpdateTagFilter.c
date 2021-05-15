// EtwpUpdateTagFilter 
 
int __fastcall EtwpUpdateTagFilter(int a1, int a2, int a3)
{
  int result; // r0

  if ( a2 )
    return sub_81B7BC();
  *(_WORD *)a3 = 1;
  *(_DWORD *)(a3 + 4) = 42;
  return result;
}
