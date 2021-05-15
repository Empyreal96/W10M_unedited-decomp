// PiSwFindChildren 
 
int PiSwFindChildren()
{
  int v0; // r0
  int result; // r0

  v0 = PiSwFindBusRelations();
  if ( v0 )
    result = v0 + 8;
  else
    result = 0;
  return result;
}
