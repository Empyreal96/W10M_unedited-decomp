// sub_7D0DC0 
 
void __fastcall sub_7D0DC0(unsigned int a1, __int64 a2, int a3, int a4, int a5, int a6)
{
  unsigned int *v7; // r4

  if ( *(_DWORD *)(a2 + 4) != a1 )
    __fastfail(3u);
  while ( 1 )
  {
    *v7 = a2;
    *(_DWORD *)(a2 + 4) = v7;
    if ( (unsigned int *)a1 == v7 )
      break;
    ExFreePoolWithTag(a1);
    a1 = *v7;
    a2 = *(_QWORD *)*v7;
    if ( (unsigned int *)HIDWORD(a2) != v7 || *(_DWORD *)(a2 + 4) != a1 )
      __fastfail(3u);
  }
  v7[2] = 0;
  v7[3] = 0;
  memset((_BYTE *)v7 + 24, 0, 48);
  __asm { POP.W           {R3,R4,R11,PC} }
}
