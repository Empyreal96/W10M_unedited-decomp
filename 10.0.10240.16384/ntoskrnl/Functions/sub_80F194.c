// sub_80F194 
 
void __fastcall sub_80F194(int a1, int a2)
{
  int i; // r2
  int v3; // r4

  for ( i = 0; ; i += 24 )
  {
    v3 = i + *(_DWORD *)(a1 + 44);
    if ( *(_DWORD *)(v3 + 16) )
      *(_DWORD *)(v3 + 20) += a1;
    if ( (unsigned int)++a2 >= *(_DWORD *)(a1 + 20) )
      JUMPOUT(0x799476);
  }
}
