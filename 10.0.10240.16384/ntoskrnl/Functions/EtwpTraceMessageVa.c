// EtwpTraceMessageVa 
 
int __fastcall EtwpTraceMessageVa(int a1, int a2, int a3, _DWORD *a4, __int16 a5, unsigned int *a6, char a7)
{
  char v7; // r5
  int v9; // r9
  int v10; // r8
  int v11; // r6
  unsigned int v12; // r1
  unsigned int v13; // r1
  __int16 v14; // r3
  _DWORD *v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r3
  int v20; // r9
  int v21; // r6
  unsigned int v22; // r0
  unsigned int v23; // lr
  int v24; // r2
  _DWORD *v25; // r3
  unsigned int *v26; // r3
  unsigned int v27; // r3
  int v28; // r4
  int v29; // r0
  int v30; // r1
  int v31; // r2
  int v32; // r3
  unsigned int v33; // r4
  int v34; // r0
  unsigned int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r1
  unsigned int *v38; // r4
  unsigned int v39; // r1
  unsigned int v40; // r2
  unsigned int v41; // r3
  unsigned int v42; // r1
  unsigned int v43; // r10
  unsigned int *v44; // r3
  int v45; // r2
  unsigned int v46; // r1
  unsigned int *v47; // r3
  unsigned int v48; // r5
  unsigned int *v49; // r4
  unsigned int v50; // r1
  unsigned int v51; // r5
  unsigned int v52; // r0
  unsigned int *v53; // r2
  unsigned int v54; // r1
  int v55; // r0
  unsigned int v56; // r1
  __int16 v57; // r3
  _DWORD *v59; // [sp+10h] [bp-68h]
  int v60; // [sp+18h] [bp-60h]
  unsigned int v61; // [sp+1Ch] [bp-5Ch]
  int v62; // [sp+24h] [bp-54h]
  unsigned int v64; // [sp+2Ch] [bp-4Ch]
  _DWORD v65[2]; // [sp+48h] [bp-30h] BYREF
  unsigned int v66; // [sp+50h] [bp-28h] BYREF
  unsigned int *v67; // [sp+54h] [bp-24h]
  int varg_r0; // [sp+80h] [bp+8h]
  int varg_r1; // [sp+84h] [bp+Ch]
  int varg_r2; // [sp+88h] [bp+10h]
  _DWORD *varg_r3; // [sp+8Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  v7 = a3;
  varg_r2 = a3;
  v61 = 0;
  v9 = (unsigned __int16)a1;
  v60 = (unsigned __int16)a1;
  if ( (unsigned __int16)a1 >= 0x40u )
    return -1073741816;
  v11 = 0;
  v62 = 0;
  if ( a7 == 1 || (unsigned int)KeGetCurrentIrql() < 2 )
  {
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v12 + 308);
    if ( !ExAcquireRundownProtectionCacheAwareEx(EtwpLoggerRundown[v9], 1) )
    {
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(_WORD *)(v13 + 0x134) + 1;
      *(_WORD *)(v13 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery(0);
      goto LABEL_18;
    }
    v11 = 1;
    v62 = 1;
  }
  v15 = (_DWORD *)WmipLoggerContext[v9];
  v59 = v15;
  if ( ((unsigned __int8)v15 & 1) == 0 )
    goto LABEL_19;
  if ( v11 )
  {
    v16 = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v9], 1);
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(_WORD *)(v17 + 0x134) + 1;
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(v16);
  }
LABEL_18:
  v15 = 0;
  v59 = 0;
