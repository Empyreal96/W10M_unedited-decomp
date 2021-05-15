// IoGetInitiatorProcess 
 
int __fastcall IoGetInitiatorProcess(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 124) )
    result = sub_52712C();
  else
    result = 0;
  return result;
}
