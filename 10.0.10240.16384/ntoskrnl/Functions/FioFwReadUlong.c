// FioFwReadUlong 
 
int __fastcall FioFwReadUlong(_DWORD *a1, unsigned int *a2)
{
  unsigned int *v2; // r4
  int result; // r0

  v2 = (unsigned int *)a1[3];
  if ( (unsigned int)(v2 + 1) > *a1 + a1[1] )
    return -1073741807;
  *a2 = *v2;
  a1[3] = v2 + 1;
  result = 0;
  *a2 = bswap32(*a2);
  return result;
}
