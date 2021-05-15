// DrvDbSetDriverFileMappedProperty 
 
int __fastcall DrvDbSetDriverFileMappedProperty(int **a1, int a2, int a3, unsigned int a4, int (*a5)[5])
{
  int v6; // r9
  int (**v7)[5]; // r7
  int v9; // r5
  unsigned int v10; // r0
  int (*v11)[5]; // t1
  int v12; // r0
  int v13; // r4
  int v15; // [sp+10h] [bp-28h] BYREF
  int v16; // [sp+14h] [bp-24h]
  int **v17; // [sp+18h] [bp-20h]

  v6 = *(_DWORD *)(a4 + 16);
  v7 = &off_41E234;
  v16 = a2;
  v17 = a1;
  v15 = 0;
  v9 = 0;
  while ( 1 )
  {
    v11 = *v7;
    v7 += 6;
    v10 = (unsigned int)v11;
    if ( (*v11)[4] == v6 )
    {
      v12 = memcmp(v10, a4, 16);
      if ( !v12 )
        break;
    }
    if ( (unsigned int)++v9 >= 2 )
      return -1073741802;
  }
  if ( !(&off_41E234 + 6 * v9) )
    return -1073741802;
  if ( a5 != *(&off_41E234 + 6 * v9 + 1) && a5 )
    return -1073741811;
  if ( !a3 )
  {
    v12 = DrvDbOpenObjectRegKey(v17, 0, 4, v16, 2, 0, (int)&v15, 0);
    v13 = v12;
    if ( v12 < 0 )
      goto LABEL_15;
    a3 = v15;
  }
  v13 = DrvDbSetRegValueMappedProperty(v12, a3);
LABEL_15:
  if ( v15 )
    ZwClose();
  return v13;
}
