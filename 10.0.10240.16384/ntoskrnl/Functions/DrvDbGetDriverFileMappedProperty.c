// DrvDbGetDriverFileMappedProperty 
 
int __fastcall DrvDbGetDriverFileMappedProperty(int **a1, int a2, int a3, unsigned int a4, _DWORD *a5, int *a6, unsigned int a7, _DWORD *a8)
{
  int v10; // r9
  int v11; // r5
  int (**v12)[5]; // r7
  unsigned int v13; // r0
  int (*v14)[5]; // t1
  int v15; // r0
  int v16; // r4
  int (**v18)[5]; // r5
  int v19; // [sp+10h] [bp-28h] BYREF
  int v20; // [sp+14h] [bp-24h]
  int **v21; // [sp+18h] [bp-20h]

  v19 = 0;
  v20 = a2;
  *a5 = 0;
  v21 = a1;
  *a8 = 0;
  v10 = *(_DWORD *)(a4 + 16);
  v11 = 0;
  v12 = &off_41E234;
  while ( 1 )
  {
    v14 = *v12;
    v12 += 6;
    v13 = (unsigned int)v14;
    if ( (*v14)[4] == v10 )
    {
      v15 = memcmp(v13, a4, 16);
      if ( !v15 )
        break;
    }
    if ( (unsigned int)++v11 >= 2 )
      return -1073741802;
  }
  v18 = &off_41E234 + 6 * v11;
  if ( !v18 )
    return -1073741802;
  if ( !a3 )
  {
    v15 = DrvDbOpenObjectRegKey(v21, 0, 4, v20, 1, 0, (int)&v19, 0);
    v16 = v15;
    if ( v15 < 0 )
      goto LABEL_12;
    a3 = v19;
  }
  v16 = DrvDbGetRegValueMappedProperty(v15, a3, (int)v18, a5, a6, a7, a8);
LABEL_12:
  if ( v19 )
    ZwClose();
  return v16;
}
