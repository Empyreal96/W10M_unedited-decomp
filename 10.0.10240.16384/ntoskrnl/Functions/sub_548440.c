// sub_548440 
 
void __fastcall sub_548440(_DWORD *a1, int a2)
{
  int *v2; // r4
  int v3; // r5
  unsigned int *v4; // r3
  unsigned int v5; // r2
  int *v6; // r6
  unsigned int v7; // r1
  int v8; // r2
  int v9; // t1
  _DWORD *v10; // r2
  _DWORD *v11; // r1
  unsigned int v12; // r2
  _DWORD *i; // r6
  int v14; // r7
  int v15; // r3
  unsigned int *v16; // r3
  unsigned int v17; // r2
  int *v18; // r6
  unsigned int v19; // r1
  int v20; // r2
  int v21; // t1
  _DWORD *v22; // r2
  _DWORD *v23; // r1
  unsigned int v24; // r2
  _DWORD *j; // r6
  int v26; // r7
  int v27; // r3
  int v28; // r3
  _DWORD *v29; // r2

  if ( a2 )
  {
    if ( a2 != 2 )
    {
      if ( a2 == 4 )
      {
        a1[16] = a1[15];
        a1[15] = *(v2 - 2);
        JUMPOUT(0x4C7C84);
      }
      JUMPOUT(0x4C7C86);
    }
    if ( a1[16] <= (unsigned int)MmHighestUserAddress && ((unsigned __int8)v2 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v4 = *(unsigned int **)(v3 + 4);
    if ( !v4 || (v5 = a1[14], v5 >= *v4) && v5 <= **(_DWORD **)(v3 + 8) - 416 )
    {
      v6 = v2 + 1;
      v7 = 0;
      while ( 1 )
      {
        v8 = *(_DWORD *)(v3 + 12);
        if ( v8 && v7 - 4 <= 7 )
          *(_DWORD *)(v8 + 4 * v7 - 16) = v6;
        v9 = *v6++;
        v10 = &a1[v7++];
        v10[1] = v9;
        if ( v7 >= 0xD )
        {
          v11 = v2 + 20;
          v12 = 0;
          for ( i = a1; ; i += 2 )
          {
            v14 = *(_DWORD *)(v3 + 12);
            if ( v14 && v12 - 8 <= 7 )
              *(_DWORD *)(v14 + 4 * v12 + 4) = v11;
            ++v12;
            i[20] = *v11;
            v15 = v11[1];
            v11 += 2;
            i[21] = v15;
            if ( v12 >= 0x20 )
            {
              a1[14] = v2[14];
              a1[15] = v2[15];
              a1[16] = v2[16];
              a1[17] = v2[17];
              a1[18] = v2[18];
              *a1 &= 0xDFFFFFFF;
              JUMPOUT(0x4C7C82);
            }
          }
        }
      }
    }
  }
  else
  {
    if ( a1[16] <= (unsigned int)MmHighestUserAddress && ((unsigned __int8)v2 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v16 = *(unsigned int **)(v3 + 4);
    if ( !v16 || (v17 = a1[14], v17 >= *v16) && v17 <= **(_DWORD **)(v3 + 8) - 200 )
    {
      v18 = v2 + 40;
      v19 = 0;
      while ( 1 )
      {
        v20 = *(_DWORD *)(v3 + 12);
        if ( v20 && v19 - 4 <= 7 )
          *(_DWORD *)(v20 + 4 * v19 - 16) = v18;
        v21 = *v18++;
        v22 = &a1[v19++];
        v22[1] = v21;
        if ( v19 >= 4 )
        {
          v23 = v2 + 24;
          v24 = 0;
          for ( j = a1; ; j += 2 )
          {
            v26 = *(_DWORD *)(v3 + 12);
            if ( v26 && v24 - 8 <= 7 )
              *(_DWORD *)(v26 + 4 * v24 + 4) = v23;
            ++v24;
            j[20] = *v23;
            v27 = v23[1];
            v23 += 2;
            j[21] = v27;
            if ( v24 >= 8 )
            {
              v28 = *(_DWORD *)(v3 + 12);
              v29 = v2 + 47;
              if ( v28 )
                *(_DWORD *)(v28 + 28) = v29;
              a1[12] = *v29;
              a1[13] = v2[44];
              a1[14] = v2[45];
              a1[15] = v2[46];
              a1[16] = v2[48];
              a1[17] = v2[49];
              a1[18] = v2[23];
              JUMPOUT(0x4C7C7C);
            }
          }
        }
      }
    }
  }
  JUMPOUT(0x4C7CBA);
}
