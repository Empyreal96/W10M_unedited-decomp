// SepRmReferenceFindCap 
 
int __fastcall SepRmReferenceFindCap(unsigned __int16 *a1, int *a2)
{
  int v3; // r5
  _DWORD *v5; // r6
  int v6; // r3
  unsigned int v7; // r0
  int v8; // r3
  int v9; // r4
  _DWORD v11[8]; // [sp+0h] [bp-20h] BYREF

  v3 = -1073741275;
  v11[0] = 0;
  v11[1] = 0;
  v11[2] = 0;
  *a2 = 0;
  v5 = (_DWORD *)SepRmReferenceCapTable();
  if ( v5 )
  {
    v6 = (unsigned __int8)SepRmEnforceCap;
    __dmb(0xBu);
    if ( !v6 )
      goto LABEL_8;
    v7 = SepComputeSidSignature(a1);
    v9 = RtlLookupEntryHashTable(v5, v7, v11, v8);
    if ( !v9 )
      goto LABEL_8;
    do
    {
      if ( RtlEqualSid(a1, *(unsigned __int16 **)(v9 + 12)) )
        break;
      v9 = RtlGetNextEntryHashTable((int)v5, (int)v11);
    }
    while ( v9 );
    if ( v9 )
    {
      *a2 = v9;
      v3 = 0;
    }
    else
    {
LABEL_8:
      SepRmDereferenceCapTable((int)v5);
    }
  }
  return v3;
}
