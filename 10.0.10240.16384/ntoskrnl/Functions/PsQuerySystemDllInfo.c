// PsQuerySystemDllInfo 
 
int __fastcall PsQuerySystemDllInfo(int a1)
{
  int v1; // r2
  int result; // r0

  v1 = (int)*(&PspSystemDlls + a1);
  if ( v1 && *(_DWORD *)(v1 + 20) )
    result = v1 + 8;
  else
    result = 0;
  return result;
}
