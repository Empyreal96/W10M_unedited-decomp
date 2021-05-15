// RtlEnumerateGenericTableWithoutSplayingAvl 
 
int __fastcall RtlEnumerateGenericTableWithoutSplayingAvl(int a1, int *a2)
{
  int v4; // r0
  int i; // r3

  if ( !RtlIsGenericTableEmptyAvl(a1) )
  {
    if ( !*a2 )
    {
      v4 = *(_DWORD *)(a1 + 8);
      for ( i = *(_DWORD *)(v4 + 4); i; i = *(_DWORD *)(i + 4) )
        v4 = i;
      goto LABEL_4;
    }
    v4 = RealSuccessor();
    if ( v4 )
    {
LABEL_4:
      *a2 = v4;
      return v4 + 16;
    }
  }
  return 0;
}
