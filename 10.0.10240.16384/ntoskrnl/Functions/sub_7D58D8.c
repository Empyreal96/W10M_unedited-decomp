// sub_7D58D8 
 
int __fastcall sub_7D58D8(int a1, int a2, int a3, int a4, int a5, int *a6, _DWORD *a7)
{
  _DWORD *v7; // r6
  int v8; // r5
  _DWORD *v9; // r4
  int v10; // r0
  unsigned int v11; // r2
  int v12; // r3
  int v14; // r4
  unsigned int v15; // r5
  _DWORD *v16; // r7
  _DWORD *v17; // r8
  int v18; // r9
  _DWORD *v19; // r10
  int v20; // r0
  int v21; // r1
  int v22; // r3
  int v23; // r4
  int v24; // r5
  int v25; // r0
  int v26; // r3
  int v27; // [sp+18h] [bp-30h]
  int v28[11]; // [sp+1Ch] [bp-2Ch] BYREF

  v20 = ExAllocatePoolWithTag(1, v18, 538996553);
  v7 = (_DWORD *)v20;
  if ( v20 )
  {
    memmove(v20 + 20, v14, v15);
    v21 = v16[1];
    v22 = v16[2];
    v23 = v16[3];
    *v7 = *v16;
    v7[1] = v21;
    v7[2] = v22;
    v7[3] = v23;
    v7[4] = v15;
    v24 = *a6 + 8;
    if ( *v19 )
    {
      if ( (*v17 & 0x10) != 0 )
        v26 = 40;
      else
        v26 = 32;
      v25 = ExAllocatePoolWithTagPriority(1, *a6 + 8, 538996553, v26);
    }
    else
    {
      v25 = ExAllocatePoolWithTag(1, *a6 + 8, 538996553);
    }
    v9 = (_DWORD *)v25;
    if ( !v25 )
    {
      v8 = -1073741670;
      goto LABEL_12;
    }
    v10 = IopIssueSystemEnvironmentRequest(5373956, 1, 0, v27, (int)v7, v18, v25, v24, v28);
    v8 = v10;
    if ( v10 < 0 )
    {
      if ( v10 != -1073741789 )
        goto LABEL_11;
      v12 = v28[0] - 8;
    }
    else
    {
      if ( a7 )
        *a7 = *v9;
      v11 = *a6;
      if ( (unsigned int)*a6 >= v9[1] )
        v11 = v9[1];
      memmove(a5, (int)(v9 + 2), v11);
      v12 = v9[1];
    }
    *a6 = v12;
LABEL_11:
    ExFreePoolWithTag((unsigned int)v9);
LABEL_12:
    ExFreePoolWithTag((unsigned int)v7);
    return ((int (__fastcall *)(int))v28[10])(v8);
  }
  v8 = -1073741670;
  return ((int (__fastcall *)(int))v28[10])(v8);
}
