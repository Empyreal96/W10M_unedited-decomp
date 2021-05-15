// sub_81329C 
 
void __fastcall sub_81329C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, char a8, unsigned __int16 *a9)
{
  int v9; // r8

  if ( BiGetPhysicalDriveName(v9, &a9) >= 0 && BiGetDriveLayoutInformation(a9, (int)&a8) >= 0 )
    JUMPOUT(0x7A485A);
  JUMPOUT(0x7A4950);
}
