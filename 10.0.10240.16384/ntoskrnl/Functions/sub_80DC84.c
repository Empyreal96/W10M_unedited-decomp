// sub_80DC84 
 
void __fastcall sub_80DC84(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int *a13, _DWORD *a14)
{
  int v14; // r5
  int v15; // r8
  int v16; // r4
  int *v17; // r3
  int v18; // r7
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r0
  _DWORD *v23; // lr
  unsigned int v24; // r6
  int v25; // r5
  int v26; // r2
  int v27; // r3
  int v28; // r4
  int v29; // r0
  int v30; // r1
  int v31; // r2
  int v32; // r3

  v16 = 0;
  v17 = *(int **)(*(_DWORD *)(a1 + 40 * v14 + 24) + 12);
  v18 = *v17;
  v19 = *(_DWORD *)(*v17 + 16);
  if ( v19 )
  {
    v20 = *v17;
    do
    {
      v21 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v20 + 20) + 20) + 80);
      if ( v21 == v15 || v21 == 7 && v15 == 3 )
        ++v16;
      v20 += 4;
      --v19;
    }
    while ( v19 );
    if ( v16 )
    {
      v22 = ExAllocatePoolWithTag(1, 16 * v16, 538996816);
      v23 = (_DWORD *)v22;
      if ( v22 )
      {
        v24 = 0;
        *a14 = v16;
        *a13 = v22;
        if ( *(_DWORD *)(v18 + 16) )
        {
          v25 = v18;
          do
          {
            v26 = *(_DWORD *)(*(_DWORD *)(v25 + 20) + 20);
            v27 = *(unsigned __int8 *)(v26 + 80);
            if ( v27 == v15 || v27 == 7 && v15 == 3 )
            {
              v28 = v26 + 80;
              v29 = *(_DWORD *)(v26 + 80);
              v30 = *(_DWORD *)(v26 + 84);
              v31 = *(_DWORD *)(v26 + 88);
              v32 = *(_DWORD *)(v28 + 12);
              *v23 = v29;
              v23[1] = v30;
              v23[2] = v31;
              v23[3] = v32;
              v23 += 4;
            }
            ++v24;
            v25 += 4;
          }
          while ( v24 < *(_DWORD *)(v18 + 16) );
        }
      }
    }
  }
  JUMPOUT(0x79537C);
}
