// MiScrubNonPagedPool 
 
int __fastcall MiScrubNonPagedPool(int result, int a2, int a3)
{
  unsigned int i; // r5
  unsigned int v6; // r4
  int v7; // r9
  int v8; // r8
  int v9; // r10
  int v10; // r2
  int v11; // [sp+0h] [bp-48h]
  int v12; // [sp+4h] [bp-44h]
  __int64 v13; // [sp+8h] [bp-40h] BYREF
  int v14[5]; // [sp+10h] [bp-38h] BYREF
  int v15; // [sp+24h] [bp-24h]
  char v16; // [sp+28h] [bp-20h]

  v14[0] = 3;
  v15 = 0;
  v16 = 1;
  v11 = result;
  for ( i = -1; !*(_DWORD *)(a3 + 4); i = v6 )
  {
    result = MiScanNonPagedPoolVa(1, a2, 0, (int)v14);
    v6 = result;
    if ( result == -1 )
      break;
    v15 = result + 1;
    v7 = dword_6337E8 + 176 * a2;
    v8 = *(_DWORD *)(v7 + 136);
    MmGetPhysicalAddress((int)&v13, v8 + (result << 12), 176, dword_6337E8);
    v9 = 3 * (v13 >> 12);
    v12 = MmPfnDatabase;
    result = MiScrubPage(v11, 0, MmPfnDatabase + 24 * (v13 >> 12)) < 0 ? MiPushBadPool(v7, v12 + 8 * v9, v10, v12) : MiReturnNonPagedPoolVa(v8 + (v6 << 12), 1u);
    if ( v6 <= i && i != -1 )
      break;
  }
  return result;
}
