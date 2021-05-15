// PspChargeJobWakeCounter 
 
int __fastcall PspChargeJobWakeCounter(_DWORD *a1, _DWORD *a2, int a3, int a4, unsigned int a5, unsigned int a6, char a7, int a8, int a9)
{
  _DWORD *v10; // r7
  unsigned int v11; // r5
  _DWORD *v12; // r4
  unsigned __int64 v13; // r0
  int v14; // r3
  int v15; // r2
  int v16; // r3
  unsigned int v17; // lr
  unsigned __int64 *v18; // r6
  __int16 v19; // r2
  int v21; // [sp+10h] [bp-40h]
  int v22; // [sp+18h] [bp-38h]

  v10 = a1;
  v22 = 0;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = a1;
  if ( (a7 & 4) != 0 )
  {
    if ( (a7 & 1) != 0 )
    {
      if ( v11 )
        --*(_WORD *)(v11 + 310);
      while ( 1 )
      {
        v14 = v10[144];
        __dmb(0xBu);
        v21 = v14;
        __dmb(0xBu);
        ExAcquireResourceSharedLite(v14 + 32, 1);
        v15 = v21;
        __dmb(0xBu);
        v16 = v10[144];
        __dmb(0xBu);
        if ( v15 == v16 )
          break;
        __dmb(0xBu);
        ExReleaseResourceLite(v21 + 32);
      }
      v22 = v21;
      __dmb(0xBu);
    }
    do
    {
      v17 = a6;
      if ( (a7 & 1) != 0 )
      {
        ExAcquireResourceSharedLite((int)(v12 + 8), 1);
        v17 = a6;
      }
      v18 = (unsigned __int64 *)(v12 + 120);
      __dmb(0xBu);
      do
        v13 = __ldrexd(v18);
      while ( __strexd(v13 + __PAIR64__(v17, a5), v18) );
      __dmb(0xBu);
      if ( v12[102] )
      {
        if ( (a7 & 2) != 0 && KdDebuggerEnabled )
          __assertfail();
        if ( (dword_682610 & 0x200) != 0 )
          LODWORD(v13) = EtwTraceWakeCounter(v10, a3, 0, 0, a8, a9);
      }
      if ( (a7 & 1) != 0 )
        LODWORD(v13) = ExReleaseResourceLite((int)(v12 + 8));
      v12 = (_DWORD *)v12[143];
    }
    while ( v12 != a2 && (v12[186] & 0x1000) != 0 );
    if ( (a7 & 1) != 0 )
    {
      LODWORD(v13) = ExReleaseResourceLite(v22 + 32);
      if ( v11 )
      {
        v19 = *(_WORD *)(v11 + 310);
        *(_WORD *)(v11 + 310) = v19 + 1;
        if ( v19 == -1 )
        {
          LODWORD(v13) = v11 + 100;
          if ( *(_DWORD *)(v11 + 100) != v11 + 100 )
            LODWORD(v13) = KiCheckForKernelApcDelivery(v13);
        }
      }
    }
  }
  else
  {
    LODWORD(v13) = sub_7BDB9C();
  }
  return v13;
}
