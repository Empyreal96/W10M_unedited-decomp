// AlpcpFlushResourcesPort 
 
unsigned int __fastcall AlpcpFlushResourcesPort(int a1)
{
  unsigned __int8 *v1; // r5
  _DWORD *v2; // r7
  int v3; // r0
  unsigned int v4; // r2
  _DWORD *v6; // r4
  unsigned int v7; // r1
  __int64 v8; // r2
  int v9; // r6
  bool v10; // zf
  unsigned int *v11; // lr
  int v12; // r0
  int v13; // r1
  unsigned int v14; // r1
  unsigned int *v15; // r2
  unsigned int v16; // r1
  int v17; // r1
  unsigned int *v18; // r2
  unsigned int v19; // r1
  int v20; // r1
  int v21; // r0
  int v22; // r4
  unsigned int v23; // r2

  v1 = (unsigned __int8 *)(a1 + 196);
  v2 = (_DWORD *)(a1 + 200);
  v3 = KeAbPreAcquire(a1 + 196, 0, 0);
  do
    v4 = __ldrex(v1);
  while ( __strex(v4 | 1, v1) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_806EF4(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  while ( 1 )
  {
    v6 = (_DWORD *)*v2;
    if ( (_DWORD *)*v2 == v2 )
      break;
    v8 = *(_QWORD *)v6;
    if ( (_DWORD *)v6[1] != v2 || *(_DWORD **)(v8 + 4) != v6 )
      __fastfail(3u);
    *v2 = v8;
    *(_DWORD *)(v8 + 4) = v2;
    *v6 = v6;
    v6[1] = v6;
    v9 = v6[3];
    v10 = v9 == 0;
    if ( v9 <= 0 )
    {
LABEL_42:
      if ( !v10 )
        KeBugCheckEx(24, 0, (int)(v6 + 6), 32, v9);
    }
    else
    {
      v11 = v6 + 3;
      while ( 1 )
      {
        v12 = v9;
        __dmb(0xBu);
        do
          v13 = __ldrex(v11);
        while ( v13 == v9 && __strex(v9 + 1, v11) );
        v9 = v13;
        __dmb(0xBu);
        if ( v13 == v12 )
          break;
        if ( v13 <= 0 )
        {
          v10 = v13 == 0;
          goto LABEL_42;
        }
      }
      if ( v13 != -1 )
      {
        __dmb(0xBu);
        do
          v14 = __ldrex((unsigned int *)v1);
        while ( __strex(v14 - 1, (unsigned int *)v1) );
        if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v1);
        KeAbPostRelease((unsigned int)v1);
        if ( AlpcpDeleteBlob((int)(v6 + 6)) )
        {
          __dmb(0xBu);
          v15 = v6 + 3;
          do
          {
            v16 = __ldrex(v15);
            v17 = v16 - 1;
          }
          while ( __strex(v17, v15) );
          __dmb(0xBu);
          if ( v17 <= 0 )
          {
            if ( v17 )
              KeBugCheckEx(24, 0, (int)(v6 + 6), 33, v17);
            AlpcpDestroyBlob((int)(v6 + 6));
          }
        }
        __dmb(0xBu);
        v18 = v6 + 3;
        do
        {
          v19 = __ldrex(v18);
          v20 = v19 - 1;
        }
        while ( __strex(v20, v18) );
        __dmb(0xBu);
        if ( v20 <= 0 )
        {
          if ( v20 )
            KeBugCheckEx(24, 0, (int)(v6 + 6), 33, v20);
          AlpcpDestroyBlob((int)(v6 + 6));
        }
        v21 = KeAbPreAcquire((unsigned int)v1, 0, 0);
        v22 = v21;
        do
          v23 = __ldrex(v1);
        while ( __strex(v23 | 1, v1) );
        __dmb(0xBu);
        if ( (v23 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v1, v21, (unsigned int)v1);
        if ( v22 )
          *(_BYTE *)(v22 + 14) |= 1u;
      }
    }
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)v1);
  while ( __strex(v7 - 1, (unsigned int *)v1) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v1);
  return KeAbPostRelease((unsigned int)v1);
}
