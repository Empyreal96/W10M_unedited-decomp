// BgkGetConsoleState 
 
int __fastcall BgkGetConsoleState(int a1)
{
  int v2; // r4

  if ( !BgkpAcquireConsole() )
    return -1073741823;
  v2 = (*(int (__fastcall **)(int))(dword_637614 + 20))(a1);
  BgkpReleaseConsole();
  return v2;
}
