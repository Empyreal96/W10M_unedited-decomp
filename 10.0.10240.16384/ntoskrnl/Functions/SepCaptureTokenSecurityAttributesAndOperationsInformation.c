// SepCaptureTokenSecurityAttributesAndOperationsInformation 
 
int __fastcall SepCaptureTokenSecurityAttributesAndOperationsInformation(unsigned int *a1, int a2, unsigned int **a3, int a4)
{
  int v5; // r10
  unsigned int v6; // r8
  int v7; // r4
  _DWORD *v8; // r5
  unsigned int v9; // r6
  unsigned int v10; // r5
  unsigned int v11; // r0
  unsigned int *v12; // r3
  unsigned int v14; // [sp+10h] [bp-28h] BYREF
  _DWORD _14[12]; // [sp+14h] [bp-24h] BYREF
  int varg_r1; // [sp+44h] [bp+Ch]
  unsigned int **varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  _14[11] = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v5 = (char)a2;
  LOBYTE(varg_r1) = a2;
  v6 = 0;
  *a3 = 0;
  if ( !(_BYTE)a2 )
  {
    if ( !a1[1] )
      return -1073741811;
    *a3 = a1;
    return 0;
  }
  if ( ((unsigned __int8)a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v8 = (_DWORD *)a1[1];
  __dmb(0xBu);
  if ( !v8 )
    return -1073741811;
  if ( ((unsigned __int8)v8 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v9 = *a1;
  __dmb(0xBu);
  if ( v9 )
  {
    if ( (v9 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v6 = *(_DWORD *)(v9 + 4);
  }
  else if ( *v8 != 1 )
  {
    return -1073741811;
  }
  v7 = SepCaptureTokenSecurityOperations(v8, v6, (char)a2, (int *)&v14);
  if ( v7 < 0 )
    return v7;
  if ( v9 )
  {
    v7 = SepCaptureTokenSecurityAttributesInformation(v9, v5, 1, _14);
    if ( v7 < 0 )
    {
      v10 = 0;
      v11 = v14;
      goto LABEL_26;
    }
    v10 = _14[0];
  }
  else
  {
    v10 = 0;
  }
  v12 = (unsigned int *)ExAllocatePoolWithTag(1, 8, 1866556755);
  v11 = v14;
  if ( v12 )
  {
    v12[1] = v14;
    *v12 = v10;
    *a3 = v12;
    v7 = 0;
LABEL_26:
    if ( v7 >= 0 )
      return v7;
    goto LABEL_27;
  }
  v7 = -1073741801;
LABEL_27:
  if ( v11 )
    ExFreePoolWithTag(v11);
  if ( v10 )
    SepFreeCapturedTokenSecurityAttributesInformation(v10);
  return v7;
}
