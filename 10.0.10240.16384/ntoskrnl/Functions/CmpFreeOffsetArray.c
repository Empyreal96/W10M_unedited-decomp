// CmpFreeOffsetArray 
 
unsigned int __fastcall CmpFreeOffsetArray(int a1, unsigned int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  unsigned int v4; // r5

  v2 = a1;
  v3 = a2;
  if ( a1 )
  {
    v4 = a2;
    do
    {
      ExFreePoolWithTag(*(_DWORD *)(v4 + 4));
      v4 += 12;
      --v2;
    }
    while ( v2 );
  }
  return ExFreePoolWithTag(v3);
}
