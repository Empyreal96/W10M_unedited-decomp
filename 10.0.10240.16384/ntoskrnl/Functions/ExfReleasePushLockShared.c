// ExfReleasePushLockShared 
 
_DWORD *__fastcall ExfReleasePushLockShared(_DWORD *result)
{
  unsigned int v1; // r4
  unsigned int v2; // r1
  unsigned int v3; // r2
  int v4; // r2
  int v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r5
  int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r1
  signed int v11; // r1

  __pld(result);
  v1 = *result;
  if ( (*result & 2) == 0 )
  {
    do
    {
      v2 = v1 - 16;
      if ( (v1 & 0xFFFFFFF0) == 16 )
        v2 = 0;
      __dmb(0xBu);
      do
        v3 = __ldrex(result);
      while ( v3 == v1 && __strex(v2, result) );
      __dmb(0xBu);
      if ( v3 == v1 )
        return result;
      v1 = v3;
    }
    while ( (v3 & 2) == 0 );
  }
  if ( (v1 & 8) == 0 )
  {
    v4 = -1;
    goto LABEL_11;
  }
  v8 = *(_DWORD *)((v1 & 0xFFFFFFF0) + 0x14);
  if ( !v8 )
    return (_DWORD *)sub_50EC30();
  __dmb(0xBu);
  v9 = (unsigned int *)(v8 + 28);
  do
  {
    v10 = __ldrex(v9);
    v11 = v10 - 1;
  }
  while ( __strex(v11, v9) );
  __dmb(0xBu);
  if ( v11 <= 0 )
  {
    v4 = -9;
LABEL_11:
    while ( 1 )
    {
      v5 = (v1 & 4) != 0 || (v1 & 2) == 0 ? v4 : v4 + 4;
      v6 = v5 + v1;
      __dmb(0xBu);
      do
        v7 = __ldrex(result);
      while ( v7 == v1 && __strex(v6, result) );
      __dmb(0xBu);
      if ( v7 == v1 )
        break;
      v1 = v7;
    }
    if ( (v1 & 4) == 0 && (v1 & 2) != 0 )
      result = (_DWORD *)ExpWakePushLock(result, v6);
  }
  return result;
}
