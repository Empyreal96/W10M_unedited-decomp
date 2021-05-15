// KeRequestTerminationProcess 
 
int __fastcall KeRequestTerminationProcess(int result)
{
  unsigned __int8 *v1; // r3
  unsigned int v2; // r1

  __dmb(0xBu);
  v1 = (unsigned __int8 *)(result + 82);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 2, v1) );
  __dmb(0xBu);
  if ( !((unsigned __int8)(v2 & 2) >> 1) )
    result = KeRequestTerminationThread(result);
  return result;
}
