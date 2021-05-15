// sub_7C9D68 
 
void __fastcall sub_7C9D68(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, _DWORD *a15)
{
  int v15; // r4

  if ( a15[1] == 4 && a15[3] >= 4u )
    v15 = *(_DWORD *)((char *)a15 + a15[2]);
  else
    v15 = 0;
  ExFreePoolWithTag((unsigned int)a15);
  if ( !v15 )
    JUMPOUT(0x76991A);
  JUMPOUT(0x769940);
}
