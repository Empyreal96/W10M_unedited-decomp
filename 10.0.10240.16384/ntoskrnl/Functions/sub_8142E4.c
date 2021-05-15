// sub_8142E4 
 
void __fastcall sub_8142E4(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int16 *a7)
{
  unsigned int *v7; // r6
  int v8; // r7
  unsigned int v9; // r8
  int v10; // r4

  if ( BiGetPhysicalDriveName(v8, &a7) < 0
    || (v10 = BiGetDriveLayoutInformation(a7, (int)v7), ExFreePoolWithTag((unsigned int)a7), v10 < 0) )
  {
    if ( *v7 )
    {
      ExFreePoolWithTag(*v7);
      *v7 = v9;
    }
    JUMPOUT(0x7A71C4);
  }
  JUMPOUT(0x7A7198);
}
