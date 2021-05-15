// NtSetInformationSymbolicLink 
 
int __fastcall NtSetInformationSymbolicLink(int a1, int a2, int a3, int a4)
{
  int v6; // r8
  int v7; // r4
  int v8; // r5
  int v10[6]; // [sp+8h] [bp-18h] BYREF

  v10[0] = a4;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v7 = ObReferenceObjectByHandle(a1, 1, ObpSymbolicLinkObjectType, v6, (int)v10, 0);
  if ( v7 >= 0 )
  {
    v8 = v10[0];
    if ( a2 == 1 )
    {
      if ( a4 )
      {
        v7 = -1073741820;
      }
      else if ( SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v6, (int)&SeTcbPrivilege) )
      {
        v7 = 0;
        *(_DWORD *)(v8 + 20) |= 1u;
      }
      else
      {
        v7 = -1073741727;
      }
    }
    else
    {
      v7 = -1073741821;
    }
    ObfDereferenceObject(v8);
  }
  return v7;
}
