// MiLocateCloneAddress 
 
int __fastcall MiLocateCloneAddress(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 272) )
    result = sub_53A39C();
  else
    result = 0;
  return result;
}
