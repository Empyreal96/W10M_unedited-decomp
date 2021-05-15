// MmInitializeProcessAddressSpace 
 
int __fastcall MmInitializeProcessAddressSpace(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  unsigned int *v8; // r2
  unsigned int v9; // r0
  int v10; // r4
  int v11; // r0
  int v12; // r1
  int v13; // r3
  _DWORD *v14; // [sp+8h] [bp-68h] BYREF
  int v15; // [sp+Ch] [bp-64h] BYREF
  __int64 v16; // [sp+10h] [bp-60h]
  int v17; // [sp+1Ch] [bp-54h]
  int v18; // [sp+20h] [bp-50h]
  int v19; // [sp+28h] [bp-48h]
  int v20; // [sp+2Ch] [bp-44h]
  int v21; // [sp+30h] [bp-40h]
  char v22[56]; // [sp+38h] [bp-38h] BYREF

  v14 = a4;
  v15 = a3;
  if ( a2 )
    return sub_7F53AC();
  v17 = 0;
  v18 = 0;
  v16 = 0i64;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  KiStackAttachProcess((int)a1, 0, (int)v22);
  a1[63] = 0;
  a1[64] = 0;
  __dmb(0xBu);
  a1[123] = 0;
  a1[159] = 0;
  a1[146] = -1069539328;
  if ( (MmTrackLockedPages & 1) != 0 && (MmTrackLockedPages & 0x10000000) == 0 )
    MiInitializeLockedPagesTracking(a1);
  MiInitializeWorkingSetList(a1);
  MEMORY[0xC0402120] = 1;
  MEMORY[0xC04021B8] = 768;
  MEMORY[0xC04021BC] = -1069538984;
  __dmb(0xBu);
  v8 = a1 + 48;
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x400, v8) );
  __dmb(0xBu);
  v14 = 0;
  v15 = 0;
  v10 = MiComputeProcessUserVa(a1, 0, a3, &v14, &v15);
  if ( v10 >= 0 )
  {
    MiInitializeProcessBottomUpEntropy(a1);
    v11 = MiInitializeProcessTopDownEntropy(a1, a3);
    if ( MiInitializeVadBitMap(v11) )
    {
      MiInsertProcessVads(a1, v14);
      if ( a3 )
        v10 = MiMapProcessExecutable(a1, a3, a4, v15);
      v13 = a1[184];
      if ( (v13 & 1) != 0 )
        v10 = PsInitializeFullProcessImageName(a1);
      if ( a3 || (v13 = a1[184], (v13 & 1) != 0) )
      {
        MiAllowWorkingSetExpansion((int)(a1 + 123), v12, 1, v13);
        KiUnstackDetachProcess((unsigned int)v22, 0);
      }
      else
      {
        if ( v10 >= 0 )
          *a4 &= 0xFFFFFFEF;
        KiUnstackDetachProcess((unsigned int)v22, 0);
        v10 = 0;
      }
      return v10;
    }
    v10 = -1073741801;
  }
  KiUnstackDetachProcess((unsigned int)v22, 0);
  MiReturnProcessVads(v14);
  return v10;
}
