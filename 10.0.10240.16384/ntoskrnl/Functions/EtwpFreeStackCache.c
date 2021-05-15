// EtwpFreeStackCache 
 
unsigned int __fastcall EtwpFreeStackCache(unsigned int a1)
{
  unsigned int v2; // r7
  unsigned int *v3; // r5
  unsigned int v4; // r0
  __int64 v5; // r2
  unsigned int v6; // r4
  _DWORD *v7; // r4
  unsigned int v8; // r0

  v2 = 0;
  if ( *(_DWORD *)(a1 + 4) )
  {
    v3 = (unsigned int *)(a1 + 16);
    do
    {
      while ( 1 )
      {
        v4 = *v3;
        if ( (unsigned int *)*v3 == v3 )
          break;
        v5 = *(_QWORD *)v4;
        if ( *(unsigned int **)(v4 + 4) != v3 || *(_DWORD *)(v5 + 4) != v4 )
          __fastfail(3u);
        *v3 = v5;
        *(_DWORD *)(v5 + 4) = v3;
        do
        {
          v6 = *(_DWORD *)(v4 + 8);
          ExFreePoolWithTag(v4);
          v4 = v6;
        }
        while ( v6 );
      }
      ++v2;
      v3 += 3;
    }
    while ( v2 < *(_DWORD *)(a1 + 4) );
  }
  v7 = (_DWORD *)RtlpInterlockedFlushSList((unsigned __int64 *)(a1 + 8));
  while ( v7 )
  {
    v8 = (unsigned int)v7;
    v7 = (_DWORD *)*v7;
    ExFreePoolWithTag(v8);
  }
  return ExFreePoolWithTag(a1);
}
