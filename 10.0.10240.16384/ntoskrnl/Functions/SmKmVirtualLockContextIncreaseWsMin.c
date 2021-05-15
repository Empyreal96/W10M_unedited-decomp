// SmKmVirtualLockContextIncreaseWsMin 
 
int __fastcall SmKmVirtualLockContextIncreaseWsMin(unsigned int a1, int a2, unsigned int a3)
{
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r6
  unsigned int v9; // r4
  int v10; // r4
  unsigned int v11; // r6
  unsigned int v12; // r0
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r3
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned int v21; // [sp+8h] [bp-30h] BYREF
  unsigned int v22; // [sp+Ch] [bp-2Ch] BYREF
  int v23; // [sp+10h] [bp-28h] BYREF
  int v24; // [sp+14h] [bp-24h] BYREF
  int v25; // [sp+18h] [bp-20h] BYREF
  _DWORD v26[7]; // [sp+1Ch] [bp-1Ch] BYREF

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire(a1, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v9 | 1, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)a1, v7, a1);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  if ( a3 >= *(_DWORD *)(a1 + 8) )
  {
    v10 = MmQueryWorkingSetInformation(v26, &v25, &v24, &v22, &v21, &v23);
    if ( v10 >= 0 )
    {
      v11 = (a2 + 0x3FFFFF) & 0xFFC00000;
      while ( 1 )
      {
        v12 = v11 + v22;
        if ( v11 + v22 <= v22 )
        {
          v10 = -1073741675;
          goto LABEL_22;
        }
        v13 = v21;
        v22 += v11;
        if ( v12 > v21 )
        {
          v13 = v12;
          v21 = v12;
        }
        v14 = MmAdjustWorkingSetSize(v12, v13, 0, 1);
        v10 = v14;
        if ( v14 >= 0 )
          break;
        if ( v14 == -1073741748 )
        {
          v10 = MmQueryWorkingSetInformation(v26, &v25, &v24, &v22, &v21, &v23);
          if ( v10 >= 0 )
            continue;
        }
        goto LABEL_22;
      }
      v15 = *(_DWORD *)(a1 + 8);
      if ( v15 + v11 > v15 )
        *(_DWORD *)(a1 + 8) = v15 + v11;
      v10 = 0;
    }
  }
  else
  {
    v10 = 1075380276;
  }
LABEL_22:
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)a1);
  while ( __strex(v16 - 1, (unsigned int *)a1) );
  if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)a1);
  v17 = KeAbPostRelease(a1);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return v10;
}
