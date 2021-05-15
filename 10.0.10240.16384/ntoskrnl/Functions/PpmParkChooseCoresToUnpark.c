// PpmParkChooseCoresToUnpark 
 
int __fastcall PpmParkChooseCoresToUnpark(int result, int a2, int a3, int a4, int a5, int a6, int *a7, int a8, _DWORD *a9)
{
  int v9; // r4
  int v11; // lr
  int v12; // r1
  int v13; // r3
  unsigned int v14; // lr
  int v15; // r1
  int v16; // r6
  int v17; // r3
  unsigned int v18; // r5
  unsigned int v19; // r6
  int v20; // r7
  int v21; // r9
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r5
  unsigned int v26; // lr
  int v27; // r10
  unsigned __int8 v28; // r2
  int v29; // r2
  unsigned int v30; // r1
  int v31; // r3
  _DWORD *v32; // r2
  int v33; // r3
  unsigned int v34; // r2
  int v35; // r3
  int v36; // r5
  unsigned int v37; // r2
  char v38; // r1
  char v39; // r0
  int v40; // [sp+18h] [bp-90h]
  unsigned int v41; // [sp+1Ch] [bp-8Ch]
  int v42; // [sp+20h] [bp-88h]
  int v43; // [sp+24h] [bp-84h]
  unsigned int v44; // [sp+28h] [bp-80h]
  int v45; // [sp+30h] [bp-78h]
  int v46; // [sp+38h] [bp-70h]
  int v47; // [sp+3Ch] [bp-6Ch]
  int v48; // [sp+40h] [bp-68h]
  __int16 v49[2]; // [sp+48h] [bp-60h] BYREF
  int v50; // [sp+4Ch] [bp-5Ch]
  int v51; // [sp+50h] [bp-58h]
  __int16 v52[2]; // [sp+58h] [bp-50h] BYREF
  int v53; // [sp+5Ch] [bp-4Ch]
  int v54; // [sp+60h] [bp-48h]
  __int16 v55[2]; // [sp+68h] [bp-40h] BYREF
  int v56; // [sp+6Ch] [bp-3Ch]
  int v57; // [sp+70h] [bp-38h]
  __int16 v58[2]; // [sp+78h] [bp-30h] BYREF
  int v59; // [sp+7Ch] [bp-2Ch]
  int v60; // [sp+80h] [bp-28h]

  v42 = result;
  v9 = a3;
  if ( !result )
    return sub_541530();
  v11 = a3 & a4;
  v48 = a3 & a4;
  if ( (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~a3 >> 16))
                       + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)a3 >> 8))
                       + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)a3)
                       + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~a3 >> 24))) != result
    || v11 )
  {
    v12 = v11 & a5;
    v13 = a3 ^ v11;
    v14 = (unsigned __int8)PpmParkGranularity;
    v44 = (unsigned __int8)PpmParkGranularity;
    v46 = v13 & a5;
    if ( (unsigned __int8)PpmParkGranularity > 1u )
    {
      v40 = 0;
      v29 = v12 | a6;
      v15 = 0;
      while ( v29 )
      {
        v30 = __clz(__rbit(v29));
        v29 &= ~(1 << v30);
        if ( v30 >= KeNumberProcessors_0 )
          v31 = 0;
        else
          v31 = (int)*(&KiProcessorBlock + v30);
        v15 = v40 | *(_DWORD *)(v31 + 3468);
        v40 = v15;
      }
    }
    else
    {
      v15 = v12 | a6;
      v40 = v15;
    }
    if ( !KiClockTimerPerCpu )
    {
      v32 = KiClockTimerOwner >= (unsigned int)KeNumberProcessors_0 ? 0 : *(&KiProcessorBlock + KiClockTimerOwner);
      if ( *((unsigned __int8 *)v32 + 1052) == a2 && (v32[262] & v9) != 0 )
      {
        *a9 |= 0x100u;
        if ( v14 <= 1 )
          v33 = v32[262];
        else
          v33 = v32[867];
        v15 |= v33;
        v40 = v15;
      }
    }
    if ( PpmParkPreferenceHandler )
    {
      v58[0] = 1;
      v55[0] = 1;
      v49[0] = 1;
      v58[1] = 1;
      v55[1] = 1;
      v49[1] = 1;
      v52[0] = 1;
      v51 = 0;
      v53 = 0;
      v57 = v15;
      v54 = 0;
      v59 = 0;
      v60 = v9;
      v56 = 0;
      v50 = 0;
      v52[1] = 1;
      PpmParkPreferenceHandler(0, PpmParkPreferenceHandler, PpmCheckTime, dword_61E04C, result, v58, v55, v49, v52);
      if ( a2 )
      {
        v16 = 0;
        v17 = 0;
      }
      else
      {
        v16 = v51;
        v17 = v54;
      }
      v43 = v17;
      PpmEventParkNodePreference(a2, v9, (unsigned __int8)v42, v42);
      v14 = (unsigned __int8)PpmParkGranularity;
      v44 = (unsigned __int8)PpmParkGranularity;
    }
    else
    {
      v16 = 0;
      v43 = 0;
    }
    v18 = v40;
    v47 = ~v16 & ~v43 & v9;
    *a7 |= v9;
    v19 = v42;
    v20 = v9;
    v21 = v9;
    v22 = (unsigned __int8)PpmParkCoreMask;
    v23 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v40 >> 16))
                          + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v40 >> 8))
                          + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v40)
                          + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v40 >> 24)));
    v45 = (unsigned __int8)PpmParkCoreMask;
    v41 = v23;
    if ( v42 )
    {
      do
      {
        if ( v19 <= v23 )
          break;
        if ( (v9 & v18) != 0 )
        {
          v9 &= v18;
          *a9 |= 0x200u;
        }
        if ( (v9 & v43) != 0 )
        {
          v9 &= v43;
          *a9 |= 0x400u;
        }
        if ( (v9 & v47) != 0 )
        {
          v9 &= v47;
          *a9 |= 0x800u;
        }
        if ( (v9 & v46) != 0 )
        {
          v9 &= v46;
          *a9 |= 0x1000u;
        }
        if ( (v9 & ~v48) != 0 )
        {
          v9 &= ~v48;
          *a9 |= 0x2000u;
        }
        v24 = __clz(__rbit(v9)) & 0x1F;
        if ( v24 >= KeNumberProcessors_0 )
          v25 = 0;
        else
          v25 = (int)*(&KiProcessorBlock + v24);
        if ( v22 )
          v26 = *(_DWORD *)(v25 + 3468);
        else
          v26 = *(_DWORD *)(v25 + 1048);
        v27 = *a7 & ~v26;
        *a7 = v27;
        if ( v19 >= v44 )
          v19 -= v44;
        v28 = *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)(~(v40 & v26) >> 16))
            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(v40 & v26) >> 8))
            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(v40 & v26))
            + *((_BYTE *)RtlpBitsClearTotal + (~(v40 & v26) >> 24));
        v23 = v41;
        if ( v28 )
        {
          v23 = v41 - v28;
          v41 = v23;
          v40 &= ~v26;
        }
        v9 &= ~*(_DWORD *)(*(_DWORD *)(v25 + 2360) + 260);
        v20 &= ~*(_DWORD *)(v25 + 4 * *(unsigned __int8 *)(v25 + 1052) + 3384);
        v21 &= ~*(_DWORD *)(v25 + 3468);
        if ( !v9 )
        {
          if ( !v20 )
          {
            if ( !v21 )
              v21 = v27;
            v20 = v21;
          }
          v9 = v20;
        }
        v18 = v40;
        v22 = v45;
      }
      while ( v19 );
      v14 = v44;
    }
    while ( 1 )
    {
      if ( a8 )
      {
        if ( !v19 )
          return (unsigned __int8)v42;
      }
      else if ( !v23 )
      {
        return (unsigned __int8)v42;
      }
      *a9 |= 0x4000u;
      v34 = __clz(__rbit(v18)) & 0x1F;
      if ( v34 >= KeNumberProcessors_0 )
        v35 = 0;
      else
        v35 = (int)*(&KiProcessorBlock + v34);
      if ( v22 )
        v36 = *(_DWORD *)(v35 + 3468);
      else
        v36 = *(_DWORD *)(v35 + 1048);
      v19 -= v14;
      v37 = ~(v36 & v40);
      v38 = *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)v37);
      v37 >>= 8;
      v40 &= ~v36;
      v39 = *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)v37) + v38;
      *a7 &= ~v36;
      v22 = v45;
      v18 = v40;
      v23 = v41
          - (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + BYTE1(v37))
                            + *((_BYTE *)RtlpBitsClearTotal + HIWORD(v37))
                            + v39);
      v41 = v23;
    }
  }
  result = (unsigned __int8)result;
  *a7 &= ~a3;
  return result;
}
