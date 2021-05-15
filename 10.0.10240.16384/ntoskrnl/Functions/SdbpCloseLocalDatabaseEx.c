// SdbpCloseLocalDatabaseEx 
 
int __fastcall SdbpCloseLocalDatabaseEx(int a1, int a2, unsigned int a3, int a4)
{
  int v6; // r7
  int v7; // r6
  unsigned int *v8; // r0
  int varg_r0; // [sp+18h] [bp+8h]
  unsigned int varg_r2; // [sp+20h] [bp+10h]

  varg_r0 = a1;
  varg_r2 = a3;
  if ( a3 >= 0x10 )
    return 0;
  v6 = 1 << a3;
  if ( (*(_DWORD *)(a1 + 16) & (1 << a3)) == 0 )
    return 0;
  v7 = a1 + 24 * a3;
  if ( (*(_DWORD *)(v7 + 40) & 2) != 0 )
  {
    v8 = *(unsigned int **)(v7 + 36);
    if ( v8 )
      SdbCloseDatabaseRead(v8);
  }
  memset((_BYTE *)(v7 + 20), 0, 24);
  *(_DWORD *)(a1 + 16) &= ~v6;
  if ( a3 == 1 )
    *(_DWORD *)(a1 + 8) = 0;
  return 1;
}
