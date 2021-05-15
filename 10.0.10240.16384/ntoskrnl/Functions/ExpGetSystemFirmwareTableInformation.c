// ExpGetSystemFirmwareTableInformation 
 
int __fastcall ExpGetSystemFirmwareTableInformation(_DWORD *a1, int a2, unsigned int a3, int *a4)
{
  int *v4; // r9
  int v6; // r10
  int v7; // r5
  unsigned int v8; // r4
  int v9; // r3
  _DWORD *v10; // r6
  unsigned int v11; // r3
  int v12; // r0
  unsigned int v13; // r2
  int (__fastcall *v14)(_DWORD *); // r8
  _DWORD *v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r3
  int v21; // [sp+4h] [bp-2Ch]
  unsigned int v22; // [sp+8h] [bp-28h]
  _DWORD *varg_r0; // [sp+38h] [bp+8h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+40h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v4 = a4;
  v21 = (char)a2;
  LOBYTE(varg_r1) = a2;
  v6 = (int)a1;
  varg_r0 = a1;
  v7 = 0;
  v8 = 0;
  if ( a3 >= 0x10 )
  {
    v10 = a1;
    v11 = a3 - 16;
    v22 = a3 - 16;
    if ( (_BYTE)a2 )
    {
      v12 = ExAllocatePoolWithQuotaTag(9u, a3, 1413894721);
      v8 = v12;
      if ( !v12 )
      {
        v7 = -1073741670;
        goto LABEL_29;
      }
      memmove(v12, v6, a3);
      v11 = v22;
      v10 = (_DWORD *)v8;
    }
    v10[3] = v11;
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v13 + 308);
    ExAcquireResourceSharedLite((int)&ExpFirmwareTableResource, 1);
    v14 = 0;
    v15 = (_DWORD *)(ExpFirmwareTableProviderListHead - 16);
    if ( &ExpFirmwareTableProviderListHead != (int *)ExpFirmwareTableProviderListHead )
    {
      while ( *v15 != *v10 )
      {
        v15 = (_DWORD *)(v15[4] - 16);
        if ( &ExpFirmwareTableProviderListHead == v15 + 4 )
          goto LABEL_12;
      }
      v14 = (int (__fastcall *)(_DWORD *))v15[2];
    }
LABEL_12:
    if ( v14 )
      v7 = v14(v10);
    v16 = ExReleaseResourceLite((int)&ExpFirmwareTableResource);
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(_WORD *)(v17 + 0x134) + 1;
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(v16);
    if ( !v14 )
    {
      v7 = -1073741822;
      goto LABEL_29;
    }
    if ( !v21 )
    {
      v19 = v10[3];
      goto LABEL_27;
    }
    if ( v7 < 0 )
    {
      if ( v7 != -1073741789 )
      {
LABEL_25:
        v19 = *(_DWORD *)(v8 + 12);
LABEL_27:
        v9 = v19 + 16;
        goto LABEL_28;
      }
    }
    else
    {
      memmove(v6 + 16, v8 + 16, *(_DWORD *)(v8 + 12));
    }
    *(_DWORD *)(v6 + 12) = *(_DWORD *)(v8 + 12);
    goto LABEL_25;
  }
  v9 = 16;
  v7 = -1073741820;
LABEL_28:
  *v4 = v9;
LABEL_29:
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v7;
}
