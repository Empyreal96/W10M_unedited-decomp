// SepFindMatchingLuidEntry 
 
int __fastcall SepFindMatchingLuidEntry(_DWORD *a1, unsigned int *a2, int *a3, int a4)
{
  unsigned int v5; // r1
  int v7; // r0
  _DWORD v9[8]; // [sp+0h] [bp-20h] BYREF

  v9[0] = a1;
  v9[1] = a2;
  v9[2] = a3;
  v9[3] = a4;
  v5 = *a2;
  if ( !v5 )
    v5 = 1;
  v7 = RtlLookupEntryHashTable(a1, v5, v9, a4);
  if ( !v7 )
    JUMPOUT(0x7C5946);
  if ( *(_QWORD *)a2 != *(_QWORD *)(v7 + 16) )
    return sub_7C5938();
  *a3 = v7;
  return v9[0];
}
