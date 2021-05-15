// ObpDeferObjectDeletion 
 
unsigned int __fastcall ObpDeferObjectDeletion(unsigned int result)
{
  int v1; // r1
  unsigned int v2; // r4
  BOOL v3; // r0
  unsigned int v4; // r0

  __pld(&ObpRemoveObjectList);
  v1 = ObpRemoveObjectList;
  *(_DWORD *)(result + 4) = ObpRemoveObjectList;
  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)&ObpRemoveObjectList);
  while ( v2 == v1 && __strex(result, (unsigned int *)&ObpRemoveObjectList) );
  if ( v2 != v1 )
    return sub_523538();
  if ( !v1 )
  {
    v3 = KeAreInterruptsEnabled();
    if ( v3 )
      v4 = KeGetCurrentIrql(v3);
    else
      v4 = 15;
    if ( v4 > 2 )
      result = KiInsertQueueDpc(&ObpRemoveObjectDpc);
    else
      result = ExQueueWorkItem(&ObpRemoveObjectWorkItem, 0);
  }
  return result;
}
