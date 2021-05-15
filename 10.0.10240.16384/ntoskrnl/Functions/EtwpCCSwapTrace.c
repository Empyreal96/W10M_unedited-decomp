// EtwpCCSwapTrace 
 
int __fastcall EtwpCCSwapTrace(int result, int a2, int a3, _QWORD *a4)
{
  int v4; // r7
  int v5; // lr
  int v6; // r10
  int v7; // r9
  unsigned int v8; // r4
  int v9; // r8
  int *v10; // r0
  int v11; // r5
  unsigned int v12; // r6
  int v13; // r4
  unsigned int v14; // r1
  int v15; // r3
  int v16; // r2
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r3
  int v20; // r3
  unsigned int v21; // r2
  __int16 v22; // r3
  unsigned int v23; // r4
  __int16 v24; // r2
  __int16 v25; // r3
  int v26; // r3
  int v27; // r2
  __int16 v28; // r3
  __int16 v29; // r3
  int v30; // r2
  unsigned int v31; // r5
  unsigned int v32; // r1
  _DWORD *v33; // r2
  unsigned int v34; // r1
  unsigned int v35; // r2
  int v36; // r3
  int v37; // r6
  int v38; // r3
  __int64 v39; // kr10_8
  int v40; // r3
  unsigned int v41; // [sp+8h] [bp-58h] BYREF
  int v42; // [sp+Ch] [bp-54h]
  int v43; // [sp+10h] [bp-50h]
  _QWORD *v44; // [sp+14h] [bp-4Ch]
  int v45; // [sp+18h] [bp-48h]
  int v46; // [sp+1Ch] [bp-44h]
  int v47; // [sp+20h] [bp-40h]
  int v48; // [sp+24h] [bp-3Ch]
  unsigned int v49; // [sp+28h] [bp-38h]
  int v50; // [sp+2Ch] [bp-34h]
  int v51[12]; // [sp+30h] [bp-30h] BYREF

  v4 = (int)a4;
  v43 = a3;
  v44 = a4;
  v5 = a3;
  v6 = a2;
  v47 = a2;
  v7 = result;
  v50 = result;
  v8 = (unsigned int)KeGetPcr();
  v9 = *(_DWORD *)(*(_DWORD *)((v8 & 0xFFFFF000) + 0x138C) + 4 * a3 + 1884);
  v45 = *(_DWORD *)((v8 & 0xFFFFF000) + 0x138C);
  v48 = v9;
  if ( v9 )
  {
    v10 = &KeTickCount;
    if ( *(_DWORD *)v9 )
    {
      v11 = (*a4 - *(_QWORD *)(v9 + 8)) >> 32;
      v12 = *(_DWORD *)a4 - *(_DWORD *)(v9 + 8);
      v4 = (int)v44;
    }
    else
    {
      v39 = *a4;
      v40 = KeTickCount;
      *(_QWORD *)(v9 + 8) = *(_QWORD *)v4;
      *(_QWORD *)(v9 + 16) = v39;
      *(_DWORD *)v9 = 104;
      *(_DWORD *)(v9 + 4) = v40;
      memset((_BYTE *)(v9 + 24), 0, 64);
      v5 = v43;
      v10 = &KeTickCount;
      v12 = 0;
      v11 = 0;
    }
    v13 = *(_DWORD *)(v7 + 880);
    v14 = 0;
    v46 = v13;
    if ( v13 )
    {
      v15 = v9;
      do
      {
        v16 = *(_DWORD *)(v15 + 24);
        if ( v16 == v13 )
          break;
        if ( !v16 )
        {
          *(_DWORD *)(v9 + 4 * v14 + 24) = v13;
          *(_BYTE *)(v14 + v9 + 88) = *(_BYTE *)(v7 + 347);
          break;
        }
        ++v14;
        v15 += 4;
      }
      while ( v14 < 0x10 );
    }
    if ( v14 == 16
      || (unsigned int)(KeTickCount - *(_DWORD *)(v9 + 4)) > 0x1F4
      || (unsigned int)(*(_DWORD *)v9 + 8) > 0x400
      || v11 > 0
      || v11 >= 0 && v12 > 0x40000000
      || *(_BYTE *)(v45 + v5 + 1880) )
    {
      v51[1] = 0;
      v30 = *(_DWORD *)v9;
      v51[0] = v9 + 16;
      v51[2] = v30 - 16;
      v51[3] = 0;
      v31 = EtwpActiveSystemLoggers;
      __dmb(0xBu);
      v32 = __clz(__rbit(v31));
      v49 = v32;
      if ( 1 != (unsigned __int8)(v32 >> 5) )
      {
        while ( 1 )
        {
          v31 &= v31 - 1;
          v33 = &EtwpGroupMasks[8 * v32];
          if ( v33 && (v33[1] & 4) != 0 && v33 && (v33[1] & 0x100) != 0 )
          {
            v37 = (unsigned __int16)EtwpSystemLogger[2 * v32];
            v10 = (int *)KeGetCurrentIrql(v10);
            if ( (unsigned int)v10 < 2 )
              return sub_51B7C8();
            v38 = WmipLoggerContext[v37];
            if ( (v38 & 1) != 0 )
              JUMPOUT(0x51B838);
            if ( v38 && *(_DWORD *)(v38 + 124) == v43 )
              v10 = (int *)EtwpLogKernelEvent(v51, v37, 1, 1317, 514);
          }
          v32 = __clz(__rbit(v31));
          v49 = v32;
          if ( 1 == (unsigned __int8)(v32 >> 5) )
          {
            v13 = v46;
            v6 = v47;
            v9 = v48;
            v7 = v50;
            v4 = (int)v44;
            break;
          }
        }
      }
      v34 = *(_DWORD *)(v4 + 4);
      v35 = *(_DWORD *)v4;
      v36 = KeTickCount;
      *(_QWORD *)(v9 + 8) = *(_QWORD *)v4;
      *(_DWORD *)v9 = 104;
      *(_DWORD *)(v9 + 4) = v36;
      *(_QWORD *)(v9 + 16) = __PAIR64__(v34, v35);
      memset((_BYTE *)(v9 + 24), 0, 64);
      v12 = 0;
      *(_BYTE *)(v43 + v45 + 1880) = 0;
      v11 = 0;
      v14 = 0;
      *(_DWORD *)(v9 + 24) = v13;
    }
    if ( v13 )
    {
      if ( *(_DWORD *)(v6 + 880) )
        v17 = KeTickCount - *(_DWORD *)(v6 + 304);
      else
        v17 = 0;
      v18 = *(char *)(v7 + 123);
      v19 = v18 - *(char *)(v14 + v9 + 88);
      if ( v17 > 1 || v11 >= 0 && v12 >= 0x20000 || v19 > 7 )
      {
        v41 = (4 * v12) | 3;
        if ( v17 >= 0x1FFFF )
          v17 = 0x1FFFF;
        v42 = ((v42 & 0xFFF0 | v14 & 0xF) & 0x3FF | (v17 << 15)) ^ ((v18 & 0x1F) << 10);
        v26 = *(unsigned __int8 *)(v7 + 132);
        __dmb(0xBu);
        if ( v26 == 5 )
        {
          v27 = v42;
          v28 = v42 ^ (16 * *(unsigned __int8 *)(v7 + 395));
        }
        else
        {
          v29 = *(unsigned __int8 *)(v7 + 132);
          __dmb(0xBu);
          v27 = v42;
          v28 = (16 * v29 - 385) ^ v42;
        }
        v42 = v28 & 0x3F0 ^ v27;
        v23 = 8;
      }
      else
      {
        v41 = (v41 & 0x7E00 | (v12 << 15)) & 0xFFFFFE02 | (4 * (v14 & 0xF | (16 * (v19 & 7)))) | 2;
        v20 = *(unsigned __int8 *)(v7 + 132);
        __dmb(0xBu);
        if ( v20 == 5 )
        {
          v21 = v41;
          v22 = v41 ^ (*(unsigned __int8 *)(v7 + 395) << 9);
        }
        else
        {
          v24 = *(unsigned __int8 *)(v7 + 132);
          __dmb(0xBu);
          v25 = (v24 << 9) - 12289;
          v21 = v41;
          v22 = v25 ^ v41;
        }
        v41 = v22 & 0x7E00 ^ v21;
        v23 = 4;
      }
    }
    else if ( v11 < 0 || v12 < 0x4000 )
    {
      LOWORD(v41) = 4 * v12;
      v23 = 2;
    }
    else
    {
      v41 = (4 * v12) | 1;
      v23 = 4;
    }
    result = memmove(*(_DWORD *)v9 + v9, (int)&v41, v23);
    *(_DWORD *)v9 += v23;
    *(_DWORD *)(v9 + 8) = *(_DWORD *)v4;
    *(_DWORD *)(v9 + 12) = *(_DWORD *)(v4 + 4);
  }
  return result;
}
