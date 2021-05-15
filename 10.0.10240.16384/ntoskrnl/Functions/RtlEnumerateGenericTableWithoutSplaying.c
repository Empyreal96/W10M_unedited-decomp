// RtlEnumerateGenericTableWithoutSplaying 
 
int __fastcall RtlEnumerateGenericTableWithoutSplaying(int *a1, int *a2)
{
  int v4; // r0
  int i; // r3

  if ( !RtlIsGenericTableEmpty() )
  {
    if ( !*a2 )
    {
      v4 = *a1;
      for ( i = *(_DWORD *)(*a1 + 4); i; i = *(_DWORD *)(i + 4) )
        v4 = i;
      goto LABEL_5;
    }
    v4 = RtlRealSuccessor(*a2);
    if ( v4 )
    {
LABEL_5:
      *a2 = v4;
      return v4 + 24;
    }
  }
  return 0;
}
