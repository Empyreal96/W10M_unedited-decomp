// sub_7E0DB4 
 
void __fastcall sub_7E0DB4(unsigned int a1)
{
  int v1; // r4

  if ( a1 )
  {
    if ( (*(_DWORD *)(v1 + 168) & 0x2000) == 0 )
      ExFreePoolWithTag(a1);
  }
  JUMPOUT(0x77813E);
}
