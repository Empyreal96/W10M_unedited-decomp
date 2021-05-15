// PoCreateThermalRequest 
 
int __fastcall PoCreateThermalRequest(unsigned int *a1, int a2, int a3, unsigned int a4, int a5)
{
  _DWORD *v5; // r6
  unsigned int v6; // r5
  int v9; // r4
  _BYTE *v10; // r0
  __int64 v12; // r0
  int v13[8]; // [sp+8h] [bp-20h] BYREF

  v13[1] = a4;
  v5 = 0;
  v6 = 0;
  *a1 = 0;
  v13[0] = 0;
  if ( a2 && a3 && a4 )
  {
    v9 = PoCaptureReasonContext(a4, 0, a3, 1, 0, v13);
    if ( v9 < 0 )
    {
      v5 = (_DWORD *)v13[0];
      goto LABEL_13;
    }
    v10 = (_BYTE *)ExAllocatePoolWithTag(1, 360, 1819231056);
    v6 = (unsigned int)v10;
    if ( !v10 )
      return sub_7F177C();
    memset(v10, 0, 360);
    v5 = (_DWORD *)v13[0];
    *(_BYTE *)(v6 + 8) = 100;
    *(_DWORD *)(v6 + 12) = v5;
    LODWORD(v12) = KeQueryInterruptTime();
    *(_QWORD *)(v6 + 32) = v12;
    v9 = PopAssociateThermalRequest(v6, a2, a5 >= 0);
    if ( v9 < 0 )
      goto LABEL_13;
    *a1 = v6;
  }
  else
  {
    v9 = -1073741811;
  }
  if ( v9 < 0 )
  {
LABEL_13:
    if ( v5 )
      PoDestroyReasonContext(v5);
    if ( v6 )
      ExFreePoolWithTag(v6);
  }
  return v9;
}
