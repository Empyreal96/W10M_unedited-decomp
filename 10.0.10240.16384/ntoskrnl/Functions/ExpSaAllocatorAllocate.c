// ExpSaAllocatorAllocate 
 
int __fastcall ExpSaAllocatorAllocate(unsigned int *a1, int a2)
{
  int v3; // r7
  int v4; // r9
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r2
  unsigned int *v10; // r6
  unsigned int *v11; // r5
  unsigned int v12; // r8
  unsigned int v13; // r2
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r5
  unsigned int v17; // r2
  int v18; // r0
  int v19; // r2
  unsigned int *v20; // r5
  unsigned int v21; // r2
  unsigned int *v22; // r2
  unsigned int v23; // r0
  unsigned int **v24; // r1
  unsigned int v25; // r2
  unsigned int v26; // r2
  unsigned int v27; // r1

  v3 = 0;
  v4 = -1;
  v6 = KeAbPreAcquire((unsigned int)a1, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(a1);
  while ( !v8 && __strex(0x11u, a1) );
  __dmb(0xBu);
  if ( v8 )
    ExfAcquirePushLockSharedEx(a1, v6, (unsigned int)a1);
  v9 = 1;
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v10 = a1 + 1;
  do
  {
    v11 = (unsigned int *)a1[1];
    if ( v11 != v10 )
    {
      while ( 1 )
      {
        v4 = ExpSaPageGroupAllocateMemory(v11, a2, v9);
        if ( v4 != -1 )
          break;
        v11 = (unsigned int *)*v11;
        if ( v11 == v10 )
        {
          v9 = 1;
          goto LABEL_13;
        }
      }
      if ( !v11[5] )
      {
        __dmb(0xBu);
        v22 = a1 + 9;
        do
          v23 = __ldrex(v22);
        while ( __strex(v23 | 2, v22) );
        __dmb(0xBu);
      }
LABEL_43:
      if ( (a1[9] & 2) != 0 )
      {
        if ( !v3 )
        {
          __dmb(0xBu);
          do
            v25 = __ldrex(a1);
          while ( v25 == 17 && __strex(1u, a1) );
          __dmb(0xBu);
          if ( v25 != 17 )
            goto LABEL_51;
        }
        v3 = 1;
        ExpSaAllocatorOptimizeList(a1);
      }
      if ( v3 )
        goto LABEL_56;
LABEL_51:
      __dmb(0xBu);
      do
        v26 = __ldrex(a1);
      while ( v26 == 17 && __strex(0, a1) );
      if ( v26 != 17 )
        ExfReleasePushLockShared(a1);
      goto LABEL_61;
    }
LABEL_13:
    v12 = a1[1];
    if ( !v3 )
    {
      __dmb(0xBu);
      do
        v13 = __ldrex(a1);
      while ( v13 == 17 && __strex(1u, a1) );
      __dmb(0xBu);
      if ( v13 == 17 )
        goto LABEL_29;
      __dmb(0xBu);
      do
        v14 = __ldrex(a1);
      while ( v14 == 17 && __strex(0, a1) );
      if ( v14 != 17 )
        ExfReleasePushLockShared(a1);
      KeAbPostRelease((unsigned int)a1);
      v15 = KeAbPreAcquire((unsigned int)a1, 0, 0);
      v16 = v15;
      do
        v17 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v17 | 1, (unsigned __int8 *)a1) );
      __dmb(0xBu);
      if ( (v17 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(a1, v15, (unsigned int)a1);
      if ( !v16 )
      {
LABEL_29:
        v9 = 1;
      }
      else
      {
        v9 = 1;
        *(_BYTE *)(v16 + 14) |= 1u;
      }
    }
    v3 = 1;
  }
  while ( v12 != a1[1] );
  v18 = ExpSaPageGroupDescriptorAllocate(a1, a1[9] & 1);
  v20 = (unsigned int *)v18;
  if ( v18 )
  {
    v4 = ExpSaPageGroupAllocateMemory(v18, a2, v19);
    if ( v20[5] )
    {
      v20[6] = 0;
      v21 = *v10;
      *v20 = *v10;
      v20[1] = (unsigned int)v10;
      if ( *(unsigned int **)(v21 + 4) != v10 )
        __fastfail(3u);
      *(_DWORD *)(v21 + 4) = v20;
      *v10 = (unsigned int)v20;
    }
    else
    {
      v20[6] = 1;
      v24 = (unsigned int **)a1[4];
      *v20 = (unsigned int)(a1 + 3);
      v20[1] = (unsigned int)v24;
      if ( *v24 != a1 + 3 )
        __fastfail(3u);
      *v24 = v20;
      a1[4] = (unsigned int)v20;
    }
    goto LABEL_43;
  }
LABEL_56:
  __dmb(0xBu);
  do
    v27 = __ldrex(a1);
  while ( __strex(v27 - 1, a1) );
  if ( (v27 & 2) != 0 && (v27 & 4) == 0 )
    ExfTryToWakePushLock(a1);
LABEL_61:
  KeAbPostRelease((unsigned int)a1);
  return v4;
}
