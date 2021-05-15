// RtlGetNextEntryHashTable 
 
int __fastcall RtlGetNextEntryHashTable(int a1, int a2)
{
  int *v3; // r4
  int result; // r0

  v3 = **(int ***)(a2 + 4);
  result = *v3;
  if ( *v3 == *(_DWORD *)a2 )
    return 0;
  if ( *(_DWORD *)(a1 + 28) )
    return sub_523300();
  if ( *(_DWORD *)(result + 8) != *(_DWORD *)(a2 + 8) )
    return 0;
  *(_DWORD *)(a2 + 4) = v3;
  return result;
}
