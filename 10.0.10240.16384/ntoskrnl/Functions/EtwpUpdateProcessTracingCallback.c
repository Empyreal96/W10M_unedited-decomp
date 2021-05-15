// EtwpUpdateProcessTracingCallback 
 
int __fastcall EtwpUpdateProcessTracingCallback(int a1, int a2)
{
  int v4; // r9
  _DWORD *v5; // r0
  unsigned int v6; // r5
  unsigned int v7; // r4
  int v8; // r2
  bool v9; // zf
  char v10; // r3
  int v11; // r0
  unsigned __int8 *v12; // r3
  unsigned int v13; // r2
  int v14; // r0
  unsigned __int8 *v15; // r3
  unsigned int v16; // r2
  unsigned int *v17; // r0
  unsigned int v18; // r4
  unsigned int v19; // r1
  _BYTE v21[56]; // [sp+8h] [bp-38h] BYREF

  v4 = *(_DWORD *)(a1 + 320);
  if ( v4 )
  {
    v5 = (_DWORD *)(a1 + 172);
    __pld(v5);
    v6 = *v5 & 0xFFFFFFFE;
    do
      v7 = __ldrex(v5);
    while ( v7 == v6 && __strex(v6 + 2, v5) );
    __dmb(0xBu);
    if ( v7 == v6 || ExfAcquireRundownProtection(v5) )
    {
      KiStackAttachProcess(a1, 0, (int)v21);
      v8 = *(_DWORD *)a2;
      v9 = *(_BYTE *)(a2 + 4) == 0;
      __dmb(0xBu);
      v10 = v8 & 7;
      if ( v9 )
      {
        v14 = 1 << v10;
        v15 = (unsigned __int8 *)(v4 + (v8 >> 3) + 576);
        do
          v16 = __ldrex(v15);
        while ( __strex(v16 & ~(_BYTE)v14, v15) );
      }
      else
      {
        v11 = 1 << v10;
        v12 = (unsigned __int8 *)(v4 + (v8 >> 3) + 576);
        do
          v13 = __ldrex(v12);
        while ( __strex(v13 | v11, v12) );
      }
      __dmb(0xBu);
      KiUnstackDetachProcess((unsigned int)v21, 0);
      v17 = (unsigned int *)(a1 + 172);
      __pld((void *)(a1 + 172));
      v18 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v19 = __ldrex(v17);
      while ( v19 == v18 && __strex(v18 - 2, v17) );
      if ( v19 != v18 )
        ExfReleaseRundownProtection((unsigned __int8 *)v17);
    }
  }
  return 0;
}
