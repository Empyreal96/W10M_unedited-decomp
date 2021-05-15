// PopOkayToQueueNextWorkItem 
 
int __fastcall PopOkayToQueueNextWorkItem(int a1)
{
  unsigned int *v1; // r2
  int result; // r0
  unsigned int v3; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(a1 + 16);
  result = 0;
  do
    v3 = __ldrex(v1);
  while ( __strex(0, v1) );
  __dmb(0xBu);
  return result;
}
