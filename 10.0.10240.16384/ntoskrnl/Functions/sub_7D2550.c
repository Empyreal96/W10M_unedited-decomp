// sub_7D2550 
 
_DWORD *__fastcall sub_7D2550(int a1, int a2)
{
  unsigned int v2; // r2
  unsigned int *v4; // r4
  _DWORD *v5; // r5

  if ( (a2 & 2) != 0 )
    goto LABEL_2;
  __dmb(0xBu);
  do
    v2 = __ldrex(v4);
  while ( v2 == a2 && __strex(a2 - 16, v4) );
  if ( v2 != a2 )
LABEL_2:
    ExfReleasePushLock(v4, a2);
  KeAbPostRelease((unsigned int)v4);
  return CmpDereferenceHive(v5);
}
