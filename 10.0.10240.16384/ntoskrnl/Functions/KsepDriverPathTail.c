// KsepDriverPathTail 
 
int __fastcall KsepDriverPathTail(unsigned __int16 *a1, unsigned int a2)
{
  int v3; // r2
  int v4; // r1
  int v5; // t1
  unsigned __int16 *v6; // r1

  if ( !a1 || !a2 )
    return -1073741811;
  v3 = *a1 >> 1;
  if ( !v3 )
    goto LABEL_7;
  v4 = *((_DWORD *)a1 + 1) + 2 * v3;
  while ( 1 )
  {
    v5 = *(unsigned __int16 *)(v4 - 2);
    v4 -= 2;
    if ( v5 == 92 )
      break;
    if ( !--v3 )
      goto LABEL_7;
  }
  v6 = (unsigned __int16 *)(*((_DWORD *)a1 + 1) + 2 * v3);
  if ( !v6 )
LABEL_7:
    v6 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  RtlInitUnicodeString(a2, v6);
  return 0;
}
