// sub_7C80CC 
 
void __fastcall sub_7C80CC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  __int64 **v8; // r4
  int v9; // r5
  __int64 *v10; // r0
  __int64 v11; // r2
  _DWORD *v12; // r0

  while ( *v8 != (__int64 *)v8 )
  {
    v10 = *v8;
    v11 = **v8;
    if ( (__int64 **)HIDWORD(v11) != v8 || *(__int64 **)(v11 + 4) != v10 )
      __fastfail(3u);
    *v8 = (__int64 *)v11;
    *(_DWORD *)(v11 + 4) = v8;
    PiDqQueryActionQueueEntryFree((unsigned int)v10);
  }
  v12 = *(_DWORD **)(v9 + 96);
  *(_DWORD *)(v9 + 108) = 0;
  if ( v12 )
  {
    PiDqActionDataFree(v12);
    *(_DWORD *)(v9 + 96) = 0;
  }
  __asm { POP.W           {R4,R5,R11,PC} }
}
