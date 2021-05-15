// _CmCreateInstallerClassWorker 
 
int __fastcall CmCreateInstallerClassWorker(int *a1, unsigned __int16 *a2, int a3, int *a4, _BYTE *a5, __int16 a6)
{
  int v9; // r4
  BOOL v10; // r2
  int v12[6]; // [sp+10h] [bp-18h] BYREF

  v12[0] = 0;
  if ( a6 )
    return -1073741811;
  v9 = CmOpenInstallerClassRegKey(a1, a2, 32, 0, a3, 1, (int)a4, v12);
  if ( v9 >= 0 )
  {
    v10 = v12[0] == 1;
    *a5 = v10;
    if ( v10 )
      CmRaiseCreateEvent((int)a1, (int)a2, 2, *a4);
  }
  return v9;
}
