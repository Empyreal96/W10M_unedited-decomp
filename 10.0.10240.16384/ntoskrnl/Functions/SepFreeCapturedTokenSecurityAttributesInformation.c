// SepFreeCapturedTokenSecurityAttributesInformation 
 
unsigned int __fastcall SepFreeCapturedTokenSecurityAttributesInformation(unsigned int a1)
{
  __int64 v2; // kr00_8
  unsigned int v3; // r7
  int v4; // r4
  unsigned int v5; // r0

  v2 = *(_QWORD *)(a1 + 4);
  v3 = 0;
  if ( (_DWORD)v2 )
  {
    v4 = *(_DWORD *)(a1 + 8);
    do
    {
      v5 = ExFreePoolWithTag(*(_DWORD *)(v4 + 4));
      if ( *(_DWORD *)(v4 + 16) && *(_WORD *)(v4 + 8) )
      {
        if ( *(unsigned __int16 *)(v4 + 8) > 2u && *(_WORD *)(v4 + 8) != 3 )
          return sub_7DBAEC(v5);
        ExFreePoolWithTag(*(_DWORD *)(v4 + 20));
      }
      ++v3;
      v4 += 24;
    }
    while ( v3 < *(_DWORD *)(a1 + 4) );
  }
  if ( HIDWORD(v2) )
    ExFreePoolWithTag(HIDWORD(v2));
  return ExFreePoolWithTag(a1);
}
