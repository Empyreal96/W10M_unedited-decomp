// PiDqQueryUnlock 
 
unsigned int __fastcall PiDqQueryUnlock(int a1)
{
  unsigned int *v1; // r4
  int v2; // r1
  unsigned int v3; // r0
  unsigned int v4; // r2
  unsigned int result; // r0
  unsigned int v6; // r1
  __int16 v7; // r3

  v1 = (unsigned int *)(a1 + 32);
  __pld((void *)(a1 + 32));
  v2 = *(_DWORD *)(a1 + 32);
  if ( (v2 & 0xFFFFFFF0) > 0x10 )
    v3 = v2 - 16;
  else
    v3 = 0;
  if ( (v2 & 2) != 0 )
    goto LABEL_13;
  __dmb(0xBu);
  do
    v4 = __ldrex(v1);
  while ( v4 == v2 && __strex(v3, v1) );
  if ( v4 != v2 )
LABEL_13:
    ExfReleasePushLock(v1, v2);
  result = KeAbPostRelease((unsigned int)v1);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 )
    result = sub_7C768C(result);
  return result;
}
