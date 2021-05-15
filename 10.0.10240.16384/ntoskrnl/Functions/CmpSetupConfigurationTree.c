// CmpSetupConfigurationTree 
 
int __fastcall CmpSetupConfigurationTree(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v6; // r0
  int v9; // r4
  int v10; // r0
  int v12; // [sp+10h] [bp-78h] BYREF
  _WORD v13[56]; // [sp+18h] [bp-70h] BYREF

  v6 = 0;
  do
  {
    if ( 2 * v6 >= 0x54 )
      _report_rangecheckfailure();
    v13[v6] = 0;
    v6 = (unsigned __int16)(v6 + 1);
  }
  while ( v6 < 0x2A );
  if ( !a1 )
    return 0;
  while ( 1 )
  {
    if ( a1[3] == 3 && !*(_DWORD *)(*a1 + 12) && a1[4] == 12 )
    {
      a3 = stricmp((unsigned __int8 *)a1[11], "ISA") == 0;
      a4 = 0;
    }
    v9 = CmpInitializeRegistryNode(a1, a2, &v12, a3, a4, (int)v13);
    if ( v9 < 0 )
      break;
    v10 = a1[1];
    if ( v10 && CmpSetupConfigurationTree(v10, v12, a3, a4) < 0 )
      return sub_9680D8();
    NtClose();
    a1 = (_DWORD *)a1[2];
    if ( !a1 )
      return 0;
  }
  return v9;
}
