// ExInitializeZone 
 
int __fastcall ExInitializeZone(_DWORD *a1, unsigned int a2, _DWORD *a3, unsigned int a4)
{
  unsigned int v5; // r4
  char *v6; // r2

  if ( (a2 & 7) != 0 || ((unsigned __int8)a3 & 7) != 0 || a2 > a4 )
    return -1073741811;
  a1[1] = a3;
  a1[2] = a2;
  *a3 = 0;
  a3[1] = 0;
  v5 = 8;
  for ( *a1 = 0; v5 <= a4 - a2; *a1 = v6 )
  {
    v6 = (char *)a3 + v5;
    *(_DWORD *)((char *)a3 + v5) = *a1;
    v5 += a2;
  }
  a1[3] = v5;
  return 0;
}
