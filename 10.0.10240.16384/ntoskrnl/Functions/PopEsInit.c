// PopEsInit 
 
int *PopEsInit()
{
  int *result; // r0
  int v1; // r5

  result = &PopEsWorkItem;
  dword_61DED4 = 0;
  PopEsLock = 0;
  dword_646358 = (int)PopEsWorker;
  dword_64635C = 0;
  PopEsWorkItem = 0;
  __dmb(0xBu);
  do
    v1 = __ldrex(&PopEsWorkItemDue);
  while ( __strex(v1 | 0x80000001, &PopEsWorkItemDue) );
  __dmb(0xBu);
  if ( v1 >= 0 )
    result = (int *)ExQueueWorkItem(&PopEsWorkItem, 1);
  return result;
}
