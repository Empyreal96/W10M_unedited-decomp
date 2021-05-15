// sub_81576C 
 
void sub_81576C()
{
  int v0; // r5
  int v1; // r6

  if ( v1 == 1 )
  {
    SiGetBiosSystemPartition(v0);
    JUMPOUT(0x7AAEB2);
  }
  JUMPOUT(0x7AAEB4);
}
