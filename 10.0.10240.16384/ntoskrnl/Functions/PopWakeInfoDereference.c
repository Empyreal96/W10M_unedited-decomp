// PopWakeInfoDereference 
 
_DWORD *__fastcall PopWakeInfoDereference(_DWORD *result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1
  unsigned int v3; // r1

  __dmb(0xBu);
  v1 = result + 2;
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 - 1;
  }
  while ( __strex(v3, v1) );
  __dmb(0xBu);
  if ( !v3 )
  {
    result[8] = PopFreeWakeInfo;
    result[9] = result;
    result[6] = 0;
    result = (_DWORD *)ExQueueWorkItem(result + 6, 1);
  }
  return result;
}
