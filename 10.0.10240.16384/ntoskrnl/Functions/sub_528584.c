// sub_528584 
 
void sub_528584()
{
  int v0; // r7
  int v1; // r10
  char v2; // [sp+10h] [bp-30h]

  if ( (v2 & 4) != 0 )
  {
    if ( !v1 )
      v1 = v0;
    RtlpAllocateHeapRaiseException(v1);
  }
  JUMPOUT(0x4DDFA8);
}
