// SepImageVerificationCallbackWorker 
 
__int64 __fastcall SepImageVerificationCallbackWorker(unsigned int a1, int a2, int a3, int a4)
{
  __int64 v6; // [sp+0h] [bp-18h] BYREF
  int v7; // [sp+8h] [bp-10h]
  int v8; // [sp+Ch] [bp-Ch]

  v7 = a3;
  v8 = a4;
  LODWORD(v6) = SepImageVerificationCallbackPreProcess;
  HIDWORD(v6) = 0;
  v7 = *(_DWORD *)(a1 + 16);
  v8 = *(_DWORD *)(a1 + 20);
  ExNotifyWithProcessing(ExCbSeImageVerificationDriverInfo, 1, a1 + 24, (int)&v6);
  ExFreePoolWithTag(*(_DWORD *)(a1 + 16));
  ExFreePoolWithTag(a1);
  return v6;
}
