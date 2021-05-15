// FsRtlReleaseFileForModWrite 
 
int __fastcall FsRtlReleaseFileForModWrite(int a1, int a2)
{
  int v3; // r4
  int v4; // r5
  char *v5; // r10
  int result; // r0
  int v7; // r3
  int v8; // r8
  _DWORD *v9; // r7
  _DWORD *v10; // r6
  int v11; // r9
  int v12; // r2
  int v13; // r9
  int (__fastcall *v14)(int, int, int); // r3
  int v15; // r3
  char v16[4]; // [sp+8h] [bp-160h] BYREF
  int v17; // [sp+Ch] [bp-15Ch]
  int v18; // [sp+10h] [bp-158h]
  int v19; // [sp+14h] [bp-154h]
  int v20; // [sp+18h] [bp-150h]
  char v21[8]; // [sp+20h] [bp-148h] BYREF
  int v22; // [sp+28h] [bp-140h]
  int v23; // [sp+2Ch] [bp-13Ch]
  int v24; // [sp+30h] [bp-138h]
  int v25; // [sp+44h] [bp-124h]

  v3 = 0;
  v4 = 0;
  v18 = a1;
  v19 = 0;
  v16[0] = 0;
  v17 = a2;
  v5 = v21;
  v20 = IoGetRelatedDeviceObject(a1);
  result = IoGetBaseFileSystemDeviceObject(a1);
  v7 = *(_DWORD *)(result + 8);
  v8 = result;
  v9 = *(_DWORD **)(v7 + 40);
  v10 = *(_DWORD **)(*(_DWORD *)(v7 + 24) + 24);
  if ( v10 && (*v10 >= 0x34u && v10[12] || *v10 >= 0x38u && v10[13]) )
    return sub_520EF4();
  if ( v20 == result )
  {
    v12 = v25;
    v13 = v18;
    v5 = 0;
LABEL_13:
    if ( !v10 || (*v10 < 0x34u || !v10[12]) && (*v10 < 0x38u || !v10[13]) )
    {
      if ( v9 && *v9 >= 0x68u && (v14 = (int (__fastcall *)(int, int, int))v9[25]) != 0 )
      {
        result = v14(v13, v17, v8);
        v12 = v25;
        v3 = result;
      }
      else
      {
        v3 = -1073741808;
      }
      v4 = 1;
    }
    if ( v19 )
    {
      result = ObfDereferenceObjectWithTag(v8);
      v12 = v25;
    }
    v11 = v17;
    goto LABEL_26;
  }
  FsFilterCtrlInit(v21, 252, v20);
  v11 = v17;
  v24 = v17;
  result = FsFilterPerformCallbacks(v21, 0, 1, v16);
  v3 = result;
  v12 = v25;
  if ( result < 0 )
  {
    v4 = (unsigned __int8)v16[0];
LABEL_27:
    if ( v4 )
    {
      result = ExpReleaseResourceForThreadLite(v11, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      v12 = v25;
      v3 = 0;
    }
    goto LABEL_29;
  }
  if ( !result )
  {
    v13 = v23;
    if ( (v25 & 4) != 0 )
    {
      result = IoGetDeviceAttachmentBaseRef(v22);
      v19 = 1;
      v15 = *(_DWORD *)(result + 8);
      v12 = v25;
      v8 = result;
      v9 = *(_DWORD **)(v15 + 40);
      v10 = *(_DWORD **)(*(_DWORD *)(v15 + 24) + 24);
    }
    v4 = (unsigned __int8)v16[0];
    goto LABEL_13;
  }
  v4 = (unsigned __int8)v16[0];
  if ( result == 294 )
    v3 = 0;
LABEL_26:
  if ( v3 < 0 )
    goto LABEL_27;
LABEL_29:
  if ( v5 )
  {
    if ( *((_WORD *)v5 + 23) )
    {
      result = FsFilterPerformCompletionCallbacks(v21, v3, v12);
      LOBYTE(v12) = v25;
    }
    if ( (v12 & 1) != 0 )
      result = FsFilterFreeCompletionStack(v21);
  }
  return result;
}
