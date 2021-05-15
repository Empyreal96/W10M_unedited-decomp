// PiSwFreeInterfaceList 
 
int __fastcall PiSwFreeInterfaceList(int *a1)
{
  int result; // r0

  result = *a1;
  if ( (int *)*a1 != a1 )
    result = sub_7E0B48();
  return result;
}
