// WdipSemDisableContextProvider 
 
int __fastcall WdipSemDisableContextProvider(int a1, int a2)
{
  int v4; // r9
  unsigned int v5; // r2
  int *v6; // r1
  int v7; // r7
  unsigned int v8; // r4
  int v9; // r4
  unsigned int v10; // r3
  unsigned int v11; // r0
  int v12; // r3
  int v13; // r0
  unsigned int v14; // r4
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v7 = KeAbPreAcquire((unsigned int)&dword_61C764, 0, 0);
  do
    v8 = __ldrex((unsigned __int8 *)&dword_61C764);
  while ( __strex(v8 | 1, (unsigned __int8 *)&dword_61C764) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_61C764, v7, (unsigned int)&dword_61C764);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( a1 )
  {
    WdipSemCaptureState(a1, a2);
    if ( *(_DWORD *)(a1 + 32) != 1 )
    {
      v9 = *(_DWORD *)(a1 + 40);
      __dmb(0xBu);
      v6 = &WdipContextLoggerId;
      v10 = WdipContextLoggerId;
      do
        v11 = __ldrex((unsigned int *)&WdipContextLoggerId);
      while ( __strex(v10, (unsigned int *)&WdipContextLoggerId) );
      __dmb(0xBu);
      v12 = *(_DWORD *)(v9 + 72) - 1;
      *(_DWORD *)(v9 + 72) = v12;
      if ( !v12 )
      {
        if ( *(_DWORD *)(v9 + 40) )
        {
          v4 = WdipSemEnableDisableTrace((unsigned __int16)v11, a1, *(unsigned __int8 *)(v9 + 16));
          if ( v4 >= 0 )
          {
            *(_BYTE *)(v9 + 48) = *(_BYTE *)(v9 + 16);
            *(_DWORD *)(v9 + 56) = *(_DWORD *)(v9 + 24);
            *(_DWORD *)(v9 + 60) = *(_DWORD *)(v9 + 28);
            *(_DWORD *)(v9 + 64) = *(_DWORD *)(v9 + 32);
          }
        }
        else
        {
          v4 = WdipSemEnableDisableTrace((unsigned __int16)v11, a1, 0);
          if ( v4 >= 0 )
            memset((_BYTE *)(v9 + 48), 0, 32);
        }
      }
    }
  }
  else
  {
    v4 = -1073741811;
  }
  __pld(&dword_61C764);
  v13 = dword_61C764;
  v14 = dword_61C764 - 16;
  if ( (dword_61C764 & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  if ( (dword_61C764 & 2) != 0 )
    goto LABEL_25;
  __dmb(0xBu);
  do
    v6 = (int *)__ldrex((unsigned int *)&dword_61C764);
  while ( v6 == (int *)v13 && __strex(v14, (unsigned int *)&dword_61C764) );
  if ( v6 != (int *)v13 )
LABEL_25:
    ExfReleasePushLock(&dword_61C764, (int)v6);
  v15 = KeAbPostRelease((unsigned int)&dword_61C764);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return v4;
}
