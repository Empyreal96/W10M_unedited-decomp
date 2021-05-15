// KeQueryGroupAffinityEx 
 
int __fastcall KeQueryGroupAffinityEx(int a1, int a2)
{
  int result; // r0

  if ( a2 )
    result = 0;
  else
    result = *(_DWORD *)(a1 + 8);
  return result;
}
