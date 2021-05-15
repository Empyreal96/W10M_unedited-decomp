// PoFxPlatformRequestHandler 
 
int __fastcall PoFxPlatformRequestHandler(int *a1)
{
  int v1; // r3

  v1 = *a1;
  if ( !*a1 )
    return sub_554568();
  if ( v1 == 1 || v1 != 2 || a1[2] != 1 )
    return -1073741637;
  *((_BYTE *)a1 + 12) = PopFxAcpiPepRegistered;
  return 0;
}
