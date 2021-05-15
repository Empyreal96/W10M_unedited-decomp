// KiIpiSendRequest 
 
unsigned int __fastcall KiIpiSendRequest(_DWORD *a1, int a2, int *a3, unsigned int *a4, unsigned __int8 a5, int a6)
{
  int v6; // lr
  _DWORD *v7; // r8
  int v8; // r4
  int v9; // r5
  unsigned int result; // r0
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r9
  unsigned int v14; // r10
  int v15; // r7
  void **v16; // r1
  int v17; // t1
  int v18; // r6
  int v19; // r4
  _DWORD *v20; // r8
  unsigned int v21; // r1
  int v22; // r2
  unsigned int *v23; // r9
  unsigned int *v24; // r7
  unsigned int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r3
  unsigned int v28; // r0
  unsigned int v29; // r1
  unsigned int v30; // r2
  __int16 *v31; // r1
  int v32; // r0
  int v33; // r5
  int v34; // r6
  int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // [sp+0h] [bp-78h]
  unsigned int v39; // [sp+4h] [bp-74h]
  int v40; // [sp+8h] [bp-70h]
  int v41; // [sp+Ch] [bp-6Ch]
  int v42; // [sp+10h] [bp-68h]
  char v43; // [sp+14h] [bp-64h]
  int v44; // [sp+18h] [bp-60h]
  void **v45; // [sp+1Ch] [bp-5Ch]
  int v47; // [sp+24h] [bp-54h]
  int v48; // [sp+28h] [bp-50h]
  int v50; // [sp+30h] [bp-48h]
  unsigned int v51; // [sp+34h] [bp-44h]
  int v52; // [sp+38h] [bp-40h] BYREF
  int v53; // [sp+3Ch] [bp-3Ch]
  int v54; // [sp+40h] [bp-38h]
  __int16 v55[2]; // [sp+48h] [bp-30h] BYREF
  int v56; // [sp+4Ch] [bp-2Ch]
  int v57; // [sp+50h] [bp-28h]

  v47 = a2;
  v6 = a2;
  v7 = a1;
  if ( a2 )
  {
    v52 = *(_DWORD *)&KeActiveProcessors;
    v53 = dword_681D74;
    v54 = dword_681D78[0];
    if ( a2 == 1 )
    {
      v8 = v54 & ~(1 << a1[5]);
      v54 = v8;
    }
    else
    {
      v8 = v54;
    }
    v9 = a6;
    if ( a6 < 0 )
      return sub_5412A8();
  }
  else
  {
    v33 = a3[1];
    v34 = a3[2];
    v52 = *a3;
    v53 = v33;
    v54 = v34;
    v9 = a6;
    v8 = v34;
  }
  v11 = (unsigned __int16)KeNumberNodes;
  a1[384] = 1;
  v55[0] = 1;
  v55[1] = 1;
  result = 0;
  v48 = v9 & 0xF | (16 * (a5 | ((_DWORD)a4 << 8)));
  v12 = v7[5];
  v56 = 0;
  v57 = 0;
  v13 = 0;
  v39 = 0;
  v40 = 0;
  v14 = 0;
  v41 = 0;
  v7[417] = v11;
  if ( v11 )
  {
    v15 = v12 + 576;
    v16 = &KeNodeBlock;
    v38 = v12 + 576;
    do
    {
      v17 = (int)*v16++;
      v45 = v16;
      v18 = v8 & *(_DWORD *)(v17 + 260);
      if ( v18 )
      {
        v19 = (unsigned __int8)~(_BYTE)v18;
        v44 = (unsigned __int8)((unsigned __int16)~(_WORD)v18 >> 8);
        v42 = (unsigned __int8)((unsigned int)~v18 >> 16);
        v20 = 0;
        v50 = v19;
        v51 = (unsigned int)~v18 >> 24;
        while ( v18 )
        {
          v21 = __clz(__rbit(v18));
          v18 &= ~(1 << v21);
          v43 = v21;
          v22 = (int)*(&KiProcessorBlock + v21);
          v23 = (unsigned int *)(v22 + 1664);
          __pld((void *)(v22 + 1664));
          v24 = (unsigned int *)(v22 + 32 * v15);
          __pld(v24);
          if ( !v20 )
          {
            v20 = v24 + 7;
            v24[7] = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + v42)
                                     + *((_BYTE *)RtlpBitsClearTotal + v51)
                                     + *((_BYTE *)RtlpBitsClearTotal + v44)
                                     + *((_BYTE *)RtlpBitsClearTotal + v19));
          }
          v24[6] = (unsigned int)v20;
          if ( v9 == 6 )
          {
            v25 = a4[1];
            v26 = a4[2];
            v27 = a4[3];
            v24[2] = *a4;
            v24[3] = v25;
            v24[4] = v26;
            v24[5] = v27;
            v19 = v50;
          }
          v24[1] = v48;
          v28 = *v23;
          do
          {
            v29 = v28;
            *v24 = v28;
            __dmb(0xBu);
            do
              v30 = __ldrex(v23);
            while ( v30 == v28 && __strex((unsigned int)v24, v23) );
            v28 = v30;
            __dmb(0xBu);
          }
          while ( v30 != v29 );
          v15 = v38;
          v13 = v40;
          if ( !v30 )
          {
            v13 = 1;
            v40 = 1;
            v57 |= 1 << v43;
          }
        }
        v8 = v54;
        v14 = v41;
        v11 = (unsigned __int16)KeNumberNodes;
        v16 = v45;
        result = v39;
      }
      else
      {
        v39 = ++result;
      }
      v41 = ++v14;
    }
    while ( v14 < v11 );
    v6 = v47;
    v7 = a1;
    if ( result )
    {
      __dmb(0xBu);
      v35 = -result;
      v36 = a1 + 417;
      do
      {
        v37 = __ldrex(v36);
        result = v37 + v35;
      }
      while ( __strex(result, v36) );
      __dmb(0xBu);
      if ( !result )
      {
        __dmb(0xBu);
        a1[384] = 0;
        return result;
      }
    }
  }
  if ( v9 == 6 )
  {
    if ( v6 == 1 || v6 == 2 )
      ++v7[931];
    else
      ++v7[932];
    v31 = (__int16 *)&v52;
    v32 = v6;
    goto LABEL_29;
  }
  if ( v13 )
  {
    v31 = v55;
    ++v7[932];
    v32 = 0;
LABEL_29:
    result = HalRequestIpi(v32, v31);
  }
  return result;
}
