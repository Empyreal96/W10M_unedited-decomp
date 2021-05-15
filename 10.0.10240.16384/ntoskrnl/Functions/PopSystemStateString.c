// PopSystemStateString 
 
const char *__fastcall PopSystemStateString(int a1)
{
  switch ( a1 )
  {
    case 0:
      return "Unspecified";
    case 1:
      return "Working";
    case 2:
      return "Sleeping1";
    case 3:
      return "Sleeping2";
    case 4:
      return "Sleeping3";
    case 5:
      return "Hibernate";
    case 6:
      return "Shutdown";
  }
  return "?";
}
