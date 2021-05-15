// WheapAttemptArchitecturalErrorRecovery 
 
int __fastcall WheapAttemptArchitecturalErrorRecovery(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6; // r0
  int v7; // r1
  int (__fastcall *v8)(_DWORD, int *); // r2
  int v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v4 = -1073741811;
  v6 = WheaGetErrPacketFromErrRecord(a1);
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 + 28);
    if ( v7 < 12 )
    {
      if ( *(_QWORD *)(v6 + 48) )
      {
        v8 = (int (__fastcall *)(_DWORD, int *))dword_649F68[7 * v7];
        __dmb(0xBu);
        if ( v8 )
        {
          v10[0] = *(_DWORD *)(a1 + 12);
          v4 = v8(*(_DWORD *)(v6 + 48), v10);
          *(_DWORD *)(a1 + 12) = v10[0];
        }
        else
        {
          v4 = -1073741637;
        }
      }
    }
  }
  return v4;
}
