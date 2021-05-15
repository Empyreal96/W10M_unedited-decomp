// KeAddSystemServiceTable 
 
int __fastcall KeAddSystemServiceTable(int a1, int a2, int a3, int a4, int a5)
{
  if ( a5 != 1 || dword_682090 || dword_682010 )
    JUMPOUT(0x81C7D4);
  return sub_81C79C();
}
