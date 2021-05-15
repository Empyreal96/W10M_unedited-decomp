// ExpAllocateFannedOutPushLock 
 
unsigned int __fastcall ExpAllocateFannedOutPushLock(int a1, char a2)
{
  int v3; // r1
  unsigned int v4; // r4
  int v5; // r0
  int v6; // r5
  unsigned int v7; // lr
  int *v8; // r7
  int v9; // t1
  _DWORD *v10; // r3

  v4 = ExSaAllocate(a1, (a2 & 1) == 0);
  if ( v4 != -1 )
  {
    v5 = KeQueryMaximumProcessorCountEx(0xFFFFu, v3);
    if ( v5 )
    {
      v6 = (v4 >> 13) & 0x3FFFF;
      v7 = __clz(v6);
      v8 = (int *)ExSaPageArrays;
      do
      {
        v9 = *v8++;
        --v5;
        v10 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v9 + 4 * (29 - v7)) + 4 * ((1 << (31 - v7)) ^ v6) + 4)
                       + 4 * ((v4 >> 3) & 0x3FF));
        *v10 = 0;
        v10[1] = a1;
      }
      while ( v5 );
    }
  }
  return v4;
}
