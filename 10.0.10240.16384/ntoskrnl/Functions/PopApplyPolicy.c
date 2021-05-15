// PopApplyPolicy 
 
int __fastcall PopApplyPolicy(int a1, int a2, int a3, unsigned int a4)
{
  int v7; // r4
  int v8; // r9
  int v9; // r0
  unsigned int v10; // r6
  char *v11; // r5
  int v12; // r3
  int v13; // r8
  int v14; // r0
  int v15; // [sp+8h] [bp-200h] BYREF
  char v16[8]; // [sp+10h] [bp-1F8h] BYREF
  char v17[96]; // [sp+18h] [bp-1F0h] BYREF
  char v18[136]; // [sp+78h] [bp-190h] BYREF
  char v19[264]; // [sp+100h] [bp-108h] BYREF

  if ( a4 < 0xE8 )
    return sub_7F1D8C();
  if ( a4 > 0xE8 )
    return -2147483643;
  memmove((int)v19, a3, 0xE8u);
  v7 = PopVerifySystemPowerPolicy(v19, v17);
  v8 = PopPolicy;
  v9 = memcmp((unsigned int)v17, PopPolicy, 232);
  if ( !a1 && !v9 )
    return 0;
  v10 = 0;
  v11 = v18;
  v12 = v8 + 96 - (_DWORD)v18;
  v15 = v12;
  v13 = 0;
  while ( !memcmp((unsigned int)v11, (unsigned int)&v11[v12], 24) )
  {
    ++v10;
    v12 = v15;
    v11 += 24;
    if ( v10 >= 4 )
      goto LABEL_8;
  }
  v13 = 1;
LABEL_8:
  memmove(v8, (int)v17, 0xE8u);
  v14 = PopSetNotificationWork(2);
  if ( v13 && !a2 )
    v14 = PopResetCBTriggers(131);
  PopInitSIdle(v14);
  if ( a1 )
  {
    v7 = PopOpenPowerKey((int)&v15);
    if ( v7 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v16, L"SystemPowerPolicy");
      v7 = ZwSetValueKey();
      ZwClose();
    }
  }
  return v7;
}
