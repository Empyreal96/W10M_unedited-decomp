// KeQueryEffectivePriorityThread 
 
int __fastcall KeQueryEffectivePriorityThread(int a1)
{
  int result; // r0

  if ( *(char *)(a1 + 123) < 16 && *(_DWORD *)(a1 + 68) )
    result = sub_554FBC();
  else
    result = *(char *)(a1 + 123);
  return result;
}
