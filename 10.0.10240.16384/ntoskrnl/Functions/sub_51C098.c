// sub_51C098 
 
void __fastcall sub_51C098(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r7

  if ( a4 >> 4 == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + v4 + 20) )
    JUMPOUT(0x446588);
  JUMPOUT(0x446504);
}
