// sub_523A18 
 
void __fastcall sub_523A18(int a1, int a2, unsigned int a3, unsigned int a4)
{
  _DWORD *v4; // r6

  if ( a3 < a4 )
  {
    MiSyncCommitSignals(v4, 0, a3, a4);
    JUMPOUT(0x45BEF6);
  }
  JUMPOUT(0x45BEEC);
}
