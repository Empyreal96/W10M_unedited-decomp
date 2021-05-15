// sub_96E6DC 
 
void __fastcall sub_96E6DC(int a1, int a2)
{
  int v2; // r4
  int v3; // r3

  v2 = 28 * a2;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v3 = 40;
    else
      v3 = 32;
    ExAllocatePoolWithTagPriority(512, v2 + 4, 538996553, v3);
  }
  else
  {
    ExAllocatePoolWithTag(512, v2 + 4, 538996553);
  }
  JUMPOUT(0x961110);
}
