// MiCreateFileOnlyPfns 
 
int __fastcall MiCreateFileOnlyPfns(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r0
  int v5; // r6
  unsigned int v6; // r5
  int *v7; // r3
  int v8; // r10
  int v9; // r8
  int *v10; // r9
  int v11; // r7
  int *v12; // r4
  int v13; // t1
  int *v16; // [sp+4h] [bp-24h]
  int v17; // [sp+8h] [bp-20h]

  v4 = a3;
  v5 = 0;
  v6 = 0;
  v7 = (int *)(a4 + 4);
  v16 = v7;
  v8 = 0;
  v17 = 0;
  v9 = -1;
  v10 = 0;
  do
  {
LABEL_2:
    v11 = 0;
    v12 = v7;
    if ( !v4 )
      break;
    while ( 1 )
    {
      if ( !v6 )
        goto LABEL_11;
      if ( v6 + v9 != *v12 )
        break;
      ++v6;
      ++v12;
LABEL_12:
      if ( ++v11 >= v4 )
        goto LABEL_15;
    }
    if ( v10 )
    {
      if ( v10 == v12 )
        break;
      MiRemovePhysicalMemory(v9, v6, 2);
      v4 = a3;
      goto LABEL_11;
    }
    v5 = MiAddFileOnlyPfns(v9, v6);
    v4 = a3;
    if ( v5 >= 0 )
    {
      v8 = 1;
LABEL_11:
      v13 = *v12++;
      v9 = v13;
      v6 = 1;
      goto LABEL_12;
    }
    v10 = v12;
    v7 = v16;
  }
  while ( &v12[-v6] != v16 );
LABEL_15:
  if ( v5 < 0 || v6 && (v5 = MiAddFileOnlyPfns(v9, v6), v5 < 0) )
  {
    if ( v8 == 1 && !v17 )
    {
      v4 = a3;
      v17 = 1;
      v7 = v16;
      goto LABEL_2;
    }
  }
  return v5;
}
