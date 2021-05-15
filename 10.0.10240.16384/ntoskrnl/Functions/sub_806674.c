// sub_806674 
 
void __fastcall sub_806674(int a1, int a2, int a3)
{
  unsigned int v3; // r5
  unsigned int v4; // r8

  if ( v4 >= *(_DWORD *)(a3 + 6680) )
  {
    MiGetCcAccessLog(a1, v3 >> 12);
    JUMPOUT(0x754086);
  }
  JUMPOUT(0x754084);
}
