// IoNotifyDump 
 
int __fastcall IoNotifyDump(int result)
{
  int v1; // r0

  if ( dword_637660 )
  {
    switch ( result )
    {
      case 1:
        v1 = 3;
        break;
      case 2:
        v1 = 4;
        break;
      case 3:
        v1 = 5;
        break;
      default:
        return result;
    }
    result = dword_637660(v1, 0, 0);
  }
  return result;
}
