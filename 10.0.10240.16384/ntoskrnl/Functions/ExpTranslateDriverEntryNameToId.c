// ExpTranslateDriverEntryNameToId 
 
int __fastcall ExpTranslateDriverEntryNameToId(unsigned __int16 *a1, int *a2)
{
  int v4; // r5
  unsigned int v5; // r6
  unsigned __int16 *v6; // r7
  int v7; // t1
  unsigned int v8; // r0

  if ( towlower(*a1) != 100
    || towlower(a1[1]) != 114
    || towlower(a1[2]) != 105
    || towlower(a1[3]) != 118
    || towlower(a1[4]) != 101
    || towlower(a1[5]) != 114 )
  {
    return 0;
  }
  v4 = 0;
  v5 = 6;
  v6 = a1 + 6;
  do
  {
    v7 = *v6++;
    v8 = towlower(v7);
    if ( v8 < 0x30 || v8 > 0x39 )
    {
      if ( v8 < 0x61 || v8 > 0x66 )
        return 0;
      v4 = v8 + 16 * v4 - 87;
    }
    else
    {
      v4 = v8 + 16 * v4 - 48;
    }
    ++v5;
  }
  while ( v5 < 0xA );
  if ( a1[10] )
    return 0;
  *a2 = v4;
  return 1;
}
