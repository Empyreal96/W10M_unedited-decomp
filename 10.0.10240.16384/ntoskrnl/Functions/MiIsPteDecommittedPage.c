// MiIsPteDecommittedPage 
 
int __fastcall MiIsPteDecommittedPage(_DWORD *a1)
{
  int result; // r0

  if ( (*a1 & 0x3E0) == 512 )
    result = sub_53E7A4();
  else
    result = 0;
  return result;
}
