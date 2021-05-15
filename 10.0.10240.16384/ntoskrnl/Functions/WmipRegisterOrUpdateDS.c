// WmipRegisterOrUpdateDS 
 
int __fastcall WmipRegisterOrUpdateDS(_DWORD *a1, int a2)
{
  unsigned int v2; // r6
  unsigned int *v5; // r5
  int v6; // r0
  int v7; // r4
  char v9[4]; // [sp+8h] [bp-28h] BYREF
  unsigned int v10; // [sp+Ch] [bp-24h]

  v2 = 0;
  v10 = 0;
  v5 = (unsigned int *)ExAllocatePoolWithTag(512, 0x2000, 1147759959);
  if ( v5 )
  {
    v6 = WmipSendWmiIrp(11, a1[2], a2 != 0, 0x2000, v5, v9);
    v7 = v6;
    if ( v6 < 0 )
    {
      if ( v6 == -1073741789 )
        return sub_7CBF74();
      v7 = WmipSendWmiIrp(8, a1[2], a2 != 0, 0x2000, v5, v9);
    }
    if ( v7 == -1073741789 )
      return sub_7CBF74();
    v2 = v10;
    if ( v10 == 4 )
      return sub_7CBF74();
  }
  else
  {
    v7 = -1073741670;
  }
  if ( v7 >= 0 )
    v7 = WmipProcessWmiRegInfo(a1, v5, v2, a2);
  if ( v5 )
    ExFreePoolWithTag((unsigned int)v5);
  return v7;
}
