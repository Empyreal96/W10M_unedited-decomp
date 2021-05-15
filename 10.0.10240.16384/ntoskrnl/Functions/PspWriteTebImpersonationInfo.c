// PspWriteTebImpersonationInfo 
 
int __fastcall PspWriteTebImpersonationInfo(_DWORD *a1, _DWORD *a2)
{
  int v4; // r9
  int v5; // r0
  int v6; // r8
  unsigned int *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  BOOL v10; // r0
  unsigned int *v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  _DWORD _C[18]; // [sp+Ch] [bp-38h] BYREF

  _C[16] = a1;
  _C[17] = a2;
  v4 = a1[39];
  if ( v4 && (a1[19] & 0x400) == 0 )
  {
    v5 = a1[84];
    if ( a2[29] == v5 )
    {
      v6 = 0;
    }
    else
    {
      KiStackAttachProcess(v5, 0, (int)_C);
      v6 = 1;
    }
    if ( a1 == a2 )
      goto LABEL_24;
    v7 = a1 + 235;
    __pld(a1 + 235);
    v8 = a1[235] & 0xFFFFFFFE;
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 + 2, v7) );
    __dmb(0xBu);
    if ( v9 == v8 || ExfAcquireRundownProtection(v7) )
    {
LABEL_24:
      do
      {
        v10 = (a1[240] & 8) != 0;
        *(_DWORD *)(v4 + 3996) = v10;
        *(_DWORD *)(v4 + 4036) = 0;
        __dmb(0xFu);
      }
      while ( v10 != ((a1[240] & 8) != 0) );
      if ( a1 != a2 )
      {
        v11 = a1 + 235;
        __pld(a1 + 235);
        v12 = a1[235] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v13 = __ldrex(v11);
        while ( v13 == v12 && __strex(v12 - 2, v11) );
        if ( v13 != v12 )
          ExfReleaseRundownProtection((unsigned __int8 *)v11);
      }
    }
    if ( v6 )
      KiUnstackDetachProcess((unsigned int)_C, 0);
  }
  return 0;
}
