// NtAlpcDeletePortSection 
 
int __fastcall NtAlpcDeletePortSection(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r4
  int v7; // r3
  int v8; // r0
  int v9; // r5
  int v10; // r6
  int v11; // r0
  int v12; // r4
  unsigned int *v13; // r2
  unsigned int v14; // r1
  int v15; // r1
  unsigned int *v16; // r2
  unsigned int v17; // r1
  int v18; // r1
  unsigned int v19; // r1
  __int16 v20; // r3
  int v21[6]; // [sp+8h] [bp-18h] BYREF

  v21[0] = a3;
  v21[1] = a4;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  if ( a2 )
    return sub_7E94D0();
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v8 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v7, v21);
  v9 = v8;
  if ( v8 >= 0 )
  {
    v10 = v21[0];
    v11 = AlpcReferenceBlobByHandle(*(_DWORD *)(v21[0] + 8) + 20, a3, AlpcSectionType);
    v12 = v11;
    if ( v11 )
    {
      if ( AlpcpDeleteBlob(v11) )
      {
        __dmb(0xBu);
        v13 = (unsigned int *)(v12 - 12);
        do
        {
          v14 = __ldrex(v13);
          v15 = v14 - 1;
        }
        while ( __strex(v15, v13) );
        __dmb(0xBu);
        if ( v15 <= 0 )
        {
          if ( v15 )
            KeBugCheckEx(24, 0, v12, 33, v15);
          AlpcpDestroyBlob(v12);
        }
      }
      else
      {
        v9 = -1073741738;
      }
      __dmb(0xBu);
      v16 = (unsigned int *)(v12 - 12);
      do
      {
        v17 = __ldrex(v16);
        v18 = v17 - 1;
      }
      while ( __strex(v18, v16) );
      __dmb(0xBu);
      if ( v18 <= 0 )
      {
        if ( v18 )
          KeBugCheckEx(24, 0, v12, 33, v18);
        AlpcpDestroyBlob(v12);
      }
    }
    else
    {
      v9 = -1073741816;
    }
    v8 = ObfDereferenceObject(v10);
  }
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v9;
}
