// PiDqGetPnpObjectType 
 
int __fastcall PiDqGetPnpObjectType(int a1)
{
  switch ( a1 )
  {
    case 3:
      return 1;
    case 1:
      return 3;
    case 2:
      return 5;
  }
  return sub_7C7188(0);
}
