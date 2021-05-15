// sub_7E0480 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_7E0480(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, _DWORD *a14)
{
  int v14; // r2
  int v15; // r5
  int v16; // r8
  int v17; // r9
  int v18; // r10
  int v19; // r4
  int v20; // r2
  int v21; // r4
  int v22; // r1
  _WORD *v23; // r5
  _WORD *v24; // r5
  int v25; // [sp-1Ch] [bp-1Ch] BYREF
  _DWORD v26[3]; // [sp-18h] [bp-18h] BYREF
  int v27; // [sp-Ch] [bp-Ch] BYREF
  int v28; // [sp-8h] [bp-8h]

  v19 = 0;
  *a14 = 0;
  v27 = 0;
  v28 = 0;
  while ( IopEnumerateRelations(v17, &v27, &v25, v26, 0) )
  {
    if ( v25 )
      v14 = *(_DWORD *)(*(_DWORD *)(v25 + 176) + 20);
    else
      v14 = 0;
    if ( v14 && (!v18 || (*(_DWORD *)(v14 + 456) & 2) == 0) && *(_DWORD *)(v14 + 24) && (!v16 || v26[0]) )
      v19 += *(unsigned __int16 *)(v14 + 20) + 2;
  }
  v24 = (_WORD *)PnpAllocateCriticalMemory(v15, 1, v19 + 2, 1265659472);
  *a14 = v24;
  if ( v24 )
  {
    v27 = 2;
    v28 = 0;
    while ( IopEnumerateRelations(v17, &v27, &v25, v26, 0) )
    {
      if ( v25 )
        v20 = *(_DWORD *)(*(_DWORD *)(v25 + 176) + 20);
      else
        v20 = 0;
      if ( v20 && (!v18 || (*(_DWORD *)(v20 + 456) & 2) == 0) && *(_DWORD *)(v20 + 24) && (!v16 || v26[0]) )
      {
        v21 = *(_DWORD *)(*(_DWORD *)(v25 + 176) + 20);
        if ( v21 )
        {
          v22 = *(_DWORD *)(v21 + 24);
          if ( v22 )
          {
            memmove((int)v24, v22, *(unsigned __int16 *)(v21 + 20));
            v23 = &v24[*(unsigned __int16 *)(v21 + 20) >> 1];
            *v23 = 0;
            v24 = v23 + 1;
          }
        }
      }
    }
    *v24 = 0;
  }
  __asm { POP.W           {R4-R11,PC} }
}
