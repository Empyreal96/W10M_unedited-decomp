// SepAdtInitializePrivilegeAuditing 
 
int __fastcall SepAdtInitializePrivilegeAuditing(int a1, int a2, int a3, int a4)
{
  int **v4; // r3
  int v6; // [sp+8h] [bp-8h] BYREF

  v6 = a4;
  LOBYTE(v6) = 0;
  if ( SepAdtRegNotifyHandle
    && (SepRegQueryValue(SepAdtRegNotifyHandle, L"FullPrivilegeAuditing", 3, 1u, &v6), (_BYTE)v6) )
  {
    v4 = SepFilterPrivilegesShort;
  }
  else
  {
    v4 = SepFilterPrivilegesLong;
  }
  SepFilterPrivileges = v4;
  return 1;
}
