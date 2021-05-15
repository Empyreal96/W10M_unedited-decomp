// sub_7E3474 
 
void __fastcall sub_7E3474(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, unsigned int a13)
{
  int v13; // r5
  unsigned int v14; // r8
  unsigned int v15; // r10

  if ( (*(_DWORD *)(v13 + 16) & 2) != 0 && a13 > v15 )
  {
    ExFreePoolWithTag(v14);
    if ( !ExAllocatePoolWithTag(1, a13, 1667526736) )
      JUMPOUT(0x77C1BC);
    JUMPOUT(0x77C184);
  }
  JUMPOUT(0x77C1C4);
}
