// EtwpLogSystemEventUnsafe 
 
int __fastcall EtwpLogSystemEventUnsafe(int a1, _DWORD *a2, int a3, unsigned int a4, __int16 a5, int a6)
{
  int v7; // r9
  int v8; // r8
  unsigned int v9; // r5
  int result; // r0
  unsigned int v11; // r4
  __int16 v12; // r3
  int v13; // r3
  _DWORD *v14; // r5
  unsigned int v15; // r1
  __int16 v16; // r3
  int v17; // r2
  int v18; // r1
  unsigned int v19; // r0
  __int16 v20; // r4
  int v21; // r8
  unsigned int i; // r6
  int *v23; // r3
  unsigned int v24; // r4
  int v25; // r1
  int v26; // r10
  _DWORD *v27; // lr
  unsigned int v28; // r6
  unsigned int *v29; // r4
  unsigned int v30; // r0
  unsigned int j; // r3
  unsigned int v32; // r1
  unsigned int *v33; // r2
  unsigned int v34; // r1
  unsigned int v35; // r1
  __int16 v36; // r3
  int v38; // [sp+10h] [bp-50h]
  __int64 v41; // [sp+28h] [bp-38h] BYREF
  int v42; // [sp+34h] [bp-2Ch]
  unsigned int v43; // [sp+38h] [bp-28h] BYREF
  unsigned int *v44; // [sp+3Ch] [bp-24h]
  int varg_r0; // [sp+68h] [bp+8h]
  _DWORD *varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  unsigned int varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  v7 = a3;
  varg_r2 = a3;
  varg_r1 = a2;
  v8 = a1;
  v38 = 0;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  result = ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[a3], 1);
  if ( result )
  {
    v38 = 1;
    v14 = (_DWORD *)WmipLoggerContext[v7];
    if ( ((unsigned __int8)v14 & 1) == 0 )
      goto LABEL_12;
    result = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v7], 1);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 )
    {
      v13 = *(__int16 *)(v15 + 310);
LABEL_9:
      if ( !v13 )
        result = KiCheckForKernelApcDelivery(result);
      goto LABEL_11;
    }
  }
  else
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x134) + 1;
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 )
    {
      v13 = *(__int16 *)(v11 + 310);
      goto LABEL_9;
    }
  }
LABEL_11:
  v14 = 0;
LABEL_12:
  if ( v14 )
  {
    v17 = 0;
    if ( a4 )
    {
      v18 = v8;
      v19 = a4;
      do
      {
        v17 += *(_DWORD *)(v18 + 8);
        v18 += 16;
        --v19;
      }
      while ( v19 );
    }
    v20 = v17 + 32;
    result = EtwpReserveTraceBuffer(v14, v17 + 32, &v43, &v41, a6);
    if ( result )
    {
      *(_DWORD *)result = (unsigned __int8)a6 | 0xC0010000;
      *(_QWORD *)(result + 16) = v41;
      *(_WORD *)(result + 4) = v20;
      *(_WORD *)(result + 6) = a5;
      *(_DWORD *)(result + 8) = a2[220];
      *(_DWORD *)(result + 12) = a2[219];
      *(_DWORD *)(result + 24) = a2[101];
      *(_DWORD *)(result + 28) = a2[112];
      v21 = result + 32;
    }
    else
    {
      v21 = 0;
    }
    if ( v21 )
    {
      for ( i = 0; i < a4; ++i )
      {
        v23 = (int *)(a1 + 16 * i);
        v24 = v23[2];
        v25 = *v23;
        v42 = v23[1];
        memmove(v21, v25, v24);
        v21 += v24;
      }
      v26 = v38;
      v27 = a2;
      if ( (!KdDebuggerNotPresent && !KdPitchDebugger || KdEventLoggingPresent) && (v14[3] & 0x80000) != 0 )
      {
        EtwpSendTraceEvent(v14, &v43);
        v27 = a2;
      }
      v28 = v43;
      v29 = v44;
      __pld(v44);
      v30 = *v29;
      for ( j = *v29 ^ v28; ; j = v32 ^ v28 )
      {
        __dmb(0xBu);
        if ( j >= 7 )
          break;
        do
          v32 = __ldrex(v29);
        while ( v32 == v30 && __strex(v30 + 1, v29) );
        if ( v32 == v30 )
          goto LABEL_37;
        v30 = v32;
      }
      v33 = (unsigned int *)(v43 + 12);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 - 1, v33) );
      __dmb(0xBu);
LABEL_37:
      result = v14[152];
      if ( (result & 0x80) != 0 && ((*(char *)(((unsigned __int16)(a5 & 0x1FFF) >> 3) + v14[155]) >> (a5 & 7)) & 1) != 0 )
        result = EtwpStackTraceDispatcher(result & 0xFFFF0000 | *v14, &v41, v27, a6);
    }
    else
    {
      v26 = v38;
    }
    if ( v26 )
    {
      result = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[a3], 1);
      v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v36 = *(_WORD *)(v35 + 0x134) + 1;
      *(_WORD *)(v35 + 308) = v36;
      if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
        result = KiCheckForKernelApcDelivery(result);
    }
  }
  return result;
}
