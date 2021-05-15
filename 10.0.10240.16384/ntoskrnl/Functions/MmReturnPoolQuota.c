// MmReturnPoolQuota 
 
int __fastcall MmReturnPoolQuota(int result, int a2)
{
  if ( result == 1 )
    dword_632D58 -= a2;
  else
    dword_632D5C -= a2;
  return result;
}
