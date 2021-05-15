// sub_80696C 
 
void __fastcall sub_80696C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  unsigned int v10; // r0
  unsigned int v11; // r0
  unsigned int v12; // r0
  unsigned int v13; // r0
  _DWORD *v14; // r4
  int **v15; // r5
  int *v16; // r6
  __int64 v17; // r2

  while ( *v15 != (int *)v15 )
  {
    v16 = *v15;
    v17 = *(_QWORD *)*v15;
    if ( (int **)HIDWORD(v17) != v15 || *(int **)(v17 + 4) != v16 )
      __fastfail(3u);
    *v15 = (int *)v17;
    *(_DWORD *)(v17 + 4) = v15;
    PfpOpenHandleClose(v16 + 9, (int)(v14 + 1));
    PfpOpenHandleClose(v16 + 4, (int)(v14 + 1));
  }
  v10 = v14[21];
  if ( v10 )
    ExFreePoolWithTag(v10);
  v11 = v14[29];
  if ( v11 )
    ExFreePoolWithTag(v11);
  v12 = v14[30];
  if ( v12 )
    ExFreePoolWithTag(v12);
  PfpPrefetchSharedCleanup(v14 + 1);
  v13 = v14[34];
  if ( v13 )
    ExFreePoolWithTag(v13);
  __asm { POP.W           {R3-R6,R11,PC} }
}
