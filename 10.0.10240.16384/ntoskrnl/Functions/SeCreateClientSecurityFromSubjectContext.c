// SeCreateClientSecurityFromSubjectContext 
 
int __fastcall SeCreateClientSecurityFromSubjectContext(int *a1, int a2, int a3, int a4)
{
  int v5; // r4
  signed int v7; // r0
  int v9; // r5

  v5 = *a1;
  if ( !*a1 )
    v5 = a1[2];
  v7 = ObfReferenceObject(v5);
  if ( *a1 )
    return sub_7EA828(v7);
  v9 = SepCreateClientSecurityEx(v5, a2, a3, 1, 0, a1[1], 0, 0, 0, 0, a4);
  if ( v9 < 0 || !*(_BYTE *)(a2 + 8) )
    ObfDereferenceObject(v5);
  return v9;
}
