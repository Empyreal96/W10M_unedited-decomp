// EtwpReferenceLoggerSecurityDescriptor 
 
int __fastcall EtwpReferenceLoggerSecurityDescriptor(int a1)
{
  unsigned int *v1; // r4
  int v2; // r1
  unsigned int v3; // r0
  int v5; // r5
  unsigned int *v6; // r2
  int v7; // r0
  unsigned int v8; // r1
  int i; // r3
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  unsigned int *v15; // r2
  int v16; // r4
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r3

  v1 = (unsigned int *)(a1 + 576);
  __pld((void *)(a1 + 576));
  v2 = *(_DWORD *)(a1 + 576);
  if ( (v2 & 7) != 0 )
  {
    do
      v3 = __ldrex(v1);
    while ( v3 == v2 && __strex(v2 - 1, v1) );
    __dmb(0xBu);
    if ( v3 != v2 )
      return sub_80983C();
  }
  if ( (v2 & 7) != 0 )
  {
    v5 = v2 & 0xFFFFFFF8;
    if ( (v2 & 7) == 1 )
    {
      v6 = (unsigned int *)(v5 - 8);
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 + 7, v6) );
      if ( v7 <= 0 )
        __fastfail(0xEu);
      __pld(v1);
      v8 = *v1;
      for ( i = *v1 & 7; (unsigned int)(i + 7) <= 7 && v5 == (v8 & 0xFFFFFFF8); i = v10 & 7 )
      {
        do
          v10 = __ldrex(v1);
        while ( v10 == v8 && __strex(v8 + 7, v1) );
        __dmb(0xBu);
        if ( v10 == v8 )
          return v5;
        v8 = v10;
      }
      ObDereferenceSecurityDescriptor(v5, 7);
    }
  }
  else
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v11 + 308);
    v12 = KeAbPreAcquire((unsigned int)&EtwpSecurityLock, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex((unsigned int *)&EtwpSecurityLock);
    while ( !v14 && __strex(0x11u, (unsigned int *)&EtwpSecurityLock) );
    __dmb(0xBu);
    if ( v14 )
      ExfAcquirePushLockSharedEx(&EtwpSecurityLock, v12, (unsigned int)&EtwpSecurityLock);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    v5 = *v1 & 0xFFFFFFF8;
    v15 = (unsigned int *)(v5 - 8);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 + 1, v15) );
    if ( v16 <= 0 )
      __fastfail(0xEu);
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&EtwpSecurityLock);
    while ( v17 == 17 && __strex(0, (unsigned int *)&EtwpSecurityLock) );
    if ( v17 != 17 )
      ExfReleasePushLockShared(&EtwpSecurityLock);
    v18 = KeAbPostRelease((unsigned int)&EtwpSecurityLock);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(v18);
  }
  return v5;
}
