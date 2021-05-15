// _CmIsInstallerClassRegPropWritable 
 
int __fastcall CmIsInstallerClassRegPropWritable(int a1, _BYTE *a2)
{
  unsigned int v3; // r3
  int result; // r0

  v3 = a1 - 1;
  result = 0;
  if ( v3 > 0x24 || !*((_BYTE *)ClassPropertyRead + a1) )
    return -1073741264;
  *a2 = *((_BYTE *)ClassPropertyWrite + a1);
  return result;
}
