// sub_8180B4 
 
void __fastcall sub_8180B4(unsigned int a1)
{
  _DWORD *v1; // r4
  int v2; // r6
  int v3; // r8

  if ( (*v1 & v2) != 0 )
    ExFreePoolWithTag(a1);
  v1[8] = v3;
  JUMPOUT(0x7B1510);
}
