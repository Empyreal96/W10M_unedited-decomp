// IopChildToRootTranslation 
 
int __fastcall IopChildToRootTranslation(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v6; // r10
  int v7; // r7
  int v8; // r4
  BOOL v10; // r9
  _DWORD *v11; // r6
  int v12; // r8
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int *v17; // r2
  int v18; // r0
  int v19; // r7
  int v20; // r0
  _DWORD *v21; // r3
  int v23; // [sp+14h] [bp-2Ch]

  v6 = a3;
  v7 = a2;
  v8 = 0;
  v23 = 0;
  v10 = a4 == 1;
  v11 = (_DWORD *)ExAllocatePoolWithTag(257, 16, 538996816);
  if ( !v11 )
    JUMPOUT(0x80DE64);
  v12 = ExAllocatePoolWithTag(1, 16, 538996816);
  if ( !v12 )
    return sub_80DE5C();
  v14 = a5[1];
  v15 = a5[2];
  v16 = a5[3];
  *v11 = *a5;
  v11[1] = v14;
  v11[2] = v15;
  v11[3] = v16;
  if ( !a1 )
    a1 = IopFindLegacyBusDeviceNode(v7, v6);
  if ( a1 )
  {
    while ( !v23 )
    {
      if ( a1 != IopRootDeviceNode || v10 )
      {
        v17 = *(int **)(a1 + 336);
        if ( v17 != (int *)(a1 + 336) )
        {
          while ( *((unsigned __int8 *)v17 + 8) != *(unsigned __int8 *)a5 )
          {
            v17 = (int *)*v17;
            if ( v17 == (int *)(a1 + 336) )
              goto LABEL_10;
          }
          v19 = v17[3];
          if ( v19 )
          {
            v20 = (*(int (__fastcall **)(_DWORD, _DWORD *, _DWORD))(v19 + 16))(*(_DWORD *)(v19 + 4), v11, 0);
            v8 = v20;
            if ( v20 < 0 )
            {
              ExFreePoolWithTag((unsigned int)v11);
              goto LABEL_22;
            }
            v21 = v11;
            v7 = a2;
            v11 = (_DWORD *)v12;
            v12 = (int)v21;
            if ( v20 == 288 )
              v23 = 1;
          }
          else
          {
            v7 = a2;
          }
        }
LABEL_10:
        a1 = *(_DWORD *)(a1 + 8);
      }
      else
      {
        v10 = 1;
        v18 = IopFindLegacyBusDeviceNode(v7, a3);
        a1 = v18;
        if ( !v7 && v18 == IopRootDeviceNode )
          a1 = IopFindLegacyBusDeviceNode(1, 0);
      }
      if ( !a1 )
        break;
    }
  }
  *a6 = v11;
LABEL_22:
  ExFreePoolWithTag(v12);
  return v8;
}
