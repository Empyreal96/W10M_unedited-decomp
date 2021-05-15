// ObpPushStackInfoQueue 
 
__int64 ObpPushStackInfoQueue()
{
  unsigned int v0; // r4
  unsigned int v1; // r3
  __int64 result; // r0
  unsigned int v3; // r2

  while ( 1 )
  {
    __dmb(0xBu);
    do
      v0 = __ldrex((unsigned int *)&ObpPushStackInfoList);
    while ( __strex(1u, (unsigned int *)&ObpPushStackInfoList) );
    __dmb(0xBu);
    do
    {
      ObpPushRefDerefInfo(
        *(_DWORD *)(v0 + 4),
        *(unsigned __int8 *)(v0 + 8),
        *(unsigned __int16 *)(v0 + 10),
        *(_DWORD *)(v0 + 16),
        (unsigned __int16 *)(v0 + 20),
        *(_DWORD *)(v0 + 12));
      v1 = v0;
      v0 = *(_DWORD *)v0;
      LODWORD(result) = ObpFreeWorkItemBlock((_DWORD *)(v1 - 4));
    }
    while ( v0 && v0 != 1 );
    if ( ObpPushStackInfoList == 1 )
    {
      __dmb(0xBu);
      HIDWORD(result) = 0;
      do
        v3 = __ldrex((unsigned int *)&ObpPushStackInfoList);
      while ( v3 == 1 && __strex(0, (unsigned int *)&ObpPushStackInfoList) );
      __dmb(0xBu);
      if ( v3 == 1 )
        break;
    }
  }
  return result;
}
