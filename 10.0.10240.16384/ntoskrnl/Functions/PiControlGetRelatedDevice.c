// PiControlGetRelatedDevice 
 
int __fastcall PiControlGetRelatedDevice(int a1, int *a2, int a3, char a4)
{
  unsigned int v5; // r2
  int v6; // r7
  int v7; // r4
  int v8; // r1
  int v9; // r5
  int v11; // r5
  unsigned int v12; // [sp+8h] [bp-28h] BYREF
  __int16 v13[2]; // [sp+10h] [bp-20h] BYREF
  unsigned int v14[7]; // [sp+14h] [bp-1Ch] BYREF

  v5 = *(unsigned __int16 *)a2;
  v6 = a4;
  v13[1] = v5;
  v13[0] = v5;
  if ( !v5 || v5 > 0x190 || (v5 & 1) != 0 )
    return -1073741811;
  v7 = a2[3];
  v14[0] = 0;
  if ( v7 && (v8 = a2[4]) != 0 )
    v9 = 2 * v8;
  else
    v9 = 0;
  v12 = v9;
  if ( v9 )
    return sub_7EEB48();
  v11 = PiControlMakeUserModeCallersCopy((int *)v14, a2[1], v5, 2, a4, 1);
  if ( v11 >= 0 )
  {
    v11 = PiGetRelatedDevice(v13, 0, &v12, a2[2]);
    a2[4] = v12 >> 1;
  }
  if ( v6 )
  {
    if ( v14[0] )
      ExFreePoolWithTag(v14[0]);
  }
  return v11;
}
