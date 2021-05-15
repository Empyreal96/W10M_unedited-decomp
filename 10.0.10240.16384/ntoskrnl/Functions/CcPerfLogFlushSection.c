// CcPerfLogFlushSection 
 
int *__fastcall CcPerfLogFlushSection(int *result, int a2, int *a3, int a4, int a5)
{
  int v8; // r8
  _DWORD *v9; // r6
  int v10; // r0
  int v11; // r3
  unsigned int v12; // r5
  unsigned int i; // r3
  unsigned int v14; // r1
  int v15; // r3
  int v16[2]; // [sp+8h] [bp-40h] BYREF
  int v17; // [sp+10h] [bp-38h]
  int v18; // [sp+14h] [bp-34h]
  int v19; // [sp+18h] [bp-30h]
  int v20; // [sp+1Ch] [bp-2Ch]
  int v21[10]; // [sp+20h] [bp-28h] BYREF

  v8 = (int)result;
  if ( a2 )
  {
    v9 = (_DWORD *)(a2 + 68);
    v10 = ObFastReferenceObject((_DWORD *)(a2 + 68));
    if ( !v10 )
      v10 = CcSlowReferenceSharedCacheMapFileObject(a2);
    v11 = *(_DWORD *)(v10 + 12);
    __pld(v9);
    v16[1] = v11;
    v12 = *v9;
    for ( i = *v9 ^ v10; i < 7; i = v14 ^ v10 )
    {
      __dmb(0xBu);
      do
        v14 = __ldrex(v9);
      while ( v14 == v12 && __strex(v12 + 1, v9) );
      if ( v14 == v12 )
        goto LABEL_12;
      v12 = v14;
    }
    ObDereferenceObjectDeferDeleteWithTag(v10);
LABEL_12:
    if ( a3 )
    {
      v17 = *a3;
      v15 = a3[1];
    }
    else
    {
      v15 = 0;
      v17 = 0;
    }
    v18 = v15;
    v19 = a4;
    v20 = a5;
    v21[0] = (int)v16;
    v21[1] = 0;
    v21[2] = 24;
    v21[3] = 0;
    v16[0] = v8;
    result = EtwTraceKernelEvent(v21, 1, 0x80020000, 5642, 4200706);
  }
  return result;
}
