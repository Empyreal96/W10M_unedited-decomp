// EtwTraceEvent 
 
int __fastcall EtwTraceEvent(int a1, int a2, unsigned int a3, int a4, int a5, char a6)
{
  int v7; // r9
  int v8; // r4
  int v9; // r5
  unsigned int v10; // r2
  int v11; // r0
  _DWORD *v12; // r9
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // r3
  unsigned int v16; // r5
  unsigned int v17; // r6
  int v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r4
  int i; // r2
  unsigned int v22; // r3
  int v23; // r0
  int v24; // r8
  unsigned int v25; // r2
  int v26; // r0
  int j; // r5
  unsigned int v28; // r1
  unsigned int v29; // r3
  int v30; // r5
  _DWORD *v31; // r2
  _DWORD *v32; // r2
  unsigned int v33; // r6
  unsigned int *v34; // r5
  unsigned int v35; // r0
  unsigned int k; // r3
  unsigned int v37; // r1
  unsigned int *v38; // r2
  unsigned int v39; // r1
  int v40; // r0
  unsigned int v41; // r1
  __int16 v42; // r3
  unsigned __int8 v44; // [sp+8h] [bp-178h]
  int v45; // [sp+Ch] [bp-174h]
  signed int v46; // [sp+10h] [bp-170h]
  int v48; // [sp+14h] [bp-16Ch]
  int v49; // [sp+24h] [bp-15Ch]
  unsigned int v50; // [sp+2Ch] [bp-154h]
  int v51; // [sp+34h] [bp-14Ch]
  unsigned int v52; // [sp+48h] [bp-138h] BYREF
  unsigned int *v53; // [sp+4Ch] [bp-134h]
  __int64 v54; // [sp+58h] [bp-128h] BYREF
  _OWORD v55[18]; // [sp+60h] [bp-120h] BYREF
  int varg_r0; // [sp+188h] [bp+8h]
  int varg_r1; // [sp+18Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+190h] [bp+10h]
  int varg_r3; // [sp+194h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v7 = (unsigned __int16)a1;
  v51 = (unsigned __int16)a1;
  if ( (unsigned __int16)a1 >= 0x40u )
    return -1073741816;
  v9 = 0;
  v45 = 0;
  v44 = 0;
  if ( a6 == 1 || (unsigned int)KeGetCurrentIrql(a1) < 2 )
  {
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v10 + 308);
    v11 = ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v7], 1);
    if ( !v11 )
    {
LABEL_10:
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(_WORD *)(v13 + 0x134) + 1;
      *(_WORD *)(v13 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery(v11);
      goto LABEL_14;
    }
    v9 = 1;
    v45 = 1;
    v44 = 1;
  }
  v12 = (_DWORD *)WmipLoggerContext[v7];
  if ( ((unsigned __int8)v12 & 1) == 0 )
    goto LABEL_15;
  if ( v9 )
  {
    v11 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[(unsigned __int16)varg_r0], 1);
    goto LABEL_10;
  }
LABEL_14:
  v12 = 0;
