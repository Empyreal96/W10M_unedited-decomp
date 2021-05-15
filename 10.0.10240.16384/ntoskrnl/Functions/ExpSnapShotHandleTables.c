// ExpSnapShotHandleTables 
 
int __fastcall ExpSnapShotHandleTables(int a1, _DWORD *a2, int a3, int a4, char a5)
{
  unsigned int v6; // r6
  int v7; // r10
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  void **v11; // r5
  int v12; // r6
  int v13; // r4
  int i; // r8
  _DWORD *v15; // r0
  _DWORD *v16; // r7
  int v18; // r0
  unsigned int v19; // r1
  int (__fastcall *v20)(_DWORD **, void *, _DWORD *, int, int, int); // lr
  unsigned int v21; // r1
  unsigned int v22; // r2
  int v23; // r0
  __int16 v24; // r3
  _DWORD *v26; // [sp+8h] [bp-30h] BYREF
  int v27; // [sp+Ch] [bp-2Ch]
  int v28; // [sp+10h] [bp-28h]
  int (__fastcall *v29)(_DWORD **, void *, _DWORD *, int, int, int); // [sp+14h] [bp-24h]
  unsigned int v30; // [sp+18h] [bp-20h]

  v27 = a3;
  v28 = a4;
  v29 = (int (__fastcall *)(_DWORD **, void *, _DWORD *, int, int, int))a1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v30 = v6;
  v7 = 0;
  if ( a5 )
    v26 = a2 + 2;
  else
    v26 = a2 + 1;
  *a2 = 0;
  --*(_WORD *)(v6 + 308);
  v8 = KeAbPreAcquire((unsigned int)&HandleTableListLock, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned int *)&HandleTableListLock);
  while ( !v10 && __strex(0x11u, (unsigned int *)&HandleTableListLock) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(&HandleTableListLock, v8, (unsigned int)&HandleTableListLock);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = (void **)HandleTableListHead;
  if ( HandleTableListHead != &HandleTableListHead )
  {
    v12 = v27;
    do
    {
      v13 = v28;
      for ( i = 0; ; i += 4 )
      {
        v15 = (_DWORD *)ExpLookupHandleTableEntry((int)(v11 - 4), i);
        v16 = v15;
        if ( !v15 )
          break;
        if ( (i & 0x7FC) != 0 && *v15 )
        {
          do
          {
            while ( 1 )
            {
              __pld(v16);
              v18 = *v16;
              if ( (*v16 & 1) != 0 )
                break;
              if ( !v18 )
                goto LABEL_28;
              ExpBlockOnLockedHandleEntry((int)(v11 - 4), (unsigned __int64 *)v16, *v16);
            }
            do
              v19 = __ldrex(v16);
            while ( v19 == v18 && __strex(v18 - 1, v16) );
            __dmb(0xBu);
          }
          while ( v19 != v18 );
          v20 = v29;
          ++*a2;
          v7 = v20(&v26, v11[2], v16, i, v12, v13);
          __dmb(0xBu);
          do
            v21 = __ldrex(v16);
          while ( __strex(v21 + 1, v16) );
          __dmb(0xBu);
          __dmb(0xFu);
          if ( v11[4] )
            ExfUnblockPushLock((int)(v11 + 4), 0);
        }
LABEL_28:
        ;
      }
      v11 = (void **)*v11;
    }
    while ( v11 != &HandleTableListHead );
    v6 = v30;
  }
  __dmb(0xBu);
  do
    v22 = __ldrex((unsigned int *)&HandleTableListLock);
  while ( v22 == 17 && __strex(0, (unsigned int *)&HandleTableListLock) );
  if ( v22 != 17 )
    ExfReleasePushLockShared(&HandleTableListLock);
  v23 = KeAbPostRelease((unsigned int)&HandleTableListLock);
  v24 = *(_WORD *)(v6 + 308) + 1;
  *(_WORD *)(v6 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v23);
  return v7;
}
