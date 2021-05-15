// KeIsSingleGroupAffinityEx 
 
int __fastcall KeIsSingleGroupAffinityEx(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 8) )
    result = sub_50B530();
  else
    result = 0;
  return result;
}
