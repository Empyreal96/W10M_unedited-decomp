// BgpConsoleSetCursor 
 
int __fastcall BgpConsoleSetCursor(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int v6; // r4

  BgpFwAcquireLock(a1);
  if ( a1 >= 0x50 || a2 >= dword_61034C || a3 > 0x64 )
  {
    v6 = -1073741811;
  }
  else
  {
    if ( dword_610384 != a1 || dword_610388 != a2 || dword_61038C != a3 )
    {
      if ( dword_61038C )
      {
        dword_61038C = 0;
        BgpConsoleDrawCursor();
      }
      dword_610384 = a1;
      dword_610388 = a2;
      dword_61038C = a3;
      if ( a3 )
        BgpConsoleDrawCursor();
    }
    v6 = 0;
  }
  BgpFwReleaseLock();
  return v6;
}
