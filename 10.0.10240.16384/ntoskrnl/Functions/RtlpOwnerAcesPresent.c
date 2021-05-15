// RtlpOwnerAcesPresent 
 
int __fastcall RtlpOwnerAcesPresent(int a1, int a2)
{
  unsigned __int16 *v3; // r8
  unsigned int v4; // r7
  unsigned int v5; // r5
  unsigned __int8 *v6; // r4
  int v7; // r6
  unsigned int v8; // r3
  unsigned __int8 *v10; // r0

  v3 = *(unsigned __int16 **)(SeExports + 392);
  if ( !a2 )
    return 0;
  v4 = *(unsigned __int16 *)(a2 + 4);
  v5 = 0;
  v6 = (unsigned __int8 *)(a2 + 8);
  if ( !*(_WORD *)(a2 + 4) )
    return 0;
  while ( 1 )
  {
    v7 = v6[1];
    if ( (v7 & 8) == 0 )
    {
      v8 = *v6;
      if ( v8 >= 5 && v8 <= 8 )
        JUMPOUT(0x52E31E);
      if ( v8 >= 0xB )
        return sub_52E310();
      v10 = v8 == 4 ? v6 + 12 : v6 + 8;
      if ( v10
        && *(unsigned __int16 *)v10 == *v3
        && !memcmp((unsigned int)v10, (unsigned int)v3, 4 * (v10[1] + 2))
        && (!a1 || (a1 & v7) != 0) )
      {
        break;
      }
    }
    ++v5;
    v6 += *((unsigned __int16 *)v6 + 1);
    if ( v5 >= v4 )
      return 0;
  }
  return 1;
}
