// MiCommitPageTablesForVad 
 
int __fastcall MiCommitPageTablesForVad(int a1, unsigned int a2, unsigned int a3)
{
  int v3; // r4
  int v6; // r7
  unsigned int v7; // r10
  int i; // r9
  unsigned int v9; // r6
  unsigned int v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r5
  int result; // r0
  int v14; // r3
  int v15; // [sp+0h] [bp-30h]
  int v16; // [sp+4h] [bp-2Ch]
  unsigned int v18; // [sp+Ch] [bp-24h]

  v3 = a1;
  if ( *(_DWORD *)(a1 + 8) == -2 && MiVadPureReserve(a1) )
  {
    if ( (*(_DWORD *)(v3 + 32) & 0x7FFFFFFF) != 0 )
      result = sub_800EB4();
    else
      result = 0;
    return result;
  }
  v6 = 0;
  v15 = 0;
  if ( (*(_DWORD *)(v3 + 28) & 0x8000) != 0 )
  {
    if ( (*(_DWORD *)(v3 + 28) & 7) != 5 )
      goto LABEL_4;
  }
  else if ( (*(_BYTE *)(v3 + 43) & 1) == 0 )
  {
    goto LABEL_4;
  }
  v6 = 1;
  v15 = 1;
LABEL_4:
  v16 = 0;
  v7 = a2 >> 22;
  v18 = a2 >> 22;
  for ( i = 0; ; i = 1 )
  {
    v9 = 0;
    v10 = 0;
    v11 = v7;
    if ( v7 <= a3 >> 22 )
    {
      do
      {
        if ( ((*(char *)((v11 >> 3) + MEMORY[0xC04021BC]) >> (v11 & 7)) & 1) == 0 )
        {
          ++v10;
          if ( i == 1 )
            *(_BYTE *)((v11 >> 3) + MEMORY[0xC04021BC]) |= 1 << (v11 & 7);
          else
            v16 = 1;
        }
        ++v11;
      }
      while ( v11 <= a3 >> 22 );
      v3 = a1;
      v7 = v18;
      v6 = v15;
    }
    if ( !v6 )
      v9 = v10;
    if ( i )
      break;
    v12 = v9;
    if ( !v6 && !MiVadPureReserve(v3) )
    {
      v14 = *(_DWORD *)(v3 + 32) & 0x7FFFFFFF;
      if ( v14 != 524286 )
        v12 = v14 + v9;
    }
    if ( v12 )
    {
      result = MiChargeFullProcessCommitment(*(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v12);
      if ( result < 0 )
        return result;
    }
    if ( v16 != 1 )
      break;
    MEMORY[0xC0402100] += v9;
  }
  return 0;
}
