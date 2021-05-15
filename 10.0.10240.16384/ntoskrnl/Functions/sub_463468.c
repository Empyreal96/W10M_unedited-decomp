// sub_463468 
 
int __fastcall sub_463468(char *a1)
{
  int v1; // r2
  int v2; // r4

  v1 = 31;
  v2 = (char *)L"\\DosDevices\\A:" - a1;
  do
  {
    if ( v1 == -2147483615 )
      break;
    if ( !*(_WORD *)&a1[v2] )
      break;
    *(_WORD *)a1 = *(_WORD *)&a1[v2];
    a1 += 2;
    --v1;
  }
  while ( v1 );
  if ( !v1 )
    return sub_50B594();
  *(_WORD *)a1 = 0;
  return 0;
}
