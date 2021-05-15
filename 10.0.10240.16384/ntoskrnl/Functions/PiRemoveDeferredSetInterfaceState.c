// PiRemoveDeferredSetInterfaceState 
 
int __fastcall PiRemoveDeferredSetInterfaceState(int a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // r4
  int *v4; // r6

  v2 = *(unsigned __int16 **)(a1 + 392);
  v4 = (int *)(a1 + 392);
  while ( 1 )
  {
    if ( v2 == (unsigned __int16 *)v4 )
      return -1073741823;
    if ( RtlEqualUnicodeString(v2 + 4, a2, 1) )
      break;
    v2 = *(unsigned __int16 **)v2;
  }
  return sub_819EDC();
}
