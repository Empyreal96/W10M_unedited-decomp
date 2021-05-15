// KiAbWaiterComputeCpuPriorityKey 
 
int __fastcall KiAbWaiterComputeCpuPriorityKey(int a1)
{
  int result; // r0

  result = *(char *)(a1 - 8 * *(unsigned __int8 *)(a1 + 12) + 123);
  if ( result > 15 )
    result = 15;
  return result;
}
