// sub_7DD860 
 
void __fastcall sub_7DD860(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r4
  int v8; // r5
  _DWORD *v10; // r3
  int v11; // r6
  unsigned int *v12; // r4
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned int v20; // r2
  unsigned int *v21; // r7
  int v22; // r0
  int v23; // r4
  unsigned int v24; // r2

  v10 = (_DWORD *)a5;
  while ( 1 )
  {
    v11 = ObpGetShadowDirectory(v10, a2, a3, (int)v10);
    if ( v11 )
    {
      if ( *(_BYTE *)(v8 + 18) )
      {
        ObfReferenceObject(a5);
        v12 = (unsigned int *)(a5 + 148);
        __pld((void *)(a5 + 148));
        v13 = *v12;
        if ( (*v12 & 0xFFFFFFF0) <= 0x10 )
          v14 = 0;
        else
          v14 = v13 - 16;
        if ( (v13 & 2) != 0 )
          goto LABEL_12;
        __dmb(0xBu);
        do
          v15 = __ldrex(v12);
        while ( v15 == v13 && __strex(v14, v12) );
        if ( v15 != v13 )
LABEL_12:
          ExfReleasePushLock(v12, v13);
        KeAbPostRelease((unsigned int)v12);
        v16 = *(_DWORD *)v8;
        *(_DWORD *)(v8 + 20) = -286387660;
        v17 = ObfDereferenceObject(v16);
        *(_DWORD *)v8 = 0;
        *(_BYTE *)(v8 + 18) = 0;
        *(_BYTE *)(v8 + 19) = 0;
        v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v19 = *(_WORD *)(v18 + 0x134) + 1;
        *(_WORD *)(v18 + 308) = v19;
        if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
          KiCheckForKernelApcDelivery(v17);
        *(_DWORD *)(v8 + 20) = -1145368012;
        v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v20 + 308);
        v21 = (unsigned int *)(v11 + 148);
        v22 = KeAbPreAcquire(v11 + 148, 0, 0);
        v23 = v22;
        do
          v24 = __ldrex(v21);
        while ( !v24 && __strex(0x11u, v21) );
        __dmb(0xBu);
        if ( v24 )
          ExfAcquirePushLockSharedEx((_DWORD *)(v11 + 148), v22, v11 + 148);
        if ( v23 )
          *(_BYTE *)(v23 + 14) |= 1u;
        *(_DWORD *)(v8 + 20) = -572714444;
        ObfReferenceObject(v11);
        *(_BYTE *)(v8 + 18) = 1;
        *(_BYTE *)(v8 + 19) = 0;
        *(_DWORD *)v8 = v11;
        ObfDereferenceObject(a5);
      }
      v7 = ObpLookupDirectoryUsingHash(v11, a7, v8, a6);
    }
    v10 = (_DWORD *)v11;
    a5 = v11;
    if ( v7 || !v11 )
      JUMPOUT(0x6EB202);
  }
}
