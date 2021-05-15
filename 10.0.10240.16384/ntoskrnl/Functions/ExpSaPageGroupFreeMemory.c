// ExpSaPageGroupFreeMemory 
 
BOOL __fastcall ExpSaPageGroupFreeMemory(int a1, unsigned int a2, unsigned int a3, int a4)
{
  unsigned __int8 *v5; // r4
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r1
  unsigned int v10; // r3
  BOOL v11; // r5
  unsigned int v12; // r1
  int varg_r0; // [sp+18h] [bp+8h]
  unsigned int varg_r2; // [sp+20h] [bp+10h]

  varg_r0 = a1;
  varg_r2 = a3;
  v5 = (unsigned __int8 *)(a1 + 12);
  v7 = KeAbPreAcquire(a1 + 12, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v5);
  while ( __strex(v9 | 1, v5) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v5, v7, (unsigned int)v5);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  RtlClearBits((_BYTE *)(a1 + 32), (a2 >> 3) & 0x3FF, a3);
  v10 = *(_DWORD *)(a1 + 20) + a3;
  v11 = v10 == 1024;
  *(_DWORD *)(a1 + 20) = v10;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v5);
  while ( __strex(v12 - 1, (unsigned int *)v5) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v5);
  KeAbPostRelease((unsigned int)v5);
  return v11;
}
