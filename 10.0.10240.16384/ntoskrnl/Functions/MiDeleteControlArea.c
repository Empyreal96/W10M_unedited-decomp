// MiDeleteControlArea 
 
int __fastcall MiDeleteControlArea(_DWORD *a1)
{
  int v2; // r3
  int v3; // r0
  _DWORD *v5; // r4
  int v6; // r2
  int v7; // r4

  v2 = a1[7];
  if ( (v2 & 0x20) != 0 )
  {
    v5 = (_DWORD *)a1[14];
    v6 = v5[1];
    if ( (v6 & 0xFFFFFFF8) > 8 )
      SeReleaseImageValidationContext(v6 & 0xFFFFFFF8);
    MiFreeRelocations(a1, *v5);
  }
  else if ( (v2 & 0x80) != 0 )
  {
    v3 = a1[22];
    if ( v3 )
    {
      do
      {
        v7 = *(_DWORD *)(v3 + 8);
        MiDeleteSubsection(v3);
        v3 = v7;
      }
      while ( v7 );
    }
  }
  return ExFreePoolWithTag(a1, 0);
}
