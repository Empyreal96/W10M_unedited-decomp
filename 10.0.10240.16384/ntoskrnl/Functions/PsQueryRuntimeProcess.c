// PsQueryRuntimeProcess 
 
int __fastcall PsQueryRuntimeProcess(_DWORD *a1, _DWORD *a2)
{
  unsigned int v4; // r6
  unsigned int *v5; // r5
  int v6; // r0
  unsigned int v7; // r2
  int v8; // r4
  int v9; // r8
  _DWORD *v10; // r1
  _DWORD *v11; // r2
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r0
  __int16 v15; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = a1 + 180;
  v6 = KeAbPreAcquire((unsigned int)(a1 + 180), 0, 0);
  do
    v7 = __ldrex(v5);
  while ( !v7 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v7 )
    return sub_7C3E70(v6, 17);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v9 = a1[39];
  v8 = a1[38];
  v10 = (_DWORD *)a1[99];
  while ( v10 != a1 + 99 )
  {
    v11 = v10 - 233;
    v12 = *(v10 - 132);
    v10 = (_DWORD *)*v10;
    v8 += v12;
    v9 += v11[112];
  }
  __dmb(0xBu);
  do
    v13 = __ldrex(v5);
  while ( v13 == 17 && __strex(0, v5) );
  if ( v13 != 17 )
    ExfReleasePushLockShared(v5);
  v14 = KeAbPostRelease((unsigned int)v5);
  v15 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(v14);
  *a2 = v9;
  return v8;
}
