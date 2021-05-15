// SepCompareSidAndAttributeArrays 
 
int __fastcall SepCompareSidAndAttributeArrays(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v5; // r4
  int v6; // r6
  int v7; // r8
  int result; // r0

  if ( a2 != a4 )
    return 0;
  v5 = 0;
  if ( a2 )
  {
    v6 = a3;
    v7 = a1 - a3;
    do
    {
      if ( !RtlEqualSid(*(unsigned __int16 **)(v7 + v6), *(unsigned __int16 **)v6) )
        break;
      if ( ((*(_DWORD *)(v7 + v6 + 4) ^ *(_DWORD *)(v6 + 4)) & 0x14) != 0 )
        break;
      ++v5;
      v6 += 8;
    }
    while ( v5 < a2 );
  }
  if ( v5 == a2 )
    result = 1;
  else
    result = sub_7E7EB0();
  return result;
}
