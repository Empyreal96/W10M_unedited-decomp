// -SmStSwapStore@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@W4_SM_STORE_SWAP_OPERATION@@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStSwapStore(_DWORD *a1, int a2)
{
  int v4; // r4
  int v5; // r0
  _BYTE v7[40]; // [sp-4h] [bp-28h] BYREF

  KiStackAttachProcess(PsInitialSystemProcess, 0, (int)v7);
  switch ( a2 )
  {
    case 0:
      v5 = SMKM_STORE<SM_TRAITS>::SmStOutSwapPrepareStore((int)a1);
      goto LABEL_8;
    case 1:
      v5 = SMKM_STORE<SM_TRAITS>::SmStOutSwapStore(a1);
      goto LABEL_8;
    case 2:
      v5 = SMKM_STORE<SM_TRAITS>::SmStInSwapStore((int)a1);
LABEL_8:
      v4 = v5;
      goto LABEL_9;
  }
  v4 = -1073741811;
LABEL_9:
  KiUnstackDetachProcess((unsigned int)v7, 0);
  return v4;
}
