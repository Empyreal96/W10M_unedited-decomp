// CmpFreezeThawDpcRoutine 
 
int CmpFreezeThawDpcRoutine()
{
  int result; // r0
  unsigned int v1; // r1

  __dmb(0xBu);
  result = 1;
  do
    v1 = __ldrex((unsigned int *)&CmpFreezeThawPending);
  while ( !v1 && __strex(1u, (unsigned int *)&CmpFreezeThawPending) );
  __dmb(0xBu);
  if ( !v1 )
    result = ExQueueWorkItem(&CmpFreezeThawWorkItem, 1);
  return result;
}
