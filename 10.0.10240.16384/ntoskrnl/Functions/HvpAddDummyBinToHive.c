// HvpAddDummyBinToHive 
 
int __fastcall HvpAddDummyBinToHive(int a1, int a2, int a3, int *a4)
{
  int v8; // r4
  unsigned int v9; // r6
  int v10; // r4
  int v11; // r3
  int v12; // r2
  unsigned int v14; // [sp+10h] [bp-28h] BYREF
  unsigned int v15[9]; // [sp+14h] [bp-24h] BYREF

  v14 = 0;
  v15[0] = 0;
  v8 = HvpAllocateBin(a1, 4096, 0, a3, 808668483, (int *)&v14, (int *)v15);
  if ( v8 < 0 )
  {
    v11 = v14;
    v12 = v15[0];
  }
  else
  {
    v9 = v15[0];
    if ( v15[0] )
      v10 = v15[0];
    else
      v10 = v14;
    if ( a2 )
      memmove(v10, a2, 0x1000u);
    else
      memset((_BYTE *)v10, 0, 4096);
    *(_DWORD *)(v10 + 4) = a3;
    *(_DWORD *)(v10 + 8) = 4096;
    if ( CmpSelfHeal || (CmpBootType & 6) != 0 )
    {
      *(_DWORD *)v10 = 1852400232;
      *(_DWORD *)(v10 + 32) = 4064;
      *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
    }
    else
    {
      *(_DWORD *)v10 = 0;
      *(_DWORD *)(v10 + 32) = -4064;
    }
    HvpPointMapEntriesToBuffer(a1, v14, v9, 0x1000u, a3, 0);
    *a4 = v10;
    v11 = 0;
    v12 = 0;
    v8 = 0;
  }
  if ( v11 || v12 )
    HvpFreeBin(a1, 4096, 0, v11, v12);
  return v8;
}
