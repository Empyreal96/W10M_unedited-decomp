// RtlComputeCrc32 
 
int __fastcall RtlComputeCrc32(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r0
  unsigned int i; // r5
  char v5; // r3

  v3 = ~a1;
  for ( i = 0; i < a3; v3 = RtlCrc32Table[(unsigned __int8)(v5 ^ v3)] ^ (v3 >> 8) )
  {
    v5 = *(_BYTE *)(i + a2);
    ++i;
  }
  return ~v3;
}
