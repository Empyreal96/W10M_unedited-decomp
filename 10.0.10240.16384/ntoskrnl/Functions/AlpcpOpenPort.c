// AlpcpOpenPort 
 
int __fastcall AlpcpOpenPort(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  unsigned int v5; // r4
  int v6; // r3
  int v7; // r4
  unsigned int v8; // r1
  __int16 v9; // r3

  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  if ( a1 )
  {
    if ( a1 != 2 || (*(_DWORD *)(a4 + 152) & 0x100000) != 0 )
    {
      v7 = -1073741637;
      goto LABEL_9;
    }
    v6 = *(_DWORD *)(a4 + 12);
    if ( (v6 & 1) != 0 )
      v6 = 0;
    if ( v6 != a3 )
      *a5 &= 0xFFFFFFFE;
  }
  v7 = 0;
LABEL_9:
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v7;
}
