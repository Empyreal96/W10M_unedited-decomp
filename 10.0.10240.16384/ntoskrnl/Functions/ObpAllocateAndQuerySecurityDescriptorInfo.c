// ObpAllocateAndQuerySecurityDescriptorInfo 
 
int ObpAllocateAndQuerySecurityDescriptorInfo(int a1, ...)
{
  int v1; // r9
  int v3; // r6
  int v4; // r0
  unsigned int v5; // r5
  int v6; // r0
  int v7; // r4
  int v9; // [sp+18h] [bp-28h] BYREF
  unsigned int *v10; // [sp+1Ch] [bp-24h]
  int varg_r1; // [sp+4Ch] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+4Ch] [bp+Ch]
  unsigned int *varg_r2; // [sp+50h] [bp+10h]
  va_list varg_r3; // [sp+54h] [bp+14h] BYREF

  va_start(varg_r3, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3, _DWORD);
  varg_r2 = va_arg(varg_r3, unsigned int *);
  v1 = a1 - 24;
  v10 = varg_r2;
  v3 = ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v9 = ObpDefaultSecurityDescriptorLength;
  v4 = ExAllocatePoolWithTag(1, ObpDefaultSecurityDescriptorLength, 1901290063);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  v6 = (*(int (__fastcall **)(int, int, int *, int, int *, int, _DWORD, int, _DWORD))(v3 + 108))(
         a1,
         1,
         (int *)varg_r1a,
         v4,
         &v9,
         v1 + 20,
         *(_DWORD *)(v3 + 76),
         v3 + 52,
         0);
  v7 = v6;
  if ( v6 == -1073741789 )
    return sub_7DCD48();
  if ( v6 < 0 )
    ExFreePoolWithTag(v5);
  else
    *v10 = v5;
  return v7;
}
