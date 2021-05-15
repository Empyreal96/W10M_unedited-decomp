// ExpWorkerFactoryStartDeferredWork 
 
int __fastcall ExpWorkerFactoryStartDeferredWork(int result, char a2)
{
  _DWORD *v2; // r5
  int v3; // r0
  __int64 v4; // kr00_8
  int v5; // r8
  unsigned int v6; // r4
  unsigned int v7; // r8
  int v8; // r4
  unsigned int *v9; // r2
  unsigned int v10; // r7
  unsigned int v11; // r1
  int v12; // r3
  int v13; // [sp+8h] [bp-48h] BYREF
  int v14[4]; // [sp+10h] [bp-40h] BYREF
  int v15; // [sp+20h] [bp-30h]
  int v16; // [sp+24h] [bp-2Ch]
  unsigned int v17; // [sp+28h] [bp-28h]

  v2 = (_DWORD *)result;
  if ( (*(_DWORD *)(result + 20) & 1) != 0 )
  {
    v4 = *(_QWORD *)(result + 8);
    v3 = *(_DWORD *)(result + 12);
    v5 = v2[4];
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 0x134);
    *v2 = 0;
    v2[1] = 0;
    v7 = v5 & 0xFFFF0000;
    result = ObReferenceObjectByHandle(v3, 1, AlpcPortObjectType, a2, &v13, 0);
    if ( result >= 0 )
    {
      v8 = v13;
      if ( (v7 & 0x40000) != 0 )
      {
        __dmb(0xBu);
        v9 = (unsigned int *)(v8 + 236);
        do
          v10 = __ldrex(v9);
        while ( __strex(v10 + 1, v9) );
        __dmb(0xBu);
        if ( *(_DWORD *)(v8 + 240) )
          return sub_52E354();
      }
      v17 = v7 | 4;
      v16 = 0;
      v14[3] = 0;
      v15 = 0;
      v14[0] = v8;
      if ( AlpcpSendMessage(v14, v4) < 0 )
      {
        result = ObfDereferenceObject(v14[0]);
      }
      else
      {
        *v2 = v15;
        v2[1] = v14[0];
        result = AlpcpSignal((int)v14, 1);
      }
    }
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = (__int16)(*(_WORD *)(v11 + 0x134) + 1);
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
