// sub_7C00AC 
 
void sub_7C00AC()
{
  int v0; // r5
  unsigned int v1; // r7
  _DWORD **i; // r9
  _DWORD *v3; // r4
  __int64 **v4; // r6
  __int64 *v5; // r0
  __int64 v6; // r2
  _DWORD *v7; // r8
  unsigned int *v8; // r4
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  unsigned int v13; // r4

  if ( RtlpLockAtomTable((_DWORD *)v0) )
  {
    v1 = 0;
    for ( i = (_DWORD **)(v0 + 24); v1 < *(_DWORD *)(v0 + 20); ++v1 )
    {
      v3 = *i;
      *i++ = 0;
      while ( 1 )
      {
        v7 = v3;
        if ( !v3 )
          break;
        v3 = (_DWORD *)*v3;
        *v7 = 0;
        v4 = (__int64 **)(v7 + 2);
        while ( *v4 != (__int64 *)v4 )
        {
          v5 = *v4;
          v6 = **v4;
          if ( (__int64 **)HIDWORD(v6) != v4 || *(__int64 **)(v6 + 4) != v5 )
            __fastfail(3u);
          *v4 = (__int64 *)v6;
          *(_DWORD *)(v6 + 4) = v4;
          RtlpFreeAtom((int)v5);
        }
        RtlpFreeAtom((int)v7);
      }
    }
    *(_DWORD *)v0 = 0;
    v8 = (unsigned int *)(v0 + 8);
    __dmb(0xBu);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 - 1, v8) );
    if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v0 + 8));
    v10 = KeAbPostRelease(v0 + 8);
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x134) + 1;
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      KiCheckForKernelApcDelivery(v10);
    v13 = *(_DWORD *)(v0 + 12);
    ExpRemoveHandleTable(v13);
    ExpFreeHandleTable(v13);
    memset((_BYTE *)v0, 0, 28);
    RtlpFreeAtom(v0);
    JUMPOUT(0x6A5F80);
  }
  JUMPOUT(0x6A5F82);
}
