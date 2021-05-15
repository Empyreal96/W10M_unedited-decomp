// PopEsBatteryStatusChanged 
 
unsigned int __fastcall PopEsBatteryStatusChanged(int a1)
{
  int v1; // r3
  unsigned int result; // r0
  int v3; // r4

  v1 = 4;
  if ( a1 )
    v1 = 12;
  __dmb(0xBu);
  result = v1 | 0x80000000;
  do
    v3 = __ldrex(&PopEsWorkItemDue);
  while ( __strex(v3 | result, &PopEsWorkItemDue) );
  __dmb(0xBu);
  if ( v3 >= 0 )
    result = ExQueueWorkItem(&PopEsWorkItem, 1);
  return result;
}
