// PopFxComponentWork 
 
int __fastcall PopFxComponentWork(_DWORD *a1)
{
  unsigned int *v2; // r5
  unsigned int v3; // r2
  unsigned int v4; // r2
  int result; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r1
  int v9; // [sp+0h] [bp-28h] BYREF

  v2 = a1 + 9;
  do
  {
    PopFxIdleWorker(a1[12], a1[4], &v9);
    __dmb(0xBu);
    do
    {
      v3 = __ldrex(v2);
      v4 = v3 - 1;
    }
    while ( __strex(v4, v2) );
    __dmb(0xBu);
  }
  while ( v4 );
  result = a1[12];
  __dmb(0xBu);
  v6 = (unsigned int *)(result + 112);
  do
  {
    v7 = __ldrex(v6);
    v8 = v7 - 1;
  }
  while ( __strex(v8, v6) );
  __dmb(0xBu);
  if ( !v8 )
    result = sub_526A70();
  return result;
}
