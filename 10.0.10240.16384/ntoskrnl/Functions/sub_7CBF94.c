// sub_7CBF94 
 
void __fastcall sub_7CBF94(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  _DWORD *v7; // r5

  if ( a7[1] == 4 && a7[3] == 4 )
    *v7 = *(_DWORD *)((char *)a7 + a7[2]);
  ExFreePoolWithTag((unsigned int)a7);
  JUMPOUT(0x76FCB8);
}
