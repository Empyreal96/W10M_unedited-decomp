// PiCMGetDeviceInterfaceAlias 
 
int __fastcall PiCMGetDeviceInterfaceAlias(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  _DWORD *v6; // r6
  _WORD *v8; // r7
  unsigned int v10; // r10
  int v11; // r4
  unsigned __int16 *v12; // r5
  unsigned int v13; // r6
  int v15; // r0
  int v16; // r3
  unsigned __int16 v17; // [sp+20h] [bp-58h] BYREF
  unsigned int v18; // [sp+24h] [bp-54h]
  char v19[8]; // [sp+28h] [bp-50h] BYREF
  char v20[4]; // [sp+30h] [bp-48h] BYREF
  int v21; // [sp+34h] [bp-44h]
  char v22[16]; // [sp+38h] [bp-40h] BYREF
  unsigned __int16 *v23; // [sp+48h] [bp-30h]
  int v24; // [sp+50h] [bp-28h]

  v6 = a6;
  *a6 = 0;
  v8 = 0;
  v10 = 0;
  v11 = PiCMCaptureInterfaceAliasInputData(a1, a2, a3, (int)v20);
  v12 = v23;
  if ( v11 >= 0 )
  {
    if ( !v23 || v21 )
    {
      v11 = -1073741811;
    }
    else
    {
      if ( !a3 || a4 < 0x14 )
      {
        v11 = -1073741811;
        goto LABEL_28;
      }
      v13 = a4 - 20;
      if ( a4 - 20 < 2 )
        return sub_7E7058();
      if ( a4 == 20 )
      {
        v8 = 0;
      }
      else
      {
        v8 = (_WORD *)ExAllocatePoolWithTag(1, a4 - 20, 879783504);
        if ( !v8 )
          v11 = -1073741670;
      }
      if ( v11 < 0 )
        goto LABEL_28;
      if ( v13 >= 2 )
        *v8 = 0;
      v11 = RtlInitUnicodeStringEx((int)v19, v12);
      if ( v11 < 0 )
        goto LABEL_28;
      v11 = IoGetDeviceInterfaceAlias(v19, v22, &v17);
      if ( v11 < 0 )
      {
        v12 = v23;
        goto LABEL_28;
      }
      v10 = ((unsigned int)v17 + 2) >> 1;
      if ( 2 * v10 > v13 )
      {
        v11 = -1073741789;
      }
      else
      {
        memmove((int)v8, v18, v17);
        v8[v10 - 1] = 0;
      }
      ExFreePoolWithTag(v18);
      v12 = v23;
      v6 = a6;
    }
    if ( v11 >= 0 )
    {
      v15 = PiCMReturnBufferResultData(v11, 2 * v10, 0, (int)v8, 2 * v10, v24, a3, a4, v6);
      goto LABEL_21;
    }
LABEL_28:
    v15 = PiCMReturnBufferResultData(v11, 2 * v10, 0, 0, 0, v24, a3, a4, a6);
LABEL_21:
    v11 = v15;
    if ( v8 )
      ExFreePoolWithTag((unsigned int)v8);
  }
  v16 = __mrc(15, 0, 13, 0, 3);
  if ( v12 )
  {
    if ( *(_BYTE *)((v16 & 0xFFFFFFC0) + 0x15A) )
      ExFreePoolWithTag((unsigned int)v12);
  }
  return v11;
}
