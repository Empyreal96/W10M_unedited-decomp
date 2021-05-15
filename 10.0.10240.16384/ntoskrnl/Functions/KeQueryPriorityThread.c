// KeQueryPriorityThread 
 
int __fastcall KeQueryPriorityThread(int a1)
{
  int result; // r0

  if ( *(_UNKNOWN **)(a1 + 336) == &KiInitialProcess )
    result = 1;
  else
    result = *(char *)(a1 + 123);
  return result;
}
