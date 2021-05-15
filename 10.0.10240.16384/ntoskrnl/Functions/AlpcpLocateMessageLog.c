// AlpcpLocateMessageLog 
 
_DWORD *__fastcall AlpcpLocateMessageLog(unsigned int a1)
{
  int v1; // r1
  _DWORD *i; // r2

  if ( AlpcpMessageLogLookupTable )
  {
    v1 = AlpcpMessageLogLookupTable + 8 * ((a1 >> 2) & 0x3FF);
    for ( i = *(_DWORD **)(v1 + 4); i != (_DWORD *)v1; i = (_DWORD *)i[1] )
    {
      if ( i[4] && i[3] == a1 )
        return i - 2;
    }
  }
  return 0;
}
