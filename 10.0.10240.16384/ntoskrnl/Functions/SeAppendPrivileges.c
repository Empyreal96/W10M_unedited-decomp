// SeAppendPrivileges 
 
int __fastcall SeAppendPrivileges(int a1, _DWORD *a2)
{
  if ( (unsigned int)(*a2 + ***(_DWORD ***)(a1 + 48)) > 3 )
    return sub_7BDC14();
  SepConcatenatePrivileges();
  return 0;
}
