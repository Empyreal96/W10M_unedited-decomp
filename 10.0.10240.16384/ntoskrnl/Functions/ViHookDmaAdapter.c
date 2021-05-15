// ViHookDmaAdapter 
 
int *__fastcall ViHookDmaAdapter(int a1, int a2, int a3, int a4)
{
  int *v8; // r4
  int *v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r1

  v8 = ViGetAdapterInformationInternal(a1, 0);
  if ( !v8 )
  {
    v9 = (int *)ExAllocatePoolWithTag(512, 224, 1449943368);
    v8 = v9;
    if ( !v9 )
      return v8;
    memset(v9, 0, 224);
    v8[2] = a1;
    v8[5] = 0;
    ExInterlockedInsertHeadList(&ViAdapterList, v8, (unsigned int *)&dword_908C58);
    ObfReferenceObject(a1);
    v8[10] = 0;
    v8[8] = (int)(v8 + 8);
    v8[9] = (int)(v8 + 8);
    v8[13] = 0;
    v8[11] = (int)(v8 + 11);
    v8[12] = (int)(v8 + 11);
    v8[16] = 0;
    v8[14] = (int)(v8 + 14);
    v8[15] = (int)(v8 + 14);
    v8[19] = 0;
    v8[17] = (int)(v8 + 17);
    v8[18] = (int)(v8 + 17);
    ViCopyDeviceDescription((int)(v8 + 30), (const void **)a2);
    v8[20] = a3;
    if ( *(_DWORD *)(a2 + 20) == 1 && *(_DWORD *)(a2 + 16) < 8u || !*(_BYTE *)(a2 + 4) )
      *((_BYTE *)v8 + 18) = 1;
    v8[50] = 0;
    if ( *(_BYTE *)(a2 + 4) && *(_BYTE *)(a2 + 5) )
    {
      if ( ViDoubleBufferDma )
        ViAllocateContiguousMemory((int)v8);
    }
    else
    {
      *((_BYTE *)v8 + 17) = 1;
    }
    v8[7] = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(a1 + 4) = &ViDmaOperations;
  }
  if ( a4 )
  {
    __dmb(0xBu);
    v10 = (unsigned int *)(v8 + 5);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 + 1, v10) );
    __dmb(0xBu);
  }
  return v8;
}
