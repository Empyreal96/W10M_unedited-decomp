// SeCaptureSecurityQos 
 
int __fastcall SeCaptureSecurityQos(int a1, int a2, _BYTE *a3, _DWORD *a4)
{
  _DWORD *v4; // r4
  _BYTE *v5; // r5
  _DWORD *v6; // r2
  int v7; // r3
  int result; // r0
  int v9; // r2
  int v10; // r3
  _DWORD *v11; // r2
  _DWORD *v12; // [sp+0h] [bp-10h]

  v4 = a4;
  v5 = a3;
  *a3 = 0;
  if ( (_BYTE)a2 )
  {
    if ( a1 )
    {
      if ( (a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v6 = *(_DWORD **)(a1 + 20);
      v12 = v6;
      __dmb(0xBu);
      if ( v6 )
      {
        if ( ((unsigned __int8)v6 & 3) != 0 )
          ExRaiseDatatypeMisalignment(a1);
        v7 = *v6;
        __dmb(0xBu);
        if ( v7 != 12 )
          return -1073741811;
        *v5 = 1;
        v9 = v6[1];
        v10 = v12[2];
        *v4 = *v12;
        v4[1] = v9;
        v4[2] = v10;
        *v4 = 12;
      }
    }
  }
  else if ( a1 && *(_DWORD *)(a1 + 20) )
  {
    *a3 = 1;
    v11 = *(_DWORD **)(a1 + 20);
    if ( *v11 != 12 )
      return -1073741811;
    *a4 = 12;
    a4[1] = v11[1];
    a4[2] = v11[2];
  }
  if ( !*v5 || (result = SeValidateSecurityQos(v4), result >= 0) )
    result = 0;
  return result;
}
