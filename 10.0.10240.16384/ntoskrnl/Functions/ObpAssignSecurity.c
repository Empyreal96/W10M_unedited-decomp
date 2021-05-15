// ObpAssignSecurity 
 
int __fastcall ObpAssignSecurity(int a1, int a2, int a3, int a4, int a5, char a6)
{
  int v9; // r1
  unsigned int v10; // r5
  int result; // r0
  int v12; // r9
  int v13; // r1
  int (__fastcall *v14)(int, int, _DWORD, unsigned int, _DWORD, _DWORD, int, int, int); // r4
  int v15; // r1
  int v16; // r4
  unsigned int v17; // [sp+18h] [bp-38h] BYREF
  unsigned int v18; // [sp+1Ch] [bp-34h] BYREF
  int v19; // [sp+20h] [bp-30h] BYREF
  int v20; // [sp+24h] [bp-2Ch]
  _DWORD v21[10]; // [sp+28h] [bp-28h] BYREF

  v20 = a3;
  v17 = 0;
  v9 = *(_DWORD *)(a1 + 44);
  v21[0] = 8;
  v21[1] = 0;
  v10 = 0;
  v18 = 0;
  result = SeComputeAutoInheritByObjectTypeEx(a4, v9, a2, &v19, v21);
  if ( result >= 0 )
  {
    v12 = v19 | a5;
    if ( a6 )
    {
      result = SeAssignSecurityEx(
                 0,
                 *(_DWORD *)(a1 + 44),
                 (int)&v18,
                 0,
                 a4 == ObpDirectoryObjectType,
                 0,
                 a1 + 28,
                 a4 + 52);
      if ( result < 0 )
        return result;
      v10 = v18;
    }
    if ( v10 )
      v13 = v10;
    else
      v13 = *(_DWORD *)(a1 + 44);
    if ( SeAssignSecurityEx2(a2, v13, (int)&v17, 0, a4 == ObpDirectoryObjectType, v12, v21, a1 + 28, a4 + 52) >= 0 )
    {
      if ( v10 )
        ExFreePoolWithTag(v10);
      v14 = *(int (__fastcall **)(int, int, _DWORD, unsigned int, _DWORD, _DWORD, int, int, int))(a4 + 108);
      v15 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
      v16 = v14(v20, 3, 0, v17, 0, 0, 1, a4 + 52, v15);
      if ( v16 < 0 )
        SeDeassignSecurity(&v17);
      result = v16;
    }
    else
    {
      result = sub_7FB858();
    }
  }
  return result;
}
