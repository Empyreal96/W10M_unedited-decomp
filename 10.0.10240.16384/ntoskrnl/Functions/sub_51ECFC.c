// sub_51ECFC 
 
void __fastcall sub_51ECFC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, char a15)
{
  int v15; // r7

  if ( (a15 & 1) != 0 )
    *(_DWORD *)(IopAllocateIrpExtension(v15, 2) + 4) = a5;
  JUMPOUT(0x44E442);
}
