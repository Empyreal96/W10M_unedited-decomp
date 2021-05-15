// sub_806C08 
 
void __fastcall sub_806C08(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  _DWORD *v10; // r4
  _DWORD **v11; // r5
  int v12; // r6
  _DWORD *v13; // r1
  __int64 v14; // r2

  while ( *v11 != v11 )
  {
    LODWORD(v14) = *v11;
    HIDWORD(v14) = (*v11)[1];
    v13 = (_DWORD *)**v11;
    if ( v14 != __PAIR64__((unsigned int)v11, v13[1]) )
      __fastfail(3u);
    *v11 = v13;
    v13[1] = v11;
    *(_DWORD *)v14 = v12;
    *(_DWORD *)(v14 + 4) = v12;
    FsRtlFreeExtraCreateParameter(v14 + 44);
  }
  if ( (v10[1] & 4) != 0 )
    ExFreeToPagedLookasideList((int)&FsRtlEcpListLookaside, v10);
  else
    ExFreePoolWithTag((unsigned int)v10);
  __asm { POP.W           {R3-R6,R11,PC} }
}
