// MiReturnCcAccessLog 
 
unsigned __int8 *__fastcall MiReturnCcAccessLog(unsigned __int8 *result, int a2)
{
  int v2; // r3

  if ( a2 )
    *((_DWORD *)result + 8) = *((_DWORD *)result + 6);
  if ( !dword_634480 )
  {
    do
      a2 = __ldrex((unsigned int *)&dword_634480);
    while ( !a2 && __strex((unsigned int)result, (unsigned int *)&dword_634480) );
    if ( !a2 )
      result = 0;
  }
  if ( result )
  {
    v2 = *((_DWORD *)result + 8);
    if ( (unsigned __int8 *)v2 == result + 56 )
      result = (unsigned __int8 *)MmFreeAccessPfnBuffer(result, 1);
    else
      result = MiQueuePageAccessLog(result, a2, (int)(result + 56), v2);
  }
  return result;
}
