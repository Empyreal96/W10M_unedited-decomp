// sub_54B61C 
 
void __fastcall sub_54B61C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
  _DWORD *v15; // r5

  *v15 = 0;
  v15[1] = 0;
  v15[2] = 0;
  v15[3] = 0;
  if ( *(_DWORD *)(a15 + 16) > 2u )
    RtlGUIDFromString(*(_DWORD *)(a15 + 20) + 16, v15);
  JUMPOUT(0x4D3922);
}
