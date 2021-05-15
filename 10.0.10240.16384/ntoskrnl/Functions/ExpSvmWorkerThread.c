// ExpSvmWorkerThread 
 
int __fastcall ExpSvmWorkerThread(int a1)
{
  int i; // r4
  int result; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1

  for ( i = 0; ; i = 1 )
  {
    do
      result = ((int (__cdecl *)())HalIommuDispatch[11])();
    while ( result );
    if ( i )
      break;
    __dmb(0xBu);
    v4 = (unsigned int *)(ExpSvmWorkQueues + 52 * a1 + 48);
    do
      v5 = __ldrex(v4);
    while ( __strex(0, v4) );
    __dmb(0xBu);
  }
  return result;
}
