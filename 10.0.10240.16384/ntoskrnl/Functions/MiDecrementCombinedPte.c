// MiDecrementCombinedPte 
 
int __fastcall MiDecrementCombinedPte(int a1)
{
  int v1; // r5
  unsigned int v2; // r4
  unsigned int *v3; // r2
  unsigned int v4; // r1
  unsigned int v5; // r1
  int v6; // r4

  v1 = a1 - 32;
  do
    v2 = __ldrex((unsigned int *)&dword_6404B0);
  while ( __strex(v2 - 1, (unsigned int *)&dword_6404B0) );
  v3 = (unsigned int *)(a1 - 8);
  do
  {
    v4 = __ldrex(v3);
    v5 = v4 - 1;
  }
  while ( __strex(v5, v3) );
  if ( v5 )
    return 2;
  if ( !*(_QWORD *)(a1 - 16) )
  {
    v6 = 0;
    goto LABEL_11;
  }
  v6 = MiDeleteMergedPte(dword_6403D0, a1);
  if ( (dword_682604 & 1) == 0 )
  {
LABEL_11:
    MiFreeCombineBlock(v1);
    return v6;
  }
  return sub_523A70();
}
