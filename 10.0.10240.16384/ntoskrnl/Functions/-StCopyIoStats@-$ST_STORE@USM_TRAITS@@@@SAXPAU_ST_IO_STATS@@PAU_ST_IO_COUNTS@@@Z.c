// -StCopyIoStats@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_IO_STATS@@PAU_ST_IO_COUNTS@@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StCopyIoStats(unsigned int *a1, int a2)
{
  int v3; // r6
  unsigned int v4; // r3
  unsigned int v5; // r3
  int v6; // r2
  int v7; // r4

  v3 = (int)(a1 + 1);
  v4 = *(_DWORD *)(a2 + 4) + 1;
  if ( v4 > 0x40 )
    v4 = 64;
  *a1 = v4;
  v5 = *(_DWORD *)(a2 + 4);
  if ( v5 >= 0x40 )
  {
    v6 = ((_BYTE)v5 + 1) & 0x3F;
    v7 = 5 * (64 - v6);
    memmove((int)(a1 + 1), a2 + 20 * v6 + 16, 20 * (64 - v6));
    v3 += 4 * v7;
  }
  return memmove(v3, a2 + 16, 20 * (((unsigned __int8)*(_DWORD *)(a2 + 4) + 1) & 0x3F));
}
