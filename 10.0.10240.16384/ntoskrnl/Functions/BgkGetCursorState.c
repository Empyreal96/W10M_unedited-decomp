// BgkGetCursorState 
 
int __fastcall BgkGetCursorState(int a1, int a2, int a3)
{
  int v6; // r4

  if ( !BgkpAcquireConsole() )
    return -1073741823;
  v6 = (*(int (__fastcall **)(int, int, int))(dword_637614 + 24))(a1, a2, a3);
  BgkpReleaseConsole();
  return v6;
}
