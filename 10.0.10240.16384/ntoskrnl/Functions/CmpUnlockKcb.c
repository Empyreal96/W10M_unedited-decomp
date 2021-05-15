// CmpUnlockKcb 
 
int __fastcall CmpUnlockKcb(_DWORD *a1)
{
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int *v4; // r5
  int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r2
  int result; // r0

  if ( a1[8] == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
  {
    a1[8] = 0;
  }
  else
  {
    __dmb(0xBu);
    v2 = a1 + 8;
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 - 1, v2) );
    __dmb(0xBu);
  }
  v4 = a1 + 7;
  __pld(a1 + 7);
  v5 = a1[7];
  if ( (v5 & 0xFFFFFFF0) > 0x10 )
    v6 = v5 - 16;
  else
    v6 = 0;
  if ( (v5 & 2) != 0 )
    goto LABEL_19;
  __dmb(0xBu);
  do
    v7 = __ldrex(v4);
  while ( v7 == v5 && __strex(v6, v4) );
  if ( v7 != v5 )
LABEL_19:
    ExfReleasePushLock(a1 + 7, v5);
  result = KeAbPostRelease((unsigned int)(a1 + 7));
  if ( (a1[1] & 0x100000) != 0 )
    return sub_7FE94C(result);
  if ( (a1[1] & 0x80000) != 0 )
    result = CmpFreeKeyControlBlock((unsigned int)a1);
  return result;
}
