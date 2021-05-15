// IovpSessionDataReference 
 
__int64 *__fastcall IovpSessionDataReference(__int64 *result)
{
  __int64 v1; // r2
  unsigned int *v2; // r2
  unsigned int v3; // r1

  v1 = *result;
  if ( !*((_DWORD *)result + 1) )
  {
    __dmb(0xBu);
    v2 = (unsigned int *)(v1 + 12);
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 + 1, v2) );
    __dmb(0xBu);
  }
  ++*((_DWORD *)result + 1);
  return result;
}
