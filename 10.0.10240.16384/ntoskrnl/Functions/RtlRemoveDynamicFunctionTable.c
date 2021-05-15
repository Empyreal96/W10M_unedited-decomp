// RtlRemoveDynamicFunctionTable 
 
int __fastcall RtlRemoveDynamicFunctionTable(int a1)
{
  unsigned int v1; // r3
  int v2; // r3
  int v3; // r10
  int v4; // r4
  unsigned int v5; // r8
  unsigned __int8 *v6; // r6
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  unsigned int *v10; // r5
  unsigned int v11; // r2
  unsigned int v12; // r1
  _DWORD *v13; // r0
  int v14; // r0
  unsigned int v15; // r9
  unsigned int v16; // r1
  int v17; // r0
  __int16 v18; // r3
  int v20; // [sp+4h] [bp-24h]
  unsigned int v21; // [sp+8h] [bp-20h]

  if ( (a1 & 7) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v1 = *(_DWORD *)(a1 + 32);
  __dmb(0xBu);
  v21 = v1;
  v2 = *(_DWORD *)(a1 + 28);
  __dmb(0xBu);
  v3 = v2 - v21;
  if ( v2 - v21 == -1 )
    return -1073741675;
  v4 = -1073741569;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_DWORD *)(v5 + 0x150);
  --*(_WORD *)(v5 + 310);
  v6 = (unsigned __int8 *)(v20 + 708);
  v7 = KeAbPreAcquire(v20 + 708, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v6);
  while ( __strex(v9 | 1, v6) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v6, v7, (unsigned int)v6);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = *(unsigned int **)(v20 + 704);
  if ( v10 )
  {
    v11 = *v10;
    v12 = 1;
    if ( *v10 > 1 )
    {
      v13 = v10 + 4;
      while ( v13[5] < v21 )
      {
        ++v12;
        v13 += 4;
        if ( v12 >= v11 )
          goto LABEL_22;
      }
      v14 = (int)&v10[4 * v12 + 4];
      if ( *(_DWORD *)(v14 + 4) == v21 && *(_DWORD *)(v14 + 8) == v3 )
      {
        v15 = v11 - 1;
        if ( v12 != v11 - 1 )
          memmove(v14, (int)&v10[4 * v12 + 8], 16 * (v11 - v12 - 1));
        v4 = 0;
        *v10 = v15;
      }
    }
  }
LABEL_22:
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)v6);
  while ( __strex(v16 - 1, (unsigned int *)v6) );
  if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v6);
  v17 = KeAbPostRelease((unsigned int)v6);
  v18 = *(_WORD *)(v5 + 310) + 1;
  *(_WORD *)(v5 + 310) = v18;
  if ( !v18 && *(_DWORD *)(v5 + 100) != v5 + 100 )
    KiCheckForKernelApcDelivery(v17);
  return v4;
}
