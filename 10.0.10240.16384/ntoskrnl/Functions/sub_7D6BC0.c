// sub_7D6BC0 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_7D6BC0(int a1, int a2, _DWORD *a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // r3
  unsigned int *v14; // r9
  int v15; // r10
  int *v16; // r8
  unsigned int v17; // r7
  int v18; // r0
  _DWORD *v19; // r6
  int v20; // r5
  int v21; // r7
  int v22; // r8
  int v23; // r9
  __int64 v24; // kr00_8
  int v25; // r0
  int v26; // r2
  int v27; // r3
  int v28; // r4
  int v29; // r3
  unsigned int v30; // r4
  unsigned int v31; // r0
  _DWORD *v32; // r5
  _DWORD *v33; // [sp-5Ch] [bp-5Ch]
  int *v34; // [sp-58h] [bp-58h]
  int v35; // [sp-54h] [bp-54h]
  _DWORD v36[19]; // [sp-4Ch] [bp-4Ch] BYREF

  if ( *a3 == v21 )
  {
    *a3 = a2;
    *(_DWORD *)(a2 + 4) = a3;
    v24 = *(_QWORD *)(v21 + 8);
    if ( *(_DWORD *)(v24 + 4) != v21 + 8 || *(_DWORD *)HIDWORD(v24) != v21 + 8 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v24) = v24;
    *(_DWORD *)(v24 + 4) = HIDWORD(v24);
    KeReleaseMutex((int)&EtwpNotificationMutex);
    v13 = *(_BYTE *)(v21 + 50) & 0x7F;
    *(_BYTE *)(v21 + 50) = v13;
    if ( (v13 & 2) != 0 )
    {
      v14 = (unsigned int *)(v21 + 24);
      v15 = 4;
      do
      {
        __dmb(0xBu);
        do
        {
          v16 = (int *)__ldrex(v14);
          v29 = __strex(0, v14);
        }
        while ( v29 );
        __dmb(0xBu);
        if ( v16 )
        {
          v25 = v16[4];
          if ( (*(_BYTE *)(v25 + 50) & 0x40) == 0 )
          {
            v36[1] = 72;
            v36[0] = 1;
            v26 = v33[4];
            v27 = v33[5];
            v28 = v33[6];
            v36[14] = v33[3];
            v36[15] = v26;
            v36[16] = v27;
            v36[17] = v28;
            EtwpQueueReply(*(_DWORD *)(v25 + 24), (int)v36, v26, v27);
          }
          EtwpReleaseQueueEntry(v16, 2);
        }
        ++v14;
        --v15;
      }
      while ( v15 );
      EtwpRundownNotifications(v34[10], v34, 0, v29);
      ObfDereferenceObjectWithTag(v34[10]);
      EtwpReleaseProviderTraitsReference((int)v34);
      v22 = v35;
      v23 = (int)v33;
    }
    else
    {
      if ( (v13 & 4) == 0 )
        KeBugCheckEx(285, 3, v21, v13, v20);
      v17 = *(_DWORD *)(v21 + 24);
      v18 = KeRundownQueueEx(v17, 1);
      v19 = (_DWORD *)v18;
      if ( v18 )
      {
        v32 = (_DWORD *)v18;
        do
        {
          v30 = (unsigned int)v32;
          v31 = v32[2];
          v32 = (_DWORD *)*v32;
          EtwpUnreferenceDataBlock(v31);
          ExFreePoolWithTag(v30);
        }
        while ( v19 != v32 );
      }
      ExFreePoolWithTag(v17);
    }
    EtwpUnreferenceGuidEntry(v23);
    if ( v22 )
      EtwpUnreferenceGuidEntry(v22);
    __asm { POP.W           {R4-R11,PC} }
  }
  JUMPOUT(0x6DE9FC);
}
