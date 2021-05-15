// RtlSparseBitmapCtxAllocateRange 
 
unsigned int __fastcall RtlSparseBitmapCtxAllocateRange(int a1, int a2)
{
  int v3; // r3
  unsigned int v4; // r4
  int v6; // r2
  unsigned int v7; // r0
  int v8; // r3
  int v9; // r0
  unsigned int v10; // r6
  unsigned int *v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r2
  int v14; // r3
  unsigned int v15; // r2
  unsigned int *v17; // r2

  v3 = *(_DWORD *)(a1 + 4);
  v4 = 0;
  if ( v3 )
    v4 = *(_DWORD *)(v3 + 4 * a2);
  if ( !v4 )
  {
    if ( *(_DWORD *)(a1 + 24) >= *(_DWORD *)(a1 + 36) )
      goto LABEL_5;
    v6 = *(_DWORD *)(a1 + 32);
    v7 = 4 * (((unsigned int)(v6 + 31) >> 5) + 3);
    v8 = *(_DWORD *)(a1 + 44);
    if ( v8 )
      v7 += v8 * v6;
    v9 = (*(int (__fastcall **)(unsigned int))(a1 + 16))(v7);
    v10 = v9;
    if ( v9 )
    {
      RtlSparseBitmapCtxInitializeRange(a1, v9);
      __dmb(0xBu);
      v11 = (unsigned int *)(a1 + 24);
      do
      {
        v12 = __ldrex(v11);
        v13 = v12 + 1;
      }
      while ( __strex(v13, v11) );
      __dmb(0xBu);
      if ( v13 <= *(_DWORD *)(a1 + 36) )
      {
        __dmb(0xBu);
        v17 = (unsigned int *)(*(_DWORD *)(a1 + 4) + 4 * a2);
        do
          v4 = __ldrex(v17);
        while ( !v4 && __strex(v10, v17) );
        __dmb(0xBu);
        if ( !v4 )
          return v10;
      }
      else
      {
        v14 = *(_DWORD *)(a1 + 4);
        v4 = 0;
        if ( v14 )
          v4 = *(_DWORD *)(v14 + 4 * a2);
      }
      __dmb(0xBu);
      do
        v15 = __ldrex(v11);
      while ( __strex(v15 - 1, v11) );
      __dmb(0xBu);
      (*(void (__fastcall **)(unsigned int))(a1 + 20))(v10);
    }
    else
    {
LABEL_5:
      v4 = 0;
    }
  }
  return v4;
}
