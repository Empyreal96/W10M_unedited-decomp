// sub_81B724 
 
void __fastcall sub_81B724(int a1, int a2, int a3, int a4)
{
  int v4; // r9

  if ( a4 == 3 )
  {
    *(_DWORD *)(v4 + 36) = (unsigned int)EtwCPUSpeedInMHz >> 29;
    JUMPOUT(0x7BA92C);
  }
  JUMPOUT(0x7BA930);
}
