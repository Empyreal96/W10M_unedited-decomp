// CcPerfLogWorkItemEnqueue 
 
int *__fastcall CcPerfLogWorkItemEnqueue(unsigned int a1, int a2, char a3, int a4)
{
  int *v4; // r4
  int v8; // r3
  unsigned int v9; // r3
  int v10; // r5
  _DWORD *v11; // r6
  int v12; // r3
  unsigned int v13; // r5
  unsigned int i; // r3
  unsigned int v15; // r1
  char v16; // r3
  int v17; // r3
  int v19; // [sp+8h] [bp-38h] BYREF
  int v20; // [sp+Ch] [bp-34h]
  int v21; // [sp+10h] [bp-30h]
  int v22[10]; // [sp+18h] [bp-28h] BYREF

  v4 = &CcFastTeardownWorkQueue;
  if ( (int *)a1 == &CcFastTeardownWorkQueue )
    LOBYTE(v4) = 1;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  if ( (int *)a1 != &CcFastTeardownWorkQueue )
  {
    if ( (int *)a1 == &CcExpressWorkQueue )
    {
      LOBYTE(v4) = 2;
    }
    else if ( (int *)a1 == &CcRegularWorkQueue )
    {
      LOBYTE(v4) = 3;
    }
    else if ( (int *)a1 == &CcPostTickWorkQueue )
    {
      LOBYTE(v4) = 4;
    }
    else if ( a1 == CcAsyncReadWorkQueue || a1 == CcAsyncReadWorkQueue + 8 || a1 == CcAsyncReadWorkQueue + 16 )
    {
      LOBYTE(v4) = 5;
    }
    else if ( a1 )
    {
      LOBYTE(v4) = 0;
    }
    else
    {
      LOBYTE(v4) = 6;
    }
  }
  v8 = *(unsigned __int8 *)(a2 + 64);
  if ( v8 == 2 )
  {
    BYTE1(v21) = 2;
    if ( a4 )
    {
      v9 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 68) & 0xFFFFFFF8;
LABEL_32:
      v20 = *(_DWORD *)(v9 + 12);
      goto LABEL_38;
    }
    v10 = *(_DWORD *)(a2 + 8);
    v11 = (_DWORD *)(v10 + 68);
    a1 = ObFastReferenceObject((_DWORD *)(v10 + 68));
    if ( !a1 )
      a1 = CcSlowReferenceSharedCacheMapFileObject(v10);
    v12 = *(_DWORD *)(a1 + 12);
    __pld(v11);
    v20 = v12;
    v13 = *v11;
    for ( i = *v11 ^ a1; i < 7; i = v15 ^ a1 )
    {
      __dmb(0xBu);
      do
        v15 = __ldrex(v11);
      while ( v15 == v13 && __strex(v13 + 1, v11) );
      if ( v15 == v13 )
        goto LABEL_38;
      v13 = v15;
    }
    a1 = ObDereferenceObjectDeferDeleteWithTag(a1);
  }
  else
  {
    switch ( v8 )
    {
      case 1:
        BYTE1(v21) = 1;
        v9 = *(_DWORD *)(a2 + 8);
        goto LABEL_32;
      case 3:
        v16 = 3;
        break;
      case 4:
        v16 = 4;
        break;
      default:
        goto LABEL_38;
    }
    BYTE1(v21) = v16;
  }
LABEL_38:
  LOBYTE(v21) = (_BYTE)v4;
  v19 = a2;
  BYTE2(v21) = a3;
  v22[0] = (int)&v19;
  v22[1] = 0;
  v22[2] = 12;
  v22[3] = 0;
  if ( (unsigned int)KeGetCurrentIrql(a1) >= 2 )
    v17 = 4194562;
  else
    v17 = 4200706;
  return EtwTraceKernelEvent(v22, 1, 0x80020000, 5632, v17);
}
