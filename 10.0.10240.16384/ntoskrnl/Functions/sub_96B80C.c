// sub_96B80C 
 
void __fastcall sub_96B80C(int a1, int a2, unsigned int *a3, int a4, int a5, int a6, char a7)
{
  unsigned int v7; // r5
  __int16 *v8; // r8
  unsigned int v9; // r7
  unsigned int *v10; // r0
  unsigned int v11; // r6
  unsigned int v12; // r4
  char *v13; // r9
  int v14; // r10
  unsigned int v15; // r2
  char *v16; // r1
  int v17; // r3
  char *v18; // r3
  int v19; // lr
  int v20; // r0
  char *v21; // r1
  int v22; // t1
  unsigned int *v23; // [sp+0h] [bp+0h]

  v9 = *a3;
  v10 = &a3[*a3 + 1];
  v23 = v10;
  v11 = *a3;
  if ( *a3 > v7 )
    v11 = v7;
  if ( v11 > 0x10 )
    v11 = 16;
  v12 = 0;
  if ( v11 )
  {
    v13 = &a7;
    v14 = 0;
    do
    {
      v15 = 0;
      if ( v9 )
      {
        v16 = &a7;
        do
        {
          if ( v15 >= 0x10 )
            break;
          v17 = *((unsigned __int16 *)v10 + v14 + v15);
          if ( !*((_WORD *)v10 + v14 + v15) )
            v17 = 1;
          *(_DWORD *)v16 = v15++;
          *((_DWORD *)v16 + 2) = v17;
          *((_DWORD *)v16 + 3) = 0;
          v16 += 16;
        }
        while ( v15 < v9 );
      }
      if ( v15 < v7 )
      {
        v18 = &a7 + 16 * v15;
        do
        {
          if ( v15 >= 0x10 )
            break;
          *(_DWORD *)v18 = v15++;
          *((_DWORD *)v18 + 2) = -1;
          *((_DWORD *)v18 + 3) = -1;
          v18 += 16;
        }
        while ( v15 < v7 );
      }
      *((_DWORD *)v13 + 2) = 0;
      *((_DWORD *)v13 + 3) = 0;
      qsort((unsigned int)&a7, v7, 0x10u, (int (__fastcall *)(unsigned int, _BYTE *))MiNodeCostSort);
      v7 = (unsigned __int16)*v8;
      if ( *v8 )
      {
        v19 = (unsigned __int16)*v8;
        v20 = 2 * v7 * v12;
        v21 = &a7;
        do
        {
          v22 = *(_DWORD *)v21;
          v21 += 16;
          *(_WORD *)(v20 + dword_6337E4) = v22;
          v20 += 2;
          --v19;
        }
        while ( v19 );
        v8 = &KeNumberNodes;
      }
      ++v12;
      v10 = v23;
      v14 += v9;
      v13 += 16;
    }
    while ( v12 < v11 );
  }
  JUMPOUT(0x957454);
}
