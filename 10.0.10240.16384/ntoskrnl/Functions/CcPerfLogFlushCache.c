// CcPerfLogFlushCache 
 
int *__fastcall CcPerfLogFlushCache(int *result, int a2, int *a3, int a4, char a5, char a6, char a7)
{
  int v10; // r9
  _DWORD *v11; // r7
  int v12; // r0
  int v13; // r3
  unsigned int v14; // r6
  unsigned int i; // r3
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r3
  int v19; // r2
  int v20[2]; // [sp+8h] [bp-50h] BYREF
  int v21; // [sp+10h] [bp-48h]
  int v22; // [sp+14h] [bp-44h]
  int v23; // [sp+18h] [bp-40h]
  int v24; // [sp+1Ch] [bp-3Ch]
  int v25; // [sp+20h] [bp-38h]
  int v26[12]; // [sp+28h] [bp-30h] BYREF

  v10 = (int)result;
  if ( a2 )
  {
    v11 = (_DWORD *)(a2 + 68);
    v12 = ObFastReferenceObject((_DWORD *)(a2 + 68));
    if ( !v12 )
      v12 = CcSlowReferenceSharedCacheMapFileObject(a2);
    v13 = *(_DWORD *)(v12 + 12);
    __pld(v11);
    v20[1] = v13;
    v14 = *v11;
    for ( i = *v11 ^ v12; i < 7; i = v16 ^ v12 )
    {
      __dmb(0xBu);
      do
        v16 = __ldrex(v11);
      while ( v16 == v14 && __strex(v14 + 1, v11) );
      if ( v16 == v14 )
        goto LABEL_12;
      v14 = v16;
    }
    ObDereferenceObjectDeferDeleteWithTag(v12);
LABEL_12:
    if ( a3 )
    {
      v21 = *a3;
      v17 = a3[1];
    }
    else
    {
      v17 = 0;
      v21 = 0;
    }
    v22 = v17;
    v23 = a4;
    v18 = *(_DWORD *)(a2 + 96);
    v19 = 0;
    v20[0] = v10;
    v24 = v18;
    v25 = 0;
    if ( a5 )
    {
      v19 = 1;
      v25 = 1;
    }
    if ( a6 )
    {
      v19 |= 2u;
      v25 = v19;
    }
    if ( a7 )
      v25 = v19 | 4;
    v26[0] = (int)v20;
    v26[1] = 0;
    v26[2] = 32;
    v26[3] = 0;
    result = EtwTraceKernelEvent(v26, 1, 0x80020000, 5641, 4200706);
  }
  return result;
}
