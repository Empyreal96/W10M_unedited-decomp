// -SmStWorkerThreadStartThread@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@P6AXPAX@ZPAPAU_ETHREAD@@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStWorkerThreadStartThread(int a1, int a2, _DWORD *a3)
{
  int v6; // r0
  int v7; // r5
  int v8; // r0
  int result; // r0
  int v10; // [sp+10h] [bp-30h] BYREF
  int v11; // [sp+14h] [bp-2Ch] BYREF
  int v12[10]; // [sp+18h] [bp-28h] BYREF

  v10 = 0;
  memset(v12, 0, 24);
  LOWORD(v12[1]) = 0;
  BYTE2(v12[1]) = 4;
  v12[2] = 0;
  v12[4] = (int)&v12[3];
  v12[3] = (int)&v12[3];
  v12[5] = -1;
  v12[0] = a1;
  v6 = PsCreateSystemThread(&v10, 0x1FFFFF, 0, 0, 0, a2, v12);
  if ( v6 < 0
    || (v7 = ObReferenceObjectByHandle(v10, 0x1FFFFF, 0, 0, &v11, 0),
        v8 = v10,
        *a3 = v11,
        ObCloseHandle(v8, 0),
        v6 = KeWaitForSingleObject(&v12[1], 0, 0),
        v12[5] < 0) )
  {
    result = sub_51126C(v6);
  }
  else
  {
    result = v7;
  }
  return result;
}
