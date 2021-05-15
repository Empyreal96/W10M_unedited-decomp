// NtSignalAndWaitForSingleObject 
 
int __fastcall NtSignalAndWaitForSingleObject(int a1, int a2, _DWORD *a3, unsigned int a4)
{
  int *v4; // r8
  int v6; // r4
  int v7; // r9
  int v8; // r5
  int v9; // lr
  int v10; // r5
  signed int v11; // r4
  int v12; // r6
  int v13; // r2
  _DWORD v15[2]; // [sp+14h] [bp-4Ch] BYREF
  unsigned int v16; // [sp+1Ch] [bp-44h] BYREF
  _DWORD *v17; // [sp+20h] [bp-40h]
  int v18; // [sp+28h] [bp-38h]
  int v19; // [sp+2Ch] [bp-34h]
  __int64 v20; // [sp+30h] [bp-30h] BYREF
  __int64 v21; // [sp+38h] [bp-28h] BYREF
  int varg_r0; // [sp+68h] [bp+8h]
  int varg_r1; // [sp+6Ch] [bp+Ch]
  _DWORD *varg_r2; // [sp+70h] [bp+10h]
  __int64 *varg_r3; // [sp+74h] [bp+14h]

  varg_r2 = a3;
  v4 = (int *)a4;
  varg_r3 = (__int64 *)a4;
  v17 = a3;
  LOBYTE(varg_r2) = (_BYTE)a3;
  varg_r1 = a2;
  varg_r0 = a1;
  v6 = __mrc(15, 0, 13, 0, 3);
  v7 = *(char *)((v6 & 0xFFFFFFC0) + 0x15A);
  if ( a4 && *(_BYTE *)((v6 & 0xFFFFFFC0) + 0x15A) )
  {
    if ( a4 >= MmUserProbeAddress )
      v4 = (int *)MmUserProbeAddress;
    v21 = *(_QWORD *)v4;
    v20 = v21;
    v4 = (int *)&v20;
    varg_r3 = &v20;
  }
  v8 = ObReferenceObjectByHandleWithTag(a1, 0, 0, v7, 1951883855, &v16, &v21);
  if ( v8 >= 0 )
  {
    v8 = ObReferenceObjectByHandleWithTag(a2, 0x100000, 0, v7, 1951883855, v15, 0);
    if ( v8 < 0 )
    {
      v12 = v16;
      goto LABEL_30;
    }
    v9 = v15[0];
    v18 = ObHeaderCookie;
    v10 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(v9 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v9 - 12)];
    v11 = *(_DWORD *)(v10 + 16);
    if ( (v11 & 1) != 0 )
    {
      if ( (v11 & 2) != 0 )
      {
        if ( (*(_DWORD *)(*(unsigned __int16 *)(v10 + 124) + v15[0]) & *(_DWORD *)(v10 + 120)) == *(_DWORD *)(v10 + 120) )
          v11 = *(_DWORD *)(*(unsigned __int16 *)(v10 + 126) + v15[0]);
        else
          v11 = v11 + v15[0] - 3;
      }
      else
      {
        v11 = *(_DWORD *)(v11 + v15[0] - 1);
      }
    }
    else if ( v11 >= 0 )
    {
      v11 += v15[0];
    }
    v15[1] = v11;
    v12 = v16;
    v13 = ObTypeIndexTable[*(unsigned __int8 *)(v12 - 12) ^ (unsigned __int8)((unsigned __int16)(v12 - 24) >> 8) ^ (unsigned __int8)v18];
    v8 = -1073741790;
    if ( v13 == ExEventObjectType )
    {
      if ( v7 && (~HIDWORD(v21) & 2) != 0 )
        goto LABEL_28;
      KeSetEvent(v16, 1, 1);
    }
    else if ( v13 == ExMutantObjectType )
    {
      KeReleaseMutant(v16, 1, 0, 1);
    }
    else
    {
      if ( v13 != ExSemaphoreObjectType )
      {
        v8 = -1073741788;
        goto LABEL_28;
      }
      if ( v7 && (~HIDWORD(v21) & 2) != 0 )
        goto LABEL_28;
      KeReleaseSemaphore(v16, 1, 1);
    }
    v8 = KeWaitForSingleObject(v11, 6, v7, v17, v4);
    v19 = v8;
    v9 = v15[0];
LABEL_28:
    ObfDereferenceObjectWithTag(v9);
LABEL_30:
    ObfDereferenceObjectWithTag(v12);
  }
  return v8;
}
