// EtwpGetLoggerInfoFromContext 
 
int __fastcall EtwpGetLoggerInfoFromContext(int a1, int *a2)
{
  int *v4; // lr
  int v5; // r2
  int v6; // r3
  int v7; // r4
  int v8; // r5
  int v9; // r3
  int v10; // r4
  int v11; // r5
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r3
  unsigned int v19; // r3
  int v20; // r3
  int v21; // r3
  int v22; // r6
  unsigned __int8 *v23; // r5
  int v24; // r0
  int v25; // r4
  unsigned int v26; // r2
  unsigned int *v27; // r4
  unsigned int v28; // r1
  int v29; // r4
  int v31[16]; // [sp+Ch] [bp-40h] BYREF

  if ( (a2[3] & 0x2000000) != 0 )
  {
    v4 = &EtwpGroupMasks[8 * *((unsigned __int8 *)a2 + 610)];
    v5 = *v4;
    v6 = v4[1];
    v7 = v4[2];
    v8 = v4[3];
    v4 += 4;
    v31[0] = v5;
    v31[1] = v6;
    v31[2] = v7;
    v31[3] = v8;
    v9 = v4[1];
    v10 = v4[2];
    v11 = v4[3];
    v31[4] = *v4;
    v31[5] = v9;
    v31[6] = v10;
    v31[7] = v11;
    EtwpMapEnableFlags(v31, 0);
    v12 = v31[0];
  }
  else
  {
    v12 = 0;
  }
  *(_DWORD *)(a1 + 72) = v12;
  v13 = a2[51];
  v14 = a2[52];
  v15 = a2[53];
  *(_DWORD *)(a1 + 24) = a2[50];
  *(_DWORD *)(a1 + 28) = v13;
  *(_DWORD *)(a1 + 32) = v14;
  *(_DWORD *)(a1 + 36) = v15;
  *(_DWORD *)(a1 + 64) = a2[3];
  *(_DWORD *)(a1 + 60) = a2[54];
  *(_DWORD *)(a1 + 68) = a2[33];
  *(_DWORD *)(a1 + 48) = (unsigned int)a2[1] >> 10;
  v16 = a2[40];
  __dmb(0xBu);
  *(_DWORD *)(a1 + 96) = v16;
  *(_DWORD *)(a1 + 52) = a2[38];
  *(_DWORD *)(a1 + 56) = a2[41];
  v17 = a2[42];
  __dmb(0xBu);
  *(_DWORD *)(a1 + 104) = v17;
  v18 = a2[39];
  __dmb(0xBu);
  *(_DWORD *)(a1 + 100) = v18;
  v19 = a2[44];
  if ( v19 <= a2[46] )
    v19 = a2[46];
  *(_DWORD *)(a1 + 108) = v19;
  *(_DWORD *)(a1 + 80) = (a2[152] & 0x10) != 0;
  *(_DWORD *)(a1 + 112) = a2[45];
  *(_DWORD *)(a1 + 116) = a2[47];
  *(_DWORD *)(a1 + 160) = a2[66];
  *(_DWORD *)(a1 + 76) = a2[34];
  v20 = *a2;
  if ( !*a2 )
    LOWORD(v20) = -1;
  *(_WORD *)(a1 + 8) = v20;
  v21 = a2[9];
  if ( v21 )
    *(_DWORD *)(a1 + 120) = *(_DWORD *)(v21 + 880);
  *(_DWORD *)(a1 + 40) = a2[31];
  v22 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v23 = (unsigned __int8 *)(a2 + 126);
  v24 = KeAbPreAcquire((unsigned int)(a2 + 126), 0, 0);
  v25 = v24;
  do
    v26 = __ldrex(v23);
  while ( __strex(v26 | 1, v23) );
  __dmb(0xBu);
  if ( (v26 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a2 + 126, v24, (unsigned int)(a2 + 126));
  if ( v25 )
    *(_BYTE *)(v25 + 14) |= 1u;
  if ( *((_WORD *)a2 + 50) && *(_WORD *)(a1 + 130) )
  {
    if ( v22 )
      ProbeForWrite(*(_DWORD *)(a1 + 132), *((unsigned __int16 *)a2 + 50) + 2, 2);
    RtlCopyUnicodeString((unsigned __int16 *)(a1 + 128), (unsigned __int16 *)a2 + 50);
  }
  v27 = (unsigned int *)(a2 + 126);
  __dmb(0xBu);
  do
    v28 = __ldrex(v27);
  while ( __strex(v28 - 1, v27) );
  if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)a2 + 126);
  KeAbPostRelease((unsigned int)(a2 + 126));
  v29 = *((unsigned __int16 *)a2 + 46);
  if ( *((_WORD *)a2 + 46)
    && *(_WORD *)(a1 + 146)
    && !RtlEqualUnicodeString((unsigned __int16 *)a2 + 46, (unsigned __int16 *)(a1 + 144), 0) )
  {
    if ( v22 )
      ProbeForWrite(*(_DWORD *)(a1 + 148), v29 + 2, 2);
    RtlCopyUnicodeString((unsigned __int16 *)(a1 + 144), (unsigned __int16 *)a2 + 46);
  }
  return 0;
}
