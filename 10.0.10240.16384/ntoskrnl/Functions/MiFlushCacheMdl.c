// MiFlushCacheMdl 
 
int __fastcall MiFlushCacheMdl(int a1, int a2)
{
  unsigned int v3; // r5
  int result; // r0
  int v5; // r6
  int *v6; // r9
  int v7; // t1
  int v8; // r8
  int v9; // r1
  int v10; // [sp+0h] [bp-B8h] BYREF
  char v11; // [sp+4h] [bp-B4h]
  char v12; // [sp+5h] [bp-B3h]
  int v13; // [sp+8h] [bp-B0h]
  int v14; // [sp+Ch] [bp-ACh]
  int v15; // [sp+10h] [bp-A8h]
  int i; // [sp+14h] [bp-A4h]

  v3 = *(_DWORD *)(a1 + 20) >> 12;
  if ( v3 < dword_633828 )
  {
    v14 = 0;
    v15 = 0;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = 33;
    if ( a2 == 2 )
      v5 = 2;
    else
      v5 = 0;
    v6 = (int *)(a1 + 28);
    for ( i = 0; v3; --v3 )
    {
      v7 = *v6++;
      v8 = MiMapPageInHyperSpaceWorker(v7, 0, v5 | 0xC0000000);
      KeInvalidatePage(v8, v9, v7 << 12, (unsigned __int64)(unsigned int)v7 >> 20);
      MiUnmapPageInHyperSpaceWorker(v8, 17, 0x80000000);
      if ( a2 == 3 )
        MiInsertTbFlushEntry((int)&v10, v8, 1, 0);
    }
    if ( a2 == 3 )
      MiFlushTbList((unsigned int)&v10, a2);
    result = 0;
  }
  else
  {
    KeInvalidateAllCaches(a1, a2, (int)MiState, ++dword_633820);
    result = 1;
  }
  return result;
}
