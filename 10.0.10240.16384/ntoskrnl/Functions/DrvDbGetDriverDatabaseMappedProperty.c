// DrvDbGetDriverDatabaseMappedProperty 
 
int __fastcall DrvDbGetDriverDatabaseMappedProperty(int a1, int a2, int a3, int a4, _DWORD *a5, int a6, int a7, _DWORD *a8)
{
  int result; // r0

  *a5 = 0;
  *a8 = 0;
  if ( wcsicmp(a2, L"*") )
    result = sub_818FD4();
  else
    result = -1073741637;
  return result;
}
