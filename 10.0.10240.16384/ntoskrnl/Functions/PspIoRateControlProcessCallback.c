// PspIoRateControlProcessCallback 
 
int __fastcall PspIoRateControlProcessCallback(int a1, int a2)
{
  int v4; // r5
  int v5; // r0
  unsigned int *v6; // r0
  unsigned int v7; // r4
  unsigned int v8; // r1

  v4 = 0;
  v5 = ObReferenceProcessHandleTable(a1);
  if ( v5 )
  {
    if ( ExEnumHandleTable(v5, PspSetFileHandleFlow, a2, 0) )
      v4 = -1073741823;
    v6 = (unsigned int *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v7 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v8 = __ldrex(v6);
    while ( v8 == v7 && __strex(v7 - 2, v6) );
    if ( v8 != v7 )
      ExfReleaseRundownProtection((unsigned __int8 *)v6);
  }
  return v4;
}
