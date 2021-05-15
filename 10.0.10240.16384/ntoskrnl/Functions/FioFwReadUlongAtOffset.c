// FioFwReadUlongAtOffset 
 
int __fastcall FioFwReadUlongAtOffset(_DWORD *a1, int a2, unsigned int *a3)
{
  int result; // r0

  result = FioFwReadBytesAtOffset(a1, a2, 4u, (int)a3);
  if ( result >= 0 )
  {
    result = 0;
    *a3 = bswap32(*a3);
  }
  return result;
}
