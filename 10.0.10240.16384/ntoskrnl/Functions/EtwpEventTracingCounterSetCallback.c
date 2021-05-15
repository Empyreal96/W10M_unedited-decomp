// EtwpEventTracingCounterSetCallback 
 
int __fastcall EtwpEventTracingCounterSetCallback(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r7
  _DWORD *v5; // r0
  unsigned int v6; // r4
  _DWORD *v7; // r5
  int v8; // r2
  bool v9; // zf
  int v10; // r3
  int v12; // [sp+8h] [bp-68h] BYREF
  __int16 v13[2]; // [sp+10h] [bp-60h] BYREF
  const __int16 *v14; // [sp+14h] [bp-5Ch]
  int *v15; // [sp+18h] [bp-58h]
  int v16; // [sp+1Ch] [bp-54h]
  int *v17; // [sp+20h] [bp-50h]
  int v18; // [sp+24h] [bp-4Ch]
  int v19; // [sp+28h] [bp-48h] BYREF
  int v20; // [sp+2Ch] [bp-44h]
  int v21; // [sp+30h] [bp-40h]
  int v22; // [sp+34h] [bp-3Ch]
  int v23; // [sp+38h] [bp-38h]
  int v24; // [sp+3Ch] [bp-34h]
  int v25[12]; // [sp+40h] [bp-30h] BYREF

  v13[0] = 44;
  v13[1] = 46;
  v14 = L"EventTracingCounterSet";
  if ( a1 != 2 && a1 != 3 )
    return 0;
  v4 = *(_DWORD *)(a2 + 20);
  if ( a3 == 1 )
  {
    v19 = 0;
    v20 = 0;
    v21 = 0;
    v22 = 0;
    v23 = 0;
    v24 = 0;
    v5 = 0;
    while ( 1 )
    {
      v5 = (_DWORD *)EtwpGetNextGuidEntry(v5, 0);
      if ( !v5 )
        break;
      if ( v5[14] )
      {
        if ( (_DWORD *)v5[7] == v5 + 7 )
          ++v24;
        else
          ++v22;
      }
      else
      {
        ++v23;
      }
    }
    v19 = dword_61AD6C;
    v21 = dword_61AD68;
    v20 = dword_61AD64[0];
    v15 = &v19;
    v16 = 24;
    v3 = PcwAddInstance(v4, (int)v13, 0, 1);
  }
  else
  {
    v3 = 0;
    v6 = 0;
    v12 = 0;
    do
    {
      v7 = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(v6, 0);
      if ( v7 )
      {
        memset(v25, 0, 24);
        v8 = v7[40];
        v9 = v7[56] == 1;
        __dmb(0xBu);
        if ( v9 )
          v25[0] = v7[1] * v8;
        else
          v25[1] = v7[1] * v8;
        v10 = v7[42];
        __dmb(0xBu);
        v25[4] = v10;
        v25[5] = v7[66];
        WmiQueryTraceInformation(10, &v25[2], 8u, 0, (unsigned int *)&v12);
        v17 = v25;
        v6 = v12;
        v18 = 24;
        v3 = PcwAddInstance(v4, (int)(v7 + 23), v12, 1);
        EtwpReleaseLoggerContext(v7, 0);
        if ( v3 < 0 )
          break;
      }
      v12 = ++v6;
    }
    while ( v6 < 0x40 );
  }
  return v3;
}
