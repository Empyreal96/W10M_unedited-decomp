// ExpExpirationThread 
 
__int64 __fastcall ExpExpirationThread(__int64 a1, int a2, int a3)
{
  int v3; // r0
  __int64 v5; // [sp+0h] [bp-10h]
  _DWORD v6[2]; // [sp+8h] [bp-8h] BYREF

  v5 = a1;
  v6[0] = a2;
  v6[1] = a3;
  if ( (_DWORD)a1 )
  {
    HIDWORD(v5) = v6;
    LODWORD(v5) = 1;
    v3 = ExRaiseHardError(a1, 0);
    PsTerminateSystemThread(v3);
  }
  return v5;
}