LABEL_19:
  if ( !v15 )
    return -1073741816;
  v19 = v15[3];
  if ( (v19 & 0x80) != 0 )
  {
    v10 = -1073741790;
  }
  else if ( a7 || (v19 & 0x1000000) == 0 )
  {
    v20 = v7 & 0x40;
    v21 = (int)a6;
    if ( (v7 & 0x40) != 0 )
    {
      v22 = (unsigned int)a6 + a2;
      v61 = (unsigned int)a6 + a2;
    }
    else
    {
      v22 = 0;
    }
    v23 = 0;
    v64 = 0;
    v24 = (int)a6;
    while ( 1 )
    {
      if ( (v7 & 0x40) != 0 && v24 + 4 > v22 )
      {
        v10 = -1073741306;
LABEL_105:
        v9 = v60;
        goto LABEL_106;
      }
      v25 = (_DWORD *)((-v24 & 3) + v24);
      if ( !*v25 )
        break;
      v26 = (_DWORD *)((char *)v25 + (-(int)(v25 + 1) & 3) + 4);
      v24 = (int)(v26 + 1);
      v27 = *v26;
      if ( v27 )
      {
        v23 += v27;
        v64 = v23;
        if ( v23 < v27 )
        {
          v10 = -1073741675;
          goto LABEL_105;
        }
      }
    }
    if ( !v15[48] )
      v7 &= 0xFEu;
    if ( (v7 & 1) != 0 )
      v28 = 4;
    else
      v28 = 0;
    if ( (v7 & 2) != 0 )
      v29 = 16;
    else
      v29 = 0;
    if ( (v7 & 4) != 0 )
      v30 = 4;
    else
      v30 = 0;
    if ( (v7 & 0x18) != 0 )
      v31 = 8;
    else
      v31 = 0;
    if ( (v7 & 0x20) != 0 )
      v32 = 8;
    else
      v32 = 0;
    v33 = v32 + v31 + v30 + v29 + v28 + v23 + 8;
    if ( v23 > v33 )
    {
      v10 = -1073741306;
      goto LABEL_105;
    }
    v34 = EtwpReserveTraceBuffer(v59, v33, &v66, v65, 0);
    v35 = 0;
    if ( v59[48] )
    {
      __dmb(0xBu);
      v36 = (unsigned int *)v59[48];
      do
      {
        v37 = __ldrex(v36);
        v35 = v37 + 1;
      }
      while ( __strex(v35, v36) );
      __dmb(0xBu);
    }
    if ( !v34 )
    {
      if ( v33 <= 0xFFF8 )
      {
        if ( v33 <= v59[2] )
          v10 = -1073741801;
        else
          v10 = -2147483643;
      }
      else
      {
        v10 = -1073741675;
      }
      goto LABEL_105;
    }
    *(_DWORD *)v34 = -1879048192;
    *(_WORD *)v34 = v33;
    *(_WORD *)(v34 + 4) = a5;
    *(_WORD *)(v34 + 6) = v7 & 0x3F | 0x40;
    v38 = (unsigned int *)(v34 + 8);
    if ( (v7 & 1) != 0 )
    {
      *v38 = v35;
      v38 = (unsigned int *)(v34 + 12);
    }
    if ( (v7 & 4) != 0 )
    {
      *v38++ = *a4;
    }
    else if ( (v7 & 2) != 0 )
    {
      v39 = a4[1];
      v40 = a4[2];
      v41 = a4[3];
      *v38 = *a4;
      v38[1] = v39;
      v38[2] = v40;
      v38[3] = v41;
      v38 += 4;
    }
    if ( (v7 & 8) != 0 )
    {
      v38[1] = v65[1];
      *v38 = v65[0];
      v38 += 2;
    }
    if ( (v7 & 0x20) != 0 )
    {
      v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *v38 = *(_DWORD *)(v42 + 0x370);
      v38[1] = *(_DWORD *)(v42 + 0x36C);
      v38 += 2;
    }
    v43 = v64;
    while ( 1 )
    {
      v44 = (unsigned int *)((-v21 & 3) + v21);
      v45 = (int)(v44 + 1);
      v46 = *v44;
      if ( !*v44 )
        break;
      if ( v20 && v45 >= v61 )
      {
LABEL_80:
        v10 = -1073741306;
        goto LABEL_90;
      }
      v47 = (unsigned int *)((-v45 & 3) + v45);
      v21 = (int)(v47 + 1);
      v48 = *v47;
      if ( *v47 )
      {
        if ( v48 > v43 )
          goto LABEL_80;
        if ( v20 && (v48 + v46 > MmUserProbeAddress || v48 + v46 < v46) )
          *(_BYTE *)MmUserProbeAddress = 0;
        memmove((int)v38, v46, v48);
        v43 -= v48;
        v38 = (unsigned int *)((char *)v38 + v48);
      }
    }
    v10 = 0;
LABEL_90:
    v9 = v60;
    if ( (!KdDebuggerNotPresent && !KdPitchDebugger || KdEventLoggingPresent) && (v59[3] & 0x80000) != 0 && v10 >= 0 )
      EtwpSendTraceEvent(v59, &v66);
    v49 = v67;
    __pld(v67);
    v50 = *v49;
    v51 = v66;
    if ( (v66 ^ *v49) >= 7 )
    {
LABEL_102:
      __dmb(0xBu);
      v53 = (unsigned int *)(v51 + 12);
      do
        v54 = __ldrex(v53);
      while ( __strex(v54 - 1, v53) );
      __dmb(0xBu);
    }
    else
    {
      while ( 1 )
      {
        __dmb(0xBu);
        do
          v52 = __ldrex(v49);
        while ( v52 == v50 && __strex(v50 + 1, v49) );
        if ( v52 == v50 )
          break;
        v50 = v52;
        if ( (v51 ^ v52) >= 7 )
          goto LABEL_102;
      }
    }
  }
  else
  {
    v10 = -1073741637;
  }
LABEL_106:
  if ( v62 )
  {
    v55 = ExReleaseRundownProtectionCacheAwareEx(EtwpLoggerRundown[v9], 1);
    v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v57 = *(_WORD *)(v56 + 0x134) + 1;
    *(_WORD *)(v56 + 308) = v57;
    if ( !v57 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
      KiCheckForKernelApcDelivery(v55);
  }
  return v10;
}
