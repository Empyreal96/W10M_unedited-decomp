// NtShutdownSystem 
 
int __fastcall NtShutdownSystem(int a1)
{
  int v2; // r0

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      v2 = 5;
    }
    else
    {
      if ( a1 != 2 )
        return -1073741811;
      v2 = 6;
    }
  }
  else
  {
    v2 = 4;
  }
  return NtSetSystemPowerState(v2, 4, -1073741820);
}
