// PfpCopyUserPfnPrioRequest 
 
int __fastcall PfpCopyUserPfnPrioRequest(unsigned int a1, unsigned int a2, int a3, _DWORD *a4, char a5, int a6)
{
  unsigned int v6; // r9
  int v7; // r8
  _DWORD *v8; // r5
  unsigned int v9; // r6
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r4
  int v13; // r8
  _BYTE *v14; // r0
  unsigned int i; // r1
  _DWORD *v17; // [sp+8h] [bp-28h]
  int v18; // [sp+Ch] [bp-24h]

  v17 = a4;
  v18 = a3;
  v6 = a2;
  v7 = a1;
  v8 = 0;
  if ( a5 && a2 )
  {
    if ( (a1 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 + a2 > MmUserProbeAddress || a1 + a2 < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v9 = *(_DWORD *)(a1 + 8);
  if ( !((16 * v9 + __PAIR64__(v9 >> 28, 104)) >> 32) && v9 && v9 <= MmGetHighestPhysicalPage(0) + 1 && v10 <= v6 )
  {
    v11 = ExAllocatePoolWithTag(512, v10, 1112565328);
    v8 = (_DWORD *)v11;
    if ( !v11 )
    {
      v12 = -1073741670;
      goto LABEL_25;
    }
    memmove(v11, v7, 0x68u);
    if ( *v8 == 1 && (v18 == 22 || (v8[1] & 0xFFFFFFFE) == 0) && v8[2] == v9 )
    {
      v13 = v7 + 104;
      v14 = v8 + 26;
      if ( a6 )
      {
        memset(v14, 0, 16 * v9);
        for ( i = 0; i < v9; ++i )
          v8[4 * i + 28] = *(_DWORD *)(v13 + 16 * i + 8);
      }
      else
      {
        memmove((int)v14, v13, 16 * v9);
      }
      *v17 = v8;
      v8 = 0;
      v12 = 0;
      goto LABEL_25;
    }
  }
  v12 = -1073741811;
LABEL_25:
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  return v12;
}