LABEL_15:
  if ( !v12 )
    return -1073741816;
  if ( !a6 || PsEqualCurrentServerSilo(v12[163]) )
  {
    v15 = v12[3];
    if ( (v15 & 0x80) != 0 )
    {
      v8 = -1073741790;
    }
    else if ( a6 || (v15 & 0x1000000) == 0 )
    {
      if ( a6 )
      {
        if ( (a3 & 7) != 0 )
          ExRaiseDatatypeMisalignment(7);
        v16 = a4;
        if ( a4 + a3 > MmUserProbeAddress || a4 + a3 < a3 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      else
      {
        v16 = a4;
      }
      v17 = *(unsigned __int16 *)a3;
      __dmb(0xBu);
      if ( v17 >= v16 )
      {
        v18 = *(_DWORD *)(a3 + 44);
        v49 = v18;
        __dmb(0xBu);
        if ( (v18 & 0x100000) == 0 )
          goto LABEL_48;
        v19 = v16 + a3;
        v20 = v17 - v16;
        if ( v17 - v16 > 0x100 )
        {
          v8 = -1073741684;
          v45 = v44;
          goto LABEL_94;
        }
        if ( v20 )
        {
          if ( a6 )
          {
            if ( (v19 & 7) != 0 )
              ExRaiseDatatypeMisalignment(7);
            if ( v20 + v19 > MmUserProbeAddress || v20 + v19 < v19 )
              *(_BYTE *)MmUserProbeAddress = 0;
          }
          memmove((int)v55, v19, v17 - v16);
          v17 = v16;
          v46 = v20 >> 4;
          for ( i = 0; i < (int)(v20 >> 4); ++i )
          {
            v22 = DWORD2(v55[i]);
            v17 += v22;
            if ( v17 < v22 )
            {
              v8 = -2147483643;
              v45 = v44;
              goto LABEL_94;
            }
          }
        }
        else
        {
LABEL_48:
          v46 = 0;
        }
        v8 = 0;
        v45 = v44;
        v23 = EtwpReserveTraceBuffer(v12, v17, &v52, &v54, 0);
        v24 = v23;
        if ( v23 )
        {
          if ( (v49 & 0x100000) != 0 )
          {
            v25 = a4;
            v48 = a4 + v23;
            v26 = memmove(v23, a3, v25);
            for ( j = 0; j < v46; ++j )
            {
              v28 = v55[j];
              v29 = DWORD2(v55[j]);
              v50 = v29;
              if ( v28 && v29 )
              {
                if ( a6 && (v29 + v28 > MmUserProbeAddress || v29 + v28 < v28) )
                  *(_BYTE *)MmUserProbeAddress = 0;
                v26 = memmove(v48, v28, v29);
                v48 += v50;
              }
            }
            v30 = a6;
          }
          else
          {
            v30 = a6;
            if ( a6 && v17 )
            {
              if ( (a3 & 7) != 0 )
                ExRaiseDatatypeMisalignment(v23);
              if ( a3 + v17 > MmUserProbeAddress || a3 + v17 < a3 )
                *(_BYTE *)MmUserProbeAddress = 0;
            }
            v26 = memmove(v23, a3, v17);
          }
          if ( (v49 & 0x80000) != 0 )
          {
            v31 = *(_DWORD **)(a3 + 24);
            if ( v30 && ((unsigned __int8)v31 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v26);
            *(_DWORD *)(v24 + 24) = *v31;
            *(_DWORD *)(v24 + 28) = v31[1];
            *(_DWORD *)(v24 + 32) = v31[2];
            *(_DWORD *)(v24 + 36) = v31[3];
          }
          v32 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
          *(_DWORD *)v24 = a5 | v17;
          *(_QWORD *)(v24 + 16) = v54;
          *(_DWORD *)(v24 + 40) = v32[101];
          *(_DWORD *)(v24 + 44) = v32[112];
          *(_DWORD *)(v24 + 8) = v32[220];
          *(_DWORD *)(v24 + 12) = v32[219];
          if ( (!KdDebuggerNotPresent && !KdPitchDebugger || KdEventLoggingPresent) && (v12[3] & 0x80000) != 0 )
            EtwpSendTraceEvent(v12, &v52);
          v33 = v52;
          v34 = v53;
          __pld(v53);
          v35 = *v34;
          for ( k = *v34 ^ v33; ; k = v37 ^ v33 )
          {
            __dmb(0xBu);
            if ( k >= 7 )
              break;
            do
              v37 = __ldrex(v34);
            while ( v37 == v35 && __strex(v35 + 1, v34) );
            if ( v37 == v35 )
              goto LABEL_94;
            v35 = v37;
          }
          v38 = (unsigned int *)(v52 + 12);
          do
            v39 = __ldrex(v38);
          while ( __strex(v39 - 1, v38) );
          __dmb(0xBu);
        }
        else if ( v17 <= 0xFFF8 )
        {
          if ( v17 <= v12[2] )
            v8 = -1073741801;
          else
            v8 = -2147483643;
        }
        else
        {
          v8 = -1073741675;
        }
        goto LABEL_94;
      }
      v8 = -1073741811;
      v45 = v44;
    }
    else
    {
      v8 = -1073741637;
    }
  }
  else
  {
    v8 = -1073741816;
  }
LABEL_94:
  if ( v45 )
  {
    v40 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v51], 1);
    v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v42 = *(_WORD *)(v41 + 0x134) + 1;
    *(_WORD *)(v41 + 308) = v42;
    if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
      KiCheckForKernelApcDelivery(v40);
  }
  return v8;
}
