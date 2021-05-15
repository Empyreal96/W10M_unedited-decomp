// sub_7E51C0 
 
void __fastcall sub_7E51C0(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7)
{
  int v7; // r3

  if ( (MmVerifierData & 0x10) != 0 )
    v7 = 40;
  else
    v7 = 32;
  ExAllocatePoolWithTagPriority(512, a7, 538996553, v7);
  JUMPOUT(0x77D4AA);
}
