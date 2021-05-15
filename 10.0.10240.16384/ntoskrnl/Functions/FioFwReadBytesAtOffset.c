// FioFwReadBytesAtOffset 
 
int __fastcall FioFwReadBytesAtOffset(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  if ( a2 + a3 > a1[1] )
    return -1073741811;
  memmove(a4, a2 + *a1, a3);
  return 0;
}
