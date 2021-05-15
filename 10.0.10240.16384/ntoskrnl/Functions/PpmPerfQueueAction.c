// PpmPerfQueueAction 
 
int __fastcall PpmPerfQueueAction(int result, char a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r5

  __dmb(0xBu);
  v2 = (unsigned int *)(result + 3192);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | (1 << a2), v2) );
  __dmb(0xBu);
  if ( !v3 )
    result = KiInsertQueueDpc(result + 3160);
  return result;
}
