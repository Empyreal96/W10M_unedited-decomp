// RtlLookupElementGenericTableFull 
 
int __fastcall RtlLookupElementGenericTableFull(int *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  __int64 v7; // r0

  LODWORD(v7) = sub_44CE2C(a1, a2, a3);
  *a4 = v7;
  if ( !(_DWORD)v7 || (_DWORD)v7 != 1 )
    return 0;
  LODWORD(v7) = *a3;
  *a1 = RtlSplay(v7);
  return *a3 + 24;
}
