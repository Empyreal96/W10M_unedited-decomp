// ExpFreeHandleTableEntry 
 
unsigned int __fastcall ExpFreeHandleTableEntry(int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r1
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r2
  int v11; // r3
  int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r1
  int v15; // r0
  int v16; // r6
  unsigned int v17; // r2
  int v18; // r3
  int v19; // r3
  unsigned int varg_r1; // [sp+24h] [bp+Ch]
  int varg_r2; // [sp+28h] [bp+10h]

  varg_r2 = a3;
  varg_r1 = a2 & 0xFFFFFFFC;
  if ( *(_DWORD *)(a1 + 4) )
    return sub_7F7194();
  if ( (*(_BYTE *)(a1 + 28) & 1) != 0 )
  {
    v6 = 0;
  }
  else
  {
    v14 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    if ( !dword_92038C )
      __brkdiv0();
    v6 = v14 % dword_92038C;
  }
  *(_DWORD *)(a3 + 4) = 0;
  v7 = a1 + 52 * v6 + 40;
  if ( (*(_BYTE *)(a1 + 28) & 1) != 0 )
  {
    v8 = KeAbPreAcquire(v7, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex((unsigned __int8 *)v7);
    while ( __strex(v10 | 1, (unsigned __int8 *)v7) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)v7, v8, v7);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    v11 = *(_DWORD *)(v7 + 8);
    if ( v11 )
      *(_DWORD *)(v11 + 4) = a3;
    else
      *(_DWORD *)(v7 + 4) = a3;
    v12 = *(_DWORD *)(v7 + 12);
    *(_DWORD *)(v7 + 8) = a3;
    *(_DWORD *)(v7 + 12) = v12 - 1;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)v7);
    while ( __strex(v13 - 1, (unsigned int *)v7) );
  }
  else
  {
    v15 = KeAbPreAcquire(v7, 0, 0);
    v16 = v15;
    do
      v17 = __ldrex((unsigned __int8 *)v7);
    while ( __strex(v17 | 1, (unsigned __int8 *)v7) );
    __dmb(0xBu);
    if ( (v17 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)v7, v15, v7);
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    v18 = *(_DWORD *)(v7 + 4);
    *(_DWORD *)(a3 + 4) = v18;
    if ( !v18 )
      *(_DWORD *)(v7 + 8) = a3;
    v19 = *(_DWORD *)(v7 + 12);
    *(_DWORD *)(v7 + 4) = a3;
    *(_DWORD *)(v7 + 12) = v19 - 1;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)v7);
    while ( __strex(v13 - 1, (unsigned int *)v7) );
  }
  if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v7);
  return KeAbPostRelease(v7);
}
