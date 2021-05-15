// MiInitializeCfg 
 
int __fastcall MiInitializeCfg(int a1, int a2)
{
  int result; // r0
  int v3[4]; // [sp+10h] [bp-10h] BYREF

  if ( PsIsSystemWideMitigationOptionSet(40, a2, 0, 512) )
    return sub_969EB0();
  if ( !dword_68124C )
    goto LABEL_4;
  v3[0] = 50331648;
  v3[1] = 0;
  result = MmCreateSection((int)&dword_632EE8, 983071, 0, (int)v3, 4, 0x4000000, 0, 0);
  if ( result >= 0 )
  {
    dword_632EEC = MiSectionControlArea(dword_632EE8);
LABEL_4:
    result = 0;
  }
  return result;
}
