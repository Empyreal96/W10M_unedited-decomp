// CmpLogDirtyVectorUse 
 
int __fastcall CmpLogDirtyVectorUse(int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  unsigned int *v4; // lr
  unsigned int v5; // r5
  unsigned int v7; // r6
  unsigned int v8; // r7
  unsigned int *v9; // r2

  v4 = (unsigned int *)(a1 + 2580);
  v5 = *(_DWORD *)(a1 + 2580);
  __dmb(0xBu);
  while ( 1 )
  {
    v7 = v5 + 1;
    if ( v5 + 1 >= *(_DWORD *)(a1 + 2584) )
      v7 = 0;
    __dmb(0xBu);
    do
      v8 = __ldrex(v4);
    while ( v8 == v5 && __strex(v7, v4) );
    __dmb(0xBu);
    if ( v5 == v8 )
      break;
    v5 = v8;
  }
  v9 = (unsigned int *)(a1 + 40 * v5 + 2588);
  *v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9[1] = a2;
  v9[2] = a3;
  v9[3] = a4;
  return RtlCaptureStackBackTrace(1u, 6u, a1 + 40 * v5 + 2604, 0);
}
