// sub_4FE0B8 
 
int __fastcall sub_4FE0B8(int result, int a2, int a3, int *a4)
{
  int v6; // r5
  char *v7; // r8
  int v8; // t1

  v6 = a2;
  v7 = (char *)result;
  if ( (*(_DWORD *)(a3 + 12) & 0x40) == 0 || *(_DWORD *)(a3 + 8) )
  {
    do
    {
      if ( v6 <= 0 )
        break;
      v8 = *v7++;
      --v6;
      result = sub_4FC120(v8, a3, a4);
    }
    while ( *a4 != -1 );
  }
  else
  {
    *a4 += a2;
  }
  return result;
}
