// sub_96F5B0 
 
void __fastcall sub_96F5B0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r4

  if ( v7 != -1073741444 )
  {
    if ( v7 >= 0 )
      PipProcessPendingObjects(a7, 0, a3, PipCommitPendingOsExtensionResource);
    JUMPOUT(0x9635A0);
  }
  JUMPOUT(0x96359E);
}
