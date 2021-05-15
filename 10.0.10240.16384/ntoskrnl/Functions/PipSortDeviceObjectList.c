// PipSortDeviceObjectList 
 
int __fastcall PipSortDeviceObjectList(unsigned int **a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r5
  unsigned int v6; // r4
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned int *v9; // r6
  unsigned int v10; // r7
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a4;
  v4 = *a1;
  v6 = **a1;
  if ( v6 )
  {
    v7 = v4 + 4;
    v8 = **a1;
    do
    {
      v7[3] &= 0xFFFFFFFD;
      v7 += 4;
      --v8;
    }
    while ( v8 );
  }
  v12[0] = 1;
  if ( v6 )
  {
    v9 = v4 + 4;
    v10 = v6;
    do
    {
      if ( (v9[3] & 4) != 0 )
        PipVisitDeviceObjectListEntry(v9, *a1, v12);
      v9 += 4;
      --v10;
    }
    while ( v10 );
  }
  qsort((unsigned int)(v4 + 4), v6, 0x10u, (int (__fastcall *)(unsigned int, _BYTE *))PipSortDevicesByOrdinal);
  return 0;
}
