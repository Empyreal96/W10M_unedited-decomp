// -SmStoreContentsRundown@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAU-$SMKM_STORE@USM_TRAITS@@@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmStoreContentsRundown(int a1, int a2)
{
  unsigned int *v4; // r0
  unsigned int *v5; // r4
  int v6; // r5
  _BYTE *v7; // r0
  _DWORD *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1
  int v12; // [sp+8h] [bp-28h] BYREF
  char v13[4]; // [sp+10h] [bp-20h] BYREF
  int v14; // [sp+14h] [bp-1Ch]
  int v15[6]; // [sp+18h] [bp-18h] BYREF

  v13[0] = 0;
  v13[1] = 0;
  v13[2] = 4;
  v14 = 0;
  v15[1] = (int)v15;
  v15[0] = (int)v15;
  v4 = (unsigned int *)ExAllocatePoolWithTag(512, 32);
  v5 = v4;
  if ( v4 )
  {
    v7 = memset(v4, 0, 32);
    *v5 = *v5 & 0xFFFFFFF8 | 3;
    v5[1] = -1;
    v6 = SMKM_STORE_MGR<SM_TRAITS>::SmStoreRequestEx((int)v7, a2, (int)v5, (int)v13, &v12);
    if ( v6 >= 0 )
    {
      KeWaitForSingleObject((unsigned int)v13, 0, 0, 0, 0);
      v6 = v12;
      a2 = 0;
      v5 = 0;
    }
    if ( v5 )
      ExFreePoolWithTag(v5);
  }
  else
  {
    v6 = -1073741670;
  }
  if ( a2 )
  {
    v8 = (_DWORD *)(a1 + 96 * (*(_DWORD *)(a2 + 3512) & 0x1F) + 4);
    __pld(v8);
    v9 = *v8 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v10 = __ldrex(v8);
    while ( v10 == v9 && __strex(v9 - 2, v8) );
    if ( v10 != v9 )
      ExfReleaseRundownProtection((unsigned __int8 *)v8);
  }
  return v6;
}
