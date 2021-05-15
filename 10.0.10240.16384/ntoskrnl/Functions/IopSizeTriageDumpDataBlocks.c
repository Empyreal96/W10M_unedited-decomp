// IopSizeTriageDumpDataBlocks 
 
unsigned int __fastcall IopSizeTriageDumpDataBlocks(_DWORD *a1, unsigned int a2, unsigned int *a3, unsigned int a4, unsigned int a5)
{
  unsigned int v6; // r6
  int *v7; // lr
  unsigned int v8; // r7
  int v9; // r4
  int v10; // t1
  unsigned int v11; // r3

  v6 = 0;
  a1[25] = 0;
  if ( a2 )
  {
    while ( 1 )
    {
      v7 = (int *)a3[2];
      v8 = 0;
      if ( *a3 )
        break;
LABEL_7:
      ++v6;
      a3 += 3;
      if ( v6 >= a2 )
        return a4;
    }
    while ( 1 )
    {
      v9 = v7[1];
      v10 = *v7;
      v7 += 2;
      v11 = ((v9 - v10 + 7) & 0xFFFFFFF8) + 16 + a4;
      if ( v11 >= a5 )
        break;
      if ( !v8 )
        a1[24] = a4;
      a4 = v11;
      ++v8;
      ++a1[25];
      if ( v8 >= *a3 )
        goto LABEL_7;
    }
    a1[17] |= 0x100u;
  }
  return a4;
}
