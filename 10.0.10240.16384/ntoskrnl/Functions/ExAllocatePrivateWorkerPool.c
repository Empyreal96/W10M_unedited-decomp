// ExAllocatePrivateWorkerPool 
 
int ExAllocatePrivateWorkerPool()
{
  unsigned int v0; // r3
  int v1; // r3
  char v2; // r5
  int v3; // r1
  unsigned __int8 *v4; // r3
  unsigned int v5; // r4

  do
  {
    v0 = ExpInstanceAllocationMask;
    __dmb(0xBu);
    v1 = __clz(__rbit(v0));
    if ( (unsigned int)v1 >= 8 )
      JUMPOUT(0x79DA16);
    v2 = v1 & 7;
    __dmb(0xBu);
    v3 = 1 << (v1 & 7);
    v4 = (unsigned __int8 *)&ExpInstanceAllocationMask + (v1 >> 3);
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 & ~(_BYTE)v3, v4) );
    __dmb(0xBu);
  }
  while ( ((v5 >> v2) & 1) == 0 );
  return sub_810584(1);
}
