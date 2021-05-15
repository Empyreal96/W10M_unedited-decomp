// KeDisableQueueingPriorityIncrement 
 
int __fastcall KeDisableQueueingPriorityIncrement(int result)
{
  unsigned __int8 *v1; // r3
  unsigned int v2; // r2

  __dmb(0xBu);
  v1 = (unsigned __int8 *)(result + 1);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 2, v1) );
  __dmb(0xBu);
  return result;
}
