// EtwpAdjustFreeBuffers 
 
int __fastcall EtwpAdjustFreeBuffers(unsigned int *a1)
{
  int v1; // r5
  unsigned int v2; // r2
  unsigned int v3; // r3

  v1 = 0;
  if ( (a1[3] & 0x40000) == 0 )
  {
    v2 = a1[39];
    __dmb(0xBu);
    if ( (a1[3] & 0x10000000) != 0 )
      v3 = 1;
    else
      v3 = KeNumberProcessors_0;
    if ( v2 < v3 && v3 - v2 != EtwpAllocateFreeBuffers(a1, v3 - v2) )
      v1 = -1073741801;
  }
  return v1;
}
