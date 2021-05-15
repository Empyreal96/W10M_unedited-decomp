// KiConfigureSchedulingInformation 
 
int __fastcall KiConfigureSchedulingInformation(int a1, int a2)
{
  int v2; // r5
  unsigned int v3; // r0
  int v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r1
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r9
  unsigned int v12; // r6
  unsigned int v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r0
  int v17; // r7
  unsigned int v18; // r9
  int v19; // r10
  int v20; // r8
  int v21; // r5
  unsigned int v22; // r2
  int v23; // r6
  int v24; // r2
  int v25; // r4
  char v26; // r2
  int v27; // r9
  unsigned int v28; // r10
  unsigned int v29; // r2
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r2
  int v34; // r1
  unsigned int v35; // [sp+0h] [bp-48h] BYREF
  int v36; // [sp+4h] [bp-44h]
  unsigned int v37; // [sp+8h] [bp-40h]
  int v38; // [sp+Ch] [bp-3Ch]
  int v39; // [sp+10h] [bp-38h]
  unsigned int v40; // [sp+14h] [bp-34h]
  unsigned int v41; // [sp+18h] [bp-30h]
  int v42; // [sp+1Ch] [bp-2Ch]
  int v43[10]; // [sp+20h] [bp-28h] BYREF

  v2 = a1;
  v3 = *(unsigned __int8 *)(a1 + 3576);
  v38 = v2;
  if ( !v3 )
    return sub_694258();
  v6 = *(_DWORD *)(v2 + 4 * v3 + 3476);
  v7 = 0;
  v8 = *(unsigned __int8 *)(v2 + 1053);
  v36 = 0;
  *(_DWORD *)(v2 + 3476) = v6;
  v9 = *(_DWORD *)(v2 + 3468);
  while ( (*(_DWORD *)(v2 + 4 * v7 + 3480) & ~v9) == 0 )
  {
    v36 = ++v7;
    if ( v7 >= v3 )
      goto LABEL_8;
  }
  v10 = *(_DWORD *)(v2 + 4 * v7 + 3480);
  v8 = __clz(__rbit(v10));
  *(_DWORD *)(v2 + 3472) = v10;
LABEL_8:
  v11 = *(_DWORD *)(v2 + 2360);
  *(_DWORD *)(v2 + 3500) = v8;
  v39 = v11;
  if ( !a2 && *(_DWORD *)(v2 + 20) == *(_DWORD *)(v11 + 280) )
  {
    v12 = KiMaximumSharedReadyQueueSize;
    if ( !KiMaximumSharedReadyQueueSize )
      v12 = 1;
    if ( (v12 & 0x100) != 0 )
    {
      v43[0] = 65537;
      v43[1] = 0;
      v43[2] = 0;
      v12 &= 0xFFFFFEFF;
      if ( KiDetectHeterogeneousSets(v43) )
        v12 *= 2;
    }
    if ( v12 > 0x20 )
      v12 = 32;
    v42 = KfRaiseIrql(2);
    v13 = *(unsigned __int16 *)(v11 + 266);
    *(_DWORD *)(v11 + 272) = 0;
    KeQueryNodeActiveAffinity(v13, v43, &v35);
    v14 = (unsigned __int16)v35;
    v15 = (unsigned __int16)v35 + v12 - 1;
    if ( !v12 )
      __brkdiv0();
    v16 = v15 / v12;
    if ( !(v15 / v12) )
      __brkdiv0();
    v17 = *(_DWORD *)(v2 + 3460);
    v35 = (unsigned __int16)v35 % v16;
    v40 = v43[0];
    v18 = v43[0];
    v19 = v14 / v16;
    v37 = v14 / v16;
    v20 = 0;
    v21 = v14 % v16;
    while ( v18 )
    {
      v22 = __clz(__rbit(v18));
      v18 &= ~(1 << v22);
      v41 = v22;
      v23 = (int)*(&KiProcessorBlock + v22);
      if ( v20 == *(unsigned __int8 *)(v17 + 299) )
      {
        v17 = *(_DWORD *)(v23 + 3460);
        v20 = 0;
      }
      if ( !v20 )
      {
        *(_BYTE *)(v17 + 299) = v19;
        if ( v21 )
        {
          *(_BYTE *)(v17 + 299) = v19 + 1;
          --v21;
        }
      }
      v24 = *(_DWORD *)(v23 + 1048);
      *(_DWORD *)(v23 + 3460) = v17;
      ++v20;
      *(_DWORD *)(v17 + 304) |= v24;
      v36 = *(unsigned __int8 *)(v23 + 1053) - *(unsigned __int8 *)(v17 + 297);
      v25 = *(_DWORD *)(v23 + 8);
      *(_DWORD *)(v23 + 28) = v36 + v17 + 264;
      if ( !v25 )
        v25 = *(_DWORD *)(v23 + 4);
      if ( *(char *)(v25 + 123) < 16
        && *(_DWORD *)(v25 + 68)
        && (v33 = *(_DWORD *)(v25 + 68)) != 0
        && (v34 = *(_DWORD *)(v23 + 2352) + v33) != 0
        && KiGetThreadEffectiveRankNonZero(v25, v34, 0) )
      {
        v26 = 1;
      }
      else
      {
        v26 = *(_BYTE *)(v25 + 123);
      }
      **(_BYTE **)(v23 + 28) = v26;
    }
    v2 = v38;
    v27 = v39;
    v28 = v40;
    while ( v28 )
    {
      v29 = __clz(__rbit(v28));
      v30 = (int)*(&KiProcessorBlock + v29);
      v41 = v29;
      v31 = *(_DWORD *)(v30 + 3460);
      v28 &= ~(1 << v29);
      if ( *(unsigned __int8 *)(v31 + 299) > 1u )
        *(_DWORD *)(v30 + 3456) = *(_DWORD *)(v31 + 304);
      v32 = *(unsigned __int8 *)(v30 + 1053);
      if ( v32 == *(unsigned __int8 *)(v31 + 297) && *(unsigned __int8 *)(v31 + 299) > 1u )
      {
        *(_DWORD *)(v30 + 3464) = 1;
        *(_BYTE *)(v31 + 300) = v32;
        *(_DWORD *)(v27 + 272) |= *(_DWORD *)(v30 + 1048);
        v36 = 31 - __clz(*(_DWORD *)(v31 + 304));
        *(_BYTE *)(v31 + 296) = v36 - *(_BYTE *)(v31 + 297) + 1;
      }
    }
    KfLowerIrql(v42);
  }
  return KiConfigureCpuSetSchedulingInformation(v2);
}
