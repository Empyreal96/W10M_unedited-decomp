// MmPrefetchVirtualMemory 
 
int __fastcall MmPrefetchVirtualMemory(int a1, int a2, int a3, int a4)
{
  char v4; // r9
  int v5; // r4
  int v6; // r8
  int v8; // r7
  int v9; // r3
  unsigned int v10; // r5
  int v11; // r2
  int v12; // r5
  int v13; // r1
  int v14; // r2
  int v15; // r3
  _DWORD *v16; // r4
  int *v17; // r0
  int v18; // r2
  int v19; // r3
  int v20; // r2
  int v21; // r3
  int v23; // [sp+10h] [bp-48h] BYREF
  int v24; // [sp+14h] [bp-44h]
  int v25; // [sp+18h] [bp-40h]
  int v26; // [sp+1Ch] [bp-3Ch] BYREF
  char var38[60]; // [sp+20h] [bp-38h] BYREF
  int varg_r0; // [sp+60h] [bp+8h]
  int varg_r1; // [sp+64h] [bp+Ch]
  int varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = 0;
  v5 = 0;
  v24 = a3;
  v25 = a2;
  v6 = 0;
  v23 = 0;
  v8 = 0;
  v9 = __mrc(15, 0, 13, 0, 3);
  v10 = v9 & 0xFFFFFFC0;
  if ( !a1 )
  {
    v11 = 1;
    goto LABEL_21;
  }
  if ( a1 == -1 )
  {
    v5 = *(_DWORD *)((v9 & 0xFFFFFFC0) + 0x74);
LABEL_14:
    v11 = v5 + 492;
    goto LABEL_21;
  }
  if ( a1 != -3 )
  {
    if ( !ObIsKernelHandle(a1) )
      return -1073741585;
    if ( ObReferenceObjectByHandleWithTag(a1, 8, PsProcessType, 0, 1716546893, &v23, 0) < 0 )
    {
      v12 = ObReferenceObjectByHandle(a1, 1, MmSessionObjectType, 0, (int)&v26, 0);
      v6 = v26;
      if ( v12 < 0 )
        return v12;
      v16 = *(_DWORD **)(v26 + 16);
      v17 = MiLockAndSelectSessionAttachProcess(v16, v13, v14, v15);
      v8 = (int)v17;
      if ( v17 )
      {
        if ( MmAttachSession((int)v17, (int)var38, v18, v19) >= 0 )
        {
          v11 = (int)(v16 + 812);
          v5 = v23;
          goto LABEL_21;
        }
        ObfDereferenceObject(v8);
      }
      ObfDereferenceObject(v6);
      return 0;
    }
    v5 = v23;
    if ( *(_DWORD *)(v10 + 116) != v23 )
    {
      KiStackAttachProcess(v23, 0, (int)var38);
      v4 = 1;
    }
    goto LABEL_14;
  }
  v5 = *(_DWORD *)((v9 & 0xFFFFFFC0) + 0x74);
  if ( (*(_DWORD *)(v5 + 192) & 0x10000) == 0 )
    return -1073741799;
  v11 = *(_DWORD *)(v5 + 324) + 3248;
LABEL_21:
  v12 = MiPrefetchVirtualMemory(v25, v24, v11, varg_r3);
  if ( (v4 & 1) != 0 )
    KiUnstackDetachProcess((unsigned int)var38, 0);
  if ( v8 )
  {
    MmDetachSession(v8, (int)var38, v20, v21);
    ObfDereferenceObject(v8);
  }
  if ( a1 != -1 && a1 != -3 && a1 )
  {
    if ( v5 )
    {
      ObfDereferenceObjectWithTag(v5);
    }
    else if ( v6 )
    {
      ObfDereferenceObject(v6);
    }
  }
  return v12;
}
