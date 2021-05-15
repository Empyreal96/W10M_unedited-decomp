// MiReplaceWorkingSetEntryLarge 
 
int __fastcall MiReplaceWorkingSetEntryLarge(int a1, int a2)
{
  _DWORD *v2; // r8
  int v5; // r3
  int v6; // r0
  int v7; // r6
  int v8; // r4
  unsigned int v9; // lr
  int v10; // r1
  int v11; // r10
  int v12; // r0
  int v13; // r9
  int v14; // lr
  int v15; // r0
  bool v16; // zf
  unsigned int v17; // [sp+8h] [bp-E8h]
  int v18; // [sp+Ch] [bp-E4h]
  int v19; // [sp+10h] [bp-E0h]
  int v21; // [sp+18h] [bp-D8h]
  int v22; // [sp+1Ch] [bp-D4h]
  unsigned int *v23; // [sp+20h] [bp-D0h]
  int v24; // [sp+24h] [bp-CCh]
  unsigned int v25; // [sp+28h] [bp-C8h]
  int v26; // [sp+30h] [bp-C0h] BYREF
  char v27; // [sp+34h] [bp-BCh]
  char v28; // [sp+35h] [bp-BBh]
  int v29; // [sp+38h] [bp-B8h]
  int v30; // [sp+3Ch] [bp-B4h]
  int v31; // [sp+40h] [bp-B0h]
  int v32; // [sp+44h] [bp-ACh]
  char v33; // [sp+C8h] [bp-28h] BYREF
  int v34; // [sp+C9h] [bp-27h]
  __int16 v35; // [sp+CDh] [bp-23h]
  char v36; // [sp+CFh] [bp-21h]

  v2 = *(_DWORD **)(a1 + 92);
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  if ( v2[9] != 16 )
    return MiReplaceWorkingSetEntrySmall(a1, a2);
  v5 = MiTbFlushType(a1);
  v6 = 0;
  v24 = v5;
  while ( 2 )
  {
    v18 = v6;
    v26 = v5;
    v27 = 0;
    v28 = 0;
    v31 = 0;
    v29 = 33;
    v7 = 7;
    v8 = 15;
    v9 = 0;
    v10 = 0xFFFFF;
    v32 = 0;
    v30 = 0;
    v11 = v2[30];
    v17 = 0;
    v19 = 0xFFFFF;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( v11 )
        {
          v12 = MiRotateHeadWsle(v2, v8);
          v10 = v19;
          v9 = v17;
          v13 = v12;
          v6 = v18;
          --v11;
        }
        else
        {
          v13 = 0xFFFFF;
        }
        if ( v13 == 0xFFFFF )
          break;
        v21 = v2[63];
        v22 = v2[9] * v13;
        v23 = (unsigned int *)(((*(_DWORD *)(v22 + v21) >> 10) & 0x3FFFFC) - 0x40000000);
        v25 = *v23;
        v14 = MmPfnDatabase + 24 * (*v23 >> 12);
        if ( !v6 && (v25 & 0x10) != 0 )
        {
          if ( (unsigned int)(v7 - 1) > 5 )
          {
            if ( ((*(_DWORD *)(v14 + 12) & 0x3FFFFFFFu) <= 1 || (*(_DWORD *)(v14 + 20) & 0x8000000) != 0)
              && ((*(_BYTE *)(a1 + 112) & 7) == 0 || *(unsigned __int16 *)(v14 + 16) <= 1u) )
            {
              ++v17;
              if ( v10 == 0xFFFFF )
                v19 = v13;
            }
            MiClearPteAccessed(
              a1,
              MmPfnDatabase + 24 * (v25 >> 12),
              (unsigned int)v23,
              (_DWORD *)(v22 + v21),
              (int)&v26,
              0);
          }
          else
          {
            MiUpdateWorkingSetAgeDistribution(a1, v7, -1);
            MiSetWsleAge((int)v2, (_DWORD *)(v21 + v22), 0);
          }
          v6 = v18;
          goto LABEL_45;
        }
        MiFlushTbList((unsigned int)&v26, v10);
        v15 = MiTrimSingleWsle(a1, v13);
        v10 = v19;
        v9 = v17;
        v16 = v15 == 1;
        v6 = v18;
        if ( v16 )
        {
          if ( !v18 )
            return MiFlushTbList((unsigned int)&v26, v10);
          v6 = v18 - 1;
          v18 = v6;
          if ( !v6 )
            return MiFlushTbList((unsigned int)&v26, v10);
LABEL_45:
          v10 = v19;
          v9 = v17;
        }
      }
      if ( *(&v33 + v7) || v9 <= 4 || a2 && (v8 & 1) != 0 )
        break;
      *(&v33 + v7) = 1;
      if ( !v7 )
      {
        v7 = 1;
        v8 = 3;
      }
      if ( v10 != 0xFFFFF )
      {
        MiFlushTbList((unsigned int)&v26, v10);
        if ( MiTrimSingleWsle(a1, v19) == 1 )
          return MiFlushTbList((unsigned int)&v26, v10);
        v10 = 0xFFFFF;
        v19 = 0xFFFFF;
      }
      v9 = 0;
      v17 = 0;
LABEL_19:
      v11 = v2[v8 + 15];
      v6 = v18;
    }
    MiRotateHeadWsle(v2, v8);
    if ( v8 )
    {
      if ( !a2 && (v8 & 1) != 0 )
        v8 &= 0xFFFFFFFE;
      if ( v8 )
      {
        if ( (v8 & 1) != 0 )
        {
          v10 = v19;
          v9 = v17;
        }
        else
        {
          v10 = 0xFFFFF;
          v9 = 0;
          v19 = 0xFFFFF;
          v17 = 0;
          --v7;
        }
        --v8;
        goto LABEL_19;
      }
    }
    if ( !a2 && !v18 )
    {
      MiFlushTbList((unsigned int)&v26, v10);
      v5 = v24;
      v6 = 4;
      continue;
    }
    return MiFlushTbList((unsigned int)&v26, v10);
  }
}
