// sub_8DFCEC 
 
void __fastcall sub_8DFCEC(int a1, int a2, __int64 a3, int a4, int a5, int a6, int a7)
{
  int *v7; // r4

  HIDWORD(a3) = *(_DWORD *)(a3 + 4);
  if ( HIDWORD(a3) != a1 )
    __fastfail(3u);
  while ( 1 )
  {
    *v7 = a3;
    *(_DWORD *)(a3 + 4) = v7;
    if ( (int *)a1 == v7 )
      break;
    RaspDestroyCachedBitmap(a1, a2, a3, SHIDWORD(a3));
    a1 = *v7;
    a3 = *(_QWORD *)*v7;
    if ( (int *)HIDWORD(a3) == v7 )
    {
      HIDWORD(a3) = *(_DWORD *)(a3 + 4);
      if ( HIDWORD(a3) == a1 )
        continue;
    }
    __fastfail(3u);
  }
  v7[8] = 0;
  __asm { POP.W           {R3,R4,R11,PC} }
}
