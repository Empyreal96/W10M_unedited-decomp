// PsSetProcessTelemetryAppState 
 
int __fastcall PsSetProcessTelemetryAppState(int a1, int a2)
{
  unsigned int v4; // r7
  unsigned __int8 *v5; // r6
  int v6; // r8
  int v7; // r0
  unsigned int v8; // r2
  __int64 v9; // kr00_8
  unsigned __int64 v10; // kr08_8
  int v11; // r5
  unsigned int v12; // r1
  int v13; // r0
  __int16 v14; // r3
  int v16; // r3
  int v17; // r2
  int v18; // r3
  __int64 v19; // [sp+0h] [bp-88h]
  int v20; // [sp+8h] [bp-80h]
  unsigned __int64 v21; // [sp+10h] [bp-78h] BYREF
  __int64 v22; // [sp+18h] [bp-70h]
  __int64 v23; // [sp+20h] [bp-68h]
  int v24; // [sp+30h] [bp-58h] BYREF
  int v25; // [sp+34h] [bp-54h]
  __int64 v26; // [sp+38h] [bp-50h]
  __int64 v27; // [sp+40h] [bp-48h]
  int v28; // [sp+48h] [bp-40h]
  int v29; // [sp+4Ch] [bp-3Ch]
  int v30; // [sp+50h] [bp-38h]
  int v31; // [sp+54h] [bp-34h]
  __int64 v32; // [sp+58h] [bp-30h]
  int v33; // [sp+60h] [bp-28h]
  int v34; // [sp+64h] [bp-24h]

  v24 = 0;
  v25 = 0;
  v26 = 0i64;
  v27 = 0i64;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0i64;
  v33 = 0;
  v34 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (unsigned __int8 *)(a1 + 168);
  while ( 1 )
  {
    PsGetProcessDeepFreezeStats(a1, &v21);
    v6 = 0;
    v19 = v22 - *(_QWORD *)(a1 + 832) - v23;
    --*(_WORD *)(v4 + 308);
    v7 = KeAbPreAcquire((unsigned int)v5, 0, 0);
    do
      v8 = __ldrex(v5);
    while ( __strex(v8 | 1, v5) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      return sub_7C2DEC(v7);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = *(_QWORD *)(a1 + 856);
    v10 = v21;
    v20 = *(_DWORD *)(a1 + 856);
    if ( HIDWORD(v9) >> 29 == 3 || *(_QWORD *)(a1 + 848) > v21 )
    {
      v11 = v19;
    }
    else
    {
      v27 = *(_QWORD *)(a1 + 848);
      v33 = HIDWORD(v9) >> 29;
      v28 = v20;
      v29 = HIDWORD(v9) & 0x1FFFFFFF;
      if ( a2 == 5 && HIDWORD(v9) >> 29 == 1 )
        a2 = 6;
      v11 = v19;
      v16 = HIDWORD(v9) & 0x1FFFFFFF | (a2 << 29);
      *(_DWORD *)(a1 + 856) = v20;
      *(_DWORD *)(a1 + 860) = v16;
      v17 = (v16 ^ HIDWORD(v19)) & 0x1FFFFFFF;
      v18 = *(_DWORD *)(a1 + 860);
      *(_QWORD *)(a1 + 848) = v10;
      *(_DWORD *)(a1 + 856) = v19;
      *(_DWORD *)(a1 + 860) = v18 ^ v17;
      v6 = 1;
    }
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)v5);
    while ( __strex(v12 - 1, (unsigned int *)v5) );
    if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v5);
    v13 = KeAbPostRelease((unsigned int)v5);
    v14 = *(_WORD *)(v4 + 308) + 1;
    *(_WORD *)(v4 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      KiCheckForKernelApcDelivery(v13);
    if ( *(_DWORD *)(a1 + 860) >> 29 == 3 )
    {
      if ( v6 )
      {
LABEL_16:
        v24 = v21;
        v25 = HIDWORD(v10);
        v30 = v11;
        v34 = a2;
        v26 = v22;
        v32 = v23;
        v31 = HIDWORD(v19);
        EtwTraceAppStateChange(a1, (int)&v24);
      }
      return v6;
    }
    if ( v6 )
      goto LABEL_16;
  }
}
