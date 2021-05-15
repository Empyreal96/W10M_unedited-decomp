// BgkDisplayCharacter 
 
int __fastcall BgkDisplayCharacter(int a1, int a2, int a3, int a4)
{
  int v8; // r0
  int v9; // r4

  v8 = BgkpAcquireConsole();
  if ( !v8 )
    return -1073741823;
  if ( byte_63760A || byte_63761C )
  {
    byte_63760A = 0;
    byte_63761C = 0;
    BgDisplayFade(v8);
  }
  v9 = (*(int (__fastcall **)(int, int, int, int))(dword_637614 + 16))(a1, a2, a3, a4);
  BgkpReleaseConsole();
  return v9;
}
