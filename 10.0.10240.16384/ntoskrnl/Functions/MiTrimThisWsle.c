// MiTrimThisWsle 
 
int __fastcall MiTrimThisWsle(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  int v6; // r10
  unsigned int v7; // r7
  _DWORD *v8; // r8
  int v9; // r4
  int v10; // r3
  unsigned int v11; // r2
  unsigned int v13; // r1
  __int16 v14; // r2
  _DWORD *v15; // r1
  int v16; // [sp+0h] [bp-28h]
  int varg_r0; // [sp+30h] [bp+8h]
  int varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  v4 = *(_DWORD *)(a1 + 92);
  varg_r2 = a3;
  v6 = *(_DWORD *)(v4 + 36) * a2;
  v7 = *(_DWORD *)(v6 + *(_DWORD *)(v4 + 252));
  v16 = *(_DWORD *)(v4 + 252);
  v8 = (_DWORD *)(((v7 >> 10) & 0x3FFFFC) - 0x40000000);
  v9 = MmPfnDatabase + 24 * (*v8 >> 12);
  v10 = *(_DWORD *)(v9 + 4);
  if ( v10 >= 0 )
  {
    MiDemoteCombinedPte(((v7 >> 10) & 0x3FFFFC) - 0x40000000, v10 | 0x80000000);
    LOBYTE(a3) = varg_r2;
    v7 = *(_DWORD *)(v6 + v16);
  }
  if ( (a3 & 0x60) != 0 )
  {
    if ( (*(_DWORD *)(v9 + 20) & 0x8000000) == 0 )
      goto LABEL_18;
    if ( (a3 & 0x20) != 0 && (*(_DWORD *)(v9 + 8) & 0x400) == 0 )
    {
      if ( (*(_DWORD *)(v9 + 4) & 0x80000000) == 0 || MiLocateCloneAddress(a1 - 492) )
        return 1;
      LOBYTE(a3) = varg_r2;
    }
    if ( (a3 & 0x40) == 0 || (*(_DWORD *)(v9 + 8) & 0x400) == 0 )
      goto LABEL_18;
    return 1;
  }
  v11 = a3 & 0xF;
  if ( !v11
    || (*v8 & 0x10) == 0 && ((v7 >> 9) & 7) >= v11
    || (*(_BYTE *)(v9 + 19) & 8) == 0 && (*(_BYTE *)(v9 + 19) & 7u) < 5 )
  {
    return 1;
  }
LABEL_18:
  v13 = (v7 >> 9) & 7;
  if ( (*v8 & 0x10) == 0 )
  {
    if ( (*(_BYTE *)(a1 + 112) & 7) != 0 && *(_WORD *)(v9 + 16) != 1
      || v13 >= 6
      || (*(_BYTE *)(v9 + 19) & 8) != 0
      || (*(_BYTE *)(v9 + 19) & 7u) >= 5 )
    {
      return 0;
    }
    MiUpdateWorkingSetAgeDistribution(a1, v13, -1);
    MiUpdateWorkingSetAgeDistribution(a1, 6, 1);
    v15 = (_DWORD *)(*(_DWORD *)(v4 + 252) + *(_DWORD *)(v4 + 36) * a2);
    v14 = 6;
    goto LABEL_27;
  }
  if ( v13 - 1 <= 5 )
  {
    MiUpdateWorkingSetAgeDistribution(a1, v13, -1);
    v14 = 0;
    v15 = (_DWORD *)(v6 + v16);
LABEL_27:
    MiSetWsleAge(v4, v15, v14);
  }
  return 0;
}
