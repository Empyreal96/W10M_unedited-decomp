// PspCopyUnicodeString 
 
int __fastcall PspCopyUnicodeString(unsigned __int16 *a1, _DWORD *a2, int *a3, int a4)
{
  int *v4; // r5
  unsigned __int16 *v5; // r4
  int v6; // r0

  v4 = a3;
  v5 = a1;
  *a2 = *(_DWORD *)a1;
  a2[1] = *((_DWORD *)a1 + 1);
  if ( *((_DWORD *)a1 + 1) )
  {
    v6 = *a3;
    a2[1] = *a3;
    memmove(v6, *((_DWORD *)v5 + 1), *v5);
    memset((_BYTE *)(*v5 + *v4), 0, v5[1] - *v5);
    if ( *v4 )
      *v4 += v5[1];
  }
  return 0;
}
