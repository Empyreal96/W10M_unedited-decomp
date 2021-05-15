// RtlUnicodeToMultiByteN 
 
int __fastcall RtlUnicodeToMultiByteN(int a1, unsigned int a2, unsigned int *a3, int a4, unsigned int a5)
{
  unsigned int v5; // r5

  v5 = a5 >> 1;
  if ( !NlsMbCodePageTag )
  {
    if ( v5 >= a2 )
      v5 = a2;
    if ( a3 )
      *a3 = v5;
    __asm { ADD             PC, R3 }
  }
  return sub_7C3DD4();
}
