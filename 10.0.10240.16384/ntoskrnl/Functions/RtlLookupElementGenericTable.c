// RtlLookupElementGenericTable 
 
int __fastcall RtlLookupElementGenericTable(int *a1, int a2)
{
  int v3; // r4
  int v5; // r0

  v3 = *a1;
  while ( v3 )
  {
    v5 = ((int (__fastcall *)(int *, int, int))a1[6])(a1, a2, v3 + 24);
    if ( v5 )
    {
      if ( v5 != 1 )
      {
        *a1 = RtlSplay(v3);
        return v3 + 24;
      }
      v3 = *(_DWORD *)(v3 + 8);
    }
    else
    {
      v3 = *(_DWORD *)(v3 + 4);
    }
  }
  return 0;
}
