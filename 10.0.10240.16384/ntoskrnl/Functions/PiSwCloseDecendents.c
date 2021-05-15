// PiSwCloseDecendents 
 
int __fastcall PiSwCloseDecendents(int *a1, int a2, int a3, int a4)
{
  int result; // r0

  result = PiSwFindBusRelations(a1, a2, a3, a4);
  if ( result )
    result = sub_81C9E0();
  return result;
}
