// RtlpStdGetSpaceForTrace 
 
int __fastcall RtlpStdGetSpaceForTrace(int a1, int a2)
{
  int result; // r0
  unsigned int v5; // r4
  unsigned __int64 *v6; // r5
  int v7; // r0
  unsigned int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r1

  if ( !a2 )
    return 0;
  v5 = a2 - 1;
  if ( (unsigned int)(a2 - 1) >= 0x20 )
  {
LABEL_7:
    result = RtlpStdExtendLowerWatermark(a1, (4 * a2 + 19) & 0xFFFFFFF8);
    if ( result )
    {
      v8 = ((((4 * a2 + 19) & 0xFFFFFFF8) - 12) >> 2) - 1;
      if ( v8 > 0x1F )
        LOWORD(v8) = 31;
      *(_WORD *)(result + 4) = *(_WORD *)(result + 4) & 0x7FF | ((_WORD)v8 << 11);
    }
  }
  else
  {
    v6 = (unsigned __int64 *)(a1 + 8 * (a2 + 14));
    while ( 1 )
    {
      v7 = RtlpInterlockedPopEntrySList(v6);
      if ( v7 )
        break;
      ++v5;
      ++v6;
      if ( v5 >= 0x20 )
        goto LABEL_7;
    }
    result = v7 - 12;
    __dmb(0xBu);
    v9 = (unsigned int *)(a1 + 108);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 - 1, v9) );
    __dmb(0xBu);
  }
  return result;
}
