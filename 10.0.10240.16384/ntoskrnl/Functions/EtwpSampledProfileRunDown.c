// EtwpSampledProfileRunDown 
 
int __fastcall EtwpSampledProfileRunDown(int a1, int a2, int a3)
{
  int v3; // r8
  __int64 v4; // r6
  int v5; // r9
  int v6; // r3
  unsigned __int16 *v7; // r4
  unsigned int v8; // r0
  int result; // r0
  int v12; // [sp+20h] [bp-58h]
  unsigned __int16 *v13; // [sp+24h] [bp-54h]
  _DWORD v14[4]; // [sp+28h] [bp-50h] BYREF
  int v15[16]; // [sp+38h] [bp-40h] BYREF

  v3 = 3914;
  if ( a2 )
    v3 = 3913;
  if ( a3 )
  {
    HIDWORD(v4) = &EtwpProfileObject;
    LODWORD(v4) = 1;
  }
  else
  {
    KeWaitForSingleObject((unsigned int)&EtwpGroupMaskMutex, 0, 0, 0, 0);
    v4 = *(_QWORD *)&EtwpPmcProfile;
    if ( !EtwpPmcProfile )
      return KeReleaseMutex((int)&EtwpGroupMaskMutex);
  }
  do
  {
    v5 = *(__int16 *)(HIDWORD(v4) + 48);
    if ( ((int (__cdecl *)())off_617B54)() < 0 )
    {
      v7 = L"Unknown";
      v6 = 0;
    }
    else
    {
      v6 = v12;
      v7 = v13;
    }
    v14[0] = v5;
    v14[1] = v6;
    v14[2] = v6;
    if ( !v7 )
      v7 = L"Unknown";
    v15[0] = (int)v14;
    v15[1] = 0;
    v15[2] = 12;
    v15[3] = 0;
    v8 = wcslen(v7);
    v15[4] = (int)v7;
    v15[5] = 0;
    v15[6] = 2 * (v8 + 1);
    v15[7] = 0;
    result = EtwpLogKernelEvent(v15, a1, 2, v3, 4200707);
    HIDWORD(v4) += 52;
    LODWORD(v4) = v4 - 1;
  }
  while ( (_DWORD)v4 );
  if ( !a3 )
    return KeReleaseMutex((int)&EtwpGroupMaskMutex);
  return result;
}
