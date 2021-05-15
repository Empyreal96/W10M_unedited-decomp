// sub_800EB4 
 
void __fastcall sub_800EB4(int a1, unsigned int a2)
{
  if ( MiChargeFullProcessCommitment(*(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), a2) < 0 )
    JUMPOUT(0x73D618);
  JUMPOUT(0x73D616);
}
