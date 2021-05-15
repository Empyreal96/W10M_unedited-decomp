// KiInvalidateAllCachesTarget 
 
int __fastcall KiInvalidateAllCachesTarget(int a1, unsigned int *a2)
{
  int result; // r0
  unsigned int v4; // r2

  __dmb(0xBu);
  KiInvalidateCurrentCache(a1);
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    result = 0;
  }
  else
  {
    __disable_irq();
    result = 1;
  }
  __dmb(0xBu);
  do
    v4 = __ldrex(a2);
  while ( __strex(v4 - 1, a2) );
  __dmb(0xBu);
  if ( KiExternalCacheGlobalSyncRequired )
    return sub_51C814(result);
  if ( result )
    __enable_irq();
  return result;
}
