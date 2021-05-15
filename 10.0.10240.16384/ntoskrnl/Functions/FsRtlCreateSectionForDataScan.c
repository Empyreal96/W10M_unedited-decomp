// FsRtlCreateSectionForDataScan 
 
int __fastcall FsRtlCreateSectionForDataScan(_DWORD *a1, int *a2, __int64 *a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v10; // r5
  int i; // r4
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  __int64 v16; // r6
  int v17; // r0
  int v18; // r6
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v23; // [sp+10h] [bp-40h] BYREF
  int v24; // [sp+14h] [bp-3Ch] BYREF
  _DWORD *v25; // [sp+18h] [bp-38h]
  int *v26; // [sp+1Ch] [bp-34h]
  __int64 *v27; // [sp+20h] [bp-30h]
  char v28[4]; // [sp+24h] [bp-2Ch] BYREF
  __int64 v29[5]; // [sp+28h] [bp-28h] BYREF

  v26 = a2;
  v27 = a3;
  v10 = 0;
  v24 = 0;
  v25 = a1;
  v23 = 0;
  if ( (a8 & 0xFFFFFFF9) != 0 || !a8 )
    return -1073741578;
  if ( (a9 & 0x8000000) == 0 || (a9 & 0xF77FFFFF) != 0 )
    return -1073741577;
  if ( !*(_DWORD *)(a4 + 20) )
    return -1073741792;
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 1;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  v13 = FsRtlAcquireToCreateMappedSection(a4, a8, v29, v28);
  i = v13;
  if ( v13 >= 0 )
  {
    i = FsRtlGetFileSize(a4, v29);
    v16 = v29[0];
    if ( i >= 0 )
    {
      if ( v29[0] )
      {
        for ( i = MmCreateSection(&v23, a5, a6, v29, a8, a9, 0, a4);
              i == -1073741740;
              i = MmCreateSection(&v23, a5, a6, v29, a8, a9, 0, a4) )
        {
          KeDelayExecutionThread(0, 0, (unsigned int *)FsRtlHalfSecond);
        }
        v10 = v23;
        if ( i >= 0 )
        {
          v17 = MmGetFileObjectForSection(v23);
          v18 = v17;
          if ( v17 )
          {
            CcZeroEndOfLastPage(v17);
            ObfDereferenceObjectWithTag(v18);
          }
        }
        v16 = v29[0];
      }
      else
      {
        i = -1073741807;
      }
    }
    v19 = FsRtlReleaseFile(a4);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = *(_WORD *)(v20 + 0x134) + 1;
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v19);
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 0;
    if ( i >= 0 )
    {
      ObfReferenceObjectWithTag(v10);
      i = ObInsertObject(v10, 0, a5, 0, 0, &v24);
      if ( i < 0 )
      {
        ObfDereferenceObjectWithTag(v10);
      }
      else
      {
        *v25 = v24;
        *v26 = v10;
        if ( v27 )
          *v27 = v16;
      }
    }
  }
  else
  {
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v15 = *(_WORD *)(v14 + 0x134) + 1;
    *(_WORD *)(v14 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
      KiCheckForKernelApcDelivery(v13);
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 0;
  }
  return i;
}
