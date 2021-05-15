// PoCreatePowerRequest 
 
int __fastcall PoCreatePowerRequest(_DWORD *a1, int a2, unsigned int a3)
{
  int v5; // r4
  int v6[4]; // [sp+8h] [bp-10h] BYREF

  *a1 = 0;
  v6[0] = 0;
  if ( !a2 )
    return -1073741811;
  if ( PoCaptureReasonContext(a3, 0, a2, 1, 0, v6) < 0 )
    return sub_7F1514();
  v5 = PopCreateKernelPowerRequest(v6, v6[0]);
  if ( v5 < 0 )
    return sub_7F1514();
  *a1 = v6[0];
  return v5;
}
