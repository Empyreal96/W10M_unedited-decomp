// DelistKeyBodyFromKCB 
 
int __fastcall DelistKeyBodyFromKCB(int a1, int a2)
{
  __int64 v4; // r0
  int v5; // r5
  unsigned int *v6; // r2
  unsigned int v7; // r1

LABEL_1:
  LODWORD(v4) = 0;
  v5 = 72;
  while ( (unsigned int)v4 < 4 )
  {
    __dmb(0xBu);
    v6 = (unsigned int *)(*(_DWORD *)(a1 + 4) + v5);
    do
      v7 = __ldrex(v6);
    while ( v7 == a1 && __strex(0, v6) );
    __dmb(0xBu);
    if ( v7 == a1 )
      return v4;
    if ( v7 == 1 || v7 == 2 )
    {
      __dmb(0xAu);
      __yield();
      goto LABEL_1;
    }
    LODWORD(v4) = v4 + 1;
    v5 += 4;
  }
  if ( !a2 )
    CmpLockKcbExclusive(*(_DWORD **)(a1 + 4));
  v4 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(v4 + 4) != a1 + 16 || *(_DWORD *)HIDWORD(v4) != a1 + 16 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v4) = v4;
  *(_DWORD *)(v4 + 4) = HIDWORD(v4);
  if ( !a2 )
    LODWORD(v4) = CmpUnlockKcb(*(_DWORD **)(a1 + 4));
  return v4;
}
