// SmKmKeyGenNewKey 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SmKmKeyGenNewKey(unsigned int a1, unsigned __int16 *a2, int a3)
{
  int v4; // r6
  unsigned int v7; // r0
  unsigned int v8; // r10
  unsigned int v9; // r5
  _BYTE *v10; // r0
  _DWORD *v11; // r4
  int v12; // r5
  int v13; // r0
  int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  int v17; // r5
  unsigned int v18; // r2
  _DWORD *v19; // r2 OVERLAPPED
  int v20; // r1 OVERLAPPED
  unsigned __int16 *v21; // r4
  unsigned int v22; // r1
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  int v27[2]; // [sp+0h] [bp-30h] BYREF
  __int16 v28; // [sp+8h] [bp-28h]
  __int16 v29; // [sp+Ah] [bp-26h]
  unsigned __int16 *v30; // [sp+Ch] [bp-24h]

  v4 = 0;
  v27[0] = 0;
  v7 = wcslen(a2);
  v8 = v7 + 11;
  v9 = v7;
  v10 = (_BYTE *)SmAlloc(a3 + 2 * (v7 + 11), 1196125555);
  v11 = v10;
  if ( !v10 )
    return -1073741670;
  memset(v10, 0, a3 + 2 * v8);
  v13 = (int)v11 + a3 + 20;
  v11[2] = v13;
  v11[3] = v11 + 5;
  v11[4] = a3;
  memmove(v13, (int)a2, 2 * v9);
  if ( !*(_DWORD *)(a1 + 16) )
    goto LABEL_6;
  v14 = SmKmKeyGenLoadKey(a1 + 12, v11, v27);
  v12 = v14;
  v4 = v27[0];
  if ( v14 >= 0 )
    goto LABEL_7;
  if ( v14 == -1073741772 )
  {
LABEL_6:
    v12 = SmCrGenRandom(v11[3], a3);
    if ( v12 >= 0 )
    {
LABEL_7:
      v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v15 + 308);
      v16 = KeAbPreAcquire(a1, 0, 0);
      v17 = v16;
      do
        v18 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v18 | 1, (unsigned __int8 *)a1) );
      __dmb(0xBu);
      if ( (v18 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)a1, v16, a1);
      if ( v17 )
        *(_BYTE *)(v17 + 14) |= 1u;
      if ( !SmKmKeyGenKeyFind(a1, (char *)a2) )
      {
        v19 = (_DWORD *)(a1 + 4);
        v20 = *(_DWORD *)(a1 + 4);
        *(_QWORD *)v11 = *(_QWORD *)&v20;
        if ( *(_DWORD *)(v20 + 4) != a1 + 4 )
          __fastfail(3u);
        *(_DWORD *)(v20 + 4) = v11;
        *v19 = v11;
        if ( v4 )
        {
          v21 = (unsigned __int16 *)v11[2];
          v28 = 0;
          v29 = 0;
          v30 = 0;
          if ( v21 && sub_5B3C84(v21, v20, v27) >= 0 )
          {
            v30 = v21;
            v28 = 2 * LOWORD(v27[0]);
            v29 = 2 * LOWORD(v27[0]) + 2;
          }
          ZwDeleteValueKey();
        }
        v11 = 0;
      }
      __dmb(0xBu);
      do
        v22 = __ldrex((unsigned int *)a1);
      while ( __strex(v22 - 1, (unsigned int *)a1) );
      if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)a1);
      v23 = KeAbPostRelease(a1);
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v25 = *(_WORD *)(v24 + 0x134) + 1;
      *(_WORD *)(v24 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
        KiCheckForKernelApcDelivery(v23);
      v12 = 0;
      goto LABEL_32;
    }
  }
LABEL_32:
  if ( v4 )
    ZwClose();
  if ( v11 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v11);
  return v12;
}
