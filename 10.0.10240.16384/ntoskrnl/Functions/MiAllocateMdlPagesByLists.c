// MiAllocateMdlPagesByLists 
 
int __fastcall MiAllocateMdlPagesByLists(int a1, int a2, unsigned int a3, int a4, char a5)
{
  int v6; // r6
  unsigned int v7; // r7
  int v8; // r10
  int v9; // r0
  int v10; // r9
  int v11; // r4
  int v12; // r3
  int v13; // r5
  int v14; // r4
  unsigned int v15; // r3
  int v16; // r6
  int v18; // r0
  int v19; // r2
  int v20; // r1
  int v21; // r4
  int *v22; // [sp+0h] [bp-38h]
  int v25; // [sp+Ch] [bp-2Ch]
  int v26; // [sp+10h] [bp-28h] BYREF
  unsigned __int16 v27; // [sp+14h] [bp-24h]
  unsigned __int16 v28; // [sp+16h] [bp-22h]

  v25 = a2;
  v6 = __mrc(15, 0, 13, 0, 3);
  v7 = 0;
  v8 = 0;
  v9 = MI_INITIALIZE_COLOR_BASE(0, a4 + 1, &v26);
  v10 = 1;
  v11 = (unsigned __int16)(*(_WORD *)v26 + 1);
  v12 = v27;
  *(_WORD *)v26 = v11;
  v13 = 8;
  v14 = v11 & v12 | v28;
  v15 = *(_DWORD *)(a2 + 20);
  v26 = (int)*(&KiProcessorBlock + *(_DWORD *)((v6 & 0xFFFFFFC0) + 0x16C));
  v22 = (int *)(a2 + 4 * ((v15 >> 12) + 7));
  v16 = ~v9;
  do
  {
    if ( *(_DWORD *)(a1 + 3712) < 0x80u )
      return sub_511964();
    if ( v10 == 1 )
    {
      v13 = 8;
      if ( (a5 & 1) == 0 )
        v13 = 10;
      v10 = 0;
    }
    v18 = MiGetPage(a1, v14, v13);
    if ( v18 == -1 )
      break;
    v19 = MmPfnDatabase + 24 * v18;
    v20 = *(_DWORD *)(v19 + 8);
    if ( v20 )
      ++v8;
    if ( v16 == -1 )
      v16 = *(_DWORD *)(v19 + 20) >> 28;
    if ( *(_DWORD *)(v19 + 20) >> 28 == v16 )
    {
      if ( v20 )
      {
        if ( (a5 & 1) == 0 )
          v13 &= 0xFFFFFFFD;
      }
      else if ( (a5 & 1) != 0 )
      {
        v13 |= 2u;
      }
    }
    else
    {
      v10 = 1;
    }
    v16 = *(_DWORD *)(v19 + 20) >> 28;
    ++v7;
    *v22++ = v18;
    v21 = (*(_DWORD *)(v19 + 20) >> 28 << byte_6337F5) | dword_633814 & v18;
    v14 = (v21 + 1) & dword_6337E0 | v21 & ~dword_6337E0;
  }
  while ( v7 < a3 );
  if ( v7 )
    *(_DWORD *)(v26 + 2724) = v14;
  *(_DWORD *)(v25 + 20) += v7 << 12;
  if ( v8 )
    *(_DWORD *)(v25 + 12) = 1;
  return v7;
}
