// PnpLookupArbitersNewResources 
 
int __fastcall PnpLookupArbitersNewResources(int *a1, unsigned int a2, int a3)
{
  unsigned int v3; // r5
  int v5; // t1
  int result; // r0

  v3 = 0;
  if ( !a2 )
    goto LABEL_6;
  do
  {
    v5 = *a1;
    a1 += 10;
    if ( v5 == *(_DWORD *)(a3 + 16) )
      break;
    ++v3;
  }
  while ( v3 < a2 );
  if ( v3 < a2 )
    result = sub_80DC84();
  else
LABEL_6:
    result = -1073741823;
  return result;
}
