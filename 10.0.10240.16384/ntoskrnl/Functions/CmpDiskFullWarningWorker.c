// CmpDiskFullWarningWorker 
 
__int64 __fastcall CmpDiskFullWarningWorker(unsigned int a1, int a2, int a3, int a4)
{
  __int64 v5; // [sp+0h] [bp-10h]
  _DWORD v6[2]; // [sp+8h] [bp-8h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  ExFreePoolWithTag(a1);
  HIDWORD(v5) = v6;
  LODWORD(v5) = 1;
  ExRaiseHardError(-1073741697, 0);
  return v5;
}
