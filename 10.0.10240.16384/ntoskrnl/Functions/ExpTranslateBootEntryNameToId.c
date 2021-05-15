// ExpTranslateBootEntryNameToId 
 
int __fastcall ExpTranslateBootEntryNameToId(unsigned __int16 *a1, int *a2)
{
  int v5; // r5
  unsigned int v6; // r6
  unsigned __int16 *v7; // r7
  int v8; // t1
  unsigned int v9; // r0

  if ( towlower(*a1) != 98 || towlower(a1[1]) != 111 || towlower(a1[2]) != 111 || towlower(a1[3]) != 116 )
    return 0;
  v5 = 0;
  v6 = 4;
  v7 = a1 + 4;
  do
  {
    v8 = *v7++;
    v9 = towlower(v8);
    if ( v9 > 0x39 || v9 < 0x30 )
    {
      if ( v9 > 0x66 || v9 < 0x61 )
        return 0;
      v5 = v9 + 16 * v5 - 87;
    }
    else
    {
      v5 = v9 + 16 * v5 - 48;
    }
    ++v6;
  }
  while ( v6 < 8 );
  if ( a1[8] )
    return 0;
  *a2 = v5;
  return 1;
}
