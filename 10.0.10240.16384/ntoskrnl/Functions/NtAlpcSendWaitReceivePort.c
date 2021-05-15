// NtAlpcSendWaitReceivePort 
 
int __fastcall NtAlpcSendWaitReceivePort(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  unsigned int v10; // r4
  unsigned int v11; // r5
  int v12; // r8
  int v13; // r0
  int v14; // r6
  int v15; // r4
  char v16; // r2
  unsigned int v17; // r1
  __int16 v18; // r3
  int v20; // r3
  unsigned int *v21; // r2
  unsigned int v22; // r10
  int v23; // [sp+18h] [bp-48h] BYREF
  int v24[4]; // [sp+20h] [bp-40h] BYREF
  int v25; // [sp+30h] [bp-30h]
  int v26; // [sp+34h] [bp-2Ch]
  unsigned int v27; // [sp+38h] [bp-28h]

  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 308);
  v11 = a2 & 0xFFFF0000;
  v12 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v13 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v12, &v23);
  v14 = v13;
  if ( v13 >= 0 )
  {
    v15 = v23;
    if ( (v11 & 0x40000) != 0 )
    {
      __dmb(0xBu);
      v21 = (unsigned int *)(v15 + 236);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 + 1, v21) );
      __dmb(0xBu);
      if ( *(_DWORD *)(v15 + 240) )
        return sub_7F8158();
    }
    if ( (v11 & 0x20000) != 0 )
    {
      if ( a3 )
      {
        if ( (v11 & 0x10000) != 0 )
        {
          v14 = -1073741584;
        }
        else if ( (v11 & 0x1000000) != 0 )
        {
          v14 = -1073741584;
        }
        else if ( a5 )
        {
          if ( (v11 & 0x100000) != 0 )
            v20 = 1;
          else
            v20 = v12;
          v14 = AlpcpProcessSynchronousRequest(v15, v11, a3, a4, a5, a6, a7, a8, v12, v20, v23);
        }
        else
        {
          v14 = -1073740027;
        }
      }
      else
      {
        v14 = -1073741584;
      }
    }
    else
    {
      v24[0] = v15;
      v27 = v11;
      if ( !a3 )
      {
LABEL_5:
        if ( a5 )
          v14 = AlpcpReceiveMessage(v24, a5, a6, a7, a8, 0);
        v16 = v27;
        LOBYTE(v27) = v27 & 0xFB;
        if ( (unsigned __int8)(v16 & 4) >> 2 )
        {
          AlpcpSignal((int)v24, 0);
          if ( v25 )
            ObfDereferenceObject(v25);
        }
        goto LABEL_8;
      }
      if ( (v11 & 0x1000000) != 0 )
      {
        v14 = -1073741584;
      }
      else
      {
        v27 = v11 | 4;
        v25 = 0;
        v26 = 0;
        v24[3] = 0;
        v14 = AlpcpSendMessage(v24, a3);
        if ( v14 >= 0 )
          goto LABEL_5;
      }
    }
LABEL_8:
    v13 = ObfDereferenceObject(v15);
  }
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( v18 )
    return v14;
  if ( *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v14;
}
