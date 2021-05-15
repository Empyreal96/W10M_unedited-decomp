// EtwpAddBinaryInfoEvents 
 
int __fastcall EtwpAddBinaryInfoEvents(int a1, int a2, int a3)
{
  unsigned __int8 *v3; // r5
  unsigned int v5; // r7
  int v7; // r8
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  _DWORD *v11; // r4
  _DWORD *v12; // r6
  unsigned int v13; // r1
  unsigned int v15[8]; // [sp+10h] [bp-20h] BYREF

  v3 = (unsigned __int8 *)(a1 + 504);
  v5 = a3 - *(_DWORD *)(a2 + 48);
  v7 = 0;
  v8 = KeAbPreAcquire(a1 + 504, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v3);
  while ( __strex(v10 | 1, v3) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3, v8, (unsigned int)v3);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = *(_DWORD **)(a1 + 632);
  v12 = (_DWORD *)(a1 + 632);
  while ( v11 != v12 )
  {
    v7 = EtwpAddEventToBuffer(a2, 67, (_DWORD *)(a2 + 88), (int)(v11 + 3), v11[2] + 16 * v11[3] + 4, v5, v15);
    if ( v7 < 0 )
      break;
    v11 = (_DWORD *)*v11;
    v5 -= v15[0];
  }
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)v3);
  while ( __strex(v13 - 1, (unsigned int *)v3) );
  if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v3);
  KeAbPostRelease((unsigned int)v3);
  return v7;
}
