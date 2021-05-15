// CmpUnlockTwoKcbs 
 
_DWORD *__fastcall CmpUnlockTwoKcbs(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r4
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int *v6; // r5
  int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r2
  unsigned int v10; // r2
  unsigned int v11; // r3

  v2 = result;
  if ( !result )
  {
    if ( !a2 )
      return result;
    v2 = a2;
    goto LABEL_5;
  }
  if ( !a2 )
  {
LABEL_5:
    if ( v2[8] == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    {
      v2[8] = 0;
    }
    else
    {
      __dmb(0xBu);
      v4 = v2 + 8;
      do
        v5 = __ldrex(v4);
      while ( __strex(v5 - 1, v4) );
      __dmb(0xBu);
    }
    v6 = v2 + 7;
    __pld(v2 + 7);
    v7 = v2[7];
    if ( (v7 & 0xFFFFFFF0) > 0x10 )
      v8 = v7 - 16;
    else
      v8 = 0;
    if ( (v7 & 2) != 0 )
      goto LABEL_25;
    __dmb(0xBu);
    do
      v9 = __ldrex(v6);
    while ( v9 == v7 && __strex(v8, v6) );
    if ( v9 != v7 )
LABEL_25:
      ExfReleasePushLock(v2 + 7, v7);
    result = (_DWORD *)KeAbPostRelease((unsigned int)(v2 + 7));
    if ( (v2[1] & 0x100000) != 0 )
      return (_DWORD *)sub_7FEDB4(result);
    if ( (v2[1] & 0x80000) != 0 )
      result = (_DWORD *)CmpFreeKeyControlBlock((unsigned int)v2);
    return result;
  }
  v10 = (result[1] >> 21) & 0x3FF;
  v11 = (a2[1] >> 21) & 0x3FF;
  if ( v10 < v11 )
    goto LABEL_23;
  if ( v10 > v11 )
  {
    CmpUnlockKcb(result);
    return (_DWORD *)CmpUnlockKcb(a2);
  }
  if ( result < a2 )
  {
LABEL_23:
    CmpUnlockKcb(a2);
    return (_DWORD *)CmpUnlockKcb(v2);
  }
  if ( result > a2 )
  {
    CmpUnlockKcb(result);
    result = a2;
  }
  return (_DWORD *)CmpUnlockKcb(result);
}
