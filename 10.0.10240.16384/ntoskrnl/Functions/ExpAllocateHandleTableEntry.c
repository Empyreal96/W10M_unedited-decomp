// ExpAllocateHandleTableEntry 
 
int __fastcall ExpAllocateHandleTableEntry(int a1, _DWORD *a2)
{
  int result; // r0
  unsigned int v5; // r5
  unsigned int v6; // r1
  unsigned int v7; // r8
  unsigned int i; // r9
  unsigned __int8 *v9; // r4
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  int v13; // r5
  int v14; // r3
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r1
  int v18; // r8
  unsigned int v19; // r1
  unsigned int v20; // r1
  unsigned __int8 *v21; // r5
  int v22; // r9
  int v23; // r0
  int v24; // r4
  unsigned int v25; // r2
  unsigned int v26; // r1
  int v27; // [sp+0h] [bp-20h]

  if ( (*(_BYTE *)(a1 + 28) & 4) != 0 )
    return sub_7F76A0();
  do
  {
    v27 = *(_DWORD *)a1;
    if ( (*(_BYTE *)(a1 + 28) & 1) != 0 )
    {
      v5 = dword_92038C;
      v7 = 0;
    }
    else
    {
      v5 = dword_92038C;
      v6 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
      if ( !dword_92038C )
        __brkdiv0();
      v7 = v6 % dword_92038C;
    }
    for ( i = 0; i < v5; ++i )
    {
      v9 = (unsigned __int8 *)(a1 + 52 * v7 + 40);
      if ( *(_DWORD *)(a1 + 52 * v7 + 44) )
      {
        v10 = KeAbPreAcquire((unsigned int)v9, 0, 0);
        v11 = v10;
        do
          v12 = __ldrex(v9);
        while ( __strex(v12 | 1, v9) );
        __dmb(0xBu);
        if ( (v12 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v9, v10, (unsigned int)v9);
        if ( v11 )
          *(_BYTE *)(v11 + 14) |= 1u;
        v13 = *(_DWORD *)(a1 + 52 * v7 + 44);
        if ( v13 )
        {
          v14 = *(_DWORD *)(v13 + 4);
          *(_DWORD *)(a1 + 52 * v7 + 44) = v14;
          if ( !v14 )
            *(_DWORD *)(a1 + 52 * v7 + 48) = 0;
          v15 = *(_DWORD *)(a1 + 52 * v7 + 52) + 1;
          v16 = *(_DWORD *)(a1 + 52 * v7 + 56);
          *(_DWORD *)(a1 + 52 * v7 + 52) = v15;
          if ( v15 > v16 )
            *(_DWORD *)(a1 + 52 * v7 + 56) = v15;
        }
        __dmb(0xBu);
        do
          v17 = __ldrex((unsigned int *)v9);
        while ( __strex(v17 - 1, (unsigned int *)v9) );
        if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v9);
        KeAbPostRelease((unsigned int)v9);
        if ( v13 )
        {
          result = v13;
          *a2 = *(_DWORD *)((v13 & 0xFFFFF000) + 4) + 4 * ((int)(v13 - (v13 & 0xFFFFF000)) >> 3);
          return result;
        }
        v5 = dword_92038C;
      }
      if ( ++v7 >= v5 )
        v7 = 0;
    }
    v18 = 1;
    if ( (*(_BYTE *)(a1 + 28) & 1) != 0 )
    {
      v20 = 0;
    }
    else
    {
      v19 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
      if ( !dword_92038C )
        __brkdiv0();
      v20 = v19 % dword_92038C;
    }
    v21 = (unsigned __int8 *)(a1 + 36);
    v22 = a1 + 52 * v20;
    v23 = KeAbPreAcquire(a1 + 36, 0, 0);
    v24 = v23;
    do
      v25 = __ldrex(v21);
    while ( __strex(v25 | 1, v21) );
    __dmb(0xBu);
    if ( (v25 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 36), v23, a1 + 36);
    if ( v24 )
      *(_BYTE *)(v24 + 14) |= 1u;
    if ( v27 == *(_DWORD *)a1 )
      v18 = ExpAllocateHandleTableEntrySlow((int *)a1, v22 + 40, v27, *(_DWORD *)a1);
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)v21);
    while ( __strex(v26 - 1, (unsigned int *)v21) );
    if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(a1 + 36));
    KeAbPostRelease(a1 + 36);
  }
  while ( v18 );
  return 0;
}
