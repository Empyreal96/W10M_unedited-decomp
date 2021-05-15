// MiFreeInitializationCode 
 
int __fastcall MiFreeInitializationCode(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r8
  int v5; // r5
  int v7; // r0
  int v9; // r0
  int v10; // r4
  int v11; // r5
  int v12; // r0
  unsigned int v13; // r4
  int v14; // [sp+8h] [bp-30h] BYREF
  int v15; // [sp+Ch] [bp-2Ch]
  int v16; // [sp+10h] [bp-28h]
  int v17; // [sp+14h] [bp-24h]

  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v3 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v5 = (int)(((a3 >> 10) & 0x3FFFFC) - v3 - 1073741820) >> 2;
  v7 = MiClearNonPagedBitMapBits(
         (int)(a1 + 23),
         dword_634F00,
         (int)(((a2 >> 10) & 0x3FFFFC) - ((a1[6] >> 10) & 0x3FFFFC)) >> 2,
         v5);
  if ( (*(_DWORD *)(((a2 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
    return sub_7CDEC4(v7);
  v9 = a1[15];
  if ( v9 )
    v10 = MiSectionControlArea(v9);
  else
    v10 = 0;
  MiDeleteSystemPagableVm((int *)dword_634F00, v10, v3, v5, 1, &v14);
  v11 = v17;
  if ( v17 )
  {
    v12 = v17;
    a1[29] -= v17;
    a1[30] -= v11;
    MiReturnResidentAvailable(v12);
    do
      v13 = __ldrex(&dword_634A2C[49]);
    while ( __strex(v13 + v11, &dword_634A2C[49]) );
    v11 -= v15;
    MiReturnCommit((int)MiSystemPartition, v11);
  }
  return v11;
}
