// MiAddRangeToCrashDump 
 
int __fastcall MiAddRangeToCrashDump(int (__fastcall **a1)(_DWORD, unsigned int, int, int), _DWORD *a2, unsigned int a3, int a4, int a5)
{
  unsigned int v5; // r5
  int v6; // r8
  int v7; // r7
  unsigned int v8; // r10
  unsigned int *v9; // r4
  unsigned int v10; // r1
  unsigned int v11; // r6
  unsigned int v12; // r4
  int v13; // r3
  int v14; // r3
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v18; // r8
  unsigned int v19; // r0
  unsigned int v20; // r4
  int v21; // r0
  int v22; // r0
  int i; // [sp+10h] [bp-20h]

  v5 = (unsigned int)a2;
  v6 = a5;
  v7 = 0;
  v8 = a3;
  v9 = (unsigned int *)(a4 + 8 * a5);
  if ( (unsigned int)a2 < *v9 )
    v5 = *v9;
  v10 = v9[1];
  if ( a3 > v10 )
    v8 = v9[1];
  if ( v5 <= v8 )
  {
    v11 = dword_63389C;
    for ( i = (v5 + 4) << 20; ; i += 0x400000 )
    {
      if ( v6 == 1 )
      {
        KdCheckForDebugBreak(1024, v10);
        v11 = dword_63389C;
      }
      v12 = *(_DWORD *)v5;
      if ( (*(_DWORD *)v5 & 2) == 0 && v6 )
        goto LABEL_29;
      if ( v6 == 1 )
        break;
      if ( v6 )
      {
LABEL_44:
        if ( MI_IS_PFN(v12 >> 12) )
        {
          v22 = (*a1)(a1, v12 >> 12, 1, 2);
          if ( v22 < 0 && v7 >= 0 )
            v7 = v22;
        }
        v16 = MiAddRangeToCrashDump(a1, v5 << 10, (v5 << 10) + 4092, a4, v6 - 1);
        goto LABEL_25;
      }
      if ( (*(_DWORD *)v5 & 2) != 0 || (v12 & 0x400) == 0 && (v12 & 0x800) != 0 )
      {
        v18 = v12 >> 12;
        v19 = v12 >> 12;
        v20 = v5 << 10;
        if ( MI_IS_PFN(v19) == 1 )
        {
          if ( v20 < v11
            || *((_BYTE *)&MiState[2423] + ((int)(((v20 >> 20) & 0xFFC) - ((v11 >> 20) & 0xFFC)) >> 2)) != 9
            || (v21 = MmPfnDatabase + 24 * v18,
                v10 = *(_DWORD *)(v21 + 4) | 0x80000000,
                v10 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000)
            || v10 < 0xC0000000
            || (*(_DWORD *)(v21 + 12) & 0x3FFFFFFF) == 1
            && (*(_BYTE *)(v21 + 18) & 7) == 6
            && (*(_DWORD *)(v21 + 20) & 0xFFFFF) == 1048573 )
          {
            v16 = (*a1)(a1, v18, 1, 2);
LABEL_25:
            if ( v16 < 0 && v7 >= 0 )
              v7 = v16;
            v11 = dword_63389C;
            goto LABEL_29;
          }
        }
      }
LABEL_29:
      v5 += 4;
      v6 = a5;
      if ( v5 > v8 )
        return v7;
    }
    v10 = v5;
    v13 = 2;
    do
    {
      v10 <<= 10;
      --v13;
    }
    while ( v13 );
    if ( *(_DWORD *)(a4 + 24) == 1 )
    {
      if ( v10 < v11 )
      {
LABEL_20:
        if ( (v12 & 0x400) == 0 )
          goto LABEL_44;
        if ( MI_IS_PFN(v12 >> 12) )
        {
          v15 = v5 << 20;
          if ( v5 << 20 < *(_DWORD *)(a4 + 16) )
            v15 = *(_DWORD *)(a4 + 16);
          v16 = (*a1)(a1, v15, (i - v15) >> 12, 1);
          goto LABEL_25;
        }
        goto LABEL_29;
      }
      v14 = *((unsigned __int8 *)&MiState[2423] + ((int)(((v10 >> 20) & 0xFFC) - ((v11 >> 20) & 0xFFC)) >> 2));
      if ( v14 == 1 || v14 == 11 )
        goto LABEL_29;
    }
    if ( v10 >= v11 && *((_BYTE *)&MiState[2423] + ((int)(((v10 >> 20) & 0xFFC) - ((v11 >> 20) & 0xFFC)) >> 2)) == 8 )
      goto LABEL_29;
    goto LABEL_20;
  }
  return v7;
}
