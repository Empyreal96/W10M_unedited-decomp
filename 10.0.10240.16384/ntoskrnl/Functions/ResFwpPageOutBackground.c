// ResFwpPageOutBackground 
 
void ResFwpPageOutBackground()
{
  int v0; // r6
  int v1; // r0
  unsigned int v2; // r5
  unsigned int v3; // r0
  unsigned int v4; // r1
  unsigned int v5; // r1

  if ( (dword_619018 & 0xC00) != 3072 )
  {
    v0 = dword_61905C;
    if ( dword_61905C )
    {
      if ( dword_619060 )
      {
LABEL_11:
        __dmb(0xBu);
        do
          v5 = __ldrex((unsigned int *)&dword_61905C);
        while ( __strex(0, (unsigned int *)&dword_61905C) );
        __dmb(0xBu);
        BgpFwFreeMemory(v0);
        return;
      }
      BgpFwReleaseLock();
      v1 = ExAllocatePoolWithTag(1, dword_619064, 1263093570);
      v2 = v1;
      if ( v1 )
        v1 = memmove(v1, dword_61905C, dword_619064);
      v3 = BgpFwAcquireLock(v1);
      if ( v2 )
      {
        if ( dword_619060 )
        {
          sub_8DF78C(v3);
          return;
        }
        __dmb(0xBu);
        do
          v4 = __ldrex((unsigned int *)&dword_619060);
        while ( __strex(v2, (unsigned int *)&dword_619060) );
        goto LABEL_11;
      }
    }
  }
}
