// PsResumeThread 
 
int __fastcall PsResumeThread(int a1, int *a2)
{
  int v4; // r0
  unsigned int *v5; // r5
  unsigned int v6; // r2
  unsigned int v8; // r1

  v4 = KeResumeThread(a1);
  if ( v4 == 1 )
  {
    v5 = (unsigned int *)(*(_DWORD *)(a1 + 336) + 316);
    v6 = *v5;
    __dmb(0xBu);
    if ( v6 )
    {
      if ( (v6 & 1) == 0 )
      {
        __dmb(0xBu);
        do
          v8 = __ldrex(v5);
        while ( v8 == v6 && __strex(0, v5) );
        __dmb(0xBu);
        if ( v8 != v6 )
          return sub_7F7938();
      }
    }
  }
  if ( a2 )
    *a2 = v4;
  return 0;
}
