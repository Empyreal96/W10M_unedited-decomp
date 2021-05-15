// NtAlpcDeleteResourceReserve 
 
int __fastcall NtAlpcDeleteResourceReserve(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  char v6; // r3
  int v7; // r5
  int v8; // r1
  int v9; // r6
  int v10; // r0
  int v11; // r4
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r1
  unsigned int *v15; // r2
  unsigned int v16; // r1
  int v17; // r1
  unsigned int v18; // r1
  __int16 v19; // r3
  int v21[4]; // [sp+8h] [bp-10h] BYREF

  v21[0] = a4;
  v5 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v5 & 0xFFFFFFC0) + 0x134);
  if ( a2 || a3 >= 0 )
  {
    v7 = -1073741811;
  }
  else
  {
    v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    a1 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v6, (int)v21, 0);
    v7 = a1;
    if ( a1 >= 0 )
    {
      v8 = a3 & 0x7FFFFFFF;
      v9 = v21[0];
      v10 = AlpcReferenceBlobByHandle((_DWORD *)(*(_DWORD *)(v21[0] + 8) + 20), v8, AlpcReserveType);
      v11 = v10;
      if ( v10 )
      {
        if ( AlpcpDeleteBlob(v10) )
        {
          __dmb(0xBu);
          v12 = (unsigned int *)(v11 - 12);
          do
          {
            v13 = __ldrex(v12);
            v14 = v13 - 1;
          }
          while ( __strex(v14, v12) );
          __dmb(0xBu);
          if ( v14 <= 0 )
          {
            if ( v14 )
              KeBugCheckEx(24, 0, v11, 33, v14);
            AlpcpDestroyBlob(v11);
          }
        }
        else
        {
          v7 = -1073741738;
        }
        __dmb(0xBu);
        v15 = (unsigned int *)(v11 - 12);
        do
        {
          v16 = __ldrex(v15);
          v17 = v16 - 1;
        }
        while ( __strex(v17, v15) );
        __dmb(0xBu);
        if ( v17 <= 0 )
        {
          if ( v17 )
            KeBugCheckEx(24, 0, v11, 33, v17);
          AlpcpDestroyBlob(v11);
        }
      }
      else
      {
        v7 = -1073741816;
      }
      a1 = ObfDereferenceObject(v9);
    }
  }
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v7;
}
