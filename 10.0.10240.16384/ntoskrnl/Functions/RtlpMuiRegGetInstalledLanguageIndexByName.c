// RtlpMuiRegGetInstalledLanguageIndexByName 
 
int __fastcall RtlpMuiRegGetInstalledLanguageIndexByName(_DWORD *a1, _WORD *a2, int a3, int a4)
{
  _DWORD v5[6]; // [sp+0h] [bp-18h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  if ( !a1 || !a2 )
    return -1073741811;
  if ( RtlpMuiRegGetOrAddString(a1, a2, 0, (__int16 *)v5) < 0 )
    return -1073741772;
  return sub_817F1C();
}
