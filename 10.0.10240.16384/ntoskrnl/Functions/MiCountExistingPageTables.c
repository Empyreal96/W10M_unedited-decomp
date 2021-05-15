// MiCountExistingPageTables 
 
int __fastcall MiCountExistingPageTables(_DWORD *a1, unsigned int a2, unsigned int *a3, int a4, int a5)
{
  unsigned int *v5; // r5
  unsigned int v6; // r4
  int v7; // r7
  unsigned int v10; // r6
  unsigned int v11; // r2
  int *v12; // r0
  unsigned int v14; // r3
  unsigned int v15; // r2

  v5 = &a3[2 * a4];
  v6 = (unsigned int)a1;
  v7 = 0;
  v10 = a2;
  if ( (unsigned int)a1 < *v5 )
    v6 = *v5;
  if ( a2 > v5[1] )
    v10 = v5[1];
  for ( ; v6 <= v10; v6 += 4 )
  {
    v11 = *(_DWORD *)v6;
    if ( (*(_DWORD *)v6 & 2) != 0 )
    {
      v12 = &MiState[a4];
      if ( v11 >> 12 != v12[1957] && v11 >> 12 != v12[1955] && ((v11 & 0x80) != 0 || (v11 & 0x200) == 0) )
        ++v7;
      if ( a4 != a5 && a4 )
      {
        if ( a4 == 1 && (v11 & 0x400) != 0 )
        {
          v14 = v6 << 10;
          v15 = (v6 << 10) + 4092;
          if ( v6 << 10 < *a3 )
            v14 = *a3;
          if ( v15 > a3[1] )
            v15 = a3[1];
          v7 += ((int)(v15 - v14) >> 2) + 1;
        }
        else
        {
          v7 += MiCountExistingPageTables(v6 << 10, (v6 << 10) + 4092, a3, a4 - 1, a5);
        }
      }
    }
  }
  return v7;
}
