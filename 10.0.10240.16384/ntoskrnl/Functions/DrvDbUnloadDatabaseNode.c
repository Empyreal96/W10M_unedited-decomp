// DrvDbUnloadDatabaseNode 
 
int __fastcall DrvDbUnloadDatabaseNode(int a1, _DWORD *a2)
{
  int (__fastcall *v3)(int, _DWORD, int, int); // r7
  int v4; // r4
  int v6; // r0
  int v8; // r0

  v3 = (int (__fastcall *)(int, _DWORD, int, int))a2[9];
  v4 = 0;
  if ( v3 )
  {
    v6 = v3(a1, a2[3], 2, 1);
    if ( v6 == -1073741822 )
    {
      v3 = 0;
    }
    else if ( v6 < 0 )
    {
      v4 = v6;
      goto LABEL_6;
    }
  }
  if ( a2[11] )
    return sub_7E2E38();
LABEL_6:
  if ( v3 )
  {
    v8 = v3(a1, a2[3], 2, 2);
    if ( v8 < 0 && v8 != -1073741822 && !v4 )
      v4 = v8;
  }
  return v4;
}
