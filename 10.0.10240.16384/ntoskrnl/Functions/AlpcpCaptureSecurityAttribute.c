// AlpcpCaptureSecurityAttribute 
 
int __fastcall AlpcpCaptureSecurityAttribute(_DWORD *a1, _DWORD *a2, int a3)
{
  int *v5; // r4
  int v6; // r2
  int v7; // r3
  int result; // r0
  _DWORD *v9; // r2
  int v10; // [sp+8h] [bp-30h] BYREF
  int v11; // [sp+Ch] [bp-2Ch]
  int v12; // [sp+10h] [bp-28h]
  int v13; // [sp+18h] [bp-20h] BYREF
  int v14; // [sp+1Ch] [bp-1Ch]
  int v15; // [sp+20h] [bp-18h]

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v11 = *a2;
    v10 = a2[2];
    v5 = (int *)a2[1];
    __dmb(0xBu);
    if ( v5 )
    {
      if ( (unsigned int)v5 >= MmUserProbeAddress )
        v5 = (int *)MmUserProbeAddress;
      v13 = *v5;
      v14 = v5[1];
      v15 = v5[2];
    }
    else
    {
      v6 = a1[40];
      v7 = a1[41];
      v13 = a1[39];
      v14 = v6;
      v15 = v7;
    }
    result = AlpcpCaptureSecurityAttributeInternal(a1, v11, &v13, &v10, a3);
    v12 = result;
    if ( result >= 0 )
      a2[2] = v10;
  }
  else
  {
    v9 = (_DWORD *)a2[1];
    if ( !v9 )
      v9 = a1 + 39;
    result = AlpcpCaptureSecurityAttributeInternal(a1, *a2, v9, a2 + 2, a3);
  }
  return result;
}
