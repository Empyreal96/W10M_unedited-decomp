// PsGetServerSiloState 
 
int __fastcall PsGetServerSiloState(int a1)
{
  int result; // r0

  if ( a1 )
    result = sub_54D150();
  else
    result = 1;
  return result;
}
