// FsRtlTeardownPerFileContexts 
 
unsigned int *__fastcall FsRtlTeardownPerFileContexts(unsigned int *result, int a2)
{
  unsigned int v2; // r4
  int v3; // r3
  _DWORD **v4; // r5
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  _DWORD *v9; // r3
  _DWORD *v10; // r6
  _DWORD *v11; // r2
  int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r6
  unsigned int v21; // r2
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3

  __dmb(0xBu);
  do
    v2 = __ldrex(result);
  while ( __strex(0, result) );
  __dmb(0xBu);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 12);
    if ( v3 )
    {
      (*(void (__fastcall **)(_DWORD, int, _DWORD))(v3 + 16))(*(_DWORD *)(v2 + 12), a2, 0);
      *(_DWORD *)(v2 + 12) = 0;
    }
    v4 = (_DWORD **)(v2 + 4);
    if ( *(_DWORD *)(v2 + 4) != v2 + 4 )
    {
      v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v5 + 308);
      v6 = KeAbPreAcquire(v2, 0, 0);
      v7 = v6;
      do
        v8 = __ldrex((unsigned __int8 *)v2);
      while ( __strex(v8 | 1, (unsigned __int8 *)v2) );
      __dmb(0xBu);
      if ( (v8 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)v2, v6, v2);
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      while ( 1 )
      {
        v9 = *v4;
        if ( *v4 == v4 )
          break;
        v10 = *v4;
        v11 = (_DWORD *)*v9;
        if ( (_DWORD **)v9[1] != v4 || (_DWORD *)v11[1] != v10 )
          __fastfail(3u);
        *v4 = v11;
        v11[1] = v4;
        __pld((void *)v2);
        v12 = *(_DWORD *)v2;
        if ( (*(_DWORD *)v2 & 0xFFFFFFF0) <= 0x10 )
          v13 = 0;
        else
          v13 = v12 - 16;
        if ( (v12 & 2) != 0 )
          goto LABEL_24;
        __dmb(0xBu);
        do
          v14 = __ldrex((unsigned int *)v2);
        while ( v14 == v12 && __strex(v13, (unsigned int *)v2) );
        if ( v14 != v12 )
LABEL_24:
          ExfReleasePushLock((_DWORD *)v2, v12);
        v15 = KeAbPostRelease(v2);
        v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v17 = *(_WORD *)(v16 + 0x134) + 1;
        *(_WORD *)(v16 + 308) = v17;
        if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
          KiCheckForKernelApcDelivery(v15);
        ((void (__fastcall *)(_DWORD *))v10[4])(v10);
        v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v18 + 308);
        v19 = KeAbPreAcquire(v2, 0, 0);
        v20 = v19;
        do
          v21 = __ldrex((unsigned __int8 *)v2);
        while ( __strex(v21 | 1, (unsigned __int8 *)v2) );
        __dmb(0xBu);
        if ( (v21 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)v2, v19, v2);
        if ( v20 )
          *(_BYTE *)(v20 + 14) |= 1u;
      }
      __pld((void *)v2);
      v22 = *(_DWORD *)v2;
      if ( (*(_DWORD *)v2 & 0xFFFFFFF0) <= 0x10 )
        v23 = 0;
      else
        v23 = v22 - 16;
      if ( (v22 & 2) != 0 )
        goto LABEL_45;
      __dmb(0xBu);
      do
        v24 = __ldrex((unsigned int *)v2);
      while ( v24 == v22 && __strex(v23, (unsigned int *)v2) );
      if ( v24 != v22 )
LABEL_45:
        ExfReleasePushLock((_DWORD *)v2, v22);
      v25 = KeAbPostRelease(v2);
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = *(_WORD *)(v26 + 0x134) + 1;
      *(_WORD *)(v26 + 308) = v27;
      if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
        KiCheckForKernelApcDelivery(v25);
    }
    result = (unsigned int *)ExFreePoolWithTag(v2);
  }
  return result;
}
