// PsSwapImpersonationToken 
 
int __fastcall PsSwapImpersonationToken(_DWORD *a1, int a2, int a3)
{
  unsigned int *v3; // r7
  int v6; // r10
  unsigned int v7; // r5
  int v8; // r9
  int v9; // r6
  unsigned __int8 *v10; // r0
  unsigned int v11; // r2
  int v12; // r6
  unsigned int v13; // r1
  unsigned int v14; // r1
  int v15; // r0
  __int16 v16; // r3
  int v18; // r0

  v3 = a1 + 240;
  v6 = 0;
  if ( (a1[240] & 8) != 0 )
  {
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v8 = 0;
    ObfReferenceObject(a3);
    --*(_WORD *)(v7 + 308);
    v9 = KeAbPreAcquire((unsigned int)(a1 + 236), 0, 0);
    v10 = (unsigned __int8 *)(a1 + 236);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 1, v10) );
    __dmb(0xBu);
    if ( (v11 & 1) != 0 )
    {
      ExfAcquirePushLockExclusiveEx(v10, v9, (unsigned int)(a1 + 236));
      v10 = (unsigned __int8 *)(a1 + 236);
    }
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    if ( (*v3 & 8) != 0 )
    {
      if ( (a1[226] & 0xFFFFFFF8) == a2 && (a1[240] & 0x100) != 0 )
      {
        v12 = a3;
        v6 = a1[263];
        a1[226] = a1[226] & 7 | a3;
        a1[263] = 0;
        __dmb(0xBu);
        do
          v13 = __ldrex(v3);
        while ( __strex(v13 & 0xFFFFFEFF, v3) );
        __dmb(0xBu);
LABEL_14:
        __dmb(0xBu);
        do
          v14 = __ldrex((unsigned int *)v10);
        while ( __strex(v14 - 1, (unsigned int *)v10) );
        if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
        {
          ExfTryToWakePushLock((unsigned int *)v10);
          v10 = (unsigned __int8 *)(a1 + 236);
        }
        v15 = KeAbPostRelease((unsigned int)v10);
        v16 = *(_WORD *)(v7 + 308) + 1;
        *(_WORD *)(v7 + 308) = v16;
        if ( !v16 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
          KiCheckForKernelApcDelivery(v15);
        if ( v8 < 0 )
        {
          v18 = v12;
        }
        else
        {
          ObfDereferenceObject(a2);
          if ( !v6 )
            return v8;
          v18 = v6;
        }
        ObfDereferenceObject(v18);
        return v8;
      }
      v8 = -1073741823;
    }
    else
    {
      v8 = -1073741700;
    }
    v12 = a3;
    goto LABEL_14;
  }
  return sub_7C51F0();
}
