// PnpGetInterruptInformation 
 
int __fastcall PnpGetInterruptInformation(int a1, int a2, unsigned int a3, unsigned int *a4)
{
  unsigned int *v4; // r0

  v4 = *(unsigned int **)(*(_DWORD *)(a1 + 176) + 48);
  if ( !v4 )
    return -1073741772;
  if ( a4 )
    *a4 = *v4;
  if ( a3 < *v4 )
    return -1073741789;
  memmove(a2, (int)(v4 + 1), *v4);
  return 0;
}
