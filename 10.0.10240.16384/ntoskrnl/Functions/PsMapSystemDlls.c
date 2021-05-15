// PsMapSystemDlls 
 
int __fastcall PsMapSystemDlls(int a1)
{
  if ( a1 == *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
    JUMPOUT(0x7F58B2);
  return sub_7F58A4();
}
