// MiAllocateAccessLog 
 
_DWORD *__fastcall MiAllocateAccessLog(int a1)
{
  unsigned int v2; // r4
  _DWORD **v3; // r6
  _DWORD *v4; // r3
  int v5; // r0
  int v6; // r0
  _DWORD *v7; // r5

  if ( (unsigned int)dword_640580 < 0x400 || dword_640600 < 1024 || MiFreePoolPagesLeft(5) < 0x800 )
    v2 = 512;
  else
    v2 = 4096;
  v3 = *(_DWORD ***)(a1 + 8);
  if ( v3 )
  {
    v4 = *v3;
    if ( v2 == 512 || v4 && *v4 )
    {
      MiEmptyPageAccessLog(*(_DWORD *)(a1 + 8));
      v3 = 0;
      *(_DWORD *)(a1 + 8) = 0;
    }
  }
  do
  {
    v6 = ExAllocatePoolWithTag(512, v2);
    v7 = (_DWORD *)v6;
    if ( v6 )
    {
      *(_DWORD *)(a1 + 8) = v6;
      MiInitializePageAccessLogging(a1, v6, v2);
      *v7 = v3;
      return v7;
    }
    v5 = *(_DWORD *)(a1 + 8);
    if ( v5 )
    {
      MiEmptyPageAccessLog(v5);
      v3 = 0;
      *(_DWORD *)(a1 + 8) = 0;
    }
    v2 >>= 1;
  }
  while ( v2 >= 0x200 );
  return 0;
}
