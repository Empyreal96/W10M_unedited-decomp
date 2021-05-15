// sub_51F42C 
 
void __fastcall sub_51F42C(unsigned int *a1)
{
  int v1; // r4
  unsigned int v2; // r6

  v2 = *(_DWORD *)(v1 + 16);
  if ( *a1 > v2 )
    *a1 = v2;
  JUMPOUT(0x44F462);
}
