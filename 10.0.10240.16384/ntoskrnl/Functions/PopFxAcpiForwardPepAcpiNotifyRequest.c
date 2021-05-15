// PopFxAcpiForwardPepAcpiNotifyRequest 
 
__int64 __fastcall PopFxAcpiForwardPepAcpiNotifyRequest(__int64 a1, int a2, int a3)
{
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int v6; // r1
  __int64 v8; // [sp+0h] [bp-18h] BYREF
  int v9; // [sp+8h] [bp-10h]
  int v10; // [sp+Ch] [bp-Ch]

  v8 = a1;
  v9 = a2;
  v10 = a3;
  if ( PopFxFindAndReferenceAcpiDevice(a1) >= 0 )
  {
    if ( !*(_DWORD *)(a1 + 44) )
      PopFxBugCheck(1640, a1, *(_DWORD *)HIDWORD(a1), 0);
    LODWORD(v8) = 0;
    v9 = 0;
    v10 = HIDWORD(a1);
    HIDWORD(v8) = dword_61DB44;
    PopFxPlatformInterface(&v8);
    __dmb(0xBu);
    v4 = (unsigned int *)(a1 + 136);
    do
    {
      v5 = __ldrex(v4);
      v6 = v5 - 1;
    }
    while ( __strex(v6, v4) );
    __dmb(0xBu);
    if ( !v6 )
      KeSetEvent(a1 + 140, 0, 0);
  }
  return v8;
}
