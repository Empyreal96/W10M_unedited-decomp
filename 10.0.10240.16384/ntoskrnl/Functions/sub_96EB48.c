// sub_96EB48 
 
void __fastcall sub_96EB48(int a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v4; // r7
  int v5; // r3

  if ( *a4 )
  {
    if ( (*v4 & a3) != 0 )
      v5 = 40;
    else
      v5 = 32;
    ExAllocatePoolWithTagPriority(512, 0x38u, 538996553, v5);
  }
  else
  {
    ExAllocatePoolWithTag(512, 56, 538996553);
  }
  JUMPOUT(0x962036);
}
