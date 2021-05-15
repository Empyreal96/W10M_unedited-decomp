// PfpRpShutdown 
 
int __fastcall PfpRpShutdown(_DWORD *a1)
{
  int v2; // r3
  unsigned int *v3; // r0
  unsigned int v4; // r1
  unsigned __int8 *v5; // r6
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  _DWORD *v10; // r2
  _DWORD *v11; // r4
  _DWORD *i; // r1
  unsigned int v13; // r0
  unsigned int v14; // r3
  _DWORD *j; // r1
  unsigned int v16; // r0
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int v22; // [sp+0h] [bp-18h]

  v2 = a1[24];
  v3 = a1 + 20;
  a1[24] = v2 & 0xFFFFFFFE;
  do
    v4 = __ldrex(v3);
  while ( !v4 && __strex(1u, v3) );
  __dmb(0xBu);
  if ( v4 && v4 != 1 )
    ExfWaitForRundownProtectionRelease(v3, v4);
  v5 = (unsigned __int8 *)(a1 + 7);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire((unsigned int)(a1 + 7), 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v5);
  while ( __strex(v9 | 1, v5) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 7, v7, (unsigned int)(a1 + 7));
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = (_DWORD *)a1[2];
  if ( !v10 || (v11 = (_DWORD *)*v10, (*v10 & 1) != 0) )
  {
    for ( i = v10 + 1; ; ++i )
    {
      if ( (unsigned int)i >= a1[2] + 4 * (a1[1] >> 5) )
      {
        v11 = 0;
        goto LABEL_28;
      }
      if ( (*i & 1) == 0 )
        break;
    }
    v11 = (_DWORD *)*i;
  }
LABEL_28:
  while ( v11 )
  {
    v13 = (unsigned int)v11;
    v14 = a1[1];
    v22 = v11[1] & (-1 << (v14 & 0x1F));
    v11 = (_DWORD *)*v11;
    if ( ((unsigned __int8)v11 & 1) != 0 )
    {
      for ( j = (_DWORD *)(a1[2]
                         + 4
                         * ((37 * (37 * (37 * ((unsigned __int8)v22 + 11623883) + BYTE1(v22)) + BYTE2(v22)) + HIBYTE(v22)) & ((v14 >> 5) - 1))
                         + 4); ; ++j )
      {
        if ( (unsigned int)j >= a1[2] + 4 * (a1[1] >> 5) )
        {
          v11 = 0;
          goto LABEL_27;
        }
        if ( (*j & 1) == 0 )
          break;
      }
      v11 = (_DWORD *)*j;
    }
LABEL_27:
    ExFreePoolWithTag(v13);
  }
  v16 = a1[2];
  if ( v16 )
    ExFreePoolWithTag(v16);
  a1[3] = a1 + 4;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)v5);
  while ( __strex(v17 - 1, (unsigned int *)v5) );
  if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 7);
  v18 = KeAbPostRelease((unsigned int)(a1 + 7));
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  return PfpRpControlRequestReset((int)a1);
}
