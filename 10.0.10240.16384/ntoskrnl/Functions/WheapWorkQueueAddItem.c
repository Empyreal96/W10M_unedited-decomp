// WheapWorkQueueAddItem 
 
__int64 **__fastcall WheapWorkQueueAddItem(int a1, __int64 *a2)
{
  __int64 **result; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int v6; // r1

  result = ExInterlockedInsertTailList((__int64 *)a1, a2, (unsigned int *)(a1 + 8));
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 12);
  do
  {
    v5 = __ldrex(v4);
    v6 = v5 + 1;
  }
  while ( __strex(v6, v4) );
  __dmb(0xBu);
  if ( v6 == 1 )
  {
    if ( (unsigned int)KeGetCurrentIrql(result) > 2 )
      result = (__int64 **)KiInsertQueueDpc(a1 + 16, 0, 0, 0, 0);
    else
      result = (__int64 **)ExQueueWorkItem((_DWORD *)(a1 + 48), 1);
  }
  return result;
}
