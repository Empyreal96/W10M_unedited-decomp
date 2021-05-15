// PopPowerActionString 
 
const char *__fastcall PopPowerActionString(int a1)
{
  switch ( a1 )
  {
    case 0:
      return "None";
    case 2:
      return "Sleep";
    case 3:
      return "Hibernate";
    case 4:
      return "Shutdown";
    case 5:
      return "ShutdownReset";
    case 6:
      return "ShutdownOff";
    case 7:
      return "WarmEject";
  }
  return "?";
}
