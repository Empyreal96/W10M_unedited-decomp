// ObCloseHandle 
 
int __fastcall ObCloseHandle(int a1)
{
  if ( (MmVerifierData & 0x100) == 0 )
    JUMPOUT(0x7F76F6);
  return sub_7F76DC(a1);
}
