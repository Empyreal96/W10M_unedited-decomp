// MiLogOutswappedProcessCommitReacquire 
 
void __fastcall MiLogOutswappedProcessCommitReacquire(int a1, int a2, int a3, int a4)
{
  if ( dword_634CA0 )
  {
    if ( a3 )
    {
      if ( !a4 )
        JUMPOUT(0x51675C);
      if ( *(_DWORD *)dword_634CA0 > 5u && TlgKeywordOn(dword_634CA0, a2, 4, 0) )
        JUMPOUT(0x51671A);
    }
    else if ( *(_DWORD *)dword_634CA0 > 5u )
    {
      if ( TlgKeywordOn(dword_634CA0, a2, 4, 0) )
        sub_5166D8();
    }
  }
}
