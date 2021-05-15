// ObpCaptureObjectCreateInformation 
 
int __fastcall ObpCaptureObjectCreateInformation(int a1, int a2, int a3, _DWORD *a4, int a5, int a6)
{
  int v7; // r5
  int v8; // r6
  int v9; // r2
  int v10; // r10
  unsigned int v11; // r9
  _DWORD *v12; // r8
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r0
  unsigned int v18[8]; // [sp+20h] [bp-20h] BYREF
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  _DWORD *varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v7 = (char)a1;
  LOBYTE(varg_r0) = a1;
  *a4 = 0;
  a4[1] = 0;
  *(_DWORD *)a5 = 0;
  *(_DWORD *)(a5 + 4) = 0;
  *(_DWORD *)(a5 + 8) = 0;
  *(_DWORD *)(a5 + 12) = 0;
  *(_DWORD *)(a5 + 16) = 0;
  *(_DWORD *)(a5 + 20) = 0;
  *(_DWORD *)(a5 + 24) = 0;
  *(_DWORD *)(a5 + 28) = 0;
  *(_DWORD *)(a5 + 32) = 0;
  *(_DWORD *)(a5 + 36) = 0;
  *(_DWORD *)(a5 + 40) = 0;
  if ( !a3 )
    return 0;
  *(_BYTE *)(a5 + 8) = a1;
  if ( (_BYTE)a1 && *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) && (a3 & 3) != 0 )
    ExRaiseDatatypeMisalignment((char)a1);
  if ( *(_DWORD *)a3 != 24 )
  {
    v8 = -1073741811;
    goto LABEL_30;
  }
  *(_DWORD *)(a5 + 4) = *(_DWORD *)(a3 + 4);
  v9 = *(_DWORD *)(a3 + 12);
  if ( (_BYTE)a2 )
    v9 &= 0xFFFFFDFF;
  if ( (v9 & 0xFFFEF00D) != 0 )
  {
    v8 = -1073741811;
    goto LABEL_30;
  }
  *(_DWORD *)a5 = v9;
  v10 = *(_DWORD *)(a3 + 8);
  v11 = *(_DWORD *)(a3 + 16);
  v12 = *(_DWORD **)(a3 + 20);
  if ( v12 )
  {
    if ( (_BYTE)a1 && *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) && ((unsigned __int8)v12 & 3) != 0 )
      ExRaiseDatatypeMisalignment((char)a1);
    v13 = v12[1];
    v14 = v12[2];
    *(_DWORD *)(a5 + 32) = *v12;
    *(_DWORD *)(a5 + 36) = v13;
    *(_DWORD *)(a5 + 40) = v14;
  }
  if ( v11 )
  {
    v8 = SeCaptureSecurityDescriptor(v11, (char)a1, 1, 1, (unsigned int *)(a5 + 24));
    if ( v8 < 0 )
    {
      *(_DWORD *)(a5 + 24) = 0;
      goto LABEL_30;
    }
    SeComputeQuotaInformationSize(*(_DWORD *)(a5 + 24), v18);
    *(_DWORD *)(a5 + 20) = v18[0];
  }
  if ( !v12 || (*(_DWORD *)(a5 + 32) = 12, *(_DWORD *)(a5 + 28) = a5 + 32, v8 = SeValidateSecurityQos(a5 + 32), v8 >= 0) )
  {
    if ( v10 )
    {
      v8 = ObpCaptureObjectName(v7, v10, a4, a6);
      if ( v8 >= 0 )
        return 0;
    }
    else
    {
      if ( !*(_DWORD *)(a5 + 4) )
        return 0;
      v8 = -1073741773;
    }
  }
LABEL_30:
  v15 = *(_DWORD *)(a5 + 24);
  if ( v15 )
  {
    SeReleaseSecurityDescriptor(v15, *(_BYTE *)(a5 + 8), 1);
    *(_DWORD *)(a5 + 24) = 0;
  }
  return v8;
}
