// PspInheritMitigationOptions 
 
int __fastcall PspInheritMitigationOptions(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int result; // r0
  int v7; // r1
  unsigned int i; // r5
  unsigned int v11; // r7
  unsigned int v12; // r6
  unsigned int v13; // r4
  unsigned int v14; // r3
  unsigned int v15; // r2

  result = 0;
  v7 = 0;
  for ( i = 0; i < 0x34; i += 4 )
  {
    v11 = a1 & 0xF;
    a1 = (a2 << 28) | (a1 >> 4);
    v12 = a3 & 0xF;
    a3 = (a4 << 28) | (a3 >> 4);
    a2 >>= 4;
    a4 >>= 4;
    if ( (v11 & 4) == 0 && (v12 & 3) != 0 )
    {
      v13 = v12 >> (32 - i);
      v14 = v12 << (i - 32);
      v15 = v12 << i;
    }
    else
    {
      v13 = v11 >> (32 - i);
      v14 = v11 << (i - 32);
      v15 = v11 << i;
    }
    v7 |= v14 | v13;
    result |= v15;
  }
  return result;
}
