// IopAcquireFileObjectLock 
 
int __fastcall IopAcquireFileObjectLock(int a1, char a2, int a3, _BYTE *a4)
{
  int v6; // r9
  unsigned int v8; // r5
  unsigned int *v9; // r8
  unsigned int v10; // r5
  int v11; // r0
  unsigned int *v12; // r1
  int v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r1
  int v19; // r3

  v6 = a2;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  *a4 = 0;
  __dmb(0xBu);
  v9 = (unsigned int *)(a1 + 64);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + 1, v9) );
  __dmb(0xBu);
  while ( 2 )
  {
    v11 = 1;
    v12 = (unsigned int *)(a1 + 68);
    if ( *(_DWORD *)(a1 + 68) )
      goto LABEL_8;
    __dmb(0xBu);
    do
      v15 = __ldrex(v12);
    while ( __strex(1u, v12) );
    __dmb(0xBu);
    if ( v15 )
    {
LABEL_8:
      while ( 1 )
      {
        if ( v6 != 1 )
          return sub_7F0564(v11, v12);
        v11 = KeWaitForSingleObject(a1 + 76, 0, a3 != 0, (_DWORD *)1, 0);
        v14 = v11;
        if ( v11 != 257 && v11 != 192 )
          break;
        if ( a3 || (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) != 0 )
        {
          if ( v11 == 192 )
            goto LABEL_21;
          break;
        }
      }
      if ( v11 != 257 )
        continue;
LABEL_21:
      __dmb(0xBu);
      do
        v17 = __ldrex(v9);
      while ( __strex(v17 - 1, v9) );
      __dmb(0xBu);
      if ( !*(_DWORD *)(a1 + 68) && *(_DWORD *)(a1 + 64) )
        v11 = KeSetEvent(a1 + 76, 0, 0);
      *a4 = 1;
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = (__int16)(*(_WORD *)(v18 + 0x134) + 1);
      *(_WORD *)(v18 + 308) = v19;
      if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
        KiCheckForKernelApcDelivery(v11);
    }
    else
    {
      ObfReferenceObject(a1);
      __dmb(0xBu);
      do
        v16 = __ldrex(v9);
      while ( __strex(v16 - 1, v9) );
      __dmb(0xBu);
      v14 = 0;
    }
    return v14;
  }
}
