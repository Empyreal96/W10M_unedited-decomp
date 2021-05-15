// WdipSemEnableContextProvider 
 
int __fastcall WdipSemEnableContextProvider(int a1)
{
  int v2; // r8
  unsigned int v3; // r2
  int v4; // r4
  int v5; // r1
  int v6; // r4
  unsigned int v7; // r3
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v10; // lr
  int v11; // r10
  int v12; // r9
  int v13; // r8
  unsigned int v14; // r3
  unsigned int v15; // r0
  int v16; // r3
  int v17; // r4
  unsigned int v18; // r7
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v23; // [sp+10h] [bp-28h]
  char v24; // [sp+14h] [bp-24h]

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&dword_61C764, 0, 0);
  do
    v5 = __ldrex((unsigned __int8 *)&dword_61C764);
  while ( __strex(v5 | 1, (unsigned __int8 *)&dword_61C764) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_61C764, v4, (unsigned int)&dword_61C764);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 32) != 1 )
    {
      v6 = *(_DWORD *)(a1 + 40);
      v7 = *(unsigned __int8 *)(a1 + 18);
      v8 = *(unsigned __int8 *)(v6 + 48);
      v9 = *(_DWORD *)(v6 + 60);
      v5 = *(_DWORD *)(v6 + 56);
      if ( v7 <= v8 )
        v7 = *(unsigned __int8 *)(v6 + 48);
      v10 = v7;
      v24 = v7;
      v11 = v5 | *(_DWORD *)(a1 + 24);
      v12 = v9 | *(_DWORD *)(a1 + 28);
      v13 = *(_DWORD *)(v6 + 64) | *(_DWORD *)(a1 + 36);
      if ( *(_BYTE *)(v6 + 69) && v7 == v8 && v11 == v5 && v12 == v9 && v13 == *(_DWORD *)(v6 + 64) )
      {
        v2 = 0;
        ++*(_DWORD *)(v6 + 72);
      }
      else
      {
        __dmb(0xBu);
        v14 = WdipContextLoggerId;
        do
          v15 = __ldrex((unsigned int *)&WdipContextLoggerId);
        while ( __strex(v14, (unsigned int *)&WdipContextLoggerId) );
        __dmb(0xBu);
        v23 = WdipSemEnableDisableTrace((unsigned __int16)v15, a1, v10);
        if ( v23 >= 0 )
        {
          *(_BYTE *)(v6 + 69) = 1;
          v16 = *(_DWORD *)(v6 + 72);
          *(_DWORD *)(v6 + 56) = v11;
          *(_DWORD *)(v6 + 60) = v12;
          *(_DWORD *)(v6 + 64) = v13;
          *(_DWORD *)(v6 + 72) = v16 + 1;
          *(_BYTE *)(v6 + 48) = v24;
        }
        v2 = v23;
      }
    }
  }
  else
  {
    v2 = -1073741811;
  }
  __pld(&dword_61C764);
  v17 = dword_61C764;
  v18 = dword_61C764 - 16;
  if ( (dword_61C764 & 0xFFFFFFF0) <= 0x10 )
    v18 = 0;
  if ( (dword_61C764 & 2) != 0 )
    goto LABEL_30;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&dword_61C764);
  while ( v5 == v17 && __strex(v18, (unsigned int *)&dword_61C764) );
  if ( v5 != v17 )
LABEL_30:
    ExfReleasePushLock(&dword_61C764, v5);
  v19 = KeAbPostRelease((unsigned int)&dword_61C764);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  return v2;
}
