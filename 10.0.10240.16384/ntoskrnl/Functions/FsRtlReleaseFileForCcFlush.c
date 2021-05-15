// FsRtlReleaseFileForCcFlush 
 
int __fastcall FsRtlReleaseFileForCcFlush(_DWORD *a1)
{
  int v2; // r4
  int v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r8
  _DWORD *v7; // r7
  _DWORD *v8; // r6
  int v9; // r9
  int (__fastcall *v10)(int, int); // r3
  unsigned int v11; // r1
  __int16 v12; // r3
  int v13; // r3
  int v14; // r4
  int v15; // r0
  char v16[4]; // [sp+8h] [bp-160h] BYREF
  int v17; // [sp+Ch] [bp-15Ch]
  char *v18; // [sp+10h] [bp-158h]
  _DWORD *v19; // [sp+14h] [bp-154h]
  int v20; // [sp+18h] [bp-150h]
  char v21[8]; // [sp+20h] [bp-148h] BYREF
  int v22; // [sp+28h] [bp-140h]
  int v23; // [sp+2Ch] [bp-13Ch]
  int v24; // [sp+44h] [bp-124h]

  v18 = v21;
  v2 = 0;
  v3 = 0;
  v17 = 0;
  v19 = a1;
  v16[0] = 0;
  v20 = IoGetRelatedDeviceObject(a1);
  result = IoGetBaseFileSystemDeviceObject(a1);
  v5 = *(_DWORD *)(result + 8);
  v6 = result;
  v7 = *(_DWORD **)(v5 + 40);
  v8 = *(_DWORD **)(*(_DWORD *)(v5 + 24) + 24);
  if ( v8 && (*v8 >= 0x24u && v8[8] || *v8 >= 0x28u && v8[9]) )
    return sub_7E5964();
  if ( v20 == result )
  {
    v9 = (int)v19;
    v18 = 0;
LABEL_13:
    if ( !v8 || (*v8 < 0x24u || !v8[8]) && (*v8 < 0x28u || !v8[9]) )
    {
      if ( v7 && *v7 >= 0x70u && (v10 = (int (__fastcall *)(int, int))v7[27]) != 0 )
      {
        result = v10(v9, v6);
        v2 = result;
      }
      else
      {
        v2 = -1073741808;
      }
      v3 = 1;
    }
    if ( v17 )
      result = ObfDereferenceObject(v6);
    goto LABEL_25;
  }
  v9 = (int)v19;
  FsFilterCtrlInit((int)v21, 250, v20, v20, (int)v19);
  result = FsFilterPerformCallbacks((int)v21, 0, 1, v16);
  v2 = result;
  if ( result >= 0 )
  {
    if ( !result )
    {
      v9 = v23;
      if ( (v24 & 4) != 0 )
      {
        result = IoGetDeviceAttachmentBaseRef(v22);
        v17 = 1;
        v13 = *(_DWORD *)(result + 8);
        v6 = result;
        v7 = *(_DWORD **)(v13 + 40);
        v8 = *(_DWORD **)(*(_DWORD *)(v13 + 24) + 24);
      }
      v3 = (unsigned __int8)v16[0];
      goto LABEL_13;
    }
    if ( result == 294 )
      v2 = 0;
  }
  v3 = (unsigned __int8)v16[0];
LABEL_25:
  if ( v2 == -1073741808 && v3 )
  {
    v14 = *(_DWORD *)(v9 + 12);
    v15 = *(_DWORD *)(v14 + 12);
    if ( v15 )
      ExReleaseResourceLite(v15);
    result = *(_DWORD *)(v14 + 8);
    if ( result )
      result = ExReleaseResourceLite(result);
    v2 = 0;
  }
  if ( v18 )
  {
    if ( *((_WORD *)v18 + 23) )
      FsFilterPerformCompletionCallbacks((int)v21, v2);
    result = FsFilterCtrlFree((int)v21);
  }
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
