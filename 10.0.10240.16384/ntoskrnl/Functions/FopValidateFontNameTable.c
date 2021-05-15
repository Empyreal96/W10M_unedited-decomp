// FopValidateFontNameTable 
 
int __fastcall FopValidateFontNameTable(_DWORD *a1, int a2, _DWORD *a3)
{
  int v5; // r4
  int v6; // r8
  int v7; // r7
  unsigned int v8; // r2
  _WORD *v9; // r5
  unsigned int v10; // r3
  int v11; // r0
  _WORD *v12; // r6
  unsigned int v14; // r2
  int v15; // r3
  _WORD *v16; // r1
  int v17; // [sp+8h] [bp-28h] BYREF
  int v18; // [sp+Ch] [bp-24h] BYREF
  char v19[32]; // [sp+10h] [bp-20h] BYREF

  v17 = 0;
  v5 = FopGetTableOffsetAndSize(a1, a2, 1851878757, &v18, v19);
  if ( v5 < 0 )
    return v5;
  v6 = v18;
  v5 = FopReadNamingTable(a1, v18, &v17);
  v7 = v17;
  if ( v5 >= 0 )
  {
    v8 = 0;
    v9 = (_WORD *)(v17 + 6);
    if ( !*(_WORD *)(v17 + 2) )
    {
LABEL_9:
      v5 = -1073741701;
LABEL_18:
      if ( v5 < 0 )
        return sub_975F28();
      goto LABEL_19;
    }
    while ( *v9 != 3 || v9[1] != 1 || v9[2] != 1033 || v9[3] != 1 )
    {
      ++v8;
      v9 += 6;
      if ( v8 >= *(unsigned __int16 *)(v17 + 2) )
        goto LABEL_9;
    }
    v10 = (unsigned __int16)v9[4];
    if ( v10 + 2 < v10 )
    {
      v5 = -1073741675;
    }
    else
    {
      v11 = BgpFwAllocateMemory(v10 + 2);
      v12 = (_WORD *)v11;
      if ( v11 )
      {
        v5 = FioFwReadBytesAtOffset(
               a1,
               (unsigned __int16)v9[5] + *(unsigned __int16 *)(v7 + 4) + v6,
               (unsigned __int16)v9[4],
               v11);
        if ( v5 < 0 )
          return sub_975F28();
        v14 = 0;
        v15 = (unsigned __int16)v9[4] >> 1;
        v9[4] = v15;
        if ( v15 )
        {
          v16 = v12;
          do
          {
            ++v14;
            *v16 = __rev16((unsigned __int16)*v16);
            ++v16;
          }
          while ( v14 < (unsigned __int16)v9[4] );
        }
        v12[v14] = 0;
        *a3 = v12;
        goto LABEL_18;
      }
      v5 = -1073741801;
    }
  }
LABEL_19:
  if ( v7 )
    BgpFwFreeMemory(v7);
  return v5;
}
