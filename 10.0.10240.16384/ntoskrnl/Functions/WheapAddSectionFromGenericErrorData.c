// WheapAddSectionFromGenericErrorData 
 
int __fastcall WheapAddSectionFromGenericErrorData(int a1, int a2, int a3, int a4, unsigned int a5, char a6)
{
  unsigned int v6; // r4
  unsigned int v8; // r0
  int v9; // r5
  int *v12; // r1
  int v13; // r6
  int *v14; // r1
  int v15; // r2
  int v16; // t1
  unsigned int v17; // r4
  int *v18; // r2
  int v19; // r8

  v6 = *(_DWORD *)(a1 + 24);
  v8 = *(unsigned __int16 *)(a2 + 10);
  v9 = a4;
  if ( v8 >= v6 )
    return -1073741789;
  v12 = (int *)(a2 + 128);
  if ( v8 )
  {
    v14 = &v12[18 * v8 - 18];
    v15 = v14[1];
    v16 = *v14;
    v12 = v14 + 18;
    v13 = v15 + v16;
  }
  else
  {
    v13 = 72 * v6 + 128;
  }
  if ( a6 )
  {
    v17 = *(_DWORD *)(a4 + 24);
    v18 = (int *)a4;
    v19 = 64;
  }
  else
  {
    v18 = &GENERIC_SECTION_GUID;
    v17 = a5;
    v19 = 0;
  }
  if ( a3 - v13 < v17 )
    return -1073741789;
  *((_WORD *)v12 + 4) = 513;
  *v12 = v13;
  v12[1] = v17;
  *((_BYTE *)v12 + 10) = *(_BYTE *)(a4 + 22);
  v12[3] = *(unsigned __int8 *)(a4 + 23);
  v12[4] = *v18;
  v12[5] = v18[1];
  v12[6] = v18[2];
  v12[7] = v18[3];
  v12[8] = *(_DWORD *)(a4 + 28);
  v12[9] = *(_DWORD *)(a4 + 32);
  v12[10] = *(_DWORD *)(a4 + 36);
  v12[11] = *(_DWORD *)(a4 + 40);
  v12[12] = *(_DWORD *)(a4 + 16);
  memmove((int)(v12 + 13), a4 + 44, 0x14u);
  memmove(v13 + a2, v19 + v9, v17);
  ++*(_WORD *)(a2 + 10);
  return 0;
}
