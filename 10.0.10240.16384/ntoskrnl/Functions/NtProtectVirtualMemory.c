// NtProtectVirtualMemory 
 
int __fastcall NtProtectVirtualMemory(int a1, _DWORD *a2, _DWORD *a3, int a4, _DWORD *a5)
{
  int v7; // r5
  int v8; // r5
  unsigned int v9; // r3
  int v10; // r8
  _DWORD *v11; // r2
  _DWORD *v12; // r2
  _DWORD *v13; // r2
  unsigned int v14; // r4
  unsigned int v15; // r2
  int v16; // r4
  int v17; // r9
  char v19; // [sp+10h] [bp-68h]
  _DWORD *v20; // [sp+14h] [bp-64h] BYREF
  int v21; // [sp+18h] [bp-60h] BYREF
  int v22; // [sp+1Ch] [bp-5Ch] BYREF
  _DWORD *v23; // [sp+20h] [bp-58h]
  int v24; // [sp+28h] [bp-50h]
  _DWORD *v25; // [sp+2Ch] [bp-4Ch]
  int v26; // [sp+30h] [bp-48h]
  _DWORD *v27; // [sp+34h] [bp-44h]
  int v28; // [sp+38h] [bp-40h]
  int v29; // [sp+3Ch] [bp-3Ch]
  _DWORD _40[20]; // [sp+40h] [bp-38h] BYREF

  _40[16] = a1;
  _40[17] = a2;
  _40[18] = a3;
  v26 = a4;
  _40[19] = a4;
  v7 = a1;
  v24 = a1;
  v29 = a1;
  v27 = a2;
  v23 = a3;
  v25 = a5;
  v20 = a5;
  if ( MiMakeProtectionMask(a4 & 0x3FFFFFFF) == -1 )
    return -1073741755;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_DWORD *)(v9 + 116);
  v28 = v10;
  v19 = *(_BYTE *)(v9 + 346);
  if ( v19 )
  {
    v11 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v11 = (_DWORD *)MmUserProbeAddress;
    *v11 = *v11;
    v12 = a3;
    if ( (unsigned int)a3 >= MmUserProbeAddress )
      v12 = (_DWORD *)MmUserProbeAddress;
    *v12 = *v12;
    v13 = a5;
    if ( (unsigned int)a5 >= MmUserProbeAddress )
      v13 = (_DWORD *)MmUserProbeAddress;
    *v13 = *v13;
    v14 = *a2;
    v21 = *a2;
    v15 = *a3;
    v22 = *a3;
    v7 = v24;
  }
  else
  {
    v15 = *a3;
    v22 = *a3;
    v14 = *a2;
    v21 = *a2;
  }
  if ( v14 > MmHighestUserAddress )
    return -1073741584;
  if ( MmHighestUserAddress - v14 < v15 || !v15 )
    return -1073741583;
  v8 = ObReferenceObjectByHandleWithTag(v7, 8, PsProcessType, v19, 1984982349, (int *)&v20, 0);
  if ( v8 >= 0 )
  {
    v16 = (int)v20;
    if ( (_DWORD *)v10 == v20 )
    {
      v17 = 0;
    }
    else
    {
      KiStackAttachProcess((int)v20, 0, (int)_40);
      v17 = 1;
    }
    v8 = MiProtectVirtualMemory(v10, v16, &v21, &v22, v26, &v20);
    v23 = (_DWORD *)v8;
    if ( v17 )
      KiUnstackDetachProcess((unsigned int)_40, 0);
    ObfDereferenceObjectWithTag(v16);
    *a3 = v22;
    *a2 = v21;
    *v25 = v20;
  }
  return v8;
}
