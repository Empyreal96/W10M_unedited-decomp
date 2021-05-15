// EtwpUpdateSchematizedFilterData 
 
int __fastcall EtwpUpdateSchematizedFilterData(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( !a4 )
    JUMPOUT(0x81C45E);
  if ( *(_DWORD *)(a1 + 32) )
    result = sub_81C458();
  else
    result = 0;
  return result;
}
