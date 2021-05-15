// PopFxAcpiForwardPepWorkRequest 
 
__int64 __fastcall PopFxAcpiForwardPepWorkRequest(__int64 a1, int a2, int a3)
{
  unsigned int *v4; // r1
  unsigned int v5; // r2
  unsigned int v6; // r2
  unsigned int v7; // r2
  bool v8; // zf
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r1
  __int64 v13; // [sp+0h] [bp-18h] BYREF
  int v14; // [sp+8h] [bp-10h]
  int v15; // [sp+Ch] [bp-Ch]

  v13 = a1;
  v14 = a2;
  v15 = a3;
  if ( !*(_DWORD *)(a1 + 44) )
    PopFxBugCheck(1640, a1, *(_DWORD *)HIDWORD(a1), 0);
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 136);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 + 1, v4) );
  __dmb(0xBu);
  if ( *(_BYTE *)(a1 + 132) )
  {
    __dmb(0xBu);
    do
    {
      v6 = __ldrex(v4);
      v7 = v6 - 1;
    }
    while ( __strex(v7, v4) );
    __dmb(0xBu);
    v8 = v7 == 0;
  }
  else
  {
    LODWORD(v13) = 0;
    v14 = 0;
    v15 = HIDWORD(a1);
    HIDWORD(v13) = dword_61DB44;
    PopFxPlatformInterface(&v13);
    __dmb(0xBu);
    v9 = (unsigned int *)(a1 + 136);
    do
    {
      v10 = __ldrex(v9);
      v11 = v10 - 1;
    }
    while ( __strex(v11, v9) );
    __dmb(0xBu);
    v8 = v11 == 0;
  }
  if ( v8 )
    KeSetEvent(a1 + 140, 0, 0);
  return v13;
}
