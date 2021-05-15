// sub_968598 
 
void sub_968598()
{
  int v0; // r4
  int v1; // r5
  int v2; // r1
  int v3; // r3

  v2 = *(_DWORD *)(*(_DWORD *)(v0 + 4) + 32);
  v3 = InitWinPEModeType;
  if ( (v2 & 1) != 0 )
  {
    v3 = InitWinPEModeType | 0x200;
    InitWinPEModeType |= 0x200u;
  }
  if ( (v2 & 2) != 0 )
    InitWinPEModeType = v3 | v1;
  JUMPOUT(0x94FBB8);
}
