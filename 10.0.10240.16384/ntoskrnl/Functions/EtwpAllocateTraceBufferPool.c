// EtwpAllocateTraceBufferPool 
 
int __fastcall EtwpAllocateTraceBufferPool(unsigned int *a1)
{
  unsigned int v2; // r7
  int v3; // r6
  unsigned int v4; // r0
  unsigned int v5; // r3
  unsigned int v6; // r5
  int result; // r0

  v2 = a1[3];
  if ( (v2 & 0x10000000) != 0 )
    v3 = 1;
  else
    v3 = KeNumberProcessors_0;
  v4 = EtwpGetSystemMaximumBufferCount(a1);
  if ( v4 < 2 * v3 )
    v4 = 2 * v3;
  v5 = a1[41];
  if ( v5 <= 2 * v3 )
    v5 = 2 * v3;
  a1[41] = v5;
  if ( v5 >= v4 )
    v5 = v4;
  v6 = a1[38];
  a1[41] = v5;
  if ( v6 <= 2 * v3 )
    v6 = 2 * v3;
  a1[38] = v6;
  if ( v6 >= v4 )
    v6 = v4;
  a1[38] = v6;
  if ( v6 > v5 )
    a1[41] = v6;
  if ( (v2 & 0x400) != 0 )
    a1[41] = v6;
  if ( (v2 & 0x40000) != 0 )
    goto LABEL_21;
  if ( a1[34] )
    return sub_809978();
  if ( EtwpAllocateFreeBuffers(a1, v6) >= v6 )
LABEL_21:
    result = 0;
  else
    result = -1073741801;
  return result;
}
