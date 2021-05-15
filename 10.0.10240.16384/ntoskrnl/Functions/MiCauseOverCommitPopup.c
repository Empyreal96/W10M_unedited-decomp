// MiCauseOverCommitPopup 
 
int __fastcall MiCauseOverCommitPopup(int result)
{
  unsigned int *v1; // r1
  unsigned int v2; // r2
  signed int v3; // r2
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r2
  signed int v7; // r2

  if ( *(_DWORD *)(result + 4116) != *(_DWORD *)(result + 3204) )
  {
    v1 = (unsigned int *)(result + 3212);
    do
    {
      v6 = __ldrex(v1);
      v7 = v6 + 1;
    }
    while ( __strex(v7, v1) );
    if ( v7 > 1 )
      goto LABEL_5;
    v5 = -1073741112;
    return IoRaiseInformationalHardError(v5, 0, 0);
  }
  v1 = (unsigned int *)(result + 3208);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 + 1;
  }
  while ( __strex(v3, v1) );
  if ( v3 <= 1 )
  {
    v5 = -1073741523;
    return IoRaiseInformationalHardError(v5, 0, 0);
  }
  do
LABEL_5:
    v4 = __ldrex(v1);
  while ( __strex(v4 - 1, v1) );
  return result;
}
