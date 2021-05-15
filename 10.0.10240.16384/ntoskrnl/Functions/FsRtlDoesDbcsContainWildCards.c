// FsRtlDoesDbcsContainWildCards 
 
int __fastcall FsRtlDoesDbcsContainWildCards(unsigned __int16 *a1)
{
  unsigned int v1; // r4
  int v2; // r2
  int v3; // r0
  int v4; // r1

  v1 = *a1;
  v2 = 0;
  if ( !*a1 )
    return 0;
  v3 = *((_DWORD *)a1 + 1);
  while ( 1 )
  {
    v4 = *(char *)(v3 + v2);
    if ( (unsigned __int8)v4 >= 0x80u )
      return sub_7D6ECC();
    if ( v4 >= 0 && (*((_BYTE *)dword_407310 + v4) & 8) != 0 )
      break;
    if ( ++v2 >= v1 )
      return 0;
  }
  return 1;
}
