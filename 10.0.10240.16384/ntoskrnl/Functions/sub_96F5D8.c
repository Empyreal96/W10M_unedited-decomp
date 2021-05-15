// sub_96F5D8 
 
void __fastcall sub_96F5D8(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r4

  if ( v7 != -1073741444 )
  {
    if ( v7 >= 0 )
      PipProcessPendingObjects(a7, PipPendingServicesFilter, a3, PipCommitPendingService);
    JUMPOUT(0x963604);
  }
  JUMPOUT(0x963602);
}
