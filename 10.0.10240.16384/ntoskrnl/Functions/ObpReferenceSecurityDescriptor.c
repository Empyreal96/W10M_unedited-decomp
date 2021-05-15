// ObpReferenceSecurityDescriptor 
 
int __fastcall ObpReferenceSecurityDescriptor(int a1)
{
  unsigned int *v1; // r6
  unsigned int v2; // r1
  unsigned int v3; // r4
  bool v4; // zf
  unsigned int v5; // r5
  unsigned int *v7; // r2
  int v8; // r0
  unsigned int v9; // r1
  int i; // r3
  unsigned int v11; // r0
  unsigned int v12; // r2
  unsigned int *v13; // r7
  int v14; // r0
  unsigned int v15; // r2
  unsigned int *v16; // r2
  int v17; // r4
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  int v21; // r3

  v1 = (unsigned int *)(a1 + 20);
  __pld((void *)(a1 + 20));
  v2 = *(_DWORD *)(a1 + 20);
  if ( (v2 & 7) != 0 )
  {
    do
    {
      do
        v3 = __ldrex(v1);
      while ( v3 == v2 && __strex(v2 - 1, v1) );
      __dmb(0xBu);
      if ( v3 == v2 )
        break;
      v2 = v3;
    }
    while ( (v3 & 7) != 0 );
  }
  v4 = (v2 & 7) == 1;
  v5 = v2 & 0xFFFFFFF8;
  if ( (v2 & 7) != 0 )
    goto LABEL_6;
  if ( !v5 )
  {
    v4 = 0;
LABEL_6:
    if ( !v4 )
      return v5;
    v7 = (unsigned int *)(v5 - 8);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 + 7, v7) );
    if ( v8 <= 0 )
      __fastfail(0xEu);
LABEL_11:
    __pld(v1);
    v9 = *v1;
    for ( i = *v1 & 7; (unsigned int)(i + 7) <= 7 && v5 == (v9 & 0xFFFFFFF8); i = v11 & 7 )
    {
      do
        v11 = __ldrex(v1);
      while ( v11 == v9 && __strex(v9 + 7, v1) );
      __dmb(0xBu);
      if ( v11 == v9 )
        return v5;
      v9 = v11;
    }
    ObDereferenceSecurityDescriptor(v5, 7);
    return v5;
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  v13 = (unsigned int *)(a1 + 8);
  v14 = KeAbPreAcquire(a1 + 8, 0, 0);
  do
    v15 = __ldrex(v13);
  while ( !v15 && __strex(0x11u, v13) );
  __dmb(0xBu);
  if ( !v15 )
  {
    if ( v14 )
      *(_BYTE *)(v14 + 14) |= 1u;
    v5 = *v1 & 0xFFFFFFF8;
    v16 = (unsigned int *)(v5 - 8);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 + 8, v16) );
    if ( v17 <= 0 )
      __fastfail(0xEu);
    __dmb(0xBu);
    do
      v18 = __ldrex(v13);
    while ( v18 == 17 && __strex(0, v13) );
    if ( v18 != 17 )
      ExfReleasePushLockShared(v13);
    v19 = KeAbPostRelease((unsigned int)v13);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v19);
    goto LABEL_11;
  }
  return sub_7E5AEC(v14, 17);
}
