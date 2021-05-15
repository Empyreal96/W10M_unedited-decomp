// SmQueryStoreInformation 
 
int __fastcall SmQueryStoreInformation(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // r5
  int v7; // r4
  int v8; // r6
  int v9; // r8
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r3 = a4;
  v5 = (char)a4;
  LOBYTE(varg_r3) = a4;
  if ( a3 != 16 )
    return -1073741820;
  v7 = a2[1];
  v8 = a2[2];
  v9 = a2[3];
  if ( *a2 != 1 )
    return -1073741811;
  if ( v7 == 2 )
    return SmProcessStatsRequest(0, v8, v9, a5, (char)a4);
  if ( v7 != 5
    && v7 != 8
    && v7 != 13
    && v7 != 16
    && !SeSinglePrivilegeCheck(
          SeProfileSingleProcessPrivilege,
          dword_922B94,
          (char)a4,
          (int)&SeProfileSingleProcessPrivilege) )
  {
    return -1073741790;
  }
  switch ( v7 )
  {
    case 5:
      return SmProcessListRequest(SmGlobals, v8, v9, a5, v5);
    case 8:
      return SmcProcessListRequest(&unk_636CE4, v8, v9, a5, v5);
    case 13:
      return SmcProcessStatsRequest(&unk_636CE4, v8, v9, a5, v5);
    case 15:
      return SmProcessRegistrationRequest(v8, v9, a5, v5);
    case 16:
      return SmProcessGlobalCacheStatsRequest(v8, v9, a5, v5);
  }
  return -1073741821;
}
