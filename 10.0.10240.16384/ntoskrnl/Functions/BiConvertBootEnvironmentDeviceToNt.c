// BiConvertBootEnvironmentDeviceToNt 
 
int __fastcall BiConvertBootEnvironmentDeviceToNt(int *a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // r0
  int v8; // r0
  unsigned __int16 *v9; // r9
  unsigned int v10; // r5
  _BYTE *v11; // r0
  _DWORD *v12; // r4
  unsigned __int16 *v13[2]; // [sp+14h] [bp-34h] BYREF
  int v14; // [sp+1Ch] [bp-2Ch]
  int v15; // [sp+20h] [bp-28h]
  _DWORD *v16; // [sp+28h] [bp-20h]

  v6 = *a1;
  v16 = a4;
  v14 = 0;
  v15 = a3;
  v13[0] = 0;
  v13[1] = 0;
  if ( v6 != 6 )
    return sub_813EA0();
  if ( BiVerifyBootPartition(a1, 0, 0) < 0 )
    JUMPOUT(0x814124);
  if ( (v15 & 0x20) != 0 )
    JUMPOUT(0x813FE8);
  v8 = BiGetNtPartitionPath(a1, v13);
  v9 = v13[0];
  if ( v8 < 0 )
    JUMPOUT(0x813FF2);
  v14 = 1;
  v10 = 2 * (wcslen(v13[0]) + 1);
  v11 = (_BYTE *)ExAllocatePoolWithTag(1, v10 + 20, 1262764866);
  v12 = v11;
  if ( !v11 )
    JUMPOUT(0x813F90);
  memset(v11, 0, v10 + 20);
  *v12 = 2;
  memmove((int)(v12 + 5), (int)v9, v10);
  *v16 = v12;
  *a5 = v10 + 20;
  if ( v14 )
    ExFreePoolWithTag((unsigned int)v9);
  return 0;
}
