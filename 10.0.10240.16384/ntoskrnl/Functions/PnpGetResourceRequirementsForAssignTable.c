// PnpGetResourceRequirementsForAssignTable 
 
int __fastcall PnpGetResourceRequirementsForAssignTable(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int result; // r0

  *a3 = 0;
  if ( a1 >= a2 )
    result = -1073741823;
  else
    result = sub_7E11C0();
  return result;
}
