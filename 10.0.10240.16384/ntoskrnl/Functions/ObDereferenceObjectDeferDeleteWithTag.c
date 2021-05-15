// ObDereferenceObjectDeferDeleteWithTag 
 
unsigned int __fastcall ObDereferenceObjectDeferDeleteWithTag(unsigned int result)
{
  unsigned int *v1; // r4
  unsigned int v2; // r2
  signed int v3; // r2

  v1 = (unsigned int *)(result - 24);
  if ( ObpTraceFlags )
    return sub_50C3AC();
  __dmb(0xBu);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 - 1;
  }
  while ( __strex(v3, v1) );
  if ( v3 <= 0 )
  {
    if ( *(_DWORD *)(result - 20) )
      KeBugCheckEx(
        24,
        ObTypeIndexTable[*(unsigned __int8 *)(result - 12) ^ (unsigned __int8)((unsigned __int16)(result - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie],
        result);
    if ( v3 < 0 )
      KeBugCheckEx(24, 0, result);
    result = ObpDeferObjectDeletion(result - 24);
  }
  return result;
}
