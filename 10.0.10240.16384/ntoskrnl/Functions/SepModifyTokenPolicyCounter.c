// SepModifyTokenPolicyCounter 
 
unsigned int __fastcall SepModifyTokenPolicyCounter(int a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int v4; // r4
  unsigned __int16 v5; // r9
  unsigned int result; // r0
  int v7; // r8
  unsigned int v8; // lr
  unsigned int *v9; // r2
  unsigned int v10; // r0
  unsigned int *v11; // r2
  unsigned __int16 v12; // [sp+0h] [bp-28h]

  v2 = 0;
  v3 = -1;
  if ( a2 )
    v3 = 1;
  v4 = 0;
  v5 = 0;
  v12 = 0;
  do
  {
    result = 0;
    v7 = 0;
    if ( AdtpPerCategoryCount[v4] )
    {
      v8 = 0;
      do
      {
        if ( ((*(unsigned __int8 *)(((v8 + v2) >> 1) + a1) >> (4 * ((v8 + v2) & 1))) & 0xF) != 0 )
        {
          __dmb(0xBu);
          v9 = &SepTokenPolicyCounter[result + v2];
          do
            v10 = __ldrex(v9);
          while ( __strex(v10 + v3, v9) );
          __dmb(0xBu);
          v7 = 1;
        }
        result = (unsigned __int16)(v8 + 1);
        v8 = result;
      }
      while ( result < (unsigned __int16)AdtpPerCategoryCount[v4] );
      v5 = v12;
      if ( v7 )
      {
        __dmb(0xBu);
        v11 = &SepTokenPolicyCounterByCategory[v4];
        do
          result = __ldrex(v11);
        while ( __strex(result + v3, v11) );
        __dmb(0xBu);
      }
    }
    v2 += (unsigned __int16)AdtpPerCategoryCount[v4];
    v4 = ++v5;
    v12 = v5;
  }
  while ( v5 < 9u );
  return result;
}
