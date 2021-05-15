// MiFindPageFileWriteCluster 
 
int __fastcall MiFindPageFileWriteCluster(int a1, unsigned int *a2, int *a3, int a4)
{
  int v7; // r0
  int result; // r0
  unsigned int v9; // r3
  unsigned int v10[16]; // [sp+8h] [bp-40h] BYREF

  v10[0] = v10[0] & 0x1FFB | (4 * (*(_WORD *)(a1 + 96) & 1 | (*a2 << 11)));
  if ( a4 )
    v7 = 2;
  else
    v7 = 0;
  result = MiFindFreePageFileSpace(*(_DWORD *)(a1 + 128), v10, *a3, 0, v7);
  if ( !result )
    return sub_548B30();
  v9 = v10[0] >> 13;
  *a3 = result;
  *a2 = v9;
  return result;
}
