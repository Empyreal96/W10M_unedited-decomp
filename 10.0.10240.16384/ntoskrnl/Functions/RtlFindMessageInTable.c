// RtlFindMessageInTable 
 
int __fastcall RtlFindMessageInTable(int *a1, unsigned int a2, _DWORD *a3)
{
  int v3; // r5
  unsigned int *i; // r4
  unsigned __int16 *v7; // r2
  unsigned int j; // r1

  v3 = *a1;
  for ( i = (unsigned int *)(a1 + 1); ; i += 3 )
  {
    if ( !v3 )
      return -1073741559;
    --v3;
    if ( a2 >= *i && a2 <= i[1] )
      break;
  }
  v7 = (unsigned __int16 *)((char *)a1 + i[2]);
  for ( j = a2 - *i; j; v7 = (unsigned __int16 *)((char *)v7 + *v7) )
    --j;
  *a3 = v7;
  return 0;
}
