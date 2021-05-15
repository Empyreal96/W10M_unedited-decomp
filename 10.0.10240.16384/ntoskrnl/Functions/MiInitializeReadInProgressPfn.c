// MiInitializeReadInProgressPfn 
 
int __fastcall MiInitializeReadInProgressPfn(int result, _DWORD *a2, int a3, unsigned int a4, int a5, char a6)
{
  int *v6; // r5
  unsigned int v7; // r7
  int v8; // r9
  int *v9; // lr
  char v10; // r2
  int v11; // t1
  int v12; // r4
  unsigned int v13; // r8
  int v14; // lr
  unsigned int v15; // r1
  char v16; // r0
  int v17; // lr
  unsigned int v18; // r2
  int v19; // r10
  int v20; // r2
  unsigned int v21; // r3
  int v22; // r8
  int v23; // r9
  unsigned __int8 *v24; // r3
  unsigned int v25; // r1
  int v26; // r3
  unsigned int *v27; // r2
  unsigned int v28; // r0
  int v29; // r2
  unsigned __int8 *v30; // r3
  unsigned int v31; // r1
  unsigned int *v32; // r1
  unsigned int v33; // r2
  unsigned int v34; // r2
  int v35; // r3
  unsigned __int8 *v36; // r1
  int v37; // r3
  unsigned int v38; // r2
  int v39; // r3
  unsigned __int8 *v40; // lr
  int v41; // r3
  unsigned int v42; // r2
  int v43; // r0
  char v44; // [sp+8h] [bp-48h]
  int v45; // [sp+Ch] [bp-44h]
  int v46; // [sp+10h] [bp-40h]
  int v47; // [sp+18h] [bp-38h]
  unsigned int v48; // [sp+1Ch] [bp-34h]
  unsigned int v49; // [sp+24h] [bp-2Ch]
  unsigned int v50; // [sp+30h] [bp-20h]
  int varg_r0; // [sp+58h] [bp+8h]
  _DWORD *varg_r1; // [sp+5Ch] [bp+Ch]
  unsigned int varg_r3; // [sp+64h] [bp+14h]

  varg_r0 = result;
  varg_r1 = a2;
  varg_r3 = a4;
  v6 = a2;
  v7 = a4;
  v46 = 0;
  v47 = 0;
  v48 = result;
  v8 = 0xFFFFF;
  v45 = 0xFFFFF;
  v50 = (unsigned int)&a2[a3];
  if ( (unsigned int)a2 < v50 )
  {
    v9 = MiState;
    v10 = a6;
    result = MmPfnDatabase;
    while ( 1 )
    {
      v11 = *v6++;
      v12 = result + 24 * v11;
      if ( v12 != v9[1950] )
        break;
LABEL_43:
      v7 += 4;
      if ( (unsigned int)v6 >= v50 )
        return result;
    }
    v13 = *(_DWORD *)v7;
    v14 = 0;
    v44 = 0;
    v49 = *(_DWORD *)v7;
    v15 = *(_DWORD *)v7;
    if ( (v10 & 0x40) != 0 )
    {
      if ( (v13 & 0xFFFFE000) == -8192 )
        return sub_5390F4();
      v34 = *(_DWORD *)(result
                      + 24
                      * (*(_DWORD *)((*(_DWORD *)v7 & 0x1FC | (*(_DWORD *)v7 >> 2) & 0x3FFFFE00) - 0x40000000) >> 12)
                      + 8);
      if ( (v34 & 0x400) != 0 )
        v35 = (*(unsigned __int16 *)((v34 & 0xFFFFF800 | (2 * (v34 & 0x3FC))) + 0x10) >> 1) & 0x1F;
      else
        v35 = (v34 >> 5) & 0x1F;
      v14 = MmMakeProtectNotWriteCopy[v35];
      v15 = 32 * (v14 & 0x1F);
      v44 = v14;
    }
    else if ( (v13 & 0x400) == 0 && (v13 & 0x800) != 0 )
    {
      v15 = *(_DWORD *)(result + 24 * (v13 >> 12) + 8);
    }
    *(_DWORD *)(v12 + 8) = v15;
    *(_DWORD *)v12 = a5;
    v16 = a6;
    if ( (a6 & 0x40) != 0 )
    {
      v18 = v14;
    }
    else
    {
      if ( (a6 & 0x10) != 0 && (*(_DWORD *)(v12 + 20) |= 0x8000000u, v16 = a6, (v15 & 0x400) != 0) )
        v17 = (*(unsigned __int16 *)((v15 & 0xFFFFF800 | (2 * (v15 & 0x3FC))) + 0x10) >> 1) & 0x1F;
      else
        v17 = (v15 >> 5) & 0x1F;
      v44 = v17;
      v18 = v17;
      if ( v17 == 24 && v48 <= MmHighestUserAddress )
      {
        v39 = MiLocateAddress(v48)[7];
        v16 = a6;
        v18 = (unsigned __int8)v39 >> 3;
      }
    }
    v19 = 1;
    if ( v18 != 31 )
    {
      if ( v18 >> 3 == 3 && (v18 & 7) != 0 )
      {
        v19 = 2;
      }
      else if ( v18 >> 3 == 1 )
      {
        v19 = 0;
      }
    }
    if ( v8 == 0xFFFFF )
    {
      v20 = ((v7 >> 10) & 0x3FFFFC) - 0x40000000;
    }
    else
    {
      if ( (v7 & 0xFFF) != 0 )
      {
LABEL_19:
        v22 = v7;
        if ( (v16 & 0x20) != 0 )
          v22 = v7 & 0x7FFFFFFF;
        *(_BYTE *)(v12 + 18) |= 0x20u;
        v23 = KfRaiseIrql(2);
        v24 = (unsigned __int8 *)(v12 + 15);
        do
          v25 = __ldrex(v24);
        while ( __strex(v25 | 0x80, v24) );
        __dmb(0xBu);
        if ( v25 >> 7 )
        {
          v40 = (unsigned __int8 *)(v12 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v41 = *(_DWORD *)(v12 + 12);
              __dmb(0xBu);
            }
            while ( (v41 & 0x80000000) != 0 );
            do
              v42 = __ldrex(v40);
            while ( __strex(v42 | 0x80, v40) );
            __dmb(0xBu);
          }
          while ( v42 >> 7 );
        }
        if ( *(unsigned __int8 *)(v12 + 18) >> 6 != v19 )
          MiChangePageAttribute(v12, v19, 1);
        MiSetPfnTbFlushStamp(v12, 0, 1);
        *(_DWORD *)(v12 + 12) &= 0xC0000000;
        *(_WORD *)(v12 + 16) = 1;
        if ( (a6 & 8) != 0 )
          *(_BYTE *)(v12 + 19) ^= (*(_BYTE *)(v12 + 19) ^ a6) & 7;
        v26 = *(_DWORD *)(v12 + 20);
        *(_DWORD *)(v12 + 4) = v22;
        *(_DWORD *)(v12 + 20) = v26 & 0xFFF00000 | v45 & 0xFFFFF;
        *(_BYTE *)(v12 + 18) = *(_BYTE *)(v12 + 18) & 0xF8 | 2;
        if ( (a6 & 0x80) != 0 )
          *(_BYTE *)(v12 + 19) |= 0x20u;
        __dmb(0xBu);
        v27 = (unsigned int *)(v12 + 12);
        do
          v28 = __ldrex(v27);
        while ( __strex(v28 & 0x7FFFFFFF, v27) );
        KfLowerIrql(v23);
        if ( (v49 & 0x400) != 0 || (v49 & 0x800) == 0 )
        {
          v29 = 32 * (v44 & 0x1F | (*(v6 - 1) << 7) | 0x40);
          if ( v7 + 0x40000000 <= 0x3FFFFF )
          {
            __dmb(0xBu);
            *(_DWORD *)v7 = v29;
            if ( v7 >= 0xC0300000 && v7 <= 0xC0300FFF )
            {
              v43 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v43, v43 + 4 * (v7 & 0xFFF), v29);
            }
          }
          else
          {
            *(_DWORD *)v7 = v29;
          }
        }
        v10 = a6;
        if ( (a6 & 0x40) == 0 )
        {
          v30 = (unsigned __int8 *)(v47 + 15);
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 | 0x80, v30) );
          __dmb(0xBu);
          if ( v31 >> 7 )
          {
            v36 = (unsigned __int8 *)(v47 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v37 = *(_DWORD *)(v47 + 12);
                __dmb(0xBu);
              }
              while ( (v37 & 0x80000000) != 0 );
              do
                v38 = __ldrex(v36);
              while ( __strex(v38 | 0x80, v36) );
              __dmb(0xBu);
            }
            while ( v38 >> 7 );
          }
          *(_DWORD *)(v47 + 12) = *(_DWORD *)(v47 + 12) & 0xC0000000 | (*(_DWORD *)(v47 + 12) + 1) & 0x3FFFFFFF;
          __dmb(0xBu);
          v32 = (unsigned int *)(v47 + 12);
          do
            v33 = __ldrex(v32);
          while ( __strex(v33 & 0x7FFFFFFF, v32) );
          v10 = a6;
        }
        v9 = MiState;
        v8 = v45;
        result = MmPfnDatabase;
        goto LABEL_43;
      }
      v20 = v46 + 4;
    }
    v21 = *(_DWORD *)v20;
    v46 = v20;
    if ( (*(_DWORD *)v20 & 2) == 0 )
      KeBugCheckEx(26, 399680, v20 << 10);
    v45 = v21 >> 12;
    v47 = MmPfnDatabase + 24 * (v21 >> 12);
    goto LABEL_19;
  }
  return result;
}
