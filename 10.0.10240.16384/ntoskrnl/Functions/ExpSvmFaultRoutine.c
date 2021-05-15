// ExpSvmFaultRoutine 
 
int __fastcall ExpSvmFaultRoutine(int result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(ExpSvmWorkQueues + 52 * result + 48);
  do
    v2 = __ldrex(v1);
  while ( !v2 && __strex(1u, v1) );
  __dmb(0xBu);
  if ( !v2 )
    result = KiInsertQueueDpc(ExpSvmWorkQueues + 52 * result + 16, 0, 0, 0, 0);
  return result;
}
