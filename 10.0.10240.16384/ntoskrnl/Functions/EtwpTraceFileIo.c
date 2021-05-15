// EtwpTraceFileIo 
 
__int16 *__fastcall EtwpTraceFileIo(__int16 *result, int a2, unsigned int a3, int a4)
{
  int v4; // r6
  __int16 v5; // r8
  unsigned int v6; // r5
  unsigned int v7; // r4
  unsigned int v8; // r1
  int v9; // r7
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r0
  _DWORD *v13; // r9
  int v14; // r0
  int v15; // r1
  __int16 *v16; // r2
  int v17; // r3
  _DWORD *v18; // r4
  __int16 v19; // r6
  int v20; // r0
  int v21; // r2
  int v22; // r8
  int v23; // r7
  int *v24; // r6
  unsigned int v25; // r4
  int v26; // t1
  unsigned int *v27; // r4
  unsigned int *v28; // t2
  unsigned int v29; // r1
  unsigned int v30; // r6
  unsigned int v31; // r0
  int v32; // r0
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  unsigned int v36; // r1
  int v37; // r3
  unsigned int *v38; // r2
  unsigned int v39; // r1
  unsigned int v40; // [sp+8h] [bp-50h]
  unsigned int v41; // [sp+Ch] [bp-4Ch]
  __int16 v43; // [sp+14h] [bp-44h]
  __int16 *v44; // [sp+18h] [bp-40h]
  int v45; // [sp+1Ch] [bp-3Ch]
  int v46; // [sp+20h] [bp-38h]
  int v47[2]; // [sp+28h] [bp-30h] BYREF
  unsigned int v48; // [sp+30h] [bp-28h] BYREF
  unsigned int *v49; // [sp+34h] [bp-24h]

  v4 = a2;
  v5 = a4;
  v43 = a4;
  v40 = a3;
  v44 = result;
  if ( (dword_61AD40 & 0x6000000) != 0 )
    return (__int16 *)sub_517FA4();
  if ( a4 != 1102 )
  {
    v6 = EtwpActiveSystemLoggers;
    v7 = __clz(__rbit(EtwpActiveSystemLoggers));
    if ( 1 != (unsigned __int8)(v7 >> 5) )
    {
      v8 = a3 >> 29;
      result = EtwpSystemLogger;
      v41 = a3 >> 29;
      do
      {
        v6 &= v6 - 1;
        if ( !&EtwpGroupMasks[8 * v7] || (EtwpGroupMasks[8 * v7 + v8] & a3 & 0x1FFFFFFF) == 0 )
          goto LABEL_8;
        v9 = (unsigned __int16)EtwpSystemLogger[2 * v7];
        v10 = 0;
        v45 = 0;
        v46 = v9;
        if ( (unsigned int)KeGetCurrentIrql() < 2 )
        {
          v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v11 + 308);
          v12 = ExAcquireRundownProtectionCacheAwareEx(EtwpLoggerRundown[v9], 1);
          if ( !v12 )
            goto LABEL_43;
          v10 = 1;
          v45 = 1;
        }
        v13 = (_DWORD *)WmipLoggerContext[v9];
        if ( ((unsigned __int8)v13 & 1) != 0 )
        {
          if ( v10 )
          {
            v12 = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v9], 1);
LABEL_43:
            v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v37 = (__int16)(*(_WORD *)(v36 + 0x134) + 1);
            *(_WORD *)(v36 + 308) = v37;
            if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
              KiCheckForKernelApcDelivery(v12);
            goto LABEL_37;
          }
        }
        else if ( v13 )
        {
          v14 = 0;
          if ( v4 )
          {
            v15 = v4;
            v16 = v44;
            do
            {
              v17 = *((_DWORD *)v16 + 2);
              v16 += 8;
              v14 += v17;
              --v15;
            }
            while ( v15 );
          }
          v18 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
          v19 = v14 + 32;
          v20 = EtwpReserveTraceBuffer(v13, v14 + 32, &v48, v47, 5249283);
          if ( v20 )
          {
            v21 = v47[1];
            *(_WORD *)(v20 + 4) = v19;
            *(_DWORD *)v20 = -1073676285;
            *(_DWORD *)(v20 + 16) = v47[0];
            *(_DWORD *)(v20 + 20) = v21;
            *(_WORD *)(v20 + 6) = v5;
            v22 = v20 + 32;
            *(_DWORD *)(v20 + 8) = v18[220];
            *(_DWORD *)(v20 + 12) = v18[219];
            *(_DWORD *)(v20 + 24) = v18[101];
            *(_DWORD *)(v20 + 28) = v18[112];
            if ( v20 == -32 )
            {
              v5 = v43;
            }
            else
            {
              if ( a2 )
              {
                v23 = a2;
                v24 = (int *)v44;
                do
                {
                  v25 = v24[2];
                  v26 = *v24;
                  v24 += 4;
                  memmove(v22, v26, v25);
                  v22 += v25;
                  --v23;
                }
                while ( v23 );
                v9 = v46;
              }
              if ( (!KdDebuggerNotPresent && !KdPitchDebugger || KdEventLoggingPresent) && (v13[3] & 0x80000) != 0 )
                EtwpSendTraceEvent(v13, &v48);
              v27 = v49;
              v28 = v49;
              __pld(v49);
              v29 = *v28;
              v30 = v48;
              if ( (*v28 ^ v48) >= 7 )
              {
LABEL_50:
                __dmb(0xBu);
                v38 = (unsigned int *)(v30 + 12);
                do
                  v39 = __ldrex(v38);
                while ( __strex(v39 - 1, v38) );
                __dmb(0xBu);
              }
              else
              {
                while ( 1 )
                {
                  __dmb(0xBu);
                  do
                    v31 = __ldrex(v27);
                  while ( v31 == v29 && __strex(v29 + 1, v27) );
                  if ( v31 == v29 )
                    break;
                  v29 = v31;
                  if ( (v31 ^ v30) >= 7 )
                    goto LABEL_50;
                }
              }
              v32 = v13[152];
              v5 = v43;
              if ( (v32 & 0x80) != 0
                && ((*(char *)(((unsigned __int16)(v43 & 0x1FFF) >> 3) + v13[155]) >> (v43 & 7)) & 1) != 0 )
              {
                EtwpStackTraceDispatcher(v32 & 0xFFFF0000 | *v13, v47, 0, 5249283);
              }
            }
          }
          if ( v45 )
          {
            v33 = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v9], 1);
            v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v35 = *(_WORD *)(v34 + 0x134) + 1;
            *(_WORD *)(v34 + 308) = v35;
            if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
            {
              KiCheckForKernelApcDelivery(v33);
              v8 = v41;
              v4 = a2;
              a3 = v40;
              result = EtwpSystemLogger;
              goto LABEL_8;
            }
          }
          v4 = a2;
        }
LABEL_37:
        a3 = v40;
        v8 = v41;
        result = EtwpSystemLogger;
LABEL_8:
        v7 = __clz(__rbit(v6));
      }
      while ( 1 != (unsigned __int8)(v7 >> 5) );
    }
  }
  return result;
}
