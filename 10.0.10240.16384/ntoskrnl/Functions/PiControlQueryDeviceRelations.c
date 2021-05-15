// PiControlQueryDeviceRelations 
 
int __fastcall PiControlQueryDeviceRelations(int a1, int *a2, int a3, char a4)
{
  unsigned int v5; // r7
  int v6; // r8
  int v7; // r3
  int v8; // r5
  unsigned int v9; // r4
  _BYTE *v10; // r0
  int v11; // r5
  int v12; // r0
  unsigned int v14; // [sp+8h] [bp-28h] BYREF
  __int16 v15[2]; // [sp+10h] [bp-20h] BYREF
  unsigned int v16[7]; // [sp+14h] [bp-1Ch] BYREF

  v5 = *(unsigned __int16 *)a2;
  v6 = a4;
  v15[1] = v5;
  v15[0] = v5;
  if ( !v5 || v5 > 0x190 || (v5 & 1) != 0 )
    return -1073741811;
  v16[0] = 0;
  v7 = a2[3];
  if ( v7 && a2[4] )
    v8 = 2 * v7;
  else
    v8 = 0;
  v14 = v8;
  if ( !v8 )
  {
    v9 = 0;
    goto LABEL_15;
  }
  if ( !v6 )
  {
    v9 = a2[4];
    goto LABEL_15;
  }
  v10 = (_BYTE *)ExAllocatePoolWithQuotaTag(9u, v8, 538996816);
  v9 = (unsigned int)v10;
  if ( v10 )
  {
    memset(v10, 0, v8);
    v5 = (unsigned __int16)v15[0];
LABEL_15:
    v11 = PiControlMakeUserModeCallersCopy((int *)v16, a2[1], v5, 2, v6, 1);
    if ( v11 >= 0 )
    {
      v11 = PiQueryDeviceRelations(v15, a2[2], &v14, v9);
      if ( v9 )
      {
        v12 = PiControlMakeUserModeCallersCopy(a2 + 4, v9, 2 * a2[3], 2, v6, 0);
        if ( v12 < 0 )
          v11 = v12;
      }
      a2[3] = v14 >> 1;
    }
    goto LABEL_20;
  }
  v11 = -1073741670;
LABEL_20:
  if ( v6 )
  {
    if ( v9 )
      ExFreePoolWithTag(v9);
    if ( v16[0] )
      ExFreePoolWithTag(v16[0]);
  }
  return v11;
}
