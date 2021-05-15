// MiChargeProcessPhysicalPages 
 
int __fastcall MiChargeProcessPhysicalPages(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r4
  int result; // r0
  unsigned int *v5; // r6
  unsigned int v6; // r4
  unsigned int i; // r2
  unsigned int v8; // r5

  if ( *(_DWORD *)(a1 + 652) )
  {
    v5 = (unsigned int *)(a1 + 648);
    v6 = *(_DWORD *)(a1 + 648);
    for ( i = v6 + a2; i <= *(_DWORD *)(a1 + 652); i = v8 + a2 )
    {
      do
        v8 = __ldrex(v5);
      while ( v8 == v6 && __strex(i, v5) );
      if ( v8 == v6 )
        goto LABEL_4;
      v6 = v8;
    }
    result = 0;
  }
  else
  {
    v2 = (unsigned int *)(a1 + 648);
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 + a2, v2) );
LABEL_4:
    result = 1;
  }
  return result;
}
