// FsRtlReleaseFile 
 
int __fastcall FsRtlReleaseFile(_DWORD *a1)
{
  int v1; // r7
  _DWORD *v2; // r9
  char *v3; // r8
  int v4; // r5
  int v5; // r10
  int result; // r0
  int v7; // r3
  _DWORD *v8; // r6
  _DWORD *v9; // r4
  int v10; // r10
  int (__fastcall *v11)(_DWORD *); // r3
  unsigned int v12; // r1
  __int16 v13; // r3
  int v14; // r3
  int v15; // r3
  char v16[4]; // [sp+8h] [bp-150h] BYREF
  int v17; // [sp+Ch] [bp-14Ch]
  char v18[8]; // [sp+10h] [bp-148h] BYREF
  int v19; // [sp+18h] [bp-140h]
  _DWORD *v20; // [sp+1Ch] [bp-13Ch]
  int v21; // [sp+34h] [bp-124h]

  v1 = 0;
  v16[0] = 0;
  v2 = a1;
  v3 = v18;
  v4 = 0;
  v5 = IoGetRelatedDeviceObject(a1);
  result = IoGetBaseFileSystemDeviceObject(v2);
  v7 = *(_DWORD *)(result + 8);
  v17 = result;
  v8 = *(_DWORD **)(v7 + 40);
  v9 = *(_DWORD **)(*(_DWORD *)(v7 + 24) + 24);
  if ( v9 && (*v9 >= 0x14u && v9[4] || *v9 >= 0x18u && v9[5]) )
    return sub_802A64();
  if ( v5 == result )
  {
    v3 = 0;
    goto LABEL_12;
  }
  FsFilterCtrlInit((int)v18, 254, v5, 0, (int)v2);
  result = FsFilterPerformCallbacks((int)v18, 0, 0, v16);
  v4 = result;
  if ( result < 0 )
    goto LABEL_46;
  if ( !result )
  {
    v2 = v20;
    if ( (v21 & 4) != 0 )
    {
      result = IoGetDeviceAttachmentBaseRef(v19);
      v15 = *(_DWORD *)(result + 8);
      v1 = (unsigned __int8)v16[0];
      v17 = result;
      v8 = *(_DWORD **)(v15 + 40);
      v10 = 1;
      v9 = *(_DWORD **)(*(_DWORD *)(v15 + 24) + 24);
LABEL_13:
      if ( !v9 || (*v9 < 0x14u || !v9[4]) && (*v9 < 0x18u || !v9[5]) )
      {
        if ( v8 && *v8 >= 0x34u && (v11 = (int (__fastcall *)(_DWORD *))v8[12]) != 0 )
          result = v11(v2);
        else
          v4 = -1073741808;
        v1 = 1;
      }
      if ( v10 )
        result = ObfDereferenceObject(v17);
LABEL_25:
      if ( v4 == -1073741808 && v1 )
      {
        v14 = v2[3];
        if ( v14 )
        {
          result = *(_DWORD *)(v14 + 8);
          if ( result )
            result = ExReleaseResourceLite(result);
        }
        v4 = 0;
      }
      if ( !v3 )
        goto LABEL_30;
      goto LABEL_27;
    }
    v1 = (unsigned __int8)v16[0];
LABEL_12:
    v10 = 0;
    goto LABEL_13;
  }
  if ( result != 294 )
  {
LABEL_46:
    v1 = (unsigned __int8)v16[0];
    goto LABEL_25;
  }
  v4 = 0;
LABEL_27:
  if ( *((_WORD *)v3 + 23) )
    FsFilterPerformCompletionCallbacks((int)v18, v4);
  result = FsFilterCtrlFree((int)v18);
LABEL_30:
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
