// PsQueryFullProcessImageName 
 
int __fastcall PsQueryFullProcessImageName(int a1, _DWORD *a2, int a3, unsigned int *a4)
{
  int v5; // r5
  unsigned int v6; // r4
  int v8; // r1
  int v9; // r3

  v5 = *(_DWORD *)(a1 + 380);
  v6 = *a4;
  *a4 = *(unsigned __int16 *)(v5 + 2);
  if ( *(unsigned __int16 *)(v5 + 2) > v6 )
    return -1073741820;
  v8 = (unsigned __int16)HIWORD(*(_DWORD *)v5);
  if ( HIWORD(*(_DWORD *)v5) )
    v9 = a3;
  else
    v9 = 0;
  *a2 = *(_DWORD *)v5;
  a2[1] = v9;
  if ( v8 )
    memmove(a3, *(_DWORD *)(v5 + 4), *(unsigned __int16 *)(v5 + 2));
  return 0;
}
