// RtlLookupElementGenericTableAvl 
 
int __fastcall RtlLookupElementGenericTableAvl(int a1, int a2)
{
  int v4; // r4
  int v5; // r0

  if ( !*(_DWORD *)(a1 + 24) )
    return 0;
  v4 = *(_DWORD *)(a1 + 8);
  while ( 1 )
  {
    v5 = (*(int (__fastcall **)(int, int, int))(a1 + 40))(a1, a2, v4 + 16);
    if ( !v5 )
    {
      v4 = *(_DWORD *)(v4 + 4);
      goto LABEL_6;
    }
    if ( v5 != 1 )
      return v4 + 16;
    v4 = *(_DWORD *)(v4 + 8);
LABEL_6:
    if ( !v4 )
      return 0;
  }
}
