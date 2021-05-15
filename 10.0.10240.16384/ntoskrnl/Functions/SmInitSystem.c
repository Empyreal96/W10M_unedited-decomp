// SmInitSystem 
 
int __fastcall SmInitSystem(int a1)
{
  if ( a1 )
  {
    if ( a1 == 1 && EtwRegister((int)SmEventProvider, (int)SmEtwEnableCallback, 0) >= 0 )
    {
      dword_636E98 |= 1u;
      dword_636E9C = 64;
    }
  }
  else
  {
    SmGlobalsInitialize(SmGlobals);
    SmQueryRegistry(SmGlobals);
  }
  return 0;
}
