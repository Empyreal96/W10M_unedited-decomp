// AlpcpWalkConnectionList 
 
unsigned int __fastcall AlpcpWalkConnectionList(unsigned int result)
{
  _DWORD **v1; // r7
  _DWORD *v2; // r4
  unsigned __int8 *v3; // r5
  int v4; // r0
  unsigned int v5; // r2
  unsigned int v6; // r1

  v1 = (_DWORD **)(*(_DWORD *)(result + 8) + 12);
  v2 = *v1;
  if ( *v1 != v1 )
  {
    while ( 1 )
    {
      v3 = (unsigned __int8 *)(v2 - 4);
      v4 = KeAbPreAcquire((unsigned int)(v2 - 4), 0, 0);
      do
        v5 = __ldrex(v3);
      while ( __strex(v5 | 1, v3) );
      __dmb(0xBu);
      if ( (v5 & 1) != 0 )
        break;
      if ( v4 )
        *(_BYTE *)(v4 + 14) |= 1u;
      __dmb(0xBu);
      do
        v6 = __ldrex((unsigned int *)v3);
      while ( __strex(v6 - 1, (unsigned int *)v3) );
      if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
        ExfTryToWakePushLock(v2 - 4);
      result = KeAbPostRelease((unsigned int)(v2 - 4));
      v2 = (_DWORD *)*v2;
      if ( v2 == v1 )
        return result;
    }
    result = sub_7E9530(v4);
  }
  return result;
}
