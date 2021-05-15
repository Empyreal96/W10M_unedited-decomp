// KeSetPagePrivilege 
 
int __fastcall KeSetPagePrivilege(int a1, int a2, char a3)
{
  int result; // r0

  if ( (a3 & 8) != 0 )
    result = 0;
  else
    result = -1073741637;
  return result;
}
