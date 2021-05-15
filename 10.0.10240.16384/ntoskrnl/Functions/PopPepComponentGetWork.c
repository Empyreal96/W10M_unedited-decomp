// PopPepComponentGetWork 
 
int __fastcall PopPepComponentGetWork(int a1, int a2, int a3)
{
  int v4; // r4
  int v7; // r8
  int v9; // r1
  int **v10; // r2
  int *v11; // t1
  int v12; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r2
  int v17; // r4
  int v18; // r0
  int v19; // r0

  v4 = 0;
  if ( !a3 )
    return v4;
  v7 = *(_DWORD *)(a1 + 72);
  if ( v7 )
  {
    v19 = PopPepGetReadyActivityType(a1 + 48, 0, 0);
    if ( v19 != 6 )
      return PopPepStartActivity(a1, 0, a1 + 48, v19, (unsigned int *)(a1 + 72), a3);
  }
  if ( a2 && *(_DWORD *)(a2 + 72) )
  {
    v9 = 1;
    v10 = (int **)(a2 + 52);
    while ( 1 )
    {
      v11 = *v10++;
      v12 = *v11;
      if ( (*v11 & 2) != 0 || (v12 & 8) != 0 )
        break;
      if ( ++v9 > 3 )
      {
        v9 = 6;
        return PopPepStartActivity(a1, a2, a2 + 48, v9, (unsigned int *)(a2 + 72), a3);
      }
    }
    return PopPepStartActivity(a1, a2, a2 + 48, v9, (unsigned int *)(a2 + 72), a3);
  }
  if ( *(_BYTE *)(a1 + 77) == 1 )
  {
    v14 = *(_DWORD *)(a1 + 120);
    v15 = 0;
    if ( v14 )
    {
      v16 = a1;
      while ( !*(_DWORD *)(v16 + 200) )
      {
        ++v15;
        v16 += 168;
        if ( v15 >= v14 )
          goto LABEL_6;
      }
      v17 = a1 + 168 * v15;
      v18 = PopPepGetReadyActivityType(v17 + 176, 1, 3);
      return PopPepStartActivity(a1, v17 + 128, v17 + 176, v18, (unsigned int *)(v17 + 200), a3);
    }
  }
LABEL_6:
  if ( v7 )
    return sub_540318();
  return v4;
}
