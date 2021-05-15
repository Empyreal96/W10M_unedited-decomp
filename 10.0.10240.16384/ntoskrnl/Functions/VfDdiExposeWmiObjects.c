// VfDdiExposeWmiObjects 
 
int __fastcall VfDdiExposeWmiObjects(int a1, int a2, int a3, int a4)
{
  int v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[1] = a3;
  v5[2] = a4;
  RtlInitUnicodeString((unsigned int)&ViDdiWmiMofKey, (unsigned __int16 *)dword_9009F8);
  RtlInitUnicodeString((unsigned int)&ViDdiWmiMofResourceName, (unsigned __int16 *)dword_9009F8);
  RtlInitUnicodeString((unsigned int)v5, L"\\DRIVER\\VERIFIER_DDI");
  return IoCreateDriver(v5, (int (__fastcall *)(_BYTE *, _DWORD))ViDdiDriverEntry);
}
