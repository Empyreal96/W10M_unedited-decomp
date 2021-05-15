// sub_53AA20 
 
void __fastcall sub_53AA20(int a1)
{
  if ( KeGetCurrentIrql(a1) != 2 )
  {
    MiWaitForFreePage(MiSystemPartition);
    JUMPOUT(0x49AF5E);
  }
  JUMPOUT(0x49AFD6);
}
