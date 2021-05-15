// FsRtlInitializeExtraCreateParameterList 
 
int __fastcall FsRtlInitializeExtraCreateParameterList(_DWORD *a1)
{
  if ( !a1 )
    return -1073741811;
  a1[2] = a1 + 2;
  a1[3] = a1 + 2;
  a1[1] = 0;
  *a1 = 1282433861;
  return 0;
}
