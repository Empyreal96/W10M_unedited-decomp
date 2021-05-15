// ExpPrefetchPushLock 
 
// positive sp value has been detected, the output may be wrong!
void ExpPrefetchPushLock()
{
  int (*v0)(); // r0
  int (*v1)(); // r1
  int v2; // r2
  int v3; // r12
  int *v4; // r1
  int v5; // [sp-8h] [bp-10h]

  v0 = (int (*)())RtlpExecuteHandlerForUnwind_xdata_compact();
  if ( !*((_DWORD *)v0 + 205) )
  {
    v1 = v0;
    v2 = *((_DWORD *)v0 + 55);
    v3 = *((_DWORD *)v0 + 199);
    do
    {
      *(_DWORD *)v1 ^= __ROR4__(v5, 3) ^ __ROR4__(v1, 7);
      v1 = (int (*)())((char *)v1 + 4);
    }
    while ( (unsigned int)v1 < (unsigned int)ExpPrefetchPushLock );
    v4 = &dword_5FB0F4;
    do
    {
      *v4 ^= __ROR4__(v5, 13) ^ __ROR4__(v4, 23);
      ++v4;
    }
    while ( v4 < (int *)((char *)v0 + v3 - 7) );
    __asm { BX              R2 }
  }
  __asm { BX              R2 }
}
