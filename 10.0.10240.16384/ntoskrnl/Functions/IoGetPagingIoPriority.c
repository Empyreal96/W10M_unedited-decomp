// IoGetPagingIoPriority 
 
int __fastcall IoGetPagingIoPriority(int a1)
{
  unsigned int v1; // r3
  int v2; // r3
  int result; // r0

  v1 = *(_DWORD *)(a1 + 8);
  if ( (v1 & 2) == 0 )
    return 0;
  v2 = (v1 >> 17) & 7;
  if ( v2 && v2 == 5 )
    result = 2;
  else
    result = 1;
  return result;
}
