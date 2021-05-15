// MiReplaceWorkingSetEntrySmall 
 
int __fastcall MiReplaceWorkingSetEntrySmall(int result, int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  bool v5; // zf
  unsigned int v6; // r1
  unsigned int v7; // r4
  unsigned int v8; // r9
  unsigned int v9; // r8
  unsigned int v10; // r6
  _DWORD *v11; // r7
  _DWORD *v12; // r8
  int v13; // r3
  int v14; // r1
  int v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // [sp+0h] [bp-40h]
  int v18; // [sp+4h] [bp-3Ch]
  int v19; // [sp+8h] [bp-38h]
  unsigned int v20; // [sp+Ch] [bp-34h]
  unsigned int v21; // [sp+10h] [bp-30h]
  int v22; // [sp+14h] [bp-2Ch]
  unsigned int v23; // [sp+18h] [bp-28h]
  unsigned int v24; // [sp+1Ch] [bp-24h]

  v4 = *(_DWORD **)(result + 92);
  v5 = a2 == 1;
  if ( a2 == 1 )
    a4 = 0;
  v7 = v4[3];
  v6 = v4[2];
  if ( !v5 )
    a4 = 17;
  v8 = v4[1];
  v23 = v4[2];
  v19 = result;
  v21 = a4;
  if ( v7 > v6 || v7 < v8 )
    v7 = v4[1];
  v17 = 0;
  v18 = 1;
  v9 = v7;
  v24 = v7;
  v20 = 0;
  v10 = 0xFFFFF;
  while ( 1 )
  {
    while ( 1 )
    {
      v11 = (_DWORD *)(v4[63] + v4[9] * v7);
      if ( (*v11 & 1) != 0 )
        break;
      if ( ++v7 > v6 )
        v7 = v8;
      if ( v7 == v9 )
        return result;
    }
    ++v20;
    v12 = (_DWORD *)(((*v11 >> 10) & 0x3FFFFC) - 0x40000000);
    v22 = MmPfnDatabase + 24 * (*v12 >> 12);
    v13 = *(_DWORD *)(v22 + 4);
    if ( (v13 & 0x80000000) == 0 )
    {
      MiDemoteCombinedPte((unsigned int)v12, v13 | 0x80000000);
      result = v19;
    }
    if ( (*v12 & 0x10) != 0 )
    {
      v14 = (*v11 >> 9) & 7;
      if ( (unsigned int)(v14 - 1) <= 5 )
      {
        MiUpdateWorkingSetAgeDistribution(result, v14, -1);
        MiSetWsleAge((int)v4, v11, 0);
      }
      v15 = 1;
    }
    else
    {
      v15 = 0;
    }
    if ( (*(_DWORD *)(v22 + 12) & 0x3FFFFFFFu) <= 1 || (*(_DWORD *)(v22 + 20) & 0x8000000) != 0 )
    {
      result = v19;
      if ( (*(_BYTE *)(v19 + 112) & 7) == 0 || *(unsigned __int16 *)(v22 + 16) <= 1u )
      {
        if ( v10 == 0xFFFFF )
          goto LABEL_25;
        if ( !v15 && (v18 == 1 || ((*v11 >> 9) & 7u) > v17) )
        {
          v15 = 0;
LABEL_25:
          v10 = v7;
          v18 = v15;
          v16 = (*v11 >> 9) & 7;
          v17 = v16;
          goto LABEL_32;
        }
      }
    }
    else
    {
      result = v19;
    }
    v16 = v17;
LABEL_32:
    if ( (v16 >= 2 || v20 > v21) && v10 != 0xFFFFF )
      break;
LABEL_37:
    v6 = v23;
    v9 = v24;
    if ( ++v7 > v23 )
      v7 = v8;
    if ( v7 == v24 )
      return result;
    result = v19;
  }
  result = MiRemoveSingleWsle(result, v10);
  if ( result != 1 )
  {
    v17 = 0;
    v7 = v10;
    v18 = 1;
    v10 = 0xFFFFF;
    goto LABEL_37;
  }
  v4[3] = v10 + 1;
  return result;
}
