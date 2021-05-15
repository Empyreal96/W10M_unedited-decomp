// MiChargeProcessCommitment 
 
int __fastcall MiChargeProcessCommitment(_DWORD *a1, int a2)
{
  unsigned int *v3; // r2
  unsigned int v4; // r5
  unsigned int *v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // r1
  unsigned int v8; // r5
  unsigned int v9; // r2

  if ( a1[120] )
    return sub_530830();
  v3 = a1 + 121;
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 + a2, v3) );
  v5 = a1 + 122;
  v6 = v4 + a2;
  v7 = *v5;
  do
  {
    v8 = v7;
    if ( v6 <= v7 )
      break;
    do
      v9 = __ldrex(v5);
    while ( v9 == v7 && __strex(v6, v5) );
    v7 = v9;
  }
  while ( v9 != v8 );
  return 1;
}
