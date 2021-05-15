// MiIsAddressValid 
 
int __fastcall MiIsAddressValid(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r2
  int *v5; // r0
  int *v7; // t1
  int v8; // r3
  int v9; // r4
  int v10; // r5
  int v12; // r1
  int v13; // r2
  unsigned int v14; // r3
  int v15[2]; // [sp+0h] [bp-20h]
  int v16; // [sp+8h] [bp-18h] BYREF

  v16 = a4;
  v15[0] = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v15[1] = (((unsigned int)v15[0] >> 10) & 0x3FFFFC) - 0x40000000;
  v4 = 2;
  v5 = &v16;
  while ( 1 )
  {
    v7 = (int *)*--v5;
    --v4;
    v8 = *v7;
    if ( (*v7 & 2) == 0 )
      return 0;
    if ( v4 <= 1 && (v8 & 0x400) != 0 )
      break;
    if ( !v4 )
      goto LABEL_6;
  }
  if ( !v4 )
    return 0;
LABEL_6:
  v9 = 2;
  do
  {
    while ( 1 )
    {
      v10 = v15[--v9];
      if ( (*(_DWORD *)v10 & 0x10) == 0 )
      {
        if ( !a2 )
          return 0;
        MI_WRITE_VALID_PTE_VOLATILE((unsigned int *)v15[v9], 1);
        KeFlushSingleCurrentTb(v10 << 10, v12, v13, v14);
      }
      if ( v9 != 1 )
        break;
      if ( (*(_DWORD *)v10 & 0x400) != 0 )
        return 1;
    }
  }
  while ( v9 );
  return 1;
}
