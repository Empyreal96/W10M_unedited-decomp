// sub_530830 
 
void __fastcall sub_530830(_DWORD *a1, int a2)
{
  unsigned int *v2; // r4
  unsigned int v3; // r5
  unsigned int v4; // r7
  unsigned int v5; // r2

  v2 = a1 + 121;
  v3 = a1[121];
  while ( 1 )
  {
    v4 = v3;
    if ( v3 + a2 > a1[120] )
      break;
    do
      v5 = __ldrex(v2);
    while ( v5 == v3 && __strex(v3 + a2, v2) );
    v3 = v5;
    if ( v5 == v4 )
      JUMPOUT(0x48696C);
  }
  if ( a1[72] )
    PsReportProcessMemoryLimitViolation();
  JUMPOUT(0x48697C);
}
