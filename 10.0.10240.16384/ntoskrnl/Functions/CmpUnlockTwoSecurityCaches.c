// CmpUnlockTwoSecurityCaches 
 
unsigned int __fastcall CmpUnlockTwoSecurityCaches(int a1, int a2)
{
  unsigned int *v3; // r4
  int v4; // r0
  unsigned int v5; // r5
  unsigned int v6; // r2
  unsigned int *v7; // r4
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r0

  if ( a1 == a2 )
  {
    v7 = (unsigned int *)(a1 + 1928);
    __pld((void *)(a1 + 1928));
    v8 = *(_DWORD *)(a1 + 1928);
    v11 = v8 - 16;
    if ( (v8 & 0xFFFFFFF0) <= 0x10 )
      v11 = 0;
    if ( (v8 & 2) != 0 )
      goto LABEL_24;
    __dmb(0xBu);
    do
      v10 = __ldrex(v7);
    while ( v10 == v8 && __strex(v11, v7) );
  }
  else
  {
    __pld((void *)(a1 + 1928));
    v3 = (unsigned int *)(a1 + 1928);
    v4 = *(_DWORD *)(a1 + 1928);
    v5 = v4 - 16;
    if ( (v4 & 0xFFFFFFF0) <= 0x10 )
      v5 = 0;
    if ( (v4 & 2) != 0 )
      goto LABEL_9;
    __dmb(0xBu);
    do
      v6 = __ldrex(v3);
    while ( v6 == v4 && __strex(v5, v3) );
    if ( v6 != v4 )
LABEL_9:
      ExfReleasePushLock(v3, a2);
    KeAbPostRelease((unsigned int)v3);
    __pld((void *)(a2 + 1928));
    v7 = (unsigned int *)(a2 + 1928);
    v8 = *(_DWORD *)(a2 + 1928);
    v9 = v8 - 16;
    if ( (v8 & 0xFFFFFFF0) <= 0x10 )
      v9 = 0;
    if ( (v8 & 2) != 0 )
      goto LABEL_24;
    __dmb(0xBu);
    do
      v10 = __ldrex(v7);
    while ( v10 == v8 && __strex(v9, v7) );
  }
  if ( v10 != v8 )
LABEL_24:
    ExfReleasePushLock(v7, v8);
  return KeAbPostRelease((unsigned int)v7);
}
