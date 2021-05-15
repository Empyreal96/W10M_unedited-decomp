// sub_56AC24 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_56AC24(int a1, int a2, int a3, int a4, int (*a5)(void))
{
  int v5; // r7

  if ( *(_DWORD *)(v5 + 56) != 3 )
    JUMPOUT(0x56ABB0);
  return a5();
}
