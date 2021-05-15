// SepIdAssignableAsGroup 
 
BOOL __fastcall SepIdAssignableAsGroup(int *a1, unsigned __int16 *a2)
{
  BOOL v3; // r4
  unsigned int v5; // r6
  unsigned int v6; // r2
  unsigned int v7; // r9
  unsigned __int16 **v8; // r8
  unsigned __int16 *v9; // t1
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v3 = 0;
  if ( a2 )
  {
    v5 = 0;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    ExAcquireResourceSharedLite(a1[12], 1);
    v7 = a1[31];
    if ( v7 )
    {
      v8 = (unsigned __int16 **)a1[37];
      do
      {
        v9 = *v8;
        v8 += 2;
        v3 = RtlEqualSid(a2, v9);
        if ( v3 )
          break;
        ++v5;
      }
      while ( v5 < v7 );
    }
    v10 = ExReleaseResourceLite(a1[12]);
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x134) + 1;
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      KiCheckForKernelApcDelivery(v10);
  }
  return v3;
}
